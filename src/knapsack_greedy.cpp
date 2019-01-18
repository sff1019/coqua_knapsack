#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

std::vector<std::vector<int>> greedy_solver(float cap, std::vector<float> weight, std::vector<float> val, int len) {
	int counter = 0;
	std::vector<std::vector<int>> sols(10);

	while(counter < 10) {
		std::vector<int> sol(len);
		float sum_weight = 0;
		float sum_val = 0;
		for (int i = 0; i < len; i ++) {
			if (weight[i] > 0 && sum_weight + weight[i] <= cap) {
				sum_weight += weight[i];
				sum_val += val[i];
				sol[i] = 1;
				weight[i] = -1;
			} else {
				sol[i] = 0;
			}
		}
		sols[counter++] = sol;
	}

	return sols;
}
//
// PYBIND11_MODULE(knapsack, m) {
//   m.doc() = "pybind11 example plugin"; // optional module docstring
// 	m.def("greedy_solver", &greedy_solver);
// }
