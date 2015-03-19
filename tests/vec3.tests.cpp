//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/vec.hpp>
#include <mon/test_case.hpp>

#include <tue/mat.hpp>
#include <tue/math.hpp>
#include <tue/quat.hpp>
#include <tue/unused.hpp>

namespace {
using namespace tue;

constexpr auto f1 = 1.1f;
constexpr auto f2 = 2.2f;

constexpr auto d2 = 2.2;

constexpr auto i1 = 111;

constexpr auto u2 = 2u;

CONST_OR_CONSTEXPR fvec3 fv31(1.1f, 1.2f, 1.3f);
CONST_OR_CONSTEXPR fvec3 fv32(2.2f, 2.4f, 2.6f);

CONST_OR_CONSTEXPR dvec3 dv31(1.1, 1.2, 1.3);
CONST_OR_CONSTEXPR dvec3 dv32(2.2, 2.4, 2.6);

CONST_OR_CONSTEXPR ivec3 iv31(111, 222, 333);
CONST_OR_CONSTEXPR ivec3 iv32(2, 4, 6);

CONST_OR_CONSTEXPR uvec3 uv32(2u, 4u, 6u);

CONST_OR_CONSTEXPR fquat fq1(1.1f, 1.2f, 1.3f, 1.4f);

CONST_OR_CONSTEXPR mat3x3<unsigned int> um332{
  {  2u,  4u,  6u },
  {  8u, 10u, 12u },
  { 14u, 16u, 18u },
};

TEST_CASE(default_constructor) {
  fvec3 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  CONST_OR_CONSTEXPR fvec3 v(1.1f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.1f);
  test_assert(v[2] == 1.1f);
}

TEST_CASE(scalar_component_constructor) {
  CONST_OR_CONSTEXPR fvec3 v = { 1.1f, 2.2f, 3.3f };
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
}

TEST_CASE(vec2_component_constructor) {
  CONST_OR_CONSTEXPR fvec3 v(fvec2(1.1f, 2.2f), 3.3f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
}

TEST_CASE(truncate_vec4_constructor) {
  CONST_OR_CONSTEXPR fvec3 v(fvec4(1.1f, 2.2f, 3.3f, 4.4f));
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 3.3f);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR fvec3 v(dv31);
  test_assert(v[0] == static_cast<float>(dv31[0]));
  test_assert(v[1] == static_cast<float>(dv31[1]));
  test_assert(v[2] == static_cast<float>(dv31[2]));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR dvec3 v = fv31;
  test_assert(v[0] == static_cast<double>(fv31[0]));
  test_assert(v[1] == static_cast<double>(fv31[1]));
  test_assert(v[2] == static_cast<double>(fv31[2]));
}

TEST_CASE(zero) {
  CONST_OR_CONSTEXPR auto v = fvec3::zero();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
  test_assert(v[2] == 0);
}

TEST_CASE(x_axis) {
  CONST_OR_CONSTEXPR auto v = fvec3::x_axis();
  test_assert(v[0] == 1);
  test_assert(v[1] == 0);
  test_assert(v[2] == 0);
}

TEST_CASE(y_axis) {
  CONST_OR_CONSTEXPR auto v = fvec3::y_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 1);
  test_assert(v[2] == 0);
}

TEST_CASE(z_axis) {
  CONST_OR_CONSTEXPR auto v = fvec3::z_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
  test_assert(v[2] == 1);
}

TEST_CASE(x) {
  CONST_OR_CONSTEXPR float x = fv31.x();
  test_assert(x == fv31[0]);
}

TEST_CASE(set_x) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_x(2.1f);
  test_assert(v[0] == 2.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
}

TEST_CASE(y) {
  CONST_OR_CONSTEXPR float y = fv31.y();
  test_assert(y == fv31[1]);
}

TEST_CASE(set_y) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_y(2.2f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 1.3f);
}

TEST_CASE(z) {
  CONST_OR_CONSTEXPR float z = fv31.z();
  test_assert(z == fv31[2]);
}

TEST_CASE(set_z) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_z(2.3f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 2.3f);
}

