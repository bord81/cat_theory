cmake_minimum_required(VERSION 3.15)
project(cat_theory)

set(CMAKE_CXX_STANDARD 17)

add_executable(cat_theory main.cpp optional.h safe_functions.cpp either.h coproduct.cpp alg_types.cpp sum_type.h sum_type.cpp)