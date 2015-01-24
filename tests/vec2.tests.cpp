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

	constexpr fvec2 fv21(1.1f, 1.2f);

	constexpr dvec2 dv21(1.1, 1.2);

	constexpr dvec2 dv22(2.2, 2.4);

	constexpr ivec2 iv21(111, 222);

	constexpr uvec2 uv22(2U, 4U);

	TEST_CASE(default_constructor)
	{
		fvec2 v;
		unused(v);
	}

	TEST_CASE(component_constructor)
	{
		constexpr fvec2 v1(1.1f, 2.2f);
		test_assert(v1[0] == 1.1f);
		test_assert(v1[1] == 2.2f);

		constexpr fvec2 v2 = { 1.1f, 2.2f };
		test_assert(v2[0] == 1.1f);
		test_assert(v2[1] == 2.2f);
	}

	TEST_CASE(scalar_constructor)
	{
		constexpr fvec2 v(1.1f);
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 1.1f);
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr fvec2 v1(dv21);
		test_assert(v1[0] == float(dv21[0]));
		test_assert(v1[1] == float(dv21[1]));

		CONST_OR_CONSTEXPR auto v2 = static_cast<fvec2>(dv21);
		test_assert(v2[0] == float(dv21[0]));
		test_assert(v2[1] == float(dv21[1]));
	}

	TEST_CASE(zero)
	{
		CONST_OR_CONSTEXPR auto v = fvec2::zero();
		test_assert(v[0] == 0);
		test_assert(v[1] == 0);
	}

	TEST_CASE(x_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec2::x_axis();
		test_assert(v[0] == 1);
		test_assert(v[1] == 0);
	}

	TEST_CASE(y_axis)
	{
		CONST_OR_CONSTEXPR auto v = fvec2::y_axis();
		test_assert(v[0] == 0);
		test_assert(v[1] == 1);
	}

	TEST_CASE(implicit_conversion_operator)
	{
		CONST_OR_CONSTEXPR dvec2 v = fv21;
		test_assert(v[0] == double(fv21[0]));
		test_assert(v[1] == double(fv21[1]));
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fvec2 cev(1.1f, 2.2f);
		CONST_OR_CONSTEXPR float cev0 = cev[0];
		CONST_OR_CONSTEXPR float cev1 = cev[1];
		test_assert(cev0 == 1.1f);
		test_assert(cev1 == 2.2f);

		fvec2 v = cev;
		float& v0 = v[0];
		float& v1 = v[1];
		test_assert(static_cast<void*>(&v0) == static_cast<void*>(&v));
		test_assert(&v1 == &v0 + 1);

		const fvec2& cv = v;
		const float& cv0 = cv[0];
		const float& cv1 = cv[1];
		test_assert(&cv0 == &v0);
		test_assert(&cv1 == &v1);
	}

	TEST_CASE(x)
	{
		CONST_OR_CONSTEXPR float x = fv21.x();
		test_assert(x == fv21[0]);
	}

	TEST_CASE(set_x)
	{
		fvec2 v = fv21;
		v.set_x(2.1f);
		test_assert(v.x() == 2.1f);
	}

	TEST_CASE(y)
	{
		CONST_OR_CONSTEXPR float y = fv21.y();
		test_assert(y == fv21[1]);
	}

	TEST_CASE(set_y)
	{
		fvec2 v = fv21;
		v.set_y(2.2f);
		test_assert(v.y() == 2.2f);
	}

	TEST_CASE(pre_increment_operator)
	{
		fvec2 v = fv21;
		test_assert(&(++v) == &v);
		test_assert(v == fv21 + 1);
	}

	TEST_CASE(pre_decrement_operator)
	{
		fvec2 v = fv21;
		test_assert(&(--v) == &v);
		test_assert(v == fv21 - 1);
	}

	TEST_CASE(post_increment_operator)
	{
		fvec2 v = fv21;
		test_assert(v++ == fv21);
		test_assert(v == fv21 + 1);
	}

	TEST_CASE(post_decrement_operator)
	{
		fvec2 v = fv21;
		test_assert(v-- == fv21);
		test_assert(v == fv21 - 1);
	}

	TEST_CASE(addition_assignment_operator)
	{
		fvec2 v1 = fv21;
		test_assert(&(v1 += u2) == &v1);
		test_assert(v1 == fv21 + u2);

		fvec2 v2 = fv21;
		test_assert(&(v2 += uv22) == &v2);
		test_assert(v2 == fv21 + uv22);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		fvec2 v1 = fv21;
		test_assert(&(v1 -= u2) == &v1);
		test_assert(v1 == fv21 - u2);

		fvec2 v2 = fv21;
		test_assert(&(v2 -= uv22) == &v2);
		test_assert(v2 == fv21 - uv22);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		fvec2 v1 = fv21;
		test_assert(&(v1 *= u2) == &v1);
		test_assert(v1 == fv21 * u2);

		fvec2 v2 = fv21;
		test_assert(&(v2 *= uv22) == &v2);
		test_assert(v2 == fv21 * uv22);
	}

	TEST_CASE(division_assignment_operator)
	{
		fvec2 v1 = fv21;
		test_assert(&(v1 /= u2) == &v1);
		test_assert(v1 == fv21 / u2);

		fvec2 v2 = fv21;
		test_assert(&(v2 /= uv22) == &v2);
		test_assert(v2 == fv21 / uv22);
	}

	TEST_CASE(modulo_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 %= u2) == &v1);
		test_assert(v1 == iv21 % u2);

		ivec2 v2 = iv21;
		test_assert(&(v2 %= uv22) == &v2);
		test_assert(v2 == iv21 % uv22);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 &= u2) == &v1);
		test_assert(v1 == (iv21 & u2));

		ivec2 v2 = iv21;
		test_assert(&(v2 &= uv22) == &v2);
		test_assert(v2 == (iv21 & uv22));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 |= u2) == &v1);
		test_assert(v1 == (iv21 | u2));

		ivec2 v2 = iv21;
		test_assert(&(v2 |= uv22) == &v2);
		test_assert(v2 == (iv21 | uv22));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 ^= u2) == &v1);
		test_assert(v1 == (iv21 ^ u2));

		ivec2 v2 = iv21;
		test_assert(&(v2 ^= uv22) == &v2);
		test_assert(v2 == (iv21 ^ uv22));
	}

	TEST_CASE(bitwise_shift_left_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 <<= u2) == &v1);
		test_assert(v1 == (iv21 << u2));

		ivec2 v2 = iv21;
		test_assert(&(v2 <<= uv22) == &v2);
		test_assert(v2 == (iv21 << uv22));
	}

	TEST_CASE(bitwise_shift_right_assignment_operator)
	{
		ivec2 v1 = iv21;
		test_assert(&(v1 >>= u2) == &v1);
		test_assert(v1 == (iv21 >> u2));

		ivec2 v2 = iv21;
		test_assert(&(v2 >>= uv22) == &v2);
		test_assert(v2 == (iv21 >> uv22));
	}

	TEST_CASE(unary_plus_operator)
	{
		CONST_OR_CONSTEXPR auto v = +fv21;
		test_assert(v[0] == +fv21[0]);
		test_assert(v[1] == +fv21[1]);
	}

	TEST_CASE(unary_minus_operator)
	{
		CONST_OR_CONSTEXPR auto v = -fv21;
		test_assert(v[0] == -fv21[0]);
		test_assert(v[1] == -fv21[1]);
	}

	TEST_CASE(bitwise_not_operator)
	{
		CONST_OR_CONSTEXPR auto v = ~iv21;
		test_assert(v[0] == ~iv21[0]);
		test_assert(v[1] == ~iv21[1]);
	}

	TEST_CASE(addition_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 + dv22;
		test_assert(v1[0] == f1 + dv22[0]);
		test_assert(v1[1] == f1 + dv22[1]);

		CONST_OR_CONSTEXPR auto v2 = fv21 + d2;
		test_assert(v2[0] == fv21[0] + d2);
		test_assert(v2[1] == fv21[1] + d2);

		CONST_OR_CONSTEXPR auto v3 = fv21 + dv22;
		test_assert(v3[0] == fv21[0] + dv22[0]);
		test_assert(v3[1] == fv21[1] + dv22[1]);
	}

	TEST_CASE(subtraction_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 - dv22;
		test_assert(v1[0] == f1 - dv22[0]);
		test_assert(v1[1] == f1 - dv22[1]);

		CONST_OR_CONSTEXPR auto v2 = fv21 - d2;
		test_assert(v2[0] == fv21[0] - d2);
		test_assert(v2[1] == fv21[1] - d2);

		CONST_OR_CONSTEXPR auto v3 = fv21 - dv22;
		test_assert(v3[0] == fv21[0] - dv22[0]);
		test_assert(v3[1] == fv21[1] - dv22[1]);
	}

	TEST_CASE(multiplication_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 * dv22;
		test_assert(v1[0] == f1 * dv22[0]);
		test_assert(v1[1] == f1 * dv22[1]);

		CONST_OR_CONSTEXPR auto v2 = fv21 * d2;
		test_assert(v2[0] == fv21[0] * d2);
		test_assert(v2[1] == fv21[1] * d2);

		CONST_OR_CONSTEXPR auto v3 = fv21 * dv22;
		test_assert(v3[0] == fv21[0] * dv22[0]);
		test_assert(v3[1] == fv21[1] * dv22[1]);
	}

	TEST_CASE(division_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 / dv22;
		test_assert(v1[0] == f1 / dv22[0]);
		test_assert(v1[1] == f1 / dv22[1]);

		CONST_OR_CONSTEXPR auto v2 = fv21 / d2;
		test_assert(v2[0] == fv21[0] / d2);
		test_assert(v2[1] == fv21[1] / d2);

		CONST_OR_CONSTEXPR auto v3 = fv21 / dv22;
		test_assert(v3[0] == fv21[0] / dv22[0]);
		test_assert(v3[1] == fv21[1] / dv22[1]);
	}

	TEST_CASE(modulo_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 % uv22;
		test_assert(v1[0] == i1 % uv22[0]);
		test_assert(v1[1] == i1 % uv22[1]);

		CONST_OR_CONSTEXPR auto v2 = iv21 % u2;
		test_assert(v2[0] == iv21[0] % u2);
		test_assert(v2[1] == iv21[1] % u2);

		CONST_OR_CONSTEXPR auto v3 = iv21 % uv22;
		test_assert(v3[0] == iv21[0] % uv22[0]);
		test_assert(v3[1] == iv21[1] % uv22[1]);
	}

	TEST_CASE(bitwise_and_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 & uv22;
		test_assert(v1[0] == (i1 & uv22[0]));
		test_assert(v1[1] == (i1 & uv22[1]));

		CONST_OR_CONSTEXPR auto v2 = iv21 & u2;
		test_assert(v2[0] == (iv21[0] & u2));
		test_assert(v2[1] == (iv21[1] & u2));

		CONST_OR_CONSTEXPR auto v3 = iv21 & uv22;
		test_assert(v3[0] == (iv21[0] & uv22[0]));
		test_assert(v3[1] == (iv21[1] & uv22[1]));
	}

	TEST_CASE(bitwise_or_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 | uv22;
		test_assert(v1[0] == (i1 | uv22[0]));
		test_assert(v1[1] == (i1 | uv22[1]));

		CONST_OR_CONSTEXPR auto v2 = iv21 | u2;
		test_assert(v2[0] == (iv21[0] | u2));
		test_assert(v2[1] == (iv21[1] | u2));

		CONST_OR_CONSTEXPR auto v3 = iv21 | uv22;
		test_assert(v3[0] == (iv21[0] | uv22[0]));
		test_assert(v3[1] == (iv21[1] | uv22[1]));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 ^ uv22;
		test_assert(v1[0] == (i1 ^ uv22[0]));
		test_assert(v1[1] == (i1 ^ uv22[1]));

		CONST_OR_CONSTEXPR auto v2 = iv21 ^ u2;
		test_assert(v2[0] == (iv21[0] ^ u2));
		test_assert(v2[1] == (iv21[1] ^ u2));

		CONST_OR_CONSTEXPR auto v3 = iv21 ^ uv22;
		test_assert(v3[0] == (iv21[0] ^ uv22[0]));
		test_assert(v3[1] == (iv21[1] ^ uv22[1]));
	}

	TEST_CASE(bitwise_shift_left_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 << uv22;
		test_assert(v1[0] == (i1 << uv22[0]));
		test_assert(v1[1] == (i1 << uv22[1]));

		CONST_OR_CONSTEXPR auto v2 = iv21 << u2;
		test_assert(v2[0] == (iv21[0] << u2));
		test_assert(v2[1] == (iv21[1] << u2));

		CONST_OR_CONSTEXPR auto v3 = iv21 << uv22;
		test_assert(v3[0] == (iv21[0] << uv22[0]));
		test_assert(v3[1] == (iv21[1] << uv22[1]));
	}

	TEST_CASE(bitwise_shift_right_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 >> uv22;
		test_assert(v1[0] == (i1 >> uv22[0]));
		test_assert(v1[1] == (i1 >> uv22[1]));

		CONST_OR_CONSTEXPR auto v2 = iv21 >> u2;
		test_assert(v2[0] == (iv21[0] >> u2));
		test_assert(v2[1] == (iv21[1] >> u2));

		CONST_OR_CONSTEXPR auto v3 = iv21 >> uv22;
		test_assert(v3[0] == (iv21[0] >> uv22[0]));
		test_assert(v3[1] == (iv21[1] >> uv22[1]));
	}

	TEST_CASE(equality_operator)
	{
		constexpr fvec2 v1(1.0f, 2.0f);
		constexpr ivec2 v2(1, 2);
		constexpr ivec2 v3(0, 2);
		constexpr ivec2 v4(1, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr fvec2 v1(1.0f, 2.0f);
		constexpr ivec2 v2(1, 2);
		constexpr ivec2 v3(0, 2);
		constexpr ivec2 v4(1, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
	}
}
