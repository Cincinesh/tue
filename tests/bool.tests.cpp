//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/bool.hpp>
#include <mon/test_case.hpp>

namespace {
using namespace tue;

TEST_CASE(bool8) {
  test_assert(sizeof(bool8) == 1);
  test_assert(sizeof(true8) == 1);
  test_assert(sizeof(false8) == 1);
  test_assert(false8 == 0);
  test_assert(true8 == static_cast<bool8>(~false8));

  if (!true8 || false8) {
    test_fail("bool8 didn't convert to a bool correctly");
  }
}

TEST_CASE(bool16) {
  test_assert(sizeof(bool16) == 2);
  test_assert(sizeof(true16) == 2);
  test_assert(sizeof(false16) == 2);
  test_assert(false16 == 0);
  test_assert(true16 == static_cast<bool16>(~false16));

  if (!true16 || false16) {
	test_fail("bool16 didn't convert to a bool correctly");
  }
}

TEST_CASE(bool32) {
  test_assert(sizeof(bool32) == 4);
  test_assert(sizeof(true32) == 4);
  test_assert(sizeof(false32) == 4);
  test_assert(false32 == 0);
  test_assert(true32 == static_cast<bool32>(~false32));

  if (!true32 || false32) {
	test_fail("bool32 didn't convert to a bool correctly");
  }
}

TEST_CASE(bool64) {
  test_assert(sizeof(bool64) == 8);
  test_assert(sizeof(true64) == 8);
  test_assert(sizeof(false64) == 8);
  test_assert(false64 == 0);
  test_assert(true64 == static_cast<bool64>(~false64));

  if (!true64 || false64) {
	test_fail("bool64 didn't convert to a bool correctly");
  }
}

}
