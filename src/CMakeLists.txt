cmake_minimum_required(VERSION 3.10 )

project(Main )

add_executable(mainLib Project.cpp)

find_package(Threads REQUIRED)
set_target_properties(
    mainLib PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(
    mainLib
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ ../ThreadPool
)
target_link_libraries(
    mainLib ThreadPool
    )
target_link_libraries(
    mainLib ${CMAKE_THREAD_LIBS_INIT}
)