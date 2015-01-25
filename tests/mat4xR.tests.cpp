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
}
