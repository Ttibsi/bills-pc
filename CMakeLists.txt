cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)

add_subdirectory(include)
set(FILES
    src/lib.cpp
    include/sqlite/sqlite3.h
    include/sqlite/sqlite3.c
)
pybind11_add_module(bpc_cpp ${FILES})
