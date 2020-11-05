cmake_minimum_required(VERSION 3.5)

project(tcpClientServer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Network REQUIRED)

add_executable(tcp-client
  src/client.cpp
  src/tcpclient.cpp
  src/abstracttcpclientserver.cpp
)

add_executable(tcp-server
  src/server.cpp
  src/tcpserver.cpp
  src/abstracttcpclientserver.cpp
)

target_compile_options(tcp-client PUBLIC -Wall -Wextra -Wpedantic -Weffc++ -fPIC)
target_compile_options(tcp-server PUBLIC -Wall -Wextra -Wpedantic -Weffc++ -fPIC)
target_include_directories(tcp-client PUBLIC include ${Qt5Network_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
target_include_directories(tcp-server PUBLIC include ${Qt5Network_INCLUDE_DIRS} ${Qt5Core_INCLUDE_DIRS})
target_link_libraries(tcp-client PUBLIC Qt5::Core Qt5::Network)
target_link_libraries(tcp-server PUBLIC Qt5::Core Qt5::Network)

add_subdirectory(tests)
