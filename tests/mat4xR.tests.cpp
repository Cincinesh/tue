//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/mat.hpp>
#include <mon/test_case.hpp>

#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
  using namespace tue;

  constexpr auto f1 = 1.1f;
  constexpr auto f2 = 2.2f;

  constexpr auto d2 = 2.2;

  constexpr auto i1 = 111;

  constexpr auto u2 = 2u;

  constexpr fmat4x2 fm421{
    { 1.1f, 1.2f },
    { 2.1f, 2.2f },
    { 3.1f, 3.2f },
    { 4.1f, 4.2f },
  };

  constexpr fmat4x2 fm422{
    { 2.2f, 2.4f },
    { 4.2f, 4.4f },
    { 6.2f, 6.4f },
    { 8.2f, 8.4f },
  };

  constexpr dmat4x2 dm421{
    { 1.1, 1.2 },
    { 2.1, 2.2 },
    { 3.1, 3.2 },
    { 4.1, 4.2 },
  };

  constexpr dmat4x2 dm422{
    { 2.2, 2.4 },
    { 4.2, 4.4 },
    { 6.2, 6.4 },
    { 8.2, 8.4 },
  };

  constexpr mat4x2<int> im421{
    { 111, 222 },
    { 333, 444 },
    { 555, 666 },
    { 777, 888 },
  };

  constexpr mat4x2<int> im422{
    { 2, 3 },
    { 4, 5 },
    { 6, 7 },
    { 8, 9 },
  };

  constexpr mat4x2<unsigned int> um422{
    { 2u, 3u },
    { 4u, 5u },
    { 6u, 7u },
    { 8u, 9u },
  };

  constexpr mat4x4<unsigned int> um442{
    {  2u,  3u,  4u,  5u },
    {  6u,  7u,  8u,  9u },
    { 10u, 11u, 12u, 13u },
    { 14u, 15u, 16u, 17u },
  };

  TEST_CASE(default_constructor)
  {
    fmat4x2 m;
    unused(m);
  }

  TEST_CASE(scalar_constructor)
  {
    constexpr fmat4x2 m1(1.1f);
    test_assert(m1[0] == fvec2(1.1f, 0.0f));
    test_assert(m1[1] == fvec2(0.0f, 1.1f));
    test_assert(m1[2] == fvec2(0.0f, 0.0f));
    test_assert(m1[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x3 m2(2.2f);
    test_assert(m2[0] == fvec3(2.2f, 0.0f, 0.0f));
    test_assert(m2[1] == fvec3(0.0f, 2.2f, 0.0f));
    test_assert(m2[2] == fvec3(0.0f, 0.0f, 2.2f));
    test_assert(m2[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x4 m3(3.3f);
    test_assert(m3[0] == fvec4(3.3f, 0.0f, 0.0f, 0.0f));
    test_assert(m3[1] == fvec4(0.0f, 3.3f, 0.0f, 0.0f));
    test_assert(m3[2] == fvec4(0.0f, 0.0f, 3.3f, 0.0f));
    test_assert(m3[3] == fvec4(0.0f, 0.0f, 0.0f, 3.3f));
  }

  TEST_CASE(column_constructor)
  {
    constexpr fmat4x2 m = {
      { 1.1f, 1.2f },
      { 2.1f, 2.2f },
      { 3.1f, 3.2f },
      { 4.1f, 4.2f },
    };
    test_assert(m[0] == fvec2(1.1f, 1.2f));
    test_assert(m[1] == fvec2(2.1f, 2.2f));
    test_assert(m[2] == fvec2(3.1f, 3.2f));
    test_assert(m[3] == fvec2(4.1f, 4.2f));
  }

  TEST_CASE(extend_and_truncate_constructors)
  {
    constexpr fmat4x4 m1({
      { 1.1f, 1.2f, 1.3f, 1.4f },
      { 2.1f, 2.2f, 2.3f, 2.4f },
      { 3.1f, 3.2f, 3.3f, 3.4f },
      { 4.1f, 4.2f, 4.3f, 4.4f },
    });

    constexpr fmat4x2 m2((fmat2x2(m1)));
    test_assert(m2[0] == fvec2(1.1f, 1.2f));
    test_assert(m2[1] == fvec2(2.1f, 2.2f));
    test_assert(m2[2] == fvec2(0.0f, 0.0f));
    test_assert(m2[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m3((fmat2x3(m1)));
    test_assert(m3[0] == fvec2(1.1f, 1.2f));
    test_assert(m3[1] == fvec2(2.1f, 2.2f));
    test_assert(m3[2] == fvec2(0.0f, 0.0f));
    test_assert(m3[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m4((fmat2x4(m1)));
    test_assert(m4[0] == fvec2(1.1f, 1.2f));
    test_assert(m4[1] == fvec2(2.1f, 2.2f));
    test_assert(m4[2] == fvec2(0.0f, 0.0f));
    test_assert(m4[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m5((fmat3x2(m1)));
    test_assert(m5[0] == fvec2(1.1f, 1.2f));
    test_assert(m5[1] == fvec2(2.1f, 2.2f));
    test_assert(m5[2] == fvec2(3.1f, 3.2f));
    test_assert(m5[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m6((fmat3x3(m1)));
    test_assert(m6[0] == fvec2(1.1f, 1.2f));
    test_assert(m6[1] == fvec2(2.1f, 2.2f));
    test_assert(m6[2] == fvec2(3.1f, 3.2f));
    test_assert(m6[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m7((fmat3x4(m1)));
    test_assert(m7[0] == fvec2(1.1f, 1.2f));
    test_assert(m7[1] == fvec2(2.1f, 2.2f));
    test_assert(m7[2] == fvec2(3.1f, 3.2f));
    test_assert(m7[3] == fvec2(0.0f, 0.0f));

    constexpr fmat4x2 m8((fmat4x2(m1)));
    test_assert(m8[0] == fvec2(1.1f, 1.2f));
    test_assert(m8[1] == fvec2(2.1f, 2.2f));
    test_assert(m8[2] == fvec2(3.1f, 3.2f));
    test_assert(m8[3] == fvec2(4.1f, 4.2f));

    constexpr fmat4x2 m9((fmat4x3(m1)));
    test_assert(m9[0] == fvec2(1.1f, 1.2f));
    test_assert(m9[1] == fvec2(2.1f, 2.2f));
    test_assert(m9[2] == fvec2(3.1f, 3.2f));
    test_assert(m9[3] == fvec2(4.1f, 4.2f));

    constexpr fmat4x2 m10((fmat4x4(m1)));
    test_assert(m10[0] == fvec2(1.1f, 1.2f));
    test_assert(m10[1] == fvec2(2.1f, 2.2f));
    test_assert(m10[2] == fvec2(3.1f, 3.2f));
    test_assert(m10[3] == fvec2(4.1f, 4.2f));

    constexpr fmat4x3 m11((fmat2x2(m1)));
    test_assert(m11[0] == fvec3(1.1f, 1.2f, 0.0f));
    test_assert(m11[1] == fvec3(2.1f, 2.2f, 0.0f));
    test_assert(m11[2] == fvec3(0.0f, 0.0f, 1.0f));
    test_assert(m11[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m12((fmat2x3(m1)));
    test_assert(m12[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m12[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m12[2] == fvec3(0.0f, 0.0f, 1.0f));
    test_assert(m12[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m13((fmat2x4(m1)));
    test_assert(m13[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m13[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m13[2] == fvec3(0.0f, 0.0f, 1.0f));
    test_assert(m13[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m14((fmat3x2(m1)));
    test_assert(m14[0] == fvec3(1.1f, 1.2f, 0.0f));
    test_assert(m14[1] == fvec3(2.1f, 2.2f, 0.0f));
    test_assert(m14[2] == fvec3(3.1f, 3.2f, 1.0f));
    test_assert(m14[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m15((fmat3x3(m1)));
    test_assert(m15[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m15[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m15[2] == fvec3(3.1f, 3.2f, 3.3f));
    test_assert(m15[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m16((fmat3x4(m1)));
    test_assert(m16[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m16[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m16[2] == fvec3(3.1f, 3.2f, 3.3f));
    test_assert(m16[3] == fvec3(0.0f, 0.0f, 0.0f));

    constexpr fmat4x3 m17((fmat4x2(m1)));
    test_assert(m17[0] == fvec3(1.1f, 1.2f, 0.0f));
    test_assert(m17[1] == fvec3(2.1f, 2.2f, 0.0f));
    test_assert(m17[2] == fvec3(3.1f, 3.2f, 1.0f));
    test_assert(m17[3] == fvec3(4.1f, 4.2f, 0.0f));

    constexpr fmat4x3 m18((fmat4x3(m1)));
    test_assert(m18[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m18[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m18[2] == fvec3(3.1f, 3.2f, 3.3f));
    test_assert(m18[3] == fvec3(4.1f, 4.2f, 4.3f));

    constexpr fmat4x3 m19((fmat4x4(m1)));
    test_assert(m19[0] == fvec3(1.1f, 1.2f, 1.3f));
    test_assert(m19[1] == fvec3(2.1f, 2.2f, 2.3f));
    test_assert(m19[2] == fvec3(3.1f, 3.2f, 3.3f));
    test_assert(m19[3] == fvec3(4.1f, 4.2f, 4.3f));

    constexpr fmat4x4 m20((fmat2x2(m1)));
    test_assert(m20[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
    test_assert(m20[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
    test_assert(m20[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
    test_assert(m20[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m21((fmat2x3(m1)));
    test_assert(m21[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
    test_assert(m21[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
    test_assert(m21[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
    test_assert(m21[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m22((fmat2x4(m1)));
    test_assert(m22[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
    test_assert(m22[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
    test_assert(m22[2] == fvec4(0.0f, 0.0f, 1.0f, 0.0f));
    test_assert(m22[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m23((fmat3x2(m1)));
    test_assert(m23[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
    test_assert(m23[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
    test_assert(m23[2] == fvec4(3.1f, 3.2f, 1.0f, 0.0f));
    test_assert(m23[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m24((fmat3x3(m1)));
    test_assert(m24[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
    test_assert(m24[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
    test_assert(m24[2] == fvec4(3.1f, 3.2f, 3.3f, 0.0f));
    test_assert(m24[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m25((fmat3x4(m1)));
    test_assert(m25[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
    test_assert(m25[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
    test_assert(m25[2] == fvec4(3.1f, 3.2f, 3.3f, 3.4f));
    test_assert(m25[3] == fvec4(0.0f, 0.0f, 0.0f, 1.0f));

    constexpr fmat4x4 m26((fmat4x2(m1)));
    test_assert(m26[0] == fvec4(1.1f, 1.2f, 0.0f, 0.0f));
    test_assert(m26[1] == fvec4(2.1f, 2.2f, 0.0f, 0.0f));
    test_assert(m26[2] == fvec4(3.1f, 3.2f, 1.0f, 0.0f));
    test_assert(m26[3] == fvec4(4.1f, 4.2f, 0.0f, 1.0f));

    constexpr fmat4x4 m27((fmat4x3(m1)));
    test_assert(m27[0] == fvec4(1.1f, 1.2f, 1.3f, 0.0f));
    test_assert(m27[1] == fvec4(2.1f, 2.2f, 2.3f, 0.0f));
    test_assert(m27[2] == fvec4(3.1f, 3.2f, 3.3f, 0.0f));
    test_assert(m27[3] == fvec4(4.1f, 4.2f, 4.3f, 1.0f));

    constexpr fmat4x4 m28((fmat4x4(m1)));
    test_assert(m28[0] == fvec4(1.1f, 1.2f, 1.3f, 1.4f));
    test_assert(m28[1] == fvec4(2.1f, 2.2f, 2.3f, 2.4f));
    test_assert(m28[2] == fvec4(3.1f, 3.2f, 3.3f, 3.4f));
    test_assert(m28[3] == fvec4(4.1f, 4.2f, 4.3f, 4.4f));
  }

  TEST_CASE(explicit_conversion_constructor)
  {
    constexpr fmat4x2 m(dm421);
    test_assert(m[0] == fvec2(dm421[0]));
    test_assert(m[1] == fvec2(dm421[1]));
    test_assert(m[2] == fvec2(dm421[2]));
    test_assert(m[3] == fvec2(dm421[3]));
  }

  TEST_CASE(implicit_conversion_operator)
  {
    CONST_OR_CONSTEXPR dmat4x2 m = fm421;
    test_assert(m[0] == dvec2(fm421[0]));
    test_assert(m[1] == dvec2(fm421[1]));
    test_assert(m[2] == dvec2(fm421[2]));
    test_assert(m[3] == dvec2(fm421[3]));
  }

  TEST_CASE(identity)
  {
    CONST_OR_CONSTEXPR auto m1 = fmat4x2::identity();
    CONST_OR_CONSTEXPR auto m2 = fmat4x3::identity();
    CONST_OR_CONSTEXPR auto m3 = fmat4x4::identity();
    test_assert(m1 == fmat4x2(1.0f));
    test_assert(m2 == fmat4x3(1.0f));
    test_assert(m3 == fmat4x4(1.0f));
  }

  TEST_CASE(zero)
  {
    CONST_OR_CONSTEXPR auto m1 = fmat4x2::zero();
    CONST_OR_CONSTEXPR auto m2 = fmat4x3::zero();
    CONST_OR_CONSTEXPR auto m3 = fmat4x4::zero();
    test_assert(m1 == fmat4x2(0.0f));
    test_assert(m2 == fmat4x3(0.0f));
    test_assert(m3 == fmat4x4(0.0f));
  }

  TEST_CASE(column)
  {
    CONST_OR_CONSTEXPR fvec2 column0 = fm421.column(0);
    CONST_OR_CONSTEXPR fvec2 column1 = fm421.column(1);
    CONST_OR_CONSTEXPR fvec2 column2 = fm421.column(2);
    CONST_OR_CONSTEXPR fvec2 column3 = fm421.column(3);
    test_assert(column0 == fm421[0]);
    test_assert(column1 == fm421[1]);
    test_assert(column2 == fm421[2]);
    test_assert(column3 == fm421[3]);
  }

  TEST_CASE(set_column)
  {
    fmat4x2 m;
    m.set_column(0, fvec2(1.1f, 1.2f));
    m.set_column(1, fvec2(2.1f, 2.2f));
    m.set_column(2, fvec2(3.1f, 3.2f));
    m.set_column(3, fvec2(4.1f, 4.2f));
    test_assert(m[0] == fvec2(1.1f, 1.2f));
    test_assert(m[1] == fvec2(2.1f, 2.2f));
    test_assert(m[2] == fvec2(3.1f, 3.2f));
    test_assert(m[3] == fvec2(4.1f, 4.2f));
  }

  TEST_CASE(row)
  {
    CONST_OR_CONSTEXPR fvec4 row0 = fm421.row(0);
    CONST_OR_CONSTEXPR fvec4 row1 = fm421.row(1);
    test_assert(row0 == fvec4(fm421[0][0], fm421[1][0], fm421[2][0], fm421[3][0]));
    test_assert(row1 == fvec4(fm421[0][1], fm421[1][1], fm421[2][1], fm421[3][1]));
  }

  TEST_CASE(set_row)
  {
    fmat4x2 m;
    m.set_row(0, fvec4(1.1f, 2.1f, 3.1f, 4.1f));
    m.set_row(1, fvec4(1.2f, 2.2f, 3.2f, 4.2f));
    test_assert(m[0] == fvec2(1.1f, 1.2f));
    test_assert(m[1] == fvec2(2.1f, 2.2f));
    test_assert(m[2] == fvec2(3.1f, 3.2f));
    test_assert(m[3] == fvec2(4.1f, 4.2f));
  }

  TEST_CASE(subscript_operator)
  {
    constexpr fmat4x2 cem = {
      { 1.1f, 1.2f },
      { 2.1f, 2.2f },
      { 3.1f, 3.2f },
      { 4.1f, 4.2f },
    };
    CONST_OR_CONSTEXPR fvec2 cem0 = cem[0];
    CONST_OR_CONSTEXPR fvec2 cem1 = cem[1];
    CONST_OR_CONSTEXPR fvec2 cem2 = cem[2];
    CONST_OR_CONSTEXPR fvec2 cem3 = cem[3];
    test_assert(cem0 == fvec2(1.1f, 1.2f));
    test_assert(cem1 == fvec2(2.1f, 2.2f));
    test_assert(cem2 == fvec2(3.1f, 3.2f));
    test_assert(cem3 == fvec2(4.1f, 4.2f));

    fmat4x2 m = cem;
    fvec2& m0 = m[0];
    fvec2& m1 = m[1];
    fvec2& m2 = m[2];
    fvec2& m3 = m[3];
    test_assert(static_cast<void*>(&m0) == static_cast<void*>(&m));
    test_assert(&m1 == &m0 + 1);
    test_assert(&m2 == &m0 + 2);
    test_assert(&m3 == &m0 + 3);

    const fmat4x2& cm = m;
    const fvec2& cm0 = cm[0];
    const fvec2& cm1 = cm[1];
    const fvec2& cm2 = cm[2];
    const fvec2& cm3 = cm[3];
    test_assert(&cm0 == &m0);
    test_assert(&cm1 == &m1);
    test_assert(&cm2 == &m2);
    test_assert(&cm3 == &m3);
  }

  TEST_CASE(pre_increment_operator)
  {
    fmat4x2 m = fm421;
    test_assert(&(++m) == &m);
    test_assert(m == fm421 + 1);
  }

  TEST_CASE(pre_decrement_operator)
  {
    fmat4x2 m = fm421;
    test_assert(&(--m) == &m);
    test_assert(m == fm421 - 1);
  }

  TEST_CASE(post_increment_operator)
  {
    fmat4x2 m = fm421;
    test_assert(m++ == fm421);
    test_assert(m == fm421 + 1);
  }

  TEST_CASE(post_decrement_operator)
  {
    fmat4x2 m = fm421;
    test_assert(m-- == fm421);
    test_assert(m == fm421 - 1);
  }

  TEST_CASE(addition_assignment_operator)
  {
    fmat4x2 m1 = fm421;
    test_assert(&(m1 += u2) == &m1);
    test_assert(m1 == fm421 + u2);

    fmat4x2 m2 = fm421;
    test_assert(&(m2 += um422) == &m2);
    test_assert(m2 == fm421 + um422);
  }

  TEST_CASE(subtraction_assignment_operator)
  {
    fmat4x2 m1 = fm421;
    test_assert(&(m1 -= u2) == &m1);
    test_assert(m1 == fm421 - u2);

    fmat4x2 m2 = fm421;
    test_assert(&(m2 -= um422) == &m2);
    test_assert(m2 == fm421 - um422);
  }

  TEST_CASE(multiplication_assignment_operator)
  {
    fmat4x2 m1 = fm421;
    test_assert(&(m1 *= u2) == &m1);
    test_assert(m1 == fm421 * u2);

    fmat4x2 m2 = fm421;
    test_assert(&(m2 *= um442) == &m2);
    test_assert(m2 == fm421 * um442);
  }

  TEST_CASE(division_assignment_operator)
  {
    fmat4x2 m1 = fm421;
    test_assert(&(m1 /= u2) == &m1);
    test_assert(m1 == fm421 / u2);

    fmat4x2 m2 = fm421;
    test_assert(&(m2 /= um422) == &m2);
    test_assert(m2 == fm421 / um422);
  }

  TEST_CASE(modulo_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 %= u2) == &m1);
    test_assert(m1 == mat4x2<int>(im421 % u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 %= um422) == &m2);
    test_assert(m2 == mat4x2<int>(im421 % um422));
  }

  TEST_CASE(bitwise_and_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 &= u2) == &m1);
    test_assert(m1 == mat4x2<int>(im421 & u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 &= um422) == &m2);
    test_assert(m2 == mat4x2<int>(im421 & um422));
  }

  TEST_CASE(bitwise_or_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 |= u2) == &m1);
    test_assert(m1 == mat4x2<int>(im421 | u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 |= um422) == &m2);
    test_assert(m2 == mat4x2<int>(im421 | um422));
  }

  TEST_CASE(bitwise_xor_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 ^= u2) == &m1);
    test_assert(m1 == mat4x2<int>(im421 ^ u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 ^= um422) == &m2);
    test_assert(m2 == mat4x2<int>(im421 ^ um422));
  }

  TEST_CASE(bitwise_shift_left_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 <<= u2) == &m1);
    test_assert(m1 == (im421 << u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 <<= um422) == &m2);
    test_assert(m2 == (im421 << um422));
  }

  TEST_CASE(bitwise_shift_right_assignment_operator)
  {
    mat4x2<int> m1 = im421;
    test_assert(&(m1 >>= u2) == &m1);
    test_assert(m1 == (im421 >> u2));

    mat4x2<int> m2 = im421;
    test_assert(&(m2 >>= um422) == &m2);
    test_assert(m2 == (im421 >> um422));
  }

  TEST_CASE(unary_plus_operator)
  {
    CONST_OR_CONSTEXPR auto m = +fm421;
    test_assert(m[0] == +fm421[0]);
    test_assert(m[1] == +fm421[1]);
    test_assert(m[2] == +fm421[2]);
    test_assert(m[3] == +fm421[3]);
  }

  TEST_CASE(unary_minus_operator)
  {
    CONST_OR_CONSTEXPR auto m = -fm421;
    test_assert(m[0] == -fm421[0]);
    test_assert(m[1] == -fm421[1]);
    test_assert(m[2] == -fm421[2]);
    test_assert(m[3] == -fm421[3]);
  }

  TEST_CASE(bitwise_not_operator)
  {
    CONST_OR_CONSTEXPR auto m = ~im421;
    test_assert(m[0] == ~im421[0]);
    test_assert(m[1] == ~im421[1]);
    test_assert(m[2] == ~im421[2]);
    test_assert(m[3] == ~im421[3]);
  }

  TEST_CASE(addition_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = f1 + dm422;
    test_assert(m1[0] == f1 + dm422[0]);
    test_assert(m1[1] == f1 + dm422[1]);
    test_assert(m1[2] == f1 + dm422[2]);
    test_assert(m1[3] == f1 + dm422[3]);

    CONST_OR_CONSTEXPR auto m2 = fm421 + d2;
    test_assert(m2[0] == fm421[0] + d2);
    test_assert(m2[1] == fm421[1] + d2);
    test_assert(m2[2] == fm421[2] + d2);
    test_assert(m2[3] == fm421[3] + d2);

    CONST_OR_CONSTEXPR auto m3 = fm421 + dm422;
    test_assert(m3[0] == fm421[0] + dm422[0]);
    test_assert(m3[1] == fm421[1] + dm422[1]);
    test_assert(m3[2] == fm421[2] + dm422[2]);
    test_assert(m3[3] == fm421[3] + dm422[3]);
  }

  TEST_CASE(subtraction_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = f1 - dm422;
    test_assert(m1[0] == f1 - dm422[0]);
    test_assert(m1[1] == f1 - dm422[1]);
    test_assert(m1[2] == f1 - dm422[2]);
    test_assert(m1[3] == f1 - dm422[3]);

    CONST_OR_CONSTEXPR auto m2 = fm421 - d2;
    test_assert(m2[0] == fm421[0] - d2);
    test_assert(m2[1] == fm421[1] - d2);
    test_assert(m2[2] == fm421[2] - d2);
    test_assert(m2[3] == fm421[3] - d2);

    CONST_OR_CONSTEXPR auto m3 = fm421 - dm422;
    test_assert(m3[0] == fm421[0] - dm422[0]);
    test_assert(m3[1] == fm421[1] - dm422[1]);
    test_assert(m3[2] == fm421[2] - dm422[2]);
    test_assert(m3[3] == fm421[3] - dm422[3]);
  }

  TEST_CASE(multiplication_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = f1 * dm422;
    test_assert(m1[0] == f1 * dm422[0]);
    test_assert(m1[1] == f1 * dm422[1]);
    test_assert(m1[2] == f1 * dm422[2]);
    test_assert(m1[3] == f1 * dm422[3]);

    CONST_OR_CONSTEXPR auto m2 = fm421 * d2;
    test_assert(m2[0] == fm421[0] * d2);
    test_assert(m2[1] == fm421[1] * d2);
    test_assert(m2[2] == fm421[2] * d2);
    test_assert(m2[3] == fm421[3] * d2);
  }

  TEST_CASE(division_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = f1 / dm422;
    test_assert(m1[0] == f1 / dm422[0]);
    test_assert(m1[1] == f1 / dm422[1]);
    test_assert(m1[2] == f1 / dm422[2]);
    test_assert(m1[3] == f1 / dm422[3]);

    CONST_OR_CONSTEXPR auto m2 = fm421 / d2;
    test_assert(m2[0] == fm421[0] / d2);
    test_assert(m2[1] == fm421[1] / d2);
    test_assert(m2[2] == fm421[2] / d2);
    test_assert(m2[3] == fm421[3] / d2);

    CONST_OR_CONSTEXPR auto m3 = fm421 / dm422;
    test_assert(m3[0] == fm421[0] / dm422[0]);
    test_assert(m3[1] == fm421[1] / dm422[1]);
    test_assert(m3[2] == fm421[2] / dm422[2]);
    test_assert(m3[3] == fm421[3] / dm422[3]);
  }

  TEST_CASE(modulo_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 % um422;
    test_assert(m1[0] == i1 % um422[0]);
    test_assert(m1[1] == i1 % um422[1]);
    test_assert(m1[2] == i1 % um422[2]);
    test_assert(m1[3] == i1 % um422[3]);

    CONST_OR_CONSTEXPR auto m2 = im421 % u2;
    test_assert(m2[0] == im421[0] % u2);
    test_assert(m2[1] == im421[1] % u2);
    test_assert(m2[2] == im421[2] % u2);
    test_assert(m2[3] == im421[3] % u2);

    CONST_OR_CONSTEXPR auto m3 = im421 % um422;
    test_assert(m3[0] == im421[0] % um422[0]);
    test_assert(m3[1] == im421[1] % um422[1]);
    test_assert(m3[2] == im421[2] % um422[2]);
    test_assert(m3[3] == im421[3] % um422[3]);
  }

  TEST_CASE(bitwise_and_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 & um422;
    test_assert(m1[0] == (i1 & um422[0]));
    test_assert(m1[1] == (i1 & um422[1]));
    test_assert(m1[2] == (i1 & um422[2]));
    test_assert(m1[3] == (i1 & um422[3]));

    CONST_OR_CONSTEXPR auto m2 = im421 & u2;
    test_assert(m2[0] == (im421[0] & u2));
    test_assert(m2[1] == (im421[1] & u2));
    test_assert(m2[2] == (im421[2] & u2));
    test_assert(m2[3] == (im421[3] & u2));

    CONST_OR_CONSTEXPR auto m3 = im421 & um422;
    test_assert(m3[0] == (im421[0] & um422[0]));
    test_assert(m3[1] == (im421[1] & um422[1]));
    test_assert(m3[2] == (im421[2] & um422[2]));
    test_assert(m3[3] == (im421[3] & um422[3]));
  }

  TEST_CASE(bitwise_or_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 | um422;
    test_assert(m1[0] == (i1 | um422[0]));
    test_assert(m1[1] == (i1 | um422[1]));
    test_assert(m1[2] == (i1 | um422[2]));
    test_assert(m1[3] == (i1 | um422[3]));

    CONST_OR_CONSTEXPR auto m2 = im421 | u2;
    test_assert(m2[0] == (im421[0] | u2));
    test_assert(m2[1] == (im421[1] | u2));
    test_assert(m2[2] == (im421[2] | u2));
    test_assert(m2[3] == (im421[3] | u2));

    CONST_OR_CONSTEXPR auto m3 = im421 | um422;
    test_assert(m3[0] == (im421[0] | um422[0]));
    test_assert(m3[1] == (im421[1] | um422[1]));
    test_assert(m3[2] == (im421[2] | um422[2]));
    test_assert(m3[3] == (im421[3] | um422[3]));
  }

  TEST_CASE(bitwise_xor_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 ^ um422;
    test_assert(m1[0] == (i1 ^ um422[0]));
    test_assert(m1[1] == (i1 ^ um422[1]));
    test_assert(m1[2] == (i1 ^ um422[2]));
    test_assert(m1[3] == (i1 ^ um422[3]));

    CONST_OR_CONSTEXPR auto m2 = im421 ^ u2;
    test_assert(m2[0] == (im421[0] ^ u2));
    test_assert(m2[1] == (im421[1] ^ u2));
    test_assert(m2[2] == (im421[2] ^ u2));
    test_assert(m2[3] == (im421[3] ^ u2));

    CONST_OR_CONSTEXPR auto m3 = im421 ^ um422;
    test_assert(m3[0] == (im421[0] ^ um422[0]));
    test_assert(m3[1] == (im421[1] ^ um422[1]));
    test_assert(m3[2] == (im421[2] ^ um422[2]));
    test_assert(m3[3] == (im421[3] ^ um422[3]));
  }

  TEST_CASE(bitwise_shift_left_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 << um422;
    test_assert(m1[0] == (i1 << um422[0]));
    test_assert(m1[1] == (i1 << um422[1]));
    test_assert(m1[2] == (i1 << um422[2]));
    test_assert(m1[3] == (i1 << um422[3]));

    CONST_OR_CONSTEXPR auto m2 = im421 << u2;
    test_assert(m2[0] == (im421[0] << u2));
    test_assert(m2[1] == (im421[1] << u2));
    test_assert(m2[2] == (im421[2] << u2));
    test_assert(m2[3] == (im421[3] << u2));

    CONST_OR_CONSTEXPR auto m3 = im421 << um422;
    test_assert(m3[0] == (im421[0] << um422[0]));
    test_assert(m3[1] == (im421[1] << um422[1]));
    test_assert(m3[2] == (im421[2] << um422[2]));
    test_assert(m3[3] == (im421[3] << um422[3]));
  }

  TEST_CASE(bitwise_shift_right_operator)
  {
    CONST_OR_CONSTEXPR auto m1 = i1 >> um422;
    test_assert(m1[0] == (i1 >> um422[0]));
    test_assert(m1[1] == (i1 >> um422[1]));
    test_assert(m1[2] == (i1 >> um422[2]));
    test_assert(m1[3] == (i1 >> um422[3]));

    CONST_OR_CONSTEXPR auto m2 = im421 >> u2;
    test_assert(m2[0] == (im421[0] >> u2));
    test_assert(m2[1] == (im421[1] >> u2));
    test_assert(m2[2] == (im421[2] >> u2));
    test_assert(m2[3] == (im421[3] >> u2));

    CONST_OR_CONSTEXPR auto m3 = im421 >> um422;
    test_assert(m3[0] == (im421[0] >> um422[0]));
    test_assert(m3[1] == (im421[1] >> um422[1]));
    test_assert(m3[2] == (im421[2] >> um422[2]));
    test_assert(m3[3] == (im421[3] >> um422[3]));
  }

  TEST_CASE(equality_operator)
  {
    constexpr fmat4x2 m1 = {
      fvec2(1.0f),
      fvec2(2.0f),
      fvec2(3.0f),
      fvec2(4.0f),
    };
    constexpr ivec2 iv0(0);
    constexpr ivec2 iv1(1);
    constexpr ivec2 iv2(2);
    constexpr ivec2 iv3(3);
    constexpr ivec2 iv4(4);
    constexpr mat4x2<int> m2(iv1, iv2, iv3, iv4);
    constexpr mat4x2<int> m3(iv0, iv2, iv3, iv4);
    constexpr mat4x2<int> m4(iv1, iv0, iv3, iv4);
    constexpr mat4x2<int> m5(iv1, iv2, iv0, iv4);
    constexpr mat4x2<int> m6(iv1, iv2, iv3, iv0);
    CONST_OR_CONSTEXPR bool result1 = (m1 == m2);
    CONST_OR_CONSTEXPR bool result2 = (m1 == m3);
    CONST_OR_CONSTEXPR bool result3 = (m1 == m4);
    CONST_OR_CONSTEXPR bool result4 = (m1 == m5);
    CONST_OR_CONSTEXPR bool result5 = (m1 == m6);
    test_assert(result1 == true);
    test_assert(result2 == false);
    test_assert(result3 == false);
    test_assert(result4 == false);
    test_assert(result5 == false);
  }

  TEST_CASE(inequality_operator)
  {
    constexpr fmat4x2 m1 = {
      fvec2(1.0f),
      fvec2(2.0f),
      fvec2(3.0f),
      fvec2(4.0f),
    };
    constexpr ivec2 iv0(0);
    constexpr ivec2 iv1(1);
    constexpr ivec2 iv2(2);
    constexpr ivec2 iv3(3);
    constexpr ivec2 iv4(4);
    constexpr mat4x2<int> m2(iv1, iv2, iv3, iv4);
    constexpr mat4x2<int> m3(iv0, iv2, iv3, iv4);
    constexpr mat4x2<int> m4(iv1, iv0, iv3, iv4);
    constexpr mat4x2<int> m5(iv1, iv2, iv0, iv4);
    constexpr mat4x2<int> m6(iv1, iv2, iv3, iv0);
    CONST_OR_CONSTEXPR bool result1 = (m1 != m2);
    CONST_OR_CONSTEXPR bool result2 = (m1 != m3);
    CONST_OR_CONSTEXPR bool result3 = (m1 != m4);
    CONST_OR_CONSTEXPR bool result4 = (m1 != m5);
    CONST_OR_CONSTEXPR bool result5 = (m1 != m6);
    test_assert(result1 == false);
    test_assert(result2 == true);
    test_assert(result3 == true);
    test_assert(result4 == true);
    test_assert(result5 == true);
  }

  TEST_CASE(sin)
  {
    const auto fsin = math::sin(fm421);
    test_assert(fsin[0] == math::sin(fm421[0]));
    test_assert(fsin[1] == math::sin(fm421[1]));
    test_assert(fsin[2] == math::sin(fm421[2]));
    test_assert(fsin[3] == math::sin(fm421[3]));

    const auto isin = math::sin(im421);
    test_assert(isin[0] == math::sin(im421[0]));
    test_assert(isin[1] == math::sin(im421[1]));
    test_assert(isin[2] == math::sin(im421[2]));
    test_assert(isin[3] == math::sin(im421[3]));
  }

  TEST_CASE(cos)
  {
    const auto fcos = math::cos(fm421);
    test_assert(fcos[0] == math::cos(fm421[0]));
    test_assert(fcos[1] == math::cos(fm421[1]));
    test_assert(fcos[2] == math::cos(fm421[2]));
    test_assert(fcos[3] == math::cos(fm421[3]));

    const auto icos = math::cos(im421);
    test_assert(icos[0] == math::cos(im421[0]));
    test_assert(icos[1] == math::cos(im421[1]));
    test_assert(icos[2] == math::cos(im421[2]));
    test_assert(icos[3] == math::cos(im421[3]));
  }

  TEST_CASE(sincos)
  {
    fmat4x2 fsin, fcos;
    math::sincos(fm421, fsin, fcos);
    test_assert(fsin == math::sin(fm421));
    test_assert(fcos == math::cos(fm421));

    dmat4x2 isin, icos;
    math::sincos(im421, isin, icos);
    test_assert(isin == math::sin(im421));
    test_assert(icos == math::cos(im421));
  }

  TEST_CASE(exp)
  {
    const auto fexp = math::exp(fm421);
    test_assert(fexp[0] == math::exp(fm421[0]));
    test_assert(fexp[1] == math::exp(fm421[1]));
    test_assert(fexp[2] == math::exp(fm421[2]));
    test_assert(fexp[3] == math::exp(fm421[3]));

    const auto iexp = math::exp(im421);
    test_assert(iexp[0] == math::exp(im421[0]));
    test_assert(iexp[1] == math::exp(im421[1]));
    test_assert(iexp[2] == math::exp(im421[2]));
    test_assert(iexp[3] == math::exp(im421[3]));
  }

  TEST_CASE(log)
  {
    const auto flog = math::log(fm421);
    test_assert(flog[0] == math::log(fm421[0]));
    test_assert(flog[1] == math::log(fm421[1]));
    test_assert(flog[2] == math::log(fm421[2]));
    test_assert(flog[3] == math::log(fm421[3]));

    const auto ilog = math::log(im421);
    test_assert(ilog[0] == math::log(im421[0]));
    test_assert(ilog[1] == math::log(im421[1]));
    test_assert(ilog[2] == math::log(im421[2]));
    test_assert(ilog[3] == math::log(im421[3]));
  }

  TEST_CASE(pow)
  {
    const auto fpow1 = math::pow(fm421, f2);
    test_assert(fpow1[0] == math::pow(fm421[0], f2));
    test_assert(fpow1[1] == math::pow(fm421[1], f2));
    test_assert(fpow1[2] == math::pow(fm421[2], f2));
    test_assert(fpow1[3] == math::pow(fm421[3], f2));

    const auto ipow1 = math::pow(im421, f2);
    test_assert(ipow1[0] == math::pow(im421[0], f2));
    test_assert(ipow1[1] == math::pow(im421[1], f2));
    test_assert(ipow1[2] == math::pow(im421[2], f2));
    test_assert(ipow1[3] == math::pow(im421[3], f2));

    const auto fpow2 = math::pow(fm421, fm422);
    test_assert(fpow2[0] == math::pow(fm421[0], fm422[0]));
    test_assert(fpow2[1] == math::pow(fm421[1], fm422[1]));
    test_assert(fpow2[2] == math::pow(fm421[2], fm422[2]));
    test_assert(fpow2[3] == math::pow(fm421[3], fm422[3]));

    const auto ipow2 = math::pow(im421, fm422);
    test_assert(ipow2[0] == math::pow(im421[0], fm422[0]));
    test_assert(ipow2[1] == math::pow(im421[1], fm422[1]));
    test_assert(ipow2[2] == math::pow(im421[2], fm422[2]));
    test_assert(ipow2[3] == math::pow(im421[3], fm422[3]));
  }

  TEST_CASE(recip)
  {
    const auto frecip = math::recip(fm421);
    test_assert(frecip[0] == math::recip(fm421[0]));
    test_assert(frecip[1] == math::recip(fm421[1]));
    test_assert(frecip[2] == math::recip(fm421[2]));
    test_assert(frecip[3] == math::recip(fm421[3]));

    const auto irecip = math::recip(im421);
    test_assert(irecip[0] == math::recip(im421[0]));
    test_assert(irecip[1] == math::recip(im421[1]));
    test_assert(irecip[2] == math::recip(im421[2]));
    test_assert(irecip[3] == math::recip(im421[3]));
  }

  TEST_CASE(sqrt)
  {
    const auto fsqrt = math::sqrt(fm421);
    test_assert(fsqrt[0] == math::sqrt(fm421[0]));
    test_assert(fsqrt[1] == math::sqrt(fm421[1]));
    test_assert(fsqrt[2] == math::sqrt(fm421[2]));
    test_assert(fsqrt[3] == math::sqrt(fm421[3]));

    const auto isqrt = math::sqrt(im421);
    test_assert(isqrt[0] == math::sqrt(im421[0]));
    test_assert(isqrt[1] == math::sqrt(im421[1]));
    test_assert(isqrt[2] == math::sqrt(im421[2]));
    test_assert(isqrt[3] == math::sqrt(im421[3]));
  }

  TEST_CASE(rsqrt)
  {
    const auto frsqrt = math::rsqrt(fm421);
    test_assert(frsqrt[0] == math::rsqrt(fm421[0]));
    test_assert(frsqrt[1] == math::rsqrt(fm421[1]));
    test_assert(frsqrt[2] == math::rsqrt(fm421[2]));
    test_assert(frsqrt[3] == math::rsqrt(fm421[3]));

    const auto irsqrt = math::rsqrt(im421);
    test_assert(irsqrt[0] == math::rsqrt(im421[0]));
    test_assert(irsqrt[1] == math::rsqrt(im421[1]));
    test_assert(irsqrt[2] == math::rsqrt(im421[2]));
    test_assert(irsqrt[3] == math::rsqrt(im421[3]));
  }

  TEST_CASE(min)
  {
    const auto fmin = math::min(fm421, fm422);
    test_assert(fmin[0] == math::min(fm421[0], fm422[0]));
    test_assert(fmin[1] == math::min(fm421[1], fm422[1]));
    test_assert(fmin[2] == math::min(fm421[2], fm422[2]));
    test_assert(fmin[3] == math::min(fm421[3], fm422[3]));

    const auto imin = math::min(im421, im422);
    test_assert(imin[0] == math::min(im421[0], im422[0]));
    test_assert(imin[1] == math::min(im421[1], im422[1]));
    test_assert(imin[2] == math::min(im421[2], im422[2]));
    test_assert(imin[3] == math::min(im421[3], im422[3]));
  }

  TEST_CASE(max)
  {
    const auto fmax = math::max(fm421, fm422);
    test_assert(fmax[0] == math::max(fm421[0], fm422[0]));
    test_assert(fmax[1] == math::max(fm421[1], fm422[1]));
    test_assert(fmax[2] == math::max(fm421[2], fm422[2]));
    test_assert(fmax[3] == math::max(fm421[3], fm422[3]));

    const auto imax = math::max(im421, im422);
    test_assert(imax[0] == math::max(im421[0], im422[0]));
    test_assert(imax[1] == math::max(im421[1], im422[1]));
    test_assert(imax[2] == math::max(im421[2], im422[2]));
    test_assert(imax[3] == math::max(im421[3], im422[3]));
  }

  TEST_CASE(abs)
  {
    const auto fabs = math::abs(fm422);
    test_assert(fabs[0] == math::abs(fm422[0]));
    test_assert(fabs[1] == math::abs(fm422[1]));
    test_assert(fabs[2] == math::abs(fm422[2]));
    test_assert(fabs[3] == math::abs(fm422[3]));

    const auto iabs = math::abs(im422);
    test_assert(iabs[0] == math::abs(im422[0]));
    test_assert(iabs[1] == math::abs(im422[1]));
    test_assert(iabs[2] == math::abs(im422[2]));
    test_assert(iabs[3] == math::abs(im422[3]));

    const auto uabs = math::abs(um422);
    test_assert(uabs[0] == math::abs(um422[0]));
    test_assert(uabs[1] == math::abs(um422[1]));
    test_assert(uabs[2] == math::abs(um422[2]));
    test_assert(uabs[3] == math::abs(um422[3]));
  }

  TEST_CASE(compmult)
  {
    CONST_OR_CONSTEXPR auto m = math::compmult(fm421, dm422);
    test_assert(m[0] == fm421[0] * dm422[0]);
    test_assert(m[1] == fm421[1] * dm422[1]);
    test_assert(m[2] == fm421[2] * dm422[2]);
    test_assert(m[3] == fm421[3] * dm422[3]);
  }

  TEST_CASE(transpose)
  {
    constexpr fmat4x4 m44 = {
      { 1.1f, 1.2f, 1.3f, 1.4f },
      { 2.1f, 2.2f, 2.3f, 2.4f },
      { 3.1f, 3.2f, 3.3f, 3.4f },
      { 4.1f, 4.2f, 4.3f, 4.4f },
    };
    constexpr fmat3x4 m34(m44);
    constexpr fmat2x4 m24(m44);

    CONST_OR_CONSTEXPR fmat4x4 m1 = math::transpose(m44);
    test_assert(m1[0] == m44.row(0));
    test_assert(m1[1] == m44.row(1));
    test_assert(m1[2] == m44.row(2));
    test_assert(m1[3] == m44.row(3));

    CONST_OR_CONSTEXPR fmat4x3 m2 = math::transpose(m34);
    test_assert(m2[0] == m34.row(0));
    test_assert(m2[1] == m34.row(1));
    test_assert(m2[2] == m34.row(2));
    test_assert(m2[3] == m34.row(3));

    CONST_OR_CONSTEXPR fmat4x2 m3 = math::transpose(m24);
    test_assert(m3[0] == m24.row(0));
    test_assert(m3[1] == m24.row(1));
    test_assert(m3[2] == m24.row(2));
    test_assert(m3[3] == m24.row(3));
  }
}
