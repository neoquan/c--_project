cmake_minimum_required(VERSION 3.16)
project(CppPlayground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add subprojects here
add_subdirectory(easy/calculator)
add_subdirectory(easy/guess_game)
add_subdirectory(easy/to_do_list)
add_subdirectory(easy/concepts)
add_subdirectory(easy/palindrome_checker)
add_subdirectory(easy/unordered_map)
add_subdirectory(easy/lambda_usage)

add_subdirectory(medium/bank_account_system)
add_subdirectory(medium/student_mng_system)