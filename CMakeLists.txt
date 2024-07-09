cmake_minimum_required(VERSION 3.2)

project(chess_engine)

add_library(include_interface INTERFACE)
target_include_directories(include_interface INTERFACE include)

add_subdirectory(src)