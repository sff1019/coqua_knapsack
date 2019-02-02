# Knapsack Problem Solver

## Intro

A knapsack problem solving library that fits with the current project I am working on.  
It uses knapsack problem solving approaches, but some of the algorithms are changed.

## Environment

OS: `macOS Mojave 10.14.2`  
python: `pyenv:python3.6.5`  
pybind11: `2.2.3`

## Knapsack
![Knapsack Illustration](./assets/knapsack.png)

Knapsack problem is one of the most famous combinatorial optimization problem.  

## Installation

1. Install `pybind11`
```
$ pip3 install pybind11
```

1. Clone this repository  
**SSH**  
```
$ git clone git@github.com:sff1019/coqua_knapsack.git
```

**HTTPS**  
```
$git clone https://github.com/sff1019/coqua_knapsack.git
```

2. pip install package  
From the parent directory install this package
```
$ pip install ./coqua_knapsack
```

## Useage Example

```
>>> import coqua_knapsack as ck
>>> ck.max(1,2)
2
```

### Modules

This library provides 5 modules:
- max(arg0: float, arg1: float) -> int
- dynamic_solver(arg0: float, arg1: List[float], arg2: List[float], arg3: int) -> float
- multiple_greedy_solver(arg0: List[float], arg1: int, arg2: int, arg3: List[List[float]], arg4: List[float], arg5: List[int]) -> List[List[int]]
- single_greedy_solver(arg0: float, arg1: int, arg2: List[float], arg3: List[float], arg4: List[int]) -> List[List[int]]
- single_limited_greedy_solver(arg0: float, arg1: int, arg2: int, arg3: List[float], arg4: List[float], arg5: List[int]) -> List[List[int]]

### Dynamic Programming Approach

Solving knapsack problem using dynamic problem approach.

```
import coqua_knapsack as ck

weight = [3, 2, 4, 1]
val = [100, 20, 60, 40]

ck.dynamic_solver(5, weight, val, 4)
```

Returns the index and total value of the optimized solution

```
Index of items used: 1 4
Totatl Value: 140.0
```

### Greedy Algorithm Approach

Solving knapsack problem using greedy algorithm approach.

### single_greedy_solver()

Simply solve problem using greedy algorithm.  
Only 1 list of weight/val/id is given.

```
import coqua_knapsack as ck

weight = [3, 2, 4, 1]
val = [100, 20, 60, 40]
id = [1,2,3,4]

ck.single_greedy_solver(5, 4, weight, val, id)
```

Returns maximum of 10 solutions' index

```
[[1, 2], [3, 4]]
```

### single_limited_greedy_solver()

Simply solve problem using greedy algorithm.
Only 1 list of weight/val/id is given.

```
import coqua_knapsack as ck

weight = [4, 2, 1, 4, 1, 1, 1]
val = [100, 20, 60, 40, 30, 60, 80]
id = [1,2,3,4, 5, 6, 7]

ck.single_greedy_solver(7, 4, 3, weight, val, id)
```

Returns maximum of 10 solutions' index

```
[[1, 2, 3],]
```

## Refrence

setup.py: https://github.com/pybind/python_example
