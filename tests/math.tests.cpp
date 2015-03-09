//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/math.hpp>
#include <mon/test_case.hpp>

#include <cmath>

namespace {
using namespace tue;

TEST_CASE(sincos) {
  float fsin, fcos;
  math::sincos(1.23f, fsin, fcos);
  test_assert(fsin == math::sin(1.23f));
  test_assert(fcos == math::cos(1.23f));

  double isin, icos;
  math::sincos(123, isin, icos);
  test_assert(isin == math::sin(123.0));
  test_assert(icos == math::cos(123.0));
}

TEST_CASE(sin) {
  test_assert(math::sin(1.23f) == std::sin(1.23f));
  test_assert(math::sin(123) == math::sin(123.0));
}

TEST_CASE(cos) {
  test_assert(math::cos(1.23f) == std::cos(1.23f));
  test_assert(math::cos(123) == math::cos(123.0));
}

TEST_CASE(exp) {
  test_assert(math::exp(1.23f) == std::exp(1.23f));
  test_assert(math::exp(123) == math::exp(123.0));
}

TEST_CASE(log) {
  test_assert(math::log(1.23f) == std::log(1.23f));
  test_assert(math::log(123) == math::log(123.0));
}

TEST_CASE(pow) {
  test_assert(math::pow(1.23f, 4.56f)
      == std::pow(1.23f, 4.56f));
  test_assert(math::pow(1.23f, 4.56)
      == math::pow(static_cast<double>(1.23f), 4.56));
  test_assert(math::pow(1.23f, 4.56L)
      == math::pow(static_cast<long double>(1.23f), 4.56L));

  test_assert(math::pow(1.23, 4.56f)
      == math::pow(1.23, static_cast<double>(4.56f)));
  test_assert(math::pow(1.23, 4.56)
      == std::pow(1.23, 4.56));
  test_assert(math::pow(1.23, 4.56L)
      == math::pow(static_cast<long double>(1.23), 4.56L));

  test_assert(math::pow(1.23L, 4.56f)
      == math::pow(1.23L, static_cast<long double>(4.56f)));
  test_assert(math::pow(1.23L, 4.56)
      == math::pow(1.23L, static_cast<long double>(4.56)));
  test_assert(math::pow(1.23L, 4.56L)
      == std::pow(1.23L, 4.56L));

  test_assert(math::pow(123, 456)
      == math::pow(123.0, 456.0));
  test_assert(math::pow(123, 4.56f)
      == math::pow(123.0, static_cast<double>(4.56f)));
  test_assert(math::pow(123, 4.56)
      == math::pow(123.0, 4.56));
  test_assert(math::pow(123, 4.56L)
      == math::pow(123.0L, 4.56L));

  test_assert(math::pow(1.23f, 456)
      == math::pow(static_cast<double>(1.23f), 456.0));
  test_assert(math::pow(1.23, 456)
      == math::pow(1.23, 456.0));
  test_assert(math::pow(1.23L, 456)
      == math::pow(1.23L, 456.0L));
}

TEST_CASE(recip) {
  test_assert(math::recip(1.23f) == 1 / 1.23f);
  test_assert(math::recip(123) == math::recip(123.0));
}

TEST_CASE(sqrt) {
  test_assert(math::sqrt(1.23f) == std::sqrt(1.23f));
  test_assert(math::sqrt(123) == math::sqrt(123.0));
}

TEST_CASE(rsqrt) {
  test_assert(math::rsqrt(1.23f) == 1 / std::sqrt(1.23f));
  test_assert(math::rsqrt(123) == math::rsqrt(123.0));
}

TEST_CASE(min) {
  test_assert(math::min(1.23f, 4.56f) == 1.23f);
  test_assert(math::min(1.23f, -4.56f) == -4.56f);
  test_assert(math::min(123, 456) == 123);
  test_assert(math::min(123, -456) == -456);
}

TEST_CASE(max) {
  test_assert(math::max(1.23f, 4.56f) == 4.56f);
  test_assert(math::max(1.23f, -4.56f) == 1.23f);
  test_assert(math::max(123, 456) == 456);
  test_assert(math::max(123, -456) == 123);
}

TEST_CASE(abs) {
  test_assert(math::abs(-1.23f) == 1.23f);
  test_assert(math::abs(1.23f) == 1.23f);
  test_assert(math::abs(-123) == 123);
  test_assert(math::abs(123) == 123);
  test_assert(math::abs(123u) == 123u);
}

TEST_CASE(dot) {
  constexpr auto f = math::dot(1.23f, 4.56);
  test_assert(f == 1.23f * 4.56);

  constexpr auto i = math::dot(123, 456);
  test_assert(i == 123 * 456);
}

TEST_CASE(length2) {
  test_assert(math::length2(-1.23f) == -1.23f * -1.23f);
  test_assert(math::length2(-123) == math::length2(-123.0));
}

TEST_CASE(length) {
  test_assert(math::length(-1.23f) == math::sqrt(math::length2(-1.23f)));
  test_assert(math::length(-123) == math::length(-123.0));
}

TEST_CASE(normalize) {
  test_assert(math::normalize(-1.23f) == -1.23f / math::length(-1.23f));
  test_assert(math::normalize(-123) == math::normalize(-123.0));
}

TEST_CASE(select) {
  CONST_OR_CONSTEXPR float f1 = math::select(1.23f, true);
  CONST_OR_CONSTEXPR float f2 = math::select(1.23f, false);
  test_assert(f1 == 1.23f);
  test_assert(f2 == 0.0f);
}

TEST_CASE(less) {
  CONST_OR_CONSTEXPR bool b1 = math::less(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::less(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::less(1.23f, 4.56f);
  test_assert(b1 == false);
  test_assert(b2 == false);
  test_assert(b3 == true);
}

TEST_CASE(less_equal) {
  CONST_OR_CONSTEXPR bool b1 = math::less_equal(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::less_equal(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::less_equal(1.23f, 4.56f);
  test_assert(b1 == false);
  test_assert(b2 == true);
  test_assert(b3 == true);
}

TEST_CASE(greater) {
  CONST_OR_CONSTEXPR bool b1 = math::greater(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::greater(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::greater(1.23f, 4.56f);
  test_assert(b1 == true);
  test_assert(b2 == false);
  test_assert(b3 == false);
}

TEST_CASE(greater_equal) {
  CONST_OR_CONSTEXPR bool b1 = math::greater_equal(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::greater_equal(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::greater_equal(1.23f, 4.56f);
  test_assert(b1 == true);
  test_assert(b2 == true);
  test_assert(b3 == false);
}

TEST_CASE(equal) {
  CONST_OR_CONSTEXPR bool b1 = math::equal(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::equal(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::equal(1.23f, 4.56f);
  test_assert(b1 == false);
  test_assert(b2 == true);
  test_assert(b3 == false);
}

TEST_CASE(not_equal) {
  CONST_OR_CONSTEXPR bool b1 = math::not_equal(1.23f, -4.56f);
  CONST_OR_CONSTEXPR bool b2 = math::not_equal(1.23f, 1.23f);
  CONST_OR_CONSTEXPR bool b3 = math::not_equal(1.23f, 4.56f);
  test_assert(b1 == true);
  test_assert(b2 == false);
  test_assert(b3 == true);
}

}
