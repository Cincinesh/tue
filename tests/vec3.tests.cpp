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
#include <tue/quat.hpp>
#include <tue/sized_bool.hpp>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(vec3<short>) == sizeof(short[3]));
        test_assert(sizeof(fvec3) == sizeof(float[3]));
        test_assert(sizeof(dvec3) == sizeof(double[3]));
        test_assert(sizeof(ivec3) == sizeof(int[3]));
        test_assert(sizeof(uvec3) == sizeof(unsigned int[3]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(vec3<short>) == alignof(short[3]));
        test_assert(alignof(fvec3) == alignof(float[3]));
        test_assert(alignof(dvec3) <= alignof(double[3]));
        test_assert(alignof(ivec3) == alignof(int[3]));
        test_assert(alignof(uvec3) == alignof(unsigned int[3]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename vec3<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fvec3::component_type, float>::value));
        test_assert((std::is_same<
            typename dvec3::component_type, double>::value));
        test_assert((std::is_same<
            typename ivec3::component_type, int>::value));
        test_assert((std::is_same<
            typename uvec3::component_type, unsigned int>::value));
    }

    TEST_CASE(component_count)
    {
        constexpr auto v3s = vec3<short>::component_count;
        constexpr auto fv3 = fvec3::component_count;
        constexpr auto dv3 = dvec3::component_count;
        constexpr auto iv3 = ivec3::component_count;
        constexpr auto uv3 = uvec3::component_count;
        test_assert(v3s == 3);
        test_assert(fv3 == 3);
        test_assert(dv3 == 3);
        test_assert(iv3 == 3);
        test_assert(uv3 == 3);
    }

    TEST_CASE(default_constructor)
    {
        dvec3 v;
        unused(v);
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2);
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 1.2);
        test_assert(v[2] == 1.2);
    }

    TEST_CASE(individual_component_constructor)
    {
        CONST_OR_CONSTEXPR dvec3 v = { 1.2, 3.4, 5.6 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
    }

    TEST_CASE(extend_vec2_constructor)
    {
        CONST_OR_CONSTEXPR dvec3 v = { { 1.2, 3.4 }, 5.6 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
    }

    TEST_CASE(truncate_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v1(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR dvec3 v2(v1);
        test_assert(v2[0] == 1.2);
        test_assert(v2[1] == 3.4);
        test_assert(v2[2] == 5.6);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dvec3 dv(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR fvec3 fv(dv);
        test_assert(fv[0] == 1.2f);
        test_assert(fv[1] == 3.4f);
        test_assert(fv[2] == 5.6f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fvec3 fv(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 dv = fv;
        test_assert(dv[0] == 1.2f);
        test_assert(dv[1] == 3.4f);
        test_assert(dv[2] == 5.6f);
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto v = dvec3::zero();
        test_assert(v == dvec3(0.0, 0.0, 0.0));
    }

    TEST_CASE(x_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec3::x_axis();
        test_assert(v == dvec3(1.0, 0.0, 0.0));
    }

    TEST_CASE(y_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec3::y_axis();
        test_assert(v == dvec3(0.0, 1.0, 0.0));
    }

    TEST_CASE(z_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec3::z_axis();
        test_assert(v == dvec3(0.0, 0.0, 1.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dvec3 cev(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto cev0 = cev[0];
        CONST_OR_CONSTEXPR auto cev1 = cev[1];
        CONST_OR_CONSTEXPR auto cev2 = cev[2];
        test_assert(cev0 == 1.2);
        test_assert(cev1 == 3.4);
        test_assert(cev2 == 5.6);

        const auto cv = cev;
        const auto& cv0 = cv[0];
        const auto& cv1 = cv[1];
        const auto& cv2 = cv[2];
        test_assert(&cv0 == cv.data() + 0);
        test_assert(&cv1 == cv.data() + 1);
        test_assert(&cv2 == cv.data() + 2);

        auto v = cev;
        auto& v0 = v[0];
        auto& v1 = v[1];
        auto& v2 = v[2];
        test_assert(&v0 == v.data() + 0);
        test_assert(&v1 == v.data() + 1);
        test_assert(&v2 == v.data() + 2);
    }

    TEST_CASE(data)
    {
        const dvec3 cv(1.2);
        const double* cdata = cv.data();
        test_assert(cdata == static_cast<const void*>(&cv));

        dvec3 v;
        double* data = v.data();
        test_assert(data == static_cast<void*>(&v));
    }

    TEST_CASE(x_y_z)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto x = v.x();
        CONST_OR_CONSTEXPR auto y = v.y();
        CONST_OR_CONSTEXPR auto z = v.z();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
        test_assert(z == 5.6);
    }

    TEST_CASE(xy)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto xy = v.xy();
        test_assert(xy == dvec2(1.2, 3.4));
    }

    TEST_CASE(xyz)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto xyz = v.xyz();
        test_assert(xyz == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(set_x_y_z)
    {
        dvec3 v(1.2, 3.4, 5.6);
        v.set_x(7.8);
        v.set_y(9.10);
        v.set_z(11.12);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 11.12);
    }

    TEST_CASE(set_xy)
    {
        dvec3 v(1.2, 3.4, 5.6);

        v.set_xy(7.8, 9.10);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 5.6);

        v.set_xy(dvec2(11.12, 13.14));
        test_assert(v[0] == 11.12);
        test_assert(v[1] == 13.14);
        test_assert(v[2] == 5.6);
    }

    TEST_CASE(set_xyz)
    {
        dvec3 v(1.2, 3.4, 5.6);

        v.set_xyz(7.8, 9.10, 11.12);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 11.12);

        v.set_xyz(dvec2(13.14, 15.16), 17.18);
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 17.18);

        v.set_xyz(dvec3(19.20, 21.22, 23.24));
        test_assert(v[0] == 19.20);
        test_assert(v[1] == 21.22);
        test_assert(v[2] == 23.24);
    }

    TEST_CASE(r_g_b)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto r = v.r();
        CONST_OR_CONSTEXPR auto g = v.g();
        CONST_OR_CONSTEXPR auto b = v.b();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
        test_assert(b == 5.6);
    }

    TEST_CASE(rg)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto rg = v.rg();
        test_assert(rg == dvec2(1.2, 3.4));
    }

    TEST_CASE(rgb)
    {
        CONST_OR_CONSTEXPR dvec3 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto rgb = v.rgb();
        test_assert(rgb == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(set_r_g_b)
    {
        dvec3 v(1.2, 3.4, 5.6);
        v.set_r(7.8);
        v.set_g(9.10);
        v.set_b(11.12);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 11.12);
    }

    TEST_CASE(set_rg)
    {
        dvec3 v(1.2, 3.4, 5.6);

        v.set_rg(7.8, 9.10);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 5.6);

        v.set_rg(dvec2(11.12, 13.14));
        test_assert(v[0] == 11.12);
        test_assert(v[1] == 13.14);
        test_assert(v[2] == 5.6);
    }

    TEST_CASE(set_rgb)
    {
        dvec3 v(1.2, 3.4, 5.6);

        v.set_rgb(7.8, 9.10, 11.12);
        test_assert(v[0] == 7.8);
        test_assert(v[1] == 9.10);
        test_assert(v[2] == 11.12);

        v.set_rgb(dvec2(13.14, 15.16), 17.18);
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 17.18);

        v.set_rgb(dvec3(19.20, 21.22, 23.24));
        test_assert(v[0] == 19.20);
        test_assert(v[1] == 21.22);
        test_assert(v[2] == 23.24);
    }

    TEST_CASE(pre_increment_operator)
    {
        ivec3 v(1, 2, 3);
        test_assert(&(++v) == &v);
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
        test_assert(v[2] == 4);
    }

    TEST_CASE(post_increment_operator)
    {
        ivec3 v(1, 2, 3);
        test_assert(v++ == ivec3(1, 2, 3));
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
        test_assert(v[2] == 4);
    }

    TEST_CASE(pre_decrement_operator)
    {
        ivec3 v(1, 2, 3);
        test_assert(&(--v) == &v);
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
        test_assert(v[2] == 2);
    }

    TEST_CASE(post_decrement_operator)
    {
        ivec3 v(1, 2, 3);
        test_assert(v-- == ivec3(1, 2, 3));
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
        test_assert(v[2] == 2);
    }

    TEST_CASE(addition_assignment_operator)
    {
        dvec3 v1(1.2, 3.4, 5.6);
        test_assert(&(v1 += 7) == &v1);
        test_assert(v1[0] == 1.2 + 7);
        test_assert(v1[1] == 3.4 + 7);
        test_assert(v1[2] == 5.6 + 7);

        dvec3 v2(1.2, 3.4, 5.6);
        test_assert(&(v2 += ivec3(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 + 7);
        test_assert(v2[1] == 3.4 + 8);
        test_assert(v2[2] == 5.6 + 9);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        dvec3 v1(1.2, 3.4, 5.6);
        test_assert(&(v1 -= 7) == &v1);
        test_assert(v1[0] == 1.2 - 7);
        test_assert(v1[1] == 3.4 - 7);
        test_assert(v1[2] == 5.6 - 7);

        dvec3 v2(1.2, 3.4, 5.6);
        test_assert(&(v2 -= ivec3(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 - 7);
        test_assert(v2[1] == 3.4 - 8);
        test_assert(v2[2] == 5.6 - 9);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        dvec3 v1(1.2, 3.4, 5.6);
        test_assert(&(v1 *= 7) == &v1);
        test_assert(v1[0] == 1.2 * 7);
        test_assert(v1[1] == 3.4 * 7);
        test_assert(v1[2] == 5.6 * 7);

        dvec3 v2(1.2, 3.4, 5.6);
        test_assert(&(v2 *= ivec3(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 * 7);
        test_assert(v2[1] == 3.4 * 8);
        test_assert(v2[2] == 5.6 * 9);
    }

    TEST_CASE(quat_multiplication_assignment_operator)
    {
        const dvec3 v1(1.2, 3.4, 5.6);
        const fquat q(7.8f, 9.10f, 11.12f, 13.14f);

        auto v2 = v1;
        test_assert(&(v2 *= q) == &v2);
        test_assert(v2 == v1 * q);
    }

    TEST_CASE(mat_multiplication_assignment_operator)
    {
        const dvec3 v1(1.2, 3.4, 5.6);
        const fmat3x3 m(7.8f);

        auto v2 = v1;
        test_assert(&(v2 *= m) == &v2);
        test_assert(v2 == v1 * m);
    }

    TEST_CASE(division_assignment_operator)
    {
        dvec3 v1(1.2, 3.4, 5.6);
        test_assert(&(v1 /= 7) == &v1);
        test_assert(v1[0] == 1.2 / 7);
        test_assert(v1[1] == 3.4 / 7);
        test_assert(v1[2] == 5.6 / 7);

        dvec3 v2(1.2, 3.4, 5.6);
        test_assert(&(v2 /= ivec3(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 / 7);
        test_assert(v2[1] == 3.4 / 8);
        test_assert(v2[2] == 5.6 / 9);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        vec3<long long> v1(10LL, 21LL, 32LL);
        test_assert(&(v1 %= 9) == &v1);
        test_assert(v1[0] == 10LL % 9);
        test_assert(v1[1] == 21LL % 9);
        test_assert(v1[2] == 32LL % 9);

        vec3<long long> v2(10LL, 21LL, 32LL);
        test_assert(&(v2 %= ivec3(9, 8, 7)) == &v2);
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 8);
        test_assert(v2[2] == 32LL % 7);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        vec3<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 &= 78) == &v1);
        test_assert(v1[0] == (12LL & 78));
        test_assert(v1[1] == (34LL & 78));
        test_assert(v1[2] == (56LL & 78));

        vec3<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 &= ivec3(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL & 78));
        test_assert(v2[1] == (34LL & 910));
        test_assert(v2[2] == (56LL & 1112));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        vec3<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 |= 78) == &v1);
        test_assert(v1[0] == (12LL | 78));
        test_assert(v1[1] == (34LL | 78));
        test_assert(v1[2] == (56LL | 78));

        vec3<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 |= ivec3(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL | 78));
        test_assert(v2[1] == (34LL | 910));
        test_assert(v2[2] == (56LL | 1112));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        vec3<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 ^= 78) == &v1);
        test_assert(v1[0] == (12LL ^ 78));
        test_assert(v1[1] == (34LL ^ 78));
        test_assert(v1[2] == (56LL ^ 78));

        vec3<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 ^= ivec3(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL ^ 78));
        test_assert(v2[1] == (34LL ^ 910));
        test_assert(v2[2] == (56LL ^ 1112));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        vec3<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 <<= 1) == &v1);
        test_assert(v1[0] == (12LL << 1));
        test_assert(v1[1] == (34LL << 1));
        test_assert(v1[2] == (56LL << 1));

        vec3<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 <<= ivec3(1, 2, 3)) == &v2);
        test_assert(v2[0] == (12LL << 1));
        test_assert(v2[1] == (34LL << 2));
        test_assert(v2[2] == (56LL << 3));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        vec3<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 >>= 1) == &v1);
        test_assert(v1[0] == (12LL >> 1));
        test_assert(v1[1] == (34LL >> 1));
        test_assert(v1[2] == (56LL >> 1));

        vec3<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 >>= ivec3(1, 2, 3)) == &v2);
        test_assert(v2[0] == (12LL >> 1));
        test_assert(v2[1] == (34LL >> 2));
        test_assert(v2[2] == (56LL >> 3));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto v = +dvec3(1.2, 3.4, 5.6);
        test_assert(v == dvec3(+1.2, +3.4, +5.6));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto v = -dvec3(1.2, 3.4, 5.6);
        test_assert(v == dvec3(-1.2, -3.4, -5.6));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto v = ~ivec3(1, 2, 3);
        test_assert(v == ivec3(~1, ~2, ~3));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 + dvec3(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 + 2.3);
        test_assert(v1[1] == 1 + 4.5);
        test_assert(v1[2] == 1 + 6.7);

        CONST_OR_CONSTEXPR auto v2 = dvec3(1.2, 3.4, 5.6) + 7;
        test_assert(v2[0] == 1.2 + 7);
        test_assert(v2[1] == 3.4 + 7);
        test_assert(v2[2] == 5.6 + 7);

        CONST_OR_CONSTEXPR auto v3 = dvec3(1.2, 3.4, 5.6) + ivec3(7, 8, 9);
        test_assert(v3[0] == 1.2 + 7);
        test_assert(v3[1] == 3.4 + 8);
        test_assert(v3[2] == 5.6 + 9);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 - dvec3(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 - 2.3);
        test_assert(v1[1] == 1 - 4.5);
        test_assert(v1[2] == 1 - 6.7);

        CONST_OR_CONSTEXPR auto v2 = dvec3(1.2, 3.4, 5.6) - 7;
        test_assert(v2[0] == 1.2 - 7);
        test_assert(v2[1] == 3.4 - 7);
        test_assert(v2[2] == 5.6 - 7);

        CONST_OR_CONSTEXPR auto v3 = dvec3(1.2, 3.4, 5.6) - ivec3(7, 8, 9);
        test_assert(v3[0] == 1.2 - 7);
        test_assert(v3[1] == 3.4 - 8);
        test_assert(v3[2] == 5.6 - 9);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 12 * dvec3(2.3, 4.5, 6.7);
        test_assert(v1[0] == 12 * 2.3);
        test_assert(v1[1] == 12 * 4.5);
        test_assert(v1[2] == 12 * 6.7);

        CONST_OR_CONSTEXPR auto v2 = dvec3(1.2, 3.4, 5.6) * 7;
        test_assert(v2[0] == 1.2 * 7);
        test_assert(v2[1] == 3.4 * 7);
        test_assert(v2[2] == 5.6 * 7);

        CONST_OR_CONSTEXPR auto v3 = dvec3(1.2, 3.4, 5.6) * ivec3(7, 8, 9);
        test_assert(v3[0] == 1.2 * 7);
        test_assert(v3[1] == 3.4 * 8);
        test_assert(v3[2] == 5.6 * 9);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 / dvec3(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 / 2.3);
        test_assert(v1[1] == 1 / 4.5);
        test_assert(v1[2] == 1 / 6.7);

        CONST_OR_CONSTEXPR auto v2 = dvec3(1.2, 3.4, 5.6) / 7;
        test_assert(v2[0] == 1.2 / 7);
        test_assert(v2[1] == 3.4 / 7);
        test_assert(v2[2] == 5.6 / 7);

        CONST_OR_CONSTEXPR auto v3 = dvec3(1.2, 3.4, 5.6) / ivec3(7, 8, 9);
        test_assert(v3[0] == 1.2 / 7);
        test_assert(v3[1] == 3.4 / 8);
        test_assert(v3[2] == 5.6 / 9);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            10 % vec3<long long>(9LL, 8LL, 7LL);
        test_assert(v1[0] == 10 % 9LL);
        test_assert(v1[1] == 10 % 8LL);
        test_assert(v1[2] == 10 % 7LL);

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(10LL, 21LL, 32LL) % 9;
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 9);
        test_assert(v2[2] == 32LL % 9);

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(10LL, 21LL, 32LL) % ivec3(9, 8, 7);
        test_assert(v3[0] == 10LL % 9);
        test_assert(v3[1] == 21LL % 8);
        test_assert(v3[2] == 32LL % 7);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 & vec3<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 & 23LL));
        test_assert(v1[1] == (1 & 45LL));
        test_assert(v1[2] == (1 & 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(12LL, 34LL, 56LL) & 7;
        test_assert(v2[0] == (12LL & 7));
        test_assert(v2[1] == (34LL & 7));
        test_assert(v2[2] == (56LL & 7));

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(12LL, 34LL, 56LL) & ivec3(78, 910, 1112);
        test_assert(v3[0] == (12LL & 78));
        test_assert(v3[1] == (34LL & 910));
        test_assert(v3[2] == (56LL & 1112));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 | vec3<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 | 23LL));
        test_assert(v1[1] == (1 | 45LL));
        test_assert(v1[2] == (1 | 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(12LL, 34LL, 56LL) | 7;
        test_assert(v2[0] == (12LL | 7));
        test_assert(v2[1] == (34LL | 7));
        test_assert(v2[2] == (56LL | 7));

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(12LL, 34LL, 56LL) | ivec3(78, 910, 1112);
        test_assert(v3[0] == (12LL | 78));
        test_assert(v3[1] == (34LL | 910));
        test_assert(v3[2] == (56LL | 1112));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 ^ vec3<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 ^ 23LL));
        test_assert(v1[1] == (1 ^ 45LL));
        test_assert(v1[2] == (1 ^ 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(12LL, 34LL, 56LL) ^ 7;
        test_assert(v2[0] == (12LL ^ 7));
        test_assert(v2[1] == (34LL ^ 7));
        test_assert(v2[2] == (56LL ^ 7));

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(12LL, 34LL, 56LL) ^ ivec3(78, 910, 1112);
        test_assert(v3[0] == (12LL ^ 78));
        test_assert(v3[1] == (34LL ^ 910));
        test_assert(v3[2] == (56LL ^ 1112));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            54 << vec3<long long>(3LL, 2LL, 1LL);
        test_assert(v1[0] == (54 << 3LL));
        test_assert(v1[1] == (54 << 2LL));
        test_assert(v1[2] == (54 << 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(76LL, 54LL, 32LL) << 1;
        test_assert(v2[0] == (76LL << 1));
        test_assert(v2[1] == (54LL << 1));
        test_assert(v2[2] == (32LL << 1));

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(98LL, 76LL, 54LL) << ivec3(3, 2, 1);
        test_assert(v3[0] == (98LL << 3));
        test_assert(v3[1] == (76LL << 2));
        test_assert(v3[2] == (54LL << 1));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            54 >> vec3<long long>(3LL, 2LL, 1LL);
        test_assert(v1[0] == (54 >> 3LL));
        test_assert(v1[1] == (54 >> 2LL));
        test_assert(v1[2] == (54 >> 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec3<long long>(76LL, 54LL, 32LL) >> 1;
        test_assert(v2[0] == (76LL >> 1));
        test_assert(v2[1] == (54LL >> 1));
        test_assert(v2[2] == (32LL >> 1));

        CONST_OR_CONSTEXPR auto v3 =
            vec3<long long>(98LL, 76LL, 54LL) >> ivec3(3, 2, 1);
        test_assert(v3[0] == (98LL >> 3));
        test_assert(v3[1] == (76LL >> 2));
        test_assert(v3[2] == (54LL >> 1));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fvec3 v1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dvec3 v4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (v1 == v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 == v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 == v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 == v5);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fvec3 v1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dvec3 v4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dvec3 v5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (v1 != v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 != v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 != v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 != v5);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
    }

    TEST_CASE(sin)
    {
        const auto v = math::sin(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::sin(1.2)));
        test_assert(nearly_equal(v[1], math::sin(3.4)));
        test_assert(nearly_equal(v[2], math::sin(5.6)));
    }

    TEST_CASE(cos)
    {
        const auto v = math::cos(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::cos(1.2)));
        test_assert(nearly_equal(v[1], math::cos(3.4)));
        test_assert(nearly_equal(v[2], math::cos(5.6)));
    }

    TEST_CASE(sincos)
    {
        dvec3 s, c;
        math::sincos(dvec3(1.2, 3.4, 5.6), s, c);

        test_assert(nearly_equal(s[0], math::sin(1.2)));
        test_assert(nearly_equal(s[1], math::sin(3.4)));
        test_assert(nearly_equal(s[2], math::sin(5.6)));

        test_assert(nearly_equal(c[0], math::cos(1.2)));
        test_assert(nearly_equal(c[1], math::cos(3.4)));
        test_assert(nearly_equal(c[2], math::cos(5.6)));
    }

    TEST_CASE(exp)
    {
        const auto v = math::exp(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::exp(1.2)));
        test_assert(nearly_equal(v[1], math::exp(3.4)));
        test_assert(nearly_equal(v[2], math::exp(5.6)));
    }

    TEST_CASE(log)
    {
        const auto v = math::log(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::log(1.2)));
        test_assert(nearly_equal(v[1], math::log(3.4)));
        test_assert(nearly_equal(v[2], math::log(5.6)));
    }

    TEST_CASE(abs)
    {
        const auto v = math::abs(dvec3(1.2, -3.4, 5.6));
        test_assert(v[0] == math::abs(1.2));
        test_assert(v[1] == math::abs(-3.4));
        test_assert(v[2] == math::abs(5.6));
    }

    TEST_CASE(pow)
    {
        const auto v = math::pow(
            dvec3(1.2, 3.4, 5.6), dvec3(7.8, 9.10, 11.12));
        test_assert(nearly_equal(v[0], math::pow(1.2, 7.8)));
        test_assert(nearly_equal(v[1], math::pow(3.4, 9.10)));
        test_assert(nearly_equal(v[2], math::pow(5.6, 11.12)));
    }

    TEST_CASE(recip)
    {
        const auto v = math::recip(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::recip(1.2)));
        test_assert(nearly_equal(v[1], math::recip(3.4)));
        test_assert(nearly_equal(v[2], math::recip(5.6)));
    }

    TEST_CASE(sqrt)
    {
        const auto v = math::sqrt(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::sqrt(1.2)));
        test_assert(nearly_equal(v[1], math::sqrt(3.4)));
        test_assert(nearly_equal(v[2], math::sqrt(5.6)));
    }

    TEST_CASE(rsqrt)
    {
        const auto v = math::rsqrt(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(v[0], math::rsqrt(1.2)));
        test_assert(nearly_equal(v[1], math::rsqrt(3.4)));
        test_assert(nearly_equal(v[2], math::rsqrt(5.6)));
    }

    TEST_CASE(min)
    {
        const auto v = math::min(
            dvec3(1.2, 3.4, 5.6), dvec3(7.8, -9.10, 11.12));
        test_assert(v[0] == math::min(1.2, 7.8));
        test_assert(v[1] == math::min(3.4, -9.10));
        test_assert(v[2] == math::min(5.6, 11.12));
    }

    TEST_CASE(max)
    {
        const auto v = math::max(
            dvec3(1.2, 3.4, 5.6), dvec3(7.8, -9.10, 11.12));
        test_assert(v[0] == math::max(1.2, 7.8));
        test_assert(v[1] == math::max(3.4, -9.10));
        test_assert(v[2] == math::max(5.6, 11.12));
    }

    TEST_CASE(mask)
    {
        const auto v = math::mask(
            vec3<bool64>(true64, false64, true64),
            dvec3(1.2, 3.4, 5.6));
        test_assert(v == dvec3(1.2, 0.0, 5.6));
    }

    TEST_CASE(select)
    {
        const auto v = math::select(
            vec3<bool64>(true64, false64, true64),
            dvec3(1.2, 3.4, 5.6), dvec3(7.8, 9.10, 11.12));
        test_assert(v == dvec3(1.2, 9.10, 5.6));
    }

    TEST_CASE(less)
    {
        const auto v = math::less(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(true64, false64, false64));
    }

    TEST_CASE(less_equal)
    {
        const auto v = math::less_equal(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(true64, true64, false64));
    }

    TEST_CASE(greater)
    {
        const auto v = math::greater(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(false64, false64, true64));
    }

    TEST_CASE(greater_equal)
    {
        const auto v = math::greater_equal(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(false64, true64, true64));
    }

    TEST_CASE(equal)
    {
        const auto v = math::equal(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(false64, true64, false64));
    }

    TEST_CASE(not_equal)
    {
        const auto v = math::not_equal(
            dvec3(1.0, 2.0, 3.0), dvec3(2.1, 2.0, 1.9));
        test_assert(v == vec3<bool64>(true64, false64, true64));
    }

    TEST_CASE(dot)
    {
        CONST_OR_CONSTEXPR auto x = math::dot(
            dvec3(1.2, 3.4, 5.6), dvec3(7, 8, 9));
        test_assert(nearly_equal(x, 1.2*7 + 3.4*8 + 5.6*9));
    }

    TEST_CASE(cross)
    {
        CONST_OR_CONSTEXPR auto v = math::cross(
            dvec3(1.2, 3.4, 5.6), dvec3(7, 8, 9));
        test_assert(v[0] == 3.4*9 - 5.6*8);
        test_assert(v[1] == 5.6*7 - 1.2*9);
        test_assert(v[2] == 1.2*8 - 3.4*7);
    }

    TEST_CASE(length)
    {
        test_assert(nearly_equal(
            math::length(dvec3(1.2, 3.4, 5.6)),
            math::sqrt(math::length2(dvec3(1.2, 3.4, 5.6)))));
    }

    TEST_CASE(length2)
    {
        CONST_OR_CONSTEXPR auto x = math::length2(dvec3(1.2, 3.4, 5.6));
        test_assert(nearly_equal(x, 1.2*1.2 + 3.4*3.4 + 5.6*5.6));
    }

    TEST_CASE(rlength)
    {
        test_assert(nearly_equal(
            math::rlength(dvec3(1.2, 3.4, 5.6)),
            math::rsqrt(math::length2(dvec3(1.2, 3.4, 5.6)))));
    }

    TEST_CASE(normalize)
    {
        const dvec3 v(1.2, 3.4, 5.6);
        test_assert(math::normalize(v) == v * math::rlength(v));
    }
}
