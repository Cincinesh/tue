//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "detail_/simd.hpp"

#ifdef __SSE__
#include "detail_/float32x4.sse.hpp"
#else
#include "detail_/float32x4.fallback.hpp"
#endif
