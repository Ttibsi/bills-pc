#include <pybind11/stl.h>
namespace py = pybind11;

#include "Pokemon.hpp"
#include "database.hpp"
#include "db_interface.hpp"

void insert_pkmn(std::string nick, std::string species, int lvl,
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

py::list get_storage() {
    std::string cmd = "SELECT * FROM STORAGE;";
    std::vector<Pokemon> ret = get_from_db(cmd);
    return py::cast(ret);
}
