//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/vec.hpp>
#include <mon/test_case.hpp>

#include <tue/mat.hpp>
#include <tue/math.hpp>
#include <tue/unused.hpp>

namespace {
using namespace tue;

constexpr auto f1 = 1.1f;
constexpr auto f2 = 2.2f;

constexpr auto d2 = 2.2;

constexpr auto i1 = 111;

constexpr auto u2 = 2u;

CONST_OR_CONSTEXPR fvec4 fv41(1.1f, 1.2f, 1.3f, 1.4f);
CONST_OR_CONSTEXPR fvec4 fv42(2.2f, -2.4f, 2.6f, -2.8f);

CONST_OR_CONSTEXPR dvec4 dv41(1.1, 1.2, 1.3, 1.4);
CONST_OR_CONSTEXPR dvec4 dv42(2.2, 2.4, 2.6, 2.8);

CONST_OR_CONSTEXPR ivec4 iv41(111, 222, 333, 444);
CONST_OR_CONSTEXPR ivec4 iv42(2, -4, 6, -8);

CONST_OR_CONSTEXPR uvec4 uv42(2u, 4u, 6u, 8u);

CONST_OR_CONSTEXPR mat4x4<unsigned int> um442{
  {  2u,  4u,  6u,  8u },
  { 10u, 12u, 14u, 16u },
  { 18u, 20u, 22u, 24u },
  { 26u, 28u, 30u, 32u },
};

TEST_CASE(default_constructor) {
  fvec4 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  CONST_OR_CONSTEXPR fvec4 v(1.1f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.1f);
  test_assert(v[2] == 1.1f);
  test_assert(v[3] == 1.1f);
}

TEST_CASE(scalar_component_constructor) {
  CONST_OR_CONSTEXPR fvec4 v = { 1.1f, 2.2f, 3.3f, 4.4f };
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
  test_assert(v[3] == 4.4f);
}

TEST_CASE(vec2_component_constructor) {
  CONST_OR_CONSTEXPR fvec4 v = { { 1.1f, 2.2f }, 3.3f, 4.4f };
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
  test_assert(v[3] == 4.4f);
}

TEST_CASE(vec3_component_constructor) {
  CONST_OR_CONSTEXPR fvec4 v = { { 1.1f, 2.2f, 3.3f }, 4.4f };
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
  test_assert(v[3] == 4.4f);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR fvec4 v(dv41);
  test_assert(v[0] == static_cast<float>(dv41[0]));
  test_assert(v[1] == static_cast<float>(dv41[1]));
  test_assert(v[2] == static_cast<float>(dv41[2]));
  test_assert(v[3] == static_cast<float>(dv41[3]));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR dvec4 v = fv41;
  test_assert(v[0] == static_cast<double>(fv41[0]));
  test_assert(v[1] == static_cast<double>(fv41[1]));
  test_assert(v[2] == static_cast<double>(fv41[2]));
  test_assert(v[3] == static_cast<double>(fv41[3]));
}

TEST_CASE(zero) {
  CONST_OR_CONSTEXPR auto v = fvec4::zero();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
  test_assert(v[2] == 0);
  test_assert(v[3] == 0);
}

TEST_CASE(x_axis) {
  CONST_OR_CONSTEXPR auto v = fvec4::x_axis();
  test_assert(v[0] == 1);
  test_assert(v[1] == 0);
  test_assert(v[2] == 0);
  test_assert(v[3] == 0);
}

TEST_CASE(y_axis) {
  CONST_OR_CONSTEXPR auto v = fvec4::y_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 1);
  test_assert(v[2] == 0);
  test_assert(v[3] == 0);
}

TEST_CASE(z_axis) {
  CONST_OR_CONSTEXPR auto v = fvec4::z_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
  test_assert(v[2] == 1);
  test_assert(v[3] == 0);
}

TEST_CASE(w_axis) {
  CONST_OR_CONSTEXPR auto v = fvec4::w_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
  test_assert(v[2] == 0);
  test_assert(v[3] == 1);
}

TEST_CASE(x) {
  CONST_OR_CONSTEXPR float x = fv41.x();
  test_assert(x == fv41[0]);
}

