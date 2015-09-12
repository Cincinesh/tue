//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/sized_bool.hpp>
#include <mon/test_case.hpp>

#include <cstdint>

namespace
{
    using namespace tue;

    TEST_CASE(bool8)
    {
        test_assert(sizeof(bool8) == 1);
        test_assert(sizeof(true8) == 1);
        test_assert(sizeof(false8) == 1);
        test_assert(static_cast<std::uint8_t>(true8)
            == static_cast<std::uint8_t>(~0LL));
        test_assert(static_cast<std::uint8_t>(false8)
            == static_cast<std::uint8_t>(0LL));
    }

    TEST_CASE(bool16)
    {
        test_assert(sizeof(bool16) == 2);
        test_assert(sizeof(true16) == 2);
        test_assert(sizeof(false16) == 2);
        test_assert(static_cast<std::uint16_t>(true16)
            == static_cast<std::uint16_t>(~0LL));
        test_assert(static_cast<std::uint16_t>(false16)
            == static_cast<std::uint16_t>(0LL));
    }

    TEST_CASE(bool32)
    {
        test_assert(sizeof(bool32) == 4);
        test_assert(sizeof(true32) == 4);
        test_assert(sizeof(false32) == 4);
        test_assert(static_cast<std::uint32_t>(true32)
            == static_cast<std::uint32_t>(~0LL));
        test_assert(static_cast<std::uint32_t>(false32)
            == static_cast<std::uint32_t>(0LL));
    }

    TEST_CASE(bool64)
    {
        test_assert(sizeof(bool64) == 8);
        test_assert(sizeof(true64) == 8);
        test_assert(sizeof(false64) == 8);
        test_assert(static_cast<std::uint64_t>(true64)
            == static_cast<std::uint64_t>(~0LL));
        test_assert(static_cast<std::uint64_t>(false64)
            == static_cast<std::uint64_t>(0LL));
    }
}
