//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/mat.hpp>
#include "tue.tests.hpp"

#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    CONST_OR_CONSTEXPR fmat4x4 fm44 = {
        { 11.1f, 11.2f, 11.3f, 11.4f },
        { 12.1f, 12.2f, 12.3f, 12.4f },
        { 13.1f, 13.2f, 13.3f, 13.4f },
        { 14.1f, 14.2f, 14.3f, 14.4f },
    };

    CONST_OR_CONSTEXPR fmat4x3 fm43(fm44);
    CONST_OR_CONSTEXPR fmat4x2 fm42(fm44);
    CONST_OR_CONSTEXPR fmat3x4 fm34(fm44);
    CONST_OR_CONSTEXPR fmat3x3 fm33(fm44);
    CONST_OR_CONSTEXPR fmat3x2 fm32(fm44);
    CONST_OR_CONSTEXPR fmat2x4 fm24(fm44);
    CONST_OR_CONSTEXPR fmat2x3 fm23(fm44);
    CONST_OR_CONSTEXPR fmat2x2 fm22(fm44);

    CONST_OR_CONSTEXPR dmat4x4 dm44 = {
        { 21.1, 21.2, 21.3, 21.4 },
        { 22.1, 22.2, 22.3, 22.4 },
        { 23.1, 23.2, 23.3, 23.4 },
        { 24.1, 24.2, 24.3, 24.4 },
    };

    CONST_OR_CONSTEXPR dmat4x3 dm43(dm44);
    CONST_OR_CONSTEXPR dmat4x2 dm42(dm44);
    CONST_OR_CONSTEXPR dmat3x4 dm34(dm44);
    CONST_OR_CONSTEXPR dmat3x3 dm33(dm44);
    CONST_OR_CONSTEXPR dmat3x2 dm32(dm44);
    CONST_OR_CONSTEXPR dmat2x4 dm24(dm44);
    CONST_OR_CONSTEXPR dmat2x3 dm23(dm44);
    CONST_OR_CONSTEXPR dmat2x2 dm22(dm44);

    CONST_OR_CONSTEXPR fvec4 fv4(11.1f, 11.2f, 11.3f, 11.4f);
    CONST_OR_CONSTEXPR fvec3 fv3(fv4);
    CONST_OR_CONSTEXPR fvec2 fv2(fv4);

    CONST_OR_CONSTEXPR dvec4 dv4(21.1, 21.2, 21.3, 21.4);
    CONST_OR_CONSTEXPR dvec3 dv3(dv4);
    CONST_OR_CONSTEXPR dvec2 dv2(dv4);

    TEST_CASE(vec2_times_mat2x2)
    {
        CONST_OR_CONSTEXPR auto v = fv2 * dm22;
        test_assert(nearly_equal(v[0], math::dot(fv2, dm22[0])));
        test_assert(nearly_equal(v[1], math::dot(fv2, dm22[1])));
    }

    TEST_CASE(vec2_times_mat3x2)
    {
        CONST_OR_CONSTEXPR auto v = fv2 * dm32;
        test_assert(nearly_equal(v[0], math::dot(fv2, dm32[0])));
        test_assert(nearly_equal(v[1], math::dot(fv2, dm32[1])));
        test_assert(nearly_equal(v[2], math::dot(fv2, dm32[2])));
    }

    TEST_CASE(vec2_times_mat4x2)
    {
        CONST_OR_CONSTEXPR auto v = fv2 * dm42;
        test_assert(nearly_equal(v[0], math::dot(fv2, dm42[0])));
        test_assert(nearly_equal(v[1], math::dot(fv2, dm42[1])));
        test_assert(nearly_equal(v[2], math::dot(fv2, dm42[2])));
        test_assert(nearly_equal(v[3], math::dot(fv2, dm42[3])));
    }

    TEST_CASE(vec3_times_mat2x3)
    {
        CONST_OR_CONSTEXPR auto v = fv3 * dm23;
        test_assert(nearly_equal(v[0], math::dot(fv3, dm23[0])));
        test_assert(nearly_equal(v[1], math::dot(fv3, dm23[1])));
    }

    TEST_CASE(vec3_times_mat3x3)
    {
        CONST_OR_CONSTEXPR auto v = fv3 * dm33;
        test_assert(nearly_equal(v[0], math::dot(fv3, dm33[0])));
        test_assert(nearly_equal(v[1], math::dot(fv3, dm33[1])));
        test_assert(nearly_equal(v[2], math::dot(fv3, dm33[2])));
    }

    TEST_CASE(vec3_times_mat4x3)
    {
        CONST_OR_CONSTEXPR auto v = fv3 * dm43;
        test_assert(nearly_equal(v[0], math::dot(fv3, dm43[0])));
        test_assert(nearly_equal(v[1], math::dot(fv3, dm43[1])));
        test_assert(nearly_equal(v[2], math::dot(fv3, dm43[2])));
        test_assert(nearly_equal(v[3], math::dot(fv3, dm43[3])));
    }

    TEST_CASE(vec4_times_mat2x4)
    {
        CONST_OR_CONSTEXPR auto v = fv4 * dm24;
        test_assert(nearly_equal(v[0], math::dot(fv4, dm24[0])));
        test_assert(nearly_equal(v[1], math::dot(fv4, dm24[1])));
    }

    TEST_CASE(vec4_times_mat3x4)
    {
        CONST_OR_CONSTEXPR auto v = fv4 * dm34;
        test_assert(nearly_equal(v[0], math::dot(fv4, dm34[0])));
        test_assert(nearly_equal(v[1], math::dot(fv4, dm34[1])));
        test_assert(nearly_equal(v[2], math::dot(fv4, dm34[2])));
    }

    TEST_CASE(vec4_times_mat4x4)
    {
        CONST_OR_CONSTEXPR auto v = fv4 * dm44;
        test_assert(nearly_equal(v[0], math::dot(fv4, dm44[0])));
        test_assert(nearly_equal(v[1], math::dot(fv4, dm44[1])));
        test_assert(nearly_equal(v[2], math::dot(fv4, dm44[2])));
        test_assert(nearly_equal(v[3], math::dot(fv4, dm44[3])));
    }

    TEST_CASE(mat2x2_times_vec2)
    {
        CONST_OR_CONSTEXPR auto v = fm22 * dv2;
        test_assert(nearly_equal(v[0], math::dot(fm22.row(0), dv2)));
        test_assert(nearly_equal(v[1], math::dot(fm22.row(1), dv2)));
    }

    TEST_CASE(mat2x2_times_mat2x2)
    {
        CONST_OR_CONSTEXPR auto m = fm22 * dm22;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm22.row(0), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm22.row(1), dm22.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm22.row(0), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm22.row(1), dm22.column(1))));
    }

    TEST_CASE(mat2x2_times_mat3x2)
    {
        CONST_OR_CONSTEXPR auto m = fm22 * dm32;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm22.row(0), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm22.row(1), dm32.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm22.row(0), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm22.row(1), dm32.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm22.row(0), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm22.row(1), dm32.column(2))));
    }

    TEST_CASE(mat2x2_times_mat4x2)
    {
        CONST_OR_CONSTEXPR auto m = fm22 * dm42;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm22.row(0), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm22.row(1), dm42.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm22.row(0), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm22.row(1), dm42.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm22.row(0), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm22.row(1), dm42.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm22.row(0), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm22.row(1), dm42.column(3))));
    }

    TEST_CASE(mat2x3_times_vec2)
    {
        CONST_OR_CONSTEXPR auto v = fm23 * dv2;
        test_assert(nearly_equal(v[0], math::dot(fm23.row(0), dv2)));
        test_assert(nearly_equal(v[1], math::dot(fm23.row(1), dv2)));
        test_assert(nearly_equal(v[2], math::dot(fm23.row(2), dv2)));
    }

    TEST_CASE(mat2x3_times_mat2x2)
    {
        CONST_OR_CONSTEXPR auto m = fm23 * dm22;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm23.row(0), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm23.row(1), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm23.row(2), dm22.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm23.row(0), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm23.row(1), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm23.row(2), dm22.column(1))));
    }

    TEST_CASE(mat2x3_times_mat3x2)
    {
        CONST_OR_CONSTEXPR auto m = fm23 * dm32;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm23.row(0), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm23.row(1), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm23.row(2), dm32.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm23.row(0), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm23.row(1), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm23.row(2), dm32.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm23.row(0), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm23.row(1), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm23.row(2), dm32.column(2))));
    }

    TEST_CASE(mat2x3_times_mat4x2)
    {
        CONST_OR_CONSTEXPR auto m = fm23 * dm42;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm23.row(0), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm23.row(1), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm23.row(2), dm42.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm23.row(0), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm23.row(1), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm23.row(2), dm42.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm23.row(0), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm23.row(1), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm23.row(2), dm42.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm23.row(0), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm23.row(1), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm23.row(2), dm42.column(3))));
    }

    TEST_CASE(mat2x4_times_vec2)
    {
        CONST_OR_CONSTEXPR auto v = fm24 * dv2;
        test_assert(nearly_equal(v[0], math::dot(fm24.row(0), dv2)));
        test_assert(nearly_equal(v[1], math::dot(fm24.row(1), dv2)));
        test_assert(nearly_equal(v[2], math::dot(fm24.row(2), dv2)));
        test_assert(nearly_equal(v[3], math::dot(fm24.row(3), dv2)));
    }

    TEST_CASE(mat2x4_times_mat2x2)
    {
        CONST_OR_CONSTEXPR auto m = fm24 * dm22;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm24.row(0), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm24.row(1), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm24.row(2), dm22.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm24.row(3), dm22.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm24.row(0), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm24.row(1), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm24.row(2), dm22.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm24.row(3), dm22.column(1))));
    }

    TEST_CASE(mat2x4_times_mat3x2)
    {
        CONST_OR_CONSTEXPR auto m = fm24 * dm32;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm24.row(0), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm24.row(1), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm24.row(2), dm32.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm24.row(3), dm32.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm24.row(0), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm24.row(1), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm24.row(2), dm32.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm24.row(3), dm32.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm24.row(0), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm24.row(1), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm24.row(2), dm32.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm24.row(3), dm32.column(2))));
    }

    TEST_CASE(mat2x4_times_mat4x2)
    {
        CONST_OR_CONSTEXPR auto m = fm24 * dm42;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm24.row(0), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm24.row(1), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm24.row(2), dm42.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm24.row(3), dm42.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm24.row(0), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm24.row(1), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm24.row(2), dm42.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm24.row(3), dm42.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm24.row(0), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm24.row(1), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm24.row(2), dm42.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm24.row(3), dm42.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm24.row(0), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm24.row(1), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm24.row(2), dm42.column(3))));
        test_assert(nearly_equal(
            m[3][3], math::dot(fm24.row(3), dm42.column(3))));
    }

    TEST_CASE(mat3x2_times_vec3)
    {
        CONST_OR_CONSTEXPR auto v = fm32 * dv3;
        test_assert(nearly_equal(v[0], math::dot(fm32.row(0), dv3)));
        test_assert(nearly_equal(v[1], math::dot(fm32.row(1), dv3)));
    }

    TEST_CASE(mat3x2_times_mat2x3)
    {
        CONST_OR_CONSTEXPR auto m = fm32 * dm23;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm32.row(0), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm32.row(1), dm23.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm32.row(0), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm32.row(1), dm23.column(1))));
    }

    TEST_CASE(mat3x2_times_mat3x3)
    {
        CONST_OR_CONSTEXPR auto m = fm32 * dm33;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm32.row(0), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm32.row(1), dm33.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm32.row(0), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm32.row(1), dm33.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm32.row(0), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm32.row(1), dm33.column(2))));
    }

    TEST_CASE(mat3x2_times_mat4x3)
    {
        CONST_OR_CONSTEXPR auto m = fm32 * dm43;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm32.row(0), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm32.row(1), dm43.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm32.row(0), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm32.row(1), dm43.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm32.row(0), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm32.row(1), dm43.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm32.row(0), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm32.row(1), dm43.column(3))));
    }

    TEST_CASE(mat3x3_times_vec3)
    {
        CONST_OR_CONSTEXPR auto v = fm33 * dv3;
        test_assert(nearly_equal(v[0], math::dot(fm33.row(0), dv3)));
        test_assert(nearly_equal(v[1], math::dot(fm33.row(1), dv3)));
        test_assert(nearly_equal(v[2], math::dot(fm33.row(2), dv3)));
    }

    TEST_CASE(mat3x3_times_mat2x3)
    {
        CONST_OR_CONSTEXPR auto m = fm33 * dm23;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm33.row(0), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm33.row(1), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm33.row(2), dm23.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm33.row(0), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm33.row(1), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm33.row(2), dm23.column(1))));
    }

    TEST_CASE(mat3x3_times_mat3x3)
    {
        CONST_OR_CONSTEXPR auto m = fm33 * dm33;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm33.row(0), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm33.row(1), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm33.row(2), dm33.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm33.row(0), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm33.row(1), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm33.row(2), dm33.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm33.row(0), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm33.row(1), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm33.row(2), dm33.column(2))));
    }

    TEST_CASE(mat3x3_times_mat4x3)
    {
        CONST_OR_CONSTEXPR auto m = fm33 * dm43;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm33.row(0), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm33.row(1), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm33.row(2), dm43.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm33.row(0), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm33.row(1), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm33.row(2), dm43.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm33.row(0), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm33.row(1), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm33.row(2), dm43.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm33.row(0), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm33.row(1), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm33.row(2), dm43.column(3))));
    }

    TEST_CASE(mat3x4_times_vec3)
    {
        CONST_OR_CONSTEXPR auto v = fm34 * dv3;
        test_assert(nearly_equal(v[0], math::dot(fm34.row(0), dv3)));
        test_assert(nearly_equal(v[1], math::dot(fm34.row(1), dv3)));
        test_assert(nearly_equal(v[2], math::dot(fm34.row(2), dv3)));
        test_assert(nearly_equal(v[3], math::dot(fm34.row(3), dv3)));
    }

    TEST_CASE(mat3x4_times_mat2x3)
    {
        CONST_OR_CONSTEXPR auto m = fm34 * dm23;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm34.row(0), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm34.row(1), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm34.row(2), dm23.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm34.row(3), dm23.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm34.row(0), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm34.row(1), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm34.row(2), dm23.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm34.row(3), dm23.column(1))));
    }

    TEST_CASE(mat3x4_times_mat3x3)
    {
        CONST_OR_CONSTEXPR auto m = fm34 * dm33;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm34.row(0), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm34.row(1), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm34.row(2), dm33.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm34.row(3), dm33.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm34.row(0), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm34.row(1), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm34.row(2), dm33.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm34.row(3), dm33.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm34.row(0), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm34.row(1), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm34.row(2), dm33.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm34.row(3), dm33.column(2))));
    }

    TEST_CASE(mat3x4_times_mat4x3)
    {
        CONST_OR_CONSTEXPR auto m = fm34 * dm43;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm34.row(0), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm34.row(1), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm34.row(2), dm43.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm34.row(3), dm43.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm34.row(0), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm34.row(1), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm34.row(2), dm43.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm34.row(3), dm43.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm34.row(0), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm34.row(1), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm34.row(2), dm43.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm34.row(3), dm43.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm34.row(0), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm34.row(1), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm34.row(2), dm43.column(3))));
        test_assert(nearly_equal(
            m[3][3], math::dot(fm34.row(3), dm43.column(3))));
    }

    TEST_CASE(mat4x2_times_vec4)
    {
        CONST_OR_CONSTEXPR auto v = fm42 * dv4;
        test_assert(nearly_equal(v[0], math::dot(fm42.row(0), dv4)));
        test_assert(nearly_equal(v[1], math::dot(fm42.row(1), dv4)));
    }

    TEST_CASE(mat4x2_times_mat2x4)
    {
        CONST_OR_CONSTEXPR auto m = fm42 * dm24;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm42.row(0), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm42.row(1), dm24.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm42.row(0), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm42.row(1), dm24.column(1))));
    }

    TEST_CASE(mat4x2_times_mat3x4)
    {
        CONST_OR_CONSTEXPR auto m = fm42 * dm34;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm42.row(0), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm42.row(1), dm34.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm42.row(0), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm42.row(1), dm34.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm42.row(0), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm42.row(1), dm34.column(2))));
    }

    TEST_CASE(mat4x2_times_mat4x4)
    {
        CONST_OR_CONSTEXPR auto m = fm42 * dm44;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm42.row(0), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm42.row(1), dm44.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm42.row(0), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm42.row(1), dm44.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm42.row(0), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm42.row(1), dm44.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm42.row(0), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm42.row(1), dm44.column(3))));
    }

    TEST_CASE(mat4x3_times_vec4)
    {
        CONST_OR_CONSTEXPR auto v = fm43 * dv4;
        test_assert(nearly_equal(v[0], math::dot(fm43.row(0), dv4)));
        test_assert(nearly_equal(v[1], math::dot(fm43.row(1), dv4)));
        test_assert(nearly_equal(v[2], math::dot(fm43.row(2), dv4)));
    }

    TEST_CASE(mat4x3_times_mat2x4)
    {
        CONST_OR_CONSTEXPR auto m = fm43 * dm24;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm43.row(0), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm43.row(1), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm43.row(2), dm24.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm43.row(0), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm43.row(1), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm43.row(2), dm24.column(1))));
    }

    TEST_CASE(mat4x3_times_mat3x4)
    {
        CONST_OR_CONSTEXPR auto m = fm43 * dm34;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm43.row(0), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm43.row(1), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm43.row(2), dm34.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm43.row(0), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm43.row(1), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm43.row(2), dm34.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm43.row(0), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm43.row(1), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm43.row(2), dm34.column(2))));
    }

    TEST_CASE(mat4x3_times_mat4x4)
    {
        CONST_OR_CONSTEXPR auto m = fm43 * dm44;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm43.row(0), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm43.row(1), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm43.row(2), dm44.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm43.row(0), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm43.row(1), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm43.row(2), dm44.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm43.row(0), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm43.row(1), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm43.row(2), dm44.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm43.row(0), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm43.row(1), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm43.row(2), dm44.column(3))));
    }

    TEST_CASE(mat4x4_times_vec4)
    {
        CONST_OR_CONSTEXPR auto v = fm44 * dv4;
        test_assert(nearly_equal(v[0], math::dot(fm44.row(0), dv4)));
        test_assert(nearly_equal(v[1], math::dot(fm44.row(1), dv4)));
        test_assert(nearly_equal(v[2], math::dot(fm44.row(2), dv4)));
        test_assert(nearly_equal(v[3], math::dot(fm44.row(3), dv4)));
    }

    TEST_CASE(mat4x4_times_mat2x4)
    {
        CONST_OR_CONSTEXPR auto m = fm44 * dm24;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm44.row(0), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm44.row(1), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm44.row(2), dm24.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm44.row(3), dm24.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm44.row(0), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm44.row(1), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm44.row(2), dm24.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm44.row(3), dm24.column(1))));
    }

    TEST_CASE(mat4x4_times_mat3x4)
    {
        CONST_OR_CONSTEXPR auto m = fm44 * dm34;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm44.row(0), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm44.row(1), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm44.row(2), dm34.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm44.row(3), dm34.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm44.row(0), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm44.row(1), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm44.row(2), dm34.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm44.row(3), dm34.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm44.row(0), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm44.row(1), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm44.row(2), dm34.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm44.row(3), dm34.column(2))));
    }

    TEST_CASE(mat4x4_times_mat4x4)
    {
        CONST_OR_CONSTEXPR auto m = fm44 * dm44;
        test_assert(nearly_equal(
            m[0][0], math::dot(fm44.row(0), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][1], math::dot(fm44.row(1), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][2], math::dot(fm44.row(2), dm44.column(0))));
        test_assert(nearly_equal(
            m[0][3], math::dot(fm44.row(3), dm44.column(0))));
        test_assert(nearly_equal(
            m[1][0], math::dot(fm44.row(0), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][1], math::dot(fm44.row(1), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][2], math::dot(fm44.row(2), dm44.column(1))));
        test_assert(nearly_equal(
            m[1][3], math::dot(fm44.row(3), dm44.column(1))));
        test_assert(nearly_equal(
            m[2][0], math::dot(fm44.row(0), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][1], math::dot(fm44.row(1), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][2], math::dot(fm44.row(2), dm44.column(2))));
        test_assert(nearly_equal(
            m[2][3], math::dot(fm44.row(3), dm44.column(2))));
        test_assert(nearly_equal(
            m[3][0], math::dot(fm44.row(0), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][1], math::dot(fm44.row(1), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][2], math::dot(fm44.row(2), dm44.column(3))));
        test_assert(nearly_equal(
            m[3][3], math::dot(fm44.row(3), dm44.column(3))));
    }
}
