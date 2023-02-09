#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

void insert_pkmn(std::string nick, std::string species, int lvl,
                 std::vector<std::string> moves, bool is_shiny);
py::list get_storage();

#endif
