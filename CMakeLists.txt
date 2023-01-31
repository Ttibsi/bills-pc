cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)

add_subdirectory(include)
set (FILES
    src/lib.cpp
    src/sqlite3.h
    src/sqlite3.c
)
pybind11_add_module(bpc_cpp ${FILES})
