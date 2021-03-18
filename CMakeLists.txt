cmake_minimum_required(VERSION 3.17)
project(student_r_w C)

set(CMAKE_C_STANDARD 11)

add_executable(student_r_w main.c Student.c Student.h)