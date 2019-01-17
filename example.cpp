#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

void append_1(std::vector<int> &v) {
   v.push_back(1);
}

void print_list(std::vector<int> my_list) {
	// std::cout << my_list(1);
	for (int i=0; i < 3; i++) {
		if (my_list[i] > 1) {
			py::print(my_list[i]);
		}
	}
	for (auto item : my_list)
		std::cout << item << "\n";
}

PYBIND11_MODULE(example, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("add", &add, "A function which adds two numbers");
	m.def("append_1", & append_1);
	m.def("print_list", &print_list);
}
