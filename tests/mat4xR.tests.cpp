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
        CONST_OR_CONSTEXPR dmat4x2 m1(1.2);
        test_assert(m1[0] == dvec2(1.2, 0.0));
        test_assert(m1[1] == dvec2(0.0, 1.2));
        test_assert(m1[2] == dvec2(0.0, 0.0));
        test_assert(m1[3] == dvec2(0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x3 m2(1.2);
        test_assert(m2[0] == dvec3(1.2, 0.0, 0.0));
        test_assert(m2[1] == dvec3(0.0, 1.2, 0.0));
        test_assert(m2[2] == dvec3(0.0, 0.0, 1.2));
        test_assert(m2[3] == dvec3(0.0, 0.0, 0.0));

        CONST_OR_CONSTEXPR dmat4x4 m3(1.2);
        test_assert(m3[0] == dvec4(1.2, 0.0, 0.0, 0.0));
        test_assert(m3[1] == dvec4(0.0, 1.2, 0.0, 0.0));
        test_assert(m3[2] == dvec4(0.0, 0.0, 1.2, 0.0));
        test_assert(m3[3] == dvec4(0.0, 0.0, 0.0, 1.2));
    }
}
