//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <string>

namespace tue
{
	class test_failure
	{
	private:
		std::string file_;

		int line_;

		std::string text_;

	public:
		test_failure(const std::string& file, int line, const std::string& text);

		std::string file() const;

		int line() const noexcept;

		std::string text() const;
	};

	bool operator==(const test_failure& lhs, const test_failure& rhs) noexcept;

	bool operator!=(const test_failure& lhs, const test_failure& rhs) noexcept;
}
