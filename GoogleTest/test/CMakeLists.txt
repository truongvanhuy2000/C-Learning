cmake_minimum_required(VERSION 3.23)

set(This ParametterizedTest)
set(Sources
ParametterizedTest.cpp
)
add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    gmock_main
)
add_test(
    NAME ${This}
    COMMAND ${This}
)