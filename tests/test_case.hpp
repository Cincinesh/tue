//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <map>
#include <string>
#include <vector>

namespace tue
{
	class test_case
	{
		friend class test_runner;

	public:
		using function_ptr_t = void(*)();

	private:
		static std::map<std::string, std::vector<const test_case*>>& global_collection_();

		std::string file_;

		int line_;

		std::string name_;

		function_ptr_t function_ptr_;

	public:
		test_case(
			const std::string& file,
			int line,
			const std::string& name,
			function_ptr_t function_ptr,
			bool should_add_to_global_collection = false);

		std::string file() const;

		int line() const;

		std::string name() const;

		function_ptr_t function_ptr() const;
		
		void run() const;

		static void throw_test_failure(
			const std::string& file,
			int line,
			const std::string& text);
	};

	bool operator==(const test_case& lhs, const test_case& rhs);

	bool operator!=(const test_case& lhs, const test_case& rhs);
}

#define TEST_CASE(name) \
namespace TEST_CASE_##name \
{ \
  void function_(); \
  ::tue::test_case TEST_CASE_##name( \
      __FILE__, __LINE__, "TEST_CASE("#name")", &function_, true); \
} \
void TEST_CASE_##name::function_()

#define test_assert(condition) static_cast<void>( \
	static_cast<bool>(condition) \
	|| (::tue::test_case::throw_test_failure( \
		__FILE__, __LINE__, "test_assert("#condition") failed"), 0))

#define test_fail(info) \
	::tue::test_case::throw_test_failure( \
		__FILE__, __LINE__, "test_fail("#info")")
