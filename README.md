# Knapsack Problem Solver

## Intro

A knapsack problem solving library that fits with the current project I am working on.  
It uses knapsack problem solving approaches, but some of the algorithms are changed.

## Environment

OS: `macOS Mojave 10.14.2`  
python: `pyenv:python3.6.5`  
pybind11: `2.2.3`

## Command

```
$ clang++ -O3 -Wall -shared -std=c++11 -fPIC `python -m pybind11 --includes` -undefined dynamic_lookup [filename] -o [filename /out .cpp]`python3-config --extension-suffix`

```

## Knapsack
![Knapsack Illustration](./assets/knapsack.png)

Knapsack problem is one of the most famous combinatorial optimization problem.  


## knapsack_dynamic.cpp

Solving knapsack problem using dynamic problem approach.

## knapsack_greedy.cpp

Solving knapsack problem using greedy algorithm approach.
