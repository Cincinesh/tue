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
        CONST_OR_CONSTEXPR dquat q = { 1.2, 3.4, 5.6, 7.8 };
        test_assert(q[0] == 1.2);
        test_assert(q[1] == 3.4);
        test_assert(q[2] == 5.6);
        test_assert(q[3] == 7.8);
    }

    TEST_CASE(extend_vec3_constructor)
    {
        CONST_OR_CONSTEXPR dquat q = { { 1.2, 3.4, 5.6 }, 7.8 };
        test_assert(q[0] == 1.2);
        test_assert(q[1] == 3.4);
        test_assert(q[2] == 5.6);
        test_assert(q[3] == 7.8);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dquat dq(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR fquat fq(dq);
        test_assert(fq[0] == 1.2f);
        test_assert(fq[1] == 3.4f);
        test_assert(fq[2] == 5.6f);
        test_assert(fq[3] == 7.8f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fquat fq(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat dq = fq;
        test_assert(dq[0] == 1.2f);
        test_assert(dq[1] == 3.4f);
        test_assert(dq[2] == 5.6f);
        test_assert(dq[3] == 7.8f);
    }

    TEST_CASE(identity)
    {
        CONST_OR_CONSTEXPR auto q = dquat::identity();
        test_assert(q == dquat(0.0, 0.0, 0.0, 1.0));
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

    TEST_CASE(equality_operator)
    {
        CONST_OR_CONSTEXPR fquat q1(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q2(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q3(1.2f, 3.4f, 5.6f, 0.0f);
        CONST_OR_CONSTEXPR dquat q4(1.2f, 3.4f, 0.0f, 7.8f);
        CONST_OR_CONSTEXPR dquat q5(1.2f, 0.0f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q6(0.0f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR auto result1 = (q1 == q2);
        CONST_OR_CONSTEXPR auto result2 = (q1 == q3);
        CONST_OR_CONSTEXPR auto result3 = (q1 == q4);
        CONST_OR_CONSTEXPR auto result4 = (q1 == q5);
        CONST_OR_CONSTEXPR auto result5 = (q1 == q6);
        test_assert(result1 == true);
        test_assert(result2 == false);
        test_assert(result3 == false);
        test_assert(result4 == false);
        test_assert(result5 == false);
    }

    TEST_CASE(inequality_operator)
    {
        CONST_OR_CONSTEXPR fquat q1(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q2(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q3(1.2f, 3.4f, 5.6f, 0.0f);
        CONST_OR_CONSTEXPR dquat q4(1.2f, 3.4f, 0.0f, 7.8f);
        CONST_OR_CONSTEXPR dquat q5(1.2f, 0.0f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dquat q6(0.0f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR auto result1 = (q1 != q2);
        CONST_OR_CONSTEXPR auto result2 = (q1 != q3);
        CONST_OR_CONSTEXPR auto result3 = (q1 != q4);
        CONST_OR_CONSTEXPR auto result4 = (q1 != q5);
        CONST_OR_CONSTEXPR auto result5 = (q1 != q6);
        test_assert(result1 == false);
        test_assert(result2 == true);
        test_assert(result3 == true);
        test_assert(result4 == true);
        test_assert(result5 == true);
    }
}