TEST_CASE(r) {
  CONST_OR_CONSTEXPR float r = fv31.r();
  test_assert(r == fv31[0]);
}

TEST_CASE(set_r) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_r(2.1f);
  test_assert(v[0] == 2.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 1.3f);
}

TEST_CASE(g) {
  CONST_OR_CONSTEXPR float g = fv31.g();
  test_assert(g == fv31[1]);
}

TEST_CASE(set_g) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_g(2.2f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
  test_assert(v[2] == 1.3f);
}

TEST_CASE(b) {
  CONST_OR_CONSTEXPR float b = fv31.b();
  test_assert(b == fv31[2]);
}

TEST_CASE(set_b) {
  fvec3 v(1.1f, 1.2f, 1.3f);
  v.set_b(2.3f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.2f);
  test_assert(v[2] == 2.3f);
}

TEST_CASE(xy) {
  CONST_OR_CONSTEXPR fvec2 xy = fv31.xy();
  test_assert(xy == fvec2(fv31));
}

TEST_CASE(set_xy) {
  fvec3 v1(1.1f, 1.2f, 1.3f);
  v1.set_xy(2.1f, 2.2f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 1.3f);

  fvec3 v2(1.1f, 1.2f, 1.3f);
  v2.set_xy(fvec2(2.1f, 2.2f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 1.3f);
}

TEST_CASE(rg) {
  CONST_OR_CONSTEXPR fvec2 rg = fv31.rg();
  test_assert(rg == fvec2(fv31));
}

TEST_CASE(set_rg) {
  fvec3 v1(1.1f, 1.2f, 1.3f);
  v1.set_rg(2.1f, 2.2f);
  test_assert(v1[0] == 2.1f);
  test_assert(v1[1] == 2.2f);
  test_assert(v1[2] == 1.3f);

  fvec3 v2(1.1f, 1.2f, 1.3f);
  v2.set_rg(fvec2(2.1f, 2.2f));
  test_assert(v2[0] == 2.1f);
  test_assert(v2[1] == 2.2f);
  test_assert(v2[2] == 1.3f);
}

TEST_CASE(data) {
  fvec3 v = fv31;
  float* data = v.data();
  test_assert(static_cast<void*>(data) == static_cast<void*>(&v));

  const fvec3& cv = v;
  const float* cdata = cv.data();
  test_assert(cdata == data);
}

TEST_CASE(subscript_operator) {
  CONST_OR_CONSTEXPR fvec3 cev(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR float cev0 = cev[0];
  CONST_OR_CONSTEXPR float cev1 = cev[1];
  CONST_OR_CONSTEXPR float cev2 = cev[2];
  test_assert(cev0 == 1.1f);
  test_assert(cev1 == 2.2f);
  test_assert(cev2 == 3.3f);

  fvec3 v = cev;
  float& v0 = v[0];
  float& v1 = v[1];
  float& v2 = v[2];
  test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
  test_assert(&v1 == &v0 + 1);
  test_assert(&v2 == &v0 + 2);

  const fvec3& cv = v;
  const float& cv0 = cv[0];
  const float& cv1 = cv[1];
  const float& cv2 = cv[2];
  test_assert(&cv0 == &v0);
  test_assert(&cv1 == &v1);
  test_assert(&cv2 == &v2);
}

TEST_CASE(pre_increment_operator) {
  fvec3 v = fv31;
  test_assert(&(++v) == &v);
  test_assert(v == fv31 + 1);
}

TEST_CASE(pre_decrement_operator) {
  fvec3 v = fv31;
  test_assert(&(--v) == &v);
  test_assert(v == fv31 - 1);
}

TEST_CASE(post_increment_operator) {
  fvec3 v = fv31;
  test_assert(v++ == fv31);
  test_assert(v == fv31 + 1);
}

TEST_CASE(post_decrement_operator) {
  fvec3 v = fv31;
  test_assert(v-- == fv31);
  test_assert(v == fv31 - 1);
}

TEST_CASE(addition_assignment_operator) {
  fvec3 v1 = fv31;
  test_assert(&(v1 += u2) == &v1);
  test_assert(v1 == fv31 + u2);

  fvec3 v2 = fv31;
  test_assert(&(v2 += uv32) == &v2);
  test_assert(v2 == fv31 + uv32);
}

TEST_CASE(subtraction_assignment_operator) {
  fvec3 v1 = fv31;
  test_assert(&(v1 -= u2) == &v1);
  test_assert(v1 == fv31 - u2);

  fvec3 v2 = fv31;
  test_assert(&(v2 -= uv32) == &v2);
  test_assert(v2 == fv31 - uv32);
}

TEST_CASE(multiplication_assignment_operator) {
  fvec3 v1 = fv31;
  test_assert(&(v1 *= u2) == &v1);
  test_assert(v1 == fv31 * u2);

  fvec3 v2 = fv31;
  test_assert(&(v2 *= uv32) == &v2);
  test_assert(v2 == fv31 * uv32);

  dvec3 v3 = dv32;
  test_assert(&(v3 *= fq1) == &v3);
  test_assert(v3 == dv32 * fq1);

  fvec3 v4 = fv31;
  test_assert(&(v4 *= um332) == &v4);
  test_assert(v4 == fv31 * um332);
}

TEST_CASE(division_assignment_operator) {
  fvec3 v1 = fv31;
  test_assert(&(v1 /= u2) == &v1);
  test_assert(v1 == fv31 / u2);

  fvec3 v2 = fv31;
  test_assert(&(v2 /= uv32) == &v2);
  test_assert(v2 == fv31 / uv32);
}

TEST_CASE(modulo_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 %= u2) == &v1);
  test_assert(v1 == ivec3(iv31 % u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 %= uv32) == &v2);
  test_assert(v2 == ivec3(iv31 % uv32));
}

