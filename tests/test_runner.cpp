//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "test_runner.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

#include "test_case.hpp"
#include "test_failure.hpp"

using namespace std;

namespace tue
{
	int test_runner::run_all()
	{
		int status = EXIT_SUCCESS;

		for (const auto& entry : test_case::global_collection_())
		{
			const auto& file = entry.first;
			const auto& tcases = entry.second;

			cout << "Running test cases in " << file << endl;
			for (const auto& tcase : tcases)
			{
				cout << "  " << tcase->name() << "..." << endl;
				cout.flush();

				bool success = false;
				try
				{
					tcase->run();
					success = true;
				}
				catch (const test_failure& f)
				{
					cerr << f.file() << "(" << f.line() << "): error: "
						<< f.text() << endl;
				}
				catch (const exception& e)
				{
					cerr << tcase->file() << "(" << tcase->line() << "): error: "
						<< tcase->name() << " threw an exception: "
						<< e.what() << endl;
				}
				catch (...)
				{
					cerr << tcase->file() << "(" << tcase->line() << "): error: "
						<< tcase->name() << " threw a non-standard exception" << endl;
				}

				if (success)
				{
					cout << "  success" << endl;
				}
				else
				{
					cout << "  failure" << endl;
					status = EXIT_FAILURE;
				}
			}
		}

		return status;
	}
}
