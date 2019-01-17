#include <stdio.h>

int max(int a, int b);
int knapsack_solver(int cap, int weight[], int val[], int len);
void knapsack_combination_solver(int len, int capacity, int weight[], int table[len+1][capacity+1]);

int max(int a, int b) {
	return (a > b) ? a : b;
}

int knapsack_solver(int cap, int weight[], int val[], int len) {
	int K[len+1][cap+1];

	for (int i = 0; i < len+1; i++) {
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

void knapsack_combination_solver(int len, int capacity, int weight[], int table[len+1][capacity+1]) {
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

int main(void) {
	int weight[6] = {2, 1, 3, 2, 1, 5};
	int val[6] = {3, 2, 6, 1, 3, 85};

	printf("%d\n", knapsack_solver(8, weight, val, 6));

	return 0;
}
