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

CONST_OR_CONSTEXPR fvec2 fv21(1.1f, 1.2f);
CONST_OR_CONSTEXPR fvec2 fv22(2.2f, 2.4f);

CONST_OR_CONSTEXPR dvec2 dv21(1.1, 1.2);
CONST_OR_CONSTEXPR dvec2 dv22(2.2, 2.4);

CONST_OR_CONSTEXPR ivec2 iv21(111, 222);
CONST_OR_CONSTEXPR ivec2 iv22(2, 4);

CONST_OR_CONSTEXPR uvec2 uv22(2u, 4u);

CONST_OR_CONSTEXPR mat2x2<unsigned int> um222{
  { 2u, 4u },
  { 6u, 8u },
};

TEST_CASE(default_constructor) {
  fvec2 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  CONST_OR_CONSTEXPR fvec2 v(1.1f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 1.1f);
}

TEST_CASE(scalar_component_constructor) {
  CONST_OR_CONSTEXPR fvec2 v = { 1.1f, 2.2f };
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
}

TEST_CASE(truncate_vec3_constructor) {
  CONST_OR_CONSTEXPR fvec2 v(fvec3(1.1f, 2.2f, 3.3f));
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
}

TEST_CASE(truncate_vec4_constructor) {
  CONST_OR_CONSTEXPR fvec2 v(fvec4(1.1f, 2.2f, 3.3f, 4.4f));
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR fvec2 v(dv21);
  test_assert(v[0] == static_cast<float>(dv21[0]));
  test_assert(v[1] == static_cast<float>(dv21[1]));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR dvec2 v = fv21;
  test_assert(v[0] == static_cast<double>(fv21[0]));
  test_assert(v[1] == static_cast<double>(fv21[1]));
}

TEST_CASE(zero) {
  CONST_OR_CONSTEXPR auto v = fvec2::zero();
  test_assert(v[0] == 0);
  test_assert(v[1] == 0);
}

TEST_CASE(x_axis) {
  CONST_OR_CONSTEXPR auto v = fvec2::x_axis();
  test_assert(v[0] == 1);
  test_assert(v[1] == 0);
}

TEST_CASE(y_axis) {
  CONST_OR_CONSTEXPR auto v = fvec2::y_axis();
  test_assert(v[0] == 0);
  test_assert(v[1] == 1);
}

TEST_CASE(x) {
  CONST_OR_CONSTEXPR float x = fv21.x();
  test_assert(x == fv21[0]);
}

TEST_CASE(set_x) {
  fvec2 v(1.1f, 1.2f);
  v.set_x(2.1f);
  test_assert(v[0] == 2.1f);
  test_assert(v[1] == 1.2f);
}

TEST_CASE(y) {
  CONST_OR_CONSTEXPR float y = fv21.y();
  test_assert(y == fv21[1]);
}

TEST_CASE(set_y) {
  fvec2 v(1.1f, 1.2f);
  v.set_y(2.2f);
  test_assert(v[0] == 1.1f);
  test_assert(v[1] == 2.2f);
}

TEST_CASE(data) {
  fvec2 v = fv21;
  float* data = v.data();
  test_assert(static_cast<void*>(data) == static_cast<void*>(&v));

  const fvec2& cv = v;
  const float* cdata = cv.data();
  test_assert(cdata == data);
}

TEST_CASE(subscript_operator) {
  CONST_OR_CONSTEXPR fvec2 cev(1.1f, 2.2f);
  CONST_OR_CONSTEXPR float cev0 = cev[0];
  CONST_OR_CONSTEXPR float cev1 = cev[1];
  test_assert(cev0 == 1.1f);
  test_assert(cev1 == 2.2f);

  fvec2 v = cev;
  float& v0 = v[0];
  float& v1 = v[1];
  test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
  test_assert(&v1 == &v0 + 1);

  const fvec2& cv = v;
  const float& cv0 = cv[0];
  const float& cv1 = cv[1];
  test_assert(&cv0 == &v0);
  test_assert(&cv1 == &v1);
}

