cmake_minimum_required(VERSION 3.16)
project(my_music_bot)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdparty)

add_executable(my_music_bot main.cpp)

include_directories(lib)
add_library(MAIN_LIB ./lib/init.hpp ./lib/init.cpp)

target_link_libraries(my_music_bot MAIN_LIB dpp )
