#include"Session.h"

Session::Session(asio::ip::tcp::socket socket,ListeUser* listUser) :
    m_socket(std::move(socket)),
    m_listeUser(listUser),
    m_nbConnect(0),
    m_timer(m_socket.get_executor())
{
    //start();
    std::cout << "session ouverte " << std::endl;
}
Session::~Session()
{

    //delete m_listeUser;
}
void Session::close()
{
    cout << "l'utilisateur : " << m_user->IP() << " s'est deconnecter" << " et on à : " << m_listeUser->isConnect(m_user->Number()) << endl;
    m_listeUser->popUser(m_user->IP(), m_user->Number());
    // delete m_user;
    m_socket.close();
    Session::~Session();
}
void  Session::Session::start()
{
    //std::cout << "le start est ouvert" << std::endl;
    do_read();
    do_timer();
}
void Session::do_read()
{
    auto self(shared_from_this());


    //char buffer[1024];
    //std::array<char, 1024> buffer;
    int buffer_size = 1024;

    m_socket.async_read_some(asio::buffer(m_data, buffer_size), [&](const asio::error_code& error, std::size_t bytes_transferred) {
        try {
            if (error == asio::error::eof || error == asio::error::connection_reset || error == asio::error::operation_aborted)
            {
                cout << "utilisateur déconnecter du reseau\n";
                throw asio::system_error(error);

            }
            // Connexion fermée proprement par le client.
            else if (error)
            {
                cout << "erreur suvenue" << endl;

               // throw asio::system_error(error);
                cout << "\nfin de l'ecoute en lecture \n";
                return;
            }
            
                std::string d = "";
                d.assign(m_data, bytes_transferred);
                if (d == "connected")
                {

                }
                else
                {
                    analyseData(d);
                   // std::cout << d << endl;
                   // std::cout << "et le nombre de bit transferer est : " << bytes_transferred << std::endl;

                }

                // std::cout << d << endl;
                 //std::cout << "Data read: " << std::string(buffer.begin(), buffer.begin() + bytes_transferred) << std::endl;
                //std::cout << m_data[0] << std::endl;
                //std::cout.write(m_data, bytes_transferred);
                do_timer(); // reset the timer when receiving data
                do_read();
            
            


        
        }
        catch (std::exception& e)
        {
            //cout << "\nexception lévé\n";
            std::cerr << "Exception dans thread client : " << e.what() << std::endl;
            if (m_socket.is_open() && m_nbConnect == 1)
            {
                Session::close();
                m_nbConnect++;
            }
                
        }
        });
}
void Session::analyseData(string data)
{
    if (json::accept(data))
    {
        json jdata = json::parse(data);
        if (m_nbConnect == 0)
        {
            string numberuser = jdata["numberuser"];

            m_user = new User(m_socket.remote_endpoint().address().to_string(), numberuser, &m_socket);
            m_listeUser->insertUser(m_user);
            cout << "\n utilisateur : " << m_socket.remote_endpoint().address().to_string() << " de numero : " << numberuser << " connecter" << endl;
            m_nbConnect++;
            return;
        }
        string typeMessage = jdata["typemessage"];
        cout << "\nle type est : " << typeMessage << endl;
        if (typeMessage == "simplemessage")
        {
            string numberreceiv = jdata["numberreceiv"];
            m_listeUser->sendMessage(numberreceiv, data);
        }
        else cout << "type incorect" << endl;
    }
    
}
void Session::do_timer()
{
    auto self(shared_from_this());
    m_timer.expires_after(std::chrono::seconds(60)); // set timer to expire after 1 minute
    m_timer.async_wait(
        [this, self](std::error_code ec)
        {
            std::cout << "on verifie";
            if (!ec)
            {
                std::cout << "Closing session with " << m_socket.remote_endpoint().address().to_string() << std::endl;
                if (m_socket.is_open() && m_nbConnect == 1)
                {
                    Session::close();
                    m_nbConnect++;
                }
                    
                
                // close the socket if the timer expires
            }
        });
}