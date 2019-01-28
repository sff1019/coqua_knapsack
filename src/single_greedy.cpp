#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

/*
 * Return list of the ids of the elements included
 */
std::vector<std::vector<int>> single_greedy_solver(
    float cap, // capacity
    int len, // length of weight/val/id
    std::vector<float> weight,
    std::vector<float> val,
    std::vector<int> id
) {
	int counter = 0;
	std::vector<std::vector<int>> sols(10);

	while(counter < 10) {
		std::vector<int> sol;
		float sum_weight = 0;
		float sum_val = 0;

		for (int i = 0; i < len; i ++) {
			if (weight[i] > 0 && sum_weight + weight[i] <= cap) {
				sum_weight += weight[i];
				sum_val += val[i];
        sol.push_back(id[i]);
				weight[i] = -1;
			}
		}
		sols[counter++] = sol;
	}

	return sols;
}

/*
 * Return list of the ids of the elements included
 * Only limited elements can be included
 */
std::vector<std::vector<int>> single_limited_greedy_solver(
    float cap, // capacity
    int len, // length of weight/val/id
    int max,
    std::vector<float> weight,
    std::vector<float> val,
    std::vector<int> id
) {
	int counter = 0;
	std::vector<std::vector<int>> sols;

	while(counter < 10) {
		std::vector<int> sol;
		float sum_weight = 0;
		float sum_val = 0;

		for (int i = 0; i < len; i ++) {
			if (weight[i] > 0 && sum_weight + weight[i] <= cap) {
				sum_weight += weight[i];
				sum_val += val[i];
        sol.push_back(id[i]);
				weight[i] = -1;
			}
		}

    if ((int)sol.size() == max && !sol.empty()) {
      sols.push_back(sol);
      counter ++;
    }
	}

	return sols;
}

