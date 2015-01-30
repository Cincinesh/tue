//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/float32x4.hpp>
#include "test_case.hpp"

#include <tue/math.hpp>
#include <tue/unused.hpp>

namespace
{
	using namespace tue;

	const float f410 = 1.1f;
	const float f411 = 1.2f;
	const float f412 = 1.3f;
	const float f413 = 1.4f;

	const float f420 = 2.2f;
	const float f421 = 2.4f;
	const float f422 = 2.6f;
	const float f423 = 2.8f;

	const int f410i = reinterpret_cast<const int&>(f410);
	const int f411i = reinterpret_cast<const int&>(f411);
	const int f412i = reinterpret_cast<const int&>(f412);
	const int f413i = reinterpret_cast<const int&>(f413);

	const int f420i = reinterpret_cast<const int&>(f420);
	const int f421i = reinterpret_cast<const int&>(f421);
	const int f422i = reinterpret_cast<const int&>(f422);
	const int f423i = reinterpret_cast<const int&>(f423);

	const float32x4 f41(f410, f411, f412, f413);
	const float32x4 f42(f420, f421, f422, f423);

	bool equal(float32x4 v, float x, float y, float z, float w)
	{
		float input[4];
		v.store(input);
		return input[0] == x
			&& input[1] == y
			&& input[2] == z
			&& input[3] == w;
	}

	bool equal(float32x4 v, int x, int y, int z, int w)
	{
		int input[4];
		v.store(reinterpret_cast<float*>(input));
		return input[0] == x
			&& input[1] == y
			&& input[2] == z
			&& input[3] == w;
	}

	bool bitwise_equal(float32x4 v1, float32x4 v2)
	{
		int input1[4], input2[4];
		v1.store(reinterpret_cast<float*>(input1));
		v2.store(reinterpret_cast<float*>(input2));
		return input1[0] == input2[0]
				&& input1[1] == input2[1]
				&& input1[2] == input2[2]
				&& input1[3] == input2[3];
	}

	TEST_CASE(default_constructor)
	{
		float32x4 v;
		unused(v);
	}

	TEST_CASE(scalar_constructor)
	{
		const float32x4 v(1.1f);
		test_assert(equal(v, 1.1f, 1.1f, 1.1f, 1.1f));
	}

	TEST_CASE(component_constructor)
	{
		const float32x4 v = { 1.1f, 2.2f, 3.3f, 4.4f };
		test_assert(equal(v, 1.1f, 2.2f, 3.3f, 4.4f));
	}

	TEST_CASE(component_array_constructor)
	{
		const float array[4] = { 1.1f, 2.2f, 3.3f, 4.4f };
		const float32x4 v(array);
		test_assert(equal(v, 1.1f, 2.2f, 3.3f, 4.4f));
	}

#ifdef __SSE__
	TEST_CASE(underlying_converison_constructor)
	{
		const __m128 underlying = _mm_setr_ps(1.1f, 2.2f, 3.3f, 4.4f);
		const float32x4 v(underlying);
		test_assert(equal(v, 1.1f, 2.2f, 3.3f, 4.4f));
	}

	TEST_CASE(underlying_converison_operator)
	{
		const __m128 underlying = f41;
		float result[4];
		_mm_store_ps(result, underlying);
		test_assert(result[0] == f410);
		test_assert(result[1] == f411);
		test_assert(result[2] == f412);
		test_assert(result[3] == f413);
	}
#endif

	TEST_CASE(zero)
	{
		const auto v = float32x4::zero();
		test_assert(equal(v, 0.0f, 0.0f, 0.0f, 0.0f));
	}

	TEST_CASE(store)
	{
		const float32x4 v(1.1f, 2.2f, 3.3f, 4.4f);
		float result[4];
		v.store(result);
		test_assert(result[0] == 1.1f);
		test_assert(result[1] == 2.2f);
		test_assert(result[2] == 3.3f);
		test_assert(result[3] == 4.4f);
	}

