//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/quat.hpp>
#include "tue.tests.hpp"

#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(size)
    {
        test_assert(sizeof(quat<short>) == sizeof(short[4]));
        test_assert(sizeof(fquat) == sizeof(float[4]));
        test_assert(sizeof(dquat) == sizeof(double[4]));
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(quat<short>) == alignof(short[4]));
        test_assert(alignof(fquat) == alignof(float[4]));
        test_assert(alignof(dquat) <= alignof(double[4]));
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
        constexpr auto qs = quat<short>::component_count;
        constexpr auto fq = fquat::component_count;
        constexpr auto dq = dquat::component_count;
        test_assert(qs == 4);
        test_assert(fq == 4);
        test_assert(dq == 4);
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

    TEST_CASE(vec4_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR dquat q(v);
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

    TEST_CASE(x_y_z_w)
    {
        CONST_OR_CONSTEXPR dquat q(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto x = q.x();
        CONST_OR_CONSTEXPR auto y = q.y();
        CONST_OR_CONSTEXPR auto z = q.z();
        CONST_OR_CONSTEXPR auto w = q.w();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
        test_assert(z == 5.6);
        test_assert(w == 7.8);
    }

    TEST_CASE(xyz)
    {
        CONST_OR_CONSTEXPR dquat q(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyz = q.xyz();
        test_assert(xyz == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(xyzw)
    {
        CONST_OR_CONSTEXPR dquat q(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyzw = q.xyzw();
        test_assert(xyzw == dvec4(1.2, 3.4, 5.6, 7.8));
    }

    TEST_CASE(set_x_y_z_w)
    {
        dquat q(1.2, 3.4, 5.6, 7.8);
        q.set_x(9.10);
        q.set_y(11.12);
        q.set_z(13.14);
        q.set_w(15.16);
        test_assert(q[0] == 9.10);
        test_assert(q[1] == 11.12);
        test_assert(q[2] == 13.14);
        test_assert(q[3] == 15.16);
    }

    TEST_CASE(set_xyz)
    {
        dquat q(1.2, 3.4, 5.6, 7.8);

        q.set_xyz(9.10, 11.12, 13.14);
        test_assert(q[0] == 9.10);
        test_assert(q[1] == 11.12);
        test_assert(q[2] == 13.14);
        test_assert(q[3] == 7.8);

        q.set_xyz(dvec3(15.16, 17.18, 19.20));
        test_assert(q[0] == 15.16);
        test_assert(q[1] == 17.18);
        test_assert(q[2] == 19.20);
        test_assert(q[3] == 7.8);
    }

    TEST_CASE(set_xyzw)
    {
        dquat q(1.2, 3.4, 5.6, 7.8);

        q.set_xyzw(9.10, 11.12, 13.14, 15.16);
        test_assert(q[0] == 9.10);
        test_assert(q[1] == 11.12);
        test_assert(q[2] == 13.14);
        test_assert(q[3] == 15.16);

        q.set_xyzw(dvec3(17.18, 19.20, 21.22), 23.24);
        test_assert(q[0] == 17.18);
        test_assert(q[1] == 19.20);
        test_assert(q[2] == 21.22);
        test_assert(q[3] == 23.24);

        q.set_xyzw(dvec4(25.26, 27.28, 29.30, 31.32));
        test_assert(q[0] == 25.26);
        test_assert(q[1] == 27.28);
        test_assert(q[2] == 29.30);
        test_assert(q[3] == 31.32);
    }

    TEST_CASE(v)
    {
        CONST_OR_CONSTEXPR dquat q(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto v = q.v();
        test_assert(v == dvec3(1.2, 3.4, 5.6));
    }

    TEST_CASE(s)
    {
        CONST_OR_CONSTEXPR dquat q(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto s = q.s();
        test_assert(s == 7.8);
    }

    TEST_CASE(set_v)
    {
        dquat q(1.2, 3.4, 5.6, 7.8);

        q.set_v(9.10, 11.12, 13.14);
        test_assert(q[0] == 9.10);
        test_assert(q[1] == 11.12);
        test_assert(q[2] == 13.14);
        test_assert(q[3] == 7.8);

        q.set_v(dvec3(15.16, 17.18, 19.20));
        test_assert(q[0] == 15.16);
        test_assert(q[1] == 17.18);
        test_assert(q[2] == 19.20);
        test_assert(q[3] == 7.8);
    }

    TEST_CASE(set_s)
    {
        dquat q(1.2, 3.4, 5.6, 7.8);
        q.set_s(9.10);
        test_assert(q[0] == 1.2);
        test_assert(q[1] == 3.4);
        test_assert(q[2] == 5.6);
        test_assert(q[3] == 9.10);
    }

    TEST_CASE(multiplication_assignment_operator)
    {
        const dquat q1(1.2, 3.4, 5.6, 7.8);
        const fquat q2(9.10f, 11.12f, 13.14f, 15.16f);

        auto q3 = q1;
        test_assert(&(q3 *= q2) == &q3);
        test_assert(q3 == q1 * q2);
    }

    TEST_CASE(multiplication_operator)
    {
        CONST_OR_CONSTEXPR dquat q1(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR fquat q2(9.10f, 11.12f, 13.14f, 15.16f);
        CONST_OR_CONSTEXPR auto q3 = q1 * q2;

        test_assert(
            q3.v() ==
            q2.s()*q1.v() + q1.s()*q2.v() + math::cross(q2.v(), q1.v()));

        test_assert(nearly_equal(
            q3.s(),
            q2.s()*q1.s() - math::dot(q2.v(), q1.v())));
    }

    TEST_CASE(vec_multiplication_operator)
    {
        CONST_OR_CONSTEXPR dvec3 v1(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR fquat q(7.8f, 9.10f, 11.12f, 13.14f);
        CONST_OR_CONSTEXPR auto v2 = v1 * q;
        test_assert(v2 == (q * dquat(v1, 0.0) * dquat(-q.v(), q.s())).v());
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

    TEST_CASE(normalize)
    {
        const auto q = math::normalize(dquat(1.2, 3.4, 5.6, 7.8));
        test_assert(q == dquat(math::normalize(q.xyzw())));
    }

    TEST_CASE(conjugate)
    {
        CONST_OR_CONSTEXPR auto q = math::conjugate(dquat(1.2, 3.4, 5.6, 7.8));
        test_assert(q == dquat(-1.2, -3.4, -5.6, 7.8));
    }
}
