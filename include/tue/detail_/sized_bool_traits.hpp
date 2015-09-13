//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstddef>
#include <cstdint>

#include "../sized_bool.hpp"

namespace tue
{
    template<>
    struct sized_bool_traits<1>
    {
        using type = bool8;
        using uint_t = std::uint8_t;
        static constexpr std::size_t size = 1;
        static constexpr bool8 true_value = true8;
        static constexpr bool8 false_value = false8;
    };

    template<>
    struct sized_bool_traits<2>
    {
        using type = bool16;
        using uint_t = std::uint16_t;
        static constexpr std::size_t size = 2;
        static constexpr bool16 true_value = true16;
        static constexpr bool16 false_value = false16;
    };

    template<>
    struct sized_bool_traits<4>
    {
        using type = bool32;
        using uint_t = std::uint32_t;
        static constexpr std::size_t size = 4;
        static constexpr bool32 true_value = true32;
        static constexpr bool32 false_value = false32;
    };

    template<>
    struct sized_bool_traits<8>
    {
        using type = bool64;
        using uint_t = std::uint64_t;
        static constexpr std::size_t size = 8;
        static constexpr bool64 true_value = true64;
        static constexpr bool64 false_value = false64;
    };
}