TEST_CASE(pre_increment_operator) {
  fvec2 v = fv21;
  test_assert(&(++v) == &v);
  test_assert(v == fv21 + 1);
}

TEST_CASE(pre_decrement_operator) {
  fvec2 v = fv21;
  test_assert(&(--v) == &v);
  test_assert(v == fv21 - 1);
}

TEST_CASE(post_increment_operator) {
  fvec2 v = fv21;
  test_assert(v++ == fv21);
  test_assert(v == fv21 + 1);
}

TEST_CASE(post_decrement_operator) {
  fvec2 v = fv21;
  test_assert(v-- == fv21);
  test_assert(v == fv21 - 1);
}

TEST_CASE(addition_assignment_operator) {
  fvec2 v1 = fv21;
  test_assert(&(v1 += u2) == &v1);
  test_assert(v1 == fv21 + u2);

  fvec2 v2 = fv21;
  test_assert(&(v2 += uv22) == &v2);
  test_assert(v2 == fv21 + uv22);
}

TEST_CASE(subtraction_assignment_operator) {
  fvec2 v1 = fv21;
  test_assert(&(v1 -= u2) == &v1);
  test_assert(v1 == fv21 - u2);

  fvec2 v2 = fv21;
  test_assert(&(v2 -= uv22) == &v2);
  test_assert(v2 == fv21 - uv22);
}

TEST_CASE(multiplication_assignment_operator) {
  fvec2 v1 = fv21;
  test_assert(&(v1 *= u2) == &v1);
  test_assert(v1 == fv21 * u2);

  fvec2 v2 = fv21;
  test_assert(&(v2 *= uv22) == &v2);
  test_assert(v2 == fv21 * uv22);

  fvec2 v3 = fv21;
  test_assert(&(v3 *= um222) == &v3);
  test_assert(v3 == fv21 * um222);
}

TEST_CASE(division_assignment_operator) {
  fvec2 v1 = fv21;
  test_assert(&(v1 /= u2) == &v1);
  test_assert(v1 == fv21 / u2);

  fvec2 v2 = fv21;
  test_assert(&(v2 /= uv22) == &v2);
  test_assert(v2 == fv21 / uv22);
}

TEST_CASE(modulo_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 %= u2) == &v1);
  test_assert(v1 == ivec2(iv21 % u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 %= uv22) == &v2);
  test_assert(v2 == ivec2(iv21 % uv22));
}

TEST_CASE(bitwise_and_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 &= u2) == &v1);
  test_assert(v1 == ivec2(iv21 & u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 &= uv22) == &v2);
  test_assert(v2 == ivec2(iv21 & uv22));
}

TEST_CASE(bitwise_or_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 |= u2) == &v1);
  test_assert(v1 == ivec2(iv21 | u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 |= uv22) == &v2);
  test_assert(v2 == ivec2(iv21 | uv22));
}

TEST_CASE(bitwise_xor_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 ^= u2) == &v1);
  test_assert(v1 == ivec2(iv21 ^ u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 ^= uv22) == &v2);
  test_assert(v2 == ivec2(iv21 ^ uv22));
}

TEST_CASE(bitwise_shift_left_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 <<= u2) == &v1);
  test_assert(v1 == (iv21 << u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 <<= uv22) == &v2);
  test_assert(v2 == (iv21 << uv22));
}

TEST_CASE(bitwise_shift_right_assignment_operator) {
  ivec2 v1 = iv21;
  test_assert(&(v1 >>= u2) == &v1);
  test_assert(v1 == (iv21 >> u2));

  ivec2 v2 = iv21;
  test_assert(&(v2 >>= uv22) == &v2);
  test_assert(v2 == (iv21 >> uv22));
}

TEST_CASE(unary_plus_operator) {
  CONST_OR_CONSTEXPR auto v = +fv21;
  test_assert(v[0] == +fv21[0]);
  test_assert(v[1] == +fv21[1]);
}

TEST_CASE(unary_minus_operator) {
  CONST_OR_CONSTEXPR auto v = -fv21;
  test_assert(v[0] == -fv21[0]);
  test_assert(v[1] == -fv21[1]);
}

