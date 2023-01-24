cmake_minimum_required(VERSION 3.14.0)
project(bills-pc)

add_subdirectory(include)

pybind11_add_module(bpc_cpp src/lib.cpp)
target_include_directories(bpc_cpp PRIVATE ${PROJECT_SOURCE_DIR}/include/SQLiteCpp/include)
target_link_libraries(bpc_cpp SQLiteCpp sqlite3 dl)