TEST_CASE(set_x) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_x(2.1f);
  test_assert(v[0] == 2.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(y) {
  CONST_OR_CONSTEXPR float y = fv41.y();
  test_assert(y == fv41[1]);
}

TEST_CASE(set_y) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_y(2.2f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(z) {
  CONST_OR_CONSTEXPR float z = fv41.z();
  test_assert(z == fv41[2]);
}

TEST_CASE(set_z) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_z(2.3f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 2.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(w) {
  CONST_OR_CONSTEXPR float w = fv41.w();
  test_assert(w == fv41[3]);
}

TEST_CASE(set_w) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_w(2.4f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 2.4f);
}

TEST_CASE(r) {
  CONST_OR_CONSTEXPR float r = fv41.r();
  test_assert(r == fv41[0]);
}

TEST_CASE(set_r) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_r(2.1f);
  test_assert(v[0] == 2.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(g) {
  CONST_OR_CONSTEXPR float g = fv41.g();
  test_assert(g == fv41[1]);
}

TEST_CASE(set_g) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_g(2.2f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(b) {
  CONST_OR_CONSTEXPR float b = fv41.b();
  test_assert(b == fv41[2]);
}

TEST_CASE(set_b) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_b(2.3f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 2.3f);
  test_assert(v[3] == 1.4f);
}

TEST_CASE(a) {
  CONST_OR_CONSTEXPR float a = fv41.a();
  test_assert(a == fv41[3]);
}

TEST_CASE(set_a) {
  fvec4 v(1.1f, 1.2f, 1.3f, 1.4f);
  v.set_a(2.4f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
  test_assert(v[3] == 2.4f);
}

TEST_CASE(xy) {
  CONST_OR_CONSTEXPR fvec2 xy = fv41.xy();
  test_assert(xy == fvec2(fv41));
}

TEST_CASE(set_xy) {
  fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
  v1.set_xy(2.1f, 2.2f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 1.3f);
  test_assert(v1[3] == 1.4f);

  fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
  v2.set_xy(fvec2(2.1f, 2.2f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 1.3f);
  test_assert(v2[3] == 1.4f);
}

TEST_CASE(rg) {
  CONST_OR_CONSTEXPR fvec2 rg = fv41.rg();
  test_assert(rg == fvec2(fv41));
}

TEST_CASE(set_rg) {
  fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
  v1.set_rg(2.1f, 2.2f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 1.3f);
  test_assert(v1[3] == 1.4f);

  fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
  v2.set_rg(fvec2(2.1f, 2.2f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 1.3f);
  test_assert(v2[3] == 1.4f);
}

TEST_CASE(xyz) {
  CONST_OR_CONSTEXPR fvec3 xyz = fv41.xyz();
  test_assert(xyz == fvec3(fv41));
}

TEST_CASE(set_xyz) {
  fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
  v1.set_xyz(2.1f, 2.2f, 2.3f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 2.3f);
  test_assert(v1[3] == 1.4f);

  fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
  v2.set_xyz(fvec3(2.1f, 2.2f, 2.3f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 2.3f);
  test_assert(v2[3] == 1.4f);
}

TEST_CASE(rgb) {
  CONST_OR_CONSTEXPR fvec3 rgb = fv41.rgb();
  test_assert(rgb == fvec3(fv41));
}

TEST_CASE(set_rgb) {
  fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
  v1.set_rgb(2.1f, 2.2f, 2.3f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 2.3f);
  test_assert(v1[3] == 1.4f);

  fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
  v2.set_rgb(fvec3(2.1f, 2.2f, 2.3f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 2.3f);
  test_assert(v2[3] == 1.4f);
}

TEST_CASE(data) {
  fvec4 v = fv41;
  float* data = v.data();
  test_assert(static_cast<void*>(data) == static_cast<void*>(&v));

  const fvec4& cv = v;
  const float* cdata = cv.data();
  test_assert(cdata == data);
}

TEST_CASE(subscript_operator) {
  CONST_OR_CONSTEXPR fvec4 cev(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR float cev0 = cev[0];
  CONST_OR_CONSTEXPR float cev1 = cev[1];
  CONST_OR_CONSTEXPR float cev2 = cev[2];
  CONST_OR_CONSTEXPR float cev3 = cev[3];
  test_assert(cev0 == 1.1f);
  test_assert(cev1 == 2.2f);
  test_assert(cev2 == 3.3f);
  test_assert(cev3 == 4.4f);

  fvec4 v = cev;
  float& v0 = v[0];
  float& v1 = v[1];
  float& v2 = v[2];
  float& v3 = v[3];
  test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
  test_assert(&v1 == &v0 + 1);
  test_assert(&v2 == &v0 + 2);
  test_assert(&v3 == &v0 + 3);

  const fvec4& cv = v;
  const float& cv0 = cv[0];
  const float& cv1 = cv[1];
  const float& cv2 = cv[2];
  const float& cv3 = cv[3];
  test_assert(&cv0 == &v0);
  test_assert(&cv1 == &v1);
  test_assert(&cv2 == &v2);
  test_assert(&cv3 == &v3);
}

TEST_CASE(pre_increment_operator) {
  fvec4 v = fv41;
  test_assert(&(++v) == &v);
  test_assert(v == fv41 + 1);
}

TEST_CASE(pre_decrement_operator) {
  fvec4 v = fv41;
  test_assert(&(--v) == &v);
  test_assert(v == fv41 - 1);
}

TEST_CASE(post_increment_operator) {
  fvec4 v = fv41;
  test_assert(v++ == fv41);
  test_assert(v == fv41 + 1);
}

TEST_CASE(post_decrement_operator) {
  fvec4 v = fv41;
  test_assert(v-- == fv41);
  test_assert(v == fv41 - 1);
}

TEST_CASE(addition_assignment_operator) {
  fvec4 v1 = fv41;
  test_assert(&(v1 += u2) == &v1);
  test_assert(v1 == fv41 + u2);

  fvec4 v2 = fv41;
  test_assert(&(v2 += uv42) == &v2);
  test_assert(v2 == fv41 + uv42);
}

TEST_CASE(subtraction_assignment_operator) {
  fvec4 v1 = fv41;
  test_assert(&(v1 -= u2) == &v1);
  test_assert(v1 == fv41 - u2);

  fvec4 v2 = fv41;
  test_assert(&(v2 -= uv42) == &v2);
  test_assert(v2 == fv41 - uv42);
}

TEST_CASE(multiplication_assignment_operator) {
  fvec4 v1 = fv41;
  test_assert(&(v1 *= u2) == &v1);
  test_assert(v1 == fv41 * u2);

  fvec4 v2 = fv41;
  test_assert(&(v2 *= uv42) == &v2);
  test_assert(v2 == fv41 * uv42);

  fvec4 v3 = fv41;
  test_assert(&(v3 *= um442) == &v3);
  test_assert(v3 == fv41 * um442);
}

TEST_CASE(division_assignment_operator) {
  fvec4 v1 = fv41;
  test_assert(&(v1 /= u2) == &v1);
  test_assert(v1 == fv41 / u2);

  fvec4 v2 = fv41;
  test_assert(&(v2 /= uv42) == &v2);
  test_assert(v2 == fv41 / uv42);
}

TEST_CASE(modulo_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 %= u2) == &v1);
  test_assert(v1 == ivec4(iv41 % u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 %= uv42) == &v2);
  test_assert(v2 == ivec4(iv41 % uv42));
}

TEST_CASE(bitwise_and_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 &= u2) == &v1);
  test_assert(v1 == ivec4(iv41 & u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 &= uv42) == &v2);
  test_assert(v2 == ivec4(iv41 & uv42));
}

TEST_CASE(bitwise_or_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 |= u2) == &v1);
  test_assert(v1 == ivec4(iv41 | u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 |= uv42) == &v2);
  test_assert(v2 == ivec4(iv41 | uv42));
}

TEST_CASE(bitwise_xor_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 ^= u2) == &v1);
  test_assert(v1 == ivec4(iv41 ^ u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 ^= uv42) == &v2);
  test_assert(v2 == ivec4(iv41 ^ uv42));
}

TEST_CASE(bitwise_shift_left_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 <<= u2) == &v1);
  test_assert(v1 == (iv41 << u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 <<= uv42) == &v2);
  test_assert(v2 == (iv41 << uv42));
}

