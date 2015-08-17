//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/mat.hpp>
#include <mon/test_case.hpp>

#include <tue/math.hpp>
#include <tue/pose2d.hpp>
#include <tue/pose3d.hpp>
#include <tue/quat.hpp>
#include <tue/vec.hpp>

namespace {
using namespace tue;

TEST_CASE(translation_mat_2d) {
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::translation_mat(1.1f, 2.2f);
  test_assert(m1[0] == fvec4(1.0f, 0.0f, 0.0f, 1.1f));
  test_assert(m1[1] == fvec4(0.0f, 1.0f, 0.0f, 2.2f));
  test_assert(m1[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
  test_assert(m1[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::translation_mat(fvec2(1.1f, 2.2f));
  test_assert(m2 == m1);

  CONST_OR_CONSTEXPR fmat2x3 m3 =
      math::translation_mat<float, 2, 3>(1.1f, 2.2f);
  test_assert(m3[0] == fvec3(1.0f, 0.0f, 1.1f));
  test_assert(m3[1] == fvec3(0.0f, 1.0f, 2.2f));

  CONST_OR_CONSTEXPR fmat2x3 m4 =
      math::translation_mat<float, 2, 3>(fvec2(1.1f, 2.2f));
  test_assert(m4 == m3);
}

TEST_CASE(translation_mat_3d) {
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::translation_mat(1.1f, 2.2f, 3.3f);
  test_assert(m1[0] == fvec4(1.0f, 0.0f, 0.0f, 1.1f));
  test_assert(m1[1] == fvec4(0.0f, 1.0f, 0.0f, 2.2f));
  test_assert(m1[2] == fvec4(0.0f, 0.0f, 1.0f, 3.3f));
  test_assert(m1[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::translation_mat(fvec3(1.1f, 2.2f, 3.3f));
  test_assert(m2 == m1);

  CONST_OR_CONSTEXPR fmat3x4 m3 =
      math::translation_mat<float, 3, 4>(1.1f, 2.2f, 3.3f);
  test_assert(m3 == fmat3x4(m1));

  CONST_OR_CONSTEXPR fmat3x4 m4 =
      math::translation_mat<float, 3, 4>(fvec3(1.1f, 2.2f, 3.3f));
  test_assert(m4 == m3);
}

TEST_CASE(rotation_mat_2d) {
  const fmat4x4 m1 = math::rotation_mat(1.23f);
  test_assert(m1[0] == fvec4(math::cos(1.23f), -math::sin(1.23f), 0.0f, 0.0f));
  test_assert(m1[1] == fvec4(math::sin(1.23f),  math::cos(1.23f), 0.0f, 0.0f));
  test_assert(m1[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
  test_assert(m1[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

  const fmat2x2 m2 = math::rotation_mat<float, 2, 2>(1.23f);
  test_assert(m2 == fmat2x2(m1));
}

TEST_CASE(rotation_mat_from_axis_angle) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const float w = 4.4f;
  const float s = math::sin(w);
  const float c = math::cos(w);
  const fmat4x4 m1 = math::rotation_mat(x, y, z, w);
  test_assert(m1[0][0] == x*x*(1-c) + c);
  test_assert(m1[0][1] == y*x*(1-c) - z*s);
  test_assert(m1[0][2] == x*z*(1-c) + y*s);
  test_assert(m1[0][3] == 0.0f);
  test_assert(m1[1][0] == x*y*(1-c) + z*s);
  test_assert(m1[1][1] == y*y*(1-c) + c);
  test_assert(m1[1][2] == y*z*(1-c) - x*s);
  test_assert(m1[1][3] == 0.0f);
  test_assert(m1[2][0] == x*z*(1-c) - y*s);
  test_assert(m1[2][1] == y*z*(1-c) + x*s);
  test_assert(m1[2][2] == z*z*(1-c) + c);
  test_assert(m1[2][3] == 0.0f);
  test_assert(m1[3][0] == 0.0f);
  test_assert(m1[3][1] == 0.0f);
  test_assert(m1[3][2] == 0.0f);
  test_assert(m1[3][3] == 1.0f);

  const fmat4x4 m2 = math::rotation_mat(fvec3(x, y, z), w);
  test_assert(m2 == m1);

  const fmat4x4 m3 = math::rotation_mat(fvec4(x, y, z, w));
  test_assert(m3 == m1);

  const fmat3x3 m4 = math::rotation_mat<float, 3, 3>(x, y, z, w);
  test_assert(m4 == fmat3x3(m1));

  const fmat3x3 m5 = math::rotation_mat<float, 3, 3>(fvec3(x, y, z), w);
  test_assert(m5 == m4);

  const fmat3x3 m6 = math::rotation_mat<float, 3, 3>(fvec4(x, y, z, w));
  test_assert(m6 == m4);
}

TEST_CASE(rotation_mat_from_rotation_vec) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const fmat4x4 m1 = math::rotation_mat(x, y, z);
  test_assert(m1 == math::rotation_mat(math::axis_angle(x, y, z)));

  const fmat4x4 m2 = math::rotation_mat(fvec3(x, y, z));
  test_assert(m2 == m1);

  const fmat3x3 m3 = math::rotation_mat<float, 3, 3>(x, y, z);
  test_assert(m3 == fmat3x3(m1));

  const fmat3x3 m4 = math::rotation_mat<float, 3, 3>(fvec3(x, y, z));
  test_assert(m4 == m3);
}

TEST_CASE(rotation_mat_from_quat) {
  constexpr float x = 1.1f;
  constexpr float y = 2.2f;
  constexpr float z = 3.3f;
  constexpr float w = 4.4f;
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::rotation_mat(fquat(x, y, z, w));
  test_assert(m1[0][0] == 1 - 2*y*y -2*z*z);
  test_assert(m1[0][1] == 2*x*y - 2*z*w);
  test_assert(m1[0][2] == 2*x*z + 2*y*w);
  test_assert(m1[0][3] == 0.0f);
  test_assert(m1[1][0] == 2*x*y + 2*z*w);
  test_assert(m1[1][1] == 1 - 2*x*x - 2*z*z);
  test_assert(m1[1][2] == 2*y*z - 2*x*w);
  test_assert(m1[1][3] == 0.0f);
  test_assert(m1[2][0] == 2*x*z - 2*y*w);
  test_assert(m1[2][1] == 2*y*z + 2*x*w);
  test_assert(m1[2][2] == 1 - 2*x*x - 2*y*y);
  test_assert(m1[2][3] == 0.0f);
  test_assert(m1[3][0] == 0.0f);
  test_assert(m1[3][1] == 0.0f);
  test_assert(m1[3][2] == 0.0f);
  test_assert(m1[3][3] == 1.0f);

  CONST_OR_CONSTEXPR fmat3x3 m2 =
      math::rotation_mat<float, 3, 3>(fquat(x, y, z, w));
  test_assert(m2 == fmat3x3(m1));
}

TEST_CASE(scale_mat_2d) {
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::scale_mat(1.1f, 2.2f);
  test_assert(m1[0] == fvec4(1.1f, 0.0f, 0.0f, 0.0f));
  test_assert(m1[1] == fvec4(0.0f, 2.2f, 0.0f, 0.0f));
  test_assert(m1[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
  test_assert(m1[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::scale_mat(fvec2(1.1f, 2.2f));
  test_assert(m2 == m1);

  CONST_OR_CONSTEXPR fmat2x2 m3 =
      math::scale_mat<float, 2, 2>(1.1f, 2.2f);
  test_assert(m3 == fmat2x2(m1));

  CONST_OR_CONSTEXPR fmat2x2 m4 =
      math::scale_mat<float, 2, 2>(fvec2(1.1f, 2.2f));
  test_assert(m4 == m3);
}

TEST_CASE(scale_mat_3d) {
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::scale_mat(1.1f, 2.2f, 3.3f);
  test_assert(m1[0] == fvec4(1.1f, 0.0f, 0.0f, 0.0f));
  test_assert(m1[1] == fvec4(0.0f, 2.2f, 0.0f, 0.0f));
  test_assert(m1[2] == fvec4(0.0f, 0.0f, 3.3f, 0.0f));
  test_assert(m1[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::scale_mat(fvec3(1.1f, 2.2f, 3.3f));
  test_assert(m2 == m1);

  CONST_OR_CONSTEXPR fmat3x3 m3 =
      math::scale_mat<float, 3, 3>(1.1f, 2.2f, 3.3f);
  test_assert(m3 == fmat3x3(m1));

  CONST_OR_CONSTEXPR fmat3x3 m4 =
      math::scale_mat<float, 3, 3>(fvec3(1.1f, 2.2f, 3.3f));
  test_assert(m4 == m3);
}

TEST_CASE(pose_mat_2d) {
  const fvec2 translation(1.1f, 2.2f);
  const float rotation = 3.3f;
  const fmat4x4 m1 =
      math::pose_mat(translation, rotation);
  test_assert(m1
      == math::rotation_mat(rotation)
          * math::translation_mat(translation));

  const fmat4x4 m2 =
      math::pose_mat(fpose2d(translation, rotation));
  test_assert(m2 == m1);

  const fmat2x3 m3 =
      math::pose_mat<float, 2, 3>(fpose2d(translation, rotation));
  test_assert(m3
      == (math::rotation_mat<float, 3, 3>(rotation)
          * math::translation_mat<float, 2, 3>(translation)));

  const fmat2x3 m4 =
      math::pose_mat<float, 2, 3>(fpose2d(translation, rotation));
  test_assert(m4 == m3);
}

TEST_CASE(pose_mat_3d) {
  CONST_OR_CONSTEXPR fvec3 translation(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fquat rotation(4.4f, 5.5f, 6.6f, 7.7f);
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::pose_mat(translation, rotation);
  test_assert(m1
      == math::rotation_mat(rotation)
          * math::translation_mat(translation));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::pose_mat(fpose3d(translation, rotation));
  test_assert(m2 == m1);

  CONST_OR_CONSTEXPR fmat3x4 m3 =
      math::pose_mat<float, 3, 4>(translation, rotation);
  test_assert(m3 == fmat3x4(m1));

  CONST_OR_CONSTEXPR fmat3x4 m4 =
      math::pose_mat<float, 3, 4>(fpose3d(translation, rotation));
  test_assert(m4 == m3);
}

TEST_CASE(view_mat_2d) {
  const fvec2 translation(1.1f, 2.2f);
  const float rotation = 3.3f;
  const fmat4x4 m1 =
      math::view_mat(translation, rotation);
  test_assert(m1
      == math::translation_mat(-translation)
          * math::rotation_mat(-rotation));

  const fmat4x4 m2 =
      math::view_mat(fpose2d(translation, rotation));
  test_assert(m2 == m1);
  
  const fmat2x3 m3 =
      math::view_mat<float, 2, 3>(translation, rotation);
  test_assert(m3
      == (math::translation_mat<float, 2, 3>(-translation)
          * math::rotation_mat<float, 2, 2>(-rotation)));

  const fmat2x3 m4 =
      math::view_mat<float, 2, 3>(fpose2d(translation, rotation));
  test_assert(m4 == m3);
}

TEST_CASE(view_mat_3d) {
  CONST_OR_CONSTEXPR fvec3 translation(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fquat rotation(4.4f, 5.5f, 6.6f, 7.7f);
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::view_mat(translation, rotation);
  test_assert(m1
      == math::translation_mat(-translation)
          * math::rotation_mat(math::conjugate(rotation)));

  CONST_OR_CONSTEXPR fmat4x4 m2 =
      math::view_mat(fpose3d(translation, rotation));
  test_assert(m2 == m1);
  
  CONST_OR_CONSTEXPR fmat3x4 m3 =
      math::view_mat<float, 3, 4>(translation, rotation);
  test_assert(m3 == fmat3x4(m1));

  CONST_OR_CONSTEXPR fmat3x4 m4 =
      math::view_mat<float, 3, 4>(fpose3d(translation, rotation));
  test_assert(m4 == m3);
}

TEST_CASE(perspective_mat) {
  const float fovy = 1.1f;
  const float aspect = 2.2f;
  const float near = 3.3f;
  const float far = 4.4f;
  const float f = math::cos(fovy/2) / math::sin(fovy/2);
  const fmat4x4 m1 =
      math::perspective_mat(fovy, aspect, near, far);
  test_assert(m1[0][0] == f / aspect);
  test_assert(m1[0][1] == 0.0f);
  test_assert(m1[0][2] == 0.0f);
  test_assert(m1[0][3] == 0.0f);
  test_assert(m1[1][0] == 0.0f);
  test_assert(m1[1][1] == f);
  test_assert(m1[1][2] == 0.0f);
  test_assert(m1[1][3] == 0.0f);
  test_assert(m1[2][0] == 0.0f);
  test_assert(m1[2][1] == 0.0f);
  test_assert(m1[2][2] == (near+far) / (near-far));
  test_assert(m1[2][3] == (2*near*far) / (near-far));
  test_assert(m1[3][0] == 0.0f);
  test_assert(m1[3][1] == 0.0f);
  test_assert(m1[3][2] == -1.0f);
  test_assert(m1[3][3] == 0.0f);
  
  const fmat4x4 m2 =
      math::perspective_mat<float, 4, 4>(fovy, aspect, near, far);
  test_assert(m2 == m1);
}

TEST_CASE(ortho_mat) {
  constexpr float width = 1.1f;
  constexpr float height = 2.2f;
  constexpr float near = 3.3f;
  constexpr float far = 4.4f;
  CONST_OR_CONSTEXPR fmat4x4 m1 =
      math::ortho_mat(width, height, near, far);
  test_assert(m1[0][0] == 2 / width);
  test_assert(m1[0][1] == 0.0f);
  test_assert(m1[0][2] == 0.0f);
  test_assert(m1[0][3] == 0.0f);
  test_assert(m1[1][0] == 0.0f);
  test_assert(m1[1][1] == 2 / height);
  test_assert(m1[1][2] == 0.0f);
  test_assert(m1[1][3] == 0.0f);
  test_assert(m1[2][0] == 0.0f);
  test_assert(m1[2][1] == 0.0f);
  test_assert(m1[2][2] == 2 / (far - near));
  test_assert(m1[2][3] == (far + near) / (far - near));
  test_assert(m1[3][0] == 0.0f);
  test_assert(m1[3][1] == 0.0f);
  test_assert(m1[3][2] == 0.0f);
  test_assert(m1[3][3] == 1.0f);
  
  CONST_OR_CONSTEXPR fmat3x4 m2 =
      math::ortho_mat<float, 3, 4>(width, height, near, far);
  test_assert(m2 == fmat3x4(m1));
}

}
