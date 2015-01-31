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

	const float f420 = -1.1f;
	const float f421 = 2.2f;
	const float f422 = 1.3f;
	const float f423 = 1.4f;

	const int f410i = reinterpret_cast<const int&>(f410);
	const int f411i = reinterpret_cast<const int&>(f411);
	const int f412i = reinterpret_cast<const int&>(f412);
	const int f413i = reinterpret_cast<const int&>(f413);

	const int f420i = reinterpret_cast<const int&>(f420);
	const int f421i = reinterpret_cast<const int&>(f421);
	const int f422i = reinterpret_cast<const int&>(f422);
	const int f423i = reinterpret_cast<const int&>(f423);

	const auto f41 = float32x4(f410, f411, f412, f413);
	const auto f42 = float32x4(f420, f421, f422, f423);

	bool equal(float32x4 v, float x, float y, float z, float w)
	{
		alignas(16) float input[4];
		v.store(input);
		return input[0] == x
			&& input[1] == y
			&& input[2] == z
			&& input[3] == w;
	}

	bool equal(float32x4 v, int x, int y, int z, int w)
	{
		alignas(16) int input[4];
		v.store(reinterpret_cast<float*>(input));
		return input[0] == x
			&& input[1] == y
			&& input[2] == z
			&& input[3] == w;
	}

	bool equal(float32x4 v, bool x, bool y, bool z, bool w)
	{
		alignas(16) int input[4];
		v.store(reinterpret_cast<float*>(input));
		return input[0] == (x == true ? ~0 : 0)
			&& input[1] == (y == true ? ~0 : 0)
			&& input[2] == (z == true ? ~0 : 0)
			&& input[3] == (w == true ? ~0 : 0);
	}

	bool bitwise_equal(float32x4 v1, float32x4 v2)
	{
		alignas(16) int input1[4], input2[4];
		v1.store(reinterpret_cast<float*>(input1));
		v2.store(reinterpret_cast<float*>(input2));
		return input1[0] == input2[0]
			&& input1[1] == input2[1]
			&& input1[2] == input2[2]
			&& input1[3] == input2[3];
	}

	bool nearly_equal(
		float32x4 v,
		float x, float y, float z, float w)
	{
		alignas(16) float input[4];
		v.store(input);
		return math::abs(input[0] - x) <= 0.001f
			&& math::abs(input[1] - y) <= 0.001f
			&& math::abs(input[2] - z) <= 0.001f
			&& math::abs(input[3] - w) <= 0.001f;
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
		alignas(16) const float array[4] = { 1.1f, 2.2f, 3.3f, 4.4f };
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
		alignas(16) float result[4];
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
		alignas(16) float result[4];
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

	TEST_CASE(equality_operator)
	{
		const float32x4 v1(1.1f, 2.2f, 3.3f, 4.4f);
		const float32x4 v2(1.1f, 2.2f, 3.3f, 4.4f);
		const float32x4 v3(0.0f, 2.2f, 3.3f, 4.4f);
		const float32x4 v4(1.1f, 0.0f, 3.3f, 4.4f);
		const float32x4 v5(1.1f, 2.2f, 0.0f, 4.4f);
		const float32x4 v6(1.1f, 2.2f, 3.3f, 0.0f);
		test_assert((v1 == v2) == true);
		test_assert((v1 == v3) == false);
		test_assert((v1 == v4) == false);
		test_assert((v1 == v5) == false);
		test_assert((v1 == v6) == false);
	}

	TEST_CASE(inequality_operator)
	{
		const float32x4 v1(1.1f, 2.2f, 3.3f, 4.4f);
		const float32x4 v2(1.1f, 2.2f, 3.3f, 4.4f);
		const float32x4 v3(0.0f, 2.2f, 3.3f, 4.4f);
		const float32x4 v4(1.1f, 0.0f, 3.3f, 4.4f);
		const float32x4 v5(1.1f, 2.2f, 0.0f, 4.4f);
		const float32x4 v6(1.1f, 2.2f, 3.3f, 0.0f);
		test_assert((v1 != v2) == false);
		test_assert((v1 != v3) == true);
		test_assert((v1 != v4) == true);
		test_assert((v1 != v5) == true);
		test_assert((v1 != v6) == true);
	}

	TEST_CASE(sincos)
	{
		float32x4 sin_result, cos_result;
		math::sincos(f41, sin_result, cos_result);
		test_assert(nearly_equal(sin_result,
			math::sin(f410),
			math::sin(f411),
			math::sin(f412),
			math::sin(f413)));
		test_assert(nearly_equal(cos_result,
			math::cos(f410),
			math::cos(f411),
			math::cos(f412),
			math::cos(f413)));
	}

	TEST_CASE(sin)
	{
		test_assert(nearly_equal(math::sin(f41),
			math::sin(f410),
			math::sin(f411),
			math::sin(f412),
			math::sin(f413)));
	}

	TEST_CASE(cos)
	{
		test_assert(nearly_equal(math::cos(f41),
			math::cos(f410),
			math::cos(f411),
			math::cos(f412),
			math::cos(f413)));
	}

	TEST_CASE(recip)
	{
		test_assert(nearly_equal(math::recip(f41),
			math::recip(f410),
			math::recip(f411),
			math::recip(f412),
			math::recip(f413)));
	}

	TEST_CASE(sqrt)
	{
		test_assert(nearly_equal(math::sqrt(f41),
			math::sqrt(f410),
			math::sqrt(f411),
			math::sqrt(f412),
			math::sqrt(f413)));
	}

	TEST_CASE(rsqrt)
	{
		test_assert(nearly_equal(math::rsqrt(f41),
			math::rsqrt(f410),
			math::rsqrt(f411),
			math::rsqrt(f412),
			math::rsqrt(f413)));
	}

	TEST_CASE(min)
	{
		test_assert(equal(math::min(f41, f42),
			math::min(f410, f420),
			math::min(f411, f421),
			math::min(f412, f422),
			math::min(f413, f423)));
	}

	TEST_CASE(max)
	{
		test_assert(equal(math::max(f41, f42),
			math::max(f410, f420),
			math::max(f411, f421),
			math::max(f412, f422),
			math::max(f413, f423)));
	}

	TEST_CASE(abs)
	{
		test_assert(equal(math::abs(f42),
			math::abs(f420),
			math::abs(f421),
			math::abs(f422),
			math::abs(f423)));
	}

	TEST_CASE(dot)
	{
		test_assert(math::dot(f41, f42) == f41 * f42);
	}

	TEST_CASE(length2)
	{
		test_assert(math::length2(f42) == f42 * f42);
	}

	TEST_CASE(length)
	{
		test_assert(math::length(f42)
			== math::sqrt(math::length2(f42)));
	}

	TEST_CASE(normalize)
	{
		test_assert(math::normalize(f42)
			== f42 / math::length(f42));
	}

	TEST_CASE(isless)
	{
		test_assert(equal(math::isless(f41, f42),
			f410 < f420,
			f411 < f421,
			f412 < f422,
			f413 < f423));
	}

	TEST_CASE(islessequal)
	{
		test_assert(equal(math::islessequal(f41, f42),
			f410 <= f420,
			f411 <= f421,
			f412 <= f422,
			f413 <= f423));
	}

	TEST_CASE(isgreater)
	{
		test_assert(equal(math::isgreater(f41, f42),
			f410 > f420,
			f411 > f421,
			f412 > f422,
			f413 > f423));
	}

	TEST_CASE(isgreaterequal)
	{
		test_assert(equal(math::isgreaterequal(f41, f42),
			f410 >= f420,
			f411 >= f421,
			f412 >= f422,
			f413 >= f423));
	}

	TEST_CASE(isequal)
	{
		test_assert(equal(math::isequal(f41, f42),
			f410 == f420,
			f411 == f421,
			f412 == f422,
			f413 == f423));
	}

	TEST_CASE(isnotequal)
	{
		test_assert(equal(math::isnotequal(f41, f42),
			f410 != f420,
			f411 != f421,
			f412 != f422,
			f413 != f423));
	}
}
