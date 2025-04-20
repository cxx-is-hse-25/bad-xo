cmake_minimum_required(VERSION 3.25)

project(bad-xo)

add_subdirectory(external)

add_executable(bad-xo main.cpp)

add_executable(bad-xo-tests test.cpp)
target_link_libraries(bad-xo-tests PUBLIC doctest)

enable_testing()
add_test(NAME bad-xo-tests COMMAND bad-xo-tests --force-colors -d)