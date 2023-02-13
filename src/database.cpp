#include <iostream>
#include <string>
#include <vector>

#include "Pokemon.hpp"
#include "database.hpp"
#include "sqlite3.h"

void insert_db(std::string cmd) {
    sqlite3 *db;
    const auto res = sqlite3_open("./db.db", &db);
    if (res != SQLITE_OK) {
        std::cerr << "Database error\n";
        return;
    }

    sqlite3_stmt *pStmt;
    int rc = sqlite3_prepare(db, cmd.c_str(), -1, &pStmt, 0);
    if (rc != SQLITE_OK) {
        std::cout << "Cannot prepare statement: " << sqlite3_errmsg(db) << "\n";
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_step(pStmt);
    if (rc != SQLITE_DONE) {
        std::cout << "Execution failed: " << sqlite3_errmsg(db);
    }

    sqlite3_finalize(pStmt);
    sqlite3_close(db);
    return;
}

std::vector<std::string> make_move_list(std::vector<std::string> params) {
    std::vector<std::string> sublst(params.begin() + 4, params.end() - 1);
    int len = sublst.size();
    while (len < 4) {
        sublst.push_back(std::string("NULL"));
    }
    return sublst;
}

std::vector<Pokemon> get_from_db(std::string cmd) {
    std::vector<Pokemon> ret;
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
        std::vector<std::string> row_contents;
        for (int i = 0; i < sqlite3_column_count(stmt); i++) {
            row_contents.push_back(std::string(
                reinterpret_cast<const char *>(sqlite3_column_text(stmt, i))));
        }

        std::vector<std::string> moves = make_move_list(row_contents);
        Pokemon pkmn = Pokemon(
            row_contents[1],            // nickname
            row_contents[2],            // species
            std::stoi(row_contents[3]), // lvl
            moves,                      // moves
            (row_contents.back() == std::string("1") ? true : false)); // shiny
        ret.push_back(pkmn);
    }
    if (rc != SQLITE_DONE) {
        std::cerr << "error: " << sqlite3_errmsg(db);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return ret;
}
