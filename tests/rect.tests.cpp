//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/rect.hpp>
#include "test_case.hpp"

#include <tue/size2d.hpp>
#include <tue/unused.hpp>
#include <tue/vec.hpp>

namespace
{
	using namespace tue;

	TEST_CASE(default_constructor)
	{
		frect r;
		unused(r);
	}

	TEST_CASE(x_y_width_height_component_constructor)
	{
		constexpr rect<float, int> r(1.1f, 2.2f, 3, 4);
		test_assert(r.x() == 1.1f);
		test_assert(r.y() == 2.2f);
		test_assert(r.width() == 3);
		test_assert(r.height() == 4);
	}

	TEST_CASE(x_y_size_component_constructor)
	{
		constexpr rect<float, int> r(1.1f, 2.2f, isize2d(3, 4));
		test_assert(r.x() == 1.1f);
		test_assert(r.y() == 2.2f);
		test_assert(r.width() == 3);
		test_assert(r.height() == 4);
	}

	TEST_CASE(position_width_height_component_constructor)
	{
		constexpr rect<float, int> r(fvec2(1.1f, 2.2f), 3, 4);
		test_assert(r.x() == 1.1f);
		test_assert(r.y() == 2.2f);
		test_assert(r.width() == 3);
		test_assert(r.height() == 4);
	}

	TEST_CASE(position_size_component_constructor)
	{
		constexpr rect<float, int> r(fvec2(1.1f, 2.2f), isize2d(3, 4));
		test_assert(r.x() == 1.1f);
		test_assert(r.y() == 2.2f);
		test_assert(r.width() == 3);
		test_assert(r.height() == 4);
	}

	TEST_CASE(explicit_conversion_constructor)
	{
		constexpr rect<float, double> fdr(1.1f, 2.2f, 3.3, 4.4);
		CONST_OR_CONSTEXPR iurect iur(fdr);
		test_assert(iur.x() == static_cast<int>(1.1f));
		test_assert(iur.y() == static_cast<int>(2.2f));
		test_assert(iur.width() == static_cast<unsigned int>(3.3));
		test_assert(iur.height() == static_cast<unsigned int>(4.4));
	}

	TEST_CASE(implicit_conversion_operator)
	{
		constexpr iurect iur(1, 2, 3U, 4U);
		constexpr rect<float, double> fdr = iur;
		test_assert(fdr.x() == static_cast<float>(1));
		test_assert(fdr.y() == static_cast<float>(2));
		test_assert(fdr.width() == static_cast<double>(3U));
		test_assert(fdr.height() == static_cast<double>(4U));
	}

