#include <pybind11/pybind11.h>
#include <SQLiteCpp/SQLiteCpp.h>
#include <string>
#include <vector>
namespace py = pybind11;

int add(int x, int y) { return x + y; }

std::vector<std::string> get_from_db() {
    std::vector<std::string> ret;
    try {
        // Open a database file
        SQLite::Database    db = "db.db";
        
        // Compile a SQL query, containing one parameter (index 1)
        SQLite::Statement   query(db, "SELECT * FROM ABILITIES");
        
        // Bind the integer value 6 to the first parameter of the SQL query
        query.bind(1, 6);
        
        // Loop to execute the query step by step, to get rows of result
        while (query.executeStep())
        {
            // Demonstrate how to get some typed column value
            int         id      = query.getColumn(0);
            std::string value   = query.getColumn(1);
            std::string size    = query.getColumn(2);

            ret.push_back(std::string(id));
            ret.push_back(value);
            ret.push_back(size);
        }
    }
    catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }

    return ret;
}

PYBIND11_MODULE(bpc_cpp, m) {
    m.def("add_two", &add);
    m.def("get_from_db", &get_from_db);
}
