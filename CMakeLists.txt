cmake_minimum_required(VERSION 3.25)
project(Company_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Company_1 main.cpp lib_1/Employee.h lib_1/Department.h lib_1/Company.h lib_1/Project.h)
