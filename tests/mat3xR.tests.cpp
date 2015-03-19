//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/mat.hpp>
#include <mon/test_case.hpp>

#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace {
using namespace tue;

constexpr auto f1 = 1.1f;
constexpr auto f2 = 2.2f;

constexpr auto d2 = 2.2;

constexpr auto i1 = 111;

constexpr auto u2 = 2u;

CONST_OR_CONSTEXPR fmat3x2 fm321{
  { 1.1f, 1.2f },
  { 2.1f, 2.2f },
  { 3.1f, 3.2f },
};

CONST_OR_CONSTEXPR fmat3x2 fm322{
  { 2.2f, 2.4f },
  { 4.2f, 4.4f },
  { 6.2f, 6.4f },
};

CONST_OR_CONSTEXPR dmat3x2 dm321{
  { 1.1, 1.2 },
  { 2.1, 2.2 },
  { 3.1, 3.2 },
};

CONST_OR_CONSTEXPR dmat3x2 dm322{
  { 2.2, 2.4 },
  { 4.2, 4.4 },
  { 6.2, 6.4 },
};

CONST_OR_CONSTEXPR mat3x2<int> im321{
  { 111, 222 },
  { 333, 444 },
  { 555, 666 },
};

CONST_OR_CONSTEXPR mat3x2<int> im322{
  { 2, 3 },
  { 4, 5 },
  { 6, 7 },
};

CONST_OR_CONSTEXPR mat3x2<unsigned int> um322{
  { 2u, 3u },
  { 4u, 5u },
  { 6u, 7u },
};

CONST_OR_CONSTEXPR mat3x3<unsigned int> um332{
  { 2u, 3u,  4u },
  { 5u, 6u,  7u },
  { 8u, 9u, 10u },
};

TEST_CASE(default_constructor) {
  fmat3x2 m;
  unused(m);
}

