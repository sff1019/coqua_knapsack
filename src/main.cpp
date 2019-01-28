#include <pybind11/pybind11.h>

#include "knapsack_dynamic.cpp"
#include "knapsack_greedy.cpp"

PYBIND11_MODULE(coqua_knapsack, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("max", &max, "A function that returns the larger number.");
	m.def("dynamic_solver", &dynamic_solver);
	m.def("greedy_solver", &greedy_solver);
  m.def("limited_greedy_solver", &limited_greedy_solver);
}
