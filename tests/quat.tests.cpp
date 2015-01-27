//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/quat.hpp>
#include "test_case.hpp"

#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
	using namespace tue;

	constexpr fquat fq(1.1f, 1.2f, 1.3f, 1.4f);

	constexpr dquat dq(1.1, 1.2, 1.3, 1.4);

	TEST_CASE(default_constructor)
	{
		fquat q;
		unused(q);
	}

	TEST_CASE(scalar_component_constructor)
	{
		constexpr fquat q(1.1f, 2.2f, 3.3f, 4.4f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 2.2f);
		test_assert(q[2] == 3.3f);
		test_assert(q[3] == 4.4f);
	}

	TEST_CASE(vector_component_constructor)
	{
		constexpr fquat q(fvec3(1.1f, 2.2f, 3.3f), 4.4f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 2.2f);
		test_assert(q[2] == 3.3f);
		test_assert(q[3] == 4.4f);
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr fquat q(dq);
		test_assert(q[0] == static_cast<float>(dq[0]));
		test_assert(q[1] == static_cast<float>(dq[1]));
		test_assert(q[2] == static_cast<float>(dq[2]));
		test_assert(q[3] == static_cast<float>(dq[3]));
	}

	TEST_CASE(implicit_conversion_constructor)
	{
		CONST_OR_CONSTEXPR dquat q = fq;
		test_assert(q[0] == static_cast<double>(fq[0]));
		test_assert(q[1] == static_cast<double>(fq[1]));
		test_assert(q[2] == static_cast<double>(fq[2]));
		test_assert(q[3] == static_cast<double>(fq[3]));
	}

	TEST_CASE(identity)
	{
		CONST_OR_CONSTEXPR auto q = fquat::identity();
		test_assert(q[0] == 0);
		test_assert(q[1] == 0);
		test_assert(q[2] == 0);
		test_assert(q[3] == 1);
	}

	TEST_CASE(x)
	{
		CONST_OR_CONSTEXPR float x = fq.x();
		test_assert(x == fq[0]);
	}

	TEST_CASE(set_x)
	{
		fquat q(1.1f, 1.2f, 1.3f, 1.4f);
		q.set_x(2.1f);
		test_assert(q[0] == 2.1f);
		test_assert(q[1] == 1.2f);
		test_assert(q[2] == 1.3f);
		test_assert(q[3] == 1.4f);
	}

	TEST_CASE(y)
	{
		CONST_OR_CONSTEXPR float y = fq.y();
		test_assert(y == fq[1]);
	}

	TEST_CASE(set_y)
	{
		fquat q(1.1f, 1.2f, 1.3f, 1.4f);
		q.set_y(2.2f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 2.2f);
		test_assert(q[2] == 1.3f);
		test_assert(q[3] == 1.4f);
	}

	TEST_CASE(z)
	{
		CONST_OR_CONSTEXPR float z = fq.z();
		test_assert(z == fq[2]);
	}

	TEST_CASE(set_z)
	{
		fquat q(1.1f, 1.2f, 1.3f, 1.4f);
		q.set_z(2.3f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 1.2f);
		test_assert(q[2] == 2.3f);
		test_assert(q[3] == 1.4f);
	}

	TEST_CASE(w)
	{
		CONST_OR_CONSTEXPR float w = fq.w();
		test_assert(w == fq[3]);
	}

	TEST_CASE(set_w)
	{
		fquat q(1.1f, 1.2f, 1.3f, 1.4f);
		q.set_w(2.4f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 1.2f);
		test_assert(q[2] == 1.3f);
		test_assert(q[3] == 2.4f);
	}

	TEST_CASE(v)
	{
		CONST_OR_CONSTEXPR fvec3 v = fq.v();
		test_assert(v == fvec3(fq[0], fq[1], fq[2]));
	}

	TEST_CASE(set_v)
	{
		fquat q1(1.1f, 1.2f, 1.3f, 1.4f);
		q1.set_v(2.1f, 2.2f, 2.3f);
		test_assert(q1[0] == 2.1f);
		test_assert(q1[1] == 2.2f);
		test_assert(q1[2] == 2.3f);
		test_assert(q1[3] == 1.4f);

		fquat q2(1.1f, 1.2f, 1.3f, 1.4f);
		q2.set_v(fvec3(2.1f, 2.2f, 2.3f));
		test_assert(q2[0] == 2.1f);
		test_assert(q2[1] == 2.2f);
		test_assert(q2[2] == 2.3f);
		test_assert(q2[3] == 1.4f);
	}

	TEST_CASE(s)
	{
		CONST_OR_CONSTEXPR float s = fq.s();
		test_assert(s == fq[3]);
	}

	TEST_CASE(set_s)
	{
		fquat q(1.1f, 1.2f, 1.3f, 1.4f);
		q.set_s(2.4f);
		test_assert(q[0] == 1.1f);
		test_assert(q[1] == 1.2f);
		test_assert(q[2] == 1.3f);
		test_assert(q[3] == 2.4f);
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fquat ceq(1.1f, 2.2f, 3.3f, 4.4f);
		CONST_OR_CONSTEXPR float ceq0 = ceq[0];
		CONST_OR_CONSTEXPR float ceq1 = ceq[1];
		CONST_OR_CONSTEXPR float ceq2 = ceq[2];
		CONST_OR_CONSTEXPR float ceq3 = ceq[3];
		test_assert(ceq0 == 1.1f);
		test_assert(ceq1 == 2.2f);
		test_assert(ceq2 == 3.3f);
		test_assert(ceq3 == 4.4f);

		fquat q = ceq;
		float& q0 = q[0];
		float& q1 = q[1];
		float& q2 = q[2];
		float& q3 = q[3];
		test_assert(static_cast<void*>(&q0) == static_cast<void*>(&q));
		test_assert(&q1 == &q0 + 1);
		test_assert(&q2 == &q0 + 2);
		test_assert(&q3 == &q0 + 3);

		const fquat& cq = q;
		const float& cq0 = cq[0];
		const float& cq1 = cq[1];
		const float& cq2 = cq[2];
		const float& cq3 = cq[3];
		test_assert(&cq0 == &q0);
		test_assert(&cq1 == &q1);
		test_assert(&cq2 == &q2);
		test_assert(&cq3 == &q3);
	}
}
