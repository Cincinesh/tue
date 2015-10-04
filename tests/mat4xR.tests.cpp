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

    CONST_OR_CONSTEXPR fmat4x2 fm42 = {
        { 1.1f, 1.2f },
        { 2.1f, 2.2f },
        { 3.1f, 3.2f },
        { 4.1f, 4.2f },
    };

    CONST_OR_CONSTEXPR fmat4x3 fm43 = {
        { 1.1f, 1.2f, 1.3f },
        { 2.1f, 2.2f, 2.3f },
        { 3.1f, 3.2f, 3.3f },
        { 4.1f, 4.2f, 4.3f },
    };

    CONST_OR_CONSTEXPR fmat4x4 fm44 = {
        { 1.1f, 1.2f, 1.3f, 1.4f },
        { 2.1f, 2.2f, 2.3f, 2.4f },
        { 3.1f, 3.2f, 3.3f, 3.4f },
        { 4.1f, 4.2f, 4.3f, 4.4f },
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

    CONST_OR_CONSTEXPR dmat4x2 dm422 = {
        { -1.1, 1.2 },
        { 22.1, -2.2 },
        { -3.1, 3.2 },
        { 24.1, -4.2 },
    };

    CONST_OR_CONSTEXPR dmat4x3 dm43 = {
        { 1.1, 1.2, 1.3 },
        { 2.1, 2.2, 2.3 },
        { 3.1, 3.2, 3.3 },
        { 4.1, 4.2, 4.3 },
    };

    CONST_OR_CONSTEXPR dmat4x4 dm44 = {
        { 1.1, 1.2, 1.3, 1.4 },
        { 2.1, 2.2, 2.3, 2.4 },
        { 3.1, 3.2, 3.3, 3.4 },
        { 4.1, 4.2, 4.3, 4.4 },
    };

    CONST_OR_CONSTEXPR mat4x2<short> sm42 = {
        { 1, 2 },
        { 3, 4 },
        { 5, 6 },
        { 7, 8 },
    };

    CONST_OR_CONSTEXPR mat4x2<int> im42 = {
        { 100, 101 },
        { 110, 111 },
        { 120, 121 },
        { 130, 131 },
    };

    CONST_OR_CONSTEXPR mat4x4<int> im44 = {
        { 100, 101, 102, 103 },
        { 110, 111, 112, 113 },
        { 120, 121, 122, 123 },
        { 130, 131, 132, 133 },
    };

    CONST_OR_CONSTEXPR mat4x2<bool64> bm42 = {
        { true64, false64 },
        { false64, true64 },
        { true64, false64 },
        { false64, true64 },
    };

    TEST_CASE(size)
    {
        test_assert(sizeof(mat<short, 4, 2>) == sizeof(vec2<short>[4]));
        test_assert(sizeof(mat<short, 4, 3>) == sizeof(vec3<short>[4]));
        test_assert(sizeof(mat<short, 4, 4>) == sizeof(vec4<short>[4]));
        test_assert(sizeof(mat4x2<short>) == sizeof(vec2<short>[4]));
        test_assert(sizeof(mat4x3<short>) == sizeof(vec3<short>[4]));
        test_assert(sizeof(mat4x4<short>) == sizeof(vec4<short>[4]));
        test_assert(sizeof(fmat4x2) == sizeof(fvec2[4]));
        test_assert(sizeof(fmat4x3) == sizeof(fvec3[4]));
        test_assert(sizeof(fmat4x4) == sizeof(fvec4[4]));
        test_assert(sizeof(dmat4x2) == sizeof(dvec2[4]));
        test_assert(sizeof(dmat4x3) == sizeof(dvec3[4]));
        test_assert(sizeof(dmat4x4) == sizeof(dvec4[4]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(mat<short, 4, 2>) == alignof(vec2<short>[4]));
        test_assert(alignof(mat<short, 4, 3>) == alignof(vec3<short>[4]));
        test_assert(alignof(mat<short, 4, 4>) == alignof(vec4<short>[4]));
        test_assert(alignof(mat4x2<short>) == alignof(vec2<short>[4]));
        test_assert(alignof(mat4x3<short>) == alignof(vec3<short>[4]));
        test_assert(alignof(mat4x4<short>) == alignof(vec4<short>[4]));
        test_assert(alignof(fmat4x2) == alignof(fvec2[4]));
        test_assert(alignof(fmat4x3) == alignof(fvec3[4]));
        test_assert(alignof(fmat4x4) == alignof(fvec4[4]));
        test_assert(alignof(dmat4x2) == alignof(dvec2[4]));
        test_assert(alignof(dmat4x3) == alignof(dvec3[4]));
        test_assert(alignof(dmat4x4) == alignof(dvec4[4]));
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
        constexpr auto ms42 = mat<short, 4, 2>::column_count;
        constexpr auto ms43 = mat<short, 4, 3>::column_count;
        constexpr auto ms44 = mat<short, 4, 4>::column_count;
        constexpr auto m42s = mat4x2<short>::column_count;
        constexpr auto m43s = mat4x3<short>::column_count;
        constexpr auto m44s = mat4x4<short>::column_count;
        constexpr auto fm42 = fmat4x2::column_count;
        constexpr auto fm43 = fmat4x3::column_count;
        constexpr auto fm44 = fmat4x4::column_count;
        constexpr auto dm42 = dmat4x2::column_count;
        constexpr auto dm43 = dmat4x3::column_count;
        constexpr auto dm44 = dmat4x4::column_count;

        test_assert(ms42 == 4);
        test_assert(ms43 == 4);
        test_assert(ms44 == 4);
        test_assert(m42s == 4);
        test_assert(m43s == 4);
        test_assert(m44s == 4);
        test_assert(fm42 == 4);
        test_assert(fm43 == 4);
        test_assert(fm44 == 4);
        test_assert(dm42 == 4);
        test_assert(dm43 == 4);
        test_assert(dm44 == 4);
    }

    TEST_CASE(row_count)
    {
        constexpr auto ms42 = mat<short, 4, 2>::row_count;
        constexpr auto ms43 = mat<short, 4, 3>::row_count;
        constexpr auto ms44 = mat<short, 4, 4>::row_count;
        constexpr auto m42s = mat4x2<short>::row_count;
        constexpr auto m43s = mat4x3<short>::row_count;
        constexpr auto m44s = mat4x4<short>::row_count;
        constexpr auto fm42 = fmat4x2::row_count;
        constexpr auto fm43 = fmat4x3::row_count;
        constexpr auto fm44 = fmat4x4::row_count;
        constexpr auto dm42 = dmat4x2::row_count;
        constexpr auto dm43 = dmat4x3::row_count;
        constexpr auto dm44 = dmat4x4::row_count;

        test_assert(ms42 == 2);
        test_assert(ms43 == 3);
        test_assert(ms44 == 4);
        test_assert(m42s == 2);
        test_assert(m43s == 3);
        test_assert(m44s == 4);
        test_assert(fm42 == 2);
        test_assert(fm43 == 3);
        test_assert(fm44 == 4);
        test_assert(dm42 == 2);
        test_assert(dm43 == 3);
        test_assert(dm44 == 4);
    }

    TEST_CASE(component_count)
    {
        constexpr auto ms42 = mat<short, 4, 2>::component_count;
        constexpr auto ms43 = mat<short, 4, 3>::component_count;
        constexpr auto ms44 = mat<short, 4, 4>::component_count;
        constexpr auto m42s = mat4x2<short>::component_count;
        constexpr auto m43s = mat4x3<short>::component_count;
        constexpr auto m44s = mat4x4<short>::component_count;
        constexpr auto fm42 = fmat4x2::component_count;
        constexpr auto fm43 = fmat4x3::component_count;
        constexpr auto fm44 = fmat4x4::component_count;
        constexpr auto dm42 = dmat4x2::component_count;
        constexpr auto dm43 = dmat4x3::component_count;
        constexpr auto dm44 = dmat4x4::component_count;

        test_assert(ms42 == 4 * 2);
        test_assert(ms43 == 4 * 3);
        test_assert(ms44 == 4 * 4);
        test_assert(m42s == 4 * 2);
        test_assert(m43s == 4 * 3);
        test_assert(m44s == 4 * 4);
        test_assert(fm42 == 4 * 2);
        test_assert(fm43 == 4 * 3);
        test_assert(fm44 == 4 * 4);
        test_assert(dm42 == 4 * 2);
        test_assert(dm43 == 4 * 3);
        test_assert(dm44 == 4 * 4);
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

    TEST_CASE(single_column_constructor)
    {
        CONST_OR_CONSTEXPR dmat4x2 m42(dvec2(1.2, 3.4));
        test_assert(m42[0] == dvec2(1.2, 3.4));
        test_assert(m42[1] == dvec2(1.2, 3.4));
        test_assert(m42[2] == dvec2(1.2, 3.4));
        test_assert(m42[3] == dvec2(1.2, 3.4));

        CONST_OR_CONSTEXPR dmat4x3 m43(dvec3(1.2, 3.4, 5.6));
        test_assert(m43[0] == dvec3(1.2, 3.4, 5.6));
        test_assert(m43[1] == dvec3(1.2, 3.4, 5.6));
        test_assert(m43[2] == dvec3(1.2, 3.4, 5.6));
        test_assert(m43[3] == dvec3(1.2, 3.4, 5.6));

        CONST_OR_CONSTEXPR dmat4x4 m44(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m44[0] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m44[1] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m44[2] == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(m44[3] == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(individual_column_constructor)
    {
        test_assert(dm42[0] == dvec2(1.1, 1.2));
        test_assert(dm42[1] == dvec2(2.1, 2.2));
        test_assert(dm42[2] == dvec2(3.1, 3.2));
        test_assert(dm42[3] == dvec2(4.1, 4.2));

        test_assert(dm43[0] == dvec3(1.1, 1.2, 1.3));
        test_assert(dm43[1] == dvec3(2.1, 2.2, 2.3));
        test_assert(dm43[2] == dvec3(3.1, 3.2, 3.3));
        test_assert(dm43[3] == dvec3(4.1, 4.2, 4.3));

        test_assert(dm44[0] == dvec4(1.1, 1.2, 1.3, 1.4));
        test_assert(dm44[1] == dvec4(2.1, 2.2, 2.3, 2.4));
        test_assert(dm44[2] == dvec4(3.1, 3.2, 3.3, 3.4));
        test_assert(dm44[3] == dvec4(4.1, 4.2, 4.3, 4.4));
    }

    TEST_CASE(extend_truncate_constructor)
    {
        CONST_OR_CONSTEXPR dmat4x2 m1(dm24);
        test_assert(m1[0] == dvec2(dm24[0]));
        test_assert(m1[1] == dvec2(dm24[1]));
        test_assert(m1[2] == dvec2(0.0, 0.0));
        test_assert(m1[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x4 m2(dm22);
        test_assert(m2[0] == dvec4(dm22[0], 0.0, 0.0));
        test_assert(m2[1] == dvec4(dm22[1], 0.0, 0.0));
        test_assert(m2[2] == dvec4(0.0, 0.0, 1.0, 0.0));
        test_assert(m2[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR dmat4x2 m3(dm34);
        test_assert(m3[0] == dvec2(dm34[0]));
        test_assert(m3[1] == dvec2(dm34[1]));
        test_assert(m3[2] == dvec2(dm34[2]));
        test_assert(m3[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x4 m4(dm32);
        test_assert(m4[0] == dvec4(dm32[0], 0.0, 0.0));
        test_assert(m4[1] == dvec4(dm32[1], 0.0, 0.0));
        test_assert(m4[2] == dvec4(dm32[2], 1.0, 0.0));
        test_assert(m4[3] == dvec4(0.0, 0.0, 0.0, 1.0));

        CONST_OR_CONSTEXPR dmat4x2 m5(dm44);
        test_assert(m5[0] == dvec2(dm44[0]));
        test_assert(m5[1] == dvec2(dm44[1]));
        test_assert(m5[2] == dvec2(dm44[2]));
        test_assert(m5[3] == dvec2(dm44[3]));

        CONST_OR_CONSTEXPR dmat4x4 m6(dm42);
        test_assert(m6[0] == dvec4(dm42[0], 0.0, 0.0));
        test_assert(m6[1] == dvec4(dm42[1], 0.0, 0.0));
        test_assert(m6[2] == dvec4(dm42[2], 1.0, 0.0));
        test_assert(m6[3] == dvec4(dm42[3], 0.0, 1.0));
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR fmat4x2 m(dm42);
        test_assert(m[0] == fvec2(dm42[0]));
        test_assert(m[1] == fvec2(dm42[1]));
        test_assert(m[2] == fvec2(dm42[2]));
        test_assert(m[3] == fvec2(dm42[3]));
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR dmat4x2 m42 = fm42;
        test_assert(m42[0] == fm42[0]);
        test_assert(m42[1] == fm42[1]);
        test_assert(m42[2] == fm42[2]);
        test_assert(m42[3] == fm42[3]);

        CONST_OR_CONSTEXPR dmat4x3 m43 = fm43;
        test_assert(m43[0] == fm43[0]);
        test_assert(m43[1] == fm43[1]);
        test_assert(m43[2] == fm43[2]);
        test_assert(m43[3] == fm43[3]);

        CONST_OR_CONSTEXPR dmat4x4 m44 = fm44;
        test_assert(m44[0] == fm44[0]);
        test_assert(m44[1] == fm44[1]);
        test_assert(m44[2] == fm44[2]);
        test_assert(m44[3] == fm44[3]);
    }

    TEST_CASE(fill)
    {
        CONST_OR_CONSTEXPR auto m42 = dmat4x2::fill(1.2);
        test_assert(m42[0] == dvec2(1.2));
        test_assert(m42[1] == dvec2(1.2));
        test_assert(m42[2] == dvec2(1.2));
        test_assert(m42[3] == dvec2(1.2));

        CONST_OR_CONSTEXPR auto m43 = dmat4x3::fill(1.2);
        test_assert(m43[0] == dvec3(1.2));
        test_assert(m43[1] == dvec3(1.2));
        test_assert(m43[2] == dvec3(1.2));
        test_assert(m43[3] == dvec3(1.2));

        CONST_OR_CONSTEXPR auto m44 = dmat4x4::fill(1.2);
        test_assert(m44[0] == dvec4(1.2));
        test_assert(m44[1] == dvec4(1.2));
        test_assert(m44[2] == dvec4(1.2));
        test_assert(m44[3] == dvec4(1.2));
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
        CONST_OR_CONSTEXPR dmat4x2 cem = dm42;
        CONST_OR_CONSTEXPR auto cem0 = cem[0];
        CONST_OR_CONSTEXPR auto cem1 = cem[1];
        CONST_OR_CONSTEXPR auto cem2 = cem[2];
        CONST_OR_CONSTEXPR auto cem3 = cem[3];
        test_assert(cem0 == dvec2(1.1, 1.2));
        test_assert(cem1 == dvec2(2.1, 2.2));
        test_assert(cem2 == dvec2(3.1, 3.2));
        test_assert(cem3 == dvec2(4.1, 4.2));

        const auto cm = dm42;
        const auto& cm0 = cm[0];
        const auto& cm1 = cm[1];
        const auto& cm2 = cm[2];
        const auto& cm3 = cm[3];
        test_assert(&cm0 == cm.columns() + 0);
        test_assert(&cm1 == cm.columns() + 1);
        test_assert(&cm2 == cm.columns() + 2);
        test_assert(&cm3 == cm.columns() + 3);

        auto m = dm42;
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

        dmat4x2 m;
        double* data = m.data();
        test_assert(data == static_cast<void*>(&m));
    }

    TEST_CASE(columns)
    {
        const dmat4x2 cm(1.2);
        const dvec2* ccolumns = cm.columns();
        test_assert(ccolumns == static_cast<const void*>(&cm));

        dmat4x2 m;
        dvec2* columns = m.columns();
        test_assert(columns == static_cast<void*>(&m));
    }

    TEST_CASE(column)
    {
        test_assert(dm42.column(0) == dm42[0]);
        test_assert(dm42.column(1) == dm42[1]);
        test_assert(dm42.column(2) == dm42[2]);
        test_assert(dm42.column(3) == dm42[3]);

        test_assert(dm43.column(0) == dm43[0]);
        test_assert(dm43.column(1) == dm43[1]);
        test_assert(dm43.column(2) == dm43[2]);
        test_assert(dm43.column(3) == dm43[3]);

        test_assert(dm44.column(0) == dm44[0]);
        test_assert(dm44.column(1) == dm44[1]);
        test_assert(dm44.column(2) == dm44[2]);
        test_assert(dm44.column(3) == dm44[3]);
    }

    TEST_CASE(set_column)
    {
        dmat4x2 m42;
        m42.set_column(0, dvec2(0.0, 0.1));
        m42.set_column(1, dvec2(1.0, 1.1));
        m42.set_column(2, dvec2(2.0, 2.1));
        m42.set_column(3, dvec2(3.0, 3.1));
        test_assert(m42.column(0) == dvec2(0.0, 0.1));
        test_assert(m42.column(1) == dvec2(1.0, 1.1));
        test_assert(m42.column(2) == dvec2(2.0, 2.1));
        test_assert(m42.column(3) == dvec2(3.0, 3.1));

        dmat4x3 m43;
        m43.set_column(0, dvec3(0.0, 0.1, 0.2));
        m43.set_column(1, dvec3(1.0, 1.1, 1.2));
        m43.set_column(2, dvec3(2.0, 2.1, 2.2));
        m43.set_column(3, dvec3(3.0, 3.1, 3.2));
        test_assert(m43.column(0) == dvec3(0.0, 0.1, 0.2));
        test_assert(m43.column(1) == dvec3(1.0, 1.1, 1.2));
        test_assert(m43.column(2) == dvec3(2.0, 2.1, 2.2));
        test_assert(m43.column(3) == dvec3(3.0, 3.1, 3.2));

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

    TEST_CASE(row)
    {
        test_assert(dm42.row(0) ==
            dvec4(dm42[0][0], dm42[1][0], dm42[2][0], dm42[3][0]));
        test_assert(dm42.row(1) ==
            dvec4(dm42[0][1], dm42[1][1], dm42[2][1], dm42[3][1]));

        test_assert(dm43.row(0) ==
            dvec4(dm43[0][0], dm43[1][0], dm43[2][0], dm43[3][0]));
        test_assert(dm43.row(1) ==
            dvec4(dm43[0][1], dm43[1][1], dm43[2][1], dm43[3][1]));
        test_assert(dm43.row(2) ==
            dvec4(dm43[0][2], dm43[1][2], dm43[2][2], dm43[3][2]));

        test_assert(dm44.row(0) ==
            dvec4(dm44[0][0], dm44[1][0], dm44[2][0], dm44[3][0]));
        test_assert(dm44.row(1) ==
            dvec4(dm44[0][1], dm44[1][1], dm44[2][1], dm44[3][1]));
        test_assert(dm44.row(2) ==
            dvec4(dm44[0][2], dm44[1][2], dm44[2][2], dm44[3][2]));
        test_assert(dm44.row(3) ==
            dvec4(dm44[0][3], dm44[1][3], dm44[2][3], dm44[3][3]));
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
        auto m = im42;
        test_assert(&(++m) == &m);
        test_assert(m[0] == im42[0] + 1);
        test_assert(m[1] == im42[1] + 1);
        test_assert(m[2] == im42[2] + 1);
        test_assert(m[3] == im42[3] + 1);
    }

    TEST_CASE(post_increment_operator)
    {
        auto m1 = im42;
        const auto m2 = m1++;
        test_assert(m1[0] == im42[0] + 1);
        test_assert(m1[1] == im42[1] + 1);
        test_assert(m1[2] == im42[2] + 1);
        test_assert(m1[3] == im42[3] + 1);
        test_assert(m2 == im42);
    }

    TEST_CASE(pre_decrement_operator)
    {
        auto m = im42;
        test_assert(&(--m) == &m);
        test_assert(m[0] == im42[0] - 1);
        test_assert(m[1] == im42[1] - 1);
        test_assert(m[2] == im42[2] - 1);
        test_assert(m[3] == im42[3] - 1);
    }

    TEST_CASE(post_decrement_operator)
    {
        auto m1 = im42;
        const auto m2 = m1--;
        test_assert(m1[0] == im42[0] - 1);
        test_assert(m1[1] == im42[1] - 1);
        test_assert(m1[2] == im42[2] - 1);
        test_assert(m1[3] == im42[3] - 1);
        test_assert(m2 == im42);
    }

    TEST_CASE(addition_assignment_operator)
    {
        auto m1 = dm42;
        test_assert(&(m1 += 12) == &m1);
        test_assert(m1[0] == dm42[0] + 12);
        test_assert(m1[1] == dm42[1] + 12);
        test_assert(m1[2] == dm42[2] + 12);
        test_assert(m1[3] == dm42[3] + 12);

        auto m2 = dm42;
        test_assert(&(m2 += im42) == &m2);
        test_assert(m2[0] == dm42[0] + im42[0]);
        test_assert(m2[1] == dm42[1] + im42[1]);
        test_assert(m2[2] == dm42[2] + im42[2]);
        test_assert(m2[3] == dm42[3] + im42[3]);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        auto m1 = dm42;
        test_assert(&(m1 -= 12) == &m1);
        test_assert(m1[0] == dm42[0] - 12);
        test_assert(m1[1] == dm42[1] - 12);
        test_assert(m1[2] == dm42[2] - 12);
        test_assert(m1[3] == dm42[3] - 12);

        auto m2 = dm42;
        test_assert(&(m2 -= im42) == &m2);
        test_assert(m2[0] == dm42[0] - im42[0]);
        test_assert(m2[1] == dm42[1] - im42[1]);
        test_assert(m2[2] == dm42[2] - im42[2]);
        test_assert(m2[3] == dm42[3] - im42[3]);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        auto m1 = dm42;
        test_assert(&(m1 *= 12) == &m1);
        test_assert(m1[0] == dm42[0] * 12);
        test_assert(m1[1] == dm42[1] * 12);
        test_assert(m1[2] == dm42[2] * 12);
        test_assert(m1[3] == dm42[3] * 12);

        auto m2 = dm42;
        test_assert(&(m2 *= im44) == &m2);
        test_assert(m2 == dm42 * im44);
    }

    TEST_CASE(division_assignment_operator)
    {
        auto m1 = dm42;
        test_assert(&(m1 /= 12) == &m1);
        test_assert(m1[0] == dm42[0] / 12);
        test_assert(m1[1] == dm42[1] / 12);
        test_assert(m1[2] == dm42[2] / 12);
        test_assert(m1[3] == dm42[3] / 12);

        auto m2 = dm42;
        test_assert(&(m2 /= im42) == &m2);
        test_assert(m2[0] == dm42[0] / im42[0]);
        test_assert(m2[1] == dm42[1] / im42[1]);
        test_assert(m2[2] == dm42[2] / im42[2]);
        test_assert(m2[3] == dm42[3] / im42[3]);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 %= 12) == &m1);
        test_assert(m1[0] == im42[0] % 12);
        test_assert(m1[1] == im42[1] % 12);
        test_assert(m1[2] == im42[2] % 12);
        test_assert(m1[3] == im42[3] % 12);

        auto m2 = im42;
        test_assert(&(m2 %= sm42) == &m2);
        test_assert(m2[0] == im42[0] % sm42[0]);
        test_assert(m2[1] == im42[1] % sm42[1]);
        test_assert(m2[2] == im42[2] % sm42[2]);
        test_assert(m2[3] == im42[3] % sm42[3]);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 &= 12) == &m1);
        test_assert(m1[0] == (im42[0] & 12));
        test_assert(m1[1] == (im42[1] & 12));
        test_assert(m1[2] == (im42[2] & 12));
        test_assert(m1[3] == (im42[3] & 12));

        auto m2 = im42;
        test_assert(&(m2 &= sm42) == &m2);
        test_assert(m2[0] == (im42[0] & sm42[0]));
        test_assert(m2[1] == (im42[1] & sm42[1]));
        test_assert(m2[2] == (im42[2] & sm42[2]));
        test_assert(m2[3] == (im42[3] & sm42[3]));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 |= 12) == &m1);
        test_assert(m1[0] == (im42[0] | 12));
        test_assert(m1[1] == (im42[1] | 12));
        test_assert(m1[2] == (im42[2] | 12));
        test_assert(m1[3] == (im42[3] | 12));

        auto m2 = im42;
        test_assert(&(m2 |= sm42) == &m2);
        test_assert(m2[0] == (im42[0] | sm42[0]));
        test_assert(m2[1] == (im42[1] | sm42[1]));
        test_assert(m2[2] == (im42[2] | sm42[2]));
        test_assert(m2[3] == (im42[3] | sm42[3]));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 ^= 12) == &m1);
        test_assert(m1[0] == (im42[0] ^ 12));
        test_assert(m1[1] == (im42[1] ^ 12));
        test_assert(m1[2] == (im42[2] ^ 12));
        test_assert(m1[3] == (im42[3] ^ 12));

        auto m2 = im42;
        test_assert(&(m2 ^= sm42) == &m2);
        test_assert(m2[0] == (im42[0] ^ sm42[0]));
        test_assert(m2[1] == (im42[1] ^ sm42[1]));
        test_assert(m2[2] == (im42[2] ^ sm42[2]));
        test_assert(m2[3] == (im42[3] ^ sm42[3]));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 <<= 12) == &m1);
        test_assert(m1[0] == (im42[0] << 12));
        test_assert(m1[1] == (im42[1] << 12));
        test_assert(m1[2] == (im42[2] << 12));
        test_assert(m1[3] == (im42[3] << 12));

        auto m2 = im42;
        test_assert(&(m2 <<= sm42) == &m2);
        test_assert(m2[0] == (im42[0] << sm42[0]));
        test_assert(m2[1] == (im42[1] << sm42[1]));
        test_assert(m2[2] == (im42[2] << sm42[2]));
        test_assert(m2[3] == (im42[3] << sm42[3]));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        auto m1 = im42;
        test_assert(&(m1 >>= 12) == &m1);
        test_assert(m1[0] == (im42[0] >> 12));
        test_assert(m1[1] == (im42[1] >> 12));
        test_assert(m1[2] == (im42[2] >> 12));
        test_assert(m1[3] == (im42[3] >> 12));

        auto m2 = im42;
        test_assert(&(m2 >>= sm42) == &m2);
        test_assert(m2[0] == (im42[0] >> sm42[0]));
        test_assert(m2[1] == (im42[1] >> sm42[1]));
        test_assert(m2[2] == (im42[2] >> sm42[2]));
        test_assert(m2[3] == (im42[3] >> sm42[3]));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto m = +dm42;
        test_assert(m == dmat4x2(+dm42[0], +dm42[1], +dm42[2], +dm42[3]));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto m = -dm42;
        test_assert(m == dmat4x2(-dm42[0], -dm42[1], -dm42[2], -dm42[3]));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto m = ~im42;
        test_assert(m == mat4x2<int>(~im42[0], ~im42[1], ~im42[2], ~im42[3]));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 + dm42;
        test_assert(m1[0] == 12 + dm42[0]);
        test_assert(m1[1] == 12 + dm42[1]);
        test_assert(m1[2] == 12 + dm42[2]);
        test_assert(m1[3] == 12 + dm42[3]);

        CONST_OR_CONSTEXPR auto m2 = dm42 + 12;
        test_assert(m2[0] == dm42[0] + 12);
        test_assert(m2[1] == dm42[1] + 12);
        test_assert(m2[2] == dm42[2] + 12);
        test_assert(m2[3] == dm42[3] + 12);

        CONST_OR_CONSTEXPR auto m3 = dm42 + im42;
        test_assert(m3[0] == dm42[0] + im42[0]);
        test_assert(m3[1] == dm42[1] + im42[1]);
        test_assert(m3[2] == dm42[2] + im42[2]);
        test_assert(m3[3] == dm42[3] + im42[3]);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 - dm42;
        test_assert(m1[0] == 12 - dm42[0]);
        test_assert(m1[1] == 12 - dm42[1]);
        test_assert(m1[2] == 12 - dm42[2]);
        test_assert(m1[3] == 12 - dm42[3]);

        CONST_OR_CONSTEXPR auto m2 = dm42 - 12;
        test_assert(m2[0] == dm42[0] - 12);
        test_assert(m2[1] == dm42[1] - 12);
        test_assert(m2[2] == dm42[2] - 12);
        test_assert(m2[3] == dm42[3] - 12);

        CONST_OR_CONSTEXPR auto m3 = dm42 - im42;
        test_assert(m3[0] == dm42[0] - im42[0]);
        test_assert(m3[1] == dm42[1] - im42[1]);
        test_assert(m3[2] == dm42[2] - im42[2]);
        test_assert(m3[3] == dm42[3] - im42[3]);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 * dm42;
        test_assert(m1[0] == 12 * dm42[0]);
        test_assert(m1[1] == 12 * dm42[1]);
        test_assert(m1[2] == 12 * dm42[2]);
        test_assert(m1[3] == 12 * dm42[3]);

        CONST_OR_CONSTEXPR auto m2 = dm42 * 12;
        test_assert(m2[0] == dm42[0] * 12);
        test_assert(m2[1] == dm42[1] * 12);
        test_assert(m2[2] == dm42[2] * 12);
        test_assert(m2[3] == dm42[3] * 12);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 12 / dm42;
        test_assert(m1[0] == 12 / dm42[0]);
        test_assert(m1[1] == 12 / dm42[1]);
        test_assert(m1[2] == 12 / dm42[2]);
        test_assert(m1[3] == 12 / dm42[3]);

        CONST_OR_CONSTEXPR auto m2 = dm42 / 12;
        test_assert(m2[0] == dm42[0] / 12);
        test_assert(m2[1] == dm42[1] / 12);
        test_assert(m2[2] == dm42[2] / 12);
        test_assert(m2[3] == dm42[3] / 12);

        CONST_OR_CONSTEXPR auto m3 = dm42 / im42;
        test_assert(m3[0] == dm42[0] / im42[0]);
        test_assert(m3[1] == dm42[1] / im42[1]);
        test_assert(m3[2] == dm42[2] / im42[2]);
        test_assert(m3[3] == dm42[3] / im42[3]);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 % sm42;
        test_assert(m1[0] == 123 % sm42[0]);
        test_assert(m1[1] == 123 % sm42[1]);
        test_assert(m1[2] == 123 % sm42[2]);
        test_assert(m1[3] == 123 % sm42[3]);

        CONST_OR_CONSTEXPR auto m2 = im42 % 12;
        test_assert(m2[0] == im42[0] % 12);
        test_assert(m2[1] == im42[1] % 12);
        test_assert(m2[2] == im42[2] % 12);
        test_assert(m2[3] == im42[3] % 12);

        CONST_OR_CONSTEXPR auto m3 = im42 % sm42;
        test_assert(m3[0] == im42[0] % sm42[0]);
        test_assert(m3[1] == im42[1] % sm42[1]);
        test_assert(m3[2] == im42[2] % sm42[2]);
        test_assert(m3[3] == im42[3] % sm42[3]);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 & sm42;
        test_assert(m1[0] == (123 & sm42[0]));
        test_assert(m1[1] == (123 & sm42[1]));
        test_assert(m1[2] == (123 & sm42[2]));
        test_assert(m1[3] == (123 & sm42[3]));

        CONST_OR_CONSTEXPR auto m2 = im42 & 12;
        test_assert(m2[0] == (im42[0] & 12));
        test_assert(m2[1] == (im42[1] & 12));
        test_assert(m2[2] == (im42[2] & 12));
        test_assert(m2[3] == (im42[3] & 12));

        CONST_OR_CONSTEXPR auto m3 = im42 & sm42;
        test_assert(m3[0] == (im42[0] & sm42[0]));
        test_assert(m3[1] == (im42[1] & sm42[1]));
        test_assert(m3[2] == (im42[2] & sm42[2]));
        test_assert(m3[3] == (im42[3] & sm42[3]));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 | sm42;
        test_assert(m1[0] == (123 | sm42[0]));
        test_assert(m1[1] == (123 | sm42[1]));
        test_assert(m1[2] == (123 | sm42[2]));
        test_assert(m1[3] == (123 | sm42[3]));

        CONST_OR_CONSTEXPR auto m2 = im42 | 12;
        test_assert(m2[0] == (im42[0] | 12));
        test_assert(m2[1] == (im42[1] | 12));
        test_assert(m2[2] == (im42[2] | 12));
        test_assert(m2[3] == (im42[3] | 12));

        CONST_OR_CONSTEXPR auto m3 = im42 | sm42;
        test_assert(m3[0] == (im42[0] | sm42[0]));
        test_assert(m3[1] == (im42[1] | sm42[1]));
        test_assert(m3[2] == (im42[2] | sm42[2]));
        test_assert(m3[3] == (im42[3] | sm42[3]));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 ^ sm42;
        test_assert(m1[0] == (123 ^ sm42[0]));
        test_assert(m1[1] == (123 ^ sm42[1]));
        test_assert(m1[2] == (123 ^ sm42[2]));
        test_assert(m1[3] == (123 ^ sm42[3]));

        CONST_OR_CONSTEXPR auto m2 = im42 ^ 12;
        test_assert(m2[0] == (im42[0] ^ 12));
        test_assert(m2[1] == (im42[1] ^ 12));
        test_assert(m2[2] == (im42[2] ^ 12));
        test_assert(m2[3] == (im42[3] ^ 12));

        CONST_OR_CONSTEXPR auto m3 = im42 ^ sm42;
        test_assert(m3[0] == (im42[0] ^ sm42[0]));
        test_assert(m3[1] == (im42[1] ^ sm42[1]));
        test_assert(m3[2] == (im42[2] ^ sm42[2]));
        test_assert(m3[3] == (im42[3] ^ sm42[3]));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 << sm42;
        test_assert(m1[0] == (123 << sm42[0]));
        test_assert(m1[1] == (123 << sm42[1]));
        test_assert(m1[2] == (123 << sm42[2]));
        test_assert(m1[3] == (123 << sm42[3]));

        CONST_OR_CONSTEXPR auto m2 = im42 << 1;
        test_assert(m2[0] == (im42[0] << 1));
        test_assert(m2[1] == (im42[1] << 1));
        test_assert(m2[2] == (im42[2] << 1));
        test_assert(m2[3] == (im42[3] << 1));

        CONST_OR_CONSTEXPR auto m3 = im42 << sm42;
        test_assert(m3[0] == (im42[0] << sm42[0]));
        test_assert(m3[1] == (im42[1] << sm42[1]));
        test_assert(m3[2] == (im42[2] << sm42[2]));
        test_assert(m3[3] == (im42[3] << sm42[3]));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto m1 = 123 >> sm42;
        test_assert(m1[0] == (123 >> sm42[0]));
        test_assert(m1[1] == (123 >> sm42[1]));
        test_assert(m1[2] == (123 >> sm42[2]));
        test_assert(m1[3] == (123 >> sm42[3]));

        CONST_OR_CONSTEXPR auto m2 = im42 >> 1;
        test_assert(m2[0] == (im42[0] >> 1));
        test_assert(m2[1] == (im42[1] >> 1));
        test_assert(m2[2] == (im42[2] >> 1));
        test_assert(m2[3] == (im42[3] >> 1));

        CONST_OR_CONSTEXPR auto m3 = im42 >> sm42;
        test_assert(m3[0] == (im42[0] >> sm42[0]));
        test_assert(m3[1] == (im42[1] >> sm42[1]));
        test_assert(m3[2] == (im42[2] >> sm42[2]));
        test_assert(m3[3] == (im42[3] >> sm42[3]));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fmat4x2 m1(
            fvec2(1.2f), fvec2(3.4f), fvec2(5.6f), fvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m2(
            dvec2(1.2f), dvec2(3.4f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m3(
            dvec2(1.2f), dvec2(3.4f), dvec2(5.6f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat4x2 m4(
            dvec2(1.2f), dvec2(3.4f), dvec2(0.0f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m5(
            dvec2(1.2f), dvec2(0.0f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m6(
            dvec2(0.0f), dvec2(3.4f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR auto result1 = (m1 == m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 == m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 == m4);
        CONST_OR_CONSTEXPR auto result4 = (m1 == m5);
        CONST_OR_CONSTEXPR auto result5 = (m1 == m6);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
        test_assert(result5 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fmat4x2 m1(
            fvec2(1.2f), fvec2(3.4f), fvec2(5.6f), fvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m2(
            dvec2(1.2f), dvec2(3.4f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m3(
            dvec2(1.2f), dvec2(3.4f), dvec2(5.6f), dvec2(0.0f));
        CONST_OR_CONSTEXPR dmat4x2 m4(
            dvec2(1.2f), dvec2(3.4f), dvec2(0.0f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m5(
            dvec2(1.2f), dvec2(0.0f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR dmat4x2 m6(
            dvec2(0.0f), dvec2(3.4f), dvec2(5.6f), dvec2(7.8f));
        CONST_OR_CONSTEXPR auto result1 = (m1 != m2);
        CONST_OR_CONSTEXPR auto result2 = (m1 != m3);
        CONST_OR_CONSTEXPR auto result3 = (m1 != m4);
        CONST_OR_CONSTEXPR auto result4 = (m1 != m5);
        CONST_OR_CONSTEXPR auto result5 = (m1 != m6);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
        test_assert(result5 == true);
    }

    TEST_CASE(sin)
    {
        const auto m = math::sin(dm42);
        test_assert(m[0] == math::sin(dm42[0]));
        test_assert(m[1] == math::sin(dm42[1]));
        test_assert(m[2] == math::sin(dm42[2]));
        test_assert(m[3] == math::sin(dm42[3]));
    }

    TEST_CASE(cos)
    {
        const auto m = math::cos(dm42);
        test_assert(m[0] == math::cos(dm42[0]));
        test_assert(m[1] == math::cos(dm42[1]));
        test_assert(m[2] == math::cos(dm42[2]));
        test_assert(m[3] == math::cos(dm42[3]));
    }

    TEST_CASE(sincos)
    {
        dmat4x2 s, c;
        math::sincos(dm42, s, c);

        test_assert(s[0] == math::sin(dm42[0]));
        test_assert(s[1] == math::sin(dm42[1]));
        test_assert(s[2] == math::sin(dm42[2]));
        test_assert(s[3] == math::sin(dm42[3]));

        test_assert(c[0] == math::cos(dm42[0]));
        test_assert(c[1] == math::cos(dm42[1]));
        test_assert(c[2] == math::cos(dm42[2]));
        test_assert(c[3] == math::cos(dm42[3]));
    }

    TEST_CASE(exp)
    {
        const auto m = math::exp(dm42);
        test_assert(m[0] == math::exp(dm42[0]));
        test_assert(m[1] == math::exp(dm42[1]));
        test_assert(m[2] == math::exp(dm42[2]));
        test_assert(m[3] == math::exp(dm42[3]));
    }

    TEST_CASE(log)
    {
        const auto m = math::log(dm42);
        test_assert(m[0] == math::log(dm42[0]));
        test_assert(m[1] == math::log(dm42[1]));
        test_assert(m[2] == math::log(dm42[2]));
        test_assert(m[3] == math::log(dm42[3]));
    }

    TEST_CASE(abs)
    {
        const auto m = math::abs(dm422);
        test_assert(m[0] == math::abs(dm422[0]));
        test_assert(m[1] == math::abs(dm422[1]));
        test_assert(m[2] == math::abs(dm422[2]));
        test_assert(m[3] == math::abs(dm422[3]));
    }

    TEST_CASE(pow)
    {
        const auto m = math::pow(dm42, dm422);
        test_assert(m[0] == math::pow(dm42[0], dm422[0]));
        test_assert(m[1] == math::pow(dm42[1], dm422[1]));
        test_assert(m[2] == math::pow(dm42[2], dm422[2]));
        test_assert(m[3] == math::pow(dm42[3], dm422[3]));
    }

    TEST_CASE(recip)
    {
        const auto m = math::recip(dm42);
        test_assert(m[0] == math::recip(dm42[0]));
        test_assert(m[1] == math::recip(dm42[1]));
        test_assert(m[2] == math::recip(dm42[2]));
        test_assert(m[3] == math::recip(dm42[3]));
    }

    TEST_CASE(sqrt)
    {
        const auto m = math::sqrt(dm42);
        test_assert(m[0] == math::sqrt(dm42[0]));
        test_assert(m[1] == math::sqrt(dm42[1]));
        test_assert(m[2] == math::sqrt(dm42[2]));
        test_assert(m[3] == math::sqrt(dm42[3]));
    }

    TEST_CASE(rsqrt)
    {
        const auto m = math::rsqrt(dm42);
        test_assert(m[0] == math::rsqrt(dm42[0]));
        test_assert(m[1] == math::rsqrt(dm42[1]));
        test_assert(m[2] == math::rsqrt(dm42[2]));
        test_assert(m[3] == math::rsqrt(dm42[3]));
    }

    TEST_CASE(min)
    {
        const auto m = math::min(dm42, dm422);
        test_assert(m[0] == math::min(dm42[0], dm422[0]));
        test_assert(m[1] == math::min(dm42[1], dm422[1]));
        test_assert(m[2] == math::min(dm42[2], dm422[2]));
        test_assert(m[3] == math::min(dm42[3], dm422[3]));
    }

    TEST_CASE(max)
    {
        const auto m = math::max(dm42, dm422);
        test_assert(m[0] == math::max(dm42[0], dm422[0]));
        test_assert(m[1] == math::max(dm42[1], dm422[1]));
        test_assert(m[2] == math::max(dm42[2], dm422[2]));
        test_assert(m[3] == math::max(dm42[3], dm422[3]));
    }

    TEST_CASE(mask)
    {
        const auto m = math::mask(bm42, dm42);
        test_assert(m[0] == math::mask(bm42[0], dm42[0]));
        test_assert(m[1] == math::mask(bm42[1], dm42[1]));
        test_assert(m[2] == math::mask(bm42[2], dm42[2]));
        test_assert(m[3] == math::mask(bm42[3], dm42[3]));
    }

    TEST_CASE(select)
    {
        const auto m = math::select(bm42, dm42, dm422);
        test_assert(m[0] == math::select(bm42[0], dm42[0], dm422[0]));
        test_assert(m[1] == math::select(bm42[1], dm42[1], dm422[1]));
        test_assert(m[2] == math::select(bm42[2], dm42[2], dm422[2]));
        test_assert(m[3] == math::select(bm42[3], dm42[3], dm422[3]));
    }

    TEST_CASE(less)
    {
        const auto m = math::less(dm42, dm422);
        test_assert(m[0] == math::less(dm42[0], dm422[0]));
        test_assert(m[1] == math::less(dm42[1], dm422[1]));
        test_assert(m[2] == math::less(dm42[2], dm422[2]));
        test_assert(m[3] == math::less(dm42[3], dm422[3]));
    }

    TEST_CASE(less_equal)
    {
        const auto m = math::less_equal(dm42, dm422);
        test_assert(m[0] == math::less_equal(dm42[0], dm422[0]));
        test_assert(m[1] == math::less_equal(dm42[1], dm422[1]));
        test_assert(m[2] == math::less_equal(dm42[2], dm422[2]));
        test_assert(m[3] == math::less_equal(dm42[3], dm422[3]));
    }

    TEST_CASE(greater)
    {
        const auto m = math::greater(dm42, dm422);
        test_assert(m[0] == math::greater(dm42[0], dm422[0]));
        test_assert(m[1] == math::greater(dm42[1], dm422[1]));
        test_assert(m[2] == math::greater(dm42[2], dm422[2]));
        test_assert(m[3] == math::greater(dm42[3], dm422[3]));
    }

    TEST_CASE(greater_equal)
    {
        const auto m = math::greater_equal(dm42, dm422);
        test_assert(m[0] == math::greater_equal(dm42[0], dm422[0]));
        test_assert(m[1] == math::greater_equal(dm42[1], dm422[1]));
        test_assert(m[2] == math::greater_equal(dm42[2], dm422[2]));
        test_assert(m[3] == math::greater_equal(dm42[3], dm422[3]));
    }

    TEST_CASE(equal)
    {
        const auto m = math::equal(dm42, dm422);
        test_assert(m[0] == math::equal(dm42[0], dm422[0]));
        test_assert(m[1] == math::equal(dm42[1], dm422[1]));
        test_assert(m[2] == math::equal(dm42[2], dm422[2]));
        test_assert(m[3] == math::equal(dm42[3], dm422[3]));
    }

    TEST_CASE(not_equal)
    {
        const auto m = math::not_equal(dm42, dm422);
        test_assert(m[0] == math::not_equal(dm42[0], dm422[0]));
        test_assert(m[1] == math::not_equal(dm42[1], dm422[1]));
        test_assert(m[2] == math::not_equal(dm42[2], dm422[2]));
        test_assert(m[3] == math::not_equal(dm42[3], dm422[3]));
    }

    TEST_CASE(comp_mult)
    {
        CONST_OR_CONSTEXPR auto m = math::comp_mult(dm42, im42);
        test_assert(m[0] == dm42[0] * im42[0]);
        test_assert(m[1] == dm42[1] * im42[1]);
        test_assert(m[2] == dm42[2] * im42[2]);
        test_assert(m[3] == dm42[3] * im42[3]);
    }

    TEST_CASE(transpose)
    {
        CONST_OR_CONSTEXPR auto m1 = math::transpose(dm42);
        test_assert(m1[0] == dm42.row(0));
        test_assert(m1[1] == dm42.row(1));

        CONST_OR_CONSTEXPR auto m2 = math::transpose(dm43);
        test_assert(m2[0] == dm43.row(0));
        test_assert(m2[1] == dm43.row(1));
        test_assert(m2[2] == dm43.row(2));

        CONST_OR_CONSTEXPR auto m3 = math::transpose(dm44);
        test_assert(m3[0] == dm44.row(0));
        test_assert(m3[1] == dm44.row(1));
        test_assert(m3[2] == dm44.row(2));
        test_assert(m3[3] == dm44.row(3));
    }
}
