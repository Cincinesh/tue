//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <emmintrin.h>

#include <cstdint>
#include <type_traits>

#include "../../../simd.hpp"

namespace tue
{
    template<>
    class alignas(tue::detail_::alignof_simd<std::uint16_t, 8>())
    simd<std::uint16_t, 8>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static uint16x8 explicit_cast(const simd<U, 8>& s) noexcept
        {
            return {
                std::uint16_t(s.data()[0]),
                std::uint16_t(s.data()[1]),
                std::uint16_t(s.data()[2]),
                std::uint16_t(s.data()[3]),
                std::uint16_t(s.data()[4]),
                std::uint16_t(s.data()[5]),
                std::uint16_t(s.data()[6]),
                std::uint16_t(s.data()[7]),
            };
        }

        inline static uint16x8 explicit_cast(const bool16x8& s) noexcept;

        inline static uint16x8 explicit_cast(const int16x8& s) noexcept;

    public:
        using component_type = std::uint16_t;

        static constexpr int component_count = 8;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(std::uint16_t x) noexcept
        :
            underlying_(_mm_set1_epi16(x))
        {
        }

        template<int M = 8, typename = std::enable_if_t<M == 2>>
        inline simd(
            std::uint16_t x, std::uint16_t y) noexcept;

        template<int M = 8, typename = std::enable_if_t<M == 4>>
        inline simd(
            std::uint16_t x, std::uint16_t y,
            std::uint16_t z, std::uint16_t w) noexcept;

        template<int M = 8, typename = std::enable_if_t<M == 8>>
        inline simd(
            std::uint16_t s0, std::uint16_t s1,
            std::uint16_t s2, std::uint16_t s3,
            std::uint16_t s4, std::uint16_t s5,
            std::uint16_t s6, std::uint16_t s7) noexcept
        :
            underlying_(_mm_setr_epi16(
                s0, s1, s2, s3, s4, s5, s6, s7))
        {
        }

        template<int M = 8, typename = std::enable_if_t<M == 16>>
        inline simd(
            std::uint16_t  s0, std::uint16_t  s1,
            std::uint16_t  s2, std::uint16_t  s3,
            std::uint16_t  s4, std::uint16_t  s5,
            std::uint16_t  s6, std::uint16_t  s7,
            std::uint16_t  s8, std::uint16_t  s9,
            std::uint16_t s10, std::uint16_t s11,
            std::uint16_t s12, std::uint16_t s13,
            std::uint16_t s14, std::uint16_t s15) noexcept;

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

        static uint16x8 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static uint16x8 load(const std::uint16_t* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static uint16x8 loadu(const std::uint16_t* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(std::uint16_t* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(std::uint16_t* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const std::uint16_t* data() const noexcept
        {
            return reinterpret_cast<const std::uint16_t*>(&underlying_);
        }

        std::uint16_t* data() noexcept
        {
            return reinterpret_cast<std::uint16_t*>(&underlying_);
        }
    };
}

#include "bool16x8.sse2.hpp"
#include "int16x8.sse2.hpp"

namespace tue
{
    inline uint16x8 uint16x8::explicit_cast(const bool16x8& s) noexcept
    {
        return __m128i(s);
    }

    inline uint16x8 uint16x8::explicit_cast(const int16x8& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline uint16x8& pre_increment_operator_s(uint16x8& s) noexcept
        {
            return s = _mm_add_epi16(s, uint16x8(1));
        }

        inline uint16x8 post_increment_operator_s(uint16x8& s) noexcept
        {
            const auto result = s;
            s = _mm_add_epi16(s, uint16x8(1));
            return result;
        }

        inline uint16x8& pre_decrement_operator_s(uint16x8& s) noexcept
        {
            return s = _mm_sub_epi16(s, uint16x8(1));
        }

        inline uint16x8 post_decrement_operator_s(uint16x8& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_epi16(s, uint16x8(1));
            return result;
        }

        inline uint16x8 bitwise_not_operator_s(const uint16x8& s) noexcept
        {
            return _mm_xor_si128(s, uint16x8(0xFFFF));
        }

        inline uint16x8 addition_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_add_epi16(lhs, rhs);
        }

        inline uint16x8 subtraction_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_sub_epi16(lhs, rhs);
        }

        /*inline uint16x8 multiplication_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline uint16x8 division_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline uint16x8 modulo_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }*/

        inline uint16x8 bitwise_and_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline uint16x8 bitwise_or_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline uint16x8 bitwise_xor_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline uint16x8 bitwise_shift_left_operator_si(
            const uint16x8& lhs, int rhs) noexcept
        {
            return _mm_slli_epi16(lhs, rhs);
        }

        inline uint16x8 bitwise_shift_right_operator_si(
            const uint16x8& lhs, int rhs) noexcept
        {
            return _mm_srli_epi16(lhs, rhs);
        }

        inline uint16x8& addition_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return lhs = _mm_add_epi16(lhs, rhs);
        }

        inline uint16x8& subtraction_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return lhs = _mm_sub_epi16(lhs, rhs);
        }

        /*inline uint16x8& multiplication_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline uint16x8& division_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline uint16x8& modulo_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }*/

        inline uint16x8& bitwise_and_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline uint16x8& bitwise_or_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline uint16x8& bitwise_xor_assignment_operator_ss(
            uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline uint16x8& bitwise_shift_left_assignment_operator_si(
            uint16x8& lhs, int rhs) noexcept
        {
            return lhs = _mm_slli_epi16(lhs, rhs);
        }

        inline uint16x8& bitwise_shift_right_assignment_operator_si(
            uint16x8& lhs, int rhs) noexcept
        {
            return lhs = _mm_srli_epi16(lhs, rhs);
        }

        inline bool equality_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline uint16x8 abs_s(const uint16x8& s) noexcept
        {
            return s;
        }

        /*inline uint16x8 min_ss(
            const uint16x8& s1, const uint16x8& s2) noexcept
        {
            // TODO
        }

        inline uint16x8 max_ss(
            const uint16x8& s1, const uint16x8& s2) noexcept
        {
            // TODO
        }*/

        inline uint16x8 mask_ss(
            const bool16x8& conditions,
            const uint16x8& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline uint16x8 select_sss(
            const bool16x8& conditions,
            const uint16x8& values,
            const uint16x8& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        /*inline bool16x8 less_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline bool16x8 less_equal_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline bool16x8 greater_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }

        inline bool16x8 greater_equal_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            // TODO
        }*/

        inline bool16x8 equal_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_cmpeq_epi16(lhs, rhs);
        }

        inline bool16x8 not_equal_ss(
            const uint16x8& lhs, const uint16x8& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi16(lhs, rhs), uint16x8(0xFFFF));
        }
    }
}
