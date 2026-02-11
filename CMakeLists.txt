cmake_minimum_required(VERSION 3.20)
project(soci_test)

set(CMAKE_CXX_STANDARD 17)

find_package(SOCI CONFIG REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE SOCI::soci_core SOCI::soci_odbc)
