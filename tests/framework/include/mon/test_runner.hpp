//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace mon
{
	class test_runner
	{
		test_runner() = delete;
		test_runner(const test_runner&) = delete;
		~test_runner() = delete;
		test_runner& operator=(const test_runner&) = delete;

	public:
		static int run_all();
	};
}
