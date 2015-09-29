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

namespace tue
{
    template<>
    class alignas(sizeof(float) * 4) simd<float, 4>
    {
        __m128 underlying_;

    private:
        template<typename U>
        static simd<float, 4> explicit_cast(const simd<U, 4>& s) noexcept
        {
            return {
                float(s.data()[0]),
                float(s.data()[1]),
                float(s.data()[2]),
                float(s.data()[3]),
            };
        }

    public:
        using component_type = float;

        static constexpr int component_count = 4;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(float x) noexcept
        :
            underlying_(_mm_set_ps1(x))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 2>>
        simd(float x, float y) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 4>>
        simd(float x, float y, float z, float w) noexcept
        :
            underlying_(_mm_setr_ps(x, y, z, w))
        {
        }

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

        static simd<float, 4> zero() noexcept
        {
            return _mm_setzero_ps();
        }

        static simd<float, 4> load(const float* data) noexcept
        {
            return _mm_load_ps(data);
        }

        static simd<float, 4> loadu(const float* data) noexcept
        {
            return _mm_loadu_ps(data);
        }

        void store(float* data) const noexcept
        {
            _mm_store_ps(data, underlying_);
        }

        void storeu(float* data) const noexcept
        {
            _mm_storeu_ps(data, underlying_);
        }

        const float* data() const noexcept
        {
            return reinterpret_cast<const float*>(&underlying_);
        }

        float* data() noexcept
        {
            return reinterpret_cast<float*>(&underlying_);
        }
    };

    namespace detail_
    {
        inline float32x4 unary_plus_operator_s(const float32x4& s) noexcept
        {
            return s;
        }

        inline float32x4& pre_increment_operator_s(float32x4& s) noexcept
        {
            return s = _mm_add_ps(s, float32x4(1.0f));
        }

        inline float32x4 post_increment_operator_s(float32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_add_ps(s, float32x4(1.0f));
            return result;
        }

        inline float32x4 unary_minus_operator_s(const float32x4& s) noexcept
        {
            return _mm_xor_ps(
                s, float32x4(tue::detail_::binary_float(0x80000000u)));
        }

        inline float32x4& pre_decrement_operator_s(float32x4& s) noexcept
        {
            return s = _mm_sub_ps(s, float32x4(1.0f));
        }

        inline float32x4 post_decrement_operator_s(float32x4& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_ps(s, float32x4(1.0f));
            return result;
        }

        inline float32x4 addition_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_add_ps(lhs, rhs);
        }

        inline float32x4 subtraction_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_sub_ps(lhs, rhs);
        }

        inline float32x4 multiplication_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_mul_ps(lhs, rhs);
        }

        inline float32x4 division_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_div_ps(lhs, rhs);
        }

        inline float32x4& addition_assignment_operator_ss(
            float32x4& lhs, const float32x4& rhs) noexcept
        {
            return lhs = _mm_add_ps(lhs, rhs);
        }

        inline float32x4& subtraction_assignment_operator_ss(
            float32x4& lhs, const float32x4& rhs) noexcept
        {
            return lhs = _mm_sub_ps(lhs, rhs);
        }

        inline float32x4& multiplication_assignment_operator_ss(
            float32x4& lhs, const float32x4& rhs) noexcept
        {
            return lhs = _mm_mul_ps(lhs, rhs);
        }

        inline float32x4& division_assignment_operator_ss(
            float32x4& lhs, const float32x4& rhs) noexcept
        {
            return lhs = _mm_div_ps(lhs, rhs);
        }

        inline bool equality_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_movemask_ps(_mm_cmpneq_ps(lhs, rhs)) == 0;
        }

        inline bool inequality_operator_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_movemask_ps(_mm_cmpneq_ps(lhs, rhs)) != 0;
        }

        /*inline float32x4 sin_s(const float32x4& s) noexcept
        {
            float32x4 result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::sin(sdata[0]);
            rdata[1] = tue::math::sin(sdata[1]);
            return result;
        }

        inline float32x4 cos_s(const float32x4& s) noexcept
        {
            float32x4 result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::cos(sdata[0]);
            rdata[1] = tue::math::cos(sdata[1]);
            return result;
        }

        inline void sincos_s(
            const float32x4& s,
            float32x4& sin_out,
            float32x4& cos_out) noexcept
        {
            const auto sdata = s.data();
            const auto sout = sin_out.data();
            const auto cout = cos_out.data();
            tue::math::sincos(sdata[0], sout[0], cout[0]);
            tue::math::sincos(sdata[1], sout[1], cout[1]);
        }

        inline float32x4 exp_s(const float32x4& s) noexcept
        {
            float32x4 result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::exp(sdata[0]);
            rdata[1] = tue::math::exp(sdata[1]);
            return result;
        }

        inline float32x4 log_s(const float32x4& s) noexcept
        {
            float32x4 result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::log(sdata[0]);
            rdata[1] = tue::math::log(sdata[1]);
            return result;
        }*/

        inline float32x4 abs_s(const float32x4& s) noexcept
        {
            return _mm_and_ps(
                s, float32x4(tue::detail_::binary_float(0x7FFFFFFFu)));
        }

        /*inline float32x4 pow_ss(
            const float32x4& bases, const float32x4& exponents) noexcept
        {
            float32x4 result;
            const auto rdata = result.data();
            const auto bdata = bases.data();
            const auto edata = exponents.data();
            rdata[0] = tue::math::pow(bdata[0], edata[0]);
            rdata[1] = tue::math::pow(bdata[1], edata[1]);
            return result;
        }*/

        inline float32x4 recip_s(const float32x4& s) noexcept
        {
            return _mm_rcp_ps(s);
        }

        inline float32x4 sqrt_s(const float32x4& s) noexcept
        {
            return _mm_sqrt_ps(s);
        }

        inline float32x4 rsqrt_s(const float32x4& s) noexcept
        {
            return _mm_rsqrt_ps(s);
        }

        inline float32x4 min_ss(
            const float32x4& s1, const float32x4& s2) noexcept
        {
            return _mm_min_ps(s1, s2);
        }

        inline float32x4 max_ss(
            const float32x4& s1, const float32x4& s2) noexcept
        {
            return _mm_max_ps(s1, s2);
        }

        template<typename T, typename U>
        inline float32x4 mask_ss(
            const bool32x4& conditions,
            const float32x4& values) noexcept
        {
            return _mm_and_ps(conditions, values);
        }

        template<typename T, typename U>
        inline float32x4 select_sss(
            const bool32x4& conditions,
            const float32x4& values,
            const float32x4& otherwise) noexcept
        {
            return _mm_or_ps(
                _mm_and_ps(conditions, values),
                _mm_andnot_ps(conditions, otherwise));
        }

        inline bool32x4 less_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmplt_ps(lhs, rhs);
        }

        inline bool32x4 less_equal_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmple_ps(lhs, rhs);
        }

        inline bool32x4 greater_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmpgt_ps(lhs, rhs);
        }

        inline bool32x4 greater_equal_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmpge_ps(lhs, rhs);
        }

        inline bool32x4 equal_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmpeq_ps(lhs, rhs);
        }

        inline bool32x4 not_equal_ss(
            const float32x4& lhs, const float32x4& rhs) noexcept
        {
            return _mm_cmpneq_ps(lhs, rhs);
        }
    }
}
