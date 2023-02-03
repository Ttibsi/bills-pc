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
    Pokemon(std::string name, Species species, int lvl,
            std::vector<std::string> move_lst);
    Pokemon(std::string name, Species species, int lvl,
            std::vector<std::string> move_lst, bool shiny);
    py::str get_nick();
    py::str get_species();
    py::int_ get_level();
    py::list get_moves();
    py::bool_ get_shiny();
};

// Constructor
inline Pokemon::Pokemon(std::string name, Species species, int lvl,
                        std::vector<std::string> move_lst)
    : nickname{name}, species{species}, lvl{lvl}, moves{move_lst} {
    this->is_shiny = false;
}

inline Pokemon::Pokemon(std::string name, Species species, int lvl,
                        std::vector<std::string> move_lst, bool shiny)
    : nickname{name}, species{species}, lvl{lvl}, moves{move_lst},
      is_shiny(shiny) {}

py::str inline Pokemon::get_nick() { return py::cast(this->nickname); }
py::str inline Pokemon::get_species() {
    return py::cast(species_stringify(this->species));
}
py::int_ inline Pokemon::get_level() { return py::cast(this->lvl); }
py::list inline Pokemon::get_moves() { return py::cast(this->moves); }
py::bool_ inline Pokemon::get_shiny() { return py::cast(this->is_shiny); }

#endif
