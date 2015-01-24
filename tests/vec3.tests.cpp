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

	constexpr auto f1 = 1.1f;

	constexpr auto d2 = 2.2;

	constexpr auto i1 = 111;

	constexpr auto u2 = 2U;

	constexpr fvec3 fv31(1.1f, 1.2f, 1.3f);

	constexpr dvec3 dv31(1.1, 1.2, 1.3);

	constexpr dvec3 dv32(2.2, 2.4, 2.6);

	constexpr ivec3 iv31(111, 222, 333);

	constexpr uvec3 uv32(2U, 4U, 6U);

	TEST_CASE(default_constructor)
	{
		fvec3 v;
		unused(v);
	}

	TEST_CASE(component_constructor)
	{
		constexpr fvec3 v1(1.1f, 2.2f, 3.3f);
		test_assert(v1[0] == 1.1f);
		test_assert(v1[1] == 2.2f);
		test_assert(v1[2] == 3.3f);

		constexpr fvec3 v2 = { 1.1f, 2.2f, 3.3f };
		test_assert(v2[0] == 1.1f);
		test_assert(v2[1] == 2.2f);
		test_assert(v2[2] == 3.3f);
	}

	TEST_CASE(scalar_constructor)
	{
		constexpr fvec3 v(1.1f);
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 1.1f);
		test_assert(v[2] == 1.1f);
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr fvec3 v1(dv31);
		test_assert(v1[0] == float(dv31[0]));
		test_assert(v1[1] == float(dv31[1]));
		test_assert(v1[2] == float(dv31[2]));

		CONST_OR_CONSTEXPR auto v2 = static_cast<fvec3>(dv31);
		test_assert(v2[0] == float(dv31[0]));
		test_assert(v2[1] == float(dv31[1]));
		test_assert(v2[2] == float(dv31[2]));
	}

	TEST_CASE(zero)
	{
		CONST_OR_CONSTEXPR auto v = fvec3::zero();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
		test_assert(v[2] == 0);
	}

	TEST_CASE(x_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec3::x_axis();
		test_assert(v[0] == 1);
		test_assert(v[1] == 0);
		test_assert(v[2] == 0);
	}

	TEST_CASE(y_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec3::y_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 1);
		test_assert(v[2] == 0);
	}

	TEST_CASE(z_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec3::z_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
		test_assert(v[2] == 1);
	}

	TEST_CASE(implicit_conversion_operator)
	{
		CONST_OR_CONSTEXPR dvec3 v = fv31;
		test_assert(v[0] == double(fv31[0]));
		test_assert(v[1] == double(fv31[1]));
		test_assert(v[2] == double(fv31[2]));
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fvec3 cev(1.1f, 2.2f, 3.3f);
		CONST_OR_CONSTEXPR float cev0 = cev[0];
		CONST_OR_CONSTEXPR float cev1 = cev[1];
		CONST_OR_CONSTEXPR float cev2 = cev[2];
		test_assert(cev0 == 1.1f);
		test_assert(cev1 == 2.2f);
		test_assert(cev2 == 3.3f);

		fvec3 v = cev;
		float& v0 = v[0];
		float& v1 = v[1];
		float& v2 = v[2];
		test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
		test_assert(&v1 == &v0 + 1);
		test_assert(&v2 == &v0 + 2);

		const fvec3& cv = v;
		const float& cv0 = cv[0];
		const float& cv1 = cv[1];
		const float& cv2 = cv[2];
		test_assert(&cv0 == &v0);
		test_assert(&cv1 == &v1);
		test_assert(&cv2 == &v2);
	}

	TEST_CASE(x)
	{
		CONST_OR_CONSTEXPR float x = fv31.x();
		test_assert(x == fv31[0]);
	}

	TEST_CASE(set_x)
	{
		fvec3 v = fv31;
		v.set_x(2.1f);
		test_assert(v.x() == 2.1f);
	}

	TEST_CASE(y)
	{
		CONST_OR_CONSTEXPR float y = fv31.y();
		test_assert(y == fv31[1]);
	}

	TEST_CASE(set_y)
	{
		fvec3 v = fv31;
		v.set_y(2.2f);
		test_assert(v.y() == 2.2f);
	}

	TEST_CASE(z)
	{
		CONST_OR_CONSTEXPR float z = fv31.z();
		test_assert(z == fv31[2]);
	}

	TEST_CASE(set_z)
	{
		fvec3 v = fv31;
		v.set_z(2.3f);
		test_assert(v.z() == 2.3f);
	}

	TEST_CASE(pre_increment_operator)
	{
		fvec3 v = fv31;
		test_assert(&(++v) == &v);
		test_assert(v == fv31 + 1);
	}

	TEST_CASE(pre_decrement_operator)
	{
		fvec3 v = fv31;
		test_assert(&(--v) == &v);
		test_assert(v == fv31 - 1);
	}

	TEST_CASE(post_increment_operator)
	{
		fvec3 v = fv31;
		test_assert(v++ == fv31);
		test_assert(v == fv31 + 1);
	}

	TEST_CASE(post_decrement_operator)
	{
		fvec3 v = fv31;
		test_assert(v-- == fv31);
		test_assert(v == fv31 - 1);
	}

	TEST_CASE(addition_assignment_operator)
	{
		fvec3 v1 = fv31;
		test_assert(&(v1 += u2) == &v1);
		test_assert(v1 == fv31 + u2);

		fvec3 v2 = fv31;
		test_assert(&(v2 += uv32) == &v2);
		test_assert(v2 == fv31 + uv32);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		fvec3 v1 = fv31;
		test_assert(&(v1 -= u2) == &v1);
		test_assert(v1 == fv31 - u2);

		fvec3 v2 = fv31;
		test_assert(&(v2 -= uv32) == &v2);
		test_assert(v2 == fv31 - uv32);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		fvec3 v1 = fv31;
		test_assert(&(v1 *= u2) == &v1);
		test_assert(v1 == fv31 * u2);

		fvec3 v2 = fv31;
		test_assert(&(v2 *= uv32) == &v2);
		test_assert(v2 == fv31 * uv32);
	}

	TEST_CASE(division_assignment_operator)
	{
		fvec3 v1 = fv31;
		test_assert(&(v1 /= u2) == &v1);
		test_assert(v1 == fv31 / u2);

		fvec3 v2 = fv31;
		test_assert(&(v2 /= uv32) == &v2);
		test_assert(v2 == fv31 / uv32);
	}

	TEST_CASE(modulo_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 %= u2) == &v1);
		test_assert(v1 == iv31 % u2);

		ivec3 v2 = iv31;
		test_assert(&(v2 %= uv32) == &v2);
		test_assert(v2 == iv31 % uv32);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 &= u2) == &v1);
		test_assert(v1 == (iv31 & u2));

		ivec3 v2 = iv31;
		test_assert(&(v2 &= uv32) == &v2);
		test_assert(v2 == (iv31 & uv32));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 |= u2) == &v1);
		test_assert(v1 == (iv31 | u2));

		ivec3 v2 = iv31;
		test_assert(&(v2 |= uv32) == &v2);
		test_assert(v2 == (iv31 | uv32));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 ^= u2) == &v1);
		test_assert(v1 == (iv31 ^ u2));

		ivec3 v2 = iv31;
		test_assert(&(v2 ^= uv32) == &v2);
		test_assert(v2 == (iv31 ^ uv32));
	}

	TEST_CASE(bitwise_shift_left_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 <<= u2) == &v1);
		test_assert(v1 == (iv31 << u2));

		ivec3 v2 = iv31;
		test_assert(&(v2 <<= uv32) == &v2);
		test_assert(v2 == (iv31 << uv32));
	}

	TEST_CASE(bitwise_shift_right_assignment_operator)
	{
		ivec3 v1 = iv31;
		test_assert(&(v1 >>= u2) == &v1);
		test_assert(v1 == (iv31 >> u2));

		ivec3 v2 = iv31;
		test_assert(&(v2 >>= uv32) == &v2);
		test_assert(v2 == (iv31 >> uv32));
	}

	TEST_CASE(unary_plus_operator)
	{
		CONST_OR_CONSTEXPR auto v = +fv31;
		test_assert(v[0] == +fv31[0]);
		test_assert(v[1] == +fv31[1]);
		test_assert(v[2] == +fv31[2]);
	}

	TEST_CASE(unary_minus_operator)
	{
		CONST_OR_CONSTEXPR auto v = -fv31;
		test_assert(v[0] == -fv31[0]);
		test_assert(v[1] == -fv31[1]);
		test_assert(v[2] == -fv31[2]);
	}

	TEST_CASE(bitwise_not_operator)
	{
		CONST_OR_CONSTEXPR auto v = ~iv31;
		test_assert(v[0] == ~iv31[0]);
		test_assert(v[1] == ~iv31[1]);
		test_assert(v[2] == ~iv31[2]);
	}

	TEST_CASE(addition_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 + dv32;
		test_assert(v1[0] == f1 + dv32[0]);
		test_assert(v1[1] == f1 + dv32[1]);
		test_assert(v1[2] == f1 + dv32[2]);

		CONST_OR_CONSTEXPR auto v2 = fv31 + d2;
		test_assert(v2[0] == fv31[0] + d2);
		test_assert(v2[1] == fv31[1] + d2);
		test_assert(v2[2] == fv31[2] + d2);

		CONST_OR_CONSTEXPR auto v3 = fv31 + dv32;
		test_assert(v3[0] == fv31[0] + dv32[0]);
		test_assert(v3[1] == fv31[1] + dv32[1]);
		test_assert(v3[2] == fv31[2] + dv32[2]);
	}

	TEST_CASE(subtraction_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 - dv32;
		test_assert(v1[0] == f1 - dv32[0]);
		test_assert(v1[1] == f1 - dv32[1]);
		test_assert(v1[2] == f1 - dv32[2]);

		CONST_OR_CONSTEXPR auto v2 = fv31 - d2;
		test_assert(v2[0] == fv31[0] - d2);
		test_assert(v2[1] == fv31[1] - d2);
		test_assert(v2[2] == fv31[2] - d2);

		CONST_OR_CONSTEXPR auto v3 = fv31 - dv32;
		test_assert(v3[0] == fv31[0] - dv32[0]);
		test_assert(v3[1] == fv31[1] - dv32[1]);
		test_assert(v3[2] == fv31[2] - dv32[2]);
	}

	TEST_CASE(multiplication_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 * dv32;
		test_assert(v1[0] == f1 * dv32[0]);
		test_assert(v1[1] == f1 * dv32[1]);
		test_assert(v1[2] == f1 * dv32[2]);

		CONST_OR_CONSTEXPR auto v2 = fv31 * d2;
		test_assert(v2[0] == fv31[0] * d2);
		test_assert(v2[1] == fv31[1] * d2);
		test_assert(v2[2] == fv31[2] * d2);

		CONST_OR_CONSTEXPR auto v3 = fv31 * dv32;
		test_assert(v3[0] == fv31[0] * dv32[0]);
		test_assert(v3[1] == fv31[1] * dv32[1]);
		test_assert(v3[2] == fv31[2] * dv32[2]);
	}

	TEST_CASE(division_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 / dv32;
		test_assert(v1[0] == f1 / dv32[0]);
		test_assert(v1[1] == f1 / dv32[1]);
		test_assert(v1[2] == f1 / dv32[2]);

		CONST_OR_CONSTEXPR auto v2 = fv31 / d2;
		test_assert(v2[0] == fv31[0] / d2);
		test_assert(v2[1] == fv31[1] / d2);
		test_assert(v2[2] == fv31[2] / d2);

		CONST_OR_CONSTEXPR auto v3 = fv31 / dv32;
		test_assert(v3[0] == fv31[0] / dv32[0]);
		test_assert(v3[1] == fv31[1] / dv32[1]);
		test_assert(v3[2] == fv31[2] / dv32[2]);
	}

	TEST_CASE(modulo_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 % uv32;
		test_assert(v1[0] == i1 % uv32[0]);
		test_assert(v1[1] == i1 % uv32[1]);
		test_assert(v1[2] == i1 % uv32[2]);

		CONST_OR_CONSTEXPR auto v2 = iv31 % u2;
		test_assert(v2[0] == iv31[0] % u2);
		test_assert(v2[1] == iv31[1] % u2);
		test_assert(v2[2] == iv31[2] % u2);

		CONST_OR_CONSTEXPR auto v3 = iv31 % uv32;
		test_assert(v3[0] == iv31[0] % uv32[0]);
		test_assert(v3[1] == iv31[1] % uv32[1]);
		test_assert(v3[2] == iv31[2] % uv32[2]);
	}

	TEST_CASE(bitwise_and_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 & uv32;
		test_assert(v1[0] == (i1 & uv32[0]));
		test_assert(v1[1] == (i1 & uv32[1]));
		test_assert(v1[2] == (i1 & uv32[2]));

		CONST_OR_CONSTEXPR auto v2 = iv31 & u2;
		test_assert(v2[0] == (iv31[0] & u2));
		test_assert(v2[1] == (iv31[1] & u2));
		test_assert(v2[2] == (iv31[2] & u2));

		CONST_OR_CONSTEXPR auto v3 = iv31 & uv32;
		test_assert(v3[0] == (iv31[0] & uv32[0]));
		test_assert(v3[1] == (iv31[1] & uv32[1]));
		test_assert(v3[2] == (iv31[2] & uv32[2]));
	}

	TEST_CASE(bitwise_or_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 | uv32;
		test_assert(v1[0] == (i1 | uv32[0]));
		test_assert(v1[1] == (i1 | uv32[1]));
		test_assert(v1[2] == (i1 | uv32[2]));

		CONST_OR_CONSTEXPR auto v2 = iv31 | u2;
		test_assert(v2[0] == (iv31[0] | u2));
		test_assert(v2[1] == (iv31[1] | u2));
		test_assert(v2[2] == (iv31[2] | u2));

		CONST_OR_CONSTEXPR auto v3 = iv31 | uv32;
		test_assert(v3[0] == (iv31[0] | uv32[0]));
		test_assert(v3[1] == (iv31[1] | uv32[1]));
		test_assert(v3[2] == (iv31[2] | uv32[2]));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 ^ uv32;
		test_assert(v1[0] == (i1 ^ uv32[0]));
		test_assert(v1[1] == (i1 ^ uv32[1]));
		test_assert(v1[2] == (i1 ^ uv32[2]));

		CONST_OR_CONSTEXPR auto v2 = iv31 ^ u2;
		test_assert(v2[0] == (iv31[0] ^ u2));
		test_assert(v2[1] == (iv31[1] ^ u2));
		test_assert(v2[2] == (iv31[2] ^ u2));

		CONST_OR_CONSTEXPR auto v3 = iv31 ^ uv32;
		test_assert(v3[0] == (iv31[0] ^ uv32[0]));
		test_assert(v3[1] == (iv31[1] ^ uv32[1]));
		test_assert(v3[2] == (iv31[2] ^ uv32[2]));
	}

	TEST_CASE(bitwise_shift_left_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 << uv32;
		test_assert(v1[0] == (i1 << uv32[0]));
		test_assert(v1[1] == (i1 << uv32[1]));
		test_assert(v1[2] == (i1 << uv32[2]));

		CONST_OR_CONSTEXPR auto v2 = iv31 << u2;
		test_assert(v2[0] == (iv31[0] << u2));
		test_assert(v2[1] == (iv31[1] << u2));
		test_assert(v2[2] == (iv31[2] << u2));

		CONST_OR_CONSTEXPR auto v3 = iv31 << uv32;
		test_assert(v3[0] == (iv31[0] << uv32[0]));
		test_assert(v3[1] == (iv31[1] << uv32[1]));
		test_assert(v3[2] == (iv31[2] << uv32[2]));
	}

	TEST_CASE(bitwise_shift_right_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 >> uv32;
		test_assert(v1[0] == (i1 >> uv32[0]));
		test_assert(v1[1] == (i1 >> uv32[1]));
		test_assert(v1[2] == (i1 >> uv32[2]));

		CONST_OR_CONSTEXPR auto v2 = iv31 >> u2;
		test_assert(v2[0] == (iv31[0] >> u2));
		test_assert(v2[1] == (iv31[1] >> u2));
		test_assert(v2[2] == (iv31[2] >> u2));

		CONST_OR_CONSTEXPR auto v3 = iv31 >> uv32;
		test_assert(v3[0] == (iv31[0] >> uv32[0]));
		test_assert(v3[1] == (iv31[1] >> uv32[1]));
		test_assert(v3[2] == (iv31[2] >> uv32[2]));
	}

	TEST_CASE(equality_operator)
	{
		constexpr fvec3 v1(1.0f, 2.0f, 3.0f);
		constexpr ivec3 v2(1, 2, 3);
		constexpr ivec3 v3(0, 2, 3);
		constexpr ivec3 v4(1, 0, 3);
		constexpr ivec3 v5(1, 2, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
		CONST_OR_CONSTEXPR bool result4 = (v1 == v5);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
		test_assert(result4 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr fvec3 v1(1.0f, 2.0f, 3.0f);
		constexpr ivec3 v2(1, 2, 3);
		constexpr ivec3 v3(0, 2, 3);
		constexpr ivec3 v4(1, 0, 3);
		constexpr ivec3 v5(1, 2, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
		CONST_OR_CONSTEXPR bool result4 = (v1 != v5);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
		test_assert(result4 == true);
	}
}
