cmake_minimum_required(VERSION 3.10 )

project(ThreadPool)

add_library(ThreadPool STATIC ThreadPool.cpp ThreadPool.h)

set_target_properties(
    ThreadPool PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(
    ThreadPool
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)