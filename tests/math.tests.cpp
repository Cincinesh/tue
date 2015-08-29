//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/math.hpp>
#include <mon/test_case.hpp>

#include <cmath>

namespace
{
    using namespace tue;

    TEST_CASE(sin)
    {
        test_assert(math::sin(1.2) == std::sin(1.2));
        test_assert(math::sin(12) == std::sin(12.0));
    }

    TEST_CASE(cos)
    {
        test_assert(math::cos(1.2) == std::cos(1.2));
        test_assert(math::cos(12) == std::cos(12.0));
    }

    TEST_CASE(sincos)
    {
        double s, c;

        math::sincos(1.2, s, c);
        test_assert(s == std::sin(1.2));
        test_assert(c == std::cos(1.2));

        math::sincos(12, s, c);
        test_assert(s == std::sin(12.0));
        test_assert(c == std::cos(12.0));
    }

    TEST_CASE(exp)
    {
        test_assert(math::exp(1.2) == std::exp(1.2));
        test_assert(math::exp(12) == std::exp(12.0));
    }

    TEST_CASE(log)
    {
        test_assert(math::log(1.2) == std::log(1.2));
        test_assert(math::log(12) == std::log(12.0));
    }

    TEST_CASE(abs)
    {
        test_assert(math::abs(1.2) == 1.2);
        test_assert(math::abs(-1.2) == 1.2);
        test_assert(math::abs(12) == 12);
        test_assert(math::abs(-12) == 12);
        test_assert(math::abs(12u) == 12u);
    }

    TEST_CASE(pow)
    {
        test_assert(math::pow(1.2, 3.4) == std::pow(1.2, 3.4));
        test_assert(math::pow(1.2, 3.4L) == std::pow(1.2, 3.4L));
        test_assert(math::pow(1.2, 34) == std::pow(1.2, 34.0));

        test_assert(math::pow(1.2L, 3.4) == std::pow(1.2L, 3.4));
        test_assert(math::pow(1.2L, 3.4L) == std::pow(1.2L, 3.4L));
        test_assert(math::pow(1.2L, 34) == std::pow(1.2L, 34.0L));

        test_assert(math::pow(12, 3.4) == std::pow(12.0, 3.4));
        test_assert(math::pow(12, 3.4L) == std::pow(12.0L, 3.4L));
        test_assert(math::pow(12, 34) == std::pow(12.0, 34.0));
    }

    TEST_CASE(recip)
    {
        test_assert(math::recip(1.2) == 1 / 1.2);
        test_assert(math::recip(12) == 1 / 12.0);
    }

    TEST_CASE(sqrt)
    {
        test_assert(math::sqrt(1.2) == std::sqrt(1.2));
        test_assert(math::sqrt(12) == std::sqrt(12.0));
    }

    TEST_CASE(rsqrt)
    {
        test_assert(math::rsqrt(1.2) == 1 / std::sqrt(1.2));
        test_assert(math::rsqrt(12) == 1 / std::sqrt(12.0));
    }

    TEST_CASE(min)
    {
        test_assert(math::min(1.2, 3.4) == 1.2);
        test_assert(math::min(1.2, -3.4) == -3.4);

        test_assert(math::min(12, 34) == 12);
        test_assert(math::min(12, -34) == -34);
    }

    TEST_CASE(max)
    {
        test_assert(math::max(1.2, 3.4) == 3.4);
        test_assert(math::max(1.2, -3.4) == 1.2);

        test_assert(math::max(12, 34) == 34);
        test_assert(math::max(12, -34) == 12);
    }

    TEST_CASE(select)
    {
        constexpr auto x = math::select(true, 1, 2);
        constexpr auto y = math::select(false, 1, 2);
        test_assert(x == 1);
        test_assert(y == 2);
    }

    TEST_CASE(less)
    {
        constexpr auto x = math::less(1, 2.0);
        constexpr auto y = math::less(2, 2.0);
        constexpr auto z = math::less(3, 2.0);
        test_assert(x == true);
        test_assert(y == false);
        test_assert(z == false);
    }

    TEST_CASE(less_equal)
    {
        constexpr auto x = math::less_equal(1, 2.0);
        constexpr auto y = math::less_equal(2, 2.0);
        constexpr auto z = math::less_equal(3, 2.0);
        test_assert(x == true);
        test_assert(y == true);
        test_assert(z == false);
    }

    TEST_CASE(greater)
    {
        constexpr auto x = math::greater(1, 2.0);
        constexpr auto y = math::greater(2, 2.0);
        constexpr auto z = math::greater(3, 2.0);
        test_assert(x == false);
        test_assert(y == false);
        test_assert(z == true);
    }

    TEST_CASE(greater_equal)
    {
        constexpr auto x = math::greater_equal(1, 2.0);
        constexpr auto y = math::greater_equal(2, 2.0);
        constexpr auto z = math::greater_equal(3, 2.0);
        test_assert(x == false);
        test_assert(y == true);
        test_assert(z == true);
    }

    TEST_CASE(equal)
    {
        constexpr auto x = math::equal(1, 2.0);
        constexpr auto y = math::equal(2, 2.0);
        constexpr auto z = math::equal(3, 2.0);
        test_assert(x == false);
        test_assert(y == true);
        test_assert(z == false);
    }

    TEST_CASE(not_equal)
    {
        constexpr auto x = math::not_equal(1, 2.0);
        constexpr auto y = math::not_equal(2, 2.0);
        constexpr auto z = math::not_equal(3, 2.0);
        test_assert(x == true);
        test_assert(y == false);
        test_assert(z == true);
    }
}