TEST_CASE(bitwise_shift_right_assignment_operator) {
  ivec4 v1 = iv41;
  test_assert(&(v1 >>= u2) == &v1);
  test_assert(v1 == (iv41 >> u2));

  ivec4 v2 = iv41;
  test_assert(&(v2 >>= uv42) == &v2);
  test_assert(v2 == (iv41 >> uv42));
}

TEST_CASE(unary_plus_operator) {
  CONST_OR_CONSTEXPR auto v = +fv41;
  test_assert(v[0] == +fv41[0]);
  test_assert(v[1] == +fv41[1]);
  test_assert(v[2] == +fv41[2]);
  test_assert(v[3] == +fv41[3]);
}

TEST_CASE(unary_minus_operator) {
  CONST_OR_CONSTEXPR auto v = -fv41;
  test_assert(v[0] == -fv41[0]);
  test_assert(v[1] == -fv41[1]);
  test_assert(v[2] == -fv41[2]);
  test_assert(v[3] == -fv41[3]);
}

TEST_CASE(bitwise_not_operator) {
  CONST_OR_CONSTEXPR auto v = ~iv41;
  test_assert(v[0] == ~iv41[0]);
  test_assert(v[1] == ~iv41[1]);
  test_assert(v[2] == ~iv41[2]);
  test_assert(v[3] == ~iv41[3]);
}

