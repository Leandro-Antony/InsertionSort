cmake_minimum_required(VERSION 3.28.3)

project (SortedInsert VERSION 1.0.0 LANGUAGES CXX )

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Define target.
set ( APP_NAME "si")
add_executable(${APP_NAME} "src/sorted_insert.cpp")

# Define c++ standard and compiling options for the target.
target_compile_features( ${APP_NAME}  PUBLIC cxx_std_17 )
target_compile_options( ${APP_NAME} PRIVATE -Wall -pedantic -g)
