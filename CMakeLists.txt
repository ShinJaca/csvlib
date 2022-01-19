cmake_minimum_required(VERSION 3.11)

project(csvlib
    LANGUAGES CXX
    VERSION 0.0.1
)

add_library(csvlib
    src/csv.cpp
)
