cmake_minimum_required(VERSION 3.5)
project(Red_Black_Tree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp RBTree.cpp RBTree.h)
add_executable(Red_Black_Tree ${SOURCE_FILES})