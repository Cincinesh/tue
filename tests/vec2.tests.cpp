//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/vec.hpp>
#include "tue.tests.hpp"

#include <type_traits>
#include <tue/mat.hpp>
#include <tue/math.hpp>
#include <tue/sized_bool.hpp>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(vec2<short>) == sizeof(short[2]));
        test_assert(sizeof(fvec2) == sizeof(float[2]));
        test_assert(sizeof(dvec2) == sizeof(double[2]));
        test_assert(sizeof(ivec2) == sizeof(int[2]));
        test_assert(sizeof(uvec2) == sizeof(unsigned int[2]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(vec2<short>) == alignof(short[2]));
        test_assert(alignof(fvec2) == alignof(float[2]));
        test_assert(alignof(dvec2) <= alignof(double[2]));
        test_assert(alignof(ivec2) == alignof(int[2]));
        test_assert(alignof(uvec2) == alignof(unsigned int[2]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename vec2<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fvec2::component_type, float>::value));
        test_assert((std::is_same<
            typename dvec2::component_type, double>::value));
        test_assert((std::is_same<
            typename ivec2::component_type, int>::value));
        test_assert((std::is_same<
            typename uvec2::component_type, unsigned int>::value));
    }

    TEST_CASE(component_count)
    {
        constexpr auto v2s = vec2<short>::component_count;
        constexpr auto fv2 = fvec2::component_count;
        constexpr auto dv2 = dvec2::component_count;
        constexpr auto iv2 = ivec2::component_count;
        constexpr auto uv2 = uvec2::component_count;
        test_assert(v2s == 2);
        test_assert(fv2 == 2);
        test_assert(dv2 == 2);
        test_assert(iv2 == 2);
        test_assert(uv2 == 2);
    }

    TEST_CASE(default_constructor)
    {
        dvec2 v;
        unused(v);
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2);
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 1.2);
    }

    TEST_CASE(individual_component_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 v = { 1.2, 3.4 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
    }

    TEST_CASE(truncate_constructor)
    {
        CONST_OR_CONSTEXPR dvec3 v1(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR dvec2 v2(v1);
        test_assert(v2[0] == 1.2);
        test_assert(v2[1] == 3.4);

        CONST_OR_CONSTEXPR dvec4 v3(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR dvec2 v4(v3);
        test_assert(v4[0] == 1.2);
        test_assert(v4[1] == 3.4);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 dv(1.2, 3.4);
        CONST_OR_CONSTEXPR fvec2 fv(dv);
        test_assert(fv[0] == 1.2f);
        test_assert(fv[1] == 3.4f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fvec2 fv(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 dv = fv;
        test_assert(dv[0] == 1.2f);
        test_assert(dv[1] == 3.4f);
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto v = dvec2::zero();
        test_assert(v == dvec2(0.0, 0.0));
    }

    TEST_CASE(x_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec2::x_axis();
        test_assert(v == dvec2(1.0, 0.0));
    }

    TEST_CASE(y_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec2::y_axis();
        test_assert(v == dvec2(0.0, 1.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dvec2 cev(1.2, 3.4);
        CONST_OR_CONSTEXPR auto cev0 = cev[0];
        CONST_OR_CONSTEXPR auto cev1 = cev[1];
        test_assert(cev0 == 1.2);
        test_assert(cev1 == 3.4);

        const auto cv = cev;
        const auto& cv0 = cv[0];
        const auto& cv1 = cv[1];
        test_assert(&cv0 == cv.data() + 0);
        test_assert(&cv1 == cv.data() + 1);

        auto v = cev;
        auto& v0 = v[0];
        auto& v1 = v[1];
        test_assert(&v0 == v.data() + 0);
        test_assert(&v1 == v.data() + 1);
    }

    TEST_CASE(data)
    {
        const dvec2 cv(1.2);
        const double* cdata = cv.data();
        test_assert(cdata == static_cast<const void*>(&cv));

        dvec2 v;
        double* data = v.data();
        test_assert(data == static_cast<void*>(&v));
    }

    TEST_CASE(x_y_z)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto x = v.x();
        CONST_OR_CONSTEXPR auto y = v.y();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
    }

    TEST_CASE(xy)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto xy = v.xy();
        test_assert(xy == dvec2(1.2, 3.4));
    }

    TEST_CASE(set_x_y)
    {
        dvec2 v(1.2, 3.4);
        v.set_x(5.6);
        v.set_y(7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);
    }

    TEST_CASE(set_xy)
    {
        dvec2 v(1.2, 3.4);

        v.set_xy(5.6, 7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);

        v.set_xy(dvec2(9.10, 11.12));
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
    }

    TEST_CASE(r_g_b)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto r = v.r();
        CONST_OR_CONSTEXPR auto g = v.g();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
    }

    TEST_CASE(rg)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto rg = v.rg();
        test_assert(rg == dvec2(1.2, 3.4));
    }

    TEST_CASE(set_r_g)
    {
        dvec2 v(1.2, 3.4);
        v.set_r(5.6);
        v.set_g(7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);
    }

    TEST_CASE(set_rg)
    {
        dvec2 v(1.2, 3.4);

        v.set_rg(5.6, 7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);

        v.set_rg(dvec2(9.10, 11.12));
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
    }

    TEST_CASE(pre_increment_operator)
    {
        ivec2 v(1, 2);
        test_assert(&(++v) == &v);
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
    }

    TEST_CASE(post_increment_operator)
    {
        ivec2 v(1, 2);
        test_assert(v++ == ivec2(1, 2));
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
    }

    TEST_CASE(pre_decrement_operator)
    {
        ivec2 v(1, 2);
        test_assert(&(--v) == &v);
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
    }

    TEST_CASE(post_decrement_operator)
    {
        ivec2 v(1, 2);
        test_assert(v-- == ivec2(1, 2));
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
    }

    TEST_CASE(addition_assignment_operator)
    {
        dvec2 v1(1.2, 3.4);
        test_assert(&(v1 += 5) == &v1);
        test_assert(v1[0] == 1.2 + 5);
        test_assert(v1[1] == 3.4 + 5);

        dvec2 v2(1.2, 3.4);
        test_assert(&(v2 += ivec2(5, 6)) == &v2);
        test_assert(v2[0] == 1.2 + 5);
        test_assert(v2[1] == 3.4 + 6);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        dvec2 v1(1.2, 3.4);
        test_assert(&(v1 -= 5) == &v1);
        test_assert(v1[0] == 1.2 - 5);
        test_assert(v1[1] == 3.4 - 5);

        dvec2 v2(1.2, 3.4);
        test_assert(&(v2 -= ivec2(5, 6)) == &v2);
        test_assert(v2[0] == 1.2 - 5);
        test_assert(v2[1] == 3.4 - 6);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        dvec2 v1(1.2, 3.4);
        test_assert(&(v1 *= 5) == &v1);
        test_assert(v1[0] == 1.2 * 5);
        test_assert(v1[1] == 3.4 * 5);

        dvec2 v2(1.2, 3.4);
        test_assert(&(v2 *= ivec2(5, 6)) == &v2);
        test_assert(v2[0] == 1.2 * 5);
        test_assert(v2[1] == 3.4 * 6);
    }

    TEST_CASE(mat_multiplication_assignment_operator)
    {
        const dvec2 v1(1.2, 3.4);
        const fmat2x2 m(5.6f);

        auto v2 = v1;
        test_assert(&(v2 *= m) == &v2);
        test_assert(v2 == v1 * m);
    }

    TEST_CASE(division_assignment_operator)
    {
        dvec2 v1(1.2, 3.4);
        test_assert(&(v1 /= 5) == &v1);
        test_assert(v1[0] == 1.2 / 5);
        test_assert(v1[1] == 3.4 / 5);

        dvec2 v2(1.2, 3.4);
        test_assert(&(v2 /= ivec2(5, 6)) == &v2);
        test_assert(v2[0] == 1.2 / 5);
        test_assert(v2[1] == 3.4 / 6);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        vec2<long long> v1(10LL, 21LL);
        test_assert(&(v1 %= 9) == &v1);
        test_assert(v1[0] == 10LL % 9);
        test_assert(v1[1] == 21LL % 9);

        vec2<long long> v2(10LL, 21LL);
        test_assert(&(v2 %= ivec2(9, 8)) == &v2);
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 8);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        vec2<long long> v1(12LL, 34LL);
        test_assert(&(v1 &= 56) == &v1);
        test_assert(v1[0] == (12LL & 56));
        test_assert(v1[1] == (34LL & 56));

        vec2<long long> v2(12LL, 34LL);
        test_assert(&(v2 &= ivec2(56, 78)) == &v2);
        test_assert(v2[0] == (12LL & 56));
        test_assert(v2[1] == (34LL & 78));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        vec2<long long> v1(12LL, 34LL);
        test_assert(&(v1 |= 56) == &v1);
        test_assert(v1[0] == (12LL | 56));
        test_assert(v1[1] == (34LL | 56));

        vec2<long long> v2(12LL, 34LL);
        test_assert(&(v2 |= ivec2(56, 78)) == &v2);
        test_assert(v2[0] == (12LL | 56));
        test_assert(v2[1] == (34LL | 78));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        vec2<long long> v1(12LL, 34LL);
        test_assert(&(v1 ^= 56) == &v1);
        test_assert(v1[0] == (12LL ^ 56));
        test_assert(v1[1] == (34LL ^ 56));

        vec2<long long> v2(12LL, 34LL);
        test_assert(&(v2 ^= ivec2(56, 78)) == &v2);
        test_assert(v2[0] == (12LL ^ 56));
        test_assert(v2[1] == (34LL ^ 78));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        vec2<long long> v1(12LL, 34LL);
        test_assert(&(v1 <<= 1) == &v1);
        test_assert(v1[0] == (12LL << 1));
        test_assert(v1[1] == (34LL << 1));

        vec2<long long> v2(12LL, 34LL);
        test_assert(&(v2 <<= ivec2(1, 2)) == &v2);
        test_assert(v2[0] == (12LL << 1));
        test_assert(v2[1] == (34LL << 2));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        vec2<long long> v1(12LL, 34LL);
        test_assert(&(v1 >>= 1) == &v1);
        test_assert(v1[0] == (12LL >> 1));
        test_assert(v1[1] == (34LL >> 1));

        vec2<long long> v2(12LL, 34LL);
        test_assert(&(v2 >>= ivec2(1, 2)) == &v2);
        test_assert(v2[0] == (12LL >> 1));
        test_assert(v2[1] == (34LL >> 2));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto v = +dvec2(1.2, 3.4);
        test_assert(v == dvec2(+1.2, +3.4));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto v = -dvec2(1.2, 3.4);
        test_assert(v == dvec2(-1.2, -3.4));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto v = ~ivec2(1, 2);
        test_assert(v == ivec2(~1, ~2));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 + dvec2(2.3, 4.5);
        test_assert(v1[0] == 1 + 2.3);
        test_assert(v1[1] == 1 + 4.5);

        CONST_OR_CONSTEXPR auto v2 = dvec2(1.2, 3.4) + 5;
        test_assert(v2[0] == 1.2 + 5);
        test_assert(v2[1] == 3.4 + 5);

        CONST_OR_CONSTEXPR auto v3 = dvec2(1.2, 3.4) + ivec2(5, 6);
        test_assert(v3[0] == 1.2 + 5);
        test_assert(v3[1] == 3.4 + 6);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 - dvec2(2.3, 4.5);
        test_assert(v1[0] == 1 - 2.3);
        test_assert(v1[1] == 1 - 4.5);

        CONST_OR_CONSTEXPR auto v2 = dvec2(1.2, 3.4) - 5;
        test_assert(v2[0] == 1.2 - 5);
        test_assert(v2[1] == 3.4 - 5);

        CONST_OR_CONSTEXPR auto v3 = dvec2(1.2, 3.4) - ivec2(5, 6);
        test_assert(v3[0] == 1.2 - 5);
        test_assert(v3[1] == 3.4 - 6);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 12 * dvec2(2.3, 4.5);
        test_assert(v1[0] == 12 * 2.3);
        test_assert(v1[1] == 12 * 4.5);

        CONST_OR_CONSTEXPR auto v2 = dvec2(1.2, 3.4) * 5;
        test_assert(v2[0] == 1.2 * 5);
        test_assert(v2[1] == 3.4 * 5);

        CONST_OR_CONSTEXPR auto v3 = dvec2(1.2, 3.4) * ivec2(5, 6);
        test_assert(v3[0] == 1.2 * 5);
        test_assert(v3[1] == 3.4 * 6);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 / dvec2(2.3, 4.5);
        test_assert(v1[0] == 1 / 2.3);
        test_assert(v1[1] == 1 / 4.5);

        CONST_OR_CONSTEXPR auto v2 = dvec2(1.2, 3.4) / 5;
        test_assert(v2[0] == 1.2 / 5);
        test_assert(v2[1] == 3.4 / 5);

        CONST_OR_CONSTEXPR auto v3 = dvec2(1.2, 3.4) / ivec2(5, 6);
        test_assert(v3[0] == 1.2 / 5);
        test_assert(v3[1] == 3.4 / 6);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 10 % vec2<long long>(9LL, 8LL);
        test_assert(v1[0] == 10 % 9LL);
        test_assert(v1[1] == 10 % 8LL);

        CONST_OR_CONSTEXPR auto v2 = vec2<long long>(10LL, 21LL) % 9;
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 9);

        CONST_OR_CONSTEXPR auto v3 = vec2<long long>(10LL, 21LL) % ivec2(9, 8);
        test_assert(v3[0] == 10LL % 9);
        test_assert(v3[1] == 21LL % 8);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 & vec2<long long>(23LL, 45LL);
        test_assert(v1[0] == (1 & 23LL));
        test_assert(v1[1] == (1 & 45LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec2<long long>(12LL, 34LL) & 5;
        test_assert(v2[0] == (12LL & 5));
        test_assert(v2[1] == (34LL & 5));

        CONST_OR_CONSTEXPR auto v3 =
            vec2<long long>(12LL, 34LL) & ivec2(56, 78);
        test_assert(v3[0] == (12LL & 56));
        test_assert(v3[1] == (34LL & 78));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 | vec2<long long>(23LL, 45LL);
        test_assert(v1[0] == (1 | 23LL));
        test_assert(v1[1] == (1 | 45LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec2<long long>(12LL, 34LL) | 5;
        test_assert(v2[0] == (12LL | 5));
        test_assert(v2[1] == (34LL | 5));

        CONST_OR_CONSTEXPR auto v3 =
            vec2<long long>(12LL, 34LL) | ivec2(56, 78);
        test_assert(v3[0] == (12LL | 56));
        test_assert(v3[1] == (34LL | 78));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 ^ vec2<long long>(23LL, 45LL);
        test_assert(v1[0] == (1 ^ 23LL));
        test_assert(v1[1] == (1 ^ 45LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec2<long long>(12LL, 34LL) ^ 5;
        test_assert(v2[0] == (12LL ^ 5));
        test_assert(v2[1] == (34LL ^ 5));

        CONST_OR_CONSTEXPR auto v3 =
            vec2<long long>(12LL, 34LL) ^ ivec2(56, 78);
        test_assert(v3[0] == (12LL ^ 56));
        test_assert(v3[1] == (34LL ^ 78));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 43 << vec2<long long>(2LL, 1LL);
        test_assert(v1[0] == (43 << 2LL));
        test_assert(v1[1] == (43 << 1LL));

        CONST_OR_CONSTEXPR auto v2 = vec2<long long>(54LL, 32LL) << 1;
        test_assert(v2[0] == (54LL << 1));
        test_assert(v2[1] == (32LL << 1));

        CONST_OR_CONSTEXPR auto v3 = vec2<long long>(65LL, 43LL) << ivec2(2, 1);
        test_assert(v3[0] == (65LL << 2));
        test_assert(v3[1] == (43LL << 1));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 43 >> vec2<long long>(2LL, 1LL);
        test_assert(v1[0] == (43 >> 2LL));
        test_assert(v1[1] == (43 >> 1LL));

        CONST_OR_CONSTEXPR auto v2 = vec2<long long>(54LL, 32LL) >> 1;
        test_assert(v2[0] == (54LL >> 1));
        test_assert(v2[1] == (32LL >> 1));

        CONST_OR_CONSTEXPR auto v3 = vec2<long long>(65LL, 43LL) >> ivec2(2, 1);
        test_assert(v3[0] == (65LL >> 2));
        test_assert(v3[1] == (43LL >> 1));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fvec2 v1(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 v2(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 v3(1.2f, 0.0f);
        CONST_OR_CONSTEXPR dvec2 v4(0.0f, 3.4f);
        CONST_OR_CONSTEXPR auto result1 = (v1 == v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 == v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 == v4);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fvec2 v1(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 v2(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 v3(1.2f, 0.0f);
        CONST_OR_CONSTEXPR dvec2 v4(0.0f, 3.4f);
        CONST_OR_CONSTEXPR auto result1 = (v1 != v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 != v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 != v4);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
    }

    TEST_CASE(sin)
    {
        const auto v = math::sin(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::sin(1.2)));
        test_assert(nearly_equal(v[1], math::sin(3.4)));
    }

    TEST_CASE(cos)
    {
        const auto v = math::cos(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::cos(1.2)));
        test_assert(nearly_equal(v[1], math::cos(3.4)));
    }

    TEST_CASE(sincos)
    {
        dvec2 s, c;
        math::sincos(dvec2(1.2, 3.4), s, c);

        test_assert(nearly_equal(s[0], math::sin(1.2)));
        test_assert(nearly_equal(s[1], math::sin(3.4)));

        test_assert(nearly_equal(c[0], math::cos(1.2)));
        test_assert(nearly_equal(c[1], math::cos(3.4)));
    }

    TEST_CASE(exp)
    {
        const auto v = math::exp(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::exp(1.2)));
        test_assert(nearly_equal(v[1], math::exp(3.4)));
    }

    TEST_CASE(log)
    {
        const auto v = math::log(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::log(1.2)));
        test_assert(nearly_equal(v[1], math::log(3.4)));
    }

    TEST_CASE(abs)
    {
        const auto v = math::abs(dvec2(1.2, -3.4));
        test_assert(v[0] == math::abs(1.2));
        test_assert(v[1] == math::abs(-3.4));
    }

    TEST_CASE(pow)
    {
        const auto v = math::pow(dvec2(1.2, 3.4), dvec2(5.6, 7.8));
        test_assert(nearly_equal(v[0], math::pow(1.2, 5.6)));
        test_assert(nearly_equal(v[1], math::pow(3.4, 7.8)));
    }

    TEST_CASE(recip)
    {
        const auto v = math::recip(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::recip(1.2)));
        test_assert(nearly_equal(v[1], math::recip(3.4)));
    }

    TEST_CASE(sqrt)
    {
        const auto v = math::sqrt(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::sqrt(1.2)));
        test_assert(nearly_equal(v[1], math::sqrt(3.4)));
    }

    TEST_CASE(rsqrt)
    {
        const auto v = math::rsqrt(dvec2(1.2, 3.4));
        test_assert(nearly_equal(v[0], math::rsqrt(1.2)));
        test_assert(nearly_equal(v[1], math::rsqrt(3.4)));
    }

    TEST_CASE(min)
    {
        const auto v = math::min(dvec2(1.2, 3.4), dvec2(5.6, -7.8));
        test_assert(v[0] == math::min(1.2, 5.6));
        test_assert(v[1] == math::min(3.4, -7.8));
    }

    TEST_CASE(max)
    {
        const auto v = math::max(dvec2(1.2, 3.4), dvec2(5.6, -7.8));
        test_assert(v[0] == math::max(1.2, 5.6));
        test_assert(v[1] == math::max(3.4, -7.8));
    }

    TEST_CASE(mask)
    {
        const auto v = math::mask(
            vec2<bool64>(true64, false64), dvec2(1.2, 3.4));
        test_assert(v == dvec2(1.2, 0.0));
    }

    TEST_CASE(select)
    {
        const auto v = math::select(
            vec2<bool64>(true64, false64), dvec2(1.2, 3.4), dvec2(5.6, 7.8));
        test_assert(v == dvec2(1.2, 7.8));
    }

    TEST_CASE(less)
    {
        const auto v1 = math::less(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::less(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(true64, false64));
        test_assert(v2 == vec2<bool64>(false64, false64));
    }

    TEST_CASE(less_equal)
    {
        const auto v1 = math::less_equal(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::less_equal(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(true64, true64));
        test_assert(v2 == vec2<bool64>(false64, false64));
    }

    TEST_CASE(greater)
    {
        const auto v1 = math::greater(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::greater(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(false64, false64));
        test_assert(v2 == vec2<bool64>(true64, true64));
    }

    TEST_CASE(greater_equal)
    {
        const auto v1 = math::greater_equal(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::greater_equal(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(false64, true64));
        test_assert(v2 == vec2<bool64>(true64, true64));
    }

    TEST_CASE(equal)
    {
        const auto v1 = math::equal(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::equal(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(false64, true64));
        test_assert(v2 == vec2<bool64>(false64, false64));
    }

    TEST_CASE(not_equal)
    {
        const auto v1 = math::not_equal(
            dvec2(1.0, 2.0), dvec2(2.1, 2.0));
        const auto v2 = math::not_equal(
            dvec2(3.0, 4.0), dvec2(1.9, 1.8));
        test_assert(v1 == vec2<bool64>(true64, false64));
        test_assert(v2 == vec2<bool64>(true64, true64));
    }

    TEST_CASE(dot)
    {
        CONST_OR_CONSTEXPR auto x = math::dot(dvec2(1.2, 3.4), dvec2(7, 8));
        test_assert(nearly_equal(x, 1.2*7 + 3.4*8));
    }

    TEST_CASE(length)
    {
        test_assert(nearly_equal(
            math::length(dvec2(1.2, 3.4)),
            math::sqrt(math::length2(dvec2(1.2, 3.4)))));
    }

    TEST_CASE(length2)
    {
        CONST_OR_CONSTEXPR auto x = math::length2(dvec2(1.2, 3.4));
        test_assert(nearly_equal(x, 1.2*1.2 + 3.4*3.4));
    }

    TEST_CASE(rlength)
    {
        test_assert(nearly_equal(
            math::rlength(dvec2(1.2, 3.4)),
            math::rsqrt(math::length2(dvec2(1.2, 3.4)))));
    }

    TEST_CASE(normalize)
    {
        const dvec2 v(1.2, 3.4);
        test_assert(math::normalize(v) == v * math::rlength(v));
    }
}
