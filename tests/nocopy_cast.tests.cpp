//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/nocopy_cast.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    struct A
    {
        mutable bool was_copied;

        A() noexcept :
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

        explicit B(const A&) noexcept
        {
        }
    };

    TEST_CASE(nocopy_cast_same_type)
    {
        const A a;
        const A& a2 = nocopy_cast<A>(a);
        test_assert(&a2 == &a);
        test_assert(!a.was_copied);
    }

    TEST_CASE(nocopy_cast_different_type)
    {
        const A a;
        const B b = nocopy_cast<B>(a);
        test_assert(!a.was_copied);
        unused(b);
    }
}
