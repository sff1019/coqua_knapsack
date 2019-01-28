#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

/*
 * Return list of the ids of the elements included
 */
std::vector<std::vector<int>> multiple_greedy_solver(
    std::vector<float> cap, // capacity
    int len, // length of weight/val/id
    int num_lst, // number of lists
    std::vector<std::vector<float>> weight,
    std::vector<float> val,
    std::vector<int> id
) {
	int counter = 0;
	std::vector<std::vector<int>> sols(10);

	while(counter < 10) {
		std::vector<int> sol;
    std::vector<float> sum_weight;

		for (int i = 0; i < len; i ++) {
      if (check_okay(i, cap, num_lst, weight, sum_weight) == 1) {
        for (int j = 0; j < num_lst; j++) {
          sum_weight[j] += weight[j][i];
          weight[j][i] = -1;
        }
        sol.push_back(id[i]);
      }
		}
		sols[counter++] = sol;
	}

	return sols;
}
