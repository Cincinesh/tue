//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <xmmintrin.h>

#include <type_traits>

#include "../../../simd.hpp"
#include "../../../sized_bool.hpp"

#ifdef TUE_SSE2
#include <emmintrin.h>
#endif

namespace tue
{
    template<>
    class alignas(tue::detail_::alignof_simd<bool32, 4>())
    simd<bool32, 4>
    {
        __m128 underlying_;

    private:
        template<typename U>
        static bool32x4 explicit_cast(const simd<U, 4>& s) noexcept
        {
            return {
                bool32(s.data()[0]),
                bool32(s.data()[1]),
                bool32(s.data()[2]),
                bool32(s.data()[3]),
            };
        }

    public:
        using component_type = bool32;

        static constexpr int component_count = 4;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(bool32 x) noexcept
        :
            underlying_(_mm_set_ps1(tue::detail_::binary_float(x)))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 2>>
        inline simd(
            bool32 x, bool32 y) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 4>>
        inline simd(
            bool32 x, bool32 y, bool32 z, bool32 w) noexcept
        :
            underlying_(_mm_setr_ps(
                tue::detail_::binary_float(x),
                tue::detail_::binary_float(y),
                tue::detail_::binary_float(z),
                tue::detail_::binary_float(w)))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 8>>
        inline simd(
            bool32 s0, bool32 s1, bool32 s2, bool32 s3,
            bool32 s4, bool32 s5, bool32 s6, bool32 s7) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 16>>
        inline simd(
            bool32  s0, bool32  s1, bool32  s2, bool32  s3,
            bool32  s4, bool32  s5, bool32  s6, bool32  s7,
            bool32  s8, bool32  s9, bool32 s10, bool32 s11,
            bool32 s12, bool32 s13, bool32 s14, bool32 s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 4>& s) noexcept
        {
            *this = explicit_cast(s);
        }

        simd(__m128 underlying) noexcept
        :
            underlying_(underlying)
        {
        }

        operator __m128() const noexcept
        {
            return underlying_;
        }

#ifdef TUE_SSE2
        simd(__m128i underlying) noexcept
        :
            underlying_(_mm_castsi128_ps(underlying))
        {
        }

        operator __m128i() const noexcept
        {
            return _mm_castps_si128(underlying_);
        }
#endif

        static bool32x4 zero() noexcept
        {
            return _mm_setzero_ps();
        }

        static bool32x4 load(const bool32* data) noexcept
        {
            return _mm_load_ps(reinterpret_cast<const float*>(data));
        }

        static bool32x4 loadu(const bool32* data) noexcept
        {
            return _mm_loadu_ps(reinterpret_cast<const float*>(data));
        }

        void store(bool32* data) const noexcept
        {
            _mm_store_ps(reinterpret_cast<float*>(data), underlying_);
        }

        void storeu(bool32* data) const noexcept
        {
            _mm_storeu_ps(reinterpret_cast<float*>(data), underlying_);
        }

        const bool32* data() const noexcept
        {
            return reinterpret_cast<const bool32*>(&underlying_);
        }

        bool32* data() noexcept
        {
            return reinterpret_cast<bool32*>(&underlying_);
        }
    };
}

namespace tue
{
    namespace detail_
    {
        inline bool32x4 bitwise_not_operator_s(
            const bool32x4& s) noexcept
        {
            return _mm_xor_ps(s, bool32x4(true32));
        }

        inline bool32x4 bitwise_and_operator_ss(
            const bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_and_ps(lhs, rhs);
        }

        inline bool32x4 bitwise_or_operator_ss(
            const bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_or_ps(lhs, rhs);
        }

        inline bool32x4 bitwise_xor_operator_ss(
            const bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_xor_ps(lhs, rhs);
        }

        inline bool32x4& bitwise_and_assignment_operator_ss(
            bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return lhs = _mm_and_ps(lhs, rhs);
        }

        inline bool32x4& bitwise_or_assignment_operator_ss(
            bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return lhs = _mm_or_ps(lhs, rhs);
        }

        inline bool32x4& bitwise_xor_assignment_operator_ss(
            bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return lhs = _mm_xor_ps(lhs, rhs);
        }

#ifdef TUE_SSE2
        inline bool equality_operator_ss(
            bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }
#endif

        inline bool32x4 mask_ss(
            const bool32x4& conditions,
            const bool32x4& values) noexcept
        {
            return _mm_and_ps(conditions, values);
        }

        inline bool32x4 select_sss(
            const bool32x4& conditions,
            const bool32x4& values,
            const bool32x4& otherwise) noexcept
        {
            return _mm_or_ps(
                _mm_and_ps(conditions, values),
                _mm_andnot_ps(conditions, otherwise));
        }

#ifdef TUE_SSE2
        inline bool32x4 equal_ss(
            const bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_cmpeq_epi32(lhs, rhs);
        }

        inline bool32x4 not_equal_ss(
            const bool32x4& lhs, const bool32x4& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi32(lhs, rhs), bool32x4(true32));
        }
#endif
    }
}
