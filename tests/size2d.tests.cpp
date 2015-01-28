//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/size2d.hpp>
#include "test_case.hpp"

#include <tue/unused.hpp>

namespace
{
	using namespace tue;

	TEST_CASE(default_constructor)
	{
		fsize2d size;
		unused(size);
	}

	TEST_CASE(component_constructor)
	{
		constexpr fsize2d size(1.1f, 2.2f);
		test_assert(size.width() == 1.1f);
		test_assert(size.height() == 2.2f);
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr dsize2d dsize(1.1, 2.2);
		CONST_OR_CONSTEXPR fsize2d fsize(dsize);
		test_assert(fsize.width() == static_cast<float>(dsize.width()));
		test_assert(fsize.height() == static_cast<float>(dsize.height()));
	}

	TEST_CASE(implicit_conversion_operator)
	{
		constexpr fsize2d fsize(1.1f, 2.2f);
		CONST_OR_CONSTEXPR dsize2d dsize = fsize;
		test_assert(dsize.width() == static_cast<double>(fsize.width()));
		test_assert(dsize.height() == static_cast<double>(fsize.height()));
	}

	TEST_CASE(width)
	{
		constexpr fsize2d size(1.1f, 2.2f);
		CONST_OR_CONSTEXPR float width = size.width();
		test_assert(width == 1.1f);
	}

	TEST_CASE(set_width)
	{
		fsize2d size(1.1f, 2.2f);
		size.set_width(3.3f);
		test_assert(size.width() == 3.3f);
		test_assert(size.height() == 2.2f);
	}

	TEST_CASE(height)
	{
		constexpr fsize2d size(1.1f, 2.2f);
		CONST_OR_CONSTEXPR float height = size.height();
		test_assert(height == 2.2f);
	}

	TEST_CASE(set_height)
	{
		fsize2d size(1.1f, 2.2f);
		size.set_height(3.3f);
		test_assert(size.width() == 1.1f);
		test_assert(size.height() == 3.3f);
	}
}
