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

    CONST_OR_CONSTEXPR fmat3x2 fm32 = {
        { 1.1f, 1.2f },
        { 2.1f, 2.2f },
        { 3.1f, 3.2f },
    };

    CONST_OR_CONSTEXPR fmat3x3 fm33 = {
        { 1.1f, 1.2f, 1.3f },
        { 2.1f, 2.2f, 2.3f },
        { 3.1f, 3.2f, 3.3f },
    };

    CONST_OR_CONSTEXPR fmat3x4 fm34 = {
        { 1.1f, 1.2f, 1.3f, 1.4f },
        { 2.1f, 2.2f, 2.3f, 2.4f },
        { 3.1f, 3.2f, 3.3f, 3.4f },
    };

    CONST_OR_CONSTEXPR dmat2x2 dm22 = {
        { 1.1, 1.2 },
        { 2.1, 2.2 },
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

    CONST_OR_CONSTEXPR dmat3x2 dm322 = {
        { -1.1, 1.2 },
        { 22.1, -2.2 },
        { -3.1, 3.2 },
    };

    CONST_OR_CONSTEXPR dmat3x3 dm33 = {
        { 1.1, 1.2, 1.3 },
        { 2.1, 2.2, 2.3 },
        { 3.1, 3.2, 3.3 },
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

    CONST_OR_CONSTEXPR mat3x2<short> sm32 = {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 },
    };

    CONST_OR_CONSTEXPR mat3x2<int> im32 = {
        { 100, 101 },
        { 110, 111 },
        { 120, 121 },
    };

    CONST_OR_CONSTEXPR mat3x3<int> im33 = {
        { 100, 101, 102 },
        { 110, 111, 112 },
        { 120, 121, 122 },
    };

    CONST_OR_CONSTEXPR mat3x2<bool64> bm32 = {
        { true64, false64 },
        { false64, true64 },
        { true64, false64 },
    };

    TEST_CASE(size)
    {
        test_assert(sizeof(mat<short, 3, 2>) == sizeof(vec2<short>[3]));
        test_assert(sizeof(mat<short, 3, 3>) == sizeof(vec3<short>[3]));
        test_assert(sizeof(mat<short, 3, 4>) == sizeof(vec4<short>[3]));
        test_assert(sizeof(mat3x2<short>) == sizeof(vec2<short>[3]));
        test_assert(sizeof(mat3x3<short>) == sizeof(vec3<short>[3]));
        test_assert(sizeof(mat3x4<short>) == sizeof(vec4<short>[3]));
        test_assert(sizeof(fmat3x2) == sizeof(fvec2[3]));
        test_assert(sizeof(fmat3x3) == sizeof(fvec3[3]));
        test_assert(sizeof(fmat3x4) == sizeof(fvec4[3]));
        test_assert(sizeof(dmat3x2) == sizeof(dvec2[3]));
        test_assert(sizeof(dmat3x3) == sizeof(dvec3[3]));
        test_assert(sizeof(dmat3x4) == sizeof(dvec4[3]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(mat<short, 3, 2>) == alignof(vec2<short>[3]));
        test_assert(alignof(mat<short, 3, 3>) == alignof(vec3<short>[3]));
        test_assert(alignof(mat<short, 3, 4>) == alignof(vec4<short>[3]));
        test_assert(alignof(mat3x2<short>) == alignof(vec2<short>[3]));
        test_assert(alignof(mat3x3<short>) == alignof(vec3<short>[3]));
        test_assert(alignof(mat3x4<short>) == alignof(vec4<short>[3]));
        test_assert(alignof(fmat3x2) == alignof(fvec2[3]));
        test_assert(alignof(fmat3x3) == alignof(fvec3[3]));
        test_assert(alignof(fmat3x4) == alignof(fvec4[3]));
        test_assert(alignof(dmat3x2) == alignof(dvec2[3]));
        test_assert(alignof(dmat3x3) == alignof(dvec3[3]));
        test_assert(alignof(dmat3x4) == alignof(dvec4[3]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename mat<short, 3, 2>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 3, 3>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 3, 4>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat3x2<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat3x3<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat3x4<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fmat3x2::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat3x3::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat3x4::component_type, float>::value));
        test_assert((std::is_same<
            typename dmat3x2::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat3x3::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat3x4::component_type, double>::value));
    }

    TEST_CASE(column_count)
    {
        constexpr auto ms32 = mat<short, 3, 2>::column_count;
        constexpr auto ms33 = mat<short, 3, 3>::column_count;
        constexpr auto ms34 = mat<short, 3, 4>::column_count;
        constexpr auto m32s = mat3x2<short>::column_count;
        constexpr auto m33s = mat3x3<short>::column_count;
        constexpr auto m34s = mat3x4<short>::column_count;
        constexpr auto fm32 = fmat3x2::column_count;
        constexpr auto fm33 = fmat3x3::column_count;
        constexpr auto fm34 = fmat3x4::column_count;
        constexpr auto dm32 = dmat3x2::column_count;
        constexpr auto dm33 = dmat3x3::column_count;
        constexpr auto dm34 = dmat3x4::column_count;

        test_assert(ms32 == 3);
        test_assert(ms33 == 3);
        test_assert(ms34 == 3);
        test_assert(m32s == 3);
        test_assert(m33s == 3);
        test_assert(m34s == 3);
        test_assert(fm32 == 3);
        test_assert(fm33 == 3);
        test_assert(fm34 == 3);
        test_assert(dm32 == 3);
        test_assert(dm33 == 3);
        test_assert(dm34 == 3);
    }

    TEST_CASE(row_count)
    {
        constexpr auto ms32 = mat<short, 3, 2>::row_count;
        constexpr auto ms33 = mat<short, 3, 3>::row_count;
        constexpr auto ms34 = mat<short, 3, 4>::row_count;
        constexpr auto m32s = mat3x2<short>::row_count;
        constexpr auto m33s = mat3x3<short>::row_count;
        constexpr auto m34s = mat3x4<short>::row_count;
        constexpr auto fm32 = fmat3x2::row_count;
        constexpr auto fm33 = fmat3x3::row_count;
        constexpr auto fm34 = fmat3x4::row_count;
        constexpr auto dm32 = dmat3x2::row_count;
        constexpr auto dm33 = dmat3x3::row_count;
        constexpr auto dm34 = dmat3x4::row_count;

        test_assert(ms32 == 2);
        test_assert(ms33 == 3);
        test_assert(ms34 == 4);
        test_assert(m32s == 2);
        test_assert(m33s == 3);
        test_assert(m34s == 4);
        test_assert(fm32 == 2);
        test_assert(fm33 == 3);
        test_assert(fm34 == 4);
        test_assert(dm32 == 2);
        test_assert(dm33 == 3);
        test_assert(dm34 == 4);
    }

    TEST_CASE(component_count)
    {
        constexpr auto ms32 = mat<short, 3, 2>::component_count;
        constexpr auto ms33 = mat<short, 3, 3>::component_count;
        constexpr auto ms34 = mat<short, 3, 4>::component_count;
        constexpr auto m32s = mat3x2<short>::component_count;
        constexpr auto m33s = mat3x3<short>::component_count;
        constexpr auto m34s = mat3x4<short>::component_count;
        constexpr auto fm32 = fmat3x2::component_count;
        constexpr auto fm33 = fmat3x3::component_count;
        constexpr auto fm34 = fmat3x4::component_count;
        constexpr auto dm32 = dmat3x2::component_count;
        constexpr auto dm33 = dmat3x3::component_count;
        constexpr auto dm34 = dmat3x4::component_count;

        test_assert(ms32 == 3 * 2);
        test_assert(ms33 == 3 * 3);
        test_assert(ms34 == 3 * 4);
        test_assert(m32s == 3 * 2);
        test_assert(m33s == 3 * 3);
        test_assert(m34s == 3 * 4);
        test_assert(fm32 == 3 * 2);
        test_assert(fm33 == 3 * 3);
        test_assert(fm34 == 3 * 4);
        test_assert(dm32 == 3 * 2);
        test_assert(dm33 == 3 * 3);
        test_assert(dm34 == 3 * 4);
    }

    TEST_CASE(default_constructor)
    {
        dmat3x2 m;
        tue::unused(m);
    }

    TEST_CASE(main_diagonal_constructor)
    {
        CONST_OR_CONSTEXPR dmat3x2 m32(1.2);
        test_assert(m32[0] == dvec2(1.2, 0.0));
        test_assert(m32[1] == dvec2(0.0, 1.2));
        test_assert(m32[2] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat3x3 m33(1.2);
        test_assert(m33[0] == dvec3(1.2, 0.0, 0.0));
        test_assert(m33[1] == dvec3(0.0, 1.2, 0.0));
        test_assert(m33[2] == dvec3(0.0, 0.0, 1.2));

        CONST_OR_CONSTEXPR dmat3x4 m34(1.2);
        test_assert(m34[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m34[1] == dvec4(0.0, 1.2, 0.0, 0.0));
        test_assert(m34[2] == dvec4(0.0, 0.0, 1.2, 0.0));
    }

    TEST_CASE(single_column_constructor)
    {
        CONST_OR_CONSTEXPR dmat3x2 m32(dvec2(1.2, 3.4));
        test_assert(m32[0] == dvec2(1.2, 3.4));
        test_assert(m32[1] == dvec2(1.2, 3.4));
        test_assert(m32[2] == dvec2(1.2, 3.4));

        CONST_OR_CONSTEXPR dmat3x3 m33(dvec3(1.2, 3.4, 5.6));
        test_assert(m33[0] == dvec3(1.2, 3.4, 5.6));
        test_assert(m33[1] == dvec3(1.2, 3.4, 5.6));
        test_assert(m33[2] == dvec3(1.2, 3.4, 5.6));

        CONST_OR_CONSTEXPR dmat3x4 m34(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m34[0] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m34[1] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m34[2] == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(individual_column_constructor)
    {
        test_assert(dm32[0] == dvec2(1.1, 1.2));
        test_assert(dm32[1] == dvec2(2.1, 2.2));
        test_assert(dm32[2] == dvec2(3.1, 3.2));

        test_assert(dm33[0] == dvec3(1.1, 1.2, 1.3));
        test_assert(dm33[1] == dvec3(2.1, 2.2, 2.3));
        test_assert(dm33[2] == dvec3(3.1, 3.2, 3.3));

        test_assert(dm34[0] == dvec4(1.1, 1.2, 1.3, 1.4));
        test_assert(dm34[1] == dvec4(2.1, 2.2, 2.3, 2.4));
        test_assert(dm34[2] == dvec4(3.1, 3.2, 3.3, 3.4));
    }

    TEST_CASE(extend_truncate_constructor)
    {
        CONST_OR_CONSTEXPR dmat3x2 m1(dm24);
        test_assert(m1[0] == dvec2(dm24[0]));
        test_assert(m1[1] == dvec2(dm24[1]));
        test_assert(m1[2] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat3x4 m2(dm22);
        test_assert(m2[0] == dvec4(dm22[0], 0.0, 0.0));
        test_assert(m2[1] == dvec4(dm22[1], 0.0, 0.0));
        test_assert(m2[2] == dvec4(0.0, 0.0, 1.0, 0.0));

        CONST_OR_CONSTEXPR dmat3x2 m3(dm34);
        test_assert(m3[0] == dvec2(dm34[0]));
        test_assert(m3[1] == dvec2(dm34[1]));
        test_assert(m3[2] == dvec2(dm34[2]));

        CONST_OR_CONSTEXPR dmat3x4 m4(dm32);
        test_assert(m4[0] == dvec4(dm32[0], 0.0, 0.0));
        test_assert(m4[1] == dvec4(dm32[1], 0.0, 0.0));
        test_assert(m4[2] == dvec4(dm32[2], 1.0, 0.0));

        CONST_OR_CONSTEXPR dmat3x2 m5(dm44);
        test_assert(m5[0] == dvec2(dm44[0]));
        test_assert(m5[1] == dvec2(dm44[1]));
        test_assert(m5[2] == dvec2(dm44[2]));

        CONST_OR_CONSTEXPR dmat3x4 m6(dm42);
        test_assert(m6[0] == dvec4(dm42[0], 0.0, 0.0));
        test_assert(m6[1] == dvec4(dm42[1], 0.0, 0.0));
        test_assert(m6[2] == dvec4(dm42[2], 1.0, 0.0));
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR fmat3x2 m(dm32);
        test_assert(m[0] == fvec2(dm32[0]));
        test_assert(m[1] == fvec2(dm32[1]));
        test_assert(m[2] == fvec2(dm32[2]));
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR dmat3x2 m32 = fm32;
        test_assert(m32[0] == fm32[0]);
        test_assert(m32[1] == fm32[1]);
        test_assert(m32[2] == fm32[2]);

        CONST_OR_CONSTEXPR dmat3x3 m33 = fm33;
        test_assert(m33[0] == fm33[0]);
        test_assert(m33[1] == fm33[1]);
        test_assert(m33[2] == fm33[2]);

        CONST_OR_CONSTEXPR dmat3x4 m34 = fm34;
        test_assert(m34[0] == fm34[0]);
        test_assert(m34[1] == fm34[1]);
        test_assert(m34[2] == fm34[2]);
    }

    TEST_CASE(fill)
    {
        CONST_OR_CONSTEXPR auto m32 = dmat3x2::fill(1.2);
        test_assert(m32[0] == dvec2(1.2));
        test_assert(m32[1] == dvec2(1.2));
        test_assert(m32[2] == dvec2(1.2));

        CONST_OR_CONSTEXPR auto m33 = dmat3x3::fill(1.2);
        test_assert(m33[0] == dvec3(1.2));
        test_assert(m33[1] == dvec3(1.2));
        test_assert(m33[2] == dvec3(1.2));

        CONST_OR_CONSTEXPR auto m34 = dmat3x4::fill(1.2);
        test_assert(m34[0] == dvec4(1.2));
        test_assert(m34[1] == dvec4(1.2));
        test_assert(m34[2] == dvec4(1.2));
    }

    TEST_CASE(identity)
    {
        CONST_OR_CONSTEXPR auto m32 = dmat3x2::identity();
        test_assert(m32[0] == dvec2(1.0, 0.0));
        test_assert(m32[1] == dvec2(0.0, 1.0));
        test_assert(m32[2] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR auto m33 = dmat3x3::identity();
        test_assert(m33[0] == dvec3(1.0, 0.0, 0.0));
        test_assert(m33[1] == dvec3(0.0, 1.0, 0.0));
        test_assert(m33[2] == dvec3(0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR auto m34 = dmat3x4::identity();
        test_assert(m34[0] == dvec4(1.0, 0.0, 0.0, 0.0));
        test_assert(m34[1] == dvec4(0.0, 1.0, 0.0, 0.0));
        test_assert(m34[2] == dvec4(0.0, 0.0, 1.0, 0.0));
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto m32 = dmat3x2::zero();
        test_assert(m32[0] == dvec2(0.0, 0.0));
        test_assert(m32[1] == dvec2(0.0, 0.0));
        test_assert(m32[2] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR auto m33 = dmat3x3::zero();
        test_assert(m33[0] == dvec3(0.0, 0.0, 0.0));
        test_assert(m33[1] == dvec3(0.0, 0.0, 0.0));
        test_assert(m33[2] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR auto m34 = dmat3x4::zero();
        test_assert(m34[0] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m34[1] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m34[2] == dvec4(0.0, 0.0, 0.0, 0.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dmat3x2 cem = dm32;
        CONST_OR_CONSTEXPR auto cem0 = cem[0];
        CONST_OR_CONSTEXPR auto cem1 = cem[1];
        CONST_OR_CONSTEXPR auto cem2 = cem[2];
        test_assert(cem0 == dvec2(1.1, 1.2));
        test_assert(cem1 == dvec2(2.1, 2.2));
        test_assert(cem2 == dvec2(3.1, 3.2));

        const auto cm = dm32;
        const auto& cm0 = cm[0];
        const auto& cm1 = cm[1];
        const auto& cm2 = cm[2];
        test_assert(&cm0 == cm.columns() + 0);
        test_assert(&cm1 == cm.columns() + 1);
        test_assert(&cm2 == cm.columns() + 2);

        auto m = dm32;
        auto& m0 = m[0];
        auto& m1 = m[1];
        auto& m2 = m[2];
        test_assert(&m0 == m.columns() + 0);
        test_assert(&m1 == m.columns() + 1);
        test_assert(&m2 == m.columns() + 2);
    }

    TEST_CASE(data)
    {
        const dmat3x2 cm(1.2);
        const double* cdata = cm.data();
        test_assert(cdata == static_cast<const void*>(&cm));

        dmat3x2 m;
        double* data = m.data();
        test_assert(data == static_cast<void*>(&m));
    }

    TEST_CASE(columns)
    {
        const dmat3x2 cm(1.2);
        const dvec2* ccolumns = cm.columns();
        test_assert(ccolumns == static_cast<const void*>(&cm));

        dmat3x2 m;
        dvec2* columns = m.columns();
        test_assert(columns == static_cast<void*>(&m));
    }

    TEST_CASE(column)
    {
        test_assert(dm32.column(0) == dm32[0]);
        test_assert(dm32.column(1) == dm32[1]);
        test_assert(dm32.column(2) == dm32[2]);

        test_assert(dm33.column(0) == dm33[0]);
        test_assert(dm33.column(1) == dm33[1]);
        test_assert(dm33.column(2) == dm33[2]);

        test_assert(dm34.column(0) == dm34[0]);
        test_assert(dm34.column(1) == dm34[1]);
        test_assert(dm34.column(2) == dm34[2]);
    }

    TEST_CASE(set_column)
    {
        dmat3x2 m32;
        m32.set_column(0, dvec2(0.0, 0.1));
        m32.set_column(1, dvec2(1.0, 1.1));
        m32.set_column(2, dvec2(2.0, 2.1));
        test_assert(m32.column(0) == dvec2(0.0, 0.1));
        test_assert(m32.column(1) == dvec2(1.0, 1.1));
        test_assert(m32.column(2) == dvec2(2.0, 2.1));

        dmat3x3 m33;
        m33.set_column(0, dvec3(0.0, 0.1, 0.2));
        m33.set_column(1, dvec3(1.0, 1.1, 1.2));
        m33.set_column(2, dvec3(2.0, 2.1, 2.2));
        test_assert(m33.column(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m33.column(1) == dvec3(1.0, 1.1, 1.2));
        test_assert(m33.column(2) == dvec3(2.0, 2.1, 2.2));

        dmat3x4 m34;
        m34.set_column(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m34.set_column(1, dvec4(1.0, 1.1, 1.2, 1.3));
        m34.set_column(2, dvec4(2.0, 2.1, 2.2, 2.3));
        test_assert(m34.column(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m34.column(1) == dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m34.column(2) == dvec4(2.0, 2.1, 2.2, 2.3));
    }

    TEST_CASE(row)
    {
        test_assert(dm32.row(0) == dvec3(dm32[0][0], dm32[1][0], dm32[2][0]));
        test_assert(dm32.row(1) == dvec3(dm32[0][1], dm32[1][1], dm32[2][1]));

        test_assert(dm33.row(0) == dvec3(dm33[0][0], dm33[1][0], dm33[2][0]));
        test_assert(dm33.row(1) == dvec3(dm33[0][1], dm33[1][1], dm33[2][1]));
        test_assert(dm33.row(2) == dvec3(dm33[0][2], dm33[1][2], dm33[2][2]));

        test_assert(dm34.row(0) == dvec3(dm34[0][0], dm34[1][0], dm34[2][0]));
        test_assert(dm34.row(1) == dvec3(dm34[0][1], dm34[1][1], dm34[2][1]));
        test_assert(dm34.row(2) == dvec3(dm34[0][2], dm34[1][2], dm34[2][2]));
        test_assert(dm34.row(3) == dvec3(dm34[0][3], dm34[1][3], dm34[2][3]));
    }

    TEST_CASE(set_row)
    {
        dmat3x2 m32;
        m32.set_row(0, dvec3(0.0, 0.1, 0.2));
        m32.set_row(1, dvec3(1.0, 1.1, 1.2));
        test_assert(m32.row(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m32.row(1) == dvec3(1.0, 1.1, 1.2));

        dmat3x3 m33;
        m33.set_row(0, dvec3(0.0, 0.1, 0.2));
        m33.set_row(1, dvec3(1.0, 1.1, 1.2));
        m33.set_row(2, dvec3(2.0, 2.1, 2.2));
        test_assert(m33.row(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m33.row(1) == dvec3(1.0, 1.1, 1.2));
        test_assert(m33.row(2) == dvec3(2.0, 2.1, 2.2));

        dmat3x4 m34;
        m34.set_row(0, dvec3(0.0, 0.1, 0.2));
        m34.set_row(1, dvec3(1.0, 1.1, 1.2));
        m34.set_row(2, dvec3(2.0, 2.1, 2.2));
        m34.set_row(3, dvec3(3.0, 3.1, 3.2));
        test_assert(m34.row(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m34.row(1) == dvec3(1.0, 1.1, 1.2));
        test_assert(m34.row(2) == dvec3(2.0, 2.1, 2.2));
        test_assert(m34.row(3) == dvec3(3.0, 3.1, 3.2));
    }

    TEST_CASE(pre_increment_operator)
    {
        auto m = im32;
        test_assert(&(++m) == &m);
        test_assert(m[0] == im32[0] + 1);
        test_assert(m[1] == im32[1] + 1);
        test_assert(m[2] == im32[2] + 1);
    }

    TEST_CASE(post_increment_operator)
    {
        auto m1 = im32;
        const auto m2 = m1++;
        test_assert(m1[0] == im32[0] + 1);
        test_assert(m1[1] == im32[1] + 1);
        test_assert(m1[2] == im32[2] + 1);
        test_assert(m2 == im32);
    }

    TEST_CASE(pre_decrement_operator)
    {
        auto m = im32;
        test_assert(&(--m) == &m);
        test_assert(m[0] == im32[0] - 1);
        test_assert(m[1] == im32[1] - 1);
        test_assert(m[2] == im32[2] - 1);
    }

    TEST_CASE(post_decrement_operator)
    {
        auto m1 = im32;
        const auto m2 = m1--;
        test_assert(m1[0] == im32[0] - 1);
        test_assert(m1[1] == im32[1] - 1);
        test_assert(m1[2] == im32[2] - 1);
        test_assert(m2 == im32);
    }

    TEST_CASE(addition_assignment_operator)
    {
        auto m1 = dm32;
        test_assert(&(m1 += 12) == &m1);
        test_assert(m1[0] == dm32[0] + 12);
        test_assert(m1[1] == dm32[1] + 12);
        test_assert(m1[2] == dm32[2] + 12);

        auto m2 = dm32;
        test_assert(&(m2 += im32) == &m2);
        test_assert(m2[0] == dm32[0] + im32[0]);
        test_assert(m2[1] == dm32[1] + im32[1]);
        test_assert(m2[2] == dm32[2] + im32[2]);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        auto m1 = dm32;
        test_assert(&(m1 -= 12) == &m1);
        test_assert(m1[0] == dm32[0] - 12);
        test_assert(m1[1] == dm32[1] - 12);
        test_assert(m1[2] == dm32[2] - 12);

        auto m2 = dm32;
        test_assert(&(m2 -= im32) == &m2);
        test_assert(m2[0] == dm32[0] - im32[0]);
        test_assert(m2[1] == dm32[1] - im32[1]);
        test_assert(m2[2] == dm32[2] - im32[2]);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        auto m1 = dm32;
        test_assert(&(m1 *= 12) == &m1);
        test_assert(m1[0] == dm32[0] * 12);
        test_assert(m1[1] == dm32[1] * 12);
        test_assert(m1[2] == dm32[2] * 12);

        auto m2 = dm32;
        test_assert(&(m2 *= im33) == &m2);
        test_assert(m2 == dm32 * im33);
    }

    TEST_CASE(division_assignment_operator)
    {
        auto m1 = dm32;
        test_assert(&(m1 /= 12) == &m1);
        test_assert(m1[0] == dm32[0] / 12);
        test_assert(m1[1] == dm32[1] / 12);
        test_assert(m1[2] == dm32[2] / 12);

        auto m2 = dm32;
        test_assert(&(m2 /= im32) == &m2);
        test_assert(m2[0] == dm32[0] / im32[0]);
        test_assert(m2[1] == dm32[1] / im32[1]);
        test_assert(m2[2] == dm32[2] / im32[2]);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 %= 12) == &m1);
        test_assert(m1[0] == im32[0] % 12);
        test_assert(m1[1] == im32[1] % 12);
        test_assert(m1[2] == im32[2] % 12);

        auto m2 = im32;
        test_assert(&(m2 %= sm32) == &m2);
        test_assert(m2[0] == im32[0] % sm32[0]);
        test_assert(m2[1] == im32[1] % sm32[1]);
        test_assert(m2[2] == im32[2] % sm32[2]);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 &= 12) == &m1);
        test_assert(m1[0] == (im32[0] & 12));
        test_assert(m1[1] == (im32[1] & 12));
        test_assert(m1[2] == (im32[2] & 12));

        auto m2 = im32;
        test_assert(&(m2 &= sm32) == &m2);
        test_assert(m2[0] == (im32[0] & sm32[0]));
        test_assert(m2[1] == (im32[1] & sm32[1]));
        test_assert(m2[2] == (im32[2] & sm32[2]));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 |= 12) == &m1);
        test_assert(m1[0] == (im32[0] | 12));
        test_assert(m1[1] == (im32[1] | 12));
        test_assert(m1[2] == (im32[2] | 12));

        auto m2 = im32;
        test_assert(&(m2 |= sm32) == &m2);
        test_assert(m2[0] == (im32[0] | sm32[0]));
        test_assert(m2[1] == (im32[1] | sm32[1]));
        test_assert(m2[2] == (im32[2] | sm32[2]));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 ^= 12) == &m1);
        test_assert(m1[0] == (im32[0] ^ 12));
        test_assert(m1[1] == (im32[1] ^ 12));
        test_assert(m1[2] == (im32[2] ^ 12));

        auto m2 = im32;
        test_assert(&(m2 ^= sm32) == &m2);
        test_assert(m2[0] == (im32[0] ^ sm32[0]));
        test_assert(m2[1] == (im32[1] ^ sm32[1]));
        test_assert(m2[2] == (im32[2] ^ sm32[2]));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 <<= 12) == &m1);
        test_assert(m1[0] == (im32[0] << 12));
        test_assert(m1[1] == (im32[1] << 12));
        test_assert(m1[2] == (im32[2] << 12));

        auto m2 = im32;
        test_assert(&(m2 <<= sm32) == &m2);
        test_assert(m2[0] == (im32[0] << sm32[0]));
        test_assert(m2[1] == (im32[1] << sm32[1]));
        test_assert(m2[2] == (im32[2] << sm32[2]));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        auto m1 = im32;
        test_assert(&(m1 >>= 12) == &m1);
        test_assert(m1[0] == (im32[0] >> 12));
        test_assert(m1[1] == (im32[1] >> 12));
        test_assert(m1[2] == (im32[2] >> 12));

        auto m2 = im32;
        test_assert(&(m2 >>= sm32) == &m2);
        test_assert(m2[0] == (im32[0] >> sm32[0]));
        test_assert(m2[1] == (im32[1] >> sm32[1]));
        test_assert(m2[2] == (im32[2] >> sm32[2]));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto m = +dm32;
        test_assert(m == dmat3x2(+dm32[0], +dm32[1], +dm32[2]));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto m = -dm32;
        test_assert(m == dmat3x2(-dm32[0], -dm32[1], -dm32[2]));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto m = ~im32;
        test_assert(m == mat3x2<int>(~im32[0], ~im32[1], ~im32[2]));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 + dm32;
        test_assert(m1[0] == 12 + dm32[0]);
        test_assert(m1[1] == 12 + dm32[1]);
        test_assert(m1[2] == 12 + dm32[2]);

        CONST_OR_CONSTEXPR auto m2 = dm32 + 12;
        test_assert(m2[0] == dm32[0] + 12);
        test_assert(m2[1] == dm32[1] + 12);
        test_assert(m2[2] == dm32[2] + 12);

        CONST_OR_CONSTEXPR auto m3 = dm32 + im32;
        test_assert(m3[0] == dm32[0] + im32[0]);
        test_assert(m3[1] == dm32[1] + im32[1]);
        test_assert(m3[2] == dm32[2] + im32[2]);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 - dm32;
        test_assert(m1[0] == 12 - dm32[0]);
        test_assert(m1[1] == 12 - dm32[1]);
        test_assert(m1[2] == 12 - dm32[2]);

        CONST_OR_CONSTEXPR auto m2 = dm32 - 12;
        test_assert(m2[0] == dm32[0] - 12);
        test_assert(m2[1] == dm32[1] - 12);
        test_assert(m2[2] == dm32[2] - 12);

        CONST_OR_CONSTEXPR auto m3 = dm32 - im32;
        test_assert(m3[0] == dm32[0] - im32[0]);
        test_assert(m3[1] == dm32[1] - im32[1]);
        test_assert(m3[2] == dm32[2] - im32[2]);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 * dm32;
        test_assert(m1[0] == 12 * dm32[0]);
        test_assert(m1[1] == 12 * dm32[1]);
        test_assert(m1[2] == 12 * dm32[2]);

        CONST_OR_CONSTEXPR auto m2 = dm32 * 12;
        test_assert(m2[0] == dm32[0] * 12);
        test_assert(m2[1] == dm32[1] * 12);
        test_assert(m2[2] == dm32[2] * 12);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 / dm32;
        test_assert(m1[0] == 12 / dm32[0]);
        test_assert(m1[1] == 12 / dm32[1]);
        test_assert(m1[2] == 12 / dm32[2]);

        CONST_OR_CONSTEXPR auto m2 = dm32 / 12;
        test_assert(m2[0] == dm32[0] / 12);
        test_assert(m2[1] == dm32[1] / 12);
        test_assert(m2[2] == dm32[2] / 12);

        CONST_OR_CONSTEXPR auto m3 = dm32 / im32;
        test_assert(m3[0] == dm32[0] / im32[0]);
        test_assert(m3[1] == dm32[1] / im32[1]);
        test_assert(m3[2] == dm32[2] / im32[2]);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 % sm32;
        test_assert(m1[0] == 123 % sm32[0]);
        test_assert(m1[1] == 123 % sm32[1]);
        test_assert(m1[2] == 123 % sm32[2]);

        CONST_OR_CONSTEXPR auto m2 = im32 % 12;
        test_assert(m2[0] == im32[0] % 12);
        test_assert(m2[1] == im32[1] % 12);
        test_assert(m2[2] == im32[2] % 12);

        CONST_OR_CONSTEXPR auto m3 = im32 % sm32;
        test_assert(m3[0] == im32[0] % sm32[0]);
        test_assert(m3[1] == im32[1] % sm32[1]);
        test_assert(m3[2] == im32[2] % sm32[2]);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 & sm32;
        test_assert(m1[0] == (123 & sm32[0]));
        test_assert(m1[1] == (123 & sm32[1]));
        test_assert(m1[2] == (123 & sm32[2]));

        CONST_OR_CONSTEXPR auto m2 = im32 & 12;
        test_assert(m2[0] == (im32[0] & 12));
        test_assert(m2[1] == (im32[1] & 12));
        test_assert(m2[2] == (im32[2] & 12));

        CONST_OR_CONSTEXPR auto m3 = im32 & sm32;
        test_assert(m3[0] == (im32[0] & sm32[0]));
        test_assert(m3[1] == (im32[1] & sm32[1]));
        test_assert(m3[2] == (im32[2] & sm32[2]));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 | sm32;
        test_assert(m1[0] == (123 | sm32[0]));
        test_assert(m1[1] == (123 | sm32[1]));
        test_assert(m1[2] == (123 | sm32[2]));

        CONST_OR_CONSTEXPR auto m2 = im32 | 12;
        test_assert(m2[0] == (im32[0] | 12));
        test_assert(m2[1] == (im32[1] | 12));
        test_assert(m2[2] == (im32[2] | 12));

        CONST_OR_CONSTEXPR auto m3 = im32 | sm32;
        test_assert(m3[0] == (im32[0] | sm32[0]));
        test_assert(m3[1] == (im32[1] | sm32[1]));
        test_assert(m3[2] == (im32[2] | sm32[2]));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 ^ sm32;
        test_assert(m1[0] == (123 ^ sm32[0]));
        test_assert(m1[1] == (123 ^ sm32[1]));
        test_assert(m1[2] == (123 ^ sm32[2]));

        CONST_OR_CONSTEXPR auto m2 = im32 ^ 12;
        test_assert(m2[0] == (im32[0] ^ 12));
        test_assert(m2[1] == (im32[1] ^ 12));
        test_assert(m2[2] == (im32[2] ^ 12));

        CONST_OR_CONSTEXPR auto m3 = im32 ^ sm32;
        test_assert(m3[0] == (im32[0] ^ sm32[0]));
        test_assert(m3[1] == (im32[1] ^ sm32[1]));
        test_assert(m3[2] == (im32[2] ^ sm32[2]));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 << sm32;
        test_assert(m1[0] == (123 << sm32[0]));
        test_assert(m1[1] == (123 << sm32[1]));
        test_assert(m1[2] == (123 << sm32[2]));

        CONST_OR_CONSTEXPR auto m2 = im32 << 1;
        test_assert(m2[0] == (im32[0] << 1));
        test_assert(m2[1] == (im32[1] << 1));
        test_assert(m2[2] == (im32[2] << 1));

        CONST_OR_CONSTEXPR auto m3 = im32 << sm32;
        test_assert(m3[0] == (im32[0] << sm32[0]));
        test_assert(m3[1] == (im32[1] << sm32[1]));
        test_assert(m3[2] == (im32[2] << sm32[2]));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 >> sm32;
        test_assert(m1[0] == (123 >> sm32[0]));
        test_assert(m1[1] == (123 >> sm32[1]));
        test_assert(m1[2] == (123 >> sm32[2]));

        CONST_OR_CONSTEXPR auto m2 = im32 >> 1;
        test_assert(m2[0] == (im32[0] >> 1));
        test_assert(m2[1] == (im32[1] >> 1));
        test_assert(m2[2] == (im32[2] >> 1));

        CONST_OR_CONSTEXPR auto m3 = im32 >> sm32;
        test_assert(m3[0] == (im32[0] >> sm32[0]));
        test_assert(m3[1] == (im32[1] >> sm32[1]));
        test_assert(m3[2] == (im32[2] >> sm32[2]));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fmat3x2 m1(fvec2(1.2f), fvec2(3.4f), fvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m2(dvec2(1.2f), dvec2(3.4f), dvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m3(dvec2(1.2f), dvec2(3.4f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat3x2 m4(dvec2(1.2f), dvec2(0.0f), dvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m5(dvec2(0.0f), dvec2(3.4f), dvec2(5.6f));
        CONST_OR_CONSTEXPR auto result1 = (m1 == m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 == m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 == m4);
        CONST_OR_CONSTEXPR auto result4 = (m1 == m5);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fmat3x2 m1(fvec2(1.2f), fvec2(3.4f), fvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m2(dvec2(1.2f), dvec2(3.4f), dvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m3(dvec2(1.2f), dvec2(3.4f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat3x2 m4(dvec2(1.2f), dvec2(0.0f), dvec2(5.6f));
        CONST_OR_CONSTEXPR dmat3x2 m5(dvec2(0.0f), dvec2(3.4f), dvec2(5.6f));
        CONST_OR_CONSTEXPR auto result1 = (m1 != m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 != m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 != m4);
        CONST_OR_CONSTEXPR auto result4 = (m1 != m5);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
    }

    TEST_CASE(sin)
    {
        const auto m = math::sin(dm32);
        test_assert(m[0] == math::sin(dm32[0]));
        test_assert(m[1] == math::sin(dm32[1]));
        test_assert(m[2] == math::sin(dm32[2]));
    }

    TEST_CASE(cos)
    {
        const auto m = math::cos(dm32);
        test_assert(m[0] == math::cos(dm32[0]));
        test_assert(m[1] == math::cos(dm32[1]));
        test_assert(m[2] == math::cos(dm32[2]));
    }

    TEST_CASE(sincos)
    {
        dmat3x2 s, c;
        math::sincos(dm32, s, c);

        test_assert(s[0] == math::sin(dm32[0]));
        test_assert(s[1] == math::sin(dm32[1]));
        test_assert(s[2] == math::sin(dm32[2]));

        test_assert(c[0] == math::cos(dm32[0]));
        test_assert(c[1] == math::cos(dm32[1]));
        test_assert(c[2] == math::cos(dm32[2]));
    }

    TEST_CASE(exp)
    {
        const auto m = math::exp(dm32);
        test_assert(m[0] == math::exp(dm32[0]));
        test_assert(m[1] == math::exp(dm32[1]));
        test_assert(m[2] == math::exp(dm32[2]));
    }

    TEST_CASE(log)
    {
        const auto m = math::log(dm32);
        test_assert(m[0] == math::log(dm32[0]));
        test_assert(m[1] == math::log(dm32[1]));
        test_assert(m[2] == math::log(dm32[2]));
    }

    TEST_CASE(abs)
    {
        const auto m = math::abs(dm322);
        test_assert(m[0] == math::abs(dm322[0]));
        test_assert(m[1] == math::abs(dm322[1]));
        test_assert(m[2] == math::abs(dm322[2]));
    }

    TEST_CASE(pow)
    {
        const auto m = math::pow(dm32, dm322);
        test_assert(m[0] == math::pow(dm32[0], dm322[0]));
        test_assert(m[1] == math::pow(dm32[1], dm322[1]));
        test_assert(m[2] == math::pow(dm32[2], dm322[2]));
    }

    TEST_CASE(recip)
    {
        const auto m = math::recip(dm32);
        test_assert(m[0] == math::recip(dm32[0]));
        test_assert(m[1] == math::recip(dm32[1]));
        test_assert(m[2] == math::recip(dm32[2]));
    }

    TEST_CASE(sqrt)
    {
        const auto m = math::sqrt(dm32);
        test_assert(m[0] == math::sqrt(dm32[0]));
        test_assert(m[1] == math::sqrt(dm32[1]));
        test_assert(m[2] == math::sqrt(dm32[2]));
    }

    TEST_CASE(rsqrt)
    {
        const auto m = math::rsqrt(dm32);
        test_assert(m[0] == math::rsqrt(dm32[0]));
        test_assert(m[1] == math::rsqrt(dm32[1]));
        test_assert(m[2] == math::rsqrt(dm32[2]));
    }

    TEST_CASE(min)
    {
        const auto m = math::min(dm32, dm322);
        test_assert(m[0] == math::min(dm32[0], dm322[0]));
        test_assert(m[1] == math::min(dm32[1], dm322[1]));
        test_assert(m[2] == math::min(dm32[2], dm322[2]));
    }

    TEST_CASE(max)
    {
        const auto m = math::max(dm32, dm322);
        test_assert(m[0] == math::max(dm32[0], dm322[0]));
        test_assert(m[1] == math::max(dm32[1], dm322[1]));
        test_assert(m[2] == math::max(dm32[2], dm322[2]));
    }

    TEST_CASE(mask)
    {
        const auto m = math::mask(bm32, dm32);
        test_assert(m[0] == math::mask(bm32[0], dm32[0]));
        test_assert(m[1] == math::mask(bm32[1], dm32[1]));
        test_assert(m[2] == math::mask(bm32[2], dm32[2]));
    }

    TEST_CASE(select)
    {
        const auto m = math::select(bm32, dm32, dm322);
        test_assert(m[0] == math::select(bm32[0], dm32[0], dm322[0]));
        test_assert(m[1] == math::select(bm32[1], dm32[1], dm322[1]));
        test_assert(m[2] == math::select(bm32[2], dm32[2], dm322[2]));
    }

    TEST_CASE(less)
    {
        const auto m = math::less(dm32, dm322);
        test_assert(m[0] == math::less(dm32[0], dm322[0]));
        test_assert(m[1] == math::less(dm32[1], dm322[1]));
        test_assert(m[2] == math::less(dm32[2], dm322[2]));
    }

    TEST_CASE(less_equal)
    {
        const auto m = math::less_equal(dm32, dm322);
        test_assert(m[0] == math::less_equal(dm32[0], dm322[0]));
        test_assert(m[1] == math::less_equal(dm32[1], dm322[1]));
        test_assert(m[2] == math::less_equal(dm32[2], dm322[2]));
    }

    TEST_CASE(greater)
    {
        const auto m = math::greater(dm32, dm322);
        test_assert(m[0] == math::greater(dm32[0], dm322[0]));
        test_assert(m[1] == math::greater(dm32[1], dm322[1]));
        test_assert(m[2] == math::greater(dm32[2], dm322[2]));
    }

    TEST_CASE(greater_equal)
    {
        const auto m = math::greater_equal(dm32, dm322);
        test_assert(m[0] == math::greater_equal(dm32[0], dm322[0]));
        test_assert(m[1] == math::greater_equal(dm32[1], dm322[1]));
        test_assert(m[2] == math::greater_equal(dm32[2], dm322[2]));
    }

    TEST_CASE(equal)
    {
        const auto m = math::equal(dm32, dm322);
        test_assert(m[0] == math::equal(dm32[0], dm322[0]));
        test_assert(m[1] == math::equal(dm32[1], dm322[1]));
        test_assert(m[2] == math::equal(dm32[2], dm322[2]));
    }

    TEST_CASE(not_equal)
    {
        const auto m = math::not_equal(dm32, dm322);
        test_assert(m[0] == math::not_equal(dm32[0], dm322[0]));
        test_assert(m[1] == math::not_equal(dm32[1], dm322[1]));
        test_assert(m[2] == math::not_equal(dm32[2], dm322[2]));
    }

    TEST_CASE(comp_mult)
    {
        CONST_OR_CONSTEXPR auto m = math::comp_mult(dm32, im32);
        test_assert(m[0] == dm32[0] * im32[0]);
        test_assert(m[1] == dm32[1] * im32[1]);
        test_assert(m[2] == dm32[2] * im32[2]);
    }

    TEST_CASE(transpose)
    {
        CONST_OR_CONSTEXPR auto m1 = math::transpose(dm32);
        test_assert(m1[0] == dm32.row(0));
        test_assert(m1[1] == dm32.row(1));

        CONST_OR_CONSTEXPR auto m2 = math::transpose(dm33);
        test_assert(m2[0] == dm33.row(0));
        test_assert(m2[1] == dm33.row(1));
        test_assert(m2[2] == dm33.row(2));

        CONST_OR_CONSTEXPR auto m3 = math::transpose(dm34);
        test_assert(m3[0] == dm34.row(0));
        test_assert(m3[1] == dm34.row(1));
        test_assert(m3[2] == dm34.row(2));
        test_assert(m3[3] == dm34.row(3));
    }
}
