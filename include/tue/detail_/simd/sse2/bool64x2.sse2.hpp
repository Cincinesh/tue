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
    class alignas(sizeof(bool64) * 2) simd<bool64, 2>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static simd<bool64, 2> explicit_cast(const simd<U, 2>& s) noexcept
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
        simd(bool64 x, bool64 y) noexcept
        :
            underlying_(_mm_set_epi64x(y, x))
        {
        }

        template<int M = 2, typename = std::enable_if_t<M == 4>>
        simd(bool64 x, bool64 y, bool64 z, bool64 w) noexcept;

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

        static simd<bool64, 2> zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static simd<bool64, 2> load(const bool64* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static simd<bool64, 2> loadu(const bool64* data) noexcept
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

        /*inline bool64x2 equal_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_cmpeq_epi64(lhs, rhs);
        }

        inline bool64x2 not_equal_ss(
            const bool64x2& lhs, const bool64x2& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi64(lhs, rhs), bool64x2(true64));
        }*/
    }
}
