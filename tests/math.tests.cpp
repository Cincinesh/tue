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

    TEST_CASE(floating_point_cos)
    {
        test_assert(math::cos(1.2) == std::cos(1.2));
    }

    TEST_CASE(integral_cos)
    {
        test_assert(math::cos(12) == std::cos(12.0));
    }


    TEST_CASE(floating_point_sin)
    {
        test_assert(math::sin(1.2) == std::sin(1.2));
    }

    TEST_CASE(integral_sin)
    {
        test_assert(math::sin(12) == std::sin(12.0));
    }

    TEST_CASE(floating_point_sincos)
    {
        double s, c;
        math::sincos(1.2, s, c);
        test_assert(s == std::sin(1.2));
        test_assert(c == std::cos(1.2));
    }

    TEST_CASE(integral_sincos)
    {
        double s, c;
        math::sincos(12, s, c);
        test_assert(s == std::sin(12.0));
        test_assert(c == std::cos(12.0));
    }

    TEST_CASE(floating_point_exp)
    {
        test_assert(math::exp(1.2) == std::exp(1.2));
    }

    TEST_CASE(integral_exp)
    {
        test_assert(math::exp(12) == std::exp(12.0));
    }

    TEST_CASE(floating_point_log)
    {
        test_assert(math::log(1.2) == std::log(1.2));
    }

    TEST_CASE(integral_log)
    {
        test_assert(math::log(12) == std::log(12.0));
    }

    TEST_CASE(signed_abs)
    {
        test_assert(math::abs(1.2) == 1.2);
        test_assert(math::abs(-1.2) == 1.2);
        test_assert(math::abs(12) == 12);
        test_assert(math::abs(-12) == 12);
    }

    TEST_CASE(unsigned_abs)
    {
        test_assert(math::abs(12u) == 12u);
    }

    TEST_CASE(pow)
    {
        test_assert(math::pow(1.2, 3.4) == std::pow(1.2, 3.4));
        test_assert(math::pow(1.2, 3.4L) == std::pow(1.2L, 3.4L));
        test_assert(math::pow(1.2, 34) == std::pow(1.2, 34.0));

        test_assert(math::pow(1.2L, 3.4) == std::pow(1.2L, 3.4L));
        test_assert(math::pow(1.2L, 3.4L) == std::pow(1.2L, 3.4L));
        test_assert(math::pow(1.2L, 34) == std::pow(1.2L, 34.0L));

        test_assert(math::pow(12, 3.4) == std::pow(12.0, 3.4));
        test_assert(math::pow(12, 3.4L) == std::pow(12.0L, 3.4L));
        test_assert(math::pow(12, 34) == std::pow(12.0, 34.0));
    }
}
