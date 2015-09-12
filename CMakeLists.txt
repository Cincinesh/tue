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
    include/tue/detail_/mat2xR.hpp
    include/tue/detail_/mat3xR.hpp
    include/tue/detail_/mat4xR.hpp
    include/tue/detail_/matmult.hpp
    include/tue/detail_/vec2.hpp
    include/tue/detail_/vec3.hpp
    include/tue/detail_/vec4.hpp
    include/tue/mat.hpp
    include/tue/math.hpp
    include/tue/quat.hpp
    include/tue/simd.hpp
    include/tue/sized_bool.hpp
    include/tue/transform.hpp
    include/tue/unused.hpp
    include/tue/vec.hpp)

# tue.tests
set(TUE_TEST_SOURCES
    tests/mat2xR.tests.cpp
    tests/mat3xR.tests.cpp
    tests/mat4xR.tests.cpp
    tests/matmult.tests.cpp
    tests/math.tests.cpp
    tests/quat.tests.cpp
    tests/sized_bool.tests.cpp
    tests/transform.tests.cpp
    tests/unused.tests.cpp
    tests/vec2.tests.cpp
    tests/vec3.tests.cpp
    tests/vec4.tests.cpp)

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
