#ifndef POKEMON_H
#define POKEMON_H

#include <pybind11/stl.h>
#include <string>
#include <vector>

#include "Species.hpp"

namespace py = pybind11;

struct Pokemon {
    std::string nickname;
    Species species;
    int lvl;
    std::vector<std::string> moves;
    bool is_shiny;

    // Methods
    Pokemon(std::string, std::string, int, std::vector<std::string>);
    Pokemon(std::string, std::string, int, std::vector<std::string>, bool);
    Pokemon(std::string, Species, int, std::vector<std::string>);
    Pokemon(std::string, Species, int, std::vector<std::string>, bool);
    py::str print();
    py::str get_nick();
    py::str get_species();
    py::int_ get_level();
    py::list get_moves();
    py::bool_ get_shiny();
    void set_lvl(int new_lvl);
    void add_move(std::string new_move);
    void del_move(std::string old_move);
};

#endif
