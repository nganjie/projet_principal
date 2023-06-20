cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME serveurChatCpp)
project(${PROJECT_NAME})
# Spécifiez le répertoire où se trouve le SDK d'AWS pour C++
find_package(Threads REQUIRED)
#find_package(nlohmann_json REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../asio-1.24.0/include)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../json/nlohmann/include)

#add_subdirectory(/../asio-1.24.0/include) 
# Chemin d'accès à la bibliothèque asio-1.18.1
#add_subdirectory(/../json/nlohmann/include) 
# Chemin d'accès à la bibliothèque nlohmann json
#set(ASIO_INCLUDE_DIR /../asio-1.24.0/include)
#set(JSON_INCLUDE_DIR /../json/nlohmann/include)

# Ajout de l'exécutable cible et configuration de ses dépendances
#add_executable(${PROJECT_NAME} ${SOURCES})
#target_include_directories(${PROJECT_NAME} PRIVATE ${ASIO_INCLUDE_DIR} ${JSON_INCLUDE_DIR})
#target_link_libraries(${PROJECT_NAME} PRIVATE asio nlohmann_json)

# Linker les bibliothèques nlohmann json et asio C++
#target_link_libraries(${PROJECT_NAME} PRIVATE json asio)
add_subdirectory(json)

add_executable(${PROJECT_NAME} main.cpp Entete.h Server.h Server.cpp Session.h Session.cpp ListeUser.h ListeUser.cpp User.h User.cpp UserExceptions.h)
#target_link_libraries(${PROJECT_NAME} PRIVATE asio)
target_link_libraries(serveurChatCpp PRIVATE Threads::Threads nlohmann_json::nlohmann_json)
#install(TARGETS ${PROJECT_NAME} DESTINATION bin)