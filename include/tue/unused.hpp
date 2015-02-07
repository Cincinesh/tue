//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

// The Tuesday C++ math and template library.
namespace tue
{
  // Does absolutely nothing with the given arguments. This function is meant
  // to get rid of "unused variable" compiler and IDE warnings.
  template<typename... Args>
  inline void unused(Args&&...) noexcept {}
}
