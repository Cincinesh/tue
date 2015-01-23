//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "vec.hpp"
#include "test_case.hpp"

#include "unused.hpp"

#ifdef _MSC_VER
#define CONST_OR_CONSTEXPR const
#else
#define CONST_OR_CONSTEXPR constexpr
#endif

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

	TEST_CASE(explicit_cast_constructor)
	{
		constexpr dvec4 dv(1.1, 2.2, 3.3, 4.4);
		
		constexpr fvec4 fv1(dv);
		test_assert(fv1[0] == float(1.1));
		test_assert(fv1[1] == float(2.2));
		test_assert(fv1[2] == float(3.3));
		test_assert(fv1[3] == float(4.4));

		CONST_OR_CONSTEXPR auto fv2 = static_cast<fvec4>(dv);
		test_assert(fv2[0] == float(1.1));
		test_assert(fv2[1] == float(2.2));
		test_assert(fv2[2] == float(3.3));
		test_assert(fv2[3] == float(4.4));
	}

	TEST_CASE(implicit_cast_operator)
	{
		constexpr fvec4 fv(1.1f, 2.2f, 3.3f, 4.4f);
		CONST_OR_CONSTEXPR dvec4 dv = fv;
		test_assert(dv[0] == double(1.1f));
		test_assert(dv[1] == double(2.2f));
		test_assert(dv[2] == double(3.3f));
		test_assert(dv[3] == double(4.4f));
	}
}