TEST_CASE(bitwise_and_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 &= u2) == &v1);
  test_assert(v1 == ivec3(iv31 & u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 &= uv32) == &v2);
  test_assert(v2 == ivec3(iv31 & uv32));
}

TEST_CASE(bitwise_or_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 |= u2) == &v1);
  test_assert(v1 == ivec3(iv31 | u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 |= uv32) == &v2);
  test_assert(v2 == ivec3(iv31 | uv32));
}

TEST_CASE(bitwise_xor_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 ^= u2) == &v1);
  test_assert(v1 == ivec3(iv31 ^ u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 ^= uv32) == &v2);
  test_assert(v2 == ivec3(iv31 ^ uv32));
}

TEST_CASE(bitwise_shift_left_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 <<= u2) == &v1);
  test_assert(v1 == (iv31 << u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 <<= uv32) == &v2);
  test_assert(v2 == (iv31 << uv32));
}

TEST_CASE(bitwise_shift_right_assignment_operator) {
  ivec3 v1 = iv31;
  test_assert(&(v1 >>= u2) == &v1);
  test_assert(v1 == (iv31 >> u2));

  ivec3 v2 = iv31;
  test_assert(&(v2 >>= uv32) == &v2);
  test_assert(v2 == (iv31 >> uv32));
}

TEST_CASE(unary_plus_operator) {
  CONST_OR_CONSTEXPR auto v = +fv31;
  test_assert(v[0] == +fv31[0]);
  test_assert(v[1] == +fv31[1]);
  test_assert(v[2] == +fv31[2]);
}

TEST_CASE(unary_minus_operator) {
  CONST_OR_CONSTEXPR auto v = -fv31;
  test_assert(v[0] == -fv31[0]);
  test_assert(v[1] == -fv31[1]);
  test_assert(v[2] == -fv31[2]);
}

TEST_CASE(bitwise_not_operator) {
  CONST_OR_CONSTEXPR auto v = ~iv31;
  test_assert(v[0] == ~iv31[0]);
  test_assert(v[1] == ~iv31[1]);
  test_assert(v[2] == ~iv31[2]);
}

