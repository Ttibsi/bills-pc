cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(include)
set(FILES
    src/lib.cpp
    src/database.cpp
    src/db_interface.cpp
    src/Pokemon.cpp
    include/sqlite/sqlite3.h
    include/sqlite/sqlite3.c
)
pybind11_add_module(bpc_cpp ${FILES})
