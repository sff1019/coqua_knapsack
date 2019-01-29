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

bool check_cap(float weight, float min_cap, float max_cap) {
  return (min_cap <= weight && weight <= max_cap) ? true : false;
}

bool check_size(int size, int comb_num) {
  return (size == comb_num) ? true : false;
}

int find_max_element(std::vector<float>weight, int max_element, int len) {
  for (int i = max_element; i < len; i ++) {
    if (weight[i] != -1) {
      return i;
    }
  }

  return 0;
}

/*
 * Return list of the ids of the elements included
 * Only limited elements can be included
 */
std::vector<std::vector<int>> single_limited_greedy_solver(
    float cap, // capacity
    int len, // length of weight/val/id
    int comb_num,
    std::vector<float> weight,
    std::vector<float> val,
    std::vector<int> id
) {
	int counter = 0;
  int max_element = 0;
  float min_cap = cap - (cap / 10);
  float max_cap = cap + (cap / 10);
	std::vector<std::vector<int>> sols;

	while(counter < 10) {
		std::vector<int> sol;
		float sum_weight = 0;

		for (int i = 0; i < len; i ++) {
      // If no combinations can be added upto cap
      if (weight[max_element] * comb_num < cap){
        return sols;
      }

			if (weight[i] > 0 && sum_weight + weight[i] <= cap) {
				sum_weight += weight[i];
        sol.push_back(id[i]);
				weight[i] = -1;
        max_element = find_max_element(weight, max_element, len);
      } else if (weight[i] > cap) {
        weight[i] = -1;
        max_element = find_max_element(weight, max_element, len);
      }

      if ((int)sol.size() == comb_num) break;
		}

    if ((check_size((int)sol.size(), comb_num) && check_cap(sum_weight, min_cap, max_cap)) && !sol.empty()) {
      sols.push_back(sol);
      counter++;
    }
	}

	return sols;
}

