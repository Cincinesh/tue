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
        test_assert(sizeof(vec4<short>) == sizeof(short[4]));
        test_assert(sizeof(fvec4) == sizeof(float[4]));
        test_assert(sizeof(dvec4) == sizeof(double[4]));
        test_assert(sizeof(ivec4) == sizeof(int[4]));
        test_assert(sizeof(uvec4) == sizeof(unsigned int[4]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(vec4<short>) == alignof(short[4]));
        test_assert(alignof(fvec4) == alignof(float[4]));
        test_assert(alignof(dvec4) <= alignof(double[4]));
        test_assert(alignof(ivec4) == alignof(int[4]));
        test_assert(alignof(uvec4) == alignof(unsigned int[4]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename vec4<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fvec4::component_type, float>::value));
        test_assert((std::is_same<
            typename dvec4::component_type, double>::value));
        test_assert((std::is_same<
            typename ivec4::component_type, int>::value));
        test_assert((std::is_same<
            typename uvec4::component_type, unsigned int>::value));
    }

    TEST_CASE(component_count)
    {
        constexpr auto v4s = vec4<short>::component_count;
        constexpr auto fv4 = fvec4::component_count;
        constexpr auto dv4 = dvec4::component_count;
        constexpr auto iv4 = ivec4::component_count;
        constexpr auto uv4 = uvec4::component_count;
        test_assert(v4s == 4);
        test_assert(fv4 == 4);
        test_assert(dv4 == 4);
        test_assert(iv4 == 4);
        test_assert(uv4 == 4);
    }

    TEST_CASE(default_constructor)
    {
        dvec4 v;
        unused(v);
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2);
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 1.2);
        test_assert(v[2] == 1.2);
        test_assert(v[3] == 1.2);
    }

    TEST_CASE(individual_component_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { 1.2, 3.4, 5.6, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(extend_vec2_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { { 1.2, 3.4 }, 5.6, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(extend_vec3_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { { 1.2, 3.4, 5.6 }, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(truncate_constructor)
    {
        // No way to test without vecN > 4
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 dv(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR fvec4 fv(dv);
        test_assert(fv[0] == 1.2f);
        test_assert(fv[1] == 3.4f);
        test_assert(fv[2] == 5.6f);
        test_assert(fv[3] == 7.8f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fvec4 fv(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 dv = fv;
        test_assert(dv[0] == 1.2f);
        test_assert(dv[1] == 3.4f);
        test_assert(dv[2] == 5.6f);
        test_assert(dv[3] == 7.8f);
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto v = dvec4::zero();
        test_assert(v == dvec4(0.0, 0.0, 0.0, 0.0));
    }

    TEST_CASE(x_axis)
    {
        CONST_OR_CONSTEXPR auto v = dvec4::x_axis();
        test_assert(v == dvec4(1.0, 0.0, 0.0, 0.0));
    }

    TEST_CASE(y_axis)
    {
        CONST_OR_CONSTEXPR auto v = fvec4::y_axis();
        test_assert(v == dvec4(0.0, 1.0, 0.0, 0.0));
    }

    TEST_CASE(z_axis)
    {
        CONST_OR_CONSTEXPR auto v = fvec4::z_axis();
        test_assert(v == dvec4(0.0, 0.0, 1.0, 0.0));
    }

    TEST_CASE(w_axis)
    {
        CONST_OR_CONSTEXPR auto v = fvec4::w_axis();
        test_assert(v == dvec4(0.0, 0.0, 0.0, 1.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dvec4 cev(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto cev0 = cev[0];
        CONST_OR_CONSTEXPR auto cev1 = cev[1];
        CONST_OR_CONSTEXPR auto cev2 = cev[2];
        CONST_OR_CONSTEXPR auto cev3 = cev[3];
        test_assert(cev0 == 1.2);
        test_assert(cev1 == 3.4);
        test_assert(cev2 == 5.6);
        test_assert(cev3 == 7.8);

        const auto cv = cev;
        const auto& cv0 = cv[0];
        const auto& cv1 = cv[1];
        const auto& cv2 = cv[2];
        const auto& cv3 = cv[3];
        test_assert(&cv0 == cv.data() + 0);
        test_assert(&cv1 == cv.data() + 1);
        test_assert(&cv2 == cv.data() + 2);
        test_assert(&cv3 == cv.data() + 3);

        auto v = cev;
        auto& v0 = v[0];
        auto& v1 = v[1];
        auto& v2 = v[2];
        auto& v3 = v[3];
        test_assert(&v0 == v.data() + 0);
        test_assert(&v1 == v.data() + 1);
        test_assert(&v2 == v.data() + 2);
        test_assert(&v3 == v.data() + 3);
    }

    TEST_CASE(data)
    {
        const dvec4 cv(1.2);
        const double* cdata = cv.data();
        test_assert(cdata == static_cast<const void*>(&cv));

        dvec4 v;
        double* data = v.data();
        test_assert(data == static_cast<void*>(&v));
    }

    TEST_CASE(x_y_z_w)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto x = v.x();
        CONST_OR_CONSTEXPR auto y = v.y();
        CONST_OR_CONSTEXPR auto z = v.z();
        CONST_OR_CONSTEXPR auto w = v.w();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
        test_assert(z == 5.6);
        test_assert(w == 7.8);
    }

    TEST_CASE(xy)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xy = v.xy();
        test_assert(xy == dvec2(1.2, 3.4));
    }

    TEST_CASE(xyz)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyz = v.xyz();
        test_assert(xyz == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(xyzw)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyzw = v.xyzw();
        test_assert(xyzw == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(set_x_y_z_w)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        v.set_x(9.10);
        v.set_y(11.12);
        v.set_z(13.14);
        v.set_w(15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);
    }

    TEST_CASE(set_xy)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_xy(9.10, 11.12);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);

        v.set_xy(dvec2(13.14, 15.16));
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_xyz)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_xyz(9.10, 11.12, 13.14);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 7.8);

        v.set_xyz(dvec2(15.16, 17.18), 19.20);
        test_assert(v[0] == 15.16);
        test_assert(v[1] == 17.18);
        test_assert(v[2] == 19.20);
        test_assert(v[3] == 7.8);

        v.set_xyz(dvec3(21.22, 23.24, 25.26));
        test_assert(v[0] == 21.22);
        test_assert(v[1] == 23.24);
        test_assert(v[2] == 25.26);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_xyzw)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_xyzw(9.10, 11.12, 13.14, 15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);

        v.set_xyzw(dvec2(17.18, 19.20), 21.22, 23.24);
        test_assert(v[0] == 17.18);
        test_assert(v[1] == 19.20);
        test_assert(v[2] == 21.22);
        test_assert(v[3] == 23.24);

        v.set_xyzw(dvec3(25.26, 27.28, 29.30), 31.32);
        test_assert(v[0] == 25.26);
        test_assert(v[1] == 27.28);
        test_assert(v[2] == 29.30);
        test_assert(v[3] == 31.32);

        v.set_xyzw(dvec4(33.34, 35.36, 37.38, 39.40));
        test_assert(v[0] == 33.34);
        test_assert(v[1] == 35.36);
        test_assert(v[2] == 37.38);
        test_assert(v[3] == 39.40);
    }

    TEST_CASE(r_g_b_a)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto r = v.r();
        CONST_OR_CONSTEXPR auto g = v.g();
        CONST_OR_CONSTEXPR auto b = v.b();
        CONST_OR_CONSTEXPR auto a = v.a();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
        test_assert(b == 5.6);
        test_assert(a == 7.8);
    }

    TEST_CASE(rg)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto rg = v.rg();
        test_assert(rg == dvec2(1.2, 3.4));
    }

    TEST_CASE(rgb)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto rgb = v.rgb();
        test_assert(rgb == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(rgba)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto rgba = v.rgba();
        test_assert(rgba == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(set_r_g_b_a)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        v.set_r(9.10);
        v.set_g(11.12);
        v.set_b(13.14);
        v.set_a(15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);
    }

    TEST_CASE(set_rg)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_rg(9.10, 11.12);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);

        v.set_rg(dvec2(13.14, 15.16));
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_rgb)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_rgb(9.10, 11.12, 13.14);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 7.8);

        v.set_rgb(dvec2(15.16, 17.18), 19.20);
        test_assert(v[0] == 15.16);
        test_assert(v[1] == 17.18);
        test_assert(v[2] == 19.20);
        test_assert(v[3] == 7.8);

        v.set_rgb(dvec3(21.22, 23.24, 25.26));
        test_assert(v[0] == 21.22);
        test_assert(v[1] == 23.24);
        test_assert(v[2] == 25.26);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_rgba)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);

        v.set_rgba(9.10, 11.12, 13.14, 15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);

        v.set_rgba(dvec2(17.18, 19.20), 21.22, 23.24);
        test_assert(v[0] == 17.18);
        test_assert(v[1] == 19.20);
        test_assert(v[2] == 21.22);
        test_assert(v[3] == 23.24);

        v.set_rgba(dvec3(25.26, 27.28, 29.30), 31.32);
        test_assert(v[0] == 25.26);
        test_assert(v[1] == 27.28);
        test_assert(v[2] == 29.30);
        test_assert(v[3] == 31.32);

        v.set_rgba(dvec4(33.34, 35.36, 37.38, 39.40));
        test_assert(v[0] == 33.34);
        test_assert(v[1] == 35.36);
        test_assert(v[2] == 37.38);
        test_assert(v[3] == 39.40);
    }

    TEST_CASE(pre_increment_operator)
    {
        ivec4 v(1, 2, 3, 4);
        test_assert(&(++v) == &v);
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
        test_assert(v[2] == 4);
        test_assert(v[3] == 5);
    }

    TEST_CASE(post_increment_operator)
    {
        ivec4 v(1, 2, 3, 4);
        test_assert(v++ == ivec4(1, 2, 3, 4));
        test_assert(v[0] == 2);
        test_assert(v[1] == 3);
        test_assert(v[2] == 4);
        test_assert(v[3] == 5);
    }

    TEST_CASE(pre_decrement_operator)
    {
        ivec4 v(1, 2, 3, 4);
        test_assert(&(--v) == &v);
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
        test_assert(v[2] == 2);
        test_assert(v[3] == 3);
    }

    TEST_CASE(post_decrement_operator)
    {
        ivec4 v(1, 2, 3, 4);
        test_assert(v-- == ivec4(1, 2, 3, 4));
        test_assert(v[0] == 0);
        test_assert(v[1] == 1);
        test_assert(v[2] == 2);
        test_assert(v[3] == 3);
    }

    TEST_CASE(addition_assignment_operator)
    {
        dvec4 v1(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v1 += 9) == &v1);
        test_assert(v1[0] == 1.2 + 9);
        test_assert(v1[1] == 3.4 + 9);
        test_assert(v1[2] == 5.6 + 9);
        test_assert(v1[3] == 7.8 + 9);

        dvec4 v2(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v2 += ivec4(9, 10, 11, 12)) == &v2);
        test_assert(v2[0] == 1.2 + 9);
        test_assert(v2[1] == 3.4 + 10);
        test_assert(v2[2] == 5.6 + 11);
        test_assert(v2[3] == 7.8 + 12);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        dvec4 v1(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v1 -= 9) == &v1);
        test_assert(v1[0] == 1.2 - 9);
        test_assert(v1[1] == 3.4 - 9);
        test_assert(v1[2] == 5.6 - 9);
        test_assert(v1[3] == 7.8 - 9);

        dvec4 v2(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v2 -= ivec4(9, 10, 11, 12)) == &v2);
        test_assert(v2[0] == 1.2 - 9);
        test_assert(v2[1] == 3.4 - 10);
        test_assert(v2[2] == 5.6 - 11);
        test_assert(v2[3] == 7.8 - 12);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        dvec4 v1(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v1 *= 9) == &v1);
        test_assert(v1[0] == 1.2 * 9);
        test_assert(v1[1] == 3.4 * 9);
        test_assert(v1[2] == 5.6 * 9);
        test_assert(v1[3] == 7.8 * 9);

        dvec4 v2(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v2 *= ivec4(9, 10, 11, 12)) == &v2);
        test_assert(v2[0] == 1.2 * 9);
        test_assert(v2[1] == 3.4 * 10);
        test_assert(v2[2] == 5.6 * 11);
        test_assert(v2[3] == 7.8 * 12);
    }

    TEST_CASE(mat_multiplication_assignment_operator)
    {
        const dvec4 v1(1.2, 3.4, 5.6, 7.8);
        const fmat4x4 m(9.10f);

        auto v2 = v1;
        test_assert(&(v2 *= m) == &v2);
        test_assert(v2 == v1 * m);
    }

    TEST_CASE(division_assignment_operator)
    {
        dvec4 v1(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v1 /= 9) == &v1);
        test_assert(v1[0] == 1.2 / 9);
        test_assert(v1[1] == 3.4 / 9);
        test_assert(v1[2] == 5.6 / 9);
        test_assert(v1[3] == 7.8 / 9);

        dvec4 v2(1.2, 3.4, 5.6, 7.8);
        test_assert(&(v2 /= ivec4(9, 10, 11, 12)) == &v2);
        test_assert(v2[0] == 1.2 / 9);
        test_assert(v2[1] == 3.4 / 10);
        test_assert(v2[2] == 5.6 / 11);
        test_assert(v2[3] == 7.8 / 12);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        vec4<long long> v1(10LL, 21LL, 32LL, 43LL);
        test_assert(&(v1 %= 9) == &v1);
        test_assert(v1[0] == 10LL % 9);
        test_assert(v1[1] == 21LL % 9);
        test_assert(v1[2] == 32LL % 9);
        test_assert(v1[3] == 43LL % 9);

        vec4<long long> v2(10LL, 21LL, 32LL, 43LL);
        test_assert(&(v2 %= ivec4(9, 8, 7, 5)) == &v2);
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 8);
        test_assert(v2[2] == 32LL % 7);
        test_assert(v2[3] == 43LL % 5);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        vec4<long long> v1(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v1 &= 910) == &v1);
        test_assert(v1[0] == (12LL & 910));
        test_assert(v1[1] == (34LL & 910));
        test_assert(v1[2] == (56LL & 910));
        test_assert(v1[3] == (78LL & 910));

        vec4<long long> v2(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v2 &= ivec4(910, 1112, 1314, 1516)) == &v2);
        test_assert(v2[0] == (12LL & 910));
        test_assert(v2[1] == (34LL & 1112));
        test_assert(v2[2] == (56LL & 1314));
        test_assert(v2[3] == (78LL & 1516));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        vec4<long long> v1(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v1 |= 910) == &v1);
        test_assert(v1[0] == (12LL | 910));
        test_assert(v1[1] == (34LL | 910));
        test_assert(v1[2] == (56LL | 910));
        test_assert(v1[3] == (78LL | 910));

        vec4<long long> v2(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v2 |= ivec4(910, 1112, 1314, 1516)) == &v2);
        test_assert(v2[0] == (12LL | 910));
        test_assert(v2[1] == (34LL | 1112));
        test_assert(v2[2] == (56LL | 1314));
        test_assert(v2[3] == (78LL | 1516));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        vec4<long long> v1(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v1 ^= 910) == &v1);
        test_assert(v1[0] == (12LL ^ 910));
        test_assert(v1[1] == (34LL ^ 910));
        test_assert(v1[2] == (56LL ^ 910));
        test_assert(v1[3] == (78LL ^ 910));

        vec4<long long> v2(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v2 ^= ivec4(910, 1112, 1314, 1516)) == &v2);
        test_assert(v2[0] == (12LL ^ 910));
        test_assert(v2[1] == (34LL ^ 1112));
        test_assert(v2[2] == (56LL ^ 1314));
        test_assert(v2[3] == (78LL ^ 1516));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        vec4<long long> v1(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v1 <<= 1) == &v1);
        test_assert(v1[0] == (12LL << 1));
        test_assert(v1[1] == (34LL << 1));
        test_assert(v1[2] == (56LL << 1));
        test_assert(v1[3] == (78LL << 1));

        vec4<long long> v2(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v2 <<= ivec4(1, 2, 3, 4)) == &v2);
        test_assert(v2[0] == (12LL << 1));
        test_assert(v2[1] == (34LL << 2));
        test_assert(v2[2] == (56LL << 3));
        test_assert(v2[3] == (78LL << 4));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        vec4<long long> v1(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v1 >>= 1) == &v1);
        test_assert(v1[0] == (12LL >> 1));
        test_assert(v1[1] == (34LL >> 1));
        test_assert(v1[2] == (56LL >> 1));
        test_assert(v1[3] == (78LL >> 1));

        vec4<long long> v2(12LL, 34LL, 56LL, 78LL);
        test_assert(&(v2 >>= ivec4(1, 2, 3, 4)) == &v2);
        test_assert(v2[0] == (12LL >> 1));
        test_assert(v2[1] == (34LL >> 2));
        test_assert(v2[2] == (56LL >> 3));
        test_assert(v2[3] == (78LL >> 4));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto v = +dvec4(1.2, 3.4, 5.6, 7.8);
        test_assert(v == dvec4(+1.2, +3.4, +5.6, +7.8));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto v = -dvec4(1.2, 3.4, 5.6, 7.8);
        test_assert(v == dvec4(-1.2, -3.4, -5.6, -7.8));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto v = ~ivec4(1, 2, 3, 4);
        test_assert(v == ivec4(~1, ~2, ~3, ~4));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 + dvec4(2.3, 4.5, 6.7, 8.9);
        test_assert(v1[0] == 1 + 2.3);
        test_assert(v1[1] == 1 + 4.5);
        test_assert(v1[2] == 1 + 6.7);
        test_assert(v1[3] == 1 + 8.9);

        CONST_OR_CONSTEXPR auto v2 =
            dvec4(1.2, 3.4, 5.6, 7.8) + 9;
        test_assert(v2[0] == 1.2 + 9);
        test_assert(v2[1] == 3.4 + 9);
        test_assert(v2[2] == 5.6 + 9);
        test_assert(v2[3] == 7.8 + 9);

        CONST_OR_CONSTEXPR auto v3 =
            dvec4(1.2, 3.4, 5.6, 7.8) + ivec4(9, 10, 11, 12);
        test_assert(v3[0] == 1.2 + 9);
        test_assert(v3[1] == 3.4 + 10);
        test_assert(v3[2] == 5.6 + 11);
        test_assert(v3[3] == 7.8 + 12);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 - dvec4(2.3, 4.5, 6.7, 8.9);
        test_assert(v1[0] == 1 - 2.3);
        test_assert(v1[1] == 1 - 4.5);
        test_assert(v1[2] == 1 - 6.7);
        test_assert(v1[3] == 1 - 8.9);

        CONST_OR_CONSTEXPR auto v2 =
            dvec4(1.2, 3.4, 5.6, 7.8) - 9;
        test_assert(v2[0] == 1.2 - 9);
        test_assert(v2[1] == 3.4 - 9);
        test_assert(v2[2] == 5.6 - 9);
        test_assert(v2[3] == 7.8 - 9);

        CONST_OR_CONSTEXPR auto v3 =
            dvec4(1.2, 3.4, 5.6, 7.8) - ivec4(9, 10, 11, 12);
        test_assert(v3[0] == 1.2 - 9);
        test_assert(v3[1] == 3.4 - 10);
        test_assert(v3[2] == 5.6 - 11);
        test_assert(v3[3] == 7.8 - 12);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            12 * dvec4(2.3, 4.5, 6.7, 8.9);
        test_assert(v1[0] == 12 * 2.3);
        test_assert(v1[1] == 12 * 4.5);
        test_assert(v1[2] == 12 * 6.7);
        test_assert(v1[3] == 12 * 8.9);

        CONST_OR_CONSTEXPR auto v2 =
            dvec4(1.2, 3.4, 5.6, 7.8) * 9;
        test_assert(v2[0] == 1.2 * 9);
        test_assert(v2[1] == 3.4 * 9);
        test_assert(v2[2] == 5.6 * 9);
        test_assert(v2[3] == 7.8 * 9);

        CONST_OR_CONSTEXPR auto v3 =
            dvec4(1.2, 3.4, 5.6, 7.8) * ivec4(9, 10, 11, 12);
        test_assert(v3[0] == 1.2 * 9);
        test_assert(v3[1] == 3.4 * 10);
        test_assert(v3[2] == 5.6 * 11);
        test_assert(v3[3] == 7.8 * 12);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 / dvec4(2.3, 4.5, 6.7, 8.9);
        test_assert(v1[0] == 1 / 2.3);
        test_assert(v1[1] == 1 / 4.5);
        test_assert(v1[2] == 1 / 6.7);
        test_assert(v1[3] == 1 / 8.9);

        CONST_OR_CONSTEXPR auto v2 =
            dvec4(1.2, 3.4, 5.6, 7.8) / 9;
        test_assert(v2[0] == 1.2 / 9);
        test_assert(v2[1] == 3.4 / 9);
        test_assert(v2[2] == 5.6 / 9);
        test_assert(v2[3] == 7.8 / 9);

        CONST_OR_CONSTEXPR auto v3 =
            dvec4(1.2, 3.4, 5.6, 7.8) / ivec4(9, 10, 11, 12);
        test_assert(v3[0] == 1.2 / 9);
        test_assert(v3[1] == 3.4 / 10);
        test_assert(v3[2] == 5.6 / 11);
        test_assert(v3[3] == 7.8 / 12);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            10 % vec4<long long>(9LL, 8LL, 7LL, 6LL);
        test_assert(v1[0] == 10 % 9LL);
        test_assert(v1[1] == 10 % 8LL);
        test_assert(v1[2] == 10 % 7LL);
        test_assert(v1[3] == 10 % 6LL);

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(10LL, 21LL, 32LL, 43LL) % 9;
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 9);
        test_assert(v2[2] == 32LL % 9);
        test_assert(v2[3] == 43LL % 9);

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(10LL, 21LL, 32LL, 43LL) % ivec4(9, 8, 7, 5);
        test_assert(v3[0] == 10LL % 9);
        test_assert(v3[1] == 21LL % 8);
        test_assert(v3[2] == 32LL % 7);
        test_assert(v3[3] == 43LL % 5);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 & vec4<long long>(23LL, 45LL, 67LL, 89LL);
        test_assert(v1[0] == (1 & 23LL));
        test_assert(v1[1] == (1 & 45LL));
        test_assert(v1[2] == (1 & 67LL));
        test_assert(v1[3] == (1 & 89LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL) & 9;
        test_assert(v2[0] == (12LL & 9));
        test_assert(v2[1] == (34LL & 9));
        test_assert(v2[2] == (56LL & 9));
        test_assert(v2[3] == (78LL & 9));

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL)
            & ivec4(910, 1112, 1314, 1516);
        test_assert(v3[0] == (12LL & 910));
        test_assert(v3[1] == (34LL & 1112));
        test_assert(v3[2] == (56LL & 1314));
        test_assert(v3[3] == (78LL & 1516));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 | vec4<long long>(23LL, 45LL, 67LL, 89LL);
        test_assert(v1[0] == (1 | 23LL));
        test_assert(v1[1] == (1 | 45LL));
        test_assert(v1[2] == (1 | 67LL));
        test_assert(v1[3] == (1 | 89LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL) | 9;
        test_assert(v2[0] == (12LL | 9));
        test_assert(v2[1] == (34LL | 9));
        test_assert(v2[2] == (56LL | 9));
        test_assert(v2[3] == (78LL | 9));

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL)
            | ivec4(910, 1112, 1314, 1516);
        test_assert(v3[0] == (12LL | 910));
        test_assert(v3[1] == (34LL | 1112));
        test_assert(v3[2] == (56LL | 1314));
        test_assert(v3[3] == (78LL | 1516));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 ^ vec4<long long>(23LL, 45LL, 67LL, 89LL);
        test_assert(v1[0] == (1 ^ 23LL));
        test_assert(v1[1] == (1 ^ 45LL));
        test_assert(v1[2] == (1 ^ 67LL));
        test_assert(v1[3] == (1 ^ 89LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL) ^ 9;
        test_assert(v2[0] == (12LL ^ 9));
        test_assert(v2[1] == (34LL ^ 9));
        test_assert(v2[2] == (56LL ^ 9));
        test_assert(v2[3] == (78LL ^ 9));

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(12LL, 34LL, 56LL, 78LL)
            ^ ivec4(910, 1112, 1314, 1516);
        test_assert(v3[0] == (12LL ^ 910));
        test_assert(v3[1] == (34LL ^ 1112));
        test_assert(v3[2] == (56LL ^ 1314));
        test_assert(v3[3] == (78LL ^ 1516));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            65 << vec4<long long>(4LL, 3LL, 2LL, 1LL);
        test_assert(v1[0] == (65 << 4LL));
        test_assert(v1[1] == (65 << 3LL));
        test_assert(v1[2] == (65 << 2LL));
        test_assert(v1[3] == (65 << 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(98LL, 76LL, 54LL, 32LL) << 1;
        test_assert(v2[0] == (98LL << 1));
        test_assert(v2[1] == (76LL << 1));
        test_assert(v2[2] == (54LL << 1));
        test_assert(v2[3] == (32LL << 1));

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(1211LL, 109LL, 87LL, 65LL) << ivec4(4, 3, 2, 1);
        test_assert(v3[0] == (1211LL << 4));
        test_assert(v3[1] == (109LL << 3));
        test_assert(v3[2] == (87LL << 2));
        test_assert(v3[3] == (65LL << 1));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            65 >> vec4<long long>(4LL, 3LL, 2LL, 1LL);
        test_assert(v1[0] == (65 >> 4LL));
        test_assert(v1[1] == (65 >> 3LL));
        test_assert(v1[2] == (65 >> 2LL));
        test_assert(v1[3] == (65 >> 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            vec4<long long>(98LL, 76LL, 54LL, 32LL) >> 1;
        test_assert(v2[0] == (98LL >> 1));
        test_assert(v2[1] == (76LL >> 1));
        test_assert(v2[2] == (54LL >> 1));
        test_assert(v2[3] == (32LL >> 1));

        CONST_OR_CONSTEXPR auto v3 =
            vec4<long long>(1211LL, 109LL, 87LL, 65LL) >> ivec4(4, 3, 2, 1);
        test_assert(v3[0] == (1211LL >> 4));
        test_assert(v3[1] == (109LL >> 3));
        test_assert(v3[2] == (87LL >> 2));
        test_assert(v3[3] == (65LL >> 1));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fvec4 v1(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v2(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v3(1.2f, 3.4f, 5.6f, 0.0f);
        CONST_OR_CONSTEXPR dvec4 v4(1.2f, 3.4f, 0.0f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v5(1.2f, 0.0f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v6(0.0f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR auto result1 = (v1 == v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 == v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 == v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 == v5);
        CONST_OR_CONSTEXPR auto result5 = (v1 == v6);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
        test_assert(result5 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fvec4 v1(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v2(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v3(1.2f, 3.4f, 5.6f, 0.0f);
        CONST_OR_CONSTEXPR dvec4 v4(1.2f, 3.4f, 0.0f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v5(1.2f, 0.0f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 v6(0.0f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR auto result1 = (v1 != v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 != v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 != v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 != v5);
        CONST_OR_CONSTEXPR auto result5 = (v1 != v6);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
        test_assert(result5 == true);
    }

    TEST_CASE(sin)
    {
        const auto v = math::sin(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::sin(1.2)));
        test_assert(nearly_equal(v[1], math::sin(3.4)));
        test_assert(nearly_equal(v[2], math::sin(5.6)));
        test_assert(nearly_equal(v[3], math::sin(7.8)));
    }

    TEST_CASE(cos)
    {
        const auto v = math::cos(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::cos(1.2)));
        test_assert(nearly_equal(v[1], math::cos(3.4)));
        test_assert(nearly_equal(v[2], math::cos(5.6)));
        test_assert(nearly_equal(v[3], math::cos(7.8)));
    }

    TEST_CASE(sincos)
    {
        dvec4 s, c;
        math::sincos(dvec4(1.2, 3.4, 5.6, 7.8), s, c);

        test_assert(nearly_equal(s[0], math::sin(1.2)));
        test_assert(nearly_equal(s[1], math::sin(3.4)));
        test_assert(nearly_equal(s[2], math::sin(5.6)));
        test_assert(nearly_equal(s[3], math::sin(7.8)));

        test_assert(nearly_equal(c[0], math::cos(1.2)));
        test_assert(nearly_equal(c[1], math::cos(3.4)));
        test_assert(nearly_equal(c[2], math::cos(5.6)));
        test_assert(nearly_equal(c[3], math::cos(7.8)));
    }

    TEST_CASE(exp)
    {
        const auto v = math::exp(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::exp(1.2)));
        test_assert(nearly_equal(v[1], math::exp(3.4)));
        test_assert(nearly_equal(v[2], math::exp(5.6)));
        test_assert(nearly_equal(v[3], math::exp(7.8)));
    }

    TEST_CASE(log)
    {
        const auto v = math::log(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::log(1.2)));
        test_assert(nearly_equal(v[1], math::log(3.4)));
        test_assert(nearly_equal(v[2], math::log(5.6)));
        test_assert(nearly_equal(v[3], math::log(7.8)));
    }

    TEST_CASE(abs)
    {
        const auto v = math::abs(dvec4(1.2, -3.4, 5.6, -7.8));
        test_assert(v[0] == math::abs(1.2));
        test_assert(v[1] == math::abs(-3.4));
        test_assert(v[2] == math::abs(5.6));
        test_assert(v[3] == math::abs(-7.8));
    }

    TEST_CASE(pow)
    {
        const auto v = math::pow(
            dvec4(1.2, 3.4, 5.6, 7.8), dvec4(9.10, 11.12, 13.14, 15.16));
        test_assert(nearly_equal(v[0], math::pow(1.2, 9.10)));
        test_assert(nearly_equal(v[1], math::pow(3.4, 11.12)));
        test_assert(nearly_equal(v[2], math::pow(5.6, 13.14)));
        test_assert(nearly_equal(v[3], math::pow(7.8, 15.16)));
    }

    TEST_CASE(recip)
    {
        const auto v = math::recip(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::recip(1.2)));
        test_assert(nearly_equal(v[1], math::recip(3.4)));
        test_assert(nearly_equal(v[2], math::recip(5.6)));
        test_assert(nearly_equal(v[3], math::recip(7.8)));
    }

    TEST_CASE(sqrt)
    {
        const auto v = math::sqrt(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::sqrt(1.2)));
        test_assert(nearly_equal(v[1], math::sqrt(3.4)));
        test_assert(nearly_equal(v[2], math::sqrt(5.6)));
        test_assert(nearly_equal(v[3], math::sqrt(7.8)));
    }

    TEST_CASE(rsqrt)
    {
        const auto v = math::rsqrt(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(v[0], math::rsqrt(1.2)));
        test_assert(nearly_equal(v[1], math::rsqrt(3.4)));
        test_assert(nearly_equal(v[2], math::rsqrt(5.6)));
        test_assert(nearly_equal(v[3], math::rsqrt(7.8)));
    }

    TEST_CASE(min)
    {
        const auto v = math::min(
            dvec4(1.2, 3.4, 5.6, 7.8), dvec4(9.10, -11.12, 13.14, -15.16));
        test_assert(v[0] == math::min(1.2, 9.10));
        test_assert(v[1] == math::min(3.4, -11.12));
        test_assert(v[2] == math::min(5.6, 13.14));
        test_assert(v[3] == math::min(7.8, -15.16));
    }

    TEST_CASE(max)
    {
        const auto v = math::max(
            dvec4(1.2, 3.4, 5.6, 7.8), dvec4(9.10, -11.12, 13.14, -15.16));
        test_assert(v[0] == math::max(1.2, 9.10));
        test_assert(v[1] == math::max(3.4, -11.12));
        test_assert(v[2] == math::max(5.6, 13.14));
        test_assert(v[3] == math::max(7.8, -15.16));
    }

    TEST_CASE(mask)
    {
        const auto v = math::mask(
            vec4<bool64>(true64, false64, true64, false64),
            dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(v == dvec4(1.2, 0.0, 5.6, 0.0));
    }

    TEST_CASE(select)
    {
        const auto v = math::select(
            vec4<bool64>(true64, false64, true64, false64),
            dvec4(1.2, 3.4, 5.6, 7.8),
            dvec4(9.10, 11.12, 13.14, 15.16));
        test_assert(v == dvec4(1.2, 11.12, 5.6, 15.16));
    }

    TEST_CASE(less)
    {
        const auto v = math::less(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(true64, false64, false64, false64));
    }

    TEST_CASE(less_equal)
    {
        const auto v = math::less_equal(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(true64, true64, false64, false64));
    }

    TEST_CASE(greater)
    {
        const auto v = math::greater(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(false64, false64, true64, true64));
    }

    TEST_CASE(greater_equal)
    {
        const auto v = math::greater_equal(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(false64, true64, true64, true64));
    }

    TEST_CASE(equal)
    {
        const auto v = math::equal(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(false64, true64, false64, false64));
    }

    TEST_CASE(not_equal)
    {
        const auto v = math::not_equal(
            dvec4(1.0, 2.0, 3.0, 4.0), dvec4(2.1, 2.0, 1.9, 1.8));
        test_assert(v == vec4<bool64>(true64, false64, true64, true64));
    }

    TEST_CASE(dot)
    {
        CONST_OR_CONSTEXPR auto x = math::dot(
            dvec4(1.2, 3.4, 5.6, 7.8), ivec4(9, 10, 11, 12));
        test_assert(nearly_equal(x, 1.2*9 + 3.4*10 + 5.6*11 + 7.8*12));
    }

    TEST_CASE(length)
    {
        test_assert(nearly_equal(
            math::length(dvec4(1.2, 3.4, 5.6, 7.8)),
            math::sqrt(math::length2(dvec4(1.2, 3.4, 5.6, 7.8)))));
    }

    TEST_CASE(length2)
    {
        CONST_OR_CONSTEXPR auto x = math::length2(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(nearly_equal(x, 1.2*1.2 + 3.4*3.4 + 5.6*5.6 + 7.8*7.8));
    }

    TEST_CASE(rlength)
    {
        test_assert(nearly_equal(
            math::rlength(dvec4(1.2, 3.4, 5.6, 7.8)),
            math::rsqrt(math::length2(dvec4(1.2, 3.4, 5.6, 7.8)))));
    }

    TEST_CASE(normalize)
    {
        const dvec4 v(1.2, 3.4, 5.6, 7.8);
        test_assert(math::normalize(v) == v * math::rlength(v));
    }
}