TEST_CASE(addition_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 + dv42;
  test_assert(v1[0] == f1 + dv42[0]);
  test_assert(v1[1] == f1 + dv42[1]);
  test_assert(v1[2] == f1 + dv42[2]);
  test_assert(v1[3] == f1 + dv42[3]);

  CONST_OR_CONSTEXPR auto v2 = fv41 + d2;
  test_assert(v2[0] == fv41[0] + d2);
  test_assert(v2[1] == fv41[1] + d2);
  test_assert(v2[2] == fv41[2] + d2);
  test_assert(v2[3] == fv41[3] + d2);

  CONST_OR_CONSTEXPR auto v3 = fv41 + dv42;
  test_assert(v3[0] == fv41[0] + dv42[0]);
  test_assert(v3[1] == fv41[1] + dv42[1]);
  test_assert(v3[2] == fv41[2] + dv42[2]);
  test_assert(v3[3] == fv41[3] + dv42[3]);
}

TEST_CASE(subtraction_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 - dv42;
  test_assert(v1[0] == f1 - dv42[0]);
  test_assert(v1[1] == f1 - dv42[1]);
  test_assert(v1[2] == f1 - dv42[2]);
  test_assert(v1[3] == f1 - dv42[3]);

  CONST_OR_CONSTEXPR auto v2 = fv41 - d2;
  test_assert(v2[0] == fv41[0] - d2);
  test_assert(v2[1] == fv41[1] - d2);
  test_assert(v2[2] == fv41[2] - d2);
  test_assert(v2[3] == fv41[3] - d2);

  CONST_OR_CONSTEXPR auto v3 = fv41 - dv42;
  test_assert(v3[0] == fv41[0] - dv42[0]);
  test_assert(v3[1] == fv41[1] - dv42[1]);
  test_assert(v3[2] == fv41[2] - dv42[2]);
  test_assert(v3[3] == fv41[3] - dv42[3]);
}

TEST_CASE(multiplication_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 * dv42;
  test_assert(v1[0] == f1 * dv42[0]);
  test_assert(v1[1] == f1 * dv42[1]);
  test_assert(v1[2] == f1 * dv42[2]);
  test_assert(v1[3] == f1 * dv42[3]);

  CONST_OR_CONSTEXPR auto v2 = fv41 * d2;
  test_assert(v2[0] == fv41[0] * d2);
  test_assert(v2[1] == fv41[1] * d2);
  test_assert(v2[2] == fv41[2] * d2);
  test_assert(v2[3] == fv41[3] * d2);

  CONST_OR_CONSTEXPR auto v3 = fv41 * dv42;
  test_assert(v3[0] == fv41[0] * dv42[0]);
  test_assert(v3[1] == fv41[1] * dv42[1]);
  test_assert(v3[2] == fv41[2] * dv42[2]);
  test_assert(v3[3] == fv41[3] * dv42[3]);
}

TEST_CASE(division_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 / dv42;
  test_assert(v1[0] == f1 / dv42[0]);
  test_assert(v1[1] == f1 / dv42[1]);
  test_assert(v1[2] == f1 / dv42[2]);
  test_assert(v1[3] == f1 / dv42[3]);

  CONST_OR_CONSTEXPR auto v2 = fv41 / d2;
  test_assert(v2[0] == fv41[0] / d2);
  test_assert(v2[1] == fv41[1] / d2);
  test_assert(v2[2] == fv41[2] / d2);
  test_assert(v2[3] == fv41[3] / d2);

  CONST_OR_CONSTEXPR auto v3 = fv41 / dv42;
  test_assert(v3[0] == fv41[0] / dv42[0]);
  test_assert(v3[1] == fv41[1] / dv42[1]);
  test_assert(v3[2] == fv41[2] / dv42[2]);
  test_assert(v3[3] == fv41[3] / dv42[3]);
}

TEST_CASE(modulo_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 % uv42;
  test_assert(v1[0] == i1 % uv42[0]);
  test_assert(v1[1] == i1 % uv42[1]);
  test_assert(v1[2] == i1 % uv42[2]);
  test_assert(v1[3] == i1 % uv42[3]);

  CONST_OR_CONSTEXPR auto v2 = iv41 % u2;
  test_assert(v2[0] == iv41[0] % u2);
  test_assert(v2[1] == iv41[1] % u2);
  test_assert(v2[2] == iv41[2] % u2);
  test_assert(v2[3] == iv41[3] % u2);

  CONST_OR_CONSTEXPR auto v3 = iv41 % uv42;
  test_assert(v3[0] == iv41[0] % uv42[0]);
  test_assert(v3[1] == iv41[1] % uv42[1]);
  test_assert(v3[2] == iv41[2] % uv42[2]);
  test_assert(v3[3] == iv41[3] % uv42[3]);
}