TEST_CASE(scalar_constructor) {
  CONST_OR_CONSTEXPR fmat3x2 m1(1.1f);
  test_assert(m1[0] == fvec2(1.1f, 0.0f));
  test_assert(m1[1] == fvec2(0.0f, 1.1f));
  test_assert(m1[2] == fvec2(0.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x3 m2(2.2f);
  test_assert(m2[0] == fvec3(2.2f, 0.0f, 0.0f));
  test_assert(m2[1] == fvec3(0.0f, 2.2f, 0.0f));
  test_assert(m2[2] == fvec3(0.0f, 0.0f, 2.2f));

  CONST_OR_CONSTEXPR fmat3x4 m3(3.3f);
  test_assert(m3[0] == fvec4(3.3f, 0.0f, 0.0f, 0.0f));
  test_assert(m3[1] == fvec4(0.0f, 3.3f, 0.0f, 0.0f));
  test_assert(m3[2] == fvec4(0.0f, 0.0f, 3.3f, 0.0f));
}

TEST_CASE(column_constructor) {
  CONST_OR_CONSTEXPR fmat3x2 m = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  test_assert(m[0] == fvec2(1.1f, 1.2f));
  test_assert(m[1] == fvec2(2.1f, 2.2f));
  test_assert(m[2] == fvec2(3.1f, 3.2f));
}

TEST_CASE(extend_and_truncate_constructors) {
  CONST_OR_CONSTEXPR fmat4x4 m1({
    { 1.1f, 1.2f, 1.3f, 1.4f },
    { 2.1f, 2.2f, 2.3f, 2.4f },
    { 3.1f, 3.2f, 3.3f, 3.4f },
    { 4.1f, 4.2f, 4.3f, 4.4f },
  });

  CONST_OR_CONSTEXPR fmat3x2 m2((fmat2x2(m1)));
  test_assert(m2[0] == fvec2(1.1f, 1.2f));
  test_assert(m2[1] == fvec2(2.1f, 2.2f));
  test_assert(m2[2] == fvec2(0.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x2 m3((fmat2x3(m1)));
  test_assert(m3[0] == fvec2(1.1f, 1.2f));
  test_assert(m3[1] == fvec2(2.1f, 2.2f));
  test_assert(m3[2] == fvec2(0.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x2 m4((fmat2x4(m1)));
  test_assert(m4[0] == fvec2(1.1f, 1.2f));
  test_assert(m4[1] == fvec2(2.1f, 2.2f));
  test_assert(m4[2] == fvec2(0.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x2 m5((fmat3x2(m1)));
  test_assert(m5[0] == fvec2(1.1f, 1.2f));
  test_assert(m5[1] == fvec2(2.1f, 2.2f));
  test_assert(m5[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x2 m6((fmat3x3(m1)));
  test_assert(m6[0] == fvec2(1.1f, 1.2f));
  test_assert(m6[1] == fvec2(2.1f, 2.2f));
  test_assert(m6[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x2 m7((fmat3x4(m1)));
  test_assert(m7[0] == fvec2(1.1f, 1.2f));
  test_assert(m7[1] == fvec2(2.1f, 2.2f));
  test_assert(m7[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x2 m8((fmat4x2(m1)));
  test_assert(m8[0] == fvec2(1.1f, 1.2f));
  test_assert(m8[1] == fvec2(2.1f, 2.2f));
  test_assert(m8[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x2 m9((fmat4x3(m1)));
  test_assert(m9[0] == fvec2(1.1f, 1.2f));
  test_assert(m9[1] == fvec2(2.1f, 2.2f));
  test_assert(m9[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x2 m10((fmat4x4(m1)));
  test_assert(m10[0] == fvec2(1.1f, 1.2f));
  test_assert(m10[1] == fvec2(2.1f, 2.2f));
  test_assert(m10[2] == fvec2(3.1f, 3.2f));

  CONST_OR_CONSTEXPR fmat3x3 m11((fmat2x2(m1)));
  test_assert(m11[0] == fvec3(1.1f, 1.2f, 0.0f));
  test_assert(m11[1] == fvec3(2.1f, 2.2f, 0.0f));
  test_assert(m11[2] == fvec3(0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat3x3 m12((fmat2x3(m1)));
  test_assert(m12[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m12[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m12[2] == fvec3(0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat3x3 m13((fmat2x4(m1)));
  test_assert(m13[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m13[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m13[2] == fvec3(0.0f, 0.0f, 1.0f));

  CONST_OR_CONSTEXPR fmat3x3 m14((fmat3x2(m1)));
  test_assert(m14[0] == fvec3(1.1f, 1.2f, 0.0f));
  test_assert(m14[1] == fvec3(2.1f, 2.2f, 0.0f));
  test_assert(m14[2] == fvec3(3.1f, 3.2f, 1.0f));

  CONST_OR_CONSTEXPR fmat3x3 m15((fmat3x3(m1)));
  test_assert(m15[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m15[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m15[2] == fvec3(3.1f, 3.2f, 3.3f));

  CONST_OR_CONSTEXPR fmat3x3 m16((fmat3x4(m1)));
  test_assert(m16[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m16[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m16[2] == fvec3(3.1f, 3.2f, 3.3f));

  CONST_OR_CONSTEXPR fmat3x3 m17((fmat4x2(m1)));
  test_assert(m17[0] == fvec3(1.1f, 1.2f, 0.0f));
  test_assert(m17[1] == fvec3(2.1f, 2.2f, 0.0f));
  test_assert(m17[2] == fvec3(3.1f, 3.2f, 1.0f));

  CONST_OR_CONSTEXPR fmat3x3 m18((fmat4x3(m1)));
  test_assert(m18[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m18[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m18[2] == fvec3(3.1f, 3.2f, 3.3f));

  CONST_OR_CONSTEXPR fmat3x3 m19((fmat4x4(m1)));
  test_assert(m19[0] == fvec3(1.1f, 1.2f, 1.3f));
  test_assert(m19[1] == fvec3(2.1f, 2.2f, 2.3f));
  test_assert(m19[2] == fvec3(3.1f, 3.2f, 3.3f));

  CONST_OR_CONSTEXPR fmat3x4 m20((fmat2x2(m1)));
  test_assert(m20[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
  test_assert(m20[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
  test_assert(m20[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m21((fmat2x3(m1)));
  test_assert(m21[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
  test_assert(m21[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
  test_assert(m21[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m22((fmat2x4(m1)));
  test_assert(m22[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
  test_assert(m22[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
  test_assert(m22[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m23((fmat3x2(m1)));
  test_assert(m23[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
  test_assert(m23[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
  test_assert(m23[2] == fvec4(3.1f, 3.2f, 1.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m24((fmat3x3(m1)));
  test_assert(m24[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
  test_assert(m24[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
  test_assert(m24[2] == fvec4(3.1f, 3.2f, 3.3f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m25((fmat3x4(m1)));
  test_assert(m25[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
  test_assert(m25[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
  test_assert(m25[2] == fvec4(3.1f, 3.2f, 3.3f, 3.4f));

  CONST_OR_CONSTEXPR fmat3x4 m26((fmat4x2(m1)));
  test_assert(m26[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
  test_assert(m26[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
  test_assert(m26[2] == fvec4(3.1f, 3.2f, 1.0f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m27((fmat4x3(m1)));
  test_assert(m27[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
  test_assert(m27[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
  test_assert(m27[2] == fvec4(3.1f, 3.2f, 3.3f, 0.0f));

  CONST_OR_CONSTEXPR fmat3x4 m28((fmat4x4(m1)));
  test_assert(m28[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
  test_assert(m28[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
  test_assert(m28[2] == fvec4(3.1f, 3.2f, 3.3f, 3.4f));
}

TEST_CASE(explicit_conversion_constructor) {
  CONST_OR_CONSTEXPR fmat3x2 m(dm321);
  test_assert(m[0] == fvec2(dm321[0]));
  test_assert(m[1] == fvec2(dm321[1]));
  test_assert(m[2] == fvec2(dm321[2]));
}

TEST_CASE(implicit_conversion_operator) {
  CONST_OR_CONSTEXPR dmat3x2 m = fm321;
  test_assert(m[0] == dvec2(fm321[0]));
  test_assert(m[1] == dvec2(fm321[1]));
  test_assert(m[2] == dvec2(fm321[2]));
}

TEST_CASE(identity) {
  CONST_OR_CONSTEXPR auto m1 = fmat3x2::identity();
  CONST_OR_CONSTEXPR auto m2 = fmat3x3::identity();
  CONST_OR_CONSTEXPR auto m3 = fmat3x4::identity();
  test_assert(m1 == fmat3x2(1.0f));
  test_assert(m2 == fmat3x3(1.0f));
  test_assert(m3 == fmat3x4(1.0f));
}

TEST_CASE(zero) {
  CONST_OR_CONSTEXPR auto m1 = fmat3x2::zero();
  CONST_OR_CONSTEXPR auto m2 = fmat3x3::zero();
  CONST_OR_CONSTEXPR auto m3 = fmat3x4::zero();
  test_assert(m1 == fmat3x2(0.0f));
  test_assert(m2 == fmat3x3(0.0f));
  test_assert(m3 == fmat3x4(0.0f));
}

TEST_CASE(column) {
  CONST_OR_CONSTEXPR fvec2 column0 = fm321.column(0);
  CONST_OR_CONSTEXPR fvec2 column1 = fm321.column(1);
  CONST_OR_CONSTEXPR fvec2 column2 = fm321.column(2);
  test_assert(column0 == fm321[0]);
  test_assert(column1 == fm321[1]);
  test_assert(column2 == fm321[2]);
}

TEST_CASE(set_column) {
  fmat3x2 m;
  m.set_column(0, fvec2(1.1f, 1.2f));
  m.set_column(1, fvec2(2.1f, 2.2f));
  m.set_column(2, fvec2(3.1f, 3.2f));
  test_assert(m[0] == fvec2(1.1f, 1.2f));
  test_assert(m[1] == fvec2(2.1f, 2.2f));
  test_assert(m[2] == fvec2(3.1f, 3.2f));
}

TEST_CASE(row) {
  CONST_OR_CONSTEXPR fvec3 row0 = fm321.row(0);
  CONST_OR_CONSTEXPR fvec3 row1 = fm321.row(1);
  test_assert(row0 == fvec3(fm321[0][0], fm321[1][0], fm321[2][0]));
  test_assert(row1 == fvec3(fm321[0][1], fm321[1][1], fm321[2][1]));
}

TEST_CASE(set_row) {
  fmat3x2 m;
  m.set_row(0, fvec3(1.1f, 2.1f, 3.1f));
  m.set_row(1, fvec3(1.2f, 2.2f, 3.2f));
  test_assert(m[0] == fvec2(1.1f, 1.2f));
  test_assert(m[1] == fvec2(2.1f, 2.2f));
  test_assert(m[2] == fvec2(3.1f, 3.2f));
}

TEST_CASE(data) {
  fmat3x2 m = fm321;
  float* data = m.data();
  test_assert(static_cast<void*>(data) == static_cast<void*>(&m));

  const fmat3x2& cm = m;
  const float* cdata = cm.data();
  test_assert(cdata == data);
}

TEST_CASE(columns) {
  fmat3x2 m = fm321;
  fvec2* columns = m.columns();
  test_assert(static_cast<void*>(columns) == static_cast<void*>(&m));

  const fmat3x2& cm = m;
  const fvec2* ccolumns = cm.columns();
  test_assert(ccolumns == columns);
}

TEST_CASE(subscript_operator) {
  CONST_OR_CONSTEXPR fmat3x2 cem = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fvec2 cem0 = cem[0];
  CONST_OR_CONSTEXPR fvec2 cem1 = cem[1];
  CONST_OR_CONSTEXPR fvec2 cem2 = cem[2];
  test_assert(cem0 == fvec2(1.1f, 1.2f));
  test_assert(cem1 == fvec2(2.1f, 2.2f));
  test_assert(cem2 == fvec2(3.1f, 3.2f));

  fmat3x2 m = cem;
  fvec2& m0 = m[0];
  fvec2& m1 = m[1];
  fvec2& m2 = m[2];
  test_assert(static_cast<void*>(&m0) == static_cast<void*>(&m));
  test_assert(&m1 == &m0 + 1);
  test_assert(&m2 == &m0 + 2);

  const fmat3x2& cm = m;
  const fvec2& cm0 = cm[0];
  const fvec2& cm1 = cm[1];
  const fvec2& cm2 = cm[2];
  test_assert(&cm0 == &m0);
  test_assert(&cm1 == &m1);
  test_assert(&cm2 == &m2);
}

TEST_CASE(pre_increment_operator) {
  fmat3x2 m = fm321;
  test_assert(&(++m) == &m);
  test_assert(m == fm321 + 1);
}

TEST_CASE(pre_decrement_operator) {
  fmat3x2 m = fm321;
  test_assert(&(--m) == &m);
  test_assert(m == fm321 - 1);
}

TEST_CASE(post_increment_operator) {
  fmat3x2 m = fm321;
  test_assert(m++ == fm321);
  test_assert(m == fm321 + 1);
}

TEST_CASE(post_decrement_operator) {
  fmat3x2 m = fm321;
  test_assert(m-- == fm321);
  test_assert(m == fm321 - 1);
}

TEST_CASE(addition_assignment_operator) {
  fmat3x2 m1 = fm321;
  test_assert(&(m1 += u2) == &m1);
  test_assert(m1 == fm321 + u2);

  fmat3x2 m2 = fm321;
  test_assert(&(m2 += um322) == &m2);
  test_assert(m2 == fm321 + um322);
}

TEST_CASE(subtraction_assignment_operator) {
  fmat3x2 m1 = fm321;
  test_assert(&(m1 -= u2) == &m1);
  test_assert(m1 == fm321 - u2);

  fmat3x2 m2 = fm321;
  test_assert(&(m2 -= um322) == &m2);
  test_assert(m2 == fm321 - um322);
}

TEST_CASE(multiplication_assignment_operator) {
  fmat3x2 m1 = fm321;
  test_assert(&(m1 *= u2) == &m1);
  test_assert(m1 == fm321 * u2);

  fmat3x2 m2 = fm321;
  test_assert(&(m2 *= um332) == &m2);
  test_assert(m2 == fm321 * um332);
}

TEST_CASE(division_assignment_operator) {
  fmat3x2 m1 = fm321;
  test_assert(&(m1 /= u2) == &m1);
  test_assert(m1 == fm321 / u2);

  fmat3x2 m2 = fm321;
  test_assert(&(m2 /= um322) == &m2);
  test_assert(m2 == fm321 / um322);
}

TEST_CASE(modulo_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 %= u2) == &m1);
  test_assert(m1 == mat3x2<int>(im321 % u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 %= um322) == &m2);
  test_assert(m2 == mat3x2<int>(im321 % um322));
}

TEST_CASE(bitwise_and_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 &= u2) == &m1);
  test_assert(m1 == mat3x2<int>(im321 & u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 &= um322) == &m2);
  test_assert(m2 == mat3x2<int>(im321 & um322));
}

TEST_CASE(bitwise_or_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 |= u2) == &m1);
  test_assert(m1 == mat3x2<int>(im321 | u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 |= um322) == &m2);
  test_assert(m2 == mat3x2<int>(im321 | um322));
}

TEST_CASE(bitwise_xor_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 ^= u2) == &m1);
  test_assert(m1 == mat3x2<int>(im321 ^ u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 ^= um322) == &m2);
  test_assert(m2 == mat3x2<int>(im321 ^ um322));
}

TEST_CASE(bitwise_shift_left_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 <<= u2) == &m1);
  test_assert(m1 == (im321 << u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 <<= um322) == &m2);
  test_assert(m2 == (im321 << um322));
}

TEST_CASE(bitwise_shift_right_assignment_operator) {
  mat3x2<int> m1 = im321;
  test_assert(&(m1 >>= u2) == &m1);
  test_assert(m1 == (im321 >> u2));

  mat3x2<int> m2 = im321;
  test_assert(&(m2 >>= um322) == &m2);
  test_assert(m2 == (im321 >> um322));
}

TEST_CASE(unary_plus_operator) {
  CONST_OR_CONSTEXPR auto m = +fm321;
  test_assert(m[0] == +fm321[0]);
  test_assert(m[1] == +fm321[1]);
  test_assert(m[2] == +fm321[2]);
}

TEST_CASE(unary_minus_operator) {
  CONST_OR_CONSTEXPR auto m = -fm321;
  test_assert(m[0] == -fm321[0]);
  test_assert(m[1] == -fm321[1]);
  test_assert(m[2] == -fm321[2]);
}

TEST_CASE(bitwise_not_operator) {
  CONST_OR_CONSTEXPR auto m = ~im321;
  test_assert(m[0] == ~im321[0]);
  test_assert(m[1] == ~im321[1]);
  test_assert(m[2] == ~im321[2]);
}

TEST_CASE(addition_operator) {
  CONST_OR_CONSTEXPR auto m1 = f1 + dm322;
  test_assert(m1[0] == f1 + dm322[0]);
  test_assert(m1[1] == f1 + dm322[1]);
  test_assert(m1[2] == f1 + dm322[2]);

  CONST_OR_CONSTEXPR auto m2 = fm321 + d2;
  test_assert(m2[0] == fm321[0] + d2);
  test_assert(m2[1] == fm321[1] + d2);
  test_assert(m2[2] == fm321[2] + d2);

  CONST_OR_CONSTEXPR auto m3 = fm321 + dm322;
  test_assert(m3[0] == fm321[0] + dm322[0]);
  test_assert(m3[1] == fm321[1] + dm322[1]);
  test_assert(m3[2] == fm321[2] + dm322[2]);
}

TEST_CASE(subtraction_operator) {
  CONST_OR_CONSTEXPR auto m1 = f1 - dm322;
  test_assert(m1[0] == f1 - dm322[0]);
  test_assert(m1[1] == f1 - dm322[1]);
  test_assert(m1[2] == f1 - dm322[2]);

  CONST_OR_CONSTEXPR auto m2 = fm321 - d2;
  test_assert(m2[0] == fm321[0] - d2);
  test_assert(m2[1] == fm321[1] - d2);
  test_assert(m2[2] == fm321[2] - d2);

  CONST_OR_CONSTEXPR auto m3 = fm321 - dm322;
  test_assert(m3[0] == fm321[0] - dm322[0]);
  test_assert(m3[1] == fm321[1] - dm322[1]);
  test_assert(m3[2] == fm321[2] - dm322[2]);
}

TEST_CASE(multiplication_operator) {
  CONST_OR_CONSTEXPR auto m1 = f1 * dm322;
  test_assert(m1[0] == f1 * dm322[0]);
  test_assert(m1[1] == f1 * dm322[1]);
  test_assert(m1[2] == f1 * dm322[2]);

  CONST_OR_CONSTEXPR auto m2 = fm321 * d2;
  test_assert(m2[0] == fm321[0] * d2);
  test_assert(m2[1] == fm321[1] * d2);
  test_assert(m2[2] == fm321[2] * d2);
}

TEST_CASE(division_operator) {
  CONST_OR_CONSTEXPR auto m1 = f1 / dm322;
  test_assert(m1[0] == f1 / dm322[0]);
  test_assert(m1[1] == f1 / dm322[1]);
  test_assert(m1[2] == f1 / dm322[2]);

  CONST_OR_CONSTEXPR auto m2 = fm321 / d2;
  test_assert(m2[0] == fm321[0] / d2);
  test_assert(m2[1] == fm321[1] / d2);
  test_assert(m2[2] == fm321[2] / d2);

  CONST_OR_CONSTEXPR auto m3 = fm321 / dm322;
  test_assert(m3[0] == fm321[0] / dm322[0]);
  test_assert(m3[1] == fm321[1] / dm322[1]);
  test_assert(m3[2] == fm321[2] / dm322[2]);
}

TEST_CASE(modulo_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 % um322;
  test_assert(m1[0] == i1 % um322[0]);
  test_assert(m1[1] == i1 % um322[1]);
  test_assert(m1[2] == i1 % um322[2]);

  CONST_OR_CONSTEXPR auto m2 = im321 % u2;
  test_assert(m2[0] == im321[0] % u2);
  test_assert(m2[1] == im321[1] % u2);
  test_assert(m2[2] == im321[2] % u2);

  CONST_OR_CONSTEXPR auto m3 = im321 % um322;
  test_assert(m3[0] == im321[0] % um322[0]);
  test_assert(m3[1] == im321[1] % um322[1]);
  test_assert(m3[2] == im321[2] % um322[2]);
}

TEST_CASE(bitwise_and_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 & um322;
  test_assert(m1[0] == (i1 & um322[0]));
  test_assert(m1[1] == (i1 & um322[1]));
  test_assert(m1[2] == (i1 & um322[2]));

  CONST_OR_CONSTEXPR auto m2 = im321 & u2;
  test_assert(m2[0] == (im321[0] & u2));
  test_assert(m2[1] == (im321[1] & u2));
  test_assert(m2[2] == (im321[2] & u2));

  CONST_OR_CONSTEXPR auto m3 = im321 & um322;
  test_assert(m3[0] == (im321[0] & um322[0]));
  test_assert(m3[1] == (im321[1] & um322[1]));
  test_assert(m3[2] == (im321[2] & um322[2]));
}

TEST_CASE(bitwise_or_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 | um322;
  test_assert(m1[0] == (i1 | um322[0]));
  test_assert(m1[1] == (i1 | um322[1]));
  test_assert(m1[2] == (i1 | um322[2]));

  CONST_OR_CONSTEXPR auto m2 = im321 | u2;
  test_assert(m2[0] == (im321[0] | u2));
  test_assert(m2[1] == (im321[1] | u2));
  test_assert(m2[2] == (im321[2] | u2));

  CONST_OR_CONSTEXPR auto m3 = im321 | um322;
  test_assert(m3[0] == (im321[0] | um322[0]));
  test_assert(m3[1] == (im321[1] | um322[1]));
  test_assert(m3[2] == (im321[2] | um322[2]));
}

TEST_CASE(bitwise_xor_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 ^ um322;
  test_assert(m1[0] == (i1 ^ um322[0]));
  test_assert(m1[1] == (i1 ^ um322[1]));
  test_assert(m1[2] == (i1 ^ um322[2]));

  CONST_OR_CONSTEXPR auto m2 = im321 ^ u2;
  test_assert(m2[0] == (im321[0] ^ u2));
  test_assert(m2[1] == (im321[1] ^ u2));
  test_assert(m2[2] == (im321[2] ^ u2));

  CONST_OR_CONSTEXPR auto m3 = im321 ^ um322;
  test_assert(m3[0] == (im321[0] ^ um322[0]));
  test_assert(m3[1] == (im321[1] ^ um322[1]));
  test_assert(m3[2] == (im321[2] ^ um322[2]));
}

TEST_CASE(bitwise_shift_left_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 << um322;
  test_assert(m1[0] == (i1 << um322[0]));
  test_assert(m1[1] == (i1 << um322[1]));
  test_assert(m1[2] == (i1 << um322[2]));

  CONST_OR_CONSTEXPR auto m2 = im321 << u2;
  test_assert(m2[0] == (im321[0] << u2));
  test_assert(m2[1] == (im321[1] << u2));
  test_assert(m2[2] == (im321[2] << u2));

  CONST_OR_CONSTEXPR auto m3 = im321 << um322;
  test_assert(m3[0] == (im321[0] << um322[0]));
  test_assert(m3[1] == (im321[1] << um322[1]));
  test_assert(m3[2] == (im321[2] << um322[2]));
}

TEST_CASE(bitwise_shift_right_operator) {
  CONST_OR_CONSTEXPR auto m1 = i1 >> um322;
  test_assert(m1[0] == (i1 >> um322[0]));
  test_assert(m1[1] == (i1 >> um322[1]));
  test_assert(m1[2] == (i1 >> um322[2]));

  CONST_OR_CONSTEXPR auto m2 = im321 >> u2;
  test_assert(m2[0] == (im321[0] >> u2));
  test_assert(m2[1] == (im321[1] >> u2));
  test_assert(m2[2] == (im321[2] >> u2));

  CONST_OR_CONSTEXPR auto m3 = im321 >> um322;
  test_assert(m3[0] == (im321[0] >> um322[0]));
  test_assert(m3[1] == (im321[1] >> um322[1]));
  test_assert(m3[2] == (im321[2] >> um322[2]));
}

TEST_CASE(equality_operator) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    fvec2(1.0f),
    fvec2(2.0f),
    fvec2(3.0f),
  };
  CONST_OR_CONSTEXPR ivec2 iv0(0);
  CONST_OR_CONSTEXPR ivec2 iv1(1);
  CONST_OR_CONSTEXPR ivec2 iv2(2);
  CONST_OR_CONSTEXPR ivec2 iv3(3);
  CONST_OR_CONSTEXPR mat3x2<int> m2(iv1, iv2, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m3(iv0, iv2, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m4(iv1, iv0, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m5(iv1, iv2, iv0);
  CONST_OR_CONSTEXPR bool result1 = (m1 == m2);
  CONST_OR_CONSTEXPR bool result2 = (m1 == m3);
  CONST_OR_CONSTEXPR bool result3 = (m1 == m4);
  CONST_OR_CONSTEXPR bool result4 = (m1 == m5);
  test_assert(result1 == true);
  test_assert(result2 == false);
  test_assert(result3 == false);
  test_assert(result4 == false);
}

TEST_CASE(inequality_operator) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    fvec2(1.0f),
    fvec2(2.0f),
    fvec2(3.0f),
  };
  CONST_OR_CONSTEXPR ivec2 iv0(0);
  CONST_OR_CONSTEXPR ivec2 iv1(1);
  CONST_OR_CONSTEXPR ivec2 iv2(2);
  CONST_OR_CONSTEXPR ivec2 iv3(3);
  CONST_OR_CONSTEXPR mat3x2<int> m2(iv1, iv2, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m3(iv0, iv2, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m4(iv1, iv0, iv3);
  CONST_OR_CONSTEXPR mat3x2<int> m5(iv1, iv2, iv0);
  CONST_OR_CONSTEXPR bool result1 = (m1 != m2);
  CONST_OR_CONSTEXPR bool result2 = (m1 != m3);
  CONST_OR_CONSTEXPR bool result3 = (m1 != m4);
  CONST_OR_CONSTEXPR bool result4 = (m1 != m5);
  test_assert(result1 == false);
  test_assert(result2 == true);
  test_assert(result3 == true);
  test_assert(result4 == true);
}

TEST_CASE(sin) {
  const auto fsin = math::sin(fm321);
  test_assert(fsin[0] == math::sin(fm321[0]));
  test_assert(fsin[1] == math::sin(fm321[1]));
  test_assert(fsin[2] == math::sin(fm321[2]));

  const auto isin = math::sin(im321);
  test_assert(isin[0] == math::sin(im321[0]));
  test_assert(isin[1] == math::sin(im321[1]));
  test_assert(isin[2] == math::sin(im321[2]));
}

TEST_CASE(cos) {
  const auto fcos = math::cos(fm321);
  test_assert(fcos[0] == math::cos(fm321[0]));
  test_assert(fcos[1] == math::cos(fm321[1]));
  test_assert(fcos[2] == math::cos(fm321[2]));

  const auto icos = math::cos(im321);
  test_assert(icos[0] == math::cos(im321[0]));
  test_assert(icos[1] == math::cos(im321[1]));
  test_assert(icos[2] == math::cos(im321[2]));
}

TEST_CASE(sincos) {
  fmat3x2 fsin, fcos;
  math::sincos(fm321, fsin, fcos);
  test_assert(fsin == math::sin(fm321));
  test_assert(fcos == math::cos(fm321));

  dmat3x2 isin, icos;
  math::sincos(im321, isin, icos);
  test_assert(isin == math::sin(im321));
  test_assert(icos == math::cos(im321));
}

TEST_CASE(exp) {
  const auto fexp = math::exp(fm321);
  test_assert(fexp[0] == math::exp(fm321[0]));
  test_assert(fexp[1] == math::exp(fm321[1]));
  test_assert(fexp[2] == math::exp(fm321[2]));

  const auto iexp = math::exp(im321);
  test_assert(iexp[0] == math::exp(im321[0]));
  test_assert(iexp[1] == math::exp(im321[1]));
  test_assert(iexp[2] == math::exp(im321[2]));
}

TEST_CASE(log) {
  const auto flog = math::log(fm321);
  test_assert(flog[0] == math::log(fm321[0]));
  test_assert(flog[1] == math::log(fm321[1]));
  test_assert(flog[2] == math::log(fm321[2]));

  const auto ilog = math::log(im321);
  test_assert(ilog[0] == math::log(im321[0]));
  test_assert(ilog[1] == math::log(im321[1]));
  test_assert(ilog[2] == math::log(im321[2]));
}

TEST_CASE(pow) {
  const auto fpow1 = math::pow(fm321, f2);
  test_assert(fpow1[0] == math::pow(fm321[0], f2));
  test_assert(fpow1[1] == math::pow(fm321[1], f2));
  test_assert(fpow1[2] == math::pow(fm321[2], f2));

  const auto ipow1 = math::pow(im321, f2);
  test_assert(ipow1[0] == math::pow(im321[0], f2));
  test_assert(ipow1[1] == math::pow(im321[1], f2));
  test_assert(ipow1[2] == math::pow(im321[2], f2));

  const auto fpow2 = math::pow(fm321, fm322);
  test_assert(fpow2[0] == math::pow(fm321[0], fm322[0]));
  test_assert(fpow2[1] == math::pow(fm321[1], fm322[1]));
  test_assert(fpow2[2] == math::pow(fm321[2], fm322[2]));

  const auto ipow2 = math::pow(im321, fm322);
  test_assert(ipow2[0] == math::pow(im321[0], fm322[0]));
  test_assert(ipow2[1] == math::pow(im321[1], fm322[1]));
  test_assert(ipow2[2] == math::pow(im321[2], fm322[2]));
}

TEST_CASE(recip) {
  const auto frecip = math::recip(fm321);
  test_assert(frecip[0] == math::recip(fm321[0]));
  test_assert(frecip[1] == math::recip(fm321[1]));
  test_assert(frecip[2] == math::recip(fm321[2]));

  const auto irecip = math::recip(im321);
  test_assert(irecip[0] == math::recip(im321[0]));
  test_assert(irecip[1] == math::recip(im321[1]));
  test_assert(irecip[2] == math::recip(im321[2]));
}

TEST_CASE(sqrt) {
  const auto fsqrt = math::sqrt(fm321);
  test_assert(fsqrt[0] == math::sqrt(fm321[0]));
  test_assert(fsqrt[1] == math::sqrt(fm321[1]));
  test_assert(fsqrt[2] == math::sqrt(fm321[2]));

  const auto isqrt = math::sqrt(im321);
  test_assert(isqrt[0] == math::sqrt(im321[0]));
  test_assert(isqrt[1] == math::sqrt(im321[1]));
  test_assert(isqrt[2] == math::sqrt(im321[2]));
}

TEST_CASE(rsqrt) {
  const auto frsqrt = math::rsqrt(fm321);
  test_assert(frsqrt[0] == math::rsqrt(fm321[0]));
  test_assert(frsqrt[1] == math::rsqrt(fm321[1]));
  test_assert(frsqrt[2] == math::rsqrt(fm321[2]));

  const auto irsqrt = math::rsqrt(im321);
  test_assert(irsqrt[0] == math::rsqrt(im321[0]));
  test_assert(irsqrt[1] == math::rsqrt(im321[1]));
  test_assert(irsqrt[2] == math::rsqrt(im321[2]));
}

TEST_CASE(min) {
  const auto fmin = math::min(fm321, fm322);
  test_assert(fmin[0] == math::min(fm321[0], fm322[0]));
  test_assert(fmin[1] == math::min(fm321[1], fm322[1]));
  test_assert(fmin[2] == math::min(fm321[2], fm322[2]));

  const auto imin = math::min(im321, im322);
  test_assert(imin[0] == math::min(im321[0], im322[0]));
  test_assert(imin[1] == math::min(im321[1], im322[1]));
  test_assert(imin[2] == math::min(im321[2], im322[2]));
}

TEST_CASE(max) {
  const auto fmax = math::max(fm321, fm322);
  test_assert(fmax[0] == math::max(fm321[0], fm322[0]));
  test_assert(fmax[1] == math::max(fm321[1], fm322[1]));
  test_assert(fmax[2] == math::max(fm321[2], fm322[2]));

  const auto imax = math::max(im321, im322);
  test_assert(imax[0] == math::max(im321[0], im322[0]));
  test_assert(imax[1] == math::max(im321[1], im322[1]));
  test_assert(imax[2] == math::max(im321[2], im322[2]));
}

TEST_CASE(abs) {
  const auto fabs = math::abs(fm322);
  test_assert(fabs[0] == math::abs(fm322[0]));
  test_assert(fabs[1] == math::abs(fm322[1]));
  test_assert(fabs[2] == math::abs(fm322[2]));

  const auto iabs = math::abs(im322);
  test_assert(iabs[0] == math::abs(im322[0]));
  test_assert(iabs[1] == math::abs(im322[1]));
  test_assert(iabs[2] == math::abs(im322[2]));

  const auto uabs = math::abs(um322);
  test_assert(uabs[0] == math::abs(um322[0]));
  test_assert(uabs[1] == math::abs(um322[1]));
  test_assert(uabs[2] == math::abs(um322[2]));
}

TEST_CASE(comp_mult) {
  CONST_OR_CONSTEXPR auto m = math::comp_mult(fm321, dm322);
  test_assert(m[0] == fm321[0] * dm322[0]);
  test_assert(m[1] == fm321[1] * dm322[1]);
  test_assert(m[2] == fm321[2] * dm322[2]);
}

TEST_CASE(transpose) {
  CONST_OR_CONSTEXPR fmat4x3 m43 = {
    { 1.1f, 1.2f, 1.3f },
    { 2.1f, 2.2f, 2.3f },
    { 3.1f, 3.2f, 3.3f },
    { 4.1f, 4.2f, 4.3f },
  };
  CONST_OR_CONSTEXPR fmat3x3 m33(m43);
  CONST_OR_CONSTEXPR fmat2x3 m23(m43);

  CONST_OR_CONSTEXPR fmat3x4 m1 = math::transpose(m43);
  test_assert(m1[0] == m43.row(0));
  test_assert(m1[1] == m43.row(1));
  test_assert(m1[2] == m43.row(2));

  CONST_OR_CONSTEXPR fmat3x3 m2 = math::transpose(m33);
  test_assert(m2[0] == m33.row(0));
  test_assert(m2[1] == m33.row(1));
  test_assert(m2[2] == m33.row(2));

  CONST_OR_CONSTEXPR fmat3x2 m3 = math::transpose(m23);
  test_assert(m3[0] == m23.row(0));
  test_assert(m3[1] == m23.row(1));
  test_assert(m3[2] == m23.row(2));
}

TEST_CASE(select) {
  CONST_OR_CONSTEXPR mat3x2<bool> condition = {
    {  true, false },
    { false,  true },
    {  true,  true },
  };

  CONST_OR_CONSTEXPR fmat3x2 m1 = math::select(condition, fm321);
  test_assert(m1[0] == math::select(condition[0], fm321[0]));
  test_assert(m1[1] == math::select(condition[1], fm321[1]));
  test_assert(m1[2] == math::select(condition[2], fm321[2]));

  CONST_OR_CONSTEXPR fmat3x2 m2 = math::select(condition, fm321, fm322);
  test_assert(m2[0] == math::select(condition[0], fm321[0], fm322[0]));
  test_assert(m2[1] == math::select(condition[1], fm321[1], fm322[1]));
  test_assert(m2[2] == math::select(condition[2], fm321[2], fm322[2]));
}

TEST_CASE(less) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.3f, 1.2f },
    { 2.1f, 2.3f },
    { 3.3f, 3.2f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::less(m1, m2);
  test_assert(b[0] == bvec2(true, false));
  test_assert(b[1] == bvec2(false, true));
  test_assert(b[2] == bvec2(true, false));
}

TEST_CASE(less_equal) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.3f, 1.0f },
    { 2.0f, 2.2f },
    { 3.3f, 3.0f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::less_equal(m1, m2);
  test_assert(b[0] == bvec2(true, false));
  test_assert(b[1] == bvec2(false, true));
  test_assert(b[2] == bvec2(true, false));
}

TEST_CASE(greater) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.3f, 1.0f },
    { 2.0f, 2.2f },
    { 3.3f, 3.0f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::greater(m1, m2);
  test_assert(b[0] == bvec2(false, true));
  test_assert(b[1] == bvec2(true, false));
  test_assert(b[2] == bvec2(false, true));
}

TEST_CASE(greater_equal) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.3f, 1.2f },
    { 2.1f, 2.3f },
    { 3.3f, 3.2f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::greater_equal(m1, m2);
  test_assert(b[0] == bvec2(false, true));
  test_assert(b[1] == bvec2(true, false));
  test_assert(b[2] == bvec2(false, true));
}

TEST_CASE(equal) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.1f, 1.3f },
    { 2.0f, 2.2f },
    { 3.1f, 3.3f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::equal(m1, m2);
  test_assert(b[0] == bvec2(true, false));
  test_assert(b[1] == bvec2(false, true));
  test_assert(b[2] == bvec2(true, false));
}

TEST_CASE(not_equal) {
  CONST_OR_CONSTEXPR fmat3x2 m1 = {
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
  };
  CONST_OR_CONSTEXPR fmat3x2 m2 = {
    { 1.1f, 1.3f },
    { 2.0f, 2.2f },
    { 3.1f, 3.3f },
  };
  CONST_OR_CONSTEXPR mat3x2<bool> b = math::not_equal(m1, m2);
  test_assert(b[0] == bvec2(false, true));
  test_assert(b[1] == bvec2(true, false));
  test_assert(b[2] == bvec2(false, true));
}

}
