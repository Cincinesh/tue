//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

/*#if defined(__SSE__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 1) \
    || defined(_M_X64)
#define TUE_SSE
#endif

#if defined(__SSE2__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 2) \
    || defined(_M_X64)
#define TUE_SSE2
#endif*/

#if defined(__ARM_NEON__)
#define TUE_NEON
#endif

#if defined(TUE_SSE)
#include <cstdint>
#include <xmmintrin.h>

namespace tue {
  namespace detail_ {
    inline __m128 binary_m128(std::uint32_t value) noexcept {
      return _mm_load1_ps(reinterpret_cast<const float*>(&value));
    }
  }
}

#include "detail_/boolx4.sse.hpp"
#include "detail_/floatx4.sse.hpp"
#elif defined(TUE_NEON)
#include "detail_/float32x4.neon.hpp"
#else
#include "detail_/boolx4.fallback.hpp"
#include "detail_/floatx4.fallback.hpp"
#endif
