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

    /*TEST_CASE(set_x_y_z)
    {
        dsize3d size(1.2, 3.4, 5.6);
        size.set_x(7.8);
        size.set_y(9.10);
        size.set_z(11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);
    }

    TEST_CASE(set_xy)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_xy(7.8, 9.10);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 5.6);

        size.set_xy(dvec2(11.12, 13.14));
        test_assert(size[0] == 11.12);
        test_assert(size[1] == 13.14);
        test_assert(size[2] == 5.6);
    }

    TEST_CASE(set_xyz)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_xyz(7.8, 9.10, 11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);

        size.set_xyz(dvec2(13.14, 15.16), 17.18);
        test_assert(size[0] == 13.14);
        test_assert(size[1] == 15.16);
        test_assert(size[2] == 17.18);

        size.set_xyz(dsize3d(19.20, 21.22, 23.24));
        test_assert(size[0] == 19.20);
        test_assert(size[1] == 21.22);
        test_assert(size[2] == 23.24);
    }

    TEST_CASE(r_g_b)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto r = size.r();
        CONST_OR_CONSTEXPR auto g = size.g();
        CONST_OR_CONSTEXPR auto b = size.b();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
        test_assert(b == 5.6);
    }

    TEST_CASE(rg)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto rg = size.rg();
        test_assert(rg == dvec2(1.2, 3.4));
    }

    TEST_CASE(rgb)
    {
        CONST_OR_CONSTEXPR dsize3d size(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto rgb = size.rgb();
        test_assert(rgb == dsize3d(1.2, 3.4, 5.6));
    }

    TEST_CASE(set_r_g_b)
    {
        dsize3d size(1.2, 3.4, 5.6);
        size.set_r(7.8);
        size.set_g(9.10);
        size.set_b(11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);
    }

    TEST_CASE(set_rg)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_rg(7.8, 9.10);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 5.6);

        size.set_rg(dvec2(11.12, 13.14));
        test_assert(size[0] == 11.12);
        test_assert(size[1] == 13.14);
        test_assert(size[2] == 5.6);
    }

    TEST_CASE(set_rgb)
    {
        dsize3d size(1.2, 3.4, 5.6);

        size.set_rgb(7.8, 9.10, 11.12);
        test_assert(size[0] == 7.8);
        test_assert(size[1] == 9.10);
        test_assert(size[2] == 11.12);

        size.set_rgb(dvec2(13.14, 15.16), 17.18);
        test_assert(size[0] == 13.14);
        test_assert(size[1] == 15.16);
        test_assert(size[2] == 17.18);

        size.set_rgb(dsize3d(19.20, 21.22, 23.24));
        test_assert(size[0] == 19.20);
        test_assert(size[1] == 21.22);
        test_assert(size[2] == 23.24);
    }

    TEST_CASE(pre_increment_operator)
    {
        isize3d size(1, 2, 3);
        test_assert(&(++size) == &size);
        test_assert(size[0] == 2);
        test_assert(size[1] == 3);
        test_assert(size[2] == 4);
    }

    TEST_CASE(post_increment_operator)
    {
        isize3d size(1, 2, 3);
        test_assert(size++ == isize3d(1, 2, 3));
        test_assert(size[0] == 2);
        test_assert(size[1] == 3);
        test_assert(size[2] == 4);
    }

    TEST_CASE(pre_decrement_operator)
    {
        isize3d size(1, 2, 3);
        test_assert(&(--size) == &size);
        test_assert(size[0] == 0);
        test_assert(size[1] == 1);
        test_assert(size[2] == 2);
    }

    TEST_CASE(post_decrement_operator)
    {
        isize3d size(1, 2, 3);
        test_assert(size-- == isize3d(1, 2, 3));
        test_assert(size[0] == 0);
        test_assert(size[1] == 1);
        test_assert(size[2] == 2);
    }

    TEST_CASE(addition_assignment_operator)
    {
        dsize3d v1(1.2, 3.4, 5.6);
        test_assert(&(v1 += 7) == &v1);
        test_assert(v1[0] == 1.2 + 7);
        test_assert(v1[1] == 3.4 + 7);
        test_assert(v1[2] == 5.6 + 7);

        dsize3d v2(1.2, 3.4, 5.6);
        test_assert(&(v2 += isize3d(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 + 7);
        test_assert(v2[1] == 3.4 + 8);
        test_assert(v2[2] == 5.6 + 9);
    }

    TEST_CASE(subtraction_assignment_operator)
    {
        dsize3d v1(1.2, 3.4, 5.6);
        test_assert(&(v1 -= 7) == &v1);
        test_assert(v1[0] == 1.2 - 7);
        test_assert(v1[1] == 3.4 - 7);
        test_assert(v1[2] == 5.6 - 7);

        dsize3d v2(1.2, 3.4, 5.6);
        test_assert(&(v2 -= isize3d(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 - 7);
        test_assert(v2[1] == 3.4 - 8);
        test_assert(v2[2] == 5.6 - 9);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        dsize3d v1(1.2, 3.4, 5.6);
        test_assert(&(v1 *= 7) == &v1);
        test_assert(v1[0] == 1.2 * 7);
        test_assert(v1[1] == 3.4 * 7);
        test_assert(v1[2] == 5.6 * 7);

        dsize3d v2(1.2, 3.4, 5.6);
        test_assert(&(v2 *= isize3d(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 * 7);
        test_assert(v2[1] == 3.4 * 8);
        test_assert(v2[2] == 5.6 * 9);
    }

    TEST_CASE(quat_multiplication_assignment_operator)
    {
        const dsize3d v1(1.2, 3.4, 5.6);
        const fquat q(7.8f, 9.10f, 11.12f, 13.14f);

        auto v2 = v1;
        test_assert(&(v2 *= q) == &v2);
        test_assert(v2 == v1 * q);
    }

    TEST_CASE(mat_multiplication_assignment_operator)
    {
        const dsize3d v1(1.2, 3.4, 5.6);
        const fmat3x3 m(7.8f);

        auto v2 = v1;
        test_assert(&(v2 *= m) == &v2);
        test_assert(v2 == v1 * m);
    }

    TEST_CASE(division_assignment_operator)
    {
        dsize3d v1(1.2, 3.4, 5.6);
        test_assert(&(v1 /= 7) == &v1);
        test_assert(v1[0] == 1.2 / 7);
        test_assert(v1[1] == 3.4 / 7);
        test_assert(v1[2] == 5.6 / 7);

        dsize3d v2(1.2, 3.4, 5.6);
        test_assert(&(v2 /= isize3d(7, 8, 9)) == &v2);
        test_assert(v2[0] == 1.2 / 7);
        test_assert(v2[1] == 3.4 / 8);
        test_assert(v2[2] == 5.6 / 9);
    }

    TEST_CASE(modulo_assignment_operator)
    {
        size3d<long long> v1(10LL, 21LL, 32LL);
        test_assert(&(v1 %= 9) == &v1);
        test_assert(v1[0] == 10LL % 9);
        test_assert(v1[1] == 21LL % 9);
        test_assert(v1[2] == 32LL % 9);

        size3d<long long> v2(10LL, 21LL, 32LL);
        test_assert(&(v2 %= isize3d(9, 8, 7)) == &v2);
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 8);
        test_assert(v2[2] == 32LL % 7);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        size3d<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 &= 78) == &v1);
        test_assert(v1[0] == (12LL & 78));
        test_assert(v1[1] == (34LL & 78));
        test_assert(v1[2] == (56LL & 78));

        size3d<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 &= isize3d(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL & 78));
        test_assert(v2[1] == (34LL & 910));
        test_assert(v2[2] == (56LL & 1112));
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        size3d<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 |= 78) == &v1);
        test_assert(v1[0] == (12LL | 78));
        test_assert(v1[1] == (34LL | 78));
        test_assert(v1[2] == (56LL | 78));

        size3d<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 |= isize3d(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL | 78));
        test_assert(v2[1] == (34LL | 910));
        test_assert(v2[2] == (56LL | 1112));
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        size3d<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 ^= 78) == &v1);
        test_assert(v1[0] == (12LL ^ 78));
        test_assert(v1[1] == (34LL ^ 78));
        test_assert(v1[2] == (56LL ^ 78));

        size3d<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 ^= isize3d(78, 910, 1112)) == &v2);
        test_assert(v2[0] == (12LL ^ 78));
        test_assert(v2[1] == (34LL ^ 910));
        test_assert(v2[2] == (56LL ^ 1112));
    }

    TEST_CASE(bitwise_shift_left_assignment_operator)
    {
        size3d<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 <<= 1) == &v1);
        test_assert(v1[0] == (12LL << 1));
        test_assert(v1[1] == (34LL << 1));
        test_assert(v1[2] == (56LL << 1));

        size3d<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 <<= isize3d(1, 2, 3)) == &v2);
        test_assert(v2[0] == (12LL << 1));
        test_assert(v2[1] == (34LL << 2));
        test_assert(v2[2] == (56LL << 3));
    }

    TEST_CASE(bitwise_shift_right_assignment_operator)
    {
        size3d<long long> v1(12LL, 34LL, 56LL);
        test_assert(&(v1 >>= 1) == &v1);
        test_assert(v1[0] == (12LL >> 1));
        test_assert(v1[1] == (34LL >> 1));
        test_assert(v1[2] == (56LL >> 1));

        size3d<long long> v2(12LL, 34LL, 56LL);
        test_assert(&(v2 >>= isize3d(1, 2, 3)) == &v2);
        test_assert(v2[0] == (12LL >> 1));
        test_assert(v2[1] == (34LL >> 2));
        test_assert(v2[2] == (56LL >> 3));
    }

    TEST_CASE(unary_plus_operator)
    {
        CONST_OR_CONSTEXPR auto size = +dsize3d(1.2, 3.4, 5.6);
        test_assert(size == dsize3d(+1.2, +3.4, +5.6));
    }

    TEST_CASE(unary_minus_operator)
    {
        CONST_OR_CONSTEXPR auto size = -dsize3d(1.2, 3.4, 5.6);
        test_assert(size == dsize3d(-1.2, -3.4, -5.6));
    }

    TEST_CASE(bitwise_not_operator)
    {
        CONST_OR_CONSTEXPR auto size = ~isize3d(1, 2, 3);
        test_assert(size == isize3d(~1, ~2, ~3));
    }

    TEST_CASE(addition_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 + dsize3d(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 + 2.3);
        test_assert(v1[1] == 1 + 4.5);
        test_assert(v1[2] == 1 + 6.7);

        CONST_OR_CONSTEXPR auto v2 = dsize3d(1.2, 3.4, 5.6) + 7;
        test_assert(v2[0] == 1.2 + 7);
        test_assert(v2[1] == 3.4 + 7);
        test_assert(v2[2] == 5.6 + 7);

        CONST_OR_CONSTEXPR auto v3 = dsize3d(1.2, 3.4, 5.6) + isize3d(7, 8, 9);
        test_assert(v3[0] == 1.2 + 7);
        test_assert(v3[1] == 3.4 + 8);
        test_assert(v3[2] == 5.6 + 9);
    }

    TEST_CASE(subtraction_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 - dsize3d(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 - 2.3);
        test_assert(v1[1] == 1 - 4.5);
        test_assert(v1[2] == 1 - 6.7);

        CONST_OR_CONSTEXPR auto v2 = dsize3d(1.2, 3.4, 5.6) - 7;
        test_assert(v2[0] == 1.2 - 7);
        test_assert(v2[1] == 3.4 - 7);
        test_assert(v2[2] == 5.6 - 7);

        CONST_OR_CONSTEXPR auto v3 = dsize3d(1.2, 3.4, 5.6) - isize3d(7, 8, 9);
        test_assert(v3[0] == 1.2 - 7);
        test_assert(v3[1] == 3.4 - 8);
        test_assert(v3[2] == 5.6 - 9);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 12 * dsize3d(2.3, 4.5, 6.7);
        test_assert(v1[0] == 12 * 2.3);
        test_assert(v1[1] == 12 * 4.5);
        test_assert(v1[2] == 12 * 6.7);

        CONST_OR_CONSTEXPR auto v2 = dsize3d(1.2, 3.4, 5.6) * 7;
        test_assert(v2[0] == 1.2 * 7);
        test_assert(v2[1] == 3.4 * 7);
        test_assert(v2[2] == 5.6 * 7);

        CONST_OR_CONSTEXPR auto v3 = dsize3d(1.2, 3.4, 5.6) * isize3d(7, 8, 9);
        test_assert(v3[0] == 1.2 * 7);
        test_assert(v3[1] == 3.4 * 8);
        test_assert(v3[2] == 5.6 * 9);
    }

    TEST_CASE(division_operator)
    {
        CONST_OR_CONSTEXPR auto v1 = 1 / dsize3d(2.3, 4.5, 6.7);
        test_assert(v1[0] == 1 / 2.3);
        test_assert(v1[1] == 1 / 4.5);
        test_assert(v1[2] == 1 / 6.7);

        CONST_OR_CONSTEXPR auto v2 = dsize3d(1.2, 3.4, 5.6) / 7;
        test_assert(v2[0] == 1.2 / 7);
        test_assert(v2[1] == 3.4 / 7);
        test_assert(v2[2] == 5.6 / 7);

        CONST_OR_CONSTEXPR auto v3 = dsize3d(1.2, 3.4, 5.6) / isize3d(7, 8, 9);
        test_assert(v3[0] == 1.2 / 7);
        test_assert(v3[1] == 3.4 / 8);
        test_assert(v3[2] == 5.6 / 9);
    }

    TEST_CASE(modulo_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            10 % size3d<long long>(9LL, 8LL, 7LL);
        test_assert(v1[0] == 10 % 9LL);
        test_assert(v1[1] == 10 % 8LL);
        test_assert(v1[2] == 10 % 7LL);

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(10LL, 21LL, 32LL) % 9;
        test_assert(v2[0] == 10LL % 9);
        test_assert(v2[1] == 21LL % 9);
        test_assert(v2[2] == 32LL % 9);

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(10LL, 21LL, 32LL) % isize3d(9, 8, 7);
        test_assert(v3[0] == 10LL % 9);
        test_assert(v3[1] == 21LL % 8);
        test_assert(v3[2] == 32LL % 7);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 & size3d<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 & 23LL));
        test_assert(v1[1] == (1 & 45LL));
        test_assert(v1[2] == (1 & 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(12LL, 34LL, 56LL) & 7;
        test_assert(v2[0] == (12LL & 7));
        test_assert(v2[1] == (34LL & 7));
        test_assert(v2[2] == (56LL & 7));

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(12LL, 34LL, 56LL) & isize3d(78, 910, 1112);
        test_assert(v3[0] == (12LL & 78));
        test_assert(v3[1] == (34LL & 910));
        test_assert(v3[2] == (56LL & 1112));
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 | size3d<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 | 23LL));
        test_assert(v1[1] == (1 | 45LL));
        test_assert(v1[2] == (1 | 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(12LL, 34LL, 56LL) | 7;
        test_assert(v2[0] == (12LL | 7));
        test_assert(v2[1] == (34LL | 7));
        test_assert(v2[2] == (56LL | 7));

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(12LL, 34LL, 56LL) | isize3d(78, 910, 1112);
        test_assert(v3[0] == (12LL | 78));
        test_assert(v3[1] == (34LL | 910));
        test_assert(v3[2] == (56LL | 1112));
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            1 ^ size3d<long long>(23LL, 45LL, 67LL);
        test_assert(v1[0] == (1 ^ 23LL));
        test_assert(v1[1] == (1 ^ 45LL));
        test_assert(v1[2] == (1 ^ 67LL));

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(12LL, 34LL, 56LL) ^ 7;
        test_assert(v2[0] == (12LL ^ 7));
        test_assert(v2[1] == (34LL ^ 7));
        test_assert(v2[2] == (56LL ^ 7));

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(12LL, 34LL, 56LL) ^ isize3d(78, 910, 1112);
        test_assert(v3[0] == (12LL ^ 78));
        test_assert(v3[1] == (34LL ^ 910));
        test_assert(v3[2] == (56LL ^ 1112));
    }

    TEST_CASE(bitwise_shift_left_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            54 << size3d<long long>(3LL, 2LL, 1LL);
        test_assert(v1[0] == (54 << 3LL));
        test_assert(v1[1] == (54 << 2LL));
        test_assert(v1[2] == (54 << 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(76LL, 54LL, 32LL) << 1;
        test_assert(v2[0] == (76LL << 1));
        test_assert(v2[1] == (54LL << 1));
        test_assert(v2[2] == (32LL << 1));

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(98LL, 76LL, 54LL) << isize3d(3, 2, 1);
        test_assert(v3[0] == (98LL << 3));
        test_assert(v3[1] == (76LL << 2));
        test_assert(v3[2] == (54LL << 1));
    }

    TEST_CASE(bitwise_shift_right_operator)
    {
        CONST_OR_CONSTEXPR auto v1 =
            54 >> size3d<long long>(3LL, 2LL, 1LL);
        test_assert(v1[0] == (54 >> 3LL));
        test_assert(v1[1] == (54 >> 2LL));
        test_assert(v1[2] == (54 >> 1LL));

        CONST_OR_CONSTEXPR auto v2 =
            size3d<long long>(76LL, 54LL, 32LL) >> 1;
        test_assert(v2[0] == (76LL >> 1));
        test_assert(v2[1] == (54LL >> 1));
        test_assert(v2[2] == (32LL >> 1));

        CONST_OR_CONSTEXPR auto v3 =
            size3d<long long>(98LL, 76LL, 54LL) >> isize3d(3, 2, 1);
        test_assert(v3[0] == (98LL >> 3));
        test_assert(v3[1] == (76LL >> 2));
        test_assert(v3[2] == (54LL >> 1));
    }

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fsize3d v1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dsize3d v4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (v1 == v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 == v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 == v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 == v5);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fsize3d v1(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v2(1.2f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v3(1.2f, 3.4f, 0.0f);
        CONST_OR_CONSTEXPR dsize3d v4(1.2f, 0.0f, 5.6f);
        CONST_OR_CONSTEXPR dsize3d v5(0.0f, 3.4f, 5.6f);
        CONST_OR_CONSTEXPR auto result1 = (v1 != v2);
        CONST_OR_CONSTEXPR auto result2 = (v1 != v3);
        CONST_OR_CONSTEXPR auto result3 = (v1 != v4);
        CONST_OR_CONSTEXPR auto result4 = (v1 != v5);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
    }

    TEST_CASE(sin)
    {
        const auto size = math::sin(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::sin(1.2)));
        test_assert(nearly_equal(size[1], math::sin(3.4)));
        test_assert(nearly_equal(size[2], math::sin(5.6)));
    }

    TEST_CASE(cos)
    {
        const auto size = math::cos(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::cos(1.2)));
        test_assert(nearly_equal(size[1], math::cos(3.4)));
        test_assert(nearly_equal(size[2], math::cos(5.6)));
    }

    TEST_CASE(sincos)
    {
        dsize3d s, c;
        math::sincos(dsize3d(1.2, 3.4, 5.6), s, c);

        test_assert(nearly_equal(s[0], math::sin(1.2)));
        test_assert(nearly_equal(s[1], math::sin(3.4)));
        test_assert(nearly_equal(s[2], math::sin(5.6)));

        test_assert(nearly_equal(c[0], math::cos(1.2)));
        test_assert(nearly_equal(c[1], math::cos(3.4)));
        test_assert(nearly_equal(c[2], math::cos(5.6)));
    }

    TEST_CASE(exp)
    {
        const auto size = math::exp(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::exp(1.2)));
        test_assert(nearly_equal(size[1], math::exp(3.4)));
        test_assert(nearly_equal(size[2], math::exp(5.6)));
    }

    TEST_CASE(log)
    {
        const auto size = math::log(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::log(1.2)));
        test_assert(nearly_equal(size[1], math::log(3.4)));
        test_assert(nearly_equal(size[2], math::log(5.6)));
    }

    TEST_CASE(abs)
    {
        const auto size = math::abs(dsize3d(1.2, -3.4, 5.6));
        test_assert(size[0] == math::abs(1.2));
        test_assert(size[1] == math::abs(-3.4));
        test_assert(size[2] == math::abs(5.6));
    }

    TEST_CASE(pow)
    {
        const auto size = math::pow(
            dsize3d(1.2, 3.4, 5.6), dsize3d(7.8, 9.10, 11.12));
        test_assert(nearly_equal(size[0], math::pow(1.2, 7.8)));
        test_assert(nearly_equal(size[1], math::pow(3.4, 9.10)));
        test_assert(nearly_equal(size[2], math::pow(5.6, 11.12)));
    }

    TEST_CASE(recip)
    {
        const auto size = math::recip(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::recip(1.2)));
        test_assert(nearly_equal(size[1], math::recip(3.4)));
        test_assert(nearly_equal(size[2], math::recip(5.6)));
    }

    TEST_CASE(sqrt)
    {
        const auto size = math::sqrt(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::sqrt(1.2)));
        test_assert(nearly_equal(size[1], math::sqrt(3.4)));
        test_assert(nearly_equal(size[2], math::sqrt(5.6)));
    }

    TEST_CASE(rsqrt)
    {
        const auto size = math::rsqrt(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(size[0], math::rsqrt(1.2)));
        test_assert(nearly_equal(size[1], math::rsqrt(3.4)));
        test_assert(nearly_equal(size[2], math::rsqrt(5.6)));
    }

    TEST_CASE(min)
    {
        const auto size = math::min(
            dsize3d(1.2, 3.4, 5.6), dsize3d(7.8, -9.10, 11.12));
        test_assert(size[0] == math::min(1.2, 7.8));
        test_assert(size[1] == math::min(3.4, -9.10));
        test_assert(size[2] == math::min(5.6, 11.12));
    }

    TEST_CASE(max)
    {
        const auto size = math::max(
            dsize3d(1.2, 3.4, 5.6), dsize3d(7.8, -9.10, 11.12));
        test_assert(size[0] == math::max(1.2, 7.8));
        test_assert(size[1] == math::max(3.4, -9.10));
        test_assert(size[2] == math::max(5.6, 11.12));
    }

    TEST_CASE(mask)
    {
        const auto size = math::mask(
            size3d<bool64>(true64, false64, true64),
            dsize3d(1.2, 3.4, 5.6));
        test_assert(size == dsize3d(1.2, 0.0, 5.6));
    }

    TEST_CASE(select)
    {
        const auto size = math::select(
            size3d<bool64>(true64, false64, true64),
            dsize3d(1.2, 3.4, 5.6), dsize3d(7.8, 9.10, 11.12));
        test_assert(size == dsize3d(1.2, 9.10, 5.6));
    }

    TEST_CASE(less)
    {
        const auto size = math::less(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(true64, false64, false64));
    }

    TEST_CASE(less_equal)
    {
        const auto size = math::less_equal(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(true64, true64, false64));
    }

    TEST_CASE(greater)
    {
        const auto size = math::greater(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(false64, false64, true64));
    }

    TEST_CASE(greater_equal)
    {
        const auto size = math::greater_equal(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(false64, true64, true64));
    }

    TEST_CASE(equal)
    {
        const auto size = math::equal(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(false64, true64, false64));
    }

    TEST_CASE(not_equal)
    {
        const auto size = math::not_equal(
            dsize3d(1.0, 2.0, 3.0), dsize3d(2.1, 2.0, 1.9));
        test_assert(size == size3d<bool64>(true64, false64, true64));
    }

    TEST_CASE(dot)
    {
        CONST_OR_CONSTEXPR auto x = math::dot(
            dsize3d(1.2, 3.4, 5.6), dsize3d(7, 8, 9));
        test_assert(nearly_equal(x, 1.2*7 + 3.4*8 + 5.6*9));
    }

    TEST_CASE(cross)
    {
        CONST_OR_CONSTEXPR auto size = math::cross(
            dsize3d(1.2, 3.4, 5.6), dsize3d(7, 8, 9));
        test_assert(size[0] == 3.4*9 - 5.6*8);
        test_assert(size[1] == 5.6*7 - 1.2*9);
        test_assert(size[2] == 1.2*8 - 3.4*7);
    }

    TEST_CASE(length)
    {
        test_assert(nearly_equal(
            math::length(dsize3d(1.2, 3.4, 5.6)),
            math::sqrt(math::length2(dsize3d(1.2, 3.4, 5.6)))));
    }

    TEST_CASE(length2)
    {
        CONST_OR_CONSTEXPR auto x = math::length2(dsize3d(1.2, 3.4, 5.6));
        test_assert(nearly_equal(x, 1.2*1.2 + 3.4*3.4 + 5.6*5.6));
    }

    TEST_CASE(rlength)
    {
        test_assert(nearly_equal(
            math::rlength(dsize3d(1.2, 3.4, 5.6)),
            math::rsqrt(math::length2(dsize3d(1.2, 3.4, 5.6)))));
    }

    TEST_CASE(normalize)
    {
        const dsize3d size(1.2, 3.4, 5.6);
        test_assert(math::normalize(size) == size * math::rlength(size));
    }

    TEST_CASE(tue_swap)
    {
        const dsize3d v1(1.2, 3.4, 5.6);
        const dsize3d v2(7.8, 9.10, 11.12);
        dsize3d v3 = v1;
        dsize3d v4 = v2;
        tue::swap(v3, v4);
        test_assert(v3 == v2);
        test_assert(v4 == v1);
    }

    TEST_CASE(std_swap)
    {
        const dsize3d v1(1.2, 3.4, 5.6);
        const dsize3d v2(7.8, 9.10, 11.12);
        dsize3d v3 = v1;
        dsize3d v4 = v2;
        std::swap(v3, v4);
        test_assert(v3 == v2);
        test_assert(v4 == v1);
    }

    TEST_CASE(std_hash)
    {
        std::hash<dsize3d> hash_dsize3d;
        const dsize3d v1(1.2, 3.4, 5.6);
        const dsize3d v2(1.2, 3.4, 5.6);
        const dsize3d v3(1.2, 3.4, 0.0);
        const dsize3d v4(1.2, 0.0, 5.6);
        const dsize3d v5(0.0, 3.4, 5.6);
        test_assert(hash_dsize3d(v1) == hash_dsize3d(v2));
        test_assert(hash_dsize3d(v1) != hash_dsize3d(v3));
        test_assert(hash_dsize3d(v1) != hash_dsize3d(v4));
        test_assert(hash_dsize3d(v1) != hash_dsize3d(v5));
    }*/
}