TEST_CASE(bitwise_not_operator) {
  CONST_OR_CONSTEXPR auto v = ~iv21;
  test_assert(v[0] == ~iv21[0]);
  test_assert(v[1] == ~iv21[1]);
}

TEST_CASE(addition_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 + dv22;
  test_assert(v1[0] == f1 + dv22[0]);
  test_assert(v1[1] == f1 + dv22[1]);

  CONST_OR_CONSTEXPR auto v2 = fv21 + d2;
  test_assert(v2[0] == fv21[0] + d2);
  test_assert(v2[1] == fv21[1] + d2);

  CONST_OR_CONSTEXPR auto v3 = fv21 + dv22;
  test_assert(v3[0] == fv21[0] + dv22[0]);
  test_assert(v3[1] == fv21[1] + dv22[1]);
}

TEST_CASE(subtraction_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 - dv22;
  test_assert(v1[0] == f1 - dv22[0]);
  test_assert(v1[1] == f1 - dv22[1]);

  CONST_OR_CONSTEXPR auto v2 = fv21 - d2;
  test_assert(v2[0] == fv21[0] - d2);
  test_assert(v2[1] == fv21[1] - d2);

  CONST_OR_CONSTEXPR auto v3 = fv21 - dv22;
  test_assert(v3[0] == fv21[0] - dv22[0]);
  test_assert(v3[1] == fv21[1] - dv22[1]);
}

TEST_CASE(multiplication_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 * dv22;
  test_assert(v1[0] == f1 * dv22[0]);
  test_assert(v1[1] == f1 * dv22[1]);

  CONST_OR_CONSTEXPR auto v2 = fv21 * d2;
  test_assert(v2[0] == fv21[0] * d2);
  test_assert(v2[1] == fv21[1] * d2);

  CONST_OR_CONSTEXPR auto v3 = fv21 * dv22;
  test_assert(v3[0] == fv21[0] * dv22[0]);
  test_assert(v3[1] == fv21[1] * dv22[1]);
}

TEST_CASE(division_operator) {
  CONST_OR_CONSTEXPR auto v1 = f1 / dv22;
  test_assert(v1[0] == f1 / dv22[0]);
  test_assert(v1[1] == f1 / dv22[1]);

  CONST_OR_CONSTEXPR auto v2 = fv21 / d2;
  test_assert(v2[0] == fv21[0] / d2);
  test_assert(v2[1] == fv21[1] / d2);

  CONST_OR_CONSTEXPR auto v3 = fv21 / dv22;
  test_assert(v3[0] == fv21[0] / dv22[0]);
  test_assert(v3[1] == fv21[1] / dv22[1]);
}

TEST_CASE(modulo_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 % uv22;
  test_assert(v1[0] == i1 % uv22[0]);
  test_assert(v1[1] == i1 % uv22[1]);

  CONST_OR_CONSTEXPR auto v2 = iv21 % u2;
  test_assert(v2[0] == iv21[0] % u2);
  test_assert(v2[1] == iv21[1] % u2);

  CONST_OR_CONSTEXPR auto v3 = iv21 % uv22;
  test_assert(v3[0] == iv21[0] % uv22[0]);
  test_assert(v3[1] == iv21[1] % uv22[1]);
}

TEST_CASE(bitwise_and_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 & uv22;
  test_assert(v1[0] == (i1 & uv22[0]));
  test_assert(v1[1] == (i1 & uv22[1]));

  CONST_OR_CONSTEXPR auto v2 = iv21 & u2;
  test_assert(v2[0] == (iv21[0] & u2));
  test_assert(v2[1] == (iv21[1] & u2));

  CONST_OR_CONSTEXPR auto v3 = iv21 & uv22;
  test_assert(v3[0] == (iv21[0] & uv22[0]));
  test_assert(v3[1] == (iv21[1] & uv22[1]));
}

