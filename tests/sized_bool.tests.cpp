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
#include <type_traits>

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

        if (!true8)
        {
            test_fail("true8 wasn't cast to bool true");
        }

        if (false8)
        {
            test_fail("false8 wasn't cast to bool false");
        }
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

        if (!true16)
        {
            test_fail("true16 wasn't cast to bool true");
        }

        if (false16)
        {
            test_fail("false16 wasn't cast to bool false");
        }
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

        if (!true32)
        {
            test_fail("true32 wasn't cast to bool true");
        }

        if (false32)
        {
            test_fail("false32 wasn't cast to bool false");
        }
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

        if (!true64)
        {
            test_fail("true64 wasn't cast to bool true");
        }

        if (false64)
        {
            test_fail("false64 wasn't cast to bool false");
        }
    }

    TEST_CASE(sized_bool_t)
    {
        test_assert((std::is_same<sized_bool_t<1>, bool8>::value));
        test_assert((std::is_same<sized_bool_t<2>, bool16>::value));
        test_assert((std::is_same<sized_bool_t<4>, bool32>::value));
        test_assert((std::is_same<sized_bool_t<8>, bool64>::value));
    }

    TEST_CASE(is_sized_bool)
    {
        test_assert(is_sized_bool<std::uint32_t>::value == false);
        test_assert(is_sized_bool<bool8>::value == true);
        test_assert(is_sized_bool<bool16>::value == true);
        test_assert(is_sized_bool<bool32>::value == true);
        test_assert(is_sized_bool<bool64>::value == true);
    }

    TEST_CASE(bitwise_and_operator)
    {
        CONST_OR_CONSTEXPR auto tt8 =  true8 &  true8;
        CONST_OR_CONSTEXPR auto tf8 =  true8 & false8;
        CONST_OR_CONSTEXPR auto ft8 = false8 &  true8;
        CONST_OR_CONSTEXPR auto ff8 = false8 & false8;
        test_assert(tt8 == true8);
        test_assert(tf8 == false8);
        test_assert(ft8 == false8);
        test_assert(ff8 == false8);

        CONST_OR_CONSTEXPR auto tt16 =  true16 &  true16;
        CONST_OR_CONSTEXPR auto tf16 =  true16 & false16;
        CONST_OR_CONSTEXPR auto ft16 = false16 &  true16;
        CONST_OR_CONSTEXPR auto ff16 = false16 & false16;
        test_assert(tt16 == true16);
        test_assert(tf16 == false16);
        test_assert(ft16 == false16);
        test_assert(ff16 == false16);

        CONST_OR_CONSTEXPR auto tt32 =  true32 &  true32;
        CONST_OR_CONSTEXPR auto tf32 =  true32 & false32;
        CONST_OR_CONSTEXPR auto ft32 = false32 &  true32;
        CONST_OR_CONSTEXPR auto ff32 = false32 & false32;
        test_assert(tt32 == true32);
        test_assert(tf32 == false32);
        test_assert(ft32 == false32);
        test_assert(ff32 == false32);

        CONST_OR_CONSTEXPR auto tt64 =  true64 &  true64;
        CONST_OR_CONSTEXPR auto tf64 =  true64 & false64;
        CONST_OR_CONSTEXPR auto ft64 = false64 &  true64;
        CONST_OR_CONSTEXPR auto ff64 = false64 & false64;
        test_assert(tt64 == true64);
        test_assert(tf64 == false64);
        test_assert(ft64 == false64);
        test_assert(ff64 == false64);
    }

    TEST_CASE(bitwise_or_operator)
    {
        CONST_OR_CONSTEXPR auto tt8 =  true8 |  true8;
        CONST_OR_CONSTEXPR auto tf8 =  true8 | false8;
        CONST_OR_CONSTEXPR auto ft8 = false8 |  true8;
        CONST_OR_CONSTEXPR auto ff8 = false8 | false8;
        test_assert(tt8 == true8);
        test_assert(tf8 == true8);
        test_assert(ft8 == true8);
        test_assert(ff8 == false8);

        CONST_OR_CONSTEXPR auto tt16 =  true16 |  true16;
        CONST_OR_CONSTEXPR auto tf16 =  true16 | false16;
        CONST_OR_CONSTEXPR auto ft16 = false16 |  true16;
        CONST_OR_CONSTEXPR auto ff16 = false16 | false16;
        test_assert(tt16 == true16);
        test_assert(tf16 == true16);
        test_assert(ft16 == true16);
        test_assert(ff16 == false16);

        CONST_OR_CONSTEXPR auto tt32 =  true32 |  true32;
        CONST_OR_CONSTEXPR auto tf32 =  true32 | false32;
        CONST_OR_CONSTEXPR auto ft32 = false32 |  true32;
        CONST_OR_CONSTEXPR auto ff32 = false32 | false32;
        test_assert(tt32 == true32);
        test_assert(tf32 == true32);
        test_assert(ft32 == true32);
        test_assert(ff32 == false32);

        CONST_OR_CONSTEXPR auto tt64 =  true64 |  true64;
        CONST_OR_CONSTEXPR auto tf64 =  true64 | false64;
        CONST_OR_CONSTEXPR auto ft64 = false64 |  true64;
        CONST_OR_CONSTEXPR auto ff64 = false64 | false64;
        test_assert(tt64 == true64);
        test_assert(tf64 == true64);
        test_assert(ft64 == true64);
        test_assert(ff64 == false64);
    }

    TEST_CASE(bitwise_xor_operator)
    {
        CONST_OR_CONSTEXPR auto tt8 =  true8 ^  true8;
        CONST_OR_CONSTEXPR auto tf8 =  true8 ^ false8;
        CONST_OR_CONSTEXPR auto ft8 = false8 ^  true8;
        CONST_OR_CONSTEXPR auto ff8 = false8 ^ false8;
        test_assert(tt8 == false8);
        test_assert(tf8 == true8);
        test_assert(ft8 == true8);
        test_assert(ff8 == false8);

        CONST_OR_CONSTEXPR auto tt16 =  true16 ^  true16;
        CONST_OR_CONSTEXPR auto tf16 =  true16 ^ false16;
        CONST_OR_CONSTEXPR auto ft16 = false16 ^  true16;
        CONST_OR_CONSTEXPR auto ff16 = false16 ^ false16;
        test_assert(tt16 == false16);
        test_assert(tf16 == true16);
        test_assert(ft16 == true16);
        test_assert(ff16 == false16);

        CONST_OR_CONSTEXPR auto tt32 =  true32 ^  true32;
        CONST_OR_CONSTEXPR auto tf32 =  true32 ^ false32;
        CONST_OR_CONSTEXPR auto ft32 = false32 ^  true32;
        CONST_OR_CONSTEXPR auto ff32 = false32 ^ false32;
        test_assert(tt32 == false32);
        test_assert(tf32 == true32);
        test_assert(ft32 == true32);
        test_assert(ff32 == false32);

        CONST_OR_CONSTEXPR auto tt64 =  true64 ^  true64;
        CONST_OR_CONSTEXPR auto tf64 =  true64 ^ false64;
        CONST_OR_CONSTEXPR auto ft64 = false64 ^  true64;
        CONST_OR_CONSTEXPR auto ff64 = false64 ^ false64;
        test_assert(tt64 == false64);
        test_assert(tf64 == true64);
        test_assert(ft64 == true64);
        test_assert(ff64 == false64);
    }

    TEST_CASE(select)
    {
        constexpr auto x8 = math::select(
            true8, std::int8_t(1));
        constexpr auto y8 = math::select(
            false8, std::int8_t(1));
        constexpr auto z8 = math::select(
            true8, std::int8_t(1), std::int8_t(2));
        constexpr auto w8 = math::select(
            false8, std::int8_t(1), std::int8_t(2));
        test_assert(x8 == std::int8_t(1));
        test_assert(y8 == std::int8_t(0));
        test_assert(z8 == std::int8_t(1));
        test_assert(w8 == std::int8_t(2));

        constexpr auto x16 = math::select(
            true16, std::int16_t(1));
        constexpr auto y16 = math::select(
            false16, std::int16_t(1));
        constexpr auto z16 = math::select(
            true16, std::int16_t(1), std::int16_t(2));
        constexpr auto w16 = math::select(
            false16, std::int16_t(1), std::int16_t(2));
        test_assert(x16 == std::int16_t(1));
        test_assert(y16 == std::int16_t(0));
        test_assert(z16 == std::int16_t(1));
        test_assert(w16 == std::int16_t(2));

        constexpr auto x32 = math::select(
            true32, std::int32_t(1));
        constexpr auto y32 = math::select(
            false32, std::int32_t(1));
        constexpr auto z32 = math::select(
            true32, std::int32_t(1), std::int32_t(2));
        constexpr auto w32 = math::select(
            false32, std::int32_t(1), std::int32_t(2));
        test_assert(x32 == std::int32_t(1));
        test_assert(y32 == std::int32_t(0));
        test_assert(z32 == std::int32_t(1));
        test_assert(w32 == std::int32_t(2));

        constexpr auto x64 = math::select(
            true64, std::int64_t(1));
        constexpr auto y64 = math::select(
            false64, std::int64_t(1));
        constexpr auto z64 = math::select(
            true64, std::int64_t(1), std::int64_t(2));
        constexpr auto w64 = math::select(
            false64, std::int64_t(1), std::int64_t(2));
        test_assert(x64 == std::int64_t(1));
        test_assert(y64 == std::int64_t(0));
        test_assert(z64 == std::int64_t(1));
        test_assert(w64 == std::int64_t(2));
    }
}
