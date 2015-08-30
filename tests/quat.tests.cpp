//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/quat.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(quat<short>) == sizeof(short) * 4);
        test_assert(sizeof(fquat) == sizeof(float) * 4);
        test_assert(sizeof(dquat) == sizeof(double) * 4);
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(quat<short>) == alignof(short));
        test_assert(alignof(fquat) == alignof(float));
        test_assert(alignof(dquat) == alignof(double));
    }

    TEST_CASE(component_type)
    {
        test_assert((
            std::is_same<typename quat<short>::component_type, short>::value));
        test_assert((
            std::is_same<typename fquat::component_type, float>::value));
        test_assert((
            std::is_same<typename dquat::component_type, double>::value));
    }

    TEST_CASE(component_count)
    {
        test_assert(quat<short>::component_count == 4);
        test_assert(fquat::component_count == 4);
        test_assert(dquat::component_count == 4);
    }

    TEST_CASE(default_constructor)
    {
        dquat q;
        unused(q);
    }
}
