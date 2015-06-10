//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/simd.hpp>
#include <mon/test_case.hpp>

#include <cstring>
#include <tue/math.hpp>
#include <tue/unused.hpp>

namespace {
using namespace tue;

TEST_CASE(default_constructor) {
  bool32x4 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  test_assert(bool32x4(true32) == bool32x4(true32, true32, true32, true32));
  test_assert(bool32x4(false32) == bool32x4(false32, false32, false32, false32));
}

TEST_CASE(component_constructor) {
  // Covered by other test cases
}

TEST_CASE(not_operator) {
  const bool32x4 v(true32, false32, true32, false32);
  test_assert(~v == bool32x4(false32, true32, false32, true32));
}

TEST_CASE(and_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 & v2) == bool32x4(false32, false32, false32, false32));
  test_assert((v1 & v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v1 & v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v2 & v3) == bool32x4(false32, false32, false32, false32));
  test_assert((v2 & v4) == bool32x4(false32, false32, false32, false32));
  test_assert((v3 & v4) == bool32x4(false32, false32, false32, false32));
}

TEST_CASE(or_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 | v2) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 | v3) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 | v4) == bool32x4(true32, true32, true32, true32));
  test_assert((v2 | v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 | v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v3 | v4) == bool32x4(true32, true32, true32, true32));
}

TEST_CASE(xor_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 ^ v2) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 ^ v3) == bool32x4(false32, true32, false32, true32));
  test_assert((v1 ^ v4) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 ^ v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 ^ v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v3 ^ v4) == bool32x4(true32, true32, true32, true32));
}

TEST_CASE(and_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 &= v2) == &v1);
  test_assert(v1 == bool32x4(true32, false32, false32, false32));
}

TEST_CASE(or_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 |= v2) == &v1);
  test_assert(v1 == bool32x4(true32, true32, true32, false32));
}

TEST_CASE(xor_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 ^= v2) == &v1);
  test_assert(v1 == bool32x4(false32, true32, true32, false32));
}

TEST_CASE(equality_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(true32, true32, true32, true32);
  const bool32x4 v3(false32, true32, true32, true32);
  const bool32x4 v4(true32, false32, true32, true32);
  const bool32x4 v5(true32, true32, false32, true32);
  const bool32x4 v6(true32, true32, true32, false32);
  test_assert((v1 == v2) == true);
  test_assert((v1 == v3) == false);
  test_assert((v1 == v4) == false);
  test_assert((v1 == v5) == false);
  test_assert((v1 == v6) == false);
}

TEST_CASE(inequality_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(true32, true32, true32, true32);
  const bool32x4 v3(false32, true32, true32, true32);
  const bool32x4 v4(true32, false32, true32, true32);
  const bool32x4 v5(true32, true32, false32, true32);
  const bool32x4 v6(true32, true32, true32, false32);
  test_assert((v1 != v2) == false);
  test_assert((v1 != v3) == true);
  test_assert((v1 != v4) == true);
  test_assert((v1 != v5) == true);
  test_assert((v1 != v6) == true);
}

}
