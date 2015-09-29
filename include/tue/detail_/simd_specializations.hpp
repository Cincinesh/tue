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
        float binary_float(std::uint32_t x) noexcept
        {
            return reinterpret_cast<const float&>(x);
        }
    }
}

#include "simd/sse/bool32x4.sse.hpp"
#include "simd/sse/float32x4.sse.hpp"
#endif
