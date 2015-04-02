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
  boolx4 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  test_assert(boolx4(true) == boolx4(true, true, true, true));
  test_assert(boolx4(false) == boolx4(false, false, false, false));
}

TEST_CASE(component_constructor) {
  // Covered by other test cases
}

TEST_CASE(not_operator) {
  const boolx4 v(true, false, true, false);
  test_assert(~v == boolx4(false, true, false, true));
}

TEST_CASE(and_operator) {
  const boolx4 v1(true, true, true, true);
  const boolx4 v2(false, false, false, false);
  const boolx4 v3(true, false, true, false);
  const boolx4 v4(false, true, false, true);
  test_assert((v1 & v2) == boolx4(false, false, false, false));
  test_assert((v1 & v3) == boolx4(true, false, true, false));
  test_assert((v1 & v4) == boolx4(false, true, false, true));
  test_assert((v2 & v3) == boolx4(false, false, false, false));
  test_assert((v2 & v4) == boolx4(false, false, false, false));
  test_assert((v3 & v4) == boolx4(false, false, false, false));
}

TEST_CASE(or_operator) {
  const boolx4 v1(true, true, true, true);
  const boolx4 v2(false, false, false, false);
  const boolx4 v3(true, false, true, false);
  const boolx4 v4(false, true, false, true);
  test_assert((v1 | v2) == boolx4(true, true, true, true));
  test_assert((v1 | v3) == boolx4(true, true, true, true));
  test_assert((v1 | v4) == boolx4(true, true, true, true));
  test_assert((v2 | v3) == boolx4(true, false, true, false));
  test_assert((v2 | v4) == boolx4(false, true, false, true));
  test_assert((v3 | v4) == boolx4(true, true, true, true));
}

TEST_CASE(xor_operator) {
  const boolx4 v1(true, true, true, true);
  const boolx4 v2(false, false, false, false);
  const boolx4 v3(true, false, true, false);
  const boolx4 v4(false, true, false, true);
  test_assert((v1 ^ v2) == boolx4(true, true, true, true));
  test_assert((v1 ^ v3) == boolx4(false, true, false, true));
  test_assert((v1 ^ v4) == boolx4(true, false, true, false));
  test_assert((v2 ^ v3) == boolx4(true, false, true, false));
  test_assert((v2 ^ v4) == boolx4(false, true, false, true));
  test_assert((v3 ^ v4) == boolx4(true, true, true, true));
}

TEST_CASE(and_assignment_operator) {
  boolx4 v1(true, true, false, false);
  const boolx4 v2(true, false, true, false);
  test_assert(&(v1 &= v2) == &v1);
  test_assert(v1 == boolx4(true, false, false, false));
}

TEST_CASE(or_assignment_operator) {
  boolx4 v1(true, true, false, false);
  const boolx4 v2(true, false, true, false);
  test_assert(&(v1 |= v2) == &v1);
  test_assert(v1 == boolx4(true, true, true, false));
}

TEST_CASE(xor_assignment_operator) {
  boolx4 v1(true, true, false, false);
  const boolx4 v2(true, false, true, false);
  test_assert(&(v1 ^= v2) == &v1);
  test_assert(v1 == boolx4(false, true, true, false));
}

TEST_CASE(equality_operator) {
  const boolx4 v1(true, true, true, true);
  const boolx4 v2(true, true, true, true);
  const boolx4 v3(false, true, true, true);
  const boolx4 v4(true, false, true, true);
  const boolx4 v5(true, true, false, true);
  const boolx4 v6(true, true, true, false);
  test_assert((v1 == v2) == true);
  test_assert((v1 == v3) == false);
  test_assert((v1 == v4) == false);
  test_assert((v1 == v5) == false);
  test_assert((v1 == v6) == false);
}

TEST_CASE(inequality_operator) {
  const boolx4 v1(true, true, true, true);
  const boolx4 v2(true, true, true, true);
  const boolx4 v3(false, true, true, true);
  const boolx4 v4(true, false, true, true);
  const boolx4 v5(true, true, false, true);
  const boolx4 v6(true, true, true, false);
  test_assert((v1 != v2) == false);
  test_assert((v1 != v3) == true);
  test_assert((v1 != v4) == true);
  test_assert((v1 != v5) == true);
  test_assert((v1 != v6) == true);
}

}
