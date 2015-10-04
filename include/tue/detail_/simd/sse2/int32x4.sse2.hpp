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
    class alignas(tue::detail_::alignof_simd<std::int32_t, 4>())
    simd<std::int32_t, 4>
    {
        __m128i underlying_;

    private:
        template<typename U>
        static int32x4 explicit_cast(const simd<U, 4>& s) noexcept
        {
            return {
                std::int32_t(s.data()[0]),
                std::int32_t(s.data()[1]),
                std::int32_t(s.data()[2]),
                std::int32_t(s.data()[3]),
            };
        }

        inline static int32x4 explicit_cast(const bool32x4& s) noexcept;

        inline static int32x4 explicit_cast(const float32x4& s) noexcept;

        inline static int32x4 explicit_cast(const uint32x4& s) noexcept;

    public:
        using component_type = std::int32_t;

        static constexpr int component_count = 4;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(std::int32_t x) noexcept
        :
            underlying_(_mm_set1_epi32(x))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 2>>
        inline simd(
            std::int32_t x, std::int32_t y) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 4>>
        inline simd(
            std::int32_t x, std::int32_t y,
            std::int32_t z, std::int32_t w) noexcept
        :
            underlying_(_mm_setr_epi32(x, y, z, w))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 8>>
        inline simd(
            std::int32_t s0, std::int32_t s1,
            std::int32_t s2, std::int32_t s3,
            std::int32_t s4, std::int32_t s5,
            std::int32_t s6, std::int32_t s7) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 16>>
        inline simd(
            std::int32_t  s0, std::int32_t  s1,
            std::int32_t  s2, std::int32_t  s3,
            std::int32_t  s4, std::int32_t  s5,
            std::int32_t  s6, std::int32_t  s7,
            std::int32_t  s8, std::int32_t  s9,
            std::int32_t s10, std::int32_t s11,
            std::int32_t s12, std::int32_t s13,
            std::int32_t s14, std::int32_t s15) noexcept;

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

        static int32x4 zero() noexcept
        {
            return _mm_setzero_si128();
        }

        static int32x4 load(const std::int32_t* data) noexcept
        {
            return _mm_load_si128(reinterpret_cast<const __m128i*>(data));
        }

        static int32x4 loadu(const std::int32_t* data) noexcept
        {
            return _mm_loadu_si128(reinterpret_cast<const __m128i*>(data));
        }

        void store(std::int32_t* data) const noexcept
        {
            _mm_store_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        void storeu(std::int32_t* data) const noexcept
        {
            _mm_storeu_si128(reinterpret_cast<__m128i*>(data), underlying_);
        }

        const std::int32_t* data() const noexcept
        {
            return reinterpret_cast<const std::int32_t*>(&underlying_);
        }

        std::int32_t* data() noexcept
        {
            return reinterpret_cast<std::int32_t*>(&underlying_);
        }
    };
}

#include "../sse/bool32x4.sse.hpp"
#include "../sse/float32x4.sse.hpp"
#include "uint32x4.sse2.hpp"

namespace tue
{
    inline int32x4 int32x4::explicit_cast(const bool32x4& s) noexcept
    {
        return __m128i(s);
    }

    inline int32x4 int32x4::explicit_cast(const float32x4& s) noexcept
    {
        return _mm_cvtps_epi32(s);
    }

    inline int32x4 int32x4::explicit_cast(const uint32x4& s) noexcept
    {
        return __m128i(s);
    }

    namespace detail_
    {
        inline int32x4 unary_plus_operator_s(const int32x4& s) noexcept
        {
            return s;
        }

        inline int32x4& pre_increment_operator_s(int32x4& s) noexcept
        {
            return s = _mm_add_epi32(s, int32x4(1));
        }

        inline int32x4 post_increment_operator_s(int32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_add_epi32(s, int32x4(1));
            return result;
        }

        inline int32x4 unary_minus_operator_s(const int32x4& s) noexcept
        {
            return _mm_sub_epi32(_mm_setzero_si128(), s);
        }

        inline int32x4& pre_decrement_operator_s(int32x4& s) noexcept
        {
            return s = _mm_sub_epi32(s, int32x4(1));
        }

        inline int32x4 post_decrement_operator_s(int32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_epi32(s, int32x4(1));
            return result;
        }

