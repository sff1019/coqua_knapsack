#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

int max(int a, int b) {
	return (a > b) ? a : b;
}

void knapsack_combination_solver(int len, int capacity, std::vector<int> weight, std::vector<std::vector<int>> table) {
	int sum = capacity;
	int flag[len+1];

	for (int i = len; i >= 0; i--) {
		if (i != 0 && table[i][sum] != table[i-1][sum]) {
			sum -= weight[i-1];
			flag[i] = 1;
		} else {
			flag[i] = 0;
		}
	}

	for (int i = 0; i < len+1; i++) {
		if (flag[i]) printf("%d ", i);
	}
	printf("\n");

}

int knapsack_solver(int cap, std::vector<int> weight, std::vector<int> val, int len) {
	std::vector<std::vector<int> > K(len+1);

	for (int i = 0; i < len+1; i++) {
		K[i] = std::vector<int>(cap+1);
		for (int j = 0; j < cap+1; j++) {
			if (i == 0 || j == 0) {
				K[i][j] = 0;
			} else if (weight[i-1] <= j) {
				K[i][j] = max(K[i-1][j], K[i-1][j - weight[i-1]] + val[i-1]);
			} else {
				K[i][j] = K[i][j-1];
			}
		}
	}

	knapsack_combination_solver(len, cap, weight, K);
	return K[len][cap];
}

PYBIND11_MODULE(knapsack_dynamic, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("max", &max, "A function that returns the larger number.");
	m.def("knapsack_solver", &knapsack_solver);
}