TEST_CASE(bitwise_or_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 | uv22;
  test_assert(v1[0] == (i1 | uv22[0]));
  test_assert(v1[1] == (i1 | uv22[1]));

  CONST_OR_CONSTEXPR auto v2 = iv21 | u2;
  test_assert(v2[0] == (iv21[0] | u2));
  test_assert(v2[1] == (iv21[1] | u2));

  CONST_OR_CONSTEXPR auto v3 = iv21 | uv22;
  test_assert(v3[0] == (iv21[0] | uv22[0]));
  test_assert(v3[1] == (iv21[1] | uv22[1]));
}

TEST_CASE(bitwise_xor_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 ^ uv22;
  test_assert(v1[0] == (i1 ^ uv22[0]));
  test_assert(v1[1] == (i1 ^ uv22[1]));

  CONST_OR_CONSTEXPR auto v2 = iv21 ^ u2;
  test_assert(v2[0] == (iv21[0] ^ u2));
  test_assert(v2[1] == (iv21[1] ^ u2));

  CONST_OR_CONSTEXPR auto v3 = iv21 ^ uv22;
  test_assert(v3[0] == (iv21[0] ^ uv22[0]));
  test_assert(v3[1] == (iv21[1] ^ uv22[1]));
}

TEST_CASE(bitwise_shift_left_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 << uv22;
  test_assert(v1[0] == (i1 << uv22[0]));
  test_assert(v1[1] == (i1 << uv22[1]));

  CONST_OR_CONSTEXPR auto v2 = iv21 << u2;
  test_assert(v2[0] == (iv21[0] << u2));
  test_assert(v2[1] == (iv21[1] << u2));

  CONST_OR_CONSTEXPR auto v3 = iv21 << uv22;
  test_assert(v3[0] == (iv21[0] << uv22[0]));
  test_assert(v3[1] == (iv21[1] << uv22[1]));
}

