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
    class alignas(tue::detail_::alignof_simd<std::uint32_t, 4>())
    simd<std::uint32_t, 4>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static uint32x4 explicit_cast(const simd<U, 4>& s) noexcept
        {
            return {
                std::uint32_t(s.data()[0]),
                std::uint32_t(s.data()[1]),
                std::uint32_t(s.data()[2]),
                std::uint32_t(s.data()[3]),
            };
        }

        inline static uint32x4 explicit_cast(const bool32x4& s) noexcept;

        inline static uint32x4 explicit_cast(const float32x4& s) noexcept;

        inline static uint32x4 explicit_cast(const int32x4& s) noexcept;

    public:
        using component_type = std::uint32_t;

        static constexpr int component_count = 4;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(std::uint32_t x) noexcept
        :
            underlying_(_mm_set1_epi32(x))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 2>>
        inline simd(
            std::uint32_t x, std::uint32_t y) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 4>>
        simd(
            std::uint32_t x, std::uint32_t y,
            std::uint32_t z, std::uint32_t w) noexcept
        :
            underlying_(_mm_setr_epi32(x, y, z, w))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 8>>
        inline simd(
            std::uint32_t s0, std::uint32_t s1,
            std::uint32_t s2, std::uint32_t s3,
            std::uint32_t s4, std::uint32_t s5,
            std::uint32_t s6, std::uint32_t s7) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 16>>
        inline simd(
            std::uint32_t  s0, std::uint32_t  s1,
            std::uint32_t  s2, std::uint32_t  s3,
            std::uint32_t  s4, std::uint32_t  s5,
            std::uint32_t  s6, std::uint32_t  s7,
            std::uint32_t  s8, std::uint32_t  s9,
            std::uint32_t s10, std::uint32_t s11,
            std::uint32_t s12, std::uint32_t s13,
            std::uint32_t s14, std::uint32_t s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 4>& s) noexcept
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

        static uint32x4 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static uint32x4 load(const std::uint32_t* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static uint32x4 loadu(const std::uint32_t* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(std::uint32_t* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(std::uint32_t* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const std::uint32_t* data() const noexcept
        {
            return reinterpret_cast<const std::uint32_t*>(&underlying_);
        }

        std::uint32_t* data() noexcept
        {
            return reinterpret_cast<std::uint32_t*>(&underlying_);
        }
    };
}

#include "../sse/bool32x4.sse.hpp"
#include "../sse/float32x4.sse.hpp"
#include "int32x4.sse2.hpp"

namespace tue
{
    inline uint32x4 uint32x4::explicit_cast(const bool32x4& s) noexcept
    {
        return __m128i(s);
    }

    inline uint32x4 uint32x4::explicit_cast(const float32x4& s) noexcept
    {
        return _mm_cvtps_epi32(s);
    }

    inline uint32x4 uint32x4::explicit_cast(const int32x4& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline uint32x4& pre_increment_operator_s(uint32x4& s) noexcept
        {
            return s = _mm_add_epi32(s, uint32x4(1));
        }

        inline uint32x4 post_increment_operator_s(uint32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_add_epi32(s, uint32x4(1));
            return result;
        }

        inline uint32x4& pre_decrement_operator_s(uint32x4& s) noexcept
        {
            return s = _mm_sub_epi32(s, uint32x4(1));
        }

        inline uint32x4 post_decrement_operator_s(uint32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_epi32(s, uint32x4(1));
            return result;
        }

        inline uint32x4 bitwise_not_operator_s(const uint32x4& s) noexcept
        {
            return _mm_xor_si128(s, uint32x4(0xFFFFFFFF));
        }

        inline uint32x4 addition_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_add_epi32(lhs, rhs);
        }

        inline uint32x4 subtraction_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_sub_epi32(lhs, rhs);
        }

        /*inline uint32x4 multiplication_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline uint32x4 division_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline uint32x4 modulo_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }*/

        inline uint32x4 bitwise_and_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline uint32x4 bitwise_or_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline uint32x4 bitwise_xor_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline uint32x4 bitwise_shift_left_operator_si(
            const uint32x4& lhs, int rhs) noexcept
        {
            return _mm_slli_epi32(lhs, rhs);
        }

        inline uint32x4 bitwise_shift_right_operator_si(
            const uint32x4& lhs, int rhs) noexcept
        {
            return _mm_srli_epi32(lhs, rhs);
        }

        inline uint32x4& addition_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return lhs = _mm_add_epi32(lhs, rhs);
        }

        inline uint32x4& subtraction_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return lhs = _mm_sub_epi32(lhs, rhs);
        }

        /*inline uint32x4& multiplication_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline uint32x4& division_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline uint32x4& modulo_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }*/

        inline uint32x4& bitwise_and_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline uint32x4& bitwise_or_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline uint32x4& bitwise_xor_assignment_operator_ss(
            uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline uint32x4& bitwise_shift_left_assignment_operator_si(
            uint32x4& lhs, int rhs) noexcept
        {
            return lhs = _mm_slli_epi32(lhs, rhs);
        }

        inline uint32x4& bitwise_shift_right_assignment_operator_si(
            uint32x4& lhs, int rhs) noexcept
        {
            return lhs = _mm_srli_epi32(lhs, rhs);
        }

        inline bool equality_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline uint32x4 abs_s(const uint32x4& s) noexcept
        {
            return s;
        }

        /*inline uint32x4 min_ss(
            const uint32x4& s1, const uint32x4& s2) noexcept
        {
            // TODO
        }

        inline uint32x4 max_ss(
            const uint32x4& s1, const uint32x4& s2) noexcept
        {
            // TODO
        }*/

        inline uint32x4 mask_ss(
            const bool32x4& conditions,
            const uint32x4& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline uint32x4 select_sss(
            const bool32x4& conditions,
            const uint32x4& values,
            const uint32x4& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        /*inline bool32x4 less_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline bool32x4 less_equal_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline bool32x4 greater_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }

        inline bool32x4 greater_equal_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            // TODO
        }*/

        inline bool32x4 equal_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_cmpeq_epi32(lhs, rhs);
        }

        inline bool32x4 not_equal_ss(
            const uint32x4& lhs, const uint32x4& rhs) noexcept
        {
            return _mm_xor_si128(
                _mm_cmpeq_epi32(lhs, rhs), uint32x4(0xFFFFFFFF));
        }
    }
}
