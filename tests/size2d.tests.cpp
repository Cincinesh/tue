//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/size2d.hpp>
#include "tue.tests.hpp"

#include <type_traits>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(size2d<short>) == sizeof(short[2]));
        test_assert(sizeof(fsize2d) == sizeof(float[2]));
        test_assert(sizeof(dsize2d) == sizeof(double[2]));
        test_assert(sizeof(isize2d) == sizeof(int[2]));
        test_assert(sizeof(usize2d) == sizeof(unsigned int[2]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(size2d<short>) == alignof(short[2]));
        test_assert(alignof(fsize2d) == alignof(float[2]));
        test_assert(alignof(dsize2d) <= alignof(double[2]));
        test_assert(alignof(isize2d) == alignof(int[2]));
        test_assert(alignof(usize2d) == alignof(unsigned int[2]));
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
                     typename size2d<short>::component_type, short>::value));
        test_assert((std::is_same<
                     typename fsize2d::component_type, float>::value));
        test_assert((std::is_same<
                     typename dsize2d::component_type, double>::value));
        test_assert((std::is_same<
                     typename isize2d::component_type, int>::value));
        test_assert((std::is_same<
                     typename usize2d::component_type, unsigned int>::value));
    }

    TEST_CASE(component_count)
    {
        constexpr auto s2s = size2d<short>::component_count;
        constexpr auto fs2 = fsize2d::component_count;
        constexpr auto ds2 = dsize2d::component_count;
        constexpr auto is2 = isize2d::component_count;
        constexpr auto us2 = usize2d::component_count;
        test_assert(s2s == 2);
        test_assert(fs2 == 2);
        test_assert(ds2 == 2);
        test_assert(is2 == 2);
        test_assert(us2 == 2);
    }

    TEST_CASE(default_constructor)
    {
        dsize2d size;
        unused(size);
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR dsize2d size(1.2);
        test_assert(size[0] == 1.2);
        test_assert(size[1] == 1.2);
    }

    TEST_CASE(individual_component_constructor)
    {
        CONST_OR_CONSTEXPR dsize2d size = { 1.2, 3.4 };
        test_assert(size[0] == 1.2);
        test_assert(size[1] == 3.4);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dsize2d dsize(1.2, 3.4);
        CONST_OR_CONSTEXPR fsize2d fsize(dsize);
        test_assert(fsize[0] == 1.2f);
        test_assert(fsize[1] == 3.4f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fsize2d fsize(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dsize2d dsize = fsize;
        test_assert(dsize[0] == 1.2f);
        test_assert(dsize[1] == 3.4f);
    }

    TEST_CASE(zero)
    {
        CONST_OR_CONSTEXPR auto size = dsize2d::zero();
        test_assert(size == dsize2d(0.0, 0.0));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dsize2d cesize(1.2, 3.4);
        CONST_OR_CONSTEXPR auto cesize0 = cesize[0];
        CONST_OR_CONSTEXPR auto cesize1 = cesize[1];
        test_assert(cesize0 == 1.2);
        test_assert(cesize1 == 3.4);

        const auto csize = cesize;
        const auto& csize0 = csize[0];
        const auto& csize1 = csize[1];
        test_assert(&csize0 == csize.data() + 0);
        test_assert(&csize1 == csize.data() + 1);

        auto size = cesize;
        auto& size0 = size[0];
        auto& size1 = size[1];
        test_assert(&size0 == size.data() + 0);
        test_assert(&size1 == size.data() + 1);
    }

    TEST_CASE(data)
    {
        const dsize2d csize(1.2);
        const double* cdata = csize.data();
        test_assert(cdata == static_cast<const void*>(&csize));

        dsize2d size;
        double* data = size.data();
        test_assert(data == static_cast<void*>(&size));
    }

    TEST_CASE(width_height_getters)
    {
        CONST_OR_CONSTEXPR dsize2d size(1.2, 3.4);
        CONST_OR_CONSTEXPR auto width = size.width();
        CONST_OR_CONSTEXPR auto height = size.height();
        test_assert(width == 1.2);
        test_assert(height == 3.4);
    }

    TEST_CASE(width_height)
    {
        CONST_OR_CONSTEXPR dsize2d size(1.2, 3.4);
        CONST_OR_CONSTEXPR auto width_height = size.width_height();
        test_assert(width_height == dsize2d(1.2, 3.4));
    }

    TEST_CASE(width_height_setters)
    {
        dsize2d size(1.2, 3.4);
        size.set_width(7.8);
        size.set_height(9.10);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
    }

    TEST_CASE(set_width_height)
    {
        dsize2d size(1.2, 3.4);

        size.set_width_height(7.8, 9.10);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);

        size.set_width_height(dsize2d(11.12, 12.14));
        test_assert(size[0] == 11.12);
        test_assert(size[1] == 12.14);
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fsize2d size1(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dsize2d size2(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dsize2d size3(1.2f, 0.0f);
        CONST_OR_CONSTEXPR dsize2d size4(0.0f, 3.4f);
        CONST_OR_CONSTEXPR auto result1 = (size1 == size2);
        CONST_OR_CONSTEXPR auto result2 = (size1 == size3);
        CONST_OR_CONSTEXPR auto result3 = (size1 == size4);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fsize2d size1(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dsize2d size2(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dsize2d size3(1.2f, 0.0f);
        CONST_OR_CONSTEXPR dsize2d size4(0.0f, 3.4f);
        CONST_OR_CONSTEXPR auto result1 = (size1 != size2);
        CONST_OR_CONSTEXPR auto result2 = (size1 != size3);
        CONST_OR_CONSTEXPR auto result3 = (size1 != size4);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
    }

    TEST_CASE(tue_swap)
    {
        const dsize2d size1(1.2, 3.4);
        const dsize2d size2(5.6, 7.8);
        dsize2d size3 = size1;
        dsize2d size4 = size2;
        tue::swap(size3, size4);
        test_assert(size3 == size2);
        test_assert(size4 == size1);
    }

    TEST_CASE(std_swap)
    {
        const dsize2d size1(1.2, 3.4);
        const dsize2d size2(5.6, 7.8);
        dsize2d size3 = size1;
        dsize2d size4 = size2;
        std::swap(size3, size4);
        test_assert(size3 == size2);
        test_assert(size4 == size1);
    }

    TEST_CASE(std_hash)
    {
        std::hash<dsize2d> hash_dsize2d;
        const dsize2d size1(1.2, 3.4);
        const dsize2d size2(1.2, 3.4);
        const dsize2d size3(1.2, 0.0);
        const dsize2d size4(0.0, 3.4);
        test_assert(hash_dsize2d(size1) == hash_dsize2d(size2));
        test_assert(hash_dsize2d(size1) != hash_dsize2d(size3));
        test_assert(hash_dsize2d(size1) != hash_dsize2d(size4));
    }
}
