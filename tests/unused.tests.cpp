//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/unused.hpp>
#include "tue.tests.hpp"

#include <utility>

namespace
{
    using namespace tue;

    struct test_struct
    {
        mutable bool was_copied;

        test_struct() noexcept :
            was_copied(false)
        {
        }

        test_struct(const test_struct& other) noexcept :
            was_copied(false)
        {
            other.was_copied = true;
        }

        test_struct(test_struct&& other) noexcept :
            was_copied(false)
        {
            other.was_copied = true;
        }
    };

    TEST_CASE(unused)
    {
        test_struct x;
        test_struct y;
        const test_struct z;
        tue::unused(x, std::move(y), z);
        test_assert(x.was_copied == false);
        test_assert(y.was_copied == false);
        test_assert(z.was_copied == false);
    }
}
