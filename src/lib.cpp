#include <pybind11/pybind11.h>
namespace py = pybind11;

int add(int x, int y) { return x + y; }

PYBIND11_MODULE(bpc_cpp, m) {
    m.def("add_two", &add);
}
