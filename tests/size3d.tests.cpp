//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/size3d.hpp>
#include "tue.tests.hpp"

#include <type_traits>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(size3d<short>) == sizeof(short[3]));
        test_assert(sizeof(fsize3d) == sizeof(float[3]));
        test_assert(sizeof(dsize3d) == sizeof(double[3]));
        test_assert(sizeof(isize3d) == sizeof(int[3]));
        test_assert(sizeof(usize3d) == sizeof(unsigned int[3]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(size3d<short>) == alignof(short[3]));
        test_assert(alignof(fsize3d) == alignof(float[3]));
        test_assert(alignof(dsize3d) <= alignof(double[3]));
        test_assert(alignof(isize3d) == alignof(int[3]));
        test_assert(alignof(usize3d) == alignof(unsigned int[3]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename size3d<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename fsize3d::component_type, float>::value));
        test_assert((std::is_same<
            typename dsize3d::component_type, double>::value));
        test_assert((std::is_same<
            typename isize3d::component_type, int>::value));
        test_assert((std::is_same<
            typename usize3d::component_type, unsigned int>::value));
    }

    TEST_CASE(component_count)
    {
        constexpr auto v3s = size3d<short>::component_count;
        constexpr auto fv3 = fsize3d::component_count;
        constexpr auto dv3 = dsize3d::component_count;
        constexpr auto iv3 = isize3d::component_count;
        constexpr auto uv3 = usize3d::component_count;
        test_assert(v3s == 3);
        test_assert(fv3 == 3);
        test_assert(dv3 == 3);
        test_assert(iv3 == 3);
        test_assert(uv3 == 3);
    }

    TEST_CASE(default_constructor)
    {
        dsize3d size;
        unused(size);
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2);
        test_assert(size[0] == 1.2);
        test_assert(size[1] == 1.2);
        test_assert(size[2] == 1.2);
    }

    TEST_CASE(individual_component_constructor)
    {
        CONST_OR_CONSTEXPR dsize3d size = { 1.2, 3.4, 5.6 };
        test_assert(size[0] == 1.2);
        test_assert(size[1] == 3.4);
        test_assert(size[2] == 5.6);
    }

    /*TEST_CASE(extend_size2d_constructor)
    {
        CONST_OR_CONSTEXPR dsize3d size = { { 1.2, 3.4 }, 5.6 };
        test_assert(size[0] == 1.2);
        test_assert(size[1] == 3.4);
        test_assert(size[2] == 5.6);
    }*/

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dsize3d dsize(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR fsize3d fsize(dsize);
        test_assert(fsize[0] == 1.2f);
        test_assert(fsize[1] == 3.4f);
        test_assert(fsize[2] == 5.6f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fsize3d fsize(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d dsize = fsize;
        test_assert(dsize[0] == 1.2f);
        test_assert(dsize[1] == 3.4f);
        test_assert(dsize[2] == 5.6f);
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto size = dsize3d::zero();
        test_assert(size == dsize3d(0.0, 0.0, 0.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dsize3d cesize(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto cesize0 = cesize[0];
        CONST_OR_CONSTEXPR auto cesize1 = cesize[1];
        CONST_OR_CONSTEXPR auto cesize2 = cesize[2];
        test_assert(cesize0 == 1.2);
        test_assert(cesize1 == 3.4);
        test_assert(cesize2 == 5.6);

        const auto csize = cesize;
        const auto& csize0 = csize[0];
        const auto& csize1 = csize[1];
        const auto& csize2 = csize[2];
        test_assert(&csize0 == csize.data() + 0);
        test_assert(&csize1 == csize.data() + 1);
        test_assert(&csize2 == csize.data() + 2);

        auto size = cesize;
        auto& size0 = size[0];
        auto& size1 = size[1];
        auto& size2 = size[2];
        test_assert(&size0 == size.data() + 0);
        test_assert(&size1 == size.data() + 1);
        test_assert(&size2 == size.data() + 2);
    }

    TEST_CASE(data)
    {
        const dsize3d csize(1.2);
        const double* cdata = csize.data();
        test_assert(cdata == static_cast<const void*>(&csize));

        dsize3d size;
        double* data = size.data();
        test_assert(data == static_cast<void*>(&size));
    }

    TEST_CASE(width_height_depth_getters)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto width = size.width();
        CONST_OR_CONSTEXPR auto height = size.height();
        CONST_OR_CONSTEXPR auto depth = size.depth();
        test_assert(width == 1.2);
        test_assert(height == 3.4);
        test_assert(depth == 5.6);
    }

    /*TEST_CASE(width_height)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto width_height = size.width_height();
        test_assert(xy == dsize2d(1.2, 3.4));
    }*/

    TEST_CASE(width_height_depth)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto width_height_depth = size.width_height_depth();
        test_assert(width_height_depth == dsize3d(1.2, 3.4, 5.6));
    }

    TEST_CASE(width_height_depth_setters)
    {
        dsize3d size(1.2, 3.4, 5.6);
        size.set_width(7.8);
        size.set_height(9.10);
        size.set_depth(11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);
    }

    TEST_CASE(set_width_height)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_width_height(7.8, 9.10);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 5.6);

        /*size.set_width_height(dsize2d(11.12, 13.14));
        test_assert(size[0] == 11.12);
        test_assert(size[1] == 13.14);
        test_assert(size[2] == 5.6);*/
    }

    TEST_CASE(set_width_height_depth)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_width_height_depth(7.8, 9.10, 11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);

        /*size.set_width_height_depth(dsize2d(13.14, 15.16), 17.18);
        test_assert(size[0] == 13.14);
        test_assert(size[1] == 15.16);
        test_assert(size[2] == 17.18);*/

        size.set_width_height_depth(dsize3d(19.20, 21.22, 23.24));
        test_assert(size[0] == 19.20);
        test_assert(size[1] == 21.22);
        test_assert(size[2] == 23.24);
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fsize3d size1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dsize3d size4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (size1 == size2);
        CONST_OR_CONSTEXPR auto result2 = (size1 == size3);
        CONST_OR_CONSTEXPR auto result3 = (size1 == size4);
        CONST_OR_CONSTEXPR auto result4 = (size1 == size5);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fsize3d size1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dsize3d size4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d size5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (size1 != size2);
        CONST_OR_CONSTEXPR auto result2 = (size1 != size3);
        CONST_OR_CONSTEXPR auto result3 = (size1 != size4);
        CONST_OR_CONSTEXPR auto result4 = (size1 != size5);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
    }

    TEST_CASE(tue_swap)
    {
        const dsize3d size1(1.2, 3.4, 5.6);
        const dsize3d size2(7.8, 9.10, 11.12);
        dsize3d size3 = size1;
        dsize3d size4 = size2;
        tue::swap(size3, size4);
        test_assert(size3 == size2);
        test_assert(size4 == size1);
    }

    TEST_CASE(std_swap)
    {
        const dsize3d size1(1.2, 3.4, 5.6);
        const dsize3d size2(7.8, 9.10, 11.12);
        dsize3d size3 = size1;
        dsize3d size4 = size2;
        std::swap(size3, size4);
        test_assert(size3 == size2);
        test_assert(size4 == size1);
    }

    TEST_CASE(std_hash)
    {
        std::hash<dsize3d> hash_dsize3d;
        const dsize3d size1(1.2, 3.4, 5.6);
        const dsize3d size2(1.2, 3.4, 5.6);
        const dsize3d size3(1.2, 3.4, 0.0);
        const dsize3d size4(1.2, 0.0, 5.6);
        const dsize3d size5(0.0, 3.4, 5.6);
        test_assert(hash_dsize3d(size1) == hash_dsize3d(size2));
        test_assert(hash_dsize3d(size1) != hash_dsize3d(size3));
        test_assert(hash_dsize3d(size1) != hash_dsize3d(size4));
        test_assert(hash_dsize3d(size1) != hash_dsize3d(size5));
    }
}
