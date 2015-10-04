//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/transform.hpp>
#include "tue.tests.hpp"

#include <tue/math.hpp>
#include <tue/quat.hpp>
#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(axis_angle_from_rotation_vec)
    {
        const auto aa1 = transform::axis_angle(1.2, 3.4, 5.6);
        test_assert(aa1.xyz() == math::normalize(dvec3(1.2, 3.4, 5.6)));
        test_assert(aa1.a() == math::length(dvec3(1.2, 3.4, 5.6)));

        const auto aa2 = transform::axis_angle(0.0, 0.0, 0.0);
        test_assert(aa2.xyz() == dvec3::z_axis());
        test_assert(aa2.a() == 0.0);

        const auto aa3 = transform::axis_angle(dvec3(1.2, 3.4, 5.6));
        test_assert(aa3 == aa1);

        const auto aa4 = transform::axis_angle(dvec3(0.0, 0.0, 0.0));
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
        const auto rq1 = transform::rotation_quat(dvec3(1.2, 3.4, 5.6), 7.8);
        test_assert(rq1.v() == dvec3(1.2, 3.4, 5.6) * math::sin(7.8/2));
        test_assert(rq1.s() == math::cos(7.8/2));

        const auto rq2 = transform::rotation_quat(1.2, 3.4, 5.6, 7.8);
        test_assert(rq2 == rq1);

        const auto rq3 = transform::rotation_quat(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(rq3 == rq1);
    }

    TEST_CASE(rotation_quat_from_rotation_vec)
    {
        const auto rq1 = transform::rotation_quat(1.2, 3.4, 5.6);
        test_assert(rq1 ==
            transform::rotation_quat(transform::axis_angle(1.2, 3.4, 5.6)));

        const auto rq2 = transform::rotation_quat(0.0, 0.0, 0.0);
        test_assert(rq2 == dquat::identity());

        const auto rq3 = transform::rotation_quat(dvec3(1.2, 3.4, 5.6));
        test_assert(rq3 == rq1);

        const auto rq4 = transform::rotation_quat(dvec3(0.0, 0.0, 0.0));
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
        const auto m1 = transform::rotation_mat(1.2);
        test_assert(m1[0] == dvec4(math::cos(1.2), -math::sin(1.2), 0.0, 0.0));
        test_assert(m1[1] == dvec4(math::sin(1.2),  math::cos(1.2), 0.0, 0.0));
        test_assert(m1[2] == dvec4(          0.0 ,            0.0 , 1.0, 0.0));
        test_assert(m1[3] == dvec4(          0.0 ,            0.0 , 0.0, 1.0));

        const auto m2 = transform::rotation_mat<double, 2, 2>(1.2);
        test_assert(m2 == dmat2x2(m1));
    }

    TEST_CASE(rotation_mat_from_axis_angle)
    {
        double s, c;
        math::sincos(7.8, s, c);

        const auto m1 = transform::rotation_mat(1.2, 3.4, 5.6, 7.8);
        test_assert(nearly_equal(m1[0][0], 1.2*1.2*(1-c) + c));
        test_assert(nearly_equal(m1[0][1], 1.2*3.4*(1-c) - 5.6*s));
        test_assert(nearly_equal(m1[0][2], 1.2*5.6*(1-c) + 3.4*s));
        test_assert(nearly_equal(m1[0][3], 0.0));
        test_assert(nearly_equal(m1[1][0], 1.2*3.4*(1-c) + 5.6*s));
        test_assert(nearly_equal(m1[1][1], 3.4*3.4*(1-c) + c));
        test_assert(nearly_equal(m1[1][2], 3.4*5.6*(1-c) - 1.2*s));
        test_assert(nearly_equal(m1[1][3], 0.0));
        test_assert(nearly_equal(m1[2][0], 1.2*5.6*(1-c) - 3.4*s));
        test_assert(nearly_equal(m1[2][1], 3.4*5.6*(1-c) + 1.2*s));
        test_assert(nearly_equal(m1[2][2], 5.6*5.6*(1-c) + c));
        test_assert(nearly_equal(m1[2][3], 0.0));
        test_assert(m1[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        const auto m2 = transform::rotation_mat<double, 3, 3>(
            1.2, 3.4, 5.6, 7.8);
        test_assert(m2 == dmat3x3(m1));

        const auto m3 = transform::rotation_mat(
            dvec3(1.2, 3.4, 5.6), 7.8);
        test_assert(m3 == m1);

        const auto m4 = transform::rotation_mat<double, 3, 3>(
            dvec3(1.2, 3.4, 5.6), 7.8);
        test_assert(m4 == m2);

        const auto m5 = transform::rotation_mat(
            dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m5 == m1);

        const auto m6 = transform::rotation_mat<double, 3, 3>(
            dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m6 == m2);
    }

    TEST_CASE(rotation_mat_from_rotation_vec)
    {
        const auto m1 = transform::rotation_mat(
            1.2, 3.4, 5.6);
        test_assert(m1 ==
            transform::rotation_mat(transform::axis_angle(1.2, 3.4, 5.6)));

        const auto m2 = transform::rotation_mat<double, 3, 3>(
            1.2, 3.4, 5.6);
        test_assert(m2 == dmat3x3(m1));

        const auto m3 = transform::rotation_mat(
            dvec3(1.2, 3.4, 5.6));
        test_assert(m3 == m1);

        const auto m4 = transform::rotation_mat<double, 3, 3>(
            dvec3(1.2, 3.4, 5.6));
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
        const auto m1 = transform::perspective_mat(1.2, 3.4, 5.6, 7.8);
        test_assert(nearly_equal(
            m1[0][0], math::cos(1.2/2) / math::sin(1.2/2) / 3.4));
        test_assert(m1[0][1] == 0.0);
        test_assert(m1[0][2] == 0.0);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 0.0);
        test_assert(nearly_equal(
            m1[1][1], math::cos(1.2/2) / math::sin(1.2/2)));
        test_assert(m1[1][2] == 0.0);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 0.0);
        test_assert(m1[2][1] == 0.0);
        test_assert(m1[2][2] ==     (5.6+7.8) / (5.6-7.8));
        test_assert(m1[2][3] == 2 * (5.6*7.8) / (5.6-7.8));
        test_assert(m1[3][0] == 0.0);
        test_assert(m1[3][1] == 0.0);
        test_assert(m1[3][2] == -1.0);
        test_assert(m1[3][3] == 0.0);

        const auto m2 = transform::perspective_mat<double, 4, 4>(
            1.2, 3.4, 5.6, 7.8);
        test_assert(m2 == m1);
    }

    TEST_CASE(ortho_mat)
    {
        CONST_OR_CONSTEXPR auto m1 = transform::ortho_mat(1.2, 3.4, 5.6, 7.8);
        test_assert(m1[0][0] == 2 / 1.2);
        test_assert(m1[0][1] == 0.0);
        test_assert(m1[0][2] == 0.0);
        test_assert(m1[0][3] == 0.0);
        test_assert(m1[1][0] == 0.0);
        test_assert(m1[1][1] == 2 / 3.4);
        test_assert(m1[1][2] == 0.0);
        test_assert(m1[1][3] == 0.0);
        test_assert(m1[2][0] == 0.0);
        test_assert(m1[2][1] == 0.0);
        test_assert(m1[2][2] ==        2  / (5.6-7.8));
        test_assert(m1[2][3] == (5.6+7.8) / (5.6-7.8));
        test_assert(m1[3][0] == 0.0);
        test_assert(m1[3][1] == 0.0);
        test_assert(m1[3][2] == 0.0);
        test_assert(m1[3][3] == 1.0);

        const auto m2 = transform::ortho_mat<double, 3, 4>(1.2, 3.4, 5.6, 7.8);
        test_assert(m2 == dmat3x4(m2));
    }
}
