#ifndef POKEMON_H
#define POKEMON_H

#include <algorithm>
#include <cctype>
#include <iostream>
#include <pybind11/stl.h>
#include <string>
#include <vector>

#include "Species.hpp"
#include "database.hpp"

namespace py = pybind11;
void inline insert_pkmn(std::string nick, std::string species, int lvl,
                        std::vector<std::string> moves, bool is_shiny);

struct Pokemon {
    std::string nickname;
    Species species;
    int lvl;
    std::vector<std::string> moves;
    bool is_shiny;

    // Methods
    Pokemon(std::string name, std::string species, int lvl,
            std::vector<std::string> move_lst);
    Pokemon(std::string name, std::string species, int lvl,
            std::vector<std::string> move_lst, bool shiny);
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

// Constructor
inline Pokemon::Pokemon(std::string name, std::string species, int lvl,
                        std::vector<std::string> move_lst) {
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = false;
    insert_pkmn(name, species, lvl, move_lst, false);
}

inline Pokemon::Pokemon(std::string name, std::string species, int lvl,
                        std::vector<std::string> move_lst, bool shiny) {
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = shiny;
    insert_pkmn(name, species, lvl, move_lst, is_shiny);
}

py::str inline Pokemon::print() {
    std::string os = "Pokemon{" + this->nickname + ", " +
                     species_stringify(this->species) + ", lvl " +
                     std::to_string(this->lvl) +
                     ", Shiny: " + (this->is_shiny ? "True" : "False") + ", [";

    for (std::string &i : this->moves) {
        os += i;
        if (!(&i == &this->moves.back()))
            os += ", ";
    }

    os += "]}";

    return py::cast(os);
}

py::str inline Pokemon::get_nick() { return py::cast(this->nickname); }
py::str inline Pokemon::get_species() {
    return py::cast(species_stringify(this->species));
}
py::int_ inline Pokemon::get_level() { return py::cast(this->lvl); }
py::list inline Pokemon::get_moves() { return py::cast(this->moves); }
py::bool_ inline Pokemon::get_shiny() { return py::cast(this->is_shiny); }

void inline Pokemon::set_lvl(int new_lvl) {
    if (1 <= new_lvl && new_lvl <= 100) {
        this->lvl = new_lvl;
        std::cout << "level set as " << new_lvl << "\n";
    } else {
        std::cerr << "Level value out of range 1-100\n";
    }
}

void inline Pokemon::add_move(std::string new_move) {
    if (this->moves.size() >= 4) {
        std::cerr << "Move list full. Remove move first\n";
    } else {
        new_move[0] = std::toupper(new_move[0]);
        this->moves.push_back(new_move);
        std::cout << new_move << " added\n";
    }
}

void inline Pokemon::del_move(std::string old_move) {
    auto mvs = this->moves;
    if (std::find(mvs.begin(), mvs.end(), old_move) != mvs.end()) {
        old_move[0] = std::toupper(old_move[0]);
        std::remove(mvs.begin(), mvs.end(), old_move);
    } else {
        std::cerr << "move not found: " << old_move << "\n";
    }
}

// -----------
// Standalone functions

void inline insert_pkmn(std::string nick, std::string species, int lvl,
                        std::vector<std::string> moves, bool is_shiny) {
    std::string cmd = std::string("INSERT INTO STORAGE VALUES (NULL, '") +=
        std::string(nick.empty() ? "NULL" : nick) += std::string("', '") +=
        species += std::string("', ") += std::to_string(lvl) +=
        std::string(", ");
    for (std::string &i : moves) {
        cmd += std::string("'") += i += std::string("'");
        if (!(&i == &moves.back()))
            cmd += std::string(", ");
    }

    if (moves.size() < 4) {
        cmd += std::string(", ");
        for (int i = moves.size(); i < 4; i++) {
            cmd += std::string("NULL, ");
        }
    } else {
        cmd += std::string(", ");
    }

    cmd += std::string(is_shiny ? "True" : "False") += std::string(");");
    insert_db(cmd);
}

#endif
