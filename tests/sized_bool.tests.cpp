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

    TEST_CASE(implicit_cast_to_bool)
    {
        if (!true8 || !true16 || !true32 || !true64
            || false8 || false16 || false32 || false64)
        {
            test_fail(
                "Sized bool types didn't implicitly cast to bool as expected");
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

    TEST_CASE(bitwise_not_operator)
    {
        constexpr auto nt = ~true32;
        constexpr auto nf = ~false32;
        test_assert(nt == false32);
        test_assert(nf == true32);
    }

    TEST_CASE(bitwise_and_operator)
    {
        constexpr auto tt =  true32 &  true32;
        constexpr auto tf =  true32 & false32;
        constexpr auto ft = false32 &  true32;
        constexpr auto ff = false32 & false32;
        test_assert(tt == true32);
        test_assert(tf == false32);
        test_assert(ft == false32);
        test_assert(ff == false32);
    }

    TEST_CASE(bitwise_or_operator)
    {
        constexpr auto tt =  true32 |  true32;
        constexpr auto tf =  true32 | false32;
        constexpr auto ft = false32 |  true32;
        constexpr auto ff = false32 | false32;
        test_assert(tt == true32);
        test_assert(tf == true32);
        test_assert(ft == true32);
        test_assert(ff == false32);
    }

    TEST_CASE(bitwise_xor_operator)
    {
        constexpr auto tt =  true32 ^  true32;
        constexpr auto tf =  true32 ^ false32;
        constexpr auto ft = false32 ^  true32;
        constexpr auto ff = false32 ^ false32;
        test_assert(tt == false32);
        test_assert(tf == true32);
        test_assert(ft == true32);
        test_assert(ff == false32);
    }

    TEST_CASE(bitwise_and_assignment_operator)
    {
        auto tt = true32;
        test_assert(&(tt &= true32) == &tt);
        test_assert(tt == true32);

        auto tf = true32;
        test_assert(&(tf &= false32) == &tf);
        test_assert(tf == false32);

        auto ft = false32;
        test_assert(&(ft &= true32) == &ft);
        test_assert(ft == false32);

        auto ff = false32;
        test_assert(&(ff &= false32) == &ff);
        test_assert(ff == false32);
    }

    TEST_CASE(bitwise_or_assignment_operator)
    {
        auto tt = true32;
        test_assert(&(tt |= true32) == &tt);
        test_assert(tt == true32);

        auto tf = true32;
        test_assert(&(tf |= false32) == &tf);
        test_assert(tf == true32);

        auto ft = false32;
        test_assert(&(ft |= true32) == &ft);
        test_assert(ft == true32);

        auto ff = false32;
        test_assert(&(ff |= false32) == &ff);
        test_assert(ff == false32);
    }

    TEST_CASE(bitwise_xor_assignment_operator)
    {
        auto tt = true32;
        test_assert(&(tt ^= true32) == &tt);
        test_assert(tt == false32);

        auto tf = true32;
        test_assert(&(tf ^= false32) == &tf);
        test_assert(tf == true32);

        auto ft = false32;
        test_assert(&(ft ^= true32) == &ft);
        test_assert(ft == true32);

        auto ff = false32;
        test_assert(&(ff ^= false32) == &ff);
        test_assert(ff == false32);
    }

    TEST_CASE(select)
    {
        constexpr auto x = math::select(
            true32, std::int32_t(1));
        constexpr auto y = math::select(
            false32, std::int32_t(1));
        constexpr auto z = math::select(
            true32, std::int32_t(1), std::int32_t(2));
        constexpr auto w = math::select(
            false32, std::int32_t(1), std::int32_t(2));
        test_assert(x == std::int32_t(1));
        test_assert(y == std::int32_t(0));
        test_assert(z == std::int32_t(1));
        test_assert(w == std::int32_t(2));
    }

    TEST_CASE(equal)
    {
        constexpr auto tt = math::equal( true32,  true32);
        constexpr auto tf = math::equal( true32, false32);
        constexpr auto ft = math::equal(false32,  true32);
        constexpr auto ff = math::equal(false32, false32);
        test_assert(tt == true);
        test_assert(tf == false);
        test_assert(ft == false);
        test_assert(ff == true);
    }

    TEST_CASE(not_equal)
    {
        constexpr auto tt = math::not_equal( true32,  true32);
        constexpr auto tf = math::not_equal( true32, false32);
        constexpr auto ft = math::not_equal(false32,  true32);
        constexpr auto ff = math::not_equal(false32, false32);
        test_assert(tt == false);
        test_assert(tf == true);
        test_assert(ft == true);
        test_assert(ff == false);
    }
}
