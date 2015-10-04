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
    class alignas(tue::detail_::alignof_simd<bool16, 8>())
    simd<bool16, 8>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static bool16x8 explicit_cast(const simd<U, 8>& s) noexcept
        {
            return {
                bool16(s.data()[0]),
                bool16(s.data()[1]),
                bool16(s.data()[2]),
                bool16(s.data()[3]),
                bool16(s.data()[4]),
                bool16(s.data()[5]),
                bool16(s.data()[6]),
                bool16(s.data()[7]),
            };
        }

        inline static bool16x8 explicit_cast(const int16x8& s) noexcept;

        inline static bool16x8 explicit_cast(const uint16x8& s) noexcept;

    public:
        using component_type = bool16;

        static constexpr int component_count = 8;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(bool16 x) noexcept
        :
            underlying_(_mm_set1_epi16(x))
        {
        }

        template<int M = 8, typename = std::enable_if_t<M == 2>>
        inline simd(
            bool16 x, bool16 y) noexcept;

        template<int M = 8, typename = std::enable_if_t<M == 4>>
        inline simd(
            bool16 x, bool16 y, bool16 z, bool16 w) noexcept;

        template<int M = 8, typename = std::enable_if_t<M == 8>>
        inline simd(
            bool16 s0, bool16 s1, bool16 s2, bool16 s3,
            bool16 s4, bool16 s5, bool16 s6, bool16 s7) noexcept
        :
            underlying_(_mm_setr_epi16(
                s0, s1, s2, s3, s4, s5, s6, s7))
        {
        }

        template<int M = 8, typename = std::enable_if_t<M == 16>>
        inline simd(
            bool16  s0, bool16  s1, bool16  s2, bool16  s3,
            bool16  s4, bool16  s5, bool16  s6, bool16  s7,
            bool16  s8, bool16  s9, bool16 s10, bool16 s11,
            bool16 s12, bool16 s13, bool16 s14, bool16 s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 8>& s) noexcept
        {
            *this = explicit_cast(s);
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

        static bool16x8 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static bool16x8 load(const bool16* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static bool16x8 loadu(const bool16* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(bool16* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(bool16* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const bool16* data() const noexcept
        {
            return reinterpret_cast<const bool16*>(&underlying_);
        }

        bool16* data() noexcept
        {
            return reinterpret_cast<bool16*>(&underlying_);
        }
    };
}

#include "int16x8.sse2.hpp"
#include "uint16x8.sse2.hpp"

namespace tue
{
    inline bool16x8 bool16x8::explicit_cast(const int16x8& s) noexcept
    {
        return __m128i(s);
    }

    inline bool16x8 bool16x8::explicit_cast(const uint16x8& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline bool16x8 bitwise_not_operator_s(
            const bool16x8& s) noexcept
        {
            return _mm_xor_si128(s, bool16x8(true16));
        }

        inline bool16x8 bitwise_and_operator_ss(
            const bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline bool16x8 bitwise_or_operator_ss(
            const bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline bool16x8 bitwise_xor_operator_ss(
            const bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline bool16x8& bitwise_and_assignment_operator_ss(
            bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline bool16x8& bitwise_or_assignment_operator_ss(
            bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline bool16x8& bitwise_xor_assignment_operator_ss(
            bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline bool equality_operator_ss(
            bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline bool16x8 mask_ss(
            const bool16x8& conditions,
            const bool16x8& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline bool16x8 select_sss(
            const bool16x8& conditions,
            const bool16x8& values,
            const bool16x8& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        inline bool16x8 equal_ss(
            const bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_cmpeq_epi16(lhs, rhs);
        }

        inline bool16x8 not_equal_ss(
            const bool16x8& lhs, const bool16x8& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi16(lhs, rhs), bool16x8(true16));
        }
    }
}
