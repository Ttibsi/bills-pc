#include <iostream>
#include <pybind11/pybind11.h>
#include <sqlite3.h>
#include <string>
#include <vector>
namespace py = pybind11;

int add(int x, int y) { return x + y; }

std::vector<std::string> get_from_db() {
    std::vector<std::string> ret;
    sqlite3* db;
    const auto res = sqlite3_open("./db.db", &db);
    if (res != SQLITE_OK) { 
        std::cerr << "Database error\n";
        return ret;
    }

    std::string stmt = "SELECT * FROM ABILITIES;";
    // sqlite3_prepare_v2(db, )

    sqlite3_close(db);
    return ret;
}

PYBIND11_MODULE(bpc_cpp, m) {
    m.def("add_two", &add);
    m.def("get_from_db", &get_from_db);
}
