//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "test_failure.hpp"

using namespace std;

namespace tue
{
	test_failure::test_failure(const string& file, int line, const string& text) :
		file_(file),
		line_(line),
		text_(text)
	{
	}

	string test_failure::file() const
	{
		return file_;
	}

	int test_failure::line() const noexcept
	{
		return line_;
	}

	string test_failure::text() const
	{
		return text_;
	}

	bool operator==(const test_failure& lhs, const test_failure& rhs) noexcept
	{
		return lhs.file() == rhs.file()
			&& lhs.line() == rhs.line()
			&& lhs.text() == rhs.text();
	}

	bool operator!=(const test_failure& lhs, const test_failure& rhs) noexcept
	{
		return !operator==(lhs, rhs);
	}
}
