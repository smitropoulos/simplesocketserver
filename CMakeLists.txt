cmake_minimum_required(VERSION 3.14)
project(tcp_server_threaded)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(/usr/local/include)
include_directories(/usr/local/Cellar/spdlog/1.3.1/include/)

add_executable(tcp_server_threaded src/main.cpp src/SocketServer.cpp src/CaesarCipher.cpp src/RequestHandler.cpp src/SignalHandling.cpp src/LoggingUtility.cpp src/ArgHandler.cpp)
target_link_libraries(tcp_server_threaded pthread /usr/local/lib/liblinet.a)
target_compile_options(tcp_server_threaded PRIVATE -Wall -Wextra)
