cmake_minimum_required(VERSION 3.18.0)

project(hellompi)

find_package(MPI)

include_directories(SYSTEM ${MPI_INCLUDE_PATH})

add_executable(hellompi hello.cpp)