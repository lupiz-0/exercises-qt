find_package(Qt5 COMPONENTS Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

enable_testing()

add_executable(date tst_date.cpp ../date.cpp)
add_test(NAME date COMMAND date)

target_include_directories(date PRIVATE ${Qt5Test_INCLUDE_DIRS})
target_link_libraries(date PRIVATE Qt5::Test)

