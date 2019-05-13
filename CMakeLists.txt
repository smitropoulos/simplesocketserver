cmake_minimum_required(VERSION 3.14)
project(tcp_server_threaded)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(tcp_server_threaded src/main.cpp src/Socket_Server.cpp src/CaesarCipher.cpp )
target_link_libraries(tcp_server_threaded pthread)