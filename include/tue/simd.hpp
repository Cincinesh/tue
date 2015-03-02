//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if defined(__SSE__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 1) \
    || defined(_M_X64)
  #define TUE_SSE
#endif

#if defined(__SSE2__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 2) \
    || defined(_M_X64)
  #define TUE_SSE2
#endif

#if defined(__ARM_NEON__)
  #define TUE_NEON
#endif

#if defined(TUE_SSE)
#include "detail_/float32x4.sse.hpp"
#elif defined(TUE_NEON)
#include "detail_/float32x4.neon.hpp"
#else
#include "detail_/float32x4.fallback.hpp"
#endif