	TEST_CASE(position)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR ivec2 position = r.position();
		test_assert(position.x() == 1);
		test_assert(position.y() == 2);
	}

	TEST_CASE(set_position)
	{
		rect<int, float> r1(1, 2, 3.3f, 4.4f);
		r1.set_position(5, 6);
		test_assert(r1.x() == 5);
		test_assert(r1.y() == 6);
		test_assert(r1.width() == 3.3f);
		test_assert(r1.height() == 4.4f);

		rect<double, unsigned int> r2(1.1, 2.2, 3U, 4U);
		r2.set_position(dvec2(5.5, 6.6));
		test_assert(r2.x() == 5.5);
		test_assert(r2.y() == 6.6);
		test_assert(r2.width() == 3U);
		test_assert(r2.height() == 4U);
	}

	TEST_CASE(x)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR int x = r.x();
		test_assert(x == 1);
	}

	TEST_CASE(set_x)
	{
		rect<int, float> r1(1, 2, 3.3f, 4.4f);
		r1.set_x(5);
		test_assert(r1.x() == 5);
		test_assert(r1.y() == 2);
		test_assert(r1.width() == 3.3f);
		test_assert(r1.height() == 4.4f);
	}

	TEST_CASE(y)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR int y = r.y();
		test_assert(y == 2);
	}

	TEST_CASE(set_y)
	{
		rect<int, float> r(1, 2, 3.3f, 4.4f);
		r.set_y(6);
		test_assert(r.x() == 1);
		test_assert(r.y() == 6);
		test_assert(r.width() == 3.3f);
		test_assert(r.height() == 4.4f);
	}





	TEST_CASE(size)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR usize2d size = r.size();
		test_assert(size.width() == 3U);
		test_assert(size.height() == 4U);
	}

	TEST_CASE(set_size)
	{
		rect<int, float> r1(1, 2, 3.3f, 4.4f);
		r1.set_size(5.5f, 6.6);
		test_assert(r1.x() == 1);
		test_assert(r1.y() == 2);
		test_assert(r1.width() == 5.5f);
		test_assert(r1.height() == 6.6f);

		rect<double, unsigned int> r2(1.1, 2.2, 3U, 4U);
		r2.set_size(usize2d(5U, 6U));
		test_assert(r2.x() == 1.1);
		test_assert(r2.y() == 2.2);
		test_assert(r2.width() == 5U);
		test_assert(r2.height() == 6U);
	}

	TEST_CASE(width)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR unsigned int width = r.width();
		test_assert(width == 3U);
	}

	TEST_CASE(set_width)
	{
		rect<int, float> r1(1, 2, 3.3f, 4.4f);
		r1.set_width(5.5f);
		test_assert(r1.x() == 1);
		test_assert(r1.y() == 2);
		test_assert(r1.width() == 5.5f);
		test_assert(r1.height() == 4.4f);
	}

	TEST_CASE(height)
	{
		constexpr iurect r(1, 2, 3U, 4U);
		CONST_OR_CONSTEXPR unsigned int height = r.height();
		test_assert(height == 4U);
	}

	TEST_CASE(set_height)
	{
		rect<int, float> r(1, 2, 3.3f, 4.4f);
		r.set_height(6.6f);
		test_assert(r.x() == 1);
		test_assert(r.y() == 2);
		test_assert(r.width() == 3.3f);
		test_assert(r.height() == 6.6f);
	}

	TEST_CASE(equality_operator)
	{
		constexpr rect<float, double> r1(1.0f, 2.0f, 3.0f, 4.0f);
		constexpr iurect r2(1, 2, 3U, 4U);
		constexpr iurect r3(0, 2, 3U, 4U);
		constexpr iurect r4(1, 0, 3U, 4U);
		constexpr iurect r5(1, 2, 0U, 4U);
		constexpr iurect r6(1, 2, 3U, 0U);
		CONST_OR_CONSTEXPR bool result1 = (r1 == r2);
		CONST_OR_CONSTEXPR bool result2 = (r1 == r3);
		CONST_OR_CONSTEXPR bool result3 = (r1 == r4);
		CONST_OR_CONSTEXPR bool result4 = (r1 == r5);
		CONST_OR_CONSTEXPR bool result5 = (r1 == r6);
		test_assert(result1 == true);
		test_assert(result2 == false);
		test_assert(result3 == false);
		test_assert(result4 == false);
		test_assert(result5 == false);
	}

	TEST_CASE(inequality_operator)
	{
		constexpr rect<float, double> r1(1.0f, 2.0f, 3.0f, 4.0f);
		constexpr iurect r2(1, 2, 3U, 4U);
		constexpr iurect r3(0, 2, 3U, 4U);
		constexpr iurect r4(1, 0, 3U, 4U);
		constexpr iurect r5(1, 2, 0U, 4U);
		constexpr iurect r6(1, 2, 3U, 0U);
		CONST_OR_CONSTEXPR bool result1 = (r1 != r2);
		CONST_OR_CONSTEXPR bool result2 = (r1 != r3);
		CONST_OR_CONSTEXPR bool result3 = (r1 != r4);
		CONST_OR_CONSTEXPR bool result4 = (r1 != r5);
		CONST_OR_CONSTEXPR bool result5 = (r1 != r6);
		test_assert(result1 == false);
		test_assert(result2 == true);
		test_assert(result3 == true);
		test_assert(result4 == true);
		test_assert(result5 == true);
	}
}
