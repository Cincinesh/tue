//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/nocopy_cast.hpp>
#include "tue.tests.hpp"

#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    struct A
    {
        mutable bool was_copied;

        constexpr A() noexcept :
            was_copied(false)
        {
        }

        A(const A& other) noexcept :
            was_copied(false)
        {
            other.was_copied = true;
        }
    };

    struct B
    {
        B() = delete;

        constexpr explicit B(const A&) noexcept
        {
        }
    };

    TEST_CASE(nocopy_cast_same_type)
    {
        const A a1;
        const A& a2 = nocopy_cast<A>(a1);
        test_assert(&a2 == &a1);
        test_assert(!a1.was_copied);

        CONST_OR_CONSTEXPR A a3;
        CONST_OR_CONSTEXPR B b1(a3);
        CONST_OR_CONSTEXPR B b2 = nocopy_cast<B>(b1);
        unused(b2);
    }

    TEST_CASE(nocopy_cast_different_type)
    {
        CONST_OR_CONSTEXPR A a;
        CONST_OR_CONSTEXPR B b = nocopy_cast<B>(a);
        test_assert(!a.was_copied);
        unused(b);
    }
}
