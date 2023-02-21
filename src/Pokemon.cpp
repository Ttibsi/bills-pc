#include <algorithm>
#include <cctype>
#include <iostream>
#include <pybind11/stl.h>
#include <string>
#include <vector>

#include "Pokemon.hpp"
#include "Species.hpp"
#include "database.hpp"
#include "db_interface.hpp"

// TODO: Verify Pokemon level is legal for species in constructors
// TODO: Verify moves are legal to species and level
// This can probably be implemented with a Moves table with all legal moves
// and a PokemonMoves table that holds all legal moves (via FK) for that
// pkmn and the level it learns it at (or 0 for egg move/starting move)

// Constructor
Pokemon::Pokemon(std::string name, std::string species, int lvl,
                 std::vector<std::string> move_lst) {
    this->id = 0;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = false;

    if (!(connection_is_active())) {
        insert_pkmn(name, species, lvl, move_lst, is_shiny);
    }
}

Pokemon::Pokemon(std::string name, std::string species, int lvl,
                 std::vector<std::string> move_lst, bool shiny) {
    this->id = 0;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = shiny;

    if (!(connection_is_active())) {
        insert_pkmn(name, species, lvl, move_lst, is_shiny);
    }
}

Pokemon::Pokemon(int id, std::string name, std::string species, int lvl,
                 std::vector<std::string> move_lst) {
    this->id = id;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = false;
}

Pokemon::Pokemon(int id, std::string name, std::string species, int lvl,
                 std::vector<std::string> move_lst, bool shiny) {
    this->id = id;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = to_species(species);
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = shiny;
}

Pokemon::Pokemon(std::string name, Species spec, int lvl,
                 std::vector<std::string> move_lst) {
    this->id = 0;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = spec;
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = false;

    if (!(connection_is_active())) {
        insert_pkmn(name, species_stringify(spec), lvl, move_lst, is_shiny);
    }
}

Pokemon::Pokemon(std::string name, Species spec, int lvl,
                 std::vector<std::string> move_lst, bool shiny) {
    this->id = 0;
    this->nickname = (name.empty() ? "" : '"' + name + '"');
    this->species = spec;
    this->lvl = ((lvl > 0 && lvl < 101) ? lvl : -1);
    this->moves = move_lst;
    this->is_shiny = shiny;

    if (!(connection_is_active())) {
        insert_pkmn(name, species_stringify(spec), lvl, move_lst, is_shiny);
    }
}

py::str Pokemon::print() {
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

py::str Pokemon::get_nick() { return py::cast(this->nickname); }
py::str Pokemon::get_species() {
    return py::cast(species_stringify(this->species));
}
py::int_ Pokemon::get_level() { return py::cast(this->lvl); }
py::list Pokemon::get_moves() { return py::cast(this->moves); }
py::bool_ Pokemon::get_shiny() { return py::cast(this->is_shiny); }

void Pokemon::set_lvl(int new_lvl) {
    if (1 <= new_lvl && new_lvl <= 100) {
        this->lvl = new_lvl;
        std::cout << "level set as " << new_lvl << "\n";
    } else {
        std::cerr << "Level value out of range 1-100\n";
    }
}

void Pokemon::add_move(std::string new_move) {
    if (this->moves.size() >= 4) {
        std::cerr << "Move list full. Remove move first\n";
    } else {
        new_move[0] = std::toupper(new_move[0]);
        this->moves.push_back(new_move);
        std::cout << new_move << " added\n";
    }
}

void Pokemon::del_move(std::string old_move) {
    auto mvs = this->moves;
    if (std::find(mvs.begin(), mvs.end(), old_move) != mvs.end()) {
        old_move[0] = std::toupper(old_move[0]);
        std::remove(mvs.begin(), mvs.end(), old_move);
    } else {
        std::cerr << "move not found: " << old_move << "\n";
    }
}
