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

	TEST_CASE(default_constructor)
	{
		float32x4 v;
		unused(v);
	}
}
