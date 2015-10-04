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
    class alignas(tue::detail_::alignof_simd<std::int8_t, 16>())
    simd<std::int8_t, 16>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static int8x16 explicit_cast(const simd<U, 16>& s) noexcept
        {
            return {
                std::int8_t(s.data()[0]),
                std::int8_t(s.data()[1]),
                std::int8_t(s.data()[2]),
                std::int8_t(s.data()[3]),
                std::int8_t(s.data()[4]),
                std::int8_t(s.data()[5]),
                std::int8_t(s.data()[6]),
                std::int8_t(s.data()[7]),
                std::int8_t(s.data()[8]),
                std::int8_t(s.data()[9]),
                std::int8_t(s.data()[10]),
                std::int8_t(s.data()[11]),
                std::int8_t(s.data()[12]),
                std::int8_t(s.data()[13]),
                std::int8_t(s.data()[14]),
                std::int8_t(s.data()[15]),
            };
        }

        inline static int8x16 explicit_cast(const bool8x16& s) noexcept;

        inline static int8x16 explicit_cast(const uint8x16& s) noexcept;

    public:
        using component_type = std::int8_t;

        static constexpr int component_count = 16;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(std::int8_t x) noexcept
        :
            underlying_(_mm_set1_epi8(x))
        {
        }

        template<int M = 16, typename = std::enable_if_t<M == 2>>
        inline simd(
            std::int8_t x, std::int8_t y) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 4>>
        inline simd(
            std::int8_t x, std::int8_t y,
            std::int8_t z, std::int8_t w) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 8>>
        inline simd(
            std::int8_t s0, std::int8_t s1,
            std::int8_t s2, std::int8_t s3,
            std::int8_t s4, std::int8_t s5,
            std::int8_t s6, std::int8_t s7) noexcept;

        template<int M = 16, typename = std::enable_if_t<M == 16>>
        inline simd(
            std::int8_t  s0, std::int8_t  s1,
            std::int8_t  s2, std::int8_t  s3,
            std::int8_t  s4, std::int8_t  s5,
            std::int8_t  s6, std::int8_t  s7,
            std::int8_t  s8, std::int8_t  s9,
            std::int8_t s10, std::int8_t s11,
            std::int8_t s12, std::int8_t s13,
            std::int8_t s14, std::int8_t s15) noexcept
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

        static int8x16 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static int8x16 load(const std::int8_t* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static int8x16 loadu(const std::int8_t* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(std::int8_t* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(std::int8_t* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const std::int8_t* data() const noexcept
        {
            return reinterpret_cast<const std::int8_t*>(&underlying_);
        }

        std::int8_t* data() noexcept
        {
            return reinterpret_cast<std::int8_t*>(&underlying_);
        }
    };
}

#include "bool8x16.sse2.hpp"
#include "uint8x16.sse2.hpp"

namespace tue
{
    inline int8x16 int8x16::explicit_cast(const bool8x16& s) noexcept
    {
        return __m128i(s);
    }

    inline int8x16 int8x16::explicit_cast(const uint8x16& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline int8x16 unary_plus_operator_s(const int8x16& s) noexcept
        {
            return s;
        }

        inline int8x16& pre_increment_operator_s(int8x16& s) noexcept
        {
            return s = _mm_add_epi8(s, int8x16(1));
        }

        inline int8x16 post_increment_operator_s(int8x16& s) noexcept
        {
            const auto result = s;
            s = _mm_add_epi8(s, int8x16(1));
            return result;
        }

        inline int8x16 unary_minus_operator_s(const int8x16& s) noexcept
        {
            return _mm_sub_epi8(_mm_setzero_si128(), s);
        }

        inline int8x16& pre_decrement_operator_s(int8x16& s) noexcept
        {
            return s = _mm_sub_epi8(s, int8x16(1));
        }

        inline int8x16 post_decrement_operator_s(int8x16& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_epi8(s, int8x16(1));
            return result;
        }

        inline int8x16 bitwise_not_operator_s(const int8x16& s) noexcept
        {
            return _mm_xor_si128(s, int8x16(0xFFu));
        }

        inline int8x16 addition_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_add_epi8(lhs, rhs);
        }

        inline int8x16 subtraction_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_sub_epi8(lhs, rhs);
        }

        /*inline int8x16 multiplication_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }

        inline int8x16 division_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }

        inline int8x16 modulo_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }*/

        inline int8x16 bitwise_and_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline int8x16 bitwise_or_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline int8x16 bitwise_xor_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        /*inline int8x16 bitwise_shift_left_operator_si(
            const int8x16& lhs, int rhs) noexcept
        {
            // TODO
        }

        inline int8x16 bitwise_shift_right_operator_si(
            const int8x16& lhs, int rhs) noexcept
        {
            // TODO
        }*/

        inline int8x16& addition_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            return lhs = _mm_add_epi8(lhs, rhs);
        }

        inline int8x16& subtraction_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            return lhs = _mm_sub_epi8(lhs, rhs);
        }

        /*inline int8x16& multiplication_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }

        inline int8x16& division_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }

        inline int8x16& modulo_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            // TODO
        }*/

        inline int8x16& bitwise_and_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline int8x16& bitwise_or_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline int8x16& bitwise_xor_assignment_operator_ss(
            int8x16& lhs, const int8x16& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        /*inline int8x16& bitwise_shift_left_assignment_operator_si(
            int8x16& lhs, int rhs) noexcept
        {
            // TODO
        }

        inline int8x16& bitwise_shift_right_assignment_operator_si(
            int8x16& lhs, int rhs) noexcept
        {
            // TODO
        }*/

        inline bool equality_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline int8x16 abs_s(const int8x16& s) noexcept
        {
            const auto nmask = _mm_cmplt_epi8(s, _mm_setzero_si128());
            return _mm_or_si128(
                _mm_and_si128(nmask, unary_minus_operator_s(s)),
                _mm_andnot_si128(nmask, s));
        }

        /*inline int8x16 min_ss(
            const int8x16& s1, const int8x16& s2) noexcept
        {
            // TODO
        }

        inline int8x16 max_ss(
            const int8x16& s1, const int8x16& s2) noexcept
        {
            // TODO
        }*/

        inline int8x16 mask_ss(
            const bool8x16& conditions,
            const int8x16& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline int8x16 select_sss(
            const bool8x16& conditions,
            const int8x16& values,
            const int8x16& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        inline bool8x16 less_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_cmplt_epi8(lhs, rhs);
        }

        inline bool8x16 less_equal_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpgt_epi8(lhs, rhs), int8x16(0xFFu));
        }

        inline bool8x16 greater_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_cmpgt_epi8(lhs, rhs);
        }

        inline bool8x16 greater_equal_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmplt_epi8(lhs, rhs), int8x16(0xFFu));
        }

        inline bool8x16 equal_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_cmpeq_epi8(lhs, rhs);
        }

        inline bool8x16 not_equal_ss(
            const int8x16& lhs, const int8x16& rhs) noexcept
        {
            return _mm_xor_si128(_mm_cmpeq_epi8(lhs, rhs), int8x16(0xFFu));
        }
    }
}
