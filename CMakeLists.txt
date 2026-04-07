cmake_minimum_required(VERSION 3.26)
project(COP4533_PA3)

set(CMAKE_CXX_STANDARD 14)

add_executable(main
        src/main.cpp
        src/algo.cpp)

add_executable(test
        test/test.cpp
        src/algo.cpp)