TEST_CASE(addition_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 + dv32;
  test_assert(v1[0] == f1 + dv32[0]);
  test_assert(v1[1] == f1 + dv32[1]);
  test_assert(v1[2] == f1 + dv32[2]);

  CONST_OR_CONSTEXPR auto v2 = fv31 + d2;
  test_assert(v2[0] == fv31[0] + d2);
  test_assert(v2[1] == fv31[1] + d2);
  test_assert(v2[2] == fv31[2] + d2);

  CONST_OR_CONSTEXPR auto v3 = fv31 + dv32;
  test_assert(v3[0] == fv31[0] + dv32[0]);
  test_assert(v3[1] == fv31[1] + dv32[1]);
  test_assert(v3[2] == fv31[2] + dv32[2]);
}

TEST_CASE(subtraction_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 - dv32;
  test_assert(v1[0] == f1 - dv32[0]);
  test_assert(v1[1] == f1 - dv32[1]);
  test_assert(v1[2] == f1 - dv32[2]);

  CONST_OR_CONSTEXPR auto v2 = fv31 - d2;
  test_assert(v2[0] == fv31[0] - d2);
  test_assert(v2[1] == fv31[1] - d2);
  test_assert(v2[2] == fv31[2] - d2);

  CONST_OR_CONSTEXPR auto v3 = fv31 - dv32;
  test_assert(v3[0] == fv31[0] - dv32[0]);
  test_assert(v3[1] == fv31[1] - dv32[1]);
  test_assert(v3[2] == fv31[2] - dv32[2]);
}

TEST_CASE(multiplication_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 * dv32;
  test_assert(v1[0] == f1 * dv32[0]);
  test_assert(v1[1] == f1 * dv32[1]);
  test_assert(v1[2] == f1 * dv32[2]);

  CONST_OR_CONSTEXPR auto v2 = fv31 * d2;
  test_assert(v2[0] == fv31[0] * d2);
  test_assert(v2[1] == fv31[1] * d2);
  test_assert(v2[2] == fv31[2] * d2);

  CONST_OR_CONSTEXPR auto v3 = fv31 * dv32;
  test_assert(v3[0] == fv31[0] * dv32[0]);
  test_assert(v3[1] == fv31[1] * dv32[1]);
  test_assert(v3[2] == fv31[2] * dv32[2]);
}

TEST_CASE(division_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 / dv32;
  test_assert(v1[0] == f1 / dv32[0]);
  test_assert(v1[1] == f1 / dv32[1]);
  test_assert(v1[2] == f1 / dv32[2]);

  CONST_OR_CONSTEXPR auto v2 = fv31 / d2;
  test_assert(v2[0] == fv31[0] / d2);
  test_assert(v2[1] == fv31[1] / d2);
  test_assert(v2[2] == fv31[2] / d2);

  CONST_OR_CONSTEXPR auto v3 = fv31 / dv32;
  test_assert(v3[0] == fv31[0] / dv32[0]);
  test_assert(v3[1] == fv31[1] / dv32[1]);
  test_assert(v3[2] == fv31[2] / dv32[2]);
}

TEST_CASE(modulo_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 % uv32;
  test_assert(v1[0] == i1 % uv32[0]);
  test_assert(v1[1] == i1 % uv32[1]);
  test_assert(v1[2] == i1 % uv32[2]);

  CONST_OR_CONSTEXPR auto v2 = iv31 % u2;
  test_assert(v2[0] == iv31[0] % u2);
  test_assert(v2[1] == iv31[1] % u2);
  test_assert(v2[2] == iv31[2] % u2);

  CONST_OR_CONSTEXPR auto v3 = iv31 % uv32;
  test_assert(v3[0] == iv31[0] % uv32[0]);
  test_assert(v3[1] == iv31[1] % uv32[1]);
  test_assert(v3[2] == iv31[2] % uv32[2]);
}

TEST_CASE(bitwise_and_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 & uv32;
  test_assert(v1[0] == (i1 & uv32[0]));
  test_assert(v1[1] == (i1 & uv32[1]));
  test_assert(v1[2] == (i1 & uv32[2]));

  CONST_OR_CONSTEXPR auto v2 = iv31 & u2;
  test_assert(v2[0] == (iv31[0] & u2));
  test_assert(v2[1] == (iv31[1] & u2));
  test_assert(v2[2] == (iv31[2] & u2));

  CONST_OR_CONSTEXPR auto v3 = iv31 & uv32;
  test_assert(v3[0] == (iv31[0] & uv32[0]));
  test_assert(v3[1] == (iv31[1] & uv32[1]));
  test_assert(v3[2] == (iv31[2] & uv32[2]));
}

