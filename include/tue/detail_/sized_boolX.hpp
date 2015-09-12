//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../sized_bool.hpp"

namespace tue
{
    template<>
    struct sized_bool<1>
    {
        using type = bool8;
        static constexpr bool8 true_value = true8;
        static constexpr bool8 false_value = false8;
    };

    template<>
    struct sized_bool<2>
    {
        using type = bool16;
        static constexpr bool16 true_value = true16;
        static constexpr bool16 false_value = false16;
    };

    template<>
    struct sized_bool<4>
    {
        using type = bool32;
        static constexpr bool32 true_value = true32;
        static constexpr bool32 false_value = false32;
    };

    template<>
    struct sized_bool<8>
    {
        using type = bool64;
        static constexpr bool64 true_value = true64;
        static constexpr bool64 false_value = false64;
    };
}
