//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

static_assert(sizeof(float) == 4, "float isn't 32-bit");

#include <cstdint>

#include "bool.hpp"

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

namespace tue {
  template<typename T, int N>
  class simd;

  using bool32x4 = simd<bool32, 4>;
  using float32x4 = simd<float, 4>;

  namespace detail_ {
    inline float binary_float(std::uint32_t value) noexcept {
      return reinterpret_cast<const float&>(value);
    }
  }
}

#if defined(TUE_SSE)
#include <xmmintrin.h>

namespace tue {
  namespace detail_ {
    inline __m128 binary_m128(std::uint32_t value) noexcept {
      return _mm_set_ps1(binary_float(value));
    }
  }
}

#include "detail_/bool32x4.sse.hpp"
#include "detail_/float32x4.sse.hpp"
#else
#include "detail_/bool32x4.fallback.hpp"
#include "detail_/float32x4.fallback.hpp"
#endif