TEST_CASE(bitwise_and_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 & uv42;
  test_assert(v1[0] == (i1 & uv42[0]));
  test_assert(v1[1] == (i1 & uv42[1]));
  test_assert(v1[2] == (i1 & uv42[2]));
  test_assert(v1[3] == (i1 & uv42[3]));

  CONST_OR_CONSTEXPR auto v2 = iv41 & u2;
  test_assert(v2[0] == (iv41[0] & u2));
  test_assert(v2[1] == (iv41[1] & u2));
  test_assert(v2[2] == (iv41[2] & u2));
  test_assert(v2[3] == (iv41[3] & u2));

  CONST_OR_CONSTEXPR auto v3 = iv41 & uv42;
  test_assert(v3[0] == (iv41[0] & uv42[0]));
  test_assert(v3[1] == (iv41[1] & uv42[1]));
  test_assert(v3[2] == (iv41[2] & uv42[2]));
  test_assert(v3[3] == (iv41[3] & uv42[3]));
}

TEST_CASE(bitwise_or_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 | uv42;
  test_assert(v1[0] == (i1 | uv42[0]));
  test_assert(v1[1] == (i1 | uv42[1]));
  test_assert(v1[2] == (i1 | uv42[2]));
  test_assert(v1[3] == (i1 | uv42[3]));

  CONST_OR_CONSTEXPR auto v2 = iv41 | u2;
  test_assert(v2[0] == (iv41[0] | u2));
  test_assert(v2[1] == (iv41[1] | u2));
  test_assert(v2[2] == (iv41[2] | u2));
  test_assert(v2[3] == (iv41[3] | u2));

  CONST_OR_CONSTEXPR auto v3 = iv41 | uv42;
  test_assert(v3[0] == (iv41[0] | uv42[0]));
  test_assert(v3[1] == (iv41[1] | uv42[1]));
  test_assert(v3[2] == (iv41[2] | uv42[2]));
  test_assert(v3[3] == (iv41[3] | uv42[3]));
}

TEST_CASE(bitwise_xor_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 ^ uv42;
  test_assert(v1[0] == (i1 ^ uv42[0]));
  test_assert(v1[1] == (i1 ^ uv42[1]));
  test_assert(v1[2] == (i1 ^ uv42[2]));
  test_assert(v1[3] == (i1 ^ uv42[3]));

  CONST_OR_CONSTEXPR auto v2 = iv41 ^ u2;
  test_assert(v2[0] == (iv41[0] ^ u2));
  test_assert(v2[1] == (iv41[1] ^ u2));
  test_assert(v2[2] == (iv41[2] ^ u2));
  test_assert(v2[3] == (iv41[3] ^ u2));

  CONST_OR_CONSTEXPR auto v3 = iv41 ^ uv42;
  test_assert(v3[0] == (iv41[0] ^ uv42[0]));
  test_assert(v3[1] == (iv41[1] ^ uv42[1]));
  test_assert(v3[2] == (iv41[2] ^ uv42[2]));
  test_assert(v3[3] == (iv41[3] ^ uv42[3]));
}

TEST_CASE(bitwise_shift_left_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 << uv42;
  test_assert(v1[0] == (i1 << uv42[0]));
  test_assert(v1[1] == (i1 << uv42[1]));
  test_assert(v1[2] == (i1 << uv42[2]));
  test_assert(v1[3] == (i1 << uv42[3]));

  CONST_OR_CONSTEXPR auto v2 = iv41 << u2;
  test_assert(v2[0] == (iv41[0] << u2));
  test_assert(v2[1] == (iv41[1] << u2));
  test_assert(v2[2] == (iv41[2] << u2));
  test_assert(v2[3] == (iv41[3] << u2));

  CONST_OR_CONSTEXPR auto v3 = iv41 << uv42;
  test_assert(v3[0] == (iv41[0] << uv42[0]));
  test_assert(v3[1] == (iv41[1] << uv42[1]));
  test_assert(v3[2] == (iv41[2] << uv42[2]));
  test_assert(v3[3] == (iv41[3] << uv42[3]));
}

