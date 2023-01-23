cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)
add_subdirectory(pybind11)
pybind11_add_module(bpc_cpp src/lib.cpp)
