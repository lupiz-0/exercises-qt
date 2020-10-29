find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

add_executable(phoneBook tst_phonebook.cpp ../phonebook.cpp)
add_test(NAME phoneBook COMMAND phoneBook)

target_link_libraries(phoneBook PRIVATE Qt5::Test)