TEST_CASE(bitwise_shift_right_operator) {
  CONST_OR_CONSTEXPR auto v1 = i1 >> uv22;
  test_assert(v1[0] == (i1 >> uv22[0]));
  test_assert(v1[1] == (i1 >> uv22[1]));

  CONST_OR_CONSTEXPR auto v2 = iv21 >> u2;
  test_assert(v2[0] == (iv21[0] >> u2));
  test_assert(v2[1] == (iv21[1] >> u2));

  CONST_OR_CONSTEXPR auto v3 = iv21 >> uv22;
  test_assert(v3[0] == (iv21[0] >> uv22[0]));
  test_assert(v3[1] == (iv21[1] >> uv22[1]));
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fvec2 v1(1.0f, 2.0f);
  CONST_OR_CONSTEXPR ivec2 v2(1, 2);
  CONST_OR_CONSTEXPR ivec2 v3(0, 2);
  CONST_OR_CONSTEXPR ivec2 v4(1, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fvec2 v1(1.0f, 2.0f);
  CONST_OR_CONSTEXPR ivec2 v2(1, 2);
  CONST_OR_CONSTEXPR ivec2 v3(0, 2);
  CONST_OR_CONSTEXPR ivec2 v4(1, 0);
  CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
  CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
  CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
}

TEST_CASE(sin) {
  const auto fsin = math::sin(fv21);
  test_assert(fsin[0] == math::sin(fv21[0]));
  test_assert(fsin[1] == math::sin(fv21[1]));

  const auto isin = math::sin(iv21);
  test_assert(isin[0] == math::sin(iv21[0]));
  test_assert(isin[1] == math::sin(iv21[1]));
}

TEST_CASE(cos) {
  const auto fcos = math::cos(fv21);
  test_assert(fcos[0] == math::cos(fv21[0]));
  test_assert(fcos[1] == math::cos(fv21[1]));

  const auto icos = math::cos(iv21);
  test_assert(icos[0] == math::cos(iv21[0]));
  test_assert(icos[1] == math::cos(iv21[1]));
}

TEST_CASE(sincos) {
  fvec2 fsin, fcos;
  math::sincos(fv21, fsin, fcos);
  test_assert(fsin == math::sin(fv21));
  test_assert(fcos == math::cos(fv21));

  dvec2 isin, icos;
  math::sincos(iv21, isin, icos);
  test_assert(isin == math::sin(iv21));
  test_assert(icos == math::cos(iv21));
}

TEST_CASE(exp) {
  const auto fexp = math::exp(fv21);
  test_assert(fexp[0] == math::exp(fv21[0]));
  test_assert(fexp[1] == math::exp(fv21[1]));

  const auto iexp = math::exp(iv21);
  test_assert(iexp[0] == math::exp(iv21[0]));
  test_assert(iexp[1] == math::exp(iv21[1]));
}

TEST_CASE(log) {
  const auto flog = math::log(fv21);
  test_assert(flog[0] == math::log(fv21[0]));
  test_assert(flog[1] == math::log(fv21[1]));

  const auto ilog = math::log(iv21);
  test_assert(ilog[0] == math::log(iv21[0]));
  test_assert(ilog[1] == math::log(iv21[1]));
}

TEST_CASE(pow) {
  const auto fpow1 = math::pow(fv21, f2);
  test_assert(fpow1[0] == math::pow(fv21[0], f2));
  test_assert(fpow1[1] == math::pow(fv21[1], f2));

  const auto ipow1 = math::pow(iv21, f2);
  test_assert(ipow1[0] == math::pow(iv21[0], f2));
  test_assert(ipow1[1] == math::pow(iv21[1], f2));

  const auto fpow2 = math::pow(fv21, fv22);
  test_assert(fpow2[0] == math::pow(fv21[0], fv22[0]));
  test_assert(fpow2[1] == math::pow(fv21[1], fv22[1]));

  const auto ipow2 = math::pow(iv21, fv22);
  test_assert(ipow2[0] == math::pow(iv21[0], fv22[0]));
  test_assert(ipow2[1] == math::pow(iv21[1], fv22[1]));
}

TEST_CASE(recip) {
  const auto frecip = math::recip(fv21);
  test_assert(frecip[0] == math::recip(fv21[0]));
  test_assert(frecip[1] == math::recip(fv21[1]));

  const auto irecip = math::recip(iv21);
  test_assert(irecip[0] == math::recip(iv21[0]));
  test_assert(irecip[1] == math::recip(iv21[1]));
}

TEST_CASE(sqrt) {
  const auto fsqrt = math::sqrt(fv21);
  test_assert(fsqrt[0] == math::sqrt(fv21[0]));
  test_assert(fsqrt[1] == math::sqrt(fv21[1]));

  const auto isqrt = math::sqrt(iv21);
  test_assert(isqrt[0] == math::sqrt(iv21[0]));
  test_assert(isqrt[1] == math::sqrt(iv21[1]));
}

TEST_CASE(rsqrt) {
  const auto frsqrt = math::rsqrt(fv21);
  test_assert(frsqrt[0] == math::rsqrt(fv21[0]));
  test_assert(frsqrt[1] == math::rsqrt(fv21[1]));

  const auto irsqrt = math::rsqrt(iv21);
  test_assert(irsqrt[0] == math::rsqrt(iv21[0]));
  test_assert(irsqrt[1] == math::rsqrt(iv21[1]));
}

TEST_CASE(min) {
  const auto fmin = math::min(fv21, fv22);
  test_assert(fmin[0] == math::min(fv21[0], fv22[0]));
  test_assert(fmin[1] == math::min(fv21[1], fv22[1]));

  const auto imin = math::min(iv21, iv22);
  test_assert(imin[0] == math::min(iv21[0], iv22[0]));
  test_assert(imin[1] == math::min(iv21[1], iv22[1]));
}

TEST_CASE(max) {
  const auto fmax = math::max(fv21, fv22);
  test_assert(fmax[0] == math::max(fv21[0], fv22[0]));
  test_assert(fmax[1] == math::max(fv21[1], fv22[1]));

  const auto imax = math::max(iv21, iv22);
  test_assert(imax[0] == math::max(iv21[0], iv22[0]));
  test_assert(imax[1] == math::max(iv21[1], iv22[1]));
}

TEST_CASE(abs) {
  const auto fabs = math::abs(fv22);
  test_assert(fabs[0] == math::abs(fv22[0]));
  test_assert(fabs[1] == math::abs(fv22[1]));

  const auto iabs = math::abs(iv22);
  test_assert(iabs[0] == math::abs(iv22[0]));
  test_assert(iabs[1] == math::abs(iv22[1]));

  const auto uabs = math::abs(uv22);
  test_assert(uabs[0] == math::abs(uv22[0]));
  test_assert(uabs[1] == math::abs(uv22[1]));
}

TEST_CASE(dot) {
  CONST_OR_CONSTEXPR auto fdot = math::dot(fv21, dv22);
  test_assert(fdot
      == fv21[0] * dv22[0]
      + fv21[1] * dv22[1]);

  CONST_OR_CONSTEXPR auto idot = math::dot(iv21, uv22);
  test_assert(idot
      == iv21[0] * uv22[0]
      + iv21[1] * uv22[1]);
}

TEST_CASE(length2) {
  test_assert(math::length2(fv21)
      == math::length2(fv21[0])
      + math::length2(fv21[1]));
  test_assert(math::length2(iv21) == math::length2(dvec2(iv21)));
}

TEST_CASE(length) {
  test_assert(math::length(fv21) == math::sqrt(math::length2(fv21)));
  test_assert(math::length(iv21) == math::length(dvec2(iv21)));
}

TEST_CASE(normalize) {
  test_assert(math::normalize(fv21) == fv21 / math::length(fv21));
  test_assert(math::normalize(iv21) == math::normalize(dvec2(iv21)));
}

TEST_CASE(comp_mult) {
  CONST_OR_CONSTEXPR auto v = math::comp_mult(fv21, dv22);
  test_assert(v == fv21 * dv22);
}

TEST_CASE(select) {
  CONST_OR_CONSTEXPR fvec2 v1 = math::select(fv21, bvec2(true, false));
  CONST_OR_CONSTEXPR fvec2 v2 = math::select(fv21, bvec2(false, true));
  test_assert(v1 == fvec2(fv21[0], 0.0f));
  test_assert(v2 == fvec2(0.0f, fv21[1]));
}

TEST_CASE(less) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.3f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::less(v1, v2);
  test_assert(b1 == bvec2(false, true));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec2 f4(3.4f, 4.4f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::less(f3, f4);
  test_assert(b2 == bvec2(true, false));
}

TEST_CASE(less_equal) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.3f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::less_equal(v1, v2);
  test_assert(b1 == bvec2(false, true));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec2 f4(3.3f, 4.3f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::less_equal(f3, f4);
  test_assert(b2 == bvec2(true, false));
}

TEST_CASE(greater) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.3f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::greater(v1, v2);
  test_assert(b1 == bvec2(true, false));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec2 f4(3.3f, 4.3f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::greater(f3, f4);
  test_assert(b2 == bvec2(false, true));
}

TEST_CASE(greater_equal) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.3f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::greater_equal(v1, v2);
  test_assert(b1 == bvec2(true, false));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.4f);
  CONST_OR_CONSTEXPR fvec2 f4(3.4f, 4.4f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::greater_equal(f3, f4);
  test_assert(b2 == bvec2(false, true));
}

TEST_CASE(equal) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.2f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::equal(v1, v2);
  test_assert(b1 == bvec2(false, true));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.3f);
  CONST_OR_CONSTEXPR fvec2 f4(3.3f, 4.4f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::equal(f3, f4);
  test_assert(b2 == bvec2(true, false));
}

TEST_CASE(not_equal) {
  CONST_OR_CONSTEXPR fvec2 v1(1.1f, 2.2f);
  CONST_OR_CONSTEXPR fvec2 v2(0.0f, 2.2f);
  CONST_OR_CONSTEXPR bvec2 b1 = math::not_equal(v1, v2);
  test_assert(b1 == bvec2(true, false));

  CONST_OR_CONSTEXPR fvec2 f3(3.3f, 4.3f);
  CONST_OR_CONSTEXPR fvec2 f4(3.3f, 4.4f);
  CONST_OR_CONSTEXPR bvec2 b2 = math::not_equal(f3, f4);
  test_assert(b2 == bvec2(false, true));
}

}
