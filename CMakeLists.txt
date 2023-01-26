cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)

add_subdirectory(include)
pybind11_add_module(bpc_cpp src/lib.cpp)
