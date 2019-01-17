cmake_minimum_required(VERSION 2.8.12)

project(coqua_knapsack)

# Set source directory
set(SOURCE_DIR "src/coqua_knapsack")

# Tell CMake that headers are also in SOURCE_DIR
include_directories(${SOURCE_DIR})

# Generate Python module
add_subdirectory(lib/pybind11)
pybind11_add_module(coqua_knapsack ${SOURCES} "${SOURCE_DIR}/bindings.cpp")
