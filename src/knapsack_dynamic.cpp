#include <pybind11/stl.h>

namespace py = pybind11;

int max(float a, float b) {
	return (a > b) ? a : b;
}

void knapsack_combination_solver(int len, float capacity, std::vector<float> weight, std::vector<std::vector<float>> table) {
	float sum = capacity;
	int flag[len+1];

	for (int i = len; i >= 0; i--) {
		if (i != 0 && table[i][sum] != table[i-1][sum]) {
			sum -= weight[i-1];
			flag[i] = 1;
		} else {
			flag[i] = 0;
		}
	}

	printf("Index of items used: ");
	for (int i = 0; i < len+1; i++) {
		if (flag[i]) printf("%d ", i);
	}
	printf("\n");

}

float dynamic_solver(float cap, std::vector<float> weight, std::vector<float> val, int len) {
	std::vector<std::vector<float> > K(len+1);

	for (int i = 0; i < len+1; i++) {
		K[i] = std::vector<float>(cap+1);
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
	printf("Total Value: ");
	return K[len][cap];
}
