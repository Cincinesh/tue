cmake_minimum_required(VERSION 3.3)
project(tue)
enable_testing()

set(CMAKE_CXX_STANDARD 14)

include_directories(
    lib/mon/include
    include)

# mon
set(MON_SOURCES
    lib/mon/include/mon/test_case.hpp
    lib/mon/include/mon/test_failure.hpp
    lib/mon/include/mon/test_runner.hpp
    lib/mon/src/main.cpp
    lib/mon/src/mon.test_case.cpp
    lib/mon/src/mon.test_failure.cpp
    lib/mon/src/mon.test_runner.cpp)

# tue
set(TUE_SOURCES
    include/tue/math.hpp)

# tue.tests
set(TUE_TEST_SOURCES
    tests/math.tests.cpp)

add_executable(
    tue.tests
    ${MON_SOURCES}
    ${TUE_SOURCES}
    ${TUE_TEST_SOURCES})

add_test(
    tue.tests
    tue.tests)

# check
add_custom_target(
    check
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS tue.tests)
