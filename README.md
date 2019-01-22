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

## knapsack_greedy.cpp

Solving knapsack problem using greedy algorithm approach.

```
import coqua_knapsack as ck

weight = [3, 2, 4, 1]
val = [100, 20, 60, 40]

ck.greedy_solver(5, weight, val, 4)
```

Returns 10 solutions' index

```
[[1, 1, 0, 0], [0, 0, 1, 1], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
```


## Refrence

setup.py: https://github.com/pybind/python_example
