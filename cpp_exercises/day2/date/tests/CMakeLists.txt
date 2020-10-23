find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

add_executable(date tst_date.cpp ../date.cpp)
add_test(NAME date COMMAND date)

target_link_libraries(date PRIVATE Qt5::Test)

