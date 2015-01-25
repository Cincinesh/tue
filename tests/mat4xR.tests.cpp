//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/mat.hpp>
#include "test_case.hpp"

#include <tue/math.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
	using namespace tue;

	constexpr auto f1 = 1.1f;

	constexpr auto f2 = 2.2f;

	constexpr auto d2 = 2.2;

	constexpr auto i1 = 111;

	constexpr auto u2 = 2U;

	constexpr fmat4x2 fm421 = {
		{ 1.1f, 1.2f },
		{ 2.1f, 2.2f },
		{ 3.1f, 3.2f },
		{ 4.1f, 4.2f },
	};

	constexpr fmat4x2 fm422 = {
		{ 2.2f, 2.4f },
		{ 4.2f, 4.4f },
		{ 6.2f, 6.4f },
		{ 8.2f, 8.4f },
	};

	constexpr dmat4x2 dm421 = {
		{ 1.1, 1.2 },
		{ 2.1, 2.2 },
		{ 3.1, 3.2 },
		{ 4.1, 4.2 },
	};

	constexpr dmat4x2 dm422 = {
		{ 2.2, 2.4 },
		{ 4.2, 4.4 },
		{ 6.2, 6.4 },
		{ 8.2, 8.4 },
	};

	constexpr mat4x2<int> im421 = {
		{ 111, 222 },
		{ 333, 444 },
		{ 555, 666 },
		{ 777, 888 },
	};

	constexpr mat4x2<int> im422 = {
		{ 2, 3 },
		{ 4, 5 },
		{ 6, 7 },
		{ 8, 9 },
	};

	constexpr mat4x2<unsigned int> um422 = {
		{ 2U, 3U },
		{ 4U, 5U },
		{ 6U, 7U },
		{ 8U, 9U },
	};

	TEST_CASE(default_constructor)
	{
		fmat4x2 m;
		unused(m);
	}

	TEST_CASE(scalar_constructor)
	{
		constexpr fmat4x2 m1(1.1f);
		test_assert(m1[0] == fvec2(1.1f, 0.0f));
		test_assert(m1[1] == fvec2(0.0f, 1.1f));
		test_assert(m1[2] == fvec2(0.0f, 0.0f));
		test_assert(m1[3] == fvec2(0.0f, 0.0f));

		constexpr fmat4x3 m2(2.2f);
		test_assert(m2[0] == fvec3(2.2f, 0.0f, 0.0f));
		test_assert(m2[1] == fvec3(0.0f, 2.2f, 0.0f));
		test_assert(m2[2] == fvec3(0.0f, 0.0f, 2.2f));
		test_assert(m2[3] == fvec3(0.0f, 0.0f, 0.0f));

		constexpr fmat4x4 m3(3.3f);
		test_assert(m3[0] == fvec4(3.3f, 0.0f, 0.0f, 0.0f));
		test_assert(m3[1] == fvec4(0.0f, 3.3f, 0.0f, 0.0f));
		test_assert(m3[2] == fvec4(0.0f, 0.0f, 3.3f, 0.0f));
		test_assert(m3[3] == fvec4(0.0f, 0.0f, 0.0f, 3.3f));
	}

	TEST_CASE(column_constructor)
	{
		constexpr fmat4x2 m = {
			{ 1.1f, 1.2f },
			{ 2.1f, 2.2f },
			{ 3.1f, 3.2f },
			{ 4.1f, 4.2f },
		};
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
		test_assert(m[2] == fvec2(3.1f, 3.2f));
		test_assert(m[3] == fvec2(4.1f, 4.2f));
	}

	TEST_CASE(extend_and_truncate_constructors)
	{
		// TODO
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr fmat4x2 m(dm421);
		test_assert(m[0] == fvec2(dm421[0]));
		test_assert(m[1] == fvec2(dm421[1]));
		test_assert(m[2] == fvec2(dm421[2]));
		test_assert(m[3] == fvec2(dm421[3]));
	}

	TEST_CASE(implicit_conversion_operator)
	{
		CONST_OR_CONSTEXPR dmat4x2 m = fm421;
		test_assert(m[0] == dvec2(fm421[0]));
		test_assert(m[1] == dvec2(fm421[1]));
		test_assert(m[2] == dvec2(fm421[2]));
		test_assert(m[3] == dvec2(fm421[3]));
	}

	TEST_CASE(identity)
	{
		CONST_OR_CONSTEXPR auto m1 = fmat4x2::identity();
		CONST_OR_CONSTEXPR auto m2 = fmat4x3::identity();
		CONST_OR_CONSTEXPR auto m3 = fmat4x4::identity();
		test_assert(m1 == fmat4x2(1.0f));
		test_assert(m2 == fmat4x3(1.0f));
		test_assert(m3 == fmat4x4(1.0f));
	}

	TEST_CASE(zero)
	{
		CONST_OR_CONSTEXPR auto m1 = fmat4x2::zero();
		CONST_OR_CONSTEXPR auto m2 = fmat4x3::zero();
		CONST_OR_CONSTEXPR auto m3 = fmat4x4::zero();
		test_assert(m1 == fmat4x2(0.0f));
		test_assert(m2 == fmat4x3(0.0f));
		test_assert(m3 == fmat4x4(0.0f));
	}

	TEST_CASE(column)
	{
		CONST_OR_CONSTEXPR fvec2 column0 = fm421.column(0);
		CONST_OR_CONSTEXPR fvec2 column1 = fm421.column(1);
		CONST_OR_CONSTEXPR fvec2 column2 = fm421.column(2);
		CONST_OR_CONSTEXPR fvec2 column3 = fm421.column(3);
		test_assert(column0 == fm421[0]);
		test_assert(column1 == fm421[1]);
		test_assert(column2 == fm421[2]);
		test_assert(column3 == fm421[3]);
	}

	TEST_CASE(set_column)
	{
		fmat4x2 m;
		m.set_column(0, fvec2(1.1f, 1.2f));
		m.set_column(1, fvec2(2.1f, 2.2f));
		m.set_column(2, fvec2(3.1f, 3.2f));
		m.set_column(3, fvec2(4.1f, 4.2f));
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
		test_assert(m[2] == fvec2(3.1f, 3.2f));
		test_assert(m[3] == fvec2(4.1f, 4.2f));
	}

	TEST_CASE(row)
	{
		CONST_OR_CONSTEXPR fvec4 row0 = fm421.row(0);
		CONST_OR_CONSTEXPR fvec4 row1 = fm421.row(1);
		test_assert(row0 == fvec4(fm421[0][0], fm421[1][0], fm421[2][0], fm421[3][0]));
		test_assert(row1 == fvec4(fm421[0][1], fm421[1][1], fm421[2][1], fm421[3][1]));
	}

	TEST_CASE(set_row)
	{
		fmat4x2 m;
		m.set_row(0, fvec4(1.1f, 2.1f, 3.1f, 4.1f));
		m.set_row(1, fvec4(1.2f, 2.2f, 3.2f, 4.2f));
		test_assert(m[0] == fvec2(1.1f, 1.2f));
		test_assert(m[1] == fvec2(2.1f, 2.2f));
		test_assert(m[2] == fvec2(3.1f, 3.2f));
		test_assert(m[3] == fvec2(4.1f, 4.2f));
	}

	TEST_CASE(subscript_operator)
	{
		constexpr fmat4x2 cem = {
			{ 1.1f, 1.2f },
			{ 2.1f, 2.2f },
			{ 3.1f, 3.2f },
			{ 4.1f, 4.2f },
		};
		CONST_OR_CONSTEXPR fvec2 cem0 = cem[0];
		CONST_OR_CONSTEXPR fvec2 cem1 = cem[1];
		CONST_OR_CONSTEXPR fvec2 cem2 = cem[2];
		CONST_OR_CONSTEXPR fvec2 cem3 = cem[3];
		test_assert(cem0 == fvec2(1.1f, 1.2f));
		test_assert(cem1 == fvec2(2.1f, 2.2f));
		test_assert(cem2 == fvec2(3.1f, 3.2f));
		test_assert(cem3 == fvec2(4.1f, 4.2f));

		fmat4x2 m = cem;
		fvec2& m0 = m[0];
		fvec2& m1 = m[1];
		fvec2& m2 = m[2];
		fvec2& m3 = m[3];
		test_assert(static_cast<void*>(&m0) == static_cast<void*>(&m));
		test_assert(&m1 == &m0 + 1);
		test_assert(&m2 == &m0 + 2);
		test_assert(&m3 == &m0 + 3);

		const fmat4x2& cm = m;
		const fvec2& cm0 = cm[0];
		const fvec2& cm1 = cm[1];
		const fvec2& cm2 = cm[2];
		const fvec2& cm3 = cm[3];
		test_assert(&cm0 == &m0);
		test_assert(&cm1 == &m1);
		test_assert(&cm2 == &m2);
		test_assert(&cm3 == &m3);
	}

	TEST_CASE(pre_increment_operator)
	{
		fmat4x2 m = fm421;
		test_assert(&(++m) == &m);
		test_assert(m == fm421 + 1);
	}

	TEST_CASE(pre_decrement_operator)
	{
		fmat4x2 m = fm421;
		test_assert(&(--m) == &m);
		test_assert(m == fm421 - 1);
	}

	TEST_CASE(post_increment_operator)
	{
		fmat4x2 m = fm421;
		test_assert(m++ == fm421);
		test_assert(m == fm421 + 1);
	}

	TEST_CASE(post_decrement_operator)
	{
		fmat4x2 m = fm421;
		test_assert(m-- == fm421);
		test_assert(m == fm421 - 1);
	}

	TEST_CASE(addition_assignment_operator)
	{
		fmat4x2 m1 = fm421;
		test_assert(&(m1 += u2) == &m1);
		test_assert(m1 == fm421 + u2);

		fmat4x2 m2 = fm421;
		test_assert(&(m2 += um422) == &m2);
		test_assert(m2 == fm421 + um422);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		fmat4x2 m1 = fm421;
		test_assert(&(m1 -= u2) == &m1);
		test_assert(m1 == fm421 - u2);

		fmat4x2 m2 = fm421;
		test_assert(&(m2 -= um422) == &m2);
		test_assert(m2 == fm421 - um422);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		fmat4x2 m1 = fm421;
		test_assert(&(m1 *= u2) == &m1);
		test_assert(m1 == fm421 * u2);

		// TODO
		//fmat4x2 m2 = fm421;
		//test_assert(&(m2 *= um422) == &m2);
		//test_assert(m2 == fm421 * um422);
	}

	TEST_CASE(division_assignment_operator)
	{
		fmat4x2 m1 = fm421;
		test_assert(&(m1 /= u2) == &m1);
		test_assert(m1 == fm421 / u2);

		fmat4x2 m2 = fm421;
		test_assert(&(m2 /= um422) == &m2);
		test_assert(m2 == fm421 / um422);
	}

	TEST_CASE(modulo_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 %= u2) == &m1);
		test_assert(m1 == im421 % u2);

		mat4x2<int> m2 = im421;
		test_assert(&(m2 %= um422) == &m2);
		test_assert(m2 == im421 % um422);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 &= u2) == &m1);
		test_assert(m1 == (im421 & u2));

		mat4x2<int> m2 = im421;
		test_assert(&(m2 &= um422) == &m2);
		test_assert(m2 == (im421 & um422));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 |= u2) == &m1);
		test_assert(m1 == (im421 | u2));

		mat4x2<int> m2 = im421;
		test_assert(&(m2 |= um422) == &m2);
		test_assert(m2 == (im421 | um422));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 ^= u2) == &m1);
		test_assert(m1 == (im421 ^ u2));

		mat4x2<int> m2 = im421;
		test_assert(&(m2 ^= um422) == &m2);
		test_assert(m2 == (im421 ^ um422));
	}

	TEST_CASE(bitwise_shift_left_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 <<= u2) == &m1);
		test_assert(m1 == (im421 << u2));

		mat4x2<int> m2 = im421;
		test_assert(&(m2 <<= um422) == &m2);
		test_assert(m2 == (im421 << um422));
	}

	TEST_CASE(bitwise_shift_right_assignment_operator)
	{
		mat4x2<int> m1 = im421;
		test_assert(&(m1 >>= u2) == &m1);
		test_assert(m1 == (im421 >> u2));

		mat4x2<int> m2 = im421;
		test_assert(&(m2 >>= um422) == &m2);
		test_assert(m2 == (im421 >> um422));
	}

	TEST_CASE(unary_plus_operator)
	{
		CONST_OR_CONSTEXPR auto m = +fm421;
		test_assert(m[0] == +fm421[0]);
		test_assert(m[1] == +fm421[1]);
		test_assert(m[2] == +fm421[2]);
		test_assert(m[3] == +fm421[3]);
	}

	TEST_CASE(unary_minus_operator)
	{
		CONST_OR_CONSTEXPR auto m = -fm421;
		test_assert(m[0] == -fm421[0]);
		test_assert(m[1] == -fm421[1]);
		test_assert(m[2] == -fm421[2]);
		test_assert(m[3] == -fm421[3]);
	}

	TEST_CASE(bitwise_not_operator)
	{
		CONST_OR_CONSTEXPR auto m = ~im421;
		test_assert(m[0] == ~im421[0]);
		test_assert(m[1] == ~im421[1]);
		test_assert(m[2] == ~im421[2]);
		test_assert(m[3] == ~im421[3]);
	}

	TEST_CASE(addition_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 + dm422;
		test_assert(m1[0] == f1 + dm422[0]);
		test_assert(m1[1] == f1 + dm422[1]);
		test_assert(m1[2] == f1 + dm422[2]);
		test_assert(m1[3] == f1 + dm422[3]);

		CONST_OR_CONSTEXPR auto m2 = fm421 + d2;
		test_assert(m2[0] == fm421[0] + d2);
		test_assert(m2[1] == fm421[1] + d2);
		test_assert(m2[2] == fm421[2] + d2);
		test_assert(m2[3] == fm421[3] + d2);

		CONST_OR_CONSTEXPR auto m3 = fm421 + dm422;
		test_assert(m3[0] == fm421[0] + dm422[0]);
		test_assert(m3[1] == fm421[1] + dm422[1]);
		test_assert(m3[2] == fm421[2] + dm422[2]);
		test_assert(m3[3] == fm421[3] + dm422[3]);
	}

	TEST_CASE(subtraction_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 - dm422;
		test_assert(m1[0] == f1 - dm422[0]);
		test_assert(m1[1] == f1 - dm422[1]);
		test_assert(m1[2] == f1 - dm422[2]);
		test_assert(m1[3] == f1 - dm422[3]);

		CONST_OR_CONSTEXPR auto m2 = fm421 - d2;
		test_assert(m2[0] == fm421[0] - d2);
		test_assert(m2[1] == fm421[1] - d2);
		test_assert(m2[2] == fm421[2] - d2);
		test_assert(m2[3] == fm421[3] - d2);

		CONST_OR_CONSTEXPR auto m3 = fm421 - dm422;
		test_assert(m3[0] == fm421[0] - dm422[0]);
		test_assert(m3[1] == fm421[1] - dm422[1]);
		test_assert(m3[2] == fm421[2] - dm422[2]);
		test_assert(m3[3] == fm421[3] - dm422[3]);
	}

	TEST_CASE(multiplication_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 * dm422;
		test_assert(m1[0] == f1 * dm422[0]);
		test_assert(m1[1] == f1 * dm422[1]);
		test_assert(m1[2] == f1 * dm422[2]);
		test_assert(m1[3] == f1 * dm422[3]);

		CONST_OR_CONSTEXPR auto m2 = fm421 * d2;
		test_assert(m2[0] == fm421[0] * d2);
		test_assert(m2[1] == fm421[1] * d2);
		test_assert(m2[2] == fm421[2] * d2);
		test_assert(m2[3] == fm421[3] * d2);
	}

	TEST_CASE(division_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = f1 / dm422;
		test_assert(m1[0] == f1 / dm422[0]);
		test_assert(m1[1] == f1 / dm422[1]);
		test_assert(m1[2] == f1 / dm422[2]);
		test_assert(m1[3] == f1 / dm422[3]);

		CONST_OR_CONSTEXPR auto m2 = fm421 / d2;
		test_assert(m2[0] == fm421[0] / d2);
		test_assert(m2[1] == fm421[1] / d2);
		test_assert(m2[2] == fm421[2] / d2);
		test_assert(m2[3] == fm421[3] / d2);

		CONST_OR_CONSTEXPR auto m3 = fm421 / dm422;
		test_assert(m3[0] == fm421[0] / dm422[0]);
		test_assert(m3[1] == fm421[1] / dm422[1]);
		test_assert(m3[2] == fm421[2] / dm422[2]);
		test_assert(m3[3] == fm421[3] / dm422[3]);
	}

	TEST_CASE(modulo_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 % um422;
		test_assert(m1[0] == i1 % um422[0]);
		test_assert(m1[1] == i1 % um422[1]);
		test_assert(m1[2] == i1 % um422[2]);
		test_assert(m1[3] == i1 % um422[3]);

		CONST_OR_CONSTEXPR auto m2 = im421 % u2;
		test_assert(m2[0] == im421[0] % u2);
		test_assert(m2[1] == im421[1] % u2);
		test_assert(m2[2] == im421[2] % u2);
		test_assert(m2[3] == im421[3] % u2);

		CONST_OR_CONSTEXPR auto m3 = im421 % um422;
		test_assert(m3[0] == im421[0] % um422[0]);
		test_assert(m3[1] == im421[1] % um422[1]);
		test_assert(m3[2] == im421[2] % um422[2]);
		test_assert(m3[3] == im421[3] % um422[3]);
	}

	TEST_CASE(bitwise_and_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 & um422;
		test_assert(m1[0] == (i1 & um422[0]));
		test_assert(m1[1] == (i1 & um422[1]));
		test_assert(m1[2] == (i1 & um422[2]));
		test_assert(m1[3] == (i1 & um422[3]));

		CONST_OR_CONSTEXPR auto m2 = im421 & u2;
		test_assert(m2[0] == (im421[0] & u2));
		test_assert(m2[1] == (im421[1] & u2));
		test_assert(m2[2] == (im421[2] & u2));
		test_assert(m2[3] == (im421[3] & u2));

		CONST_OR_CONSTEXPR auto m3 = im421 & um422;
		test_assert(m3[0] == (im421[0] & um422[0]));
		test_assert(m3[1] == (im421[1] & um422[1]));
		test_assert(m3[2] == (im421[2] & um422[2]));
		test_assert(m3[3] == (im421[3] & um422[3]));
	}

	TEST_CASE(bitwise_or_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 | um422;
		test_assert(m1[0] == (i1 | um422[0]));
		test_assert(m1[1] == (i1 | um422[1]));
		test_assert(m1[2] == (i1 | um422[2]));
		test_assert(m1[3] == (i1 | um422[3]));

		CONST_OR_CONSTEXPR auto m2 = im421 | u2;
		test_assert(m2[0] == (im421[0] | u2));
		test_assert(m2[1] == (im421[1] | u2));
		test_assert(m2[2] == (im421[2] | u2));
		test_assert(m2[3] == (im421[3] | u2));

		CONST_OR_CONSTEXPR auto m3 = im421 | um422;
		test_assert(m3[0] == (im421[0] | um422[0]));
		test_assert(m3[1] == (im421[1] | um422[1]));
		test_assert(m3[2] == (im421[2] | um422[2]));
		test_assert(m3[3] == (im421[3] | um422[3]));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 ^ um422;
		test_assert(m1[0] == (i1 ^ um422[0]));
		test_assert(m1[1] == (i1 ^ um422[1]));
		test_assert(m1[2] == (i1 ^ um422[2]));
		test_assert(m1[3] == (i1 ^ um422[3]));

		CONST_OR_CONSTEXPR auto m2 = im421 ^ u2;
		test_assert(m2[0] == (im421[0] ^ u2));
		test_assert(m2[1] == (im421[1] ^ u2));
		test_assert(m2[2] == (im421[2] ^ u2));
		test_assert(m2[3] == (im421[3] ^ u2));

		CONST_OR_CONSTEXPR auto m3 = im421 ^ um422;
		test_assert(m3[0] == (im421[0] ^ um422[0]));
		test_assert(m3[1] == (im421[1] ^ um422[1]));
		test_assert(m3[2] == (im421[2] ^ um422[2]));
		test_assert(m3[3] == (im421[3] ^ um422[3]));
	}

	TEST_CASE(bitwise_shift_left_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 << um422;
		test_assert(m1[0] == (i1 << um422[0]));
		test_assert(m1[1] == (i1 << um422[1]));
		test_assert(m1[2] == (i1 << um422[2]));
		test_assert(m1[3] == (i1 << um422[3]));

		CONST_OR_CONSTEXPR auto m2 = im421 << u2;
		test_assert(m2[0] == (im421[0] << u2));
		test_assert(m2[1] == (im421[1] << u2));
		test_assert(m2[2] == (im421[2] << u2));
		test_assert(m2[3] == (im421[3] << u2));

		CONST_OR_CONSTEXPR auto m3 = im421 << um422;
		test_assert(m3[0] == (im421[0] << um422[0]));
		test_assert(m3[1] == (im421[1] << um422[1]));
		test_assert(m3[2] == (im421[2] << um422[2]));
		test_assert(m3[3] == (im421[3] << um422[3]));
	}

	TEST_CASE(bitwise_shift_right_operator)
	{
		CONST_OR_CONSTEXPR auto m1 = i1 >> um422;
		test_assert(m1[0] == (i1 >> um422[0]));
		test_assert(m1[1] == (i1 >> um422[1]));
		test_assert(m1[2] == (i1 >> um422[2]));
		test_assert(m1[3] == (i1 >> um422[3]));

		CONST_OR_CONSTEXPR auto m2 = im421 >> u2;
		test_assert(m2[0] == (im421[0] >> u2));
		test_assert(m2[1] == (im421[1] >> u2));
		test_assert(m2[2] == (im421[2] >> u2));
		test_assert(m2[3] == (im421[3] >> u2));

		CONST_OR_CONSTEXPR auto m3 = im421 >> um422;
		test_assert(m3[0] == (im421[0] >> um422[0]));
		test_assert(m3[1] == (im421[1] >> um422[1]));
		test_assert(m3[2] == (im421[2] >> um422[2]));
		test_assert(m3[3] == (im421[3] >> um422[3]));
	}

	TEST_CASE(equality_operator)
	{
		constexpr fmat4x2 m1 = {
			fvec2(1.0f),
			fvec2(2.0f),
			fvec2(3.0f),
			fvec2(4.0f),
		};
		constexpr ivec2 iv0(0);
		constexpr ivec2 iv1(1);
		constexpr ivec2 iv2(2);
		constexpr ivec2 iv3(3);
		constexpr ivec2 iv4(4);
		constexpr mat4x2<int> m2(iv1, iv2, iv3, iv4);
		constexpr mat4x2<int> m3(iv0, iv2, iv3, iv4);
		constexpr mat4x2<int> m4(iv1, iv0, iv3, iv4);
		constexpr mat4x2<int> m5(iv1, iv2, iv0, iv4);
		constexpr mat4x2<int> m6(iv1, iv2, iv3, iv0);
		CONST_OR_CONSTEXPR bool result1 = (m1 == m2);
		CONST_OR_CONSTEXPR bool result2 = (m1 == m3);
		CONST_OR_CONSTEXPR bool result3 = (m1 == m4);
		CONST_OR_CONSTEXPR bool result4 = (m1 == m5);
		CONST_OR_CONSTEXPR bool result5 = (m1 == m6);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
		test_assert(result4 == false);
		test_assert(result5 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr fmat4x2 m1 = {
			fvec2(1.0f),
			fvec2(2.0f),
			fvec2(3.0f),
			fvec2(4.0f),
		};
		constexpr ivec2 iv0(0);
		constexpr ivec2 iv1(1);
		constexpr ivec2 iv2(2);
		constexpr ivec2 iv3(3);
		constexpr ivec2 iv4(4);
		constexpr mat4x2<int> m2(iv1, iv2, iv3, iv4);
		constexpr mat4x2<int> m3(iv0, iv2, iv3, iv4);
		constexpr mat4x2<int> m4(iv1, iv0, iv3, iv4);
		constexpr mat4x2<int> m5(iv1, iv2, iv0, iv4);
		constexpr mat4x2<int> m6(iv1, iv2, iv3, iv0);
		CONST_OR_CONSTEXPR bool result1 = (m1 != m2);
		CONST_OR_CONSTEXPR bool result2 = (m1 != m3);
		CONST_OR_CONSTEXPR bool result3 = (m1 != m4);
		CONST_OR_CONSTEXPR bool result4 = (m1 != m5);
		CONST_OR_CONSTEXPR bool result5 = (m1 != m6);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
		test_assert(result4 == true);
		test_assert(result5 == true);
	}

	TEST_CASE(sin)
	{
		const auto fsin = math::sin(fm421);
		test_assert(fsin[0] == math::sin(fm421[0]));
		test_assert(fsin[1] == math::sin(fm421[1]));
		test_assert(fsin[2] == math::sin(fm421[2]));
		test_assert(fsin[3] == math::sin(fm421[3]));

		const auto isin = math::sin(im421);
		test_assert(isin[0] == math::sin(im421[0]));
		test_assert(isin[1] == math::sin(im421[1]));
		test_assert(isin[2] == math::sin(im421[2]));
		test_assert(isin[3] == math::sin(im421[3]));
	}

	TEST_CASE(cos)
	{
		const auto fcos = math::cos(fm421);
		test_assert(fcos[0] == math::cos(fm421[0]));
		test_assert(fcos[1] == math::cos(fm421[1]));
		test_assert(fcos[2] == math::cos(fm421[2]));
		test_assert(fcos[3] == math::cos(fm421[3]));

		const auto icos = math::cos(im421);
		test_assert(icos[0] == math::cos(im421[0]));
		test_assert(icos[1] == math::cos(im421[1]));
		test_assert(icos[2] == math::cos(im421[2]));
		test_assert(icos[3] == math::cos(im421[3]));
	}

	TEST_CASE(sincos)
	{
		fmat4x2 fsin, fcos;
		math::sincos(fm421, fsin, fcos);
		test_assert(fsin == math::sin(fm421));
		test_assert(fcos == math::cos(fm421));

		dmat4x2 isin, icos;
		math::sincos(im421, isin, icos);
		test_assert(isin == math::sin(im421));
		test_assert(icos == math::cos(im421));
	}

	TEST_CASE(pow)
	{
		const auto fpow1 = math::pow(fm421, f2);
		test_assert(fpow1[0] == math::pow(fm421[0], f2));
		test_assert(fpow1[1] == math::pow(fm421[1], f2));
		test_assert(fpow1[2] == math::pow(fm421[2], f2));
		test_assert(fpow1[3] == math::pow(fm421[3], f2));

		const auto ipow1 = math::pow(im421, f2);
		test_assert(ipow1[0] == math::pow(im421[0], f2));
		test_assert(ipow1[1] == math::pow(im421[1], f2));
		test_assert(ipow1[2] == math::pow(im421[2], f2));
		test_assert(ipow1[3] == math::pow(im421[3], f2));

		const auto fpow2 = math::pow(fm421, fm422);
		test_assert(fpow2[0] == math::pow(fm421[0], fm422[0]));
		test_assert(fpow2[1] == math::pow(fm421[1], fm422[1]));
		test_assert(fpow2[2] == math::pow(fm421[2], fm422[2]));
		test_assert(fpow2[3] == math::pow(fm421[3], fm422[3]));

		const auto ipow2 = math::pow(im421, fm422);
		test_assert(ipow2[0] == math::pow(im421[0], fm422[0]));
		test_assert(ipow2[1] == math::pow(im421[1], fm422[1]));
		test_assert(ipow2[2] == math::pow(im421[2], fm422[2]));
		test_assert(ipow2[3] == math::pow(im421[3], fm422[3]));
	}

	TEST_CASE(rcp)
	{
		const auto frcp = math::rcp(fm421);
		test_assert(frcp[0] == math::rcp(fm421[0]));
		test_assert(frcp[1] == math::rcp(fm421[1]));
		test_assert(frcp[2] == math::rcp(fm421[2]));
		test_assert(frcp[3] == math::rcp(fm421[3]));

		const auto ircp = math::rcp(im421);
		test_assert(ircp[0] == math::rcp(im421[0]));
		test_assert(ircp[1] == math::rcp(im421[1]));
		test_assert(ircp[2] == math::rcp(im421[2]));
		test_assert(ircp[3] == math::rcp(im421[3]));
	}

	TEST_CASE(sqrt)
	{
		const auto fsqrt = math::sqrt(fm421);
		test_assert(fsqrt[0] == math::sqrt(fm421[0]));
		test_assert(fsqrt[1] == math::sqrt(fm421[1]));
		test_assert(fsqrt[2] == math::sqrt(fm421[2]));
		test_assert(fsqrt[3] == math::sqrt(fm421[3]));

		const auto isqrt = math::sqrt(im421);
		test_assert(isqrt[0] == math::sqrt(im421[0]));
		test_assert(isqrt[1] == math::sqrt(im421[1]));
		test_assert(isqrt[2] == math::sqrt(im421[2]));
		test_assert(isqrt[3] == math::sqrt(im421[3]));
	}

	TEST_CASE(rsqrt)
	{
		const auto frsqrt = math::rsqrt(fm421);
		test_assert(frsqrt[0] == math::rsqrt(fm421[0]));
		test_assert(frsqrt[1] == math::rsqrt(fm421[1]));
		test_assert(frsqrt[2] == math::rsqrt(fm421[2]));
		test_assert(frsqrt[3] == math::rsqrt(fm421[3]));

		const auto irsqrt = math::rsqrt(im421);
		test_assert(irsqrt[0] == math::rsqrt(im421[0]));
		test_assert(irsqrt[1] == math::rsqrt(im421[1]));
		test_assert(irsqrt[2] == math::rsqrt(im421[2]));
		test_assert(irsqrt[3] == math::rsqrt(im421[3]));
	}

	TEST_CASE(min)
	{
		const auto fmin = math::min(fm421, fm422);
		test_assert(fmin[0] == math::min(fm421[0], fm422[0]));
		test_assert(fmin[1] == math::min(fm421[1], fm422[1]));
		test_assert(fmin[2] == math::min(fm421[2], fm422[2]));
		test_assert(fmin[3] == math::min(fm421[3], fm422[3]));

		const auto imin = math::min(im421, im422);
		test_assert(imin[0] == math::min(im421[0], im422[0]));
		test_assert(imin[1] == math::min(im421[1], im422[1]));
		test_assert(imin[2] == math::min(im421[2], im422[2]));
		test_assert(imin[3] == math::min(im421[3], im422[3]));
	}

	TEST_CASE(max)
	{
		const auto fmax = math::max(fm421, fm422);
		test_assert(fmax[0] == math::max(fm421[0], fm422[0]));
		test_assert(fmax[1] == math::max(fm421[1], fm422[1]));
		test_assert(fmax[2] == math::max(fm421[2], fm422[2]));
		test_assert(fmax[3] == math::max(fm421[3], fm422[3]));

		const auto imax = math::max(im421, im422);
		test_assert(imax[0] == math::max(im421[0], im422[0]));
		test_assert(imax[1] == math::max(im421[1], im422[1]));
		test_assert(imax[2] == math::max(im421[2], im422[2]));
		test_assert(imax[3] == math::max(im421[3], im422[3]));
	}

	TEST_CASE(abs)
	{
		const auto fabs = math::abs(fm422);
		test_assert(fabs[0] == math::abs(fm422[0]));
		test_assert(fabs[1] == math::abs(fm422[1]));
		test_assert(fabs[2] == math::abs(fm422[2]));
		test_assert(fabs[3] == math::abs(fm422[3]));

		const auto iabs = math::abs(im422);
		test_assert(iabs[0] == math::abs(im422[0]));
		test_assert(iabs[1] == math::abs(im422[1]));
		test_assert(iabs[2] == math::abs(im422[2]));
		test_assert(iabs[3] == math::abs(im422[3]));

		const auto uabs = math::abs(um422);
		test_assert(uabs[0] == math::abs(um422[0]));
		test_assert(uabs[1] == math::abs(um422[1]));
		test_assert(uabs[2] == math::abs(um422[2]));
		test_assert(uabs[3] == math::abs(um422[3]));
	}
}
