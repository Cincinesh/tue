//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "test_case.hpp"

#include <tuple>
#include <utility>

#include "test_failure.hpp"

using namespace std;

namespace tue
{
	map<string, vector<const test_case*>>& test_case::global_collection_()
	{
		static map<string, vector<const test_case*>> value;
		return value;
	}

	test_case::test_case(
		const string& file,
		int line,
		const string& name,
		function_ptr_t function_ptr,
		bool should_add_to_global_collection) :
		file_(file),
		line_(line),
		name_(name),
		function_ptr_(function_ptr)
	{
		if (should_add_to_global_collection)
		{
			const auto emplace_result = global_collection_().emplace(
				piecewise_construct,
				forward_as_tuple(file),
				forward_as_tuple());

			auto& tcases = emplace_result.first->second;
			tcases.push_back(this);
		}
	}

	string test_case::file() const
	{
		return file_;
	}

	int test_case::line() const
	{
		return line_;
	}

	string test_case::name() const
	{
		return name_;
	}

	test_case::function_ptr_t test_case::function_ptr() const
	{
		return function_ptr_;
	}

	void test_case::run() const
	{
		function_ptr_();
	}

	void test_case::throw_test_failure(
		const string& file,
		int line,
		const string& text)
	{
		throw test_failure(file, line, text);
	}

	bool operator==(const test_case& lhs, const test_case& rhs)
	{
		return lhs.file() == rhs.file()
			&& lhs.line() == rhs.line()
			&& lhs.name() == rhs.name()
			&& lhs.function_ptr() == rhs.function_ptr();
	}

	bool operator!=(const test_case& lhs, const test_case& rhs)
	{
		return !operator==(lhs, rhs);
	}
}
