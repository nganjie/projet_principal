// serveurChatCPPFinal.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//

#include <iostream>
#include"Server.h"

int main()
{
    try
    {
        asio::io_context io_context;
        Server s(io_context, 8080);
        io_context.run();
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}