	TEST_CASE(unary_plus_operator)
	{
		const float32x4 v = +f41;
		test_assert(equal(v, +f410, +f411, +f412, +f413));
	}

	TEST_CASE(unary_minus_operator)
	{
		const float32x4 v = -f41;
		test_assert(equal(v, -f410, -f411, -f412, -f413));
	}

	TEST_CASE(bitwise_not_operator)
	{
		const float32x4 v = ~f41;
		test_assert(equal(v, ~f410i, ~f411i, ~f412i, ~f413i));
	}

	TEST_CASE(addition_operator)
	{
		const float32x4 v = f41 + f42;
		test_assert(equal(v,
			f410 + f420,
			f411 + f421,
			f412 + f422,
			f413 + f423));
	}

	TEST_CASE(subtraction_operator)
	{
		const float32x4 v = f41 - f42;
		test_assert(equal(v,
			f410 - f420,
			f411 - f421,
			f412 - f422,
			f413 - f423));
	}

	TEST_CASE(multiplication_operator)
	{
		const float32x4 v = f41 * f42;
		test_assert(equal(v,
			f410 * f420,
			f411 * f421,
			f412 * f422,
			f413 * f423));
	}

	TEST_CASE(division_operator)
	{
		const float32x4 v = f41 / f42;
		test_assert(equal(v,
			f410 / f420,
			f411 / f421,
			f412 / f422,
			f413 / f423));
	}

	TEST_CASE(bitwise_and_operator)
	{
		const float32x4 v = f41 & f42;
		test_assert(equal(v,
			f410i & f420i,
			f411i & f421i,
			f412i & f422i,
			f413i & f423i));
	}

	TEST_CASE(bitwise_or_operator)
	{
		const float32x4 v = f41 | f42;
		test_assert(equal(v,
			f410i | f420i,
			f411i | f421i,
			f412i | f422i,
			f413i | f423i));
	}

	TEST_CASE(bitwise_xor_operator)
	{
		const float32x4 v = f41 ^ f42;
		test_assert(equal(v,
			f410i ^ f420i,
			f411i ^ f421i,
			f412i ^ f422i,
			f413i ^ f423i));
	}

	TEST_CASE(pre_increment_operator)
	{
		float32x4 v = f41;
		test_assert(&(++v) == &v);
		test_assert(v == f41 + float32x4(1.0f));
	}

	TEST_CASE(pre_decrement_operator)
	{
		float32x4 v = f41;
		test_assert(&(--v) == &v);
		test_assert(v == f41 - float32x4(1.0f));
	}

	TEST_CASE(post_increment_operator)
	{
		float32x4 v = f41;
		test_assert(v++ == f41);
		test_assert(v == f41 + float32x4(1.0f));
	}

	TEST_CASE(post_decrement_operator)
	{
		float32x4 v = f41;
		test_assert(v-- == f41);
		test_assert(v == f41 - float32x4(1.0f));
	}

	TEST_CASE(addition_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v += f42) == &v);
		test_assert(v == f41 + f42);
	}

	TEST_CASE(subtraction_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v -= f42) == &v);
		test_assert(v == f41 - f42);
	}

	TEST_CASE(multiplication_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v *= f42) == &v);
		test_assert(v == f41 * f42);
	}

	TEST_CASE(division_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v /= f42) == &v);
		test_assert(v == f41 / f42);
	}

	TEST_CASE(bitwise_and_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v &= f42) == &v);
		test_assert(bitwise_equal(v, f41 & f42));
	}

	TEST_CASE(bitwise_or_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v ^= f42) == &v);
		test_assert(bitwise_equal(v, f41 ^ f42));
	}

	TEST_CASE(bitwise_xor_assignment_operator)
	{
		float32x4 v = f41;
		test_assert(&(v ^= f42) == &v);
		test_assert(bitwise_equal(v, f41 ^ f42));
	}
}
