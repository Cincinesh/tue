//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/math.hpp>
#include "test_case.hpp"

#include <cmath>

namespace
{
	using namespace tue;

	TEST_CASE(sincos)
	{
		float fsin, fcos;
		math::sincos(1.23f, fsin, fcos);
		test_assert(fsin == math::sin(1.23f));
		test_assert(fcos == math::cos(1.23f));

		double isin, icos;
		math::sincos(123, isin, icos);
		test_assert(isin == math::sin(123));
		test_assert(icos == math::cos(123));
	}

	TEST_CASE(sin)
	{
		test_assert(math::sin(1.23f) == std::sin(1.23f));
		test_assert(math::sin(123) == std::sin(123));
	}

	TEST_CASE(cos)
	{
		test_assert(math::cos(1.23f) == std::cos(1.23f));
		test_assert(math::cos(123) == std::cos(123));
	}

	TEST_CASE(pow)
	{
		test_assert(math::pow(1.23f, 4.56f) == std::pow(1.23f, 4.56f));
		test_assert(math::pow(123, 456) == std::pow(123, 456));
	}

	TEST_CASE(rcp)
	{
		test_assert(math::rcp(1.23f) == 1 / 1.23f);
		test_assert(math::rcp(123) == 1 / 123.0);
	}

	TEST_CASE(sqrt)
	{
		test_assert(math::sqrt(1.23f) == std::sqrt(1.23f));
		test_assert(math::sqrt(123) == std::sqrt(123));
	}

	TEST_CASE(rsqrt)
	{
		test_assert(math::rsqrt(1.23f) == 1 / std::sqrt(1.23f));
		test_assert(math::rsqrt(123) == 1 / std::sqrt(123));
	}

	TEST_CASE(min)
	{
		test_assert(math::min(1.23f, 4.56f) == 1.23f);
		test_assert(math::min(1.23f, -4.56f) == -4.56f);
		test_assert(math::min(123, 456) == 123);
		test_assert(math::min(123, -456) == -456);
	}

	TEST_CASE(max)
	{
		test_assert(math::max(1.23f, 4.56f) == 4.56f);
		test_assert(math::max(1.23f, -4.56f) == 1.23f);
		test_assert(math::max(123, 456) == 456);
		test_assert(math::max(123, -456) == 123);
	}

	TEST_CASE(abs)
	{
		test_assert(math::abs(-1.23f) == 1.23f);
		test_assert(math::abs(1.23f) == 1.23f);
		test_assert(math::abs(-123) == 123);
		test_assert(math::abs(123) == 123);
		test_assert(math::abs(123U) == 123U);
	}
}
