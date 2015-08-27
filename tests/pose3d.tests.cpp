//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/pose3d.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>
#include <tue/quat.hpp>
#include <tue/vec.hpp>

namespace {
using namespace tue;

CONST_OR_CONSTEXPR fvec3 fv31(1.1f, 1.2f, 1.3f);
CONST_OR_CONSTEXPR fvec3 fv32(2.1f, 2.2f, 2.3f);
CONST_OR_CONSTEXPR fvec3 fv33(3.1f, 3.2f, 3.3f);

CONST_OR_CONSTEXPR fquat fq1(4.1f, 4.2f, 4.3f, 4.4f);
CONST_OR_CONSTEXPR fquat fq2(5.1f, 5.2f, 5.3f, 5.4f);

TEST_CASE(default_constructor) {
  fpose3d pose;
  unused(pose);
}

TEST_CASE(component_constructor) {
  CONST_OR_CONSTEXPR fpose3d pose = { fv31, fq1 };
  test_assert(pose.translation() == fv31);
  test_assert(pose.rotation() == fq1);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR dpose3d dpose(
      dvec3(1.1, 2.2, 3.3),
      dquat(4.4, 5.5, 6.6, 7.7));
  CONST_OR_CONSTEXPR fpose3d fpose(dpose);
  test_assert(fpose.translation() == fvec3(dpose.translation()));
  test_assert(fpose.rotation() == fquat(dpose.rotation()));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR fpose3d fpose(
      fvec3(1.1f, 2.2f, 3.3f),
      fquat(4.4f, 5.5f, 6.6f, 7.7f));
  CONST_OR_CONSTEXPR dpose3d dpose = fpose;
  test_assert(dpose.translation() == dvec3(fpose.translation()));
  test_assert(dpose.rotation() == dquat(fpose.rotation()));
}

TEST_CASE(identity) {
  CONST_OR_CONSTEXPR auto pose = fpose3d::identity();
  test_assert(pose.translation() == fvec3::zero());
  test_assert(pose.rotation() == fquat::identity());
}

TEST_CASE(translation) {
  CONST_OR_CONSTEXPR fpose3d pose(fv31, fq1);
  CONST_OR_CONSTEXPR fvec3 translation = pose.translation();
  test_assert(translation == fv31);
}

TEST_CASE(set_translation) {
  fpose3d pose(fv31, fq1);
  pose.set_translation(fv32.x(), fv32.y(), fv32.z());
  test_assert(pose.translation() == fv32);

  pose.set_translation(fv33);
  test_assert(pose.translation() == fv33);
}

TEST_CASE(rotation) {
  CONST_OR_CONSTEXPR fpose3d pose(fv31, fq1);
  CONST_OR_CONSTEXPR fquat rotation = pose.rotation();
  test_assert(rotation == fq1);
}

TEST_CASE(set_rotation) {
  fpose3d pose(fv31, fq1);
  pose.set_rotation(fq2);
  test_assert(pose.rotation() == fq2);
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fpose3d p1(fvec3(1), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p2(fvec3(1), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p3(fvec3(0), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p4(fvec3(1), fquat(0, 0, 0, 0));
  CONST_OR_CONSTEXPR bool result1 = (p1 == p2);
  CONST_OR_CONSTEXPR bool result2 = (p1 == p3);
  CONST_OR_CONSTEXPR bool result3 = (p1 == p4);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fpose3d p1(fvec3(1), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p2(fvec3(1), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p3(fvec3(0), fquat(2, 2, 2, 2));
  CONST_OR_CONSTEXPR fpose3d p4(fvec3(1), fquat(0, 0, 0, 0));
  CONST_OR_CONSTEXPR bool result1 = (p1 != p2);
  CONST_OR_CONSTEXPR bool result2 = (p1 != p3);
  CONST_OR_CONSTEXPR bool result3 = (p1 != p4);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
}

}
