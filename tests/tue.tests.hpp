//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <mon/test_case.hpp>

#include <cmath>
#include <limits>

#ifdef _MSC_VER
#define CONST_OR_CONSTEXPR const
#else
#define CONST_OR_CONSTEXPR constexpr
#endif

namespace
{
    template<typename T>
    bool nearly_equal(T actual, T expected) noexcept
    {
        return actual == expected
            || std::abs(actual - expected) < std::abs(expected * 0.0003f)
            || std::abs(expected) == std::numeric_limits<T>::infinity();
    }
}
