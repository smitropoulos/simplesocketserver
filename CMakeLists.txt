cmake_minimum_required(VERSION 3.14)
project(tcp_server_threaded)

set(CMAKE_CXX_STANDARD 14)

add_executable(tcp_server_threaded main.cpp Socket_Server.cpp Socket_Server.h)
target_link_libraries(tcp_server_threaded pthread)