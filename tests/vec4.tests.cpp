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

	constexpr fvec4 fv41(1.1f, 1.2f, 1.3f, 1.4f);

	constexpr dvec4 dv41(1.1, 1.2, 1.3, 1.4);

	constexpr dvec4 dv42(2.2, 2.4, 2.6, 2.8);

	constexpr ivec4 iv41(111, 222, 333, 444);

	constexpr uvec4 uv42(2U, 4U, 6U, 8U);

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

	TEST_CASE(vec2_constructor)
	{
		constexpr fvec4 v(fvec2(1.1f, 2.2f), 3.3f, 4.4f);
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 2.2f);
		test_assert(v[2] == 3.3f);
		test_assert(v[3] == 4.4f);
	}

	TEST_CASE(vec3_constructor)
	{
		constexpr fvec4 v(fvec3(1.1f, 2.2f, 3.3f), 4.4f);
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 2.2f);
		test_assert(v[2] == 3.3f);
		test_assert(v[3] == 4.4f);
	}

	TEST_CASE(explicit_conversion_constructor)
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

	TEST_CASE(implicit_conversion_operator)
	{
		CONST_OR_CONSTEXPR dvec4 v = fv41;
		test_assert(v[0] == double(fv41[0]));
		test_assert(v[1] == double(fv41[1]));
		test_assert(v[2] == double(fv41[2]));
		test_assert(v[3] == double(fv41[3]));
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

	TEST_CASE(xy)
	{
		CONST_OR_CONSTEXPR fvec2 xy = fv41.xy();
		test_assert(xy == fvec2(fv41));
	}

	TEST_CASE(set_xy)
	{
		fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
		v1.set_xy(2.1f, 2.2f);
		test_assert(v1[0] == 2.1f);
		test_assert(v1[1] == 2.2f);
		test_assert(v1[2] == 1.3f);
		test_assert(v1[3] == 1.4f);

		fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
		v2.set_xy(fvec2(2.1f, 2.2f));
		test_assert(v2[0] == 2.1f);
		test_assert(v2[1] == 2.2f);
		test_assert(v2[2] == 1.3f);
		test_assert(v2[3] == 1.4f);
	}

	TEST_CASE(xyz)
	{
		CONST_OR_CONSTEXPR fvec3 xyz = fv41.xyz();
		test_assert(xyz == fvec3(fv41));
	}

	TEST_CASE(set_xyz)
	{
		fvec4 v1(1.1f, 1.2f, 1.3f, 1.4f);
		v1.set_xyz(2.1f, 2.2f, 2.3f);
		test_assert(v1[0] == 2.1f);
		test_assert(v1[1] == 2.2f);
		test_assert(v1[2] == 2.3f);
		test_assert(v1[3] == 1.4f);

		fvec4 v2(1.1f, 1.2f, 1.3f, 1.4f);
		v2.set_xyz(fvec3(2.1f, 2.2f, 2.3f));
		test_assert(v2[0] == 2.1f);
		test_assert(v2[1] == 2.2f);
		test_assert(v2[2] == 2.3f);
		test_assert(v2[3] == 1.4f);
	}

	TEST_CASE(pre_increment_operator)
	{
		fvec4 v = fv41;
		test_assert(&(++v) == &v);
		test_assert(v == fv41 + 1);
	}

	TEST_CASE(pre_decrement_operator)
	{
		fvec4 v = fv41;
		test_assert(&(--v) == &v);
		test_assert(v == fv41 - 1);
	}

	TEST_CASE(post_increment_operator)
	{
		fvec4 v = fv41;
		test_assert(v++ == fv41);
		test_assert(v == fv41 + 1);
	}

	TEST_CASE(post_decrement_operator)
	{
		fvec4 v = fv41;
		test_assert(v-- == fv41);
		test_assert(v == fv41 - 1);
	}

	TEST_CASE(addition_assignment_operator)
	{
		fvec4 v1 = fv41;
		test_assert(&(v1 += u2) == &v1);
		test_assert(v1 == fv41 + u2);

		fvec4 v2 = fv41;
		test_assert(&(v2 += uv42) == &v2);
		test_assert(v2 == fv41 + uv42);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		fvec4 v1 = fv41;
		test_assert(&(v1 -= u2) == &v1);
		test_assert(v1 == fv41 - u2);

		fvec4 v2 = fv41;
		test_assert(&(v2 -= uv42) == &v2);
		test_assert(v2 == fv41 - uv42);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		fvec4 v1 = fv41;
		test_assert(&(v1 *= u2) == &v1);
		test_assert(v1 == fv41 * u2);

		fvec4 v2 = fv41;
		test_assert(&(v2 *= uv42) == &v2);
		test_assert(v2 == fv41 * uv42);
	}

	TEST_CASE(division_assignment_operator)
	{
		fvec4 v1 = fv41;
		test_assert(&(v1 /= u2) == &v1);
		test_assert(v1 == fv41 / u2);

		fvec4 v2 = fv41;
		test_assert(&(v2 /= uv42) == &v2);
		test_assert(v2 == fv41 / uv42);
	}

	TEST_CASE(modulo_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 %= u2) == &v1);
		test_assert(v1 == iv41 % u2);

		ivec4 v2 = iv41;
		test_assert(&(v2 %= uv42) == &v2);
		test_assert(v2 == iv41 % uv42);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 &= u2) == &v1);
		test_assert(v1 == (iv41 & u2));

		ivec4 v2 = iv41;
		test_assert(&(v2 &= uv42) == &v2);
		test_assert(v2 == (iv41 & uv42));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 |= u2) == &v1);
		test_assert(v1 == (iv41 | u2));

		ivec4 v2 = iv41;
		test_assert(&(v2 |= uv42) == &v2);
		test_assert(v2 == (iv41 | uv42));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 ^= u2) == &v1);
		test_assert(v1 == (iv41 ^ u2));

		ivec4 v2 = iv41;
		test_assert(&(v2 ^= uv42) == &v2);
		test_assert(v2 == (iv41 ^ uv42));
	}

	TEST_CASE(bitwise_shift_left_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 <<= u2) == &v1);
		test_assert(v1 == (iv41 << u2));

		ivec4 v2 = iv41;
		test_assert(&(v2 <<= uv42) == &v2);
		test_assert(v2 == (iv41 << uv42));
	}

	TEST_CASE(bitwise_shift_right_assignment_operator)
	{
		ivec4 v1 = iv41;
		test_assert(&(v1 >>= u2) == &v1);
		test_assert(v1 == (iv41 >> u2));

		ivec4 v2 = iv41;
		test_assert(&(v2 >>= uv42) == &v2);
		test_assert(v2 == (iv41 >> uv42));
	}

	TEST_CASE(unary_plus_operator)
	{
		CONST_OR_CONSTEXPR auto v = +fv41;
		test_assert(v[0] == +fv41[0]);
		test_assert(v[1] == +fv41[1]);
		test_assert(v[2] == +fv41[2]);
		test_assert(v[3] == +fv41[3]);
	}

	TEST_CASE(unary_minus_operator)
	{
		CONST_OR_CONSTEXPR auto v = -fv41;
		test_assert(v[0] == -fv41[0]);
		test_assert(v[1] == -fv41[1]);
		test_assert(v[2] == -fv41[2]);
		test_assert(v[3] == -fv41[3]);
	}

	TEST_CASE(bitwise_not_operator)
	{
		CONST_OR_CONSTEXPR auto v = ~iv41;
		test_assert(v[0] == ~iv41[0]);
		test_assert(v[1] == ~iv41[1]);
		test_assert(v[2] == ~iv41[2]);
		test_assert(v[3] == ~iv41[3]);
	}

	TEST_CASE(addition_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 + dv42;
		test_assert(v1[0] == f1 + dv42[0]);
		test_assert(v1[1] == f1 + dv42[1]);
		test_assert(v1[2] == f1 + dv42[2]);
		test_assert(v1[3] == f1 + dv42[3]);

		CONST_OR_CONSTEXPR auto v2 = fv41 + d2;
		test_assert(v2[0] == fv41[0] + d2);
		test_assert(v2[1] == fv41[1] + d2);
		test_assert(v2[2] == fv41[2] + d2);
		test_assert(v2[3] == fv41[3] + d2);

		CONST_OR_CONSTEXPR auto v3 = fv41 + dv42;
		test_assert(v3[0] == fv41[0] + dv42[0]);
		test_assert(v3[1] == fv41[1] + dv42[1]);
		test_assert(v3[2] == fv41[2] + dv42[2]);
		test_assert(v3[3] == fv41[3] + dv42[3]);
	}

	TEST_CASE(subtraction_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 - dv42;
		test_assert(v1[0] == f1 - dv42[0]);
		test_assert(v1[1] == f1 - dv42[1]);
		test_assert(v1[2] == f1 - dv42[2]);
		test_assert(v1[3] == f1 - dv42[3]);

		CONST_OR_CONSTEXPR auto v2 = fv41 - d2;
		test_assert(v2[0] == fv41[0] - d2);
		test_assert(v2[1] == fv41[1] - d2);
		test_assert(v2[2] == fv41[2] - d2);
		test_assert(v2[3] == fv41[3] - d2);

		CONST_OR_CONSTEXPR auto v3 = fv41 - dv42;
		test_assert(v3[0] == fv41[0] - dv42[0]);
		test_assert(v3[1] == fv41[1] - dv42[1]);
		test_assert(v3[2] == fv41[2] - dv42[2]);
		test_assert(v3[3] == fv41[3] - dv42[3]);
	}

	TEST_CASE(multiplication_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 * dv42;
		test_assert(v1[0] == f1 * dv42[0]);
		test_assert(v1[1] == f1 * dv42[1]);
		test_assert(v1[2] == f1 * dv42[2]);
		test_assert(v1[3] == f1 * dv42[3]);

		CONST_OR_CONSTEXPR auto v2 = fv41 * d2;
		test_assert(v2[0] == fv41[0] * d2);
		test_assert(v2[1] == fv41[1] * d2);
		test_assert(v2[2] == fv41[2] * d2);
		test_assert(v2[3] == fv41[3] * d2);

		CONST_OR_CONSTEXPR auto v3 = fv41 * dv42;
		test_assert(v3[0] == fv41[0] * dv42[0]);
		test_assert(v3[1] == fv41[1] * dv42[1]);
		test_assert(v3[2] == fv41[2] * dv42[2]);
		test_assert(v3[3] == fv41[3] * dv42[3]);
	}

	TEST_CASE(division_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = f1 / dv42;
		test_assert(v1[0] == f1 / dv42[0]);
		test_assert(v1[1] == f1 / dv42[1]);
		test_assert(v1[2] == f1 / dv42[2]);
		test_assert(v1[3] == f1 / dv42[3]);

		CONST_OR_CONSTEXPR auto v2 = fv41 / d2;
		test_assert(v2[0] == fv41[0] / d2);
		test_assert(v2[1] == fv41[1] / d2);
		test_assert(v2[2] == fv41[2] / d2);
		test_assert(v2[3] == fv41[3] / d2);

		CONST_OR_CONSTEXPR auto v3 = fv41 / dv42;
		test_assert(v3[0] == fv41[0] / dv42[0]);
		test_assert(v3[1] == fv41[1] / dv42[1]);
		test_assert(v3[2] == fv41[2] / dv42[2]);
		test_assert(v3[3] == fv41[3] / dv42[3]);
	}

	TEST_CASE(modulo_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 % uv42;
		test_assert(v1[0] == i1 % uv42[0]);
		test_assert(v1[1] == i1 % uv42[1]);
		test_assert(v1[2] == i1 % uv42[2]);
		test_assert(v1[3] == i1 % uv42[3]);

		CONST_OR_CONSTEXPR auto v2 = iv41 % u2;
		test_assert(v2[0] == iv41[0] % u2);
		test_assert(v2[1] == iv41[1] % u2);
		test_assert(v2[2] == iv41[2] % u2);
		test_assert(v2[3] == iv41[3] % u2);

		CONST_OR_CONSTEXPR auto v3 = iv41 % uv42;
		test_assert(v3[0] == iv41[0] % uv42[0]);
		test_assert(v3[1] == iv41[1] % uv42[1]);
		test_assert(v3[2] == iv41[2] % uv42[2]);
		test_assert(v3[3] == iv41[3] % uv42[3]);
	}

	TEST_CASE(bitwise_and_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 & uv42;
		test_assert(v1[0] == (i1 & uv42[0]));
		test_assert(v1[1] == (i1 & uv42[1]));
		test_assert(v1[2] == (i1 & uv42[2]));
		test_assert(v1[3] == (i1 & uv42[3]));

		CONST_OR_CONSTEXPR auto v2 = iv41 & u2;
		test_assert(v2[0] == (iv41[0] & u2));
		test_assert(v2[1] == (iv41[1] & u2));
		test_assert(v2[2] == (iv41[2] & u2));
		test_assert(v2[3] == (iv41[3] & u2));

		CONST_OR_CONSTEXPR auto v3 = iv41 & uv42;
		test_assert(v3[0] == (iv41[0] & uv42[0]));
		test_assert(v3[1] == (iv41[1] & uv42[1]));
		test_assert(v3[2] == (iv41[2] & uv42[2]));
		test_assert(v3[3] == (iv41[3] & uv42[3]));
	}

	TEST_CASE(bitwise_or_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 | uv42;
		test_assert(v1[0] == (i1 | uv42[0]));
		test_assert(v1[1] == (i1 | uv42[1]));
		test_assert(v1[2] == (i1 | uv42[2]));
		test_assert(v1[3] == (i1 | uv42[3]));

		CONST_OR_CONSTEXPR auto v2 = iv41 | u2;
		test_assert(v2[0] == (iv41[0] | u2));
		test_assert(v2[1] == (iv41[1] | u2));
		test_assert(v2[2] == (iv41[2] | u2));
		test_assert(v2[3] == (iv41[3] | u2));

		CONST_OR_CONSTEXPR auto v3 = iv41 | uv42;
		test_assert(v3[0] == (iv41[0] | uv42[0]));
		test_assert(v3[1] == (iv41[1] | uv42[1]));
		test_assert(v3[2] == (iv41[2] | uv42[2]));
		test_assert(v3[3] == (iv41[3] | uv42[3]));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 ^ uv42;
		test_assert(v1[0] == (i1 ^ uv42[0]));
		test_assert(v1[1] == (i1 ^ uv42[1]));
		test_assert(v1[2] == (i1 ^ uv42[2]));
		test_assert(v1[3] == (i1 ^ uv42[3]));

		CONST_OR_CONSTEXPR auto v2 = iv41 ^ u2;
		test_assert(v2[0] == (iv41[0] ^ u2));
		test_assert(v2[1] == (iv41[1] ^ u2));
		test_assert(v2[2] == (iv41[2] ^ u2));
		test_assert(v2[3] == (iv41[3] ^ u2));

		CONST_OR_CONSTEXPR auto v3 = iv41 ^ uv42;
		test_assert(v3[0] == (iv41[0] ^ uv42[0]));
		test_assert(v3[1] == (iv41[1] ^ uv42[1]));
		test_assert(v3[2] == (iv41[2] ^ uv42[2]));
		test_assert(v3[3] == (iv41[3] ^ uv42[3]));
	}

	TEST_CASE(bitwise_shift_left_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 << uv42;
		test_assert(v1[0] == (i1 << uv42[0]));
		test_assert(v1[1] == (i1 << uv42[1]));
		test_assert(v1[2] == (i1 << uv42[2]));
		test_assert(v1[3] == (i1 << uv42[3]));

		CONST_OR_CONSTEXPR auto v2 = iv41 << u2;
		test_assert(v2[0] == (iv41[0] << u2));
		test_assert(v2[1] == (iv41[1] << u2));
		test_assert(v2[2] == (iv41[2] << u2));
		test_assert(v2[3] == (iv41[3] << u2));

		CONST_OR_CONSTEXPR auto v3 = iv41 << uv42;
		test_assert(v3[0] == (iv41[0] << uv42[0]));
		test_assert(v3[1] == (iv41[1] << uv42[1]));
		test_assert(v3[2] == (iv41[2] << uv42[2]));
		test_assert(v3[3] == (iv41[3] << uv42[3]));
	}

	TEST_CASE(bitwise_shift_right_operator)
	{
		CONST_OR_CONSTEXPR auto v1 = i1 >> uv42;
		test_assert(v1[0] == (i1 >> uv42[0]));
		test_assert(v1[1] == (i1 >> uv42[1]));
		test_assert(v1[2] == (i1 >> uv42[2]));
		test_assert(v1[3] == (i1 >> uv42[3]));

		CONST_OR_CONSTEXPR auto v2 = iv41 >> u2;
		test_assert(v2[0] == (iv41[0] >> u2));
		test_assert(v2[1] == (iv41[1] >> u2));
		test_assert(v2[2] == (iv41[2] >> u2));
		test_assert(v2[3] == (iv41[3] >> u2));

		CONST_OR_CONSTEXPR auto v3 = iv41 >> uv42;
		test_assert(v3[0] == (iv41[0] >> uv42[0]));
		test_assert(v3[1] == (iv41[1] >> uv42[1]));
		test_assert(v3[2] == (iv41[2] >> uv42[2]));
		test_assert(v3[3] == (iv41[3] >> uv42[3]));
	}

	TEST_CASE(equality_operator)
	{
		constexpr fvec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
		constexpr ivec4 v2(1, 2, 3, 4);
		constexpr ivec4 v3(0, 2, 3, 4);
		constexpr ivec4 v4(1, 0, 3, 4);
		constexpr ivec4 v5(1, 2, 0, 4);
		constexpr ivec4 v6(1, 2, 3, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 == v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 == v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 == v4);
		CONST_OR_CONSTEXPR bool result4 = (v1 == v5);
		CONST_OR_CONSTEXPR bool result5 = (v1 == v6);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
		test_assert(result4 == false);
		test_assert(result5 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr fvec4 v1(1.0f, 2.0f, 3.0f, 4.0f);
		constexpr ivec4 v2(1, 2, 3, 4);
		constexpr ivec4 v3(0, 2, 3, 4);
		constexpr ivec4 v4(1, 0, 3, 4);
		constexpr ivec4 v5(1, 2, 0, 4);
		constexpr ivec4 v6(1, 2, 3, 0);
		CONST_OR_CONSTEXPR bool result1 = (v1 != v2);
		CONST_OR_CONSTEXPR bool result2 = (v1 != v3);
		CONST_OR_CONSTEXPR bool result3 = (v1 != v4);
		CONST_OR_CONSTEXPR bool result4 = (v1 != v5);
		CONST_OR_CONSTEXPR bool result5 = (v1 != v6);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
		test_assert(result4 == true);
		test_assert(result5 == true);
	}
}
