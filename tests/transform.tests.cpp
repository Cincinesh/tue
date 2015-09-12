//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/transform.hpp>
#include <mon/test_case.hpp>

#include <tue/math.hpp>
#include <tue/quat.hpp>
#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(axis_angle_from_rotation_vec)
    {
        const auto aa1 = transform::axis_angle(1, 2, 3);
        test_assert(aa1.xyz() == math::normalize(ivec3(1, 2, 3)));
        test_assert(aa1.a() == math::length(ivec3(1, 2, 3)));

        const auto aa2 = transform::axis_angle(0, 0, 0);
        test_assert(aa2.xyz() == dvec3::z_axis());
        test_assert(aa2.a() == 0.0);

        const auto aa3 = transform::axis_angle(ivec3(1, 2, 3));
        test_assert(aa3 == aa1);

        const auto aa4 = transform::axis_angle(ivec3(0, 0, 0));
        test_assert(aa4 == aa2);
    }

    TEST_CASE(rotation_vec_from_axis_angle)
    {
        CONST_OR_CONSTEXPR auto rv1 =
            transform::rotation_vec(1.2, 3.4, 5.6, 7.8);
        test_assert(rv1 == dvec3(1.2, 3.4, 5.6) * 7.8);

        CONST_OR_CONSTEXPR auto rv2 =
            transform::rotation_vec(dvec3(1.2, 3.4, 5.6), 7.8);
        test_assert(rv2 == rv1);

        CONST_OR_CONSTEXPR auto rv3 =
            transform::rotation_vec(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(rv3 == rv1);
    }

    TEST_CASE(rotation_quat_from_axis_angle)
    {
        const auto rq1 = transform::rotation_quat(ivec3(1, 2, 3), 5);
        test_assert(rq1.v() == ivec3(1, 2, 3) * math::sin(5/2.0));
        test_assert(rq1.s() == math::cos(5/2.0));

        const auto rq2 = transform::rotation_quat(1, 2, 3, 5);
        test_assert(rq2 == rq1);

        const auto rq3 = transform::rotation_quat(ivec4(1, 2, 3, 5));
        test_assert(rq3 == rq1);
    }

    TEST_CASE(rotation_quat_from_rotation_vec)
    {
        const auto rq1 = transform::rotation_quat(1, 2, 3);
        test_assert(rq1 ==
            transform::rotation_quat(transform::axis_angle(1, 2, 3)));

        const auto rq2 = transform::rotation_quat(0, 0, 0);
        test_assert(rq2 == dquat::identity());

        const auto rq3 = transform::rotation_quat(ivec3(1, 2, 3));
        test_assert(rq3 == rq1);

        const auto rq4 = transform::rotation_quat(ivec3(0, 0, 0));
        test_assert(rq4 == rq2);
    }

    TEST_CASE(translation_mat_2d)
    {
        CONST_OR_CONSTEXPR auto m1 =
            transform::translation_mat(1.2, 3.4);
        test_assert(m1[0] == dvec4(1.0, 0.0, 0.0, 1.2));
        test_assert(m1[1] == dvec4(0.0, 1.0, 0.0, 3.4));
        test_assert(m1[2] == dvec4(0.0, 0.0, 1.0, 0.0));
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m2 =
            transform::translation_mat<double, 2, 3>(1.2, 3.4);
        test_assert(m2[0] == dvec3(1.0, 0.0, 1.2));
        test_assert(m2[1] == dvec3(0.0, 1.0, 3.4));

        CONST_OR_CONSTEXPR auto m3 =
            transform::translation_mat(dvec2(1.2, 3.4));
        test_assert(m3 == m1);

        CONST_OR_CONSTEXPR auto m4 =
            transform::translation_mat<double, 2, 3>(dvec2(1.2, 3.4));
        test_assert(m4 == m2);
    }

    TEST_CASE(translation_mat_3d)
    {
        CONST_OR_CONSTEXPR auto m1 =
            transform::translation_mat(1.2, 3.4, 5.6);
        test_assert(m1[0] == dvec4(1.0, 0.0, 0.0, 1.2));
        test_assert(m1[1] == dvec4(0.0, 1.0, 0.0, 3.4));
        test_assert(m1[2] == dvec4(0.0, 0.0, 1.0, 5.6));
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m2 =
            transform::translation_mat<double, 3, 4>(1.2, 3.4, 5.6);
        test_assert(m2 == dmat3x4(m1));

        CONST_OR_CONSTEXPR auto m3 =
            transform::translation_mat(dvec3(1.2, 3.4, 5.6));
        test_assert(m3 == m1);

        CONST_OR_CONSTEXPR auto m4 =
            transform::translation_mat<double, 3, 4>(dvec3(1.2, 3.4, 5.6));
        test_assert(m4 == m2);
    }

    TEST_CASE(rotation_mat_2d)
    {
        const auto m1 = transform::rotation_mat(12);
        test_assert(m1[0] == dvec4(math::cos(12), -math::sin(12), 0.0, 0.0));
        test_assert(m1[1] == dvec4(math::sin(12),  math::cos(12), 0.0, 0.0));
        test_assert(m1[2] == dvec4(          0.0,            0.0, 1.0, 0.0));
        test_assert(m1[3] == dvec4(          0.0,            0.0, 0.0, 1.0));

        const auto m2 = transform::rotation_mat<int, 2, 2>(12);
        test_assert(m2 == dmat2x2(m1));
    }

    TEST_CASE(rotation_mat_from_axis_angle)
    {
        double s, c;
        math::sincos(78, s, c);

        const auto m1 = transform::rotation_mat(
            12, 34, 56, 78);
        test_assert(m1[0][0] == 12*12*(1-c) + c);
        test_assert(m1[0][1] == 12*34*(1-c) - 56*s);
        test_assert(m1[0][2] == 12*56*(1-c) + 34*s);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 12*34*(1-c) + 56*s);
        test_assert(m1[1][1] == 34*34*(1-c) + c);
        test_assert(m1[1][2] == 34*56*(1-c) - 12*s);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 12*56*(1-c) - 34*s);
        test_assert(m1[2][1] == 34*56*(1-c) + 12*s);
        test_assert(m1[2][2] == 56*56*(1-c) + c);
        test_assert(m1[2][3] == 0.0);
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        const auto m2 = transform::rotation_mat<int, 3, 3>(
            12, 34, 56, 78);
        test_assert(m2 == dmat3x3(m1));

        const auto m3 = transform::rotation_mat(
            ivec3(12, 34, 56), 78);
        test_assert(m3 == m1);

        const auto m4 = transform::rotation_mat<int, 3, 3>(
            ivec3(12, 34, 56), 78);
        test_assert(m4 == m2);

        const auto m5 = transform::rotation_mat(
            ivec4(12, 34, 56, 78));
        test_assert(m5 == m1);

        const auto m6 = transform::rotation_mat<int, 3, 3>(
            ivec4(12, 34, 56, 78));
        test_assert(m6 == m2);
    }

    TEST_CASE(rotation_mat_from_rotation_vec)
    {
        const auto m1 = transform::rotation_mat(12, 34, 56);
        test_assert(m1 ==
            transform::rotation_mat(transform::axis_angle(12, 34, 56)));

        const auto m2 = transform::rotation_mat<int, 3, 3>(12, 34, 56);
        test_assert(m2 == dmat3x3(m1));

        const auto m3 = transform::rotation_mat(ivec3(12, 34, 56));
        test_assert(m3 == m1);

        const auto m4 = transform::rotation_mat<int, 3, 3>(ivec3(12, 34, 56));
        test_assert(m4 == m2);
    }

    TEST_CASE(rotation_mat_from_rotation_quat)
    {
        CONST_OR_CONSTEXPR auto x = 1.2, y = 3.4, z = 5.6, w = 7.8;
        CONST_OR_CONSTEXPR auto m1 =
            transform::rotation_mat(dquat(x, y, z, w));
        test_assert(m1[0][0] == 1 - 2*y*y - 2*z*z);
        test_assert(m1[0][1] == 2*x*y - 2*z*w);
        test_assert(m1[0][2] == 2*x*z + 2*y*w);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 2*x*y + 2*z*w);
        test_assert(m1[1][1] == 1 - 2*x*x - 2*z*z);
        test_assert(m1[1][2] == 2*y*z - 2*x*w);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 2*x*z - 2*y*w);
        test_assert(m1[2][1] == 2*y*z + 2*x*w);
        test_assert(m1[2][2] == 1 - 2*x*x - 2*y*y);
        test_assert(m1[2][3] == 0.0);
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m2 =
            transform::rotation_mat<double, 3, 3>(dquat(x, y, z, w));
        test_assert(m2 == dmat3x3(m1));
    }

    TEST_CASE(scale_mat_2d)
    {
        CONST_OR_CONSTEXPR auto m1 =
            transform::scale_mat(1.2, 3.4);
        test_assert(m1[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m1[1] == dvec4(0.0, 3.4, 0.0, 0.0));
        test_assert(m1[2] == dvec4(0.0, 0.0, 1.0, 0.0));
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m2 =
            transform::scale_mat<double, 2, 2>(1.2, 3.4);
        test_assert(m2 == dmat2x2(m2));

        CONST_OR_CONSTEXPR auto m3 =
            transform::scale_mat(dvec2(1.2, 3.4));
        test_assert(m3 == m1);

        CONST_OR_CONSTEXPR auto m4 =
            transform::scale_mat<double, 2, 2>(dvec2(1.2, 3.4));
        test_assert(m4 == m2);
    }

    TEST_CASE(scale_mat_3d)
    {
        CONST_OR_CONSTEXPR auto m1 =
            transform::scale_mat(1.2, 3.4, 5.6);
        test_assert(m1[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m1[1] == dvec4(0.0, 3.4, 0.0, 0.0));
        test_assert(m1[2] == dvec4(0.0, 0.0, 5.6, 0.0));
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m2 =
            transform::scale_mat<double, 3, 3>(1.2, 3.4, 5.6);
        test_assert(m2 == dmat3x3(m1));

        CONST_OR_CONSTEXPR auto m3 =
            transform::scale_mat(dvec3(1.2, 3.4, 5.6));
        test_assert(m3 == m1);

        CONST_OR_CONSTEXPR auto m4 =
            transform::scale_mat<double, 3, 3>(dvec3(1.2, 3.4, 5.6));
        test_assert(m4 == m2);
    }

    TEST_CASE(perspective_mat)
    {
        const auto m1 = transform::perspective_mat(1, 3, 5, 7);
        test_assert(m1[0][0] == math::cos(1 / 2.0) / math::sin(1 / 2.0) / 3);
        test_assert(m1[0][1] == 0.0);
        test_assert(m1[0][2] == 0.0);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 0.0);
        test_assert(m1[1][1] == math::cos(1 / 2.0) / math::sin(1 / 2.0));
        test_assert(m1[1][2] == 0.0);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 0.0);
        test_assert(m1[2][1] == 0.0);
        test_assert(m1[2][2] == double(5+7) / double(5-7));
        test_assert(m1[2][3] == 2.0 * double(5*7) / double(5-7));
        test_assert(m1[3][0] == 0.0);
        test_assert(m1[3][1] == 0.0);
        test_assert(m1[3][2] == -1.0);
        test_assert(m1[3][3] == 0.0);

        const auto m2 = transform::perspective_mat<int, 4, 4>(1, 3, 5, 7);
        test_assert(m2 == m1);
    }

    TEST_CASE(ortho_mat)
    {
        CONST_OR_CONSTEXPR auto m1 = transform::ortho_mat(3, 5, 7, 9);
        test_assert(m1[0][0] == 2.0 / 3);
        test_assert(m1[0][1] == 0.0);
        test_assert(m1[0][2] == 0.0);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 0.0);
        test_assert(m1[1][1] == 2.0 / 5);
        test_assert(m1[1][2] == 0.0);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 0.0);
        test_assert(m1[2][1] == 0.0);
        test_assert(m1[2][2] == (2.0) / (7-9));
        test_assert(m1[2][3] == (7+9) / (7-9));
        test_assert(m1[3][0] == 0.0);
        test_assert(m1[3][1] == 0.0);
        test_assert(m1[3][2] == 0.0);
        test_assert(m1[3][3] == 1.0);

        const auto m2 = transform::ortho_mat<int, 3, 4>(3, 5, 7, 9);
        test_assert(m2 == dmat3x4(m2));
    }
}
