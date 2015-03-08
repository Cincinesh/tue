//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/size2d.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>

namespace {
using namespace tue;

TEST_CASE(default_constructor) {
  fsize2d size;
  unused(size);
}

TEST_CASE(component_constructor) {
  constexpr fsize2d size(1.1f, 2.2f);
  test_assert(size.width() == 1.1f);
  test_assert(size.height() == 2.2f);
}

TEST_CASE(explicit_conversion_constructor) {
  constexpr dsize2d dsize(1.1, 2.2);
  CONST_OR_CONSTEXPR fsize2d fsize(dsize);
  test_assert(fsize.width() == static_cast<float>(dsize.width()));
  test_assert(fsize.height() == static_cast<float>(dsize.height()));
}

TEST_CASE(implicit_conversion_operator) {
  constexpr fsize2d fsize(1.1f, 2.2f);
  CONST_OR_CONSTEXPR dsize2d dsize = fsize;
  test_assert(dsize.width() == static_cast<double>(fsize.width()));
  test_assert(dsize.height() == static_cast<double>(fsize.height()));
}

TEST_CASE(width) {
  CONST_OR_CONSTEXPR fsize2d size(1.1f, 2.2f);
  CONST_OR_CONSTEXPR float width = size.width();
  test_assert(width == 1.1f);
}

TEST_CASE(set_width) {
  fsize2d size(1.1f, 2.2f);
  size.set_width(3.3f);
  test_assert(size.width() == 3.3f);
  test_assert(size.height() == 2.2f);
}

TEST_CASE(height) {
  CONST_OR_CONSTEXPR fsize2d size(1.1f, 2.2f);
  CONST_OR_CONSTEXPR float height = size.height();
  test_assert(height == 2.2f);
}

TEST_CASE(set_height) {
  fsize2d size(1.1f, 2.2f);
  size.set_height(3.3f);
  test_assert(size.width() == 1.1f);
  test_assert(size.height() == 3.3f);
}

TEST_CASE(equality_operator) {
  constexpr fsize2d s1(1.0f, 2.0f);
  constexpr isize2d s2(1, 2);
  constexpr isize2d s3(0, 2);
  constexpr isize2d s4(1, 0);
  CONST_OR_CONSTEXPR bool result1 = (s1 == s2);
  CONST_OR_CONSTEXPR bool result2 = (s1 == s3);
  CONST_OR_CONSTEXPR bool result3 = (s1 == s4);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
}

TEST_CASE(inequality_operator) {
  constexpr fsize2d s1(1.0f, 2.0f);
  constexpr isize2d s2(1, 2);
  constexpr isize2d s3(0, 2);
  constexpr isize2d s4(1, 0);
  CONST_OR_CONSTEXPR bool result1 = (s1 != s2);
  CONST_OR_CONSTEXPR bool result2 = (s1 != s3);
  CONST_OR_CONSTEXPR bool result3 = (s1 != s4);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
}

}