TEST_CASE(bitwise_or_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 | uv32;
  test_assert(v1[0] == (i1 | uv32[0]));
  test_assert(v1[1] == (i1 | uv32[1]));
  test_assert(v1[2] == (i1 | uv32[2]));

  CONST_OR_CONSTEXPR auto v2 = iv31 | u2;
  test_assert(v2[0] == (iv31[0] | u2));
  test_assert(v2[1] == (iv31[1] | u2));
  test_assert(v2[2] == (iv31[2] | u2));

  CONST_OR_CONSTEXPR auto v3 = iv31 | uv32;
  test_assert(v3[0] == (iv31[0] | uv32[0]));
  test_assert(v3[1] == (iv31[1] | uv32[1]));
  test_assert(v3[2] == (iv31[2] | uv32[2]));
}

TEST_CASE(bitwise_xor_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 ^ uv32;
  test_assert(v1[0] == (i1 ^ uv32[0]));
  test_assert(v1[1] == (i1 ^ uv32[1]));
  test_assert(v1[2] == (i1 ^ uv32[2]));

  CONST_OR_CONSTEXPR auto v2 = iv31 ^ u2;
  test_assert(v2[0] == (iv31[0] ^ u2));
  test_assert(v2[1] == (iv31[1] ^ u2));
  test_assert(v2[2] == (iv31[2] ^ u2));

  CONST_OR_CONSTEXPR auto v3 = iv31 ^ uv32;
  test_assert(v3[0] == (iv31[0] ^ uv32[0]));
  test_assert(v3[1] == (iv31[1] ^ uv32[1]));
  test_assert(v3[2] == (iv31[2] ^ uv32[2]));
}

TEST_CASE(bitwise_shift_left_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 << uv32;
  test_assert(v1[0] == (i1 << uv32[0]));
  test_assert(v1[1] == (i1 << uv32[1]));
  test_assert(v1[2] == (i1 << uv32[2]));

  CONST_OR_CONSTEXPR auto v2 = iv31 << u2;
  test_assert(v2[0] == (iv31[0] << u2));
  test_assert(v2[1] == (iv31[1] << u2));
  test_assert(v2[2] == (iv31[2] << u2));

  CONST_OR_CONSTEXPR auto v3 = iv31 << uv32;
  test_assert(v3[0] == (iv31[0] << uv32[0]));
  test_assert(v3[1] == (iv31[1] << uv32[1]));
  test_assert(v3[2] == (iv31[2] << uv32[2]));
}

