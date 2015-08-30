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

    TEST_CASE(individual_components_constructor)
    {
        CONST_OR_CONSTEXPR dquat v = { 1.2, 3.4, 5.6, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dquat ceq(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto ceq0 = ceq[0];
        CONST_OR_CONSTEXPR auto ceq1 = ceq[1];
        CONST_OR_CONSTEXPR auto ceq2 = ceq[2];
        CONST_OR_CONSTEXPR auto ceq3 = ceq[3];
        test_assert(ceq0 == 1.2);
        test_assert(ceq1 == 3.4);
        test_assert(ceq2 == 5.6);
        test_assert(ceq3 == 7.8);

        const auto cq = ceq;
        const auto& cq0 = cq[0];
        const auto& cq1 = cq[1];
        const auto& cq2 = cq[2];
        const auto& cq3 = cq[3];
        test_assert(&cq0 == cq.data() + 0);
        test_assert(&cq1 == cq.data() + 1);
        test_assert(&cq2 == cq.data() + 2);
        test_assert(&cq3 == cq.data() + 3);

        auto q = ceq;
        auto& q0 = q[0];
        auto& q1 = q[1];
        auto& q2 = q[2];
        auto& q3 = q[3];
        test_assert(&q0 == q.data() + 0);
        test_assert(&q1 == q.data() + 1);
        test_assert(&q2 == q.data() + 2);
        test_assert(&q3 == q.data() + 3);
    }

    TEST_CASE(data)
    {
        const dquat dq(1.2, 3.4, 5.6, 7.8);
        test_assert(dq.data() == static_cast<const void*>(&dq));

        dquat q;
        test_assert(q.data() == static_cast<void*>(&q));
    }
}
