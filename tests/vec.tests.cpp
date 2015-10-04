//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/vec.hpp>
#include "tue.tests.hpp"

#include <cstdint>

namespace
{
    using namespace tue;

    TEST_CASE(is_simd_component)
    {
        test_assert(is_vec_component<bool>::value == false);
        test_assert(is_vec_component<float>::value == true);
        test_assert(is_vec_component<double>::value == true);
        test_assert(is_vec_component<std::int8_t>::value == true);
        test_assert(is_vec_component<std::int16_t>::value == true);
        test_assert(is_vec_component<std::int32_t>::value == true);
        test_assert(is_vec_component<std::int64_t>::value == true);
        test_assert(is_vec_component<std::uint8_t>::value == true);
        test_assert(is_vec_component<std::uint16_t>::value == true);
        test_assert(is_vec_component<std::uint32_t>::value == true);
        test_assert(is_vec_component<std::uint64_t>::value == true);
        test_assert(is_vec_component<bool8>::value == true);
        test_assert(is_vec_component<bool16>::value == true);
        test_assert(is_vec_component<bool32>::value == true);
        test_assert(is_vec_component<bool64>::value == true);
        test_assert((is_vec_component<simd<float, 4>>::value == true));
    }
}
