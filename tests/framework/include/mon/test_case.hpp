//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <map>
#include <string>
#include <vector>

namespace mon
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
}

#ifdef _MSC_VER
#define CONST_OR_CONSTEXPR const
#else
#define CONST_OR_CONSTEXPR constexpr
#endif

#define TEST_CASE(name) \
namespace TEST_CASE_##name \
{ \
  void function_(); \
  ::mon::test_case TEST_CASE_##name( \
      __FILE__, __LINE__, "TEST_CASE("#name")", &function_, true); \
} \
void TEST_CASE_##name::function_()

#define test_assert(condition) static_cast<void>( \
	static_cast<bool>(condition) \
	|| (::mon::test_case::throw_test_failure( \
		__FILE__, __LINE__, "test_assert("#condition") failed"), 0))

#define test_fail(info) \
	::mon::test_case::throw_test_failure( \
		__FILE__, __LINE__, "test_fail("#info")")
