//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/mat.hpp>
#include "tue.tests.hpp"

#include <type_traits>
#include <tue/math.hpp>
#include <tue/sized_bool.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    CONST_OR_CONSTEXPR fmat2x2 fm22 = {
        { 1.1f, 1.2f },
        { 2.1f, 2.2f },
    };

    CONST_OR_CONSTEXPR fmat2x3 fm23 = {
        { 1.1f, 1.2f, 1.3f },
        { 2.1f, 2.2f, 2.3f },
    };

    CONST_OR_CONSTEXPR fmat2x4 fm24 = {
        { 1.1f, 1.2f, 1.3f, 1.4f },
        { 2.1f, 2.2f, 2.3f, 2.4f },
    };

    CONST_OR_CONSTEXPR dmat2x2 dm22 = {
        { 1.1, 1.2 },
        { 2.1, 2.2 },
    };

    CONST_OR_CONSTEXPR dmat2x2 dm222 = {
        { -1.1, 1.2 },
        { 22.1, -2.2 },
    };

    CONST_OR_CONSTEXPR dmat2x3 dm23 = {
        { 1.1, 1.2, 1.3 },
        { 2.1, 2.2, 2.3 },
    };

    CONST_OR_CONSTEXPR dmat2x4 dm24 = {
        { 1.1, 1.2, 1.3, 1.4 },
        { 2.1, 2.2, 2.3, 2.4 },
    };

    CONST_OR_CONSTEXPR dmat3x2 dm32 = {
        { 1.1, 1.2 },
        { 2.1, 2.2 },
        { 3.1, 3.2 },
    };

    CONST_OR_CONSTEXPR dmat3x4 dm34 = {
        { 1.1, 1.2, 1.3, 1.4 },
        { 2.1, 2.2, 2.3, 2.4 },
        { 3.1, 3.2, 3.3, 3.4 },
    };

    CONST_OR_CONSTEXPR dmat4x2 dm42 = {
        { 1.1, 1.2 },
        { 2.1, 2.2 },
        { 3.1, 3.2 },
        { 4.1, 4.2 },
    };

    CONST_OR_CONSTEXPR dmat4x4 dm44 = {
        { 1.1, 1.2, 1.3, 1.4 },
        { 2.1, 2.2, 2.3, 2.4 },
        { 3.1, 3.2, 3.3, 3.4 },
        { 4.1, 4.2, 4.3, 4.4 },
    };

    CONST_OR_CONSTEXPR mat2x2<short> sm22 = {
        { 1, 2 },
        { 3, 4 },
    };

    CONST_OR_CONSTEXPR mat2x2<int> im22 = {
        { 100, 101 },
        { 110, 111 },
    };

    CONST_OR_CONSTEXPR mat2x2<bool64> bm22 = {
        { true64, false64 },
        { false64, true64 },
    };

    TEST_CASE(size)
    {
        test_assert(sizeof(mat<short, 2, 2>) == sizeof(vec2<short>[2]));
        test_assert(sizeof(mat<short, 2, 3>) == sizeof(vec3<short>[2]));
        test_assert(sizeof(mat<short, 2, 4>) == sizeof(vec4<short>[2]));
        test_assert(sizeof(mat2x2<short>) == sizeof(vec2<short>[2]));
        test_assert(sizeof(mat2x3<short>) == sizeof(vec3<short>[2]));
        test_assert(sizeof(mat2x4<short>) == sizeof(vec4<short>[2]));
        test_assert(sizeof(fmat2x2) == sizeof(fvec2[2]));
        test_assert(sizeof(fmat2x3) == sizeof(fvec3[2]));
        test_assert(sizeof(fmat2x4) == sizeof(fvec4[2]));
        test_assert(sizeof(dmat2x2) == sizeof(dvec2[2]));
        test_assert(sizeof(dmat2x3) == sizeof(dvec3[2]));
        test_assert(sizeof(dmat2x4) == sizeof(dvec4[2]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(mat<short, 2, 2>) == alignof(vec2<short>[2]));
        test_assert(alignof(mat<short, 2, 3>) == alignof(vec3<short>[2]));
        test_assert(alignof(mat<short, 2, 4>) == alignof(vec4<short>[2]));
        test_assert(alignof(mat2x2<short>) == alignof(vec2<short>[2]));
        test_assert(alignof(mat2x3<short>) == alignof(vec3<short>[2]));
        test_assert(alignof(mat2x4<short>) == alignof(vec4<short>[2]));
        test_assert(alignof(fmat2x2) == alignof(fvec2[2]));
        test_assert(alignof(fmat2x3) == alignof(fvec3[2]));
        test_assert(alignof(fmat2x4) == alignof(fvec4[2]));
        test_assert(alignof(dmat2x2) == alignof(dvec2[2]));
        test_assert(alignof(dmat2x3) == alignof(dvec3[2]));
        test_assert(alignof(dmat2x4) == alignof(dvec4[2]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename mat<short, 2, 2>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 2, 3>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 2, 4>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat2x2<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat2x3<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat2x4<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fmat2x2::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat2x3::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat2x4::component_type, float>::value));
        test_assert((std::is_same<
            typename dmat2x2::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat2x3::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat2x4::component_type, double>::value));
    }

    TEST_CASE(column_count)
    {
        constexpr auto ms22 = mat<short, 2, 2>::column_count;
        constexpr auto ms23 = mat<short, 2, 3>::column_count;
        constexpr auto ms24 = mat<short, 2, 4>::column_count;
        constexpr auto m22s = mat2x2<short>::column_count;
        constexpr auto m23s = mat2x3<short>::column_count;
        constexpr auto m24s = mat2x4<short>::column_count;
        constexpr auto fm22 = fmat2x2::column_count;
        constexpr auto fm23 = fmat2x3::column_count;
        constexpr auto fm24 = fmat2x4::column_count;
        constexpr auto dm22 = dmat2x2::column_count;
        constexpr auto dm23 = dmat2x3::column_count;
        constexpr auto dm24 = dmat2x4::column_count;

        test_assert(ms22 == 2);
        test_assert(ms23 == 2);
        test_assert(ms24 == 2);
        test_assert(m22s == 2);
        test_assert(m23s == 2);
        test_assert(m24s == 2);
        test_assert(fm22 == 2);
        test_assert(fm23 == 2);
        test_assert(fm24 == 2);
        test_assert(dm22 == 2);
        test_assert(dm23 == 2);
        test_assert(dm24 == 2);
    }

    TEST_CASE(row_count)
    {
        constexpr auto ms22 = mat<short, 2, 2>::row_count;
        constexpr auto ms23 = mat<short, 2, 3>::row_count;
        constexpr auto ms24 = mat<short, 2, 4>::row_count;
        constexpr auto m22s = mat2x2<short>::row_count;
        constexpr auto m23s = mat2x3<short>::row_count;
        constexpr auto m24s = mat2x4<short>::row_count;
        constexpr auto fm22 = fmat2x2::row_count;
        constexpr auto fm23 = fmat2x3::row_count;
        constexpr auto fm24 = fmat2x4::row_count;
        constexpr auto dm22 = dmat2x2::row_count;
        constexpr auto dm23 = dmat2x3::row_count;
        constexpr auto dm24 = dmat2x4::row_count;

        test_assert(ms22 == 2);
        test_assert(ms23 == 3);
        test_assert(ms24 == 4);
        test_assert(m22s == 2);
        test_assert(m23s == 3);
        test_assert(m24s == 4);
        test_assert(fm22 == 2);
        test_assert(fm23 == 3);
        test_assert(fm24 == 4);
        test_assert(dm22 == 2);
        test_assert(dm23 == 3);
        test_assert(dm24 == 4);
    }

    TEST_CASE(component_count)
    {
        constexpr auto ms22 = mat<short, 2, 2>::component_count;
        constexpr auto ms23 = mat<short, 2, 3>::component_count;
        constexpr auto ms24 = mat<short, 2, 4>::component_count;
        constexpr auto m22s = mat2x2<short>::component_count;
        constexpr auto m23s = mat2x3<short>::component_count;
        constexpr auto m24s = mat2x4<short>::component_count;
        constexpr auto fm22 = fmat2x2::component_count;
        constexpr auto fm23 = fmat2x3::component_count;
        constexpr auto fm24 = fmat2x4::component_count;
        constexpr auto dm22 = dmat2x2::component_count;
        constexpr auto dm23 = dmat2x3::component_count;
        constexpr auto dm24 = dmat2x4::component_count;

        test_assert(ms22 == 2 * 2);
        test_assert(ms23 == 2 * 3);
        test_assert(ms24 == 2 * 4);
        test_assert(m22s == 2 * 2);
        test_assert(m23s == 2 * 3);
        test_assert(m24s == 2 * 4);
        test_assert(fm22 == 2 * 2);
        test_assert(fm23 == 2 * 3);
        test_assert(fm24 == 2 * 4);
        test_assert(dm22 == 2 * 2);
        test_assert(dm23 == 2 * 3);
        test_assert(dm24 == 2 * 4);
    }

    TEST_CASE(default_constructor)
    {
        dmat2x2 m;
        tue::unused(m);
    }

    TEST_CASE(main_diagonal_constructor)
    {
        CONST_OR_CONSTEXPR dmat2x2 m22(1.2);
        test_assert(m22[0] == dvec2(1.2, 0.0));
        test_assert(m22[1] == dvec2(0.0, 1.2));

        CONST_OR_CONSTEXPR dmat2x3 m23(1.2);
        test_assert(m23[0] == dvec3(1.2, 0.0, 0.0));
        test_assert(m23[1] == dvec3(0.0, 1.2, 0.0));

        CONST_OR_CONSTEXPR dmat2x4 m24(1.2);
        test_assert(m24[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m24[1] == dvec4(0.0, 1.2, 0.0, 0.0));
    }

    TEST_CASE(single_column_constructor)
    {
        CONST_OR_CONSTEXPR dmat2x2 m22(dvec2(1.2, 3.4));
        test_assert(m22[0] == dvec2(1.2, 3.4));
        test_assert(m22[1] == dvec2(1.2, 3.4));

        CONST_OR_CONSTEXPR dmat2x3 m23(dvec3(1.2, 3.4, 5.6));
        test_assert(m23[0] == dvec3(1.2, 3.4, 5.6));
        test_assert(m23[1] == dvec3(1.2, 3.4, 5.6));

        CONST_OR_CONSTEXPR dmat2x4 m24(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m24[0] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m24[1] == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(individual_column_constructor)
    {
        test_assert(dm22[0] == dvec2(1.1, 1.2));
        test_assert(dm22[1] == dvec2(2.1, 2.2));

        test_assert(dm23[0] == dvec3(1.1, 1.2, 1.3));
        test_assert(dm23[1] == dvec3(2.1, 2.2, 2.3));

        test_assert(dm24[0] == dvec4(1.1, 1.2, 1.3, 1.4));
        test_assert(dm24[1] == dvec4(2.1, 2.2, 2.3, 2.4));
    }

    TEST_CASE(mat2xR_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dmat2x2 m1(dm24);
        test_assert(m1[0] == dvec2(dm24[0]));
        test_assert(m1[1] == dvec2(dm24[1]));

        CONST_OR_CONSTEXPR dmat2x4 m2(dm22);
        test_assert(m2[0] == dvec4(dm22[0], 0.0, 0.0));
        test_assert(m2[1] == dvec4(dm22[1], 0.0, 0.0));

        CONST_OR_CONSTEXPR dmat2x2 m3(dm34);
        test_assert(m3[0] == dvec2(dm34[0]));
        test_assert(m3[1] == dvec2(dm34[1]));

        CONST_OR_CONSTEXPR dmat2x4 m4(dm32);
        test_assert(m4[0] == dvec4(dm32[0], 0.0, 0.0));
        test_assert(m4[1] == dvec4(dm32[1], 0.0, 0.0));

        CONST_OR_CONSTEXPR dmat2x2 m5(dm44);
        test_assert(m5[0] == dvec2(dm44[0]));
        test_assert(m5[1] == dvec2(dm44[1]));

        CONST_OR_CONSTEXPR dmat2x4 m6(dm42);
        test_assert(m6[0] == dvec4(dm42[0], 0.0, 0.0));
        test_assert(m6[1] == dvec4(dm42[1], 0.0, 0.0));
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR fmat2x2 m(dm22);
        test_assert(m[0] == fvec2(dm42[0]));
        test_assert(m[1] == fvec2(dm42[1]));
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR dmat2x2 m22 = fm22;
        test_assert(m22[0] == fm22[0]);
        test_assert(m22[1] == fm22[1]);

        CONST_OR_CONSTEXPR dmat2x3 m23 = fm23;
        test_assert(m23[0] == fm23[0]);
        test_assert(m23[1] == fm23[1]);

        CONST_OR_CONSTEXPR dmat2x4 m24 = fm24;
        test_assert(m24[0] == fm24[0]);
        test_assert(m24[1] == fm24[1]);
    }

    TEST_CASE(fill)
    {
        CONST_OR_CONSTEXPR auto m22 = dmat2x2::fill(1.2);
        test_assert(m22[0] == dvec2(1.2));
        test_assert(m22[1] == dvec2(1.2));

        CONST_OR_CONSTEXPR auto m23 = dmat2x3::fill(1.2);
        test_assert(m23[0] == dvec3(1.2));
        test_assert(m23[1] == dvec3(1.2));

        CONST_OR_CONSTEXPR auto m24 = dmat2x4::fill(1.2);
        test_assert(m24[0] == dvec4(1.2));
        test_assert(m24[1] == dvec4(1.2));
    }

    TEST_CASE(identity)
    {
        CONST_OR_CONSTEXPR auto m22 = dmat2x2::identity();
        test_assert(m22[0] == dvec2(1.0, 0.0));
        test_assert(m22[1] == dvec2(0.0, 1.0));

        CONST_OR_CONSTEXPR auto m23 = dmat2x3::identity();
        test_assert(m23[0] == dvec3(1.0, 0.0, 0.0));
        test_assert(m23[1] == dvec3(0.0, 1.0, 0.0));

        CONST_OR_CONSTEXPR auto m24 = dmat2x4::identity();
        test_assert(m24[0] == dvec4(1.0, 0.0, 0.0, 0.0));
        test_assert(m24[1] == dvec4(0.0, 1.0, 0.0, 0.0));
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto m22 = dmat2x2::zero();
        test_assert(m22[0] == dvec2(0.0, 0.0));
        test_assert(m22[1] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR auto m23 = dmat2x3::zero();
        test_assert(m23[0] == dvec3(0.0, 0.0, 0.0));
        test_assert(m23[1] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR auto m24 = dmat2x4::zero();
        test_assert(m24[0] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m24[1] == dvec4(0.0, 0.0, 0.0, 0.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dmat2x2 cem = dm22;
        CONST_OR_CONSTEXPR auto cem0 = cem[0];
        CONST_OR_CONSTEXPR auto cem1 = cem[1];
        test_assert(cem0 == dvec2(1.1, 1.2));
        test_assert(cem1 == dvec2(2.1, 2.2));

        const auto cm = dm22;
        const auto& cm0 = cm[0];
        const auto& cm1 = cm[1];
        test_assert(&cm0 == cm.columns() + 0);
        test_assert(&cm1 == cm.columns() + 1);

        auto m = dm22;
        auto& m0 = m[0];
        auto& m1 = m[1];
        test_assert(&m0 == m.columns() + 0);
        test_assert(&m1 == m.columns() + 1);
    }

    TEST_CASE(data)
    {
        const dmat2x2 cm(1.2);
        const double* cdata = cm.data();
        test_assert(cdata == static_cast<const void*>(&cm));

        dmat2x2 m;
        double* data = m.data();
        test_assert(data == static_cast<void*>(&m));
    }

    TEST_CASE(columns)
    {
        const dmat2x2 cm(1.2);
        const dvec2* ccolumns = cm.columns();
        test_assert(ccolumns == static_cast<const void*>(&cm));

        dmat2x2 m;
        dvec2* columns = m.columns();
        test_assert(columns == static_cast<void*>(&m));
    }

    TEST_CASE(column)
    {
        test_assert(dm22.column(0) == dm22[0]);
        test_assert(dm22.column(1) == dm22[1]);

        test_assert(dm23.column(0) == dm23[0]);
        test_assert(dm23.column(1) == dm23[1]);

        test_assert(dm24.column(0) == dm24[0]);
        test_assert(dm24.column(1) == dm24[1]);
    }

    TEST_CASE(set_column)
    {
        dmat2x2 m22;
        m22.set_column(0, dvec2(0.0, 0.1));
        m22.set_column(1, dvec2(1.0, 1.1));
        test_assert(m22.column(0) == dvec2(0.0, 0.1));
        test_assert(m22.column(1) == dvec2(1.0, 1.1));

        dmat2x3 m23;
        m23.set_column(0, dvec3(0.0, 0.1, 0.2));
        m23.set_column(1, dvec3(1.0, 1.1, 1.2));
        test_assert(m23.column(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m23.column(1) == dvec3(1.0, 1.1, 1.2));

        dmat2x4 m24;
        m24.set_column(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m24.set_column(1, dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m24.column(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m24.column(1) == dvec4(1.0, 1.1, 1.2, 1.3));
    }

    TEST_CASE(row)
    {
        test_assert(dm22.row(0) == dvec2(dm22[0][0], dm22[1][0]));
        test_assert(dm22.row(1) == dvec2(dm22[0][1], dm22[1][1]));

        test_assert(dm23.row(0) == dvec2(dm23[0][0], dm23[1][0]));
        test_assert(dm23.row(1) == dvec2(dm23[0][1], dm23[1][1]));
        test_assert(dm23.row(2) == dvec2(dm23[0][2], dm23[1][2]));

        test_assert(dm24.row(0) == dvec2(dm24[0][0], dm24[1][0]));
        test_assert(dm24.row(1) == dvec2(dm24[0][1], dm24[1][1]));
        test_assert(dm24.row(2) == dvec2(dm24[0][2], dm24[1][2]));
        test_assert(dm24.row(3) == dvec2(dm24[0][3], dm24[1][3]));
    }

    TEST_CASE(set_row)
    {
        dmat2x2 m22;
        m22.set_row(0, dvec2(0.0, 0.1));
        m22.set_row(1, dvec2(1.0, 1.1));
        test_assert(m22.row(0) == dvec2(0.0, 0.1));
        test_assert(m22.row(1) == dvec2(1.0, 1.1));

        dmat2x3 m23;
        m23.set_row(0, dvec2(0.0, 0.1));
        m23.set_row(1, dvec2(1.0, 1.1));
        m23.set_row(2, dvec2(2.0, 2.1));
        test_assert(m23.row(0) == dvec2(0.0, 0.1));
        test_assert(m23.row(1) == dvec2(1.0, 1.1));
        test_assert(m23.row(2) == dvec2(2.0, 2.1));

        dmat2x4 m24;
        m24.set_row(0, dvec2(0.0, 0.1));
        m24.set_row(1, dvec2(1.0, 1.1));
        m24.set_row(2, dvec2(2.0, 2.1));
        m24.set_row(3, dvec2(3.0, 3.1));
        test_assert(m24.row(0) == dvec2(0.0, 0.1));
        test_assert(m24.row(1) == dvec2(1.0, 1.1));
        test_assert(m24.row(2) == dvec2(2.0, 2.1));
        test_assert(m24.row(3) == dvec2(3.0, 3.1));
    }

    TEST_CASE(pre_increment_operator)
    {
        auto m = im22;
        test_assert(&(++m) == &m);
        test_assert(m[0] == im22[0] + 1);
        test_assert(m[1] == im22[1] + 1);
    }

    TEST_CASE(post_increment_operator)
    {
        auto m1 = im22;
        const auto m2 = m1++;
        test_assert(m1[0] == im22[0] + 1);
        test_assert(m1[1] == im22[1] + 1);
        test_assert(m2 == im22);
    }

    TEST_CASE(pre_decrement_operator)
    {
        auto m = im22;
        test_assert(&(--m) == &m);
        test_assert(m[0] == im22[0] - 1);
        test_assert(m[1] == im22[1] - 1);
    }

    TEST_CASE(post_decrement_operator)
    {
        auto m1 = im22;
        const auto m2 = m1--;
        test_assert(m1[0] == im22[0] - 1);
        test_assert(m1[1] == im22[1] - 1);
        test_assert(m2 == im22);
    }

    TEST_CASE(addition_assignment_operator)
    {
        auto m1 = dm22;
        test_assert(&(m1 += 12) == &m1);
        test_assert(m1[0] == dm22[0] + 12);
        test_assert(m1[1] == dm22[1] + 12);

        auto m2 = dm22;
        test_assert(&(m2 += im22) == &m2);
        test_assert(m2[0] == dm22[0] + im22[0]);
        test_assert(m2[1] == dm22[1] + im22[1]);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        auto m1 = dm22;
        test_assert(&(m1 -= 12) == &m1);
        test_assert(m1[0] == dm22[0] - 12);
        test_assert(m1[1] == dm22[1] - 12);

        auto m2 = dm22;
        test_assert(&(m2 -= im22) == &m2);
        test_assert(m2[0] == dm22[0] - im22[0]);
        test_assert(m2[1] == dm22[1] - im22[1]);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        auto m1 = dm22;
        test_assert(&(m1 *= 12) == &m1);
        test_assert(m1[0] == dm22[0] * 12);
        test_assert(m1[1] == dm22[1] * 12);

        auto m2 = dm23;
        test_assert(&(m2 *= im22) == &m2);
        test_assert(m2 == dm23 * im22);
    }

    TEST_CASE(division_assignment_operator)
    {
        auto m1 = dm22;
        test_assert(&(m1 /= 12) == &m1);
        test_assert(m1[0] == dm22[0] / 12);
        test_assert(m1[1] == dm22[1] / 12);

        auto m2 = dm22;
        test_assert(&(m2 /= im22) == &m2);
        test_assert(m2[0] == dm22[0] / im22[0]);
        test_assert(m2[1] == dm22[1] / im22[1]);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 %= 12) == &m1);
        test_assert(m1[0] == im22[0] % 12);
        test_assert(m1[1] == im22[1] % 12);

        auto m2 = im22;
        test_assert(&(m2 %= sm22) == &m2);
        test_assert(m2[0] == im22[0] % sm22[0]);
        test_assert(m2[1] == im22[1] % sm22[1]);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 &= 12) == &m1);
        test_assert(m1[0] == (im22[0] & 12));
        test_assert(m1[1] == (im22[1] & 12));

        auto m2 = im22;
        test_assert(&(m2 &= sm22) == &m2);
        test_assert(m2[0] == (im22[0] & sm22[0]));
        test_assert(m2[1] == (im22[1] & sm22[1]));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 |= 12) == &m1);
        test_assert(m1[0] == (im22[0] | 12));
        test_assert(m1[1] == (im22[1] | 12));

        auto m2 = im22;
        test_assert(&(m2 |= sm22) == &m2);
        test_assert(m2[0] == (im22[0] | sm22[0]));
        test_assert(m2[1] == (im22[1] | sm22[1]));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 ^= 12) == &m1);
        test_assert(m1[0] == (im22[0] ^ 12));
        test_assert(m1[1] == (im22[1] ^ 12));

        auto m2 = im22;
        test_assert(&(m2 ^= sm22) == &m2);
        test_assert(m2[0] == (im22[0] ^ sm22[0]));
        test_assert(m2[1] == (im22[1] ^ sm22[1]));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 <<= 12) == &m1);
        test_assert(m1[0] == (im22[0] << 12));
        test_assert(m1[1] == (im22[1] << 12));

        auto m2 = im22;
        test_assert(&(m2 <<= sm22) == &m2);
        test_assert(m2[0] == (im22[0] << sm22[0]));
        test_assert(m2[1] == (im22[1] << sm22[1]));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        auto m1 = im22;
        test_assert(&(m1 >>= 12) == &m1);
        test_assert(m1[0] == (im22[0] >> 12));
        test_assert(m1[1] == (im22[1] >> 12));

        auto m2 = im22;
        test_assert(&(m2 >>= sm22) == &m2);
        test_assert(m2[0] == (im22[0] >> sm22[0]));
        test_assert(m2[1] == (im22[1] >> sm22[1]));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto m = +dm22;
        test_assert(m == dmat2x2(+dm22[0], +dm22[1]));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto m = -dm22;
        test_assert(m == dmat2x2(-dm22[0], -dm22[1]));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto m = ~im22;
        test_assert(m == mat2x2<int>(~im22[0], ~im22[1]));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 + dm22;
        test_assert(m1[0] == 12 + dm22[0]);
        test_assert(m1[1] == 12 + dm22[1]);

        CONST_OR_CONSTEXPR auto m2 = dm22 + 12;
        test_assert(m2[0] == dm22[0] + 12);
        test_assert(m2[1] == dm22[1] + 12);

        CONST_OR_CONSTEXPR auto m3 = dm22 + im22;
        test_assert(m3[0] == dm22[0] + im22[0]);
        test_assert(m3[1] == dm22[1] + im22[1]);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 - dm22;
        test_assert(m1[0] == 12 - dm22[0]);
        test_assert(m1[1] == 12 - dm22[1]);

        CONST_OR_CONSTEXPR auto m2 = dm22 - 12;
        test_assert(m2[0] == dm22[0] - 12);
        test_assert(m2[1] == dm22[1] - 12);

        CONST_OR_CONSTEXPR auto m3 = dm22 - im22;
        test_assert(m3[0] == dm22[0] - im22[0]);
        test_assert(m3[1] == dm22[1] - im22[1]);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 * dm22;
        test_assert(m1[0] == 12 * dm22[0]);
        test_assert(m1[1] == 12 * dm22[1]);

        CONST_OR_CONSTEXPR auto m2 = dm22 * 12;
        test_assert(m2[0] == dm22[0] * 12);
        test_assert(m2[1] == dm22[1] * 12);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 / dm22;
        test_assert(m1[0] == 12 / dm22[0]);
        test_assert(m1[1] == 12 / dm22[1]);

        CONST_OR_CONSTEXPR auto m2 = dm22 / 12;
        test_assert(m2[0] == dm22[0] / 12);
        test_assert(m2[1] == dm22[1] / 12);

        CONST_OR_CONSTEXPR auto m3 = dm22 / im22;
        test_assert(m3[0] == dm22[0] / im22[0]);
        test_assert(m3[1] == dm22[1] / im22[1]);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 % sm22;
        test_assert(m1[0] == 123 % sm22[0]);
        test_assert(m1[1] == 123 % sm22[1]);

        CONST_OR_CONSTEXPR auto m2 = im22 % 12;
        test_assert(m2[0] == im22[0] % 12);
        test_assert(m2[1] == im22[1] % 12);

        CONST_OR_CONSTEXPR auto m3 = im22 % sm22;
        test_assert(m3[0] == im22[0] % sm22[0]);
        test_assert(m3[1] == im22[1] % sm22[1]);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 & sm22;
        test_assert(m1[0] == (123 & sm22[0]));
        test_assert(m1[1] == (123 & sm22[1]));

        CONST_OR_CONSTEXPR auto m2 = im22 & 12;
        test_assert(m2[0] == (im22[0] & 12));
        test_assert(m2[1] == (im22[1] & 12));

        CONST_OR_CONSTEXPR auto m3 = im22 & sm22;
        test_assert(m3[0] == (im22[0] & sm22[0]));
        test_assert(m3[1] == (im22[1] & sm22[1]));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 | sm22;
        test_assert(m1[0] == (123 | sm22[0]));
        test_assert(m1[1] == (123 | sm22[1]));

        CONST_OR_CONSTEXPR auto m2 = im22 | 12;
        test_assert(m2[0] == (im22[0] | 12));
        test_assert(m2[1] == (im22[1] | 12));

        CONST_OR_CONSTEXPR auto m3 = im22 | sm22;
        test_assert(m3[0] == (im22[0] | sm22[0]));
        test_assert(m3[1] == (im22[1] | sm22[1]));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 ^ sm22;
        test_assert(m1[0] == (123 ^ sm22[0]));
        test_assert(m1[1] == (123 ^ sm22[1]));

        CONST_OR_CONSTEXPR auto m2 = im22 ^ 12;
        test_assert(m2[0] == (im22[0] ^ 12));
        test_assert(m2[1] == (im22[1] ^ 12));

        CONST_OR_CONSTEXPR auto m3 = im22 ^ sm22;
        test_assert(m3[0] == (im22[0] ^ sm22[0]));
        test_assert(m3[1] == (im22[1] ^ sm22[1]));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 << sm22;
        test_assert(m1[0] == (123 << sm22[0]));
        test_assert(m1[1] == (123 << sm22[1]));

        CONST_OR_CONSTEXPR auto m2 = im22 << 1;
        test_assert(m2[0] == (im22[0] << 1));
        test_assert(m2[1] == (im22[1] << 1));

        CONST_OR_CONSTEXPR auto m3 = im22 << sm22;
        test_assert(m3[0] == (im22[0] << sm22[0]));
        test_assert(m3[1] == (im22[1] << sm22[1]));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 >> sm22;
        test_assert(m1[0] == (123 >> sm22[0]));
        test_assert(m1[1] == (123 >> sm22[1]));

        CONST_OR_CONSTEXPR auto m2 = im22 >> 1;
        test_assert(m2[0] == (im22[0] >> 1));
        test_assert(m2[1] == (im22[1] >> 1));

        CONST_OR_CONSTEXPR auto m3 = im22 >> sm22;
        test_assert(m3[0] == (im22[0] >> sm22[0]));
        test_assert(m3[1] == (im22[1] >> sm22[1]));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fmat2x2 m1(fvec2(1.2f), fvec2(3.4f));
        CONST_OR_CONSTEXPR dmat2x2 m2(dvec2(1.2f), dvec2(3.4f));
        CONST_OR_CONSTEXPR dmat2x2 m3(dvec2(1.2f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat2x2 m4(dvec2(0.0f), dvec2(3.4f));
        CONST_OR_CONSTEXPR auto result1 = (m1 == m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 == m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 == m4);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fmat2x2 m1(fvec2(1.2f), fvec2(3.4f));
        CONST_OR_CONSTEXPR dmat2x2 m2(dvec2(1.2f), dvec2(3.4f));
        CONST_OR_CONSTEXPR dmat2x2 m3(dvec2(1.2f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat2x2 m4(dvec2(0.0f), dvec2(3.4f));
        CONST_OR_CONSTEXPR auto result1 = (m1 != m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 != m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 != m4);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
    }

    TEST_CASE(sin)
    {
        const auto m = math::sin(dm22);
        test_assert(m[0] == math::sin(dm22[0]));
        test_assert(m[1] == math::sin(dm22[1]));
    }

    TEST_CASE(cos)
    {
        const auto m = math::cos(dm22);
        test_assert(m[0] == math::cos(dm22[0]));
        test_assert(m[1] == math::cos(dm22[1]));
    }

    TEST_CASE(sincos)
    {
        dmat2x2 s, c;
        math::sincos(dm22, s, c);

        test_assert(s[0] == math::sin(dm22[0]));
        test_assert(s[1] == math::sin(dm22[1]));

        test_assert(c[0] == math::cos(dm22[0]));
        test_assert(c[1] == math::cos(dm22[1]));
    }

    TEST_CASE(exp)
    {
        const auto m = math::exp(dm22);
        test_assert(m[0] == math::exp(dm22[0]));
        test_assert(m[1] == math::exp(dm22[1]));
    }

    TEST_CASE(log)
    {
        const auto m = math::log(dm22);
        test_assert(m[0] == math::log(dm22[0]));
        test_assert(m[1] == math::log(dm22[1]));
    }

    TEST_CASE(abs)
    {
        const auto m = math::abs(dm222);
        test_assert(m[0] == math::abs(dm222[0]));
        test_assert(m[1] == math::abs(dm222[1]));
    }

    TEST_CASE(pow)
    {
        const auto m = math::pow(dm22, dm222);
        test_assert(m[0] == math::pow(dm22[0], dm222[0]));
        test_assert(m[1] == math::pow(dm22[1], dm222[1]));
    }

    TEST_CASE(recip)
    {
        const auto m = math::recip(dm22);
        test_assert(m[0] == math::recip(dm22[0]));
        test_assert(m[1] == math::recip(dm22[1]));
    }

    TEST_CASE(sqrt)
    {
        const auto m = math::sqrt(dm22);
        test_assert(m[0] == math::sqrt(dm22[0]));
        test_assert(m[1] == math::sqrt(dm22[1]));
    }

    TEST_CASE(rsqrt)
    {
        const auto m = math::rsqrt(dm22);
        test_assert(m[0] == math::rsqrt(dm22[0]));
        test_assert(m[1] == math::rsqrt(dm22[1]));
    }

    TEST_CASE(min)
    {
        const auto m = math::min(dm22, dm222);
        test_assert(m[0] == math::min(dm22[0], dm222[0]));
        test_assert(m[1] == math::min(dm22[1], dm222[1]));
    }

    TEST_CASE(max)
    {
        const auto m = math::max(dm22, dm222);
        test_assert(m[0] == math::max(dm22[0], dm222[0]));
        test_assert(m[1] == math::max(dm22[1], dm222[1]));
    }

    TEST_CASE(mask)
    {
        const auto m = math::mask(bm22, dm22);
        test_assert(m[0] == math::mask(bm22[0], dm22[0]));
        test_assert(m[1] == math::mask(bm22[1], dm22[1]));
    }

    TEST_CASE(select)
    {
        const auto m = math::select(bm22, dm22, dm222);
        test_assert(m[0] == math::select(bm22[0], dm22[0], dm222[0]));
        test_assert(m[1] == math::select(bm22[1], dm22[1], dm222[1]));
    }

    TEST_CASE(less)
    {
        const auto m = math::less(dm22, dm222);
        test_assert(m[0] == math::less(dm22[0], dm222[0]));
        test_assert(m[1] == math::less(dm22[1], dm222[1]));
    }

    TEST_CASE(less_equal)
    {
        const auto m = math::less_equal(dm22, dm222);
        test_assert(m[0] == math::less_equal(dm22[0], dm222[0]));
        test_assert(m[1] == math::less_equal(dm22[1], dm222[1]));
    }

    TEST_CASE(greater)
    {
        const auto m = math::greater(dm22, dm222);
        test_assert(m[0] == math::greater(dm22[0], dm222[0]));
        test_assert(m[1] == math::greater(dm22[1], dm222[1]));
    }

    TEST_CASE(greater_equal)
    {
        const auto m = math::greater_equal(dm22, dm222);
        test_assert(m[0] == math::greater_equal(dm22[0], dm222[0]));
        test_assert(m[1] == math::greater_equal(dm22[1], dm222[1]));
    }

    TEST_CASE(equal)
    {
        const auto m = math::equal(dm22, dm222);
        test_assert(m[0] == math::equal(dm22[0], dm222[0]));
        test_assert(m[1] == math::equal(dm22[1], dm222[1]));
    }

    TEST_CASE(not_equal)
    {
        const auto m = math::not_equal(dm22, dm222);
        test_assert(m[0] == math::not_equal(dm22[0], dm222[0]));
        test_assert(m[1] == math::not_equal(dm22[1], dm222[1]));
    }

    TEST_CASE(comp_mult)
    {
        CONST_OR_CONSTEXPR auto m = math::comp_mult(dm22, im22);
        test_assert(m[0] == dm22[0] * im22[0]);
        test_assert(m[1] == dm22[1] * im22[1]);
    }

    TEST_CASE(transpose)
    {
        CONST_OR_CONSTEXPR auto m1 = math::transpose(dm22);
        test_assert(m1[0] == dm22.row(0));
        test_assert(m1[1] == dm22.row(1));

        CONST_OR_CONSTEXPR auto m2 = math::transpose(dm23);
        test_assert(m2[0] == dm23.row(0));
        test_assert(m2[1] == dm23.row(1));
        test_assert(m2[2] == dm23.row(2));

        CONST_OR_CONSTEXPR auto m3 = math::transpose(dm24);
        test_assert(m3[0] == dm24.row(0));
        test_assert(m3[1] == dm24.row(1));
        test_assert(m3[2] == dm24.row(2));
        test_assert(m3[3] == dm24.row(3));
    }
}
