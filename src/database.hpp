#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>

std::vector<std::string> get_from_db(std::string cmd);
void insert_db(std::string cmd);

#endif
