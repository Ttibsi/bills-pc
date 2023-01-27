#include <iostream>
#include <pybind11/pybind11.h>
#include <sqlite3.h>
#include <string>
#include <vector>
namespace py = pybind11;

int add(int x, int y) { return x + y; }

std::vector<std::string> get_from_db(std::string cmd) {
    std::vector<std::string> ret;
    sqlite3 *db;
    const auto res = sqlite3_open("./db.db", &db);
    if (res != SQLITE_OK) {
        std::cerr << "Database error\n";
        return ret;
    }

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, cmd.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        std::cerr << "error: " << sqlite3_errmsg(db);
        return ret;
    }
    
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        ret.push_back(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    if (rc != SQLITE_DONE) {
        std::cerr << "error: " << sqlite3_errmsg(db);
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);
    return ret;
}

PYBIND11_MODULE(bpc_cpp, m) {
    m.def("add_two", &add);
    m.def("get_from_db", &get_from_db);
}
