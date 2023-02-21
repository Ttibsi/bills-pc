#include <iostream>
#include <string>
#include <vector>

#include "Pokemon.hpp"
#include "database.hpp"
#include "sqlite3.h"

// The implementation of this function was iterated on with ChatGPT
void insert_db(std::string cmd) {
    sqlite3 *db;
    const auto res = sqlite3_open("./db.db", &db);
    if (res != SQLITE_OK) {
        std::cerr << "Database error\n";
        return;
    }

    char *errMsg = nullptr;
    int rc = sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to begin transaction: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, cmd.c_str(), NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to execute statement: " << errMsg << "\n";
        sqlite3_free(errMsg);
        sqlite3_exec(db, "ROLLBACK", NULL, NULL, NULL);
        sqlite3_close(db);
        return;
    }

    rc = sqlite3_exec(db, "COMMIT", NULL, NULL, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to commit transaction: " << errMsg << "\n";
        sqlite3_free(errMsg);
    }

    sqlite3_close(db);
}

std::vector<Pokemon> get_from_db(std::string statement) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    std::vector<Pokemon> results;

    // Open database connection
    int rc = sqlite3_open("db.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db)
                  << std::endl;
        return results;
    }

    // Prepare statement
    if (sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, nullptr) !=
        SQLITE_OK) {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db)
                  << std::endl;
        sqlite3_close(db);
        return results;
    }

    // Get number of columns in result set
    int numCols = sqlite3_column_count(stmt);

    // Fetch result set
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < numCols; i++) {
            const char *columnValue =
                (const char *)sqlite3_column_text(stmt, i);
            if (columnValue == nullptr) {
                row.push_back("NULL");
            } else {
                row.push_back(columnValue);
            }
        }
        Pokemon pkmn = Pokemon{
            std::stoi(row[0]), // id
            row[1],            // nickname
            row[2],            // species
            std::stoi(row[3]), // lvl
            std::vector{row[4], row[5], row[6], row[7]},
            (row.back() == std::string("1") ? true : false) // shiny
        };
        results.push_back(pkmn);
    }

    // Finalize statement and close database connection
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return results;
}

bool connection_is_active() {
    sqlite3 *db;
    int rc = sqlite3_open_v2("db.db", &db, SQLITE_OPEN_READONLY, nullptr);

    if (rc == SQLITE_OK) {
        sqlite3_close(db);
        return false;
    } else {
        return true;
    }
}
