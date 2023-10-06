cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project(
  database 
  VERSION 1.0
  LANGUAGES CXX)

include_directories(include)

#add_library(mylib my_lib.cpp my_lib.hpp)
add_executable(client client.cpp)

add_executable(server server.cpp database.cpp)



#target_link_libraries(main PRIVATE mylib)

