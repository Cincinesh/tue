//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/vec.hpp>
#include "test_case.hpp"

#include <tue/unused.hpp>

#ifdef _MSC_VER
#define CONST_OR_CONSTEXPR const
#else
#define CONST_OR_CONSTEXPR constexpr
#endif

namespace
{
	using namespace tue;

	constexpr fvec4 fv41(1.1f, 1.2f, 1.3f, 1.4f);

	constexpr dvec4 dv41(1.1, 1.2, 1.3, 1.4);

	TEST_CASE(default_constructor)
	{
		fvec4 v;
		unused(v);
	}

	TEST_CASE(component_constructor)
	{
		constexpr fvec4 v1(1.1f, 2.2f, 3.3f, 4.4f);
		test_assert(v1[0] == 1.1f);
		test_assert(v1[1] == 2.2f);
		test_assert(v1[2] == 3.3f);
		test_assert(v1[3] == 4.4f);

		constexpr fvec4 v2 = { 1.1f, 2.2f, 3.3f, 4.4f };
		test_assert(v2[0] == 1.1f);
		test_assert(v2[1] == 2.2f);
		test_assert(v2[2] == 3.3f);
		test_assert(v2[3] == 4.4f);
	}

	TEST_CASE(scalar_constructor)
	{
		constexpr fvec4 v(1.1f);
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 1.1f);
		test_assert(v[2] == 1.1f);
		test_assert(v[3] == 1.1f);
	}

	TEST_CASE(explicit_cast_constructor)
	{
		constexpr fvec4 v1(dv41);
		test_assert(v1[0] == float(dv41[0]));
		test_assert(v1[1] == float(dv41[1]));
		test_assert(v1[2] == float(dv41[2]));
		test_assert(v1[3] == float(dv41[3]));

		CONST_OR_CONSTEXPR auto v2 = static_cast<fvec4>(dv41);
		test_assert(v2[0] == float(dv41[0]));
		test_assert(v2[1] == float(dv41[1]));
		test_assert(v2[2] == float(dv41[2]));
		test_assert(v2[3] == float(dv41[3]));
	}

	TEST_CASE(implicit_cast_operator)
	{
		CONST_OR_CONSTEXPR dvec4 v = fv41;
		test_assert(v[0] == double(fv41[0]));
		test_assert(v[1] == double(fv41[1]));
		test_assert(v[2] == double(fv41[2]));
		test_assert(v[3] == double(fv41[3]));
	}

	TEST_CASE(zero)
	{
		CONST_OR_CONSTEXPR auto v = fvec4::zero();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
		test_assert(v[2] == 0);
		test_assert(v[3] == 0);
	}

	TEST_CASE(x_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec4::x_axis();
		test_assert(v[0] == 1);
		test_assert(v[1] == 0);
		test_assert(v[2] == 0);
		test_assert(v[3] == 0);
	}

	TEST_CASE(y_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec4::y_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 1);
		test_assert(v[2] == 0);
		test_assert(v[3] == 0);
	}

	TEST_CASE(z_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec4::z_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
		test_assert(v[2] == 1);
		test_assert(v[3] == 0);
	}

	TEST_CASE(w_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec4::w_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
		test_assert(v[2] == 0);
		test_assert(v[3] == 1);
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fvec4 cev(1.1f, 2.2f, 3.3f, 4.4f);
		CONST_OR_CONSTEXPR float cev0 = cev[0];
		CONST_OR_CONSTEXPR float cev1 = cev[1];
		CONST_OR_CONSTEXPR float cev2 = cev[2];
		CONST_OR_CONSTEXPR float cev3 = cev[3];
		test_assert(cev0 == 1.1f);
		test_assert(cev1 == 2.2f);
		test_assert(cev2 == 3.3f);
		test_assert(cev3 == 4.4f);

		fvec4 v = cev;
		float& v0 = v[0];
		float& v1 = v[1];
		float& v2 = v[2];
		float& v3 = v[3];
		test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
		test_assert(&v1 == &v0 + 1);
		test_assert(&v2 == &v0 + 2);
		test_assert(&v3 == &v0 + 3);

		const fvec4& cv = v;
		const float& cv0 = cv[0];
		const float& cv1 = cv[1];
		const float& cv2 = cv[2];
		const float& cv3 = cv[3];
		test_assert(&cv0 == &v0);
		test_assert(&cv1 == &v1);
		test_assert(&cv2 == &v2);
		test_assert(&cv3 == &v3);
	}

	TEST_CASE(x)
	{
		CONST_OR_CONSTEXPR float x = fv41.x();
		test_assert(x == fv41[0]);
	}

	TEST_CASE(set_x)
	{
		fvec4 v = fv41;
		v.set_x(2.1f);
		test_assert(v.x() == 2.1f);
	}

	TEST_CASE(y)
	{
		CONST_OR_CONSTEXPR float y = fv41.y();
		test_assert(y == fv41[1]);
	}

	TEST_CASE(set_y)
	{
		fvec4 v = fv41;
		v.set_y(2.2f);
		test_assert(v.y() == 2.2f);
	}

	TEST_CASE(z)
	{
		CONST_OR_CONSTEXPR float z = fv41.z();
		test_assert(z == fv41[2]);
	}

	TEST_CASE(set_z)
	{
		fvec4 v = fv41;
		v.set_z(2.3f);
		test_assert(v.z() == 2.3f);
	}

	TEST_CASE(w)
	{
		CONST_OR_CONSTEXPR float w = fv41.w();
		test_assert(w == fv41[3]);
	}

	TEST_CASE(set_w)
	{
		fvec4 v = fv41;
		v.set_w(2.4f);
		test_assert(v.w() == 2.4f);
	}
}
