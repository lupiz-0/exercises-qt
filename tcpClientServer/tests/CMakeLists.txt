find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

add_executable(tcpClientServerTests tst_tcpclientserver.cpp)
add_test(NAME tcpClientServerTests COMMAND tcpClientServerTests)

target_link_libraries(tcpClientServerTests PRIVATE Qt5::Test)

