cmake_minimum_required(VERSION 3.16)
project(CppPlayground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subprojects here
add_subdirectory(easy/calculator)
add_subdirectory(easy/guess_game)
add_subdirectory(easy/to_do_list)
add_subdirectory(easy/concepts)
