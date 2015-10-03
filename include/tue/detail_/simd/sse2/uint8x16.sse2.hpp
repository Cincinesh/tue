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
    class alignas(sizeof(std::uint8_t) * 16) simd<std::uint8_t, 16>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static uint8x16 explicit_cast(const simd<U, 16>& s) noexcept
        {
            uint8x16 result;
            for (int i = 0; i < 16; ++i)
            {
                result.data()[i] = std::uint8_t(s.data()[i]);
            }
            return result;
        }

        inline static uint8x16 explicit_cast(const bool8x16& s) noexcept;

        inline static uint8x16 explicit_cast(const int8x16& s) noexcept;

    public:
        using component_type = std::uint8_t;

        static constexpr int component_count = 16;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(std::uint8_t x) noexcept
        :
            underlying_(_mm_set1_epi8(x))
        {
        }

        template<int M = 16, typename = std::enable_if_t<M == 2>>
        inline simd(std::uint8_t x, std::uint8_t y) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 4>>
        inline simd(
            std::uint8_t x,
            std::uint8_t y,
            std::uint8_t z,
            std::uint8_t w) noexcept;

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

        static uint8x16 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static uint8x16 load(const std::uint8_t* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static uint8x16 loadu(const std::uint8_t* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(std::uint8_t* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(std::uint8_t* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const std::uint8_t* data() const noexcept
        {
            return reinterpret_cast<const std::uint8_t*>(&underlying_);
        }

        std::uint8_t* data() noexcept
        {
            return reinterpret_cast<std::uint8_t*>(&underlying_);
        }
    };
}

#include "bool8x16.sse2.hpp"
#include "int8x16.sse2.hpp"

namespace tue
{
    inline uint8x16 uint8x16::explicit_cast(const bool8x16& s) noexcept
    {
        return __m128i(s);
    }

    inline uint8x16 uint8x16::explicit_cast(const int8x16& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        template<typename T>
        inline uint8x16& pre_increment_operator_s(uint8x16& s) noexcept
        {
            return s = _mm_add_epi8(s, uint8x16(1));
        }

        template<typename T>
        inline uint8x16 post_increment_operator_s(uint8x16& s) noexcept
        {
            const auto result = s;
            s = _mm_add_epi8(s, uint8x16(1));
            return result;
        }

        template<typename T>
        inline uint8x16& pre_decrement_operator_s(uint8x16& s) noexcept
        {
            return s = _mm_sub_epi8(s, uint8x16(1));
        }

        template<typename T>
        inline uint8x16 post_decrement_operator_s(uint8x16& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_epi8(s, uint8x16(1));
            return result;
        }

        template<typename T>
        inline uint8x16 bitwise_not_operator_s(const uint8x16& s) noexcept
        {
            return _mm_xor_si128(s, uint8x16(0xFF));
        }

        template<typename T>
        inline uint8x16 addition_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_add_epi8(lhs, rhs);
        }

        template<typename T>
        inline uint8x16 subtraction_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_sub_epi8(lhs, rhs);
        }

        /*template<typename T>
        inline uint8x16 multiplication_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16 division_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16 modulo_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }*/

        template<typename T>
        inline uint8x16 bitwise_and_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        template<typename T>
        inline uint8x16 bitwise_or_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        template<typename T>
        inline uint8x16 bitwise_xor_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        /*template<typename T>
        inline uint8x16 bitwise_shift_left_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16 bitwise_shift_right_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }*/

        template<typename T>
        inline uint8x16& addition_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return lhs = _mm_add_epi8(lhs, rhs);
        }

        template<typename T>
        inline uint8x16& subtraction_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return lhs = _mm_sub_epi8(lhs, rhs);
        }

        /*template<typename T>
        inline uint8x16& multiplication_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16& division_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16& modulo_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }*/

        template<typename T>
        inline uint8x16& bitwise_and_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        template<typename T>
        inline uint8x16& bitwise_or_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        template<typename T>
        inline uint8x16& bitwise_xor_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        /*template<typename T>
        inline uint8x16& bitwise_shift_left_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline uint8x16& bitwise_shift_right_assignment_operator_ss(
            uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }*/

        template<typename T>
        inline bool equality_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        template<typename T>
        inline bool inequality_operator_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        template<typename T>
        inline uint8x16 abs_s(const uint8x16& s) noexcept
        {
            return s;
        }

        template<typename T>
        inline uint8x16 min_ss(
            const uint8x16& s1, const uint8x16& s2) noexcept
        {
            return _mm_min_epu8(s1, s2);
        }

        template<typename T>
        inline uint8x16 max_ss(
            const uint8x16& s1, const uint8x16& s2) noexcept
        {
            return _mm_max_epu8(s1, s2);
        }

        template<typename T, typename U>
        inline uint8x16 mask_ss(
            const bool8x16& conditions,
            const uint8x16& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        template<typename T, typename U>
        inline uint8x16 select_sss(
            const bool8x16& conditions,
            const uint8x16& values,
            const uint8x16& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        /*template<typename T>
        inline bool8x16 less_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline bool8x16 less_equal_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline bool8x16 greater_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }

        template<typename T>
        inline bool8x16 greater_equal_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            // TODO
        }*/

        template<typename T>
        inline bool8x16 equal_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_cmpeq_epi8(lhs, rhs);
        }

        template<typename T>
        inline bool8x16 not_equal_ss(
            const uint8x16& lhs, const uint8x16& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi8(lhs, rhs), uint8x16(0xFF));
        }
    }
}
