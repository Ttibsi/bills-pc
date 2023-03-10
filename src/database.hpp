#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

#include "Pokemon.hpp"

std::vector<Pokemon> get_from_db(std::string cmd);
void insert_db(std::string cmd);
bool connection_is_active();
int deleteFromTable(std::string statement);

#endif