TEST_CASE(bitwise_shift_right_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 >> uv42;
  test_assert(v1[0] == (i1 >> uv42[0]));
  test_assert(v1[1] == (i1 >> uv42[1]));
  test_assert(v1[2] == (i1 >> uv42[2]));
  test_assert(v1[3] == (i1 >> uv42[3]));

  CONST_OR_CONSTEXPR auto v2 = iv41 >> u2;
  test_assert(v2[0] == (iv41[0] >> u2));
  test_assert(v2[1] == (iv41[1] >> u2));
  test_assert(v2[2] == (iv41[2] >> u2));
  test_assert(v2[3] == (iv41[3] >> u2));

  CONST_OR_CONSTEXPR auto v3 = iv41 >> uv42;
  test_assert(v3[0] == (iv41[0] >> uv42[0]));
  test_assert(v3[1] == (iv41[1] >> uv42[1]));
  test_assert(v3[2] == (iv41[2] >> uv42[2]));
  test_assert(v3[3] == (iv41[3] >> uv42[3]));
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fvec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
  CONST_OR_CONSTEXPR ivec4 v2(1, 2, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v3(0, 2, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v4(1, 0, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v5(1, 2, 0, 4);
  CONST_OR_CONSTEXPR ivec4 v6(1, 2, 3, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
  CONST_OR_CONSTEXPR bool result4 = (v1 == v5);
  CONST_OR_CONSTEXPR bool result5 = (v1 == v6);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
  test_assert(result4 == false);
  test_assert(result5 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fvec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
  CONST_OR_CONSTEXPR ivec4 v2(1, 2, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v3(0, 2, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v4(1, 0, 3, 4);
  CONST_OR_CONSTEXPR ivec4 v5(1, 2, 0, 4);
  CONST_OR_CONSTEXPR ivec4 v6(1, 2, 3, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
  CONST_OR_CONSTEXPR bool result4 = (v1 != v5);
  CONST_OR_CONSTEXPR bool result5 = (v1 != v6);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
  test_assert(result4 == true);
  test_assert(result5 == true);
}

TEST_CASE(sin) {
  const auto fsin = math::sin(fv41);
  test_assert(fsin[0] == math::sin(fv41[0]));
  test_assert(fsin[1] == math::sin(fv41[1]));
  test_assert(fsin[2] == math::sin(fv41[2]));
  test_assert(fsin[3] == math::sin(fv41[3]));

  const auto isin = math::sin(iv41);
  test_assert(isin[0] == math::sin(iv41[0]));
  test_assert(isin[1] == math::sin(iv41[1]));
  test_assert(isin[2] == math::sin(iv41[2]));
  test_assert(isin[3] == math::sin(iv41[3]));
}

TEST_CASE(cos) {
  const auto fcos = math::cos(fv41);
  test_assert(fcos[0] == math::cos(fv41[0]));
  test_assert(fcos[1] == math::cos(fv41[1]));
  test_assert(fcos[2] == math::cos(fv41[2]));
  test_assert(fcos[3] == math::cos(fv41[3]));

  const auto icos = math::cos(iv41);
  test_assert(icos[0] == math::cos(iv41[0]));
  test_assert(icos[1] == math::cos(iv41[1]));
  test_assert(icos[2] == math::cos(iv41[2]));
  test_assert(icos[3] == math::cos(iv41[3]));
}

TEST_CASE(sincos) {
  fvec4 fsin, fcos;
  math::sincos(fv41, fsin, fcos);
  test_assert(fsin == math::sin(fv41));
  test_assert(fcos == math::cos(fv41));

  dvec4 isin, icos;
  math::sincos(iv41, isin, icos);
  test_assert(isin == math::sin(iv41));
  test_assert(icos == math::cos(iv41));
}

TEST_CASE(exp) {
  const auto fexp = math::exp(fv41);
  test_assert(fexp[0] == math::exp(fv41[0]));
  test_assert(fexp[1] == math::exp(fv41[1]));
  test_assert(fexp[2] == math::exp(fv41[2]));
  test_assert(fexp[3] == math::exp(fv41[3]));

  const auto iexp = math::exp(iv41);
  test_assert(iexp[0] == math::exp(iv41[0]));
  test_assert(iexp[1] == math::exp(iv41[1]));
  test_assert(iexp[2] == math::exp(iv41[2]));
  test_assert(iexp[3] == math::exp(iv41[3]));
}

TEST_CASE(log) {
  const auto flog = math::log(fv41);
  test_assert(flog[0] == math::log(fv41[0]));
  test_assert(flog[1] == math::log(fv41[1]));
  test_assert(flog[2] == math::log(fv41[2]));
  test_assert(flog[3] == math::log(fv41[3]));

  const auto ilog = math::log(iv41);
  test_assert(ilog[0] == math::log(iv41[0]));
  test_assert(ilog[1] == math::log(iv41[1]));
  test_assert(ilog[2] == math::log(iv41[2]));
  test_assert(ilog[3] == math::log(iv41[3]));
}

TEST_CASE(pow) {
  const auto fpow1 = math::pow(fv41, f2);
  test_assert(fpow1[0] == math::pow(fv41[0], f2));
  test_assert(fpow1[1] == math::pow(fv41[1], f2));
  test_assert(fpow1[2] == math::pow(fv41[2], f2));
  test_assert(fpow1[3] == math::pow(fv41[3], f2));

  const auto ipow1 = math::pow(iv41, f2);
  test_assert(ipow1[0] == math::pow(iv41[0], f2));
  test_assert(ipow1[1] == math::pow(iv41[1], f2));
  test_assert(ipow1[2] == math::pow(iv41[2], f2));
  test_assert(ipow1[3] == math::pow(iv41[3], f2));

  const auto fpow2 = math::pow(fv41, fv42);
  test_assert(fpow2[0] == math::pow(fv41[0], fv42[0]));
  test_assert(fpow2[1] == math::pow(fv41[1], fv42[1]));
  test_assert(fpow2[2] == math::pow(fv41[2], fv42[2]));
  test_assert(fpow2[3] == math::pow(fv41[3], fv42[3]));

  const auto ipow2 = math::pow(iv41, fv42);
  test_assert(ipow2[0] == math::pow(iv41[0], fv42[0]));
  test_assert(ipow2[1] == math::pow(iv41[1], fv42[1]));
  test_assert(ipow2[2] == math::pow(iv41[2], fv42[2]));
  test_assert(ipow2[3] == math::pow(iv41[3], fv42[3]));
}

TEST_CASE(recip) {
  const auto frecip = math::recip(fv41);
  test_assert(frecip[0] == math::recip(fv41[0]));
  test_assert(frecip[1] == math::recip(fv41[1]));
  test_assert(frecip[2] == math::recip(fv41[2]));
  test_assert(frecip[3] == math::recip(fv41[3]));

  const auto irecip = math::recip(iv41);
  test_assert(irecip[0] == math::recip(iv41[0]));
  test_assert(irecip[1] == math::recip(iv41[1]));
  test_assert(irecip[2] == math::recip(iv41[2]));
  test_assert(irecip[3] == math::recip(iv41[3]));
}

TEST_CASE(sqrt) {
  const auto fsqrt = math::sqrt(fv41);
  test_assert(fsqrt[0] == math::sqrt(fv41[0]));
  test_assert(fsqrt[1] == math::sqrt(fv41[1]));
  test_assert(fsqrt[2] == math::sqrt(fv41[2]));
  test_assert(fsqrt[3] == math::sqrt(fv41[3]));

  const auto isqrt = math::sqrt(iv41);
  test_assert(isqrt[0] == math::sqrt(iv41[0]));
  test_assert(isqrt[1] == math::sqrt(iv41[1]));
  test_assert(isqrt[2] == math::sqrt(iv41[2]));
  test_assert(isqrt[3] == math::sqrt(iv41[3]));
}

TEST_CASE(rsqrt) {
  const auto frsqrt = math::rsqrt(fv41);
  test_assert(frsqrt[0] == math::rsqrt(fv41[0]));
  test_assert(frsqrt[1] == math::rsqrt(fv41[1]));
  test_assert(frsqrt[2] == math::rsqrt(fv41[2]));
  test_assert(frsqrt[3] == math::rsqrt(fv41[3]));

  const auto irsqrt = math::rsqrt(iv41);
  test_assert(irsqrt[0] == math::rsqrt(iv41[0]));
  test_assert(irsqrt[1] == math::rsqrt(iv41[1]));
  test_assert(irsqrt[2] == math::rsqrt(iv41[2]));
  test_assert(irsqrt[3] == math::rsqrt(iv41[3]));
}

TEST_CASE(min) {
  const auto fmin = math::min(fv41, fv42);
  test_assert(fmin[0] == math::min(fv41[0], fv42[0]));
  test_assert(fmin[1] == math::min(fv41[1], fv42[1]));
  test_assert(fmin[2] == math::min(fv41[2], fv42[2]));
  test_assert(fmin[3] == math::min(fv41[3], fv42[3]));

  const auto imin = math::min(iv41, iv42);
  test_assert(imin[0] == math::min(iv41[0], iv42[0]));
  test_assert(imin[1] == math::min(iv41[1], iv42[1]));
  test_assert(imin[2] == math::min(iv41[2], iv42[2]));
  test_assert(imin[3] == math::min(iv41[3], iv42[3]));
}

TEST_CASE(max) {
  const auto fmax = math::max(fv41, fv42);
  test_assert(fmax[0] == math::max(fv41[0], fv42[0]));
  test_assert(fmax[1] == math::max(fv41[1], fv42[1]));
  test_assert(fmax[2] == math::max(fv41[2], fv42[2]));
  test_assert(fmax[3] == math::max(fv41[3], fv42[3]));

  const auto imax = math::max(iv41, iv42);
  test_assert(imax[0] == math::max(iv41[0], iv42[0]));
  test_assert(imax[1] == math::max(iv41[1], iv42[1]));
  test_assert(imax[2] == math::max(iv41[2], iv42[2]));
  test_assert(imax[3] == math::max(iv41[3], iv42[3]));
}

TEST_CASE(abs) {
  const auto fabs = math::abs(fv42);
  test_assert(fabs[0] == math::abs(fv42[0]));
  test_assert(fabs[1] == math::abs(fv42[1]));
  test_assert(fabs[2] == math::abs(fv42[2]));
  test_assert(fabs[3] == math::abs(fv42[3]));

  const auto iabs = math::abs(iv42);
  test_assert(iabs[0] == math::abs(iv42[0]));
  test_assert(iabs[1] == math::abs(iv42[1]));
  test_assert(iabs[2] == math::abs(iv42[2]));
  test_assert(iabs[3] == math::abs(iv42[3]));

  const auto uabs = math::abs(uv42);
  test_assert(uabs[0] == math::abs(uv42[0]));
  test_assert(uabs[1] == math::abs(uv42[1]));
  test_assert(uabs[2] == math::abs(uv42[2]));
  test_assert(uabs[3] == math::abs(uv42[3]));
}

TEST_CASE(dot) {
  CONST_OR_CONSTEXPR auto fdot = math::dot(fv41, dv42);
  test_assert(fdot
      == fv41[0] * dv42[0]
      + fv41[1] * dv42[1]
      + fv41[2] * dv42[2]
      + fv41[3] * dv42[3]);

  CONST_OR_CONSTEXPR auto idot = math::dot(iv41, uv42);
  test_assert(idot
      == iv41[0] * uv42[0]
      + iv41[1] * uv42[1]
      + iv41[2] * uv42[2]
      + iv41[3] * uv42[3]);
}

TEST_CASE(length2) {
  test_assert(math::length2(fv41)
      == math::length2(fv41[0])
      + math::length2(fv41[1])
      + math::length2(fv41[2])
      + math::length2(fv41[3]));

  test_assert(math::length2(iv41) == math::length2(dvec4(iv41)));
}

TEST_CASE(length) {
  test_assert(math::length(fv41) == math::sqrt(math::length2(fv41)));
  test_assert(math::length(iv41) == math::length(dvec4(iv41)));
}

TEST_CASE(normalize) {
  test_assert(math::normalize(fv41) == fv41 / math::length(fv41));
  test_assert(math::normalize(iv41) == math::normalize(dvec4(iv41)));
}

TEST_CASE(comp_mult) {
  CONST_OR_CONSTEXPR auto v = math::comp_mult(fv41, dv42);
  test_assert(v == fv41 * dv42);
}

TEST_CASE(transpose) {
  CONST_OR_CONSTEXPR auto v = math::transpose(fv41);
  test_assert(v == fv41);
}

TEST_CASE(select) {
  CONST_OR_CONSTEXPR fvec4 v1 =
      math::select(bvec4(true, false, true, false), fv41);
  CONST_OR_CONSTEXPR fvec4 v2 =
      math::select(bvec4(false, true, false, true), fv41);
  test_assert(v1 == fvec4(fv41[0], 0.0f, fv41[2], 0.0f));
  test_assert(v2 == fvec4(0.0f, fv41[1], 0.0f, fv41[3]));

  CONST_OR_CONSTEXPR fvec4 v3 =
      math::select(bvec4(true, false, true, false), fv41, fv42);
  CONST_OR_CONSTEXPR fvec4 v4 =
      math::select(bvec4(false, true, false, true), fv41, fv42);
  test_assert(v3 == fvec4(fv41[0], fv42[1], fv41[2], fv42[3]));
  test_assert(v4 == fvec4(fv42[0], fv41[1], fv42[2], fv41[3]));
}

TEST_CASE(less) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::less(v1, v2);
  test_assert(b == bvec4(false, false, true, true));
}

TEST_CASE(less_equal) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::less_equal(v1, v2);
  test_assert(b == bvec4(false, true, true, true));
}

TEST_CASE(greater) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::greater(v1, v2);
  test_assert(b == bvec4(true, false, false, false));
}

TEST_CASE(greater_equal) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::greater_equal(v1, v2);
  test_assert(b == bvec4(true, true, false, false));
}

TEST_CASE(equal) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::equal(v1, v2);
  test_assert(b == bvec4(false, true, false, false));
}

TEST_CASE(not_equal) {
  CONST_OR_CONSTEXPR fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec4 v2(0.0f, 2.2f, 3.4f, 5.6f);
  CONST_OR_CONSTEXPR bvec4 b = math::not_equal(v1, v2);
  test_assert(b == bvec4(true, false, true, true));
}

TEST_CASE(axis_angle) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const fvec3 rv(x, y, z);
  const fvec4 aa1 = math::axis_angle(rv);
  test_assert(aa1.xyz() == math::normalize(rv));
  test_assert(aa1.w() == math::length(rv));

  const fvec4 aa2 = math::axis_angle(x, y, z);
  test_assert(aa2 == aa1);

  const fvec4 aa3 = math::axis_angle(fvec3(0.0f));
  test_assert(aa3 == fvec4(0.0f, 0.0f, 1.0f, 0.0f));

  const fvec4 aa4 = math::axis_angle(0.0f, 0.0f, 0.0f);
  test_assert(aa4 == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
}

}
