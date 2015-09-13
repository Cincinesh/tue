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

    TEST_CASE(sized_bool_type)
    {
        test_assert((std::is_same<
            typename sized_bool<1>::type, bool8>::value));
        test_assert((std::is_same<
            typename sized_bool<2>::type, bool16>::value));
        test_assert((std::is_same<
            typename sized_bool<4>::type, bool32>::value));
        test_assert((std::is_same<
            typename sized_bool<8>::type, bool64>::value));
    }

    TEST_CASE(sized_bool_true_value)
    {
        CONST_OR_CONSTEXPR auto b1 = sized_bool<1>::true_value;
        CONST_OR_CONSTEXPR auto b2 = sized_bool<2>::true_value;
        CONST_OR_CONSTEXPR auto b4 = sized_bool<4>::true_value;
        CONST_OR_CONSTEXPR auto b8 = sized_bool<8>::true_value;
        test_assert(b1 == true8);
        test_assert(b2 == true16);
        test_assert(b4 == true32);
        test_assert(b8 == true64);
    }

    TEST_CASE(sized_bool_false_value)
    {
        CONST_OR_CONSTEXPR auto b1 = sized_bool<1>::false_value;
        CONST_OR_CONSTEXPR auto b2 = sized_bool<2>::false_value;
        CONST_OR_CONSTEXPR auto b4 = sized_bool<4>::false_value;
        CONST_OR_CONSTEXPR auto b8 = sized_bool<8>::false_value;
        test_assert(b1 == false8);
        test_assert(b2 == false16);
        test_assert(b4 == false32);
        test_assert(b8 == false64);
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
}
