//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../simd.hpp"

// SSE
#ifdef TUE_SSE
#include <cstdint>

namespace tue
{
    namespace detail_
    {
        inline float binary_float(std::uint32_t x) noexcept
        {
            return reinterpret_cast<const float&>(x);
        }
    }
}

#include "simd/sse/bool32x4.sse.hpp"
#include "simd/sse/float32x4.sse.hpp"

#ifdef TUE_SSE2

namespace tue
{
    namespace detail_
    {
        inline double binary_double(std::uint64_t x) noexcept
        {
            return reinterpret_cast<const double&>(x);
        }
    }
}

#include "simd/sse2/bool8x16.sse2.hpp"
#include "simd/sse2/bool16x8.sse2.hpp"
#include "simd/sse2/bool64x2.sse2.hpp"
#include "simd/sse2/float64x2.sse2.hpp"
#include "simd/sse2/int8x16.sse2.hpp"
#include "simd/sse2/int16x8.sse2.hpp"
#include "simd/sse2/int32x4.sse2.hpp"
#include "simd/sse2/int64x2.sse2.hpp"
#include "simd/sse2/uint8x16.sse2.hpp"
#include "simd/sse2/uint16x8.sse2.hpp"
#include "simd/sse2/uint32x4.sse2.hpp"
#include "simd/sse2/uint64x2.sse2.hpp"

#endif
#endif
