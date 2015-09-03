//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/mat.hpp>
#include <mon/test_case.hpp>

#include <type_traits>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    CONST_OR_CONSTEXPR fmat4x2 fm420 = {
        { 0.0f, 0.1f },
        { 1.0f, 1.1f },
        { 2.0f, 2.1f },
        { 3.0f, 3.1f },
    };

    CONST_OR_CONSTEXPR fmat4x3 fm430 = {
        { 0.0f, 0.1f, 0.2f },
        { 1.0f, 1.1f, 1.2f },
        { 2.0f, 2.1f, 2.2f },
        { 3.0f, 3.1f, 3.2f },
    };

    CONST_OR_CONSTEXPR fmat4x4 fm440 = {
        { 0.0f, 0.1f, 0.2f, 0.3f },
        { 1.0f, 1.1f, 1.2f, 1.3f },
        { 2.0f, 2.1f, 2.2f, 2.3f },
        { 3.0f, 3.1f, 3.2f, 3.3f },
    };

    CONST_OR_CONSTEXPR dmat4x2 dm420 = {
        { 0.0, 0.1 },
        { 1.0, 1.1 },
        { 2.0, 2.1 },
        { 3.0, 3.1 },
    };

    CONST_OR_CONSTEXPR dmat4x3 dm430 = {
        { 0.0, 0.1, 0.2 },
        { 1.0, 1.1, 1.2 },
        { 2.0, 2.1, 2.2 },
        { 3.0, 3.1, 3.2 },
    };

    CONST_OR_CONSTEXPR dmat4x4 dm440 = {
        { 0.0, 0.1, 0.2, 0.3 },
        { 1.0, 1.1, 1.2, 1.3 },
        { 2.0, 2.1, 2.2, 2.3 },
        { 3.0, 3.1, 3.2, 3.3 },
    };

    CONST_OR_CONSTEXPR mat4x2<int> im420 = {
        { 00, 01 },
        { 10, 11 },
        { 20, 21 },
        { 30, 31 },
    };

    TEST_CASE(size)
    {
        test_assert(sizeof(mat<short, 4, 2>) == sizeof(short) * 4 * 2);
        test_assert(sizeof(mat<short, 4, 3>) == sizeof(short) * 4 * 3);
        test_assert(sizeof(mat<short, 4, 4>) == sizeof(short) * 4 * 4);
        test_assert(sizeof(mat4x2<short>) == sizeof(short) * 4 * 2);
        test_assert(sizeof(mat4x3<short>) == sizeof(short) * 4 * 3);
        test_assert(sizeof(mat4x4<short>) == sizeof(short) * 4 * 4);
        test_assert(sizeof(fmat4x2) == sizeof(float) * 4 * 2);
        test_assert(sizeof(fmat4x3) == sizeof(float) * 4 * 3);
        test_assert(sizeof(fmat4x4) == sizeof(float) * 4 * 4);
        test_assert(sizeof(dmat4x2) == sizeof(double) * 4 * 2);
        test_assert(sizeof(dmat4x3) == sizeof(double) * 4 * 3);
        test_assert(sizeof(dmat4x4) == sizeof(double) * 4 * 4);
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(mat<short, 4, 2>) == alignof(short));
        test_assert(alignof(mat<short, 4, 3>) == alignof(short));
        test_assert(alignof(mat<short, 4, 4>) == alignof(short));
        test_assert(alignof(mat4x2<short>) == alignof(short));
        test_assert(alignof(mat4x3<short>) == alignof(short));
        test_assert(alignof(mat4x4<short>) == alignof(short));
        test_assert(alignof(fmat4x2) == alignof(float));
        test_assert(alignof(fmat4x3) == alignof(float));
        test_assert(alignof(fmat4x4) == alignof(float));
        test_assert(alignof(dmat4x2) == alignof(double));
        test_assert(alignof(dmat4x3) == alignof(double));
        test_assert(alignof(dmat4x4) == alignof(double));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename mat<short, 4, 2>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 4, 3>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat<short, 4, 4>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat4x2<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat4x3<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename mat4x4<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fmat4x2::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat4x3::component_type, float>::value));
        test_assert((std::is_same<
            typename fmat4x4::component_type, float>::value));
        test_assert((std::is_same<
            typename dmat4x2::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat4x3::component_type, double>::value));
        test_assert((std::is_same<
            typename dmat4x4::component_type, double>::value));
    }

    TEST_CASE(column_count)
    {
        test_assert((mat<short, 4, 2>::column_count == 4));
        test_assert((mat<short, 4, 3>::column_count == 4));
        test_assert((mat<short, 4, 4>::column_count == 4));
        test_assert((mat4x2<short>::column_count == 4));
        test_assert((mat4x3<short>::column_count == 4));
        test_assert((mat4x4<short>::column_count == 4));
        test_assert((fmat4x2::column_count == 4));
        test_assert((fmat4x3::column_count == 4));
        test_assert((fmat4x4::column_count == 4));
        test_assert((dmat4x2::column_count == 4));
        test_assert((dmat4x3::column_count == 4));
        test_assert((dmat4x4::column_count == 4));
    }

    TEST_CASE(row_count)
    {
        test_assert((mat<short, 4, 2>::row_count == 2));
        test_assert((mat<short, 4, 3>::row_count == 3));
        test_assert((mat<short, 4, 4>::row_count == 4));
        test_assert((mat4x2<short>::row_count == 2));
        test_assert((mat4x3<short>::row_count == 3));
        test_assert((mat4x4<short>::row_count == 4));
        test_assert((fmat4x2::row_count == 2));
        test_assert((fmat4x3::row_count == 3));
        test_assert((fmat4x4::row_count == 4));
        test_assert((dmat4x2::row_count == 2));
        test_assert((dmat4x3::row_count == 3));
        test_assert((dmat4x4::row_count == 4));
    }

    TEST_CASE(component_count)
    {
        test_assert((mat<short, 4, 2>::component_count == 4 * 2));
        test_assert((mat<short, 4, 3>::component_count == 4 * 3));
        test_assert((mat<short, 4, 4>::component_count == 4 * 4));
        test_assert((mat4x2<short>::component_count == 4 * 2));
        test_assert((mat4x3<short>::component_count == 4 * 3));
        test_assert((mat4x4<short>::component_count == 4 * 4));
        test_assert((fmat4x2::component_count == 4 * 2));
        test_assert((fmat4x3::component_count == 4 * 3));
        test_assert((fmat4x4::component_count == 4 * 4));
        test_assert((dmat4x2::component_count == 4 * 2));
        test_assert((dmat4x3::component_count == 4 * 3));
        test_assert((dmat4x4::component_count == 4 * 4));
    }

    TEST_CASE(default_constructor)
    {
        dmat4x2 m;
        tue::unused(m);
    }

    TEST_CASE(main_diagonal_constructor)
    {
        CONST_OR_CONSTEXPR dmat4x2 m42(1.2);
        test_assert(m42[0] == dvec2(1.2, 0.0));
        test_assert(m42[1] == dvec2(0.0, 1.2));
        test_assert(m42[2] == dvec2(0.0, 0.0));
        test_assert(m42[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x3 m43(1.2);
        test_assert(m43[0] == dvec3(1.2, 0.0, 0.0));
        test_assert(m43[1] == dvec3(0.0, 1.2, 0.0));
        test_assert(m43[2] == dvec3(0.0, 0.0, 1.2));
        test_assert(m43[3] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x4 m44(1.2);
        test_assert(m44[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m44[1] == dvec4(0.0, 1.2, 0.0, 0.0));
        test_assert(m44[2] == dvec4(0.0, 0.0, 1.2, 0.0));
        test_assert(m44[3] == dvec4(0.0, 0.0, 0.0, 1.2));
    }

    TEST_CASE(individual_columns_constructor)
    {
        test_assert(dm420[0] == dvec2(0.0, 0.1));
        test_assert(dm420[1] == dvec2(1.0, 1.1));
        test_assert(dm420[2] == dvec2(2.0, 2.1));
        test_assert(dm420[3] == dvec2(3.0, 3.1));

        test_assert(dm430[0] == dvec3(0.0, 0.1, 0.2));
        test_assert(dm430[1] == dvec3(1.0, 1.1, 1.2));
        test_assert(dm430[2] == dvec3(2.0, 2.1, 2.2));
        test_assert(dm430[3] == dvec3(3.0, 3.1, 3.2));

        test_assert(dm440[0] == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(dm440[1] == dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(dm440[2] == dvec4(2.0, 2.1, 2.2, 2.3));
        test_assert(dm440[3] == dvec4(3.0, 3.1, 3.2, 3.3));
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        // TODO
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR dmat4x2 m42 = fm420;
        test_assert(m42[0] == fm420[0]);
        test_assert(m42[1] == fm420[1]);
        test_assert(m42[2] == fm420[2]);
        test_assert(m42[3] == fm420[3]);

        CONST_OR_CONSTEXPR dmat4x3 m43 = fm430;
        test_assert(m43[0] == fm430[0]);
        test_assert(m43[1] == fm430[1]);
        test_assert(m43[2] == fm430[2]);
        test_assert(m43[3] == fm430[3]);

        CONST_OR_CONSTEXPR dmat4x4 m44 = fm440;
        test_assert(m44[0] == fm440[0]);
        test_assert(m44[1] == fm440[1]);
        test_assert(m44[2] == fm440[2]);
        test_assert(m44[3] == fm440[3]);
    }

    TEST_CASE(identity)
    {
        CONST_OR_CONSTEXPR auto m42 = dmat4x2::identity();
        test_assert(m42[0] == dvec2(1.0, 0.0));
        test_assert(m42[1] == dvec2(0.0, 1.0));
        test_assert(m42[2] == dvec2(0.0, 0.0));
        test_assert(m42[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR auto m43 = dmat4x3::identity();
        test_assert(m43[0] == dvec3(1.0, 0.0, 0.0));
        test_assert(m43[1] == dvec3(0.0, 1.0, 0.0));
        test_assert(m43[2] == dvec3(0.0, 0.0, 1.0));
        test_assert(m43[3] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR auto m44 = dmat4x4::identity();
        test_assert(m44[0] == dvec4(1.0, 0.0, 0.0, 0.0));
        test_assert(m44[1] == dvec4(0.0, 1.0, 0.0, 0.0));
        test_assert(m44[2] == dvec4(0.0, 0.0, 1.0, 0.0));
        test_assert(m44[3] == dvec4(0.0, 0.0, 0.0, 1.0));
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto m42 = dmat4x2::zero();
        test_assert(m42[0] == dvec2(0.0, 0.0));
        test_assert(m42[1] == dvec2(0.0, 0.0));
        test_assert(m42[2] == dvec2(0.0, 0.0));
        test_assert(m42[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR auto m43 = dmat4x3::zero();
        test_assert(m43[0] == dvec3(0.0, 0.0, 0.0));
        test_assert(m43[1] == dvec3(0.0, 0.0, 0.0));
        test_assert(m43[2] == dvec3(0.0, 0.0, 0.0));
        test_assert(m43[3] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR auto m44 = dmat4x4::zero();
        test_assert(m44[0] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m44[1] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m44[2] == dvec4(0.0, 0.0, 0.0, 0.0));
        test_assert(m44[3] == dvec4(0.0, 0.0, 0.0, 0.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dmat4x2 cem = dm420;
        CONST_OR_CONSTEXPR auto cem0 = cem[0];
        CONST_OR_CONSTEXPR auto cem1 = cem[1];
        CONST_OR_CONSTEXPR auto cem2 = cem[2];
        CONST_OR_CONSTEXPR auto cem3 = cem[3];
        test_assert(cem0 == dvec2(0.0, 0.1));
        test_assert(cem1 == dvec2(1.0, 1.1));
        test_assert(cem2 == dvec2(2.0, 2.1));
        test_assert(cem3 == dvec2(3.0, 3.1));

        const auto cm = dm420;
        const auto& cm0 = cm[0];
        const auto& cm1 = cm[1];
        const auto& cm2 = cm[2];
        const auto& cm3 = cm[3];
        test_assert(&cm0 == cm.columns() + 0);
        test_assert(&cm1 == cm.columns() + 1);
        test_assert(&cm2 == cm.columns() + 2);
        test_assert(&cm3 == cm.columns() + 3);

        auto m = dm420;
        auto& m0 = m[0];
        auto& m1 = m[1];
        auto& m2 = m[2];
        auto& m3 = m[3];
        test_assert(&m0 == m.columns() + 0);
        test_assert(&m1 == m.columns() + 1);
        test_assert(&m2 == m.columns() + 2);
        test_assert(&m3 == m.columns() + 3);
    }

    TEST_CASE(data)
    {
        const dmat4x2 cm(1.2);
        const double* cdata = cm.data();
        test_assert(cdata == static_cast<const void*>(&cm));

        dvec4 m;
        double* data = m.data();
        test_assert(data == static_cast<void*>(&m));
    }

    TEST_CASE(columns)
    {
        const dmat4x2 cm(1.2);
        const dvec2* cdata = cm.columns();
        test_assert(cdata == static_cast<const void*>(&cm));

        dmat4x2 m;
        dvec2* data = m.columns();
        test_assert(data == static_cast<void*>(&m));
    }

    TEST_CASE(column)
    {
        test_assert(dm420.column(0) == dm420[0]);
        test_assert(dm420.column(1) == dm420[1]);
        test_assert(dm420.column(2) == dm420[2]);
        test_assert(dm420.column(3) == dm420[3]);

        test_assert(dm430.column(0) == dm430[0]);
        test_assert(dm430.column(1) == dm430[1]);
        test_assert(dm430.column(2) == dm430[2]);
        test_assert(dm430.column(3) == dm430[3]);

        test_assert(dm440.column(0) == dm440[0]);
        test_assert(dm440.column(1) == dm440[1]);
        test_assert(dm440.column(2) == dm440[2]);
        test_assert(dm440.column(3) == dm440[3]);
    }

    TEST_CASE(row)
    {
        test_assert(dm420.row(0) ==
            dvec4(dm420[0][0], dm420[1][0], dm420[2][0], dm420[3][0]));
        test_assert(dm420.row(1) ==
            dvec4(dm420[0][1], dm420[1][1], dm420[2][1], dm420[3][1]));

        test_assert(dm430.row(0) ==
            dvec4(dm430[0][0], dm430[1][0], dm430[2][0], dm430[3][0]));
        test_assert(dm430.row(1) ==
            dvec4(dm430[0][1], dm430[1][1], dm430[2][1], dm430[3][1]));
        test_assert(dm430.row(2) ==
            dvec4(dm430[0][2], dm430[1][2], dm430[2][2], dm430[3][2]));

        test_assert(dm440.row(0) ==
            dvec4(dm440[0][0], dm440[1][0], dm440[2][0], dm440[3][0]));
        test_assert(dm440.row(1) ==
            dvec4(dm440[0][1], dm440[1][1], dm440[2][1], dm440[3][1]));
        test_assert(dm440.row(2) ==
            dvec4(dm440[0][2], dm440[1][2], dm440[2][2], dm440[3][2]));
        test_assert(dm440.row(3) ==
            dvec4(dm440[0][3], dm440[1][3], dm440[2][3], dm440[3][3]));
    }

    TEST_CASE(set_column)
    {
        dmat4x2 m42 = dm420;
        m42.set_column(0, dvec2(20.0, 20.1));
        m42.set_column(1, dvec2(21.0, 21.1));
        m42.set_column(2, dvec2(22.0, 22.1));
        m42.set_column(3, dvec2(23.0, 23.1));
        test_assert(m42.column(0) == dvec2(20.0, 20.1));
        test_assert(m42.column(1) == dvec2(21.0, 21.1));
        test_assert(m42.column(2) == dvec2(22.0, 22.1));
        test_assert(m42.column(3) == dvec2(23.0, 23.1));
        
        dmat4x3 m43 = dm430;
        m43.set_column(0, dvec3(20.0, 20.1, 20.2));
        m43.set_column(1, dvec3(21.0, 21.1, 21.2));
        m43.set_column(2, dvec3(22.0, 22.1, 22.2));
        m43.set_column(3, dvec3(23.0, 23.1, 23.2));
        test_assert(m43.column(0) == dvec3(20.0, 20.1, 20.2));
        test_assert(m43.column(1) == dvec3(21.0, 21.1, 21.2));
        test_assert(m43.column(2) == dvec3(22.0, 22.1, 22.2));
        test_assert(m43.column(3) == dvec3(23.0, 23.1, 23.2));
        
        dmat4x4 m44;
        m44.set_column(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m44.set_column(1, dvec4(1.0, 1.1, 1.2, 1.3));
        m44.set_column(2, dvec4(2.0, 2.1, 2.2, 2.3));
        m44.set_column(3, dvec4(3.0, 3.1, 3.2, 3.3));
        test_assert(m44.column(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m44.column(1) == dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m44.column(2) == dvec4(2.0, 2.1, 2.2, 2.3));
        test_assert(m44.column(3) == dvec4(3.0, 3.1, 3.2, 3.3));
    }

    TEST_CASE(set_row)
    {
        dmat4x2 m42;
        m42.set_row(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m42.set_row(1, dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m42.row(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m42.row(1) == dvec4(1.0, 1.1, 1.2, 1.3));
        
        dmat4x3 m43;
        m43.set_row(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m43.set_row(1, dvec4(1.0, 1.1, 1.2, 1.3));
        m43.set_row(2, dvec4(2.0, 2.1, 2.2, 2.3));
        test_assert(m43.row(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m43.row(1) == dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m43.row(2) == dvec4(2.0, 2.1, 2.2, 2.3));
        
        dmat4x4 m44;
        m44.set_row(0, dvec4(0.0, 0.1, 0.2, 0.3));
        m44.set_row(1, dvec4(1.0, 1.1, 1.2, 1.3));
        m44.set_row(2, dvec4(2.0, 2.1, 2.2, 2.3));
        m44.set_row(3, dvec4(3.0, 3.1, 3.2, 3.3));
        test_assert(m44.row(0) == dvec4(0.0, 0.1, 0.2, 0.3));
        test_assert(m44.row(1) == dvec4(1.0, 1.1, 1.2, 1.3));
        test_assert(m44.row(2) == dvec4(2.0, 2.1, 2.2, 2.3));
        test_assert(m44.row(3) == dvec4(3.0, 3.1, 3.2, 3.3));
    }

    TEST_CASE(pre_increment_operator)
    {
        mat4x2<int> m = im420;
        test_assert(&(++m) == &m);
        test_assert(m[0] == im420[0] + 1);
        test_assert(m[1] == im420[1] + 1);
        test_assert(m[2] == im420[2] + 1);
        test_assert(m[3] == im420[3] + 1);
    }

    TEST_CASE(post_increment_operator)
    {
        mat4x2<int> m1 = im420;
        const mat4x2<int> m2 = m1++;
        test_assert(m1[0] == im420[0] + 1);
        test_assert(m1[1] == im420[1] + 1);
        test_assert(m1[2] == im420[2] + 1);
        test_assert(m1[3] == im420[3] + 1);
        test_assert(m2 == im420);
    }
}
