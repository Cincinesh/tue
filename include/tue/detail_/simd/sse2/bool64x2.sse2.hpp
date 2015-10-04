//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <emmintrin.h>

#include <type_traits>

#include "../../../simd.hpp"
#include "../../../sized_bool.hpp"

namespace tue
{
    template<>
    class alignas(tue::detail_::alignof_simd<bool64, 2>())
    simd<bool64, 2>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static bool64x2 explicit_cast(const simd<U, 2>& s) noexcept
        {
            return {
                bool64(s.data()[0]),
                bool64(s.data()[1]),
            };
        }

    public:
        using component_type = bool64;

        static constexpr int component_count = 2;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(bool64 x) noexcept
        :
            underlying_(_mm_set1_epi64x(x))
        {
        }

        template<int M = 2, typename = std::enable_if_t<M == 2>>
        inline simd(
            bool64 x, bool64 y) noexcept
        :
            underlying_(_mm_set_epi64x(y, x))
        {
        }

        template<int M = 2, typename = std::enable_if_t<M == 4>>
        inline simd(
            bool64 x, bool64 y, bool64 z, bool64 w) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 8>>
        inline simd(
            bool64 s0, bool64 s1, bool64 s2, bool64 s3,
            bool64 s4, bool64 s5, bool64 s6, bool64 s7) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 16>>
        inline simd(
            bool64  s0, bool64  s1, bool64  s2, bool64  s3,
            bool64  s4, bool64  s5, bool64  s6, bool64  s7,
            bool64  s8, bool64  s9, bool64 s10, bool64 s11,
            bool64 s12, bool64 s13, bool64 s14, bool64 s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 2>& s) noexcept
        {
            *this = explicit_cast(s);
        }

        simd(__m128d underlying) noexcept
        :
            underlying_(_mm_castpd_si128(underlying))
        {
        }

        operator __m128d() const noexcept
        {
            return _mm_castsi128_pd(underlying_);
        }

        simd(__m128i underlying) noexcept
        :
            underlying_(underlying)
        {
        }

        operator __m128i() const noexcept
        {
            return underlying_;
        }

        static bool64x2 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static bool64x2 load(const bool64* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static bool64x2 loadu(const bool64* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(bool64* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(bool64* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const bool64* data() const noexcept
        {
            return reinterpret_cast<const bool64*>(&underlying_);
        }

        bool64* data() noexcept
        {
            return reinterpret_cast<bool64*>(&underlying_);
        }
    };
}

namespace tue
{
    namespace detail_
    {
        inline bool64x2 bitwise_not_operator_s(
            const bool64x2& s) noexcept
        {
            return _mm_xor_si128(s, bool64x2(true64));
        }

        inline bool64x2 bitwise_and_operator_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline bool64x2 bitwise_or_operator_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline bool64x2 bitwise_xor_operator_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline bool64x2& bitwise_and_assignment_operator_ss(
            bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline bool64x2& bitwise_or_assignment_operator_ss(
            bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline bool64x2& bitwise_xor_assignment_operator_ss(
            bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline bool equality_operator_ss(
            bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline bool64x2 mask_ss(
            const bool64x2& conditions,
            const bool64x2& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline bool64x2 select_sss(
            const bool64x2& conditions,
            const bool64x2& values,
            const bool64x2& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        inline bool64x2 equal_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            const auto cmp = _mm_cmpeq_epi32(lhs, rhs);
            const auto hi = _mm_shuffle_epi32(cmp, _MM_SHUFFLE(3, 3, 1, 1));
            const auto lo = _mm_shuffle_epi32(cmp, _MM_SHUFFLE(2, 2, 0, 0));
            return _mm_and_si128(hi, lo);
        }

        inline bool64x2 not_equal_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_xor_si128(equal_ss(lhs, rhs), bool64x2(true64));
        }
    }
}
