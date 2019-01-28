#include <pybind11/pybind11.h>

#include "dynamic.cpp"
#include "single_greedy.cpp"
#include "multiple_greedy.cpp"

PYBIND11_MODULE(coqua_knapsack, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("max", &max, "A function that returns the larger number.");
	m.def("dynamic_solver", &dynamic_solver);
	m.def("single_greedy_solver", &single_greedy_solver);
  m.def("single_limited_greedy_solver", &single_limited_greedy_solver);
  m.def("multiple_greedy_solver", &multiple_greedy_solver);
}
