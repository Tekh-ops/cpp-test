cmake_minimum_required(VERSION 3.21.2)

set(This cpp_project_tests)

set (Sources
    mytests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    cpp_project
)

add_test(
    NAME ${This}
    COMMAND ${This}
)