        inline int32x4 bitwise_not_operator_s(const int32x4& s) noexcept
        {
            return _mm_xor_si128(s, int32x4(0xFFFFFFFF));
        }

        inline int32x4 addition_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_add_epi32(lhs, rhs);
        }

        inline int32x4 subtraction_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_sub_epi32(lhs, rhs);
        }

        /*inline int32x4 multiplication_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }

        inline int32x4 division_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }

        inline int32x4 modulo_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }*/

        inline int32x4 bitwise_and_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_and_si128(lhs, rhs);
        }

        inline int32x4 bitwise_or_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_or_si128(lhs, rhs);
        }

        inline int32x4 bitwise_xor_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_xor_si128(lhs, rhs);
        }

        inline int32x4 bitwise_shift_left_operator_si(
            const int32x4& lhs, int rhs) noexcept
        {
            return _mm_slli_epi32(lhs, rhs);
        }

        inline int32x4 bitwise_shift_right_operator_si(
            const int32x4& lhs, int rhs) noexcept
        {
            return _mm_srli_epi32(lhs, rhs);
        }

        inline int32x4& addition_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            return lhs = _mm_add_epi32(lhs, rhs);
        }

        inline int32x4& subtraction_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            return lhs = _mm_sub_epi32(lhs, rhs);
        }

        /*inline int32x4& multiplication_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }

        inline int32x4& division_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }

        inline int32x4& modulo_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            // TODO
        }*/

        inline int32x4& bitwise_and_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            return lhs = _mm_and_si128(lhs, rhs);
        }

        inline int32x4& bitwise_or_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            return lhs = _mm_or_si128(lhs, rhs);
        }

        inline int32x4& bitwise_xor_assignment_operator_ss(
            int32x4& lhs, const int32x4& rhs) noexcept
        {
            return lhs = _mm_xor_si128(lhs, rhs);
        }

        inline int32x4& bitwise_shift_left_assignment_operator_si(
            int32x4& lhs, int rhs) noexcept
        {
            return lhs = _mm_slli_epi32(lhs, rhs);
        }

        inline int32x4& bitwise_shift_right_assignment_operator_si(
            int32x4& lhs, int rhs) noexcept
        {
            return lhs = _mm_srli_epi32(lhs, rhs);
        }

        inline bool equality_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) == 0xFFFF;
        }

        inline bool inequality_operator_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_movemask_epi8(_mm_cmpeq_epi8(lhs, rhs)) != 0xFFFF;
        }

        inline int32x4 abs_s(const int32x4& s) noexcept
        {
            const auto nmask = _mm_cmplt_epi32(s, _mm_setzero_si128());
            return _mm_or_si128(
                _mm_and_si128(nmask, unary_minus_operator_s(s)),
                _mm_andnot_si128(nmask, s));
        }

        /*inline int32x4 min_ss(
            const int32x4& s1, const int32x4& s2) noexcept
        {
            // TODO
        }

        inline int32x4 max_ss(
            const int32x4& s1, const int32x4& s2) noexcept
        {
            // TODO
        }*/

        inline int32x4 mask_ss(
            const bool32x4& conditions,
            const int32x4& values) noexcept
        {
            return _mm_and_si128(conditions, values);
        }

        inline int32x4 select_sss(
            const bool32x4& conditions,
            const int32x4& values,
            const int32x4& otherwise) noexcept
        {
            return _mm_or_si128(
                _mm_and_si128(conditions, values),
                _mm_andnot_si128(conditions, otherwise));
        }

        inline bool32x4 less_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_cmplt_epi32(lhs, rhs);
        }

        inline bool32x4 less_equal_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_xor_si128(
                _mm_cmpgt_epi32(lhs, rhs), int32x4(0xFFFFFFFF));
        }

        inline bool32x4 greater_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_cmpgt_epi32(lhs, rhs);
        }

        inline bool32x4 greater_equal_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_xor_si128(
                _mm_cmplt_epi32(lhs, rhs), int32x4(0xFFFFFFFF));
        }

        inline bool32x4 equal_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_cmpeq_epi32(lhs, rhs);
        }

        inline bool32x4 not_equal_ss(
            const int32x4& lhs, const int32x4& rhs) noexcept
        {
            return _mm_xor_si128(
                _mm_cmpeq_epi32(lhs, rhs), int32x4(0xFFFFFFFF));
        }
    }
}
