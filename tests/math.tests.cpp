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
    }

    TEST_CASE(cos)
    {
        test_assert(math::cos(1.2) == std::cos(1.2));
    }

    TEST_CASE(sincos)
    {
        double s, c;
        math::sincos(1.2, s, c);
        test_assert(s == std::sin(1.2));
        test_assert(c == std::cos(1.2));
    }

    TEST_CASE(exp)
    {
        test_assert(math::exp(1.2) == std::exp(1.2));
    }

    TEST_CASE(log)
    {
        test_assert(math::log(1.2) == std::log(1.2));
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
    }

    TEST_CASE(recip)
    {
        test_assert(math::recip(1.2) == 1 / 1.2);
    }

    TEST_CASE(sqrt)
    {
        test_assert(math::sqrt(1.2) == std::sqrt(1.2));
    }

    TEST_CASE(rsqrt)
    {
        test_assert(math::rsqrt(1.2) == 1 / std::sqrt(1.2));
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
        test_assert(math::select(true64, 1.2) == 1.2);
        test_assert(math::select(false64, 1.2) == 0.0);
        test_assert(math::select(true64, 1.2, 3.4) == 1.2);
        test_assert(math::select(false64, 1.2, 3.4) == 3.4);

        test_assert(math::select(true32, 1) == 1);
        test_assert(math::select(false32, 1) == 0);
        test_assert(math::select(true32, 1, 2) == 1);
        test_assert(math::select(false32, 1, 2) == 2);

        const auto t1 = math::select(
            true16, static_cast<bool16>(1));
        const auto f1 = math::select(
            false16, static_cast<bool16>(1));
        const auto t2 = math::select(
            true16, static_cast<bool16>(1), static_cast<bool16>(2));
        const auto f2 = math::select(
            false16, static_cast<bool16>(1), static_cast<bool16>(2));
        test_assert(t1 == static_cast<bool16>(1));
        test_assert(f1 == static_cast<bool16>(0));
        test_assert(t2 == static_cast<bool16>(1));
        test_assert(f2 == static_cast<bool16>(2));
    }

    TEST_CASE(less)
    {
        test_assert(math::less(1, 2) == true32);
        test_assert(math::less(2, 2) == false32);
        test_assert(math::less(3, 2) == false32);
    }

    TEST_CASE(less_equal)
    {
        test_assert(math::less_equal(1, 2) == true32);
        test_assert(math::less_equal(2, 2) == true32);
        test_assert(math::less_equal(3, 2) == false32);
    }

    TEST_CASE(greater)
    {
        test_assert(math::greater(1, 2) == false32);
        test_assert(math::greater(2, 2) == false32);
        test_assert(math::greater(3, 2) == true32);
    }

    TEST_CASE(greater_equal)
    {
        test_assert(math::greater_equal(1, 2) == false32);
        test_assert(math::greater_equal(2, 2) == true32);
        test_assert(math::greater_equal(3, 2) == true32);
    }

    TEST_CASE(equal)
    {
        test_assert(math::equal(1, 2) == false32);
        test_assert(math::equal(2, 2) == true32);
        test_assert(math::equal(3, 2) == false32);

        test_assert(math::equal(true32, true32) == true32);
        test_assert(math::equal(true32, false32) == false32);
        test_assert(math::equal(false32, true32) == false32);
        test_assert(math::equal(false32, false32) == true32);
    }

    TEST_CASE(not_equal)
    {
        test_assert(math::not_equal(1, 2) == true32);
        test_assert(math::not_equal(2, 2) == false32);
        test_assert(math::not_equal(3, 2) == true32);

        test_assert(math::not_equal(true32, true32) == false32);
        test_assert(math::not_equal(true32, false32) == true32);
        test_assert(math::not_equal(false32, true32) == true32);
        test_assert(math::not_equal(false32, false32) == false32);
    }
}