TEST_CASE(bitwise_shift_right_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 >> uv32;
  test_assert(v1[0] == (i1 >> uv32[0]));
  test_assert(v1[1] == (i1 >> uv32[1]));
  test_assert(v1[2] == (i1 >> uv32[2]));

  CONST_OR_CONSTEXPR auto v2 = iv31 >> u2;
  test_assert(v2[0] == (iv31[0] >> u2));
  test_assert(v2[1] == (iv31[1] >> u2));
  test_assert(v2[2] == (iv31[2] >> u2));

  CONST_OR_CONSTEXPR auto v3 = iv31 >> uv32;
  test_assert(v3[0] == (iv31[0] >> uv32[0]));
  test_assert(v3[1] == (iv31[1] >> uv32[1]));
  test_assert(v3[2] == (iv31[2] >> uv32[2]));
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fvec3 v1(1.0f, 2.0f, 3.0f);
  CONST_OR_CONSTEXPR ivec3 v2(1, 2, 3);
  CONST_OR_CONSTEXPR ivec3 v3(0, 2, 3);
  CONST_OR_CONSTEXPR ivec3 v4(1, 0, 3);
  CONST_OR_CONSTEXPR ivec3 v5(1, 2, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
  CONST_OR_CONSTEXPR bool result4 = (v1 == v5);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
  test_assert(result4 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fvec3 v1(1.0f, 2.0f, 3.0f);
  CONST_OR_CONSTEXPR ivec3 v2(1, 2, 3);
  CONST_OR_CONSTEXPR ivec3 v3(0, 2, 3);
  CONST_OR_CONSTEXPR ivec3 v4(1, 0, 3);
  CONST_OR_CONSTEXPR ivec3 v5(1, 2, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
  CONST_OR_CONSTEXPR bool result4 = (v1 != v5);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
  test_assert(result4 == true);
}

TEST_CASE(sin) {
  const auto fsin = math::sin(fv31);
  test_assert(fsin[0] == math::sin(fv31[0]));
  test_assert(fsin[1] == math::sin(fv31[1]));
  test_assert(fsin[2] == math::sin(fv31[2]));

  const auto isin = math::sin(iv31);
  test_assert(isin[0] == math::sin(iv31[0]));
  test_assert(isin[1] == math::sin(iv31[1]));
  test_assert(isin[2] == math::sin(iv31[2]));
}

TEST_CASE(cos) {
  const auto fcos = math::cos(fv31);
  test_assert(fcos[0] == math::cos(fv31[0]));
  test_assert(fcos[1] == math::cos(fv31[1]));
  test_assert(fcos[2] == math::cos(fv31[2]));

  const auto icos = math::cos(iv31);
  test_assert(icos[0] == math::cos(iv31[0]));
  test_assert(icos[1] == math::cos(iv31[1]));
  test_assert(icos[2] == math::cos(iv31[2]));
}

TEST_CASE(sincos) {
  fvec3 fsin, fcos;
  math::sincos(fv31, fsin, fcos);
  test_assert(fsin == math::sin(fv31));
  test_assert(fcos == math::cos(fv31));

  dvec3 isin, icos;
  math::sincos(iv31, isin, icos);
  test_assert(isin == math::sin(iv31));
  test_assert(icos == math::cos(iv31));
}

TEST_CASE(exp) {
  const auto fexp = math::exp(fv31);
  test_assert(fexp[0] == math::exp(fv31[0]));
  test_assert(fexp[1] == math::exp(fv31[1]));
  test_assert(fexp[2] == math::exp(fv31[2]));

  const auto iexp = math::exp(iv31);
  test_assert(iexp[0] == math::exp(iv31[0]));
  test_assert(iexp[1] == math::exp(iv31[1]));
  test_assert(iexp[2] == math::exp(iv31[2]));
}

TEST_CASE(log) {
  const auto flog = math::log(fv31);
  test_assert(flog[0] == math::log(fv31[0]));
  test_assert(flog[1] == math::log(fv31[1]));
  test_assert(flog[2] == math::log(fv31[2]));

  const auto ilog = math::log(iv31);
  test_assert(ilog[0] == math::log(iv31[0]));
  test_assert(ilog[1] == math::log(iv31[1]));
  test_assert(ilog[2] == math::log(iv31[2]));
}

TEST_CASE(pow) {
  const auto fpow1 = math::pow(fv31, f2);
  test_assert(fpow1[0] == math::pow(fv31[0], f2));
  test_assert(fpow1[1] == math::pow(fv31[1], f2));
  test_assert(fpow1[2] == math::pow(fv31[2], f2));

  const auto ipow1 = math::pow(iv31, f2);
  test_assert(ipow1[0] == math::pow(iv31[0], f2));
  test_assert(ipow1[1] == math::pow(iv31[1], f2));
  test_assert(ipow1[2] == math::pow(iv31[2], f2));

  const auto fpow2 = math::pow(fv31, fv32);
  test_assert(fpow2[0] == math::pow(fv31[0], fv32[0]));
  test_assert(fpow2[1] == math::pow(fv31[1], fv32[1]));
  test_assert(fpow2[2] == math::pow(fv31[2], fv32[2]));

  const auto ipow2 = math::pow(iv31, fv32);
  test_assert(ipow2[0] == math::pow(iv31[0], fv32[0]));
  test_assert(ipow2[1] == math::pow(iv31[1], fv32[1]));
  test_assert(ipow2[2] == math::pow(iv31[2], fv32[2]));
}

TEST_CASE(recip) {
  const auto frecip = math::recip(fv31);
  test_assert(frecip[0] == math::recip(fv31[0]));
  test_assert(frecip[1] == math::recip(fv31[1]));
  test_assert(frecip[2] == math::recip(fv31[2]));

  const auto irecip = math::recip(iv31);
  test_assert(irecip[0] == math::recip(iv31[0]));
  test_assert(irecip[1] == math::recip(iv31[1]));
  test_assert(irecip[2] == math::recip(iv31[2]));
}

TEST_CASE(sqrt) {
  const auto fsqrt = math::sqrt(fv31);
  test_assert(fsqrt[0] == math::sqrt(fv31[0]));
  test_assert(fsqrt[1] == math::sqrt(fv31[1]));
  test_assert(fsqrt[2] == math::sqrt(fv31[2]));

  const auto isqrt = math::sqrt(iv31);
  test_assert(isqrt[0] == math::sqrt(iv31[0]));
  test_assert(isqrt[1] == math::sqrt(iv31[1]));
  test_assert(isqrt[2] == math::sqrt(iv31[2]));
}

TEST_CASE(rsqrt) {
  const auto frsqrt = math::rsqrt(fv31);
  test_assert(frsqrt[0] == math::rsqrt(fv31[0]));
  test_assert(frsqrt[1] == math::rsqrt(fv31[1]));
  test_assert(frsqrt[2] == math::rsqrt(fv31[2]));

  const auto irsqrt = math::rsqrt(iv31);
  test_assert(irsqrt[0] == math::rsqrt(iv31[0]));
  test_assert(irsqrt[1] == math::rsqrt(iv31[1]));
  test_assert(irsqrt[2] == math::rsqrt(iv31[2]));
}

TEST_CASE(min) {
  const auto fmin = math::min(fv31, fv32);
  test_assert(fmin[0] == math::min(fv31[0], fv32[0]));
  test_assert(fmin[1] == math::min(fv31[1], fv32[1]));
  test_assert(fmin[2] == math::min(fv31[2], fv32[2]));

  const auto imin = math::min(iv31, iv32);
  test_assert(imin[0] == math::min(iv31[0], iv32[0]));
  test_assert(imin[1] == math::min(iv31[1], iv32[1]));
  test_assert(imin[2] == math::min(iv31[2], iv32[2]));
}

TEST_CASE(max) {
  const auto fmax = math::max(fv31, fv32);
  test_assert(fmax[0] == math::max(fv31[0], fv32[0]));
  test_assert(fmax[1] == math::max(fv31[1], fv32[1]));
  test_assert(fmax[2] == math::max(fv31[2], fv32[2]));

  const auto imax = math::max(iv31, iv32);
  test_assert(imax[0] == math::max(iv31[0], iv32[0]));
  test_assert(imax[1] == math::max(iv31[1], iv32[1]));
  test_assert(imax[2] == math::max(iv31[2], iv32[2]));
}

TEST_CASE(abs) {
  const auto fabs = math::abs(fv32);
  test_assert(fabs[0] == math::abs(fv32[0]));
  test_assert(fabs[1] == math::abs(fv32[1]));
  test_assert(fabs[2] == math::abs(fv32[2]));

  const auto iabs = math::abs(iv32);
  test_assert(iabs[0] == math::abs(iv32[0]));
  test_assert(iabs[1] == math::abs(iv32[1]));
  test_assert(iabs[2] == math::abs(iv32[2]));

  const auto uabs = math::abs(uv32);
  test_assert(uabs[0] == math::abs(uv32[0]));
  test_assert(uabs[1] == math::abs(uv32[1]));
  test_assert(uabs[2] == math::abs(uv32[2]));
}

TEST_CASE(dot) {
  CONST_OR_CONSTEXPR auto fdot = math::dot(fv31, dv32);
  test_assert(fdot
      == fv31[0] * dv32[0]
      + fv31[1] * dv32[1]
      + fv31[2] * dv32[2]);

  CONST_OR_CONSTEXPR auto idot = math::dot(iv31, uv32);
  test_assert(idot
      == iv31[0] * uv32[0]
      + iv31[1] * uv32[1]
      + iv31[2] * uv32[2]);
}

TEST_CASE(cross) {
  CONST_OR_CONSTEXPR auto fcross = math::cross(fv31, dv32);
  test_assert((fcross == dvec3{
    fv31[1] * dv32[2] - fv31[2] * dv32[1],
    fv31[2] * dv32[0] - fv31[0] * dv32[2],
    fv31[0] * dv32[1] - fv31[1] * dv32[0],
  }));

  CONST_OR_CONSTEXPR auto icross = math::cross(iv31, uv32);
  test_assert((icross == uvec3{
    iv31[1] * uv32[2] - iv31[2] * uv32[1],
    iv31[2] * uv32[0] - iv31[0] * uv32[2],
    iv31[0] * uv32[1] - iv31[1] * uv32[0],
  }));
}

TEST_CASE(length2) {
  test_assert(math::length2(fv31) ==
    math::length2(fv31[0])
    + math::length2(fv31[1])
    + math::length2(fv31[2]));

  test_assert(math::length2(iv31) == math::length2(dvec3(iv31)));
}

TEST_CASE(length) {
  test_assert(math::length(fv31) == math::sqrt(math::length2(fv31)));
  test_assert(math::length(iv31) == math::length(dvec3(iv31)));
}

TEST_CASE(normalize) {
  test_assert(math::normalize(fv31) == fv31 / math::length(fv31));
  test_assert(math::normalize(iv31) == math::normalize(dvec3(iv31)));
}

TEST_CASE(comp_mult) {
  CONST_OR_CONSTEXPR auto v = math::comp_mult(fv31, dv32);
  test_assert(v == fv31 * dv32);
}

TEST_CASE(select) {
  CONST_OR_CONSTEXPR fvec3 v1 =
      math::select(bvec3(true, false, true), fv31);
  CONST_OR_CONSTEXPR fvec3 v2 =
      math::select(bvec3(false, true, false), fv31);
  test_assert(v1 == fvec3(fv31[0], 0.0f, fv31[2]));
  test_assert(v2 == fvec3(0.0f, fv31[1], 0.0f));

  CONST_OR_CONSTEXPR fvec3 v3 =
      math::select(bvec3(true, false, true), fv31, fv32);
  CONST_OR_CONSTEXPR fvec3 v4 =
      math::select(bvec3(false, true, false), fv31, fv32);
  test_assert(v3 == fvec3(fv31[0], fv32[1], fv31[2]));
  test_assert(v4 == fvec3(fv32[0], fv31[1], fv32[2]));
}

TEST_CASE(less) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::less(v1, v2);
  test_assert(b == bvec3(false, false, true));
}

TEST_CASE(less_equal) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::less_equal(v1, v2);
  test_assert(b == bvec3(false, true, true));
}

TEST_CASE(greater) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::greater(v1, v2);
  test_assert(b == bvec3(true, false, false));
}

TEST_CASE(greater_equal) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::greater_equal(v1, v2);
  test_assert(b == bvec3(true, true, false));
}

TEST_CASE(equal) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::equal(v1, v2);
  test_assert(b == bvec3(false, true, false));
}

TEST_CASE(not_equal) {
  CONST_OR_CONSTEXPR fvec3 v1(1.1f, 2.2f, 3.3f);
  CONST_OR_CONSTEXPR fvec3 v2(0.0f, 2.2f, 3.4f);
  CONST_OR_CONSTEXPR bvec3 b = math::not_equal(v1, v2);
  test_assert(b == bvec3(true, false, true));
}

TEST_CASE(rotation_vec) {
  const float x = 1.1f;
  const float y = 2.2f;
  const float z = 3.3f;
  const float w = 4.4f;
  const fvec3 v1 = math::rotation_vec(fvec3(x, y, z), w);
  test_assert(v1 == fvec3(x, y, z) * w);

  const fvec3 v2 = math::rotation_vec(x, y, z, w);
  test_assert(v2 == v1);

  const fvec3 v3 = math::rotation_vec(fvec4(x, y, z, w));
  test_assert(v3 == v1);
}

}
