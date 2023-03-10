#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

#include "Pokemon.hpp"
#include "Species.hpp"
#include "db_interface.hpp"

PYBIND11_MODULE(bpc_cpp, m) {
    m.def("get_storage", &get_storage);
    m.def("remove_pkmn", &remove_pkmn);
    py::class_<Pokemon>(m, "Pokemon")
        .def(
            py::init<std::string, std::string, int, std::vector<std::string>>())
        .def(py::init<std::string, std::string, int, std::vector<std::string>,
                      bool>())
        .def(py::init<int, std::string, std::string, int,
                      std::vector<std::string>>())
        .def(py::init<int, std::string, std::string, int,
                      std::vector<std::string>, bool>())
        .def(py::init<std::string, Species, int, std::vector<std::string>>())
        .def(py::init<std::string, Species, int, std::vector<std::string>,
                      bool>())
        .def_readonly("id", &Pokemon::id)
        .def_readonly("nickname", &Pokemon::nickname)
        .def_readonly("species", &Pokemon::species)
        .def_readonly("lvl", &Pokemon::lvl)
        .def_readonly("moves", &Pokemon::moves)
        .def_readonly("is_shiny", &Pokemon::is_shiny)
        .def("__repr__", &Pokemon::print)
        .def("get_nick", &Pokemon::get_nick)
        .def("get_species", &Pokemon::get_species)
        .def("get_level", &Pokemon::get_level)
        .def("get_moves", &Pokemon::get_moves)
        .def("get_shiny", &Pokemon::get_shiny)
        .def("set_lvl", &Pokemon::set_lvl)
        .def("add_move", &Pokemon::add_move)
        .def("del_move", &Pokemon::del_move);

    py::enum_<Species>(m, "Species")
        .value("Bulbasaur", Species::Bulbasaur)
        .value("Ivysaur", Species::Ivysaur)
        .value("Venusaur", Species::Venusaur)
        .value("Charmander", Species::Charmander)
        .value("Charmeleon", Species::Charmeleon)
        .value("Charizard", Species::Charizard)
        .value("Squirtle", Species::Squirtle)
        .value("Wartortle", Species::Wartortle)
        .value("Blastoise", Species::Blastoise)
        .value("Caterpie", Species::Caterpie)
        .value("Metapod", Species::Metapod)
        .value("Butterfree", Species::Butterfree)
        .value("Weedle", Species::Weedle)
        .value("Kakuna", Species::Kakuna)
        .value("Beedrill", Species::Beedrill)
        .value("Pidgey", Species::Pidgey)
        .value("Pidgeotto", Species::Pidgeotto)
        .value("Pidgeot", Species::Pidgeot)
        .value("Rattata", Species::Rattata)
        .value("Raticate", Species::Raticate)
        .value("Spearow", Species::Spearow)
        .value("Fearow", Species::Fearow)
        .value("Ekans", Species::Ekans)
        .value("Arbok", Species::Arbok)
        .value("Pikachu", Species::Pikachu)
        .value("Raichu", Species::Raichu)
        .value("Sandshrew", Species::Sandshrew)
        .value("Sandslash", Species::Sandslash)
        .value("NidoranF", Species::NidoranF)
        .value("Nidorina", Species::Nidorina)
        .value("Nidoqueen", Species::Nidoqueen)
        .value("NidoranM", Species::NidoranM)
        .value("Nidorino", Species::Nidorino)
        .value("Nidoking", Species::Nidoking)
        .value("Clefairy", Species::Clefairy)
        .value("Clefable", Species::Clefable)
        .value("Vulpix", Species::Vulpix)
        .value("Ninetales", Species::Ninetales)
        .value("Jigglypuff", Species::Jigglypuff)
        .value("Wigglytuff", Species::Wigglytuff)
        .value("Zubat", Species::Zubat)
        .value("Golbat", Species::Golbat)
        .value("Oddish", Species::Oddish)
        .value("Gloom", Species::Gloom)
        .value("Vileplume", Species::Vileplume)
        .value("Paras", Species::Paras)
        .value("Parasect", Species::Parasect)
        .value("Venonat", Species::Venonat)
        .value("Venomoth", Species::Venomoth)
        .value("Diglett", Species::Diglett)
        .value("Dugtrio", Species::Dugtrio)
        .value("Meowth", Species::Meowth)
        .value("Persian", Species::Persian)
        .value("Psyduck", Species::Psyduck)
        .value("Golduck", Species::Golduck)
        .value("Mankey", Species::Mankey)
        .value("Primeape", Species::Primeape)
        .value("Growlithe", Species::Growlithe)
        .value("Arcanine", Species::Arcanine)
        .value("Poliwag", Species::Poliwag)
        .value("Poliwhirl", Species::Poliwhirl)
        .value("Poliwrath", Species::Poliwrath)
        .value("Abra", Species::Abra)
        .value("Kadabra", Species::Kadabra)
        .value("Alakazam", Species::Alakazam)
        .value("Machop", Species::Machop)
        .value("Machoke", Species::Machoke)
        .value("Machamp", Species::Machamp)
        .value("Bellsprout", Species::Bellsprout)
        .value("Weepinbell", Species::Weepinbell)
        .value("Victreebel", Species::Victreebel)
        .value("Tentacool", Species::Tentacool)
        .value("Tentacruel", Species::Tentacruel)
        .value("Geodude", Species::Geodude)
        .value("Graveler", Species::Graveler)
        .value("Golem", Species::Golem)
        .value("Ponyta", Species::Ponyta)
        .value("Rapidash", Species::Rapidash)
        .value("Slowpoke", Species::Slowpoke)
        .value("Slowbro", Species::Slowbro)
        .value("Magnemite", Species::Magnemite)
        .value("Magneton", Species::Magneton)
        .value("Farfetchd", Species::Farfetchd)
        .value("Doduo", Species::Doduo)
        .value("Dodrio", Species::Dodrio)
        .value("Seel", Species::Seel)
        .value("Dewgong", Species::Dewgong)
        .value("Grimer", Species::Grimer)
        .value("Muk", Species::Muk)
        .value("Shellder", Species::Shellder)
        .value("Cloyster", Species::Cloyster)
        .value("Gastly", Species::Gastly)
        .value("Haunter", Species::Haunter)
        .value("Gengar", Species::Gengar)
        .value("Onix", Species::Onix)
        .value("Drowzee", Species::Drowzee)
        .value("Hypno", Species::Hypno)
        .value("Krabby", Species::Krabby)
        .value("Kingler", Species::Kingler)
        .value("Voltorb", Species::Voltorb)
        .value("Electrode", Species::Electrode)
        .value("Exeggcute", Species::Exeggcute)
        .value("Exeggutor", Species::Exeggutor)
        .value("Cubone", Species::Cubone)
        .value("Marowak", Species::Marowak)
        .value("Hitmonlee", Species::Hitmonlee)
        .value("Hitmonchan", Species::Hitmonchan)
        .value("Lickitung", Species::Lickitung)
        .value("Koffing", Species::Koffing)
        .value("Weezing", Species::Weezing)
        .value("Rhyhorn", Species::Rhyhorn)
        .value("Rhydon", Species::Rhydon)
        .value("Chansey", Species::Chansey)
        .value("Tangela", Species::Tangela)
        .value("Kangaskhan", Species::Kangaskhan)
        .value("Horsea", Species::Horsea)
        .value("Seadra", Species::Seadra)
        .value("Goldeen", Species::Goldeen)
        .value("Seaking", Species::Seaking)
        .value("Staryu", Species::Staryu)
        .value("Starmie", Species::Starmie)
        .value("MrMime", Species::MrMime)
        .value("Scyther", Species::Scyther)
        .value("Jynx", Species::Jynx)
        .value("Electabuzz", Species::Electabuzz)
        .value("Magmar", Species::Magmar)
        .value("Pinsir", Species::Pinsir)
        .value("Tauros", Species::Tauros)
        .value("Magikarp", Species::Magikarp)
        .value("Gyarados", Species::Gyarados)
        .value("Lapras", Species::Lapras)
        .value("Ditto", Species::Ditto)
        .value("Eevee", Species::Eevee)
        .value("Vaporeon", Species::Vaporeon)
        .value("Jolteon", Species::Jolteon)
        .value("Flareon", Species::Flareon)
        .value("Porygon", Species::Porygon)
        .value("Omanyte", Species::Omanyte)
        .value("Omastar", Species::Omastar)
        .value("Kabuto", Species::Kabuto)
        .value("Kabutops", Species::Kabutops)
        .value("Aerodactyl", Species::Aerodactyl)
        .value("Snorlax", Species::Snorlax)
        .value("Articuno", Species::Articuno)
        .value("Zapdos", Species::Zapdos)
        .value("Moltres", Species::Moltres)
        .value("Dratini", Species::Dratini)
        .value("Dragonair", Species::Dragonair)
        .value("Dragonite", Species::Dragonite)
        .value("Mewtwo", Species::Mewtwo)
        .value("Mew", Species::Mew);
}
