//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

#include "../sized_bool.hpp"

namespace tue
{
    template<typename T>
    struct is_sized_bool : public std::integral_constant<bool, false>
    {
        using std::integral_constant<bool, false>::integral_constant;
    };

    template<>
    struct is_sized_bool<bool8> : public std::integral_constant<bool, true>
    {
        using std::integral_constant<bool, true>::integral_constant;
    };

    template<>
    struct is_sized_bool<bool16> : public std::integral_constant<bool, true>
    {
        using std::integral_constant<bool, true>::integral_constant;
    };

    template<>
    struct is_sized_bool<bool32> : public std::integral_constant<bool, true>
    {
        using std::integral_constant<bool, true>::integral_constant;
    };

    template<>
    struct is_sized_bool<bool64> : public std::integral_constant<bool, true>
    {
        using std::integral_constant<bool, true>::integral_constant;
    };
}
