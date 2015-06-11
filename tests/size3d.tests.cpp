//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/size3d.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>

namespace {
using namespace tue;

TEST_CASE(default_constructor) {
  fsize3d size;
  unused(size);
}

TEST_CASE(component_constructor) {
  CONST_OR_CONSTEXPR fsize3d size = { 1.1f, 2.2f, 3.3f };
  test_assert(size.width() == 1.1f);
  test_assert(size.height() == 2.2f);
  test_assert(size.depth() == 3.3f);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR dsize3d dsize(1.1, 2.2, 3.3);
  CONST_OR_CONSTEXPR fsize3d fsize(dsize);
  test_assert(fsize.width() == static_cast<float>(dsize.width()));
  test_assert(fsize.height() == static_cast<float>(dsize.height()));
  test_assert(fsize.depth() == static_cast<float>(dsize.depth()));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR fsize3d fsize(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR dsize3d dsize = fsize;
  test_assert(dsize.width() == static_cast<double>(fsize.width()));
  test_assert(dsize.height() == static_cast<double>(fsize.height()));
  test_assert(dsize.depth() == static_cast<double>(fsize.depth()));
}

TEST_CASE(zero) {
  CONST_OR_CONSTEXPR fsize3d size = fsize3d::zero();
  test_assert(size.width() == 0.0f);
  test_assert(size.height() == 0.0f);
  test_assert(size.depth() == 0.0f);
}

TEST_CASE(width) {
  CONST_OR_CONSTEXPR fsize3d size(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR float width = size.width();
  test_assert(width == 1.1f);
}

TEST_CASE(set_width) {
  fsize3d size(1.1f, 2.2f, 3.3f);
  size.set_width(4.4f);
  test_assert(size.width() == 4.4f);
  test_assert(size.height() == 2.2f);
  test_assert(size.depth() == 3.3f);
}

TEST_CASE(height) {
  CONST_OR_CONSTEXPR fsize3d size(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR float height = size.height();
  test_assert(height == 2.2f);
}

TEST_CASE(set_height) {
  fsize3d size(1.1f, 2.2f, 3.3f);
  size.set_height(4.4f);
  test_assert(size.width() == 1.1f);
  test_assert(size.height() == 4.4f);
  test_assert(size.depth() == 3.3f);
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fsize3d s1(1.0f, 2.0f, 3.0f);
  CONST_OR_CONSTEXPR isize3d s2(1, 2, 3);
  CONST_OR_CONSTEXPR isize3d s3(0, 2, 3);
  CONST_OR_CONSTEXPR isize3d s4(1, 0, 3);
  CONST_OR_CONSTEXPR isize3d s5(1, 2, 0);
  CONST_OR_CONSTEXPR bool result1 = (s1 == s2);
  CONST_OR_CONSTEXPR bool result2 = (s1 == s3);
  CONST_OR_CONSTEXPR bool result3 = (s1 == s4);
  CONST_OR_CONSTEXPR bool result4 = (s1 == s5);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
  test_assert(result4 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fsize3d s1(1.0f, 2.0f, 3.0f);
  CONST_OR_CONSTEXPR isize3d s2(1, 2, 3);
  CONST_OR_CONSTEXPR isize3d s3(0, 2, 3);
  CONST_OR_CONSTEXPR isize3d s4(1, 0, 3);
  CONST_OR_CONSTEXPR isize3d s5(1, 2, 0);
  CONST_OR_CONSTEXPR bool result1 = (s1 != s2);
  CONST_OR_CONSTEXPR bool result2 = (s1 != s3);
  CONST_OR_CONSTEXPR bool result3 = (s1 != s4);
  CONST_OR_CONSTEXPR bool result4 = (s1 != s5);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
  test_assert(result4 == true);
}

}
