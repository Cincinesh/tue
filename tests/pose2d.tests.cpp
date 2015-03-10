//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/pose2d.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace {
using namespace tue;

constexpr fvec2 fv21(1.1f, 1.2f);
constexpr fvec2 fv22(2.1f, 2.2f);
constexpr fvec2 fv23(3.1f, 3.2f);

constexpr float f1(4.1f);
constexpr float f2(5.1f);

TEST_CASE(default_constructor) {
  fpose2d pose;
  unused(pose);
}

TEST_CASE(component_constructor) {
  constexpr fpose2d pose(fv21, f1);
  test_assert(pose.translation() == fv21);
  test_assert(pose.rotation() == f1);
}

TEST_CASE(explicit_conversion_constructor) {
  constexpr dpose2d dpose(dvec2(1.1, 2.2), 3.3);
  CONST_OR_CONSTEXPR fpose2d fpose(dpose);
  test_assert(fpose.translation() == fvec2(dpose.translation()));
  test_assert(fpose.rotation() == static_cast<float>(dpose.rotation()));
}

TEST_CASE(implicit_conversion_operator) {
  constexpr fpose2d fpose(fvec2(1.1f, 2.2f), 3.3f);
  CONST_OR_CONSTEXPR dpose2d dpose = fpose;
  test_assert(dpose.translation() == dvec2(fpose.translation()));
  test_assert(dpose.rotation() == static_cast<double>(fpose.rotation()));
}

TEST_CASE(translation) {
  CONST_OR_CONSTEXPR fpose2d pose(fv21, f1);
  CONST_OR_CONSTEXPR fvec2 translation = pose.translation();
  test_assert(translation == fv21);
}

TEST_CASE(set_translation) {
  fpose2d pose(fv21, f1);
  pose.set_translation(fv22.x(), fv22.y());
  test_assert(pose.translation() == fv22);

  pose.set_translation(fv23);
  test_assert(pose.translation() == fv23);
}

TEST_CASE(rotation) {
  CONST_OR_CONSTEXPR fpose2d pose(fv21, f1);
  CONST_OR_CONSTEXPR float rotation = pose.rotation();
  test_assert(rotation == f1);
}

TEST_CASE(set_rotation) {
  fpose2d pose(fv21, f1);
  pose.set_rotation(f2);
  test_assert(pose.rotation() == f2);
}

TEST_CASE(equality_operator) {
  constexpr fpose2d p1(fvec2(1), 2);
  constexpr fpose2d p2(fvec2(1), 2);
  constexpr fpose2d p3(fvec2(0), 2);
  constexpr fpose2d p4(fvec2(1), 0);
  CONST_OR_CONSTEXPR bool result1 = (p1 == p2);
  CONST_OR_CONSTEXPR bool result2 = (p1 == p3);
  CONST_OR_CONSTEXPR bool result3 = (p1 == p4);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
}

TEST_CASE(inequality_operator) {
  constexpr fpose2d p1(fvec2(1), 2);
  constexpr fpose2d p2(fvec2(1), 2);
  constexpr fpose2d p3(fvec2(0), 2);
  constexpr fpose2d p4(fvec2(1), 0);
  CONST_OR_CONSTEXPR bool result1 = (p1 != p2);
  CONST_OR_CONSTEXPR bool result2 = (p1 != p3);
  CONST_OR_CONSTEXPR bool result3 = (p1 != p4);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
}

}
