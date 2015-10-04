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
    class alignas(tue::detail_::alignof_simd<bool8, 16>())
    simd<bool8, 16>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static bool8x16 explicit_cast(const simd<U, 16>& s) noexcept
        {
            return {
                bool8(s.data()[0]),
                bool8(s.data()[1]),
                bool8(s.data()[2]),
                bool8(s.data()[3]),
                bool8(s.data()[4]),
                bool8(s.data()[5]),
                bool8(s.data()[6]),
                bool8(s.data()[7]),
                bool8(s.data()[8]),
                bool8(s.data()[9]),
                bool8(s.data()[10]),
                bool8(s.data()[11]),
                bool8(s.data()[12]),
                bool8(s.data()[13]),
                bool8(s.data()[14]),
                bool8(s.data()[15]),
            };
        }

        inline static bool8x16 explicit_cast(const int8x16& s) noexcept;

        inline static bool8x16 explicit_cast(const uint8x16& s) noexcept;

    public:
        using component_type = bool8;

        static constexpr int component_count = 16;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(bool8 x) noexcept
        :
            underlying_(_mm_set1_epi8(x))
        {
        }

        template<int M = 16, typename = std::enable_if_t<M == 2>>
        inline simd(
            bool8 x, bool8 y) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 4>>
        inline simd(
            bool8 x, bool8 y, bool8 z, bool8 w) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 8>>
        inline simd(
            bool8 s0, bool8 s1, bool8 s2, bool8 s3,
            bool8 s4, bool8 s5, bool8 s6, bool8 s7) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 16>>
        inline simd(
            bool8  s0, bool8  s1, bool8  s2, bool8  s3,
            bool8  s4, bool8  s5, bool8  s6, bool8  s7,
            bool8  s8, bool8  s9, bool8 s10, bool8 s11,
            bool8 s12, bool8 s13, bool8 s14, bool8 s15) noexcept
        :
            underlying_(_mm_setr_epi8(
                s0, s1,  s2,  s3,  s4,  s5,  s6,  s7,
                s8, s9, s10, s11, s12, s13, s14, s15))
        {
        }

        template<typename U>
        explicit simd(const simd<U, 16>& s) noexcept
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

        static bool8x16 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static bool8x16 load(const bool8* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static bool8x16 loadu(const bool8* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(bool8* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(bool8* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const bool8* data() const noexcept
        {
            return reinterpret_cast<const bool8*>(&underlying_);
        }

        bool8* data() noexcept
        {
            return reinterpret_cast<bool8*>(&underlying_);
        }
    };
}

#include "int8x16.sse2.hpp"
#include "uint8x16.sse2.hpp"

namespace tue
{
    inline bool8x16 bool8x16::explicit_cast(const int8x16& s) noexcept
    {
        return __m128i(s);
    }

    inline bool8x16 bool8x16::explicit_cast(const uint8x16& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline bool8x16 bitwise_not_operator_s(
            const bool8x16& s) noexcept
        {
            return _mm_xor_si128(s, bool8x16(true8));
        }

        inline bool8x16 bitwise_and_operator_ss(
            const bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline bool8x16 bitwise_or_operator_ss(
            const bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline bool8x16 bitwise_xor_operator_ss(
            const bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline bool8x16& bitwise_and_assignment_operator_ss(
            bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline bool8x16& bitwise_or_assignment_operator_ss(
            bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline bool8x16& bitwise_xor_assignment_operator_ss(
            bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline bool equality_operator_ss(
            bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline bool8x16 mask_ss(
            const bool8x16& conditions,
            const bool8x16& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline bool8x16 select_sss(
            const bool8x16& conditions,
            const bool8x16& values,
            const bool8x16& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        inline bool8x16 equal_ss(
            const bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_cmpeq_epi8(lhs, rhs);
        }

        inline bool8x16 not_equal_ss(
            const bool8x16& lhs, const bool8x16& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi8(lhs, rhs), bool8x16(true8));
        }
    }
}
