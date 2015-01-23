//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "vec.hpp"
#include "test_case.hpp"

#include "unused.hpp"

namespace
{
	using namespace tue;

	TEST_CASE(default_constructor)
	{
		fvec4 v;
		unused(v);
	}

	TEST_CASE(component_constructor)
	{
		constexpr fvec4 v = { 1.1f, 2.2f, 3.3f, 4.4f };
		test_assert(v[0] == 1.1f);
		test_assert(v[1] == 2.2f);
		test_assert(v[2] == 3.3f);
		test_assert(v[3] == 4.4f);
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
		constexpr dvec4 dv(1.1, 2.2, 3.3, 4.4);
		constexpr fvec4 fv(dv);
		test_assert(fv[0] == float(1.1));
		test_assert(fv[1] == float(2.2));
		test_assert(fv[2] == float(3.3));
		test_assert(fv[3] == float(4.4));
	}

	TEST_CASE(implicit_cast_operator)
	{
		constexpr fvec4 fv(1.1f, 2.2f, 3.3f, 4.4f);
#if defined(_MSC_VER) && (_MSC_VER <= 1900)
		const dvec4 dv = fv;
#else
		constexpr dvec4 dv = fv;
#endif
		test_assert(dv[0] == double(1.1f));
		test_assert(dv[1] == double(2.2f));
		test_assert(dv[2] == double(3.3f));
		test_assert(dv[3] == double(4.4f));
	}
}
