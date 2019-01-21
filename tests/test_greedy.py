import coqua_knapsack

if __name__ == '__main__':
    weight = [2, 1, 3, 2, 1, 5]
    val = [3, 2, 6, 1, 3, 85]

    print(coqua_knapsack.greedy_solver(8, weight, val, 6))
