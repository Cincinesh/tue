//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

// This file contains code based on Julien Pommier's sse_mathfun.h originally
// published at http://gruntthepeon.free.fr/ssemath/ under the following
// license:
//
// Copyright (C) 2007 Julien Pommier
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from
// the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software in
//    a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//
// (this is the zlib license)

#pragma once

#include <xmmintrin.h>
#include <emmintrin.h>

#include <type_traits>

#include "../../../simd.hpp"

namespace tue
{
    template<>
    class alignas(tue::detail_::alignof_simd<double, 2>())
    simd<double, 2>
    {
        __m128d underlying_;

    private:
        template<typename U>
        static float64x2 explicit_cast(const simd<U, 2>& s) noexcept
        {
            return {
                float(s.data()[0]),
                float(s.data()[1]),
            };
        }

    public:
        using component_type = double;

        static constexpr int component_count = 2;

        static constexpr bool is_accelerated = true;

        simd() noexcept = default;

        explicit simd(double x) noexcept
        :
            underlying_(_mm_set1_pd(x))
        {
        }

        template<int M = 2, typename = std::enable_if_t<M == 2>>
        inline simd(
            double x, double y) noexcept
        :
            underlying_(_mm_setr_pd(x, y))
        {
        }

        template<int M = 2, typename = std::enable_if_t<M == 4>>
        inline simd(
            double x, double y, double z, double w) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 8>>
        inline simd(
            double s0, double s1, double s2, double s3,
            double s4, double s5, double s6, double s7) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 16>>
        inline simd(
            double  s0, double  s1, double  s2, double  s3,
            double  s4, double  s5, double  s6, double  s7,
            double  s8, double  s9, double s10, double s11,
            double s12, double s13, double s14, double s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 2>& s) noexcept
        {
            *this = explicit_cast(s);
        }

        simd(__m128d underlying) noexcept
        :
            underlying_(underlying)
        {
        }

        operator __m128d() const noexcept
        {
            return underlying_;
        }

        static float64x2 zero() noexcept
        {
            return _mm_setzero_pd();
        }

        static float64x2 load(const double* data) noexcept
        {
            return _mm_load_pd(data);
        }

        static float64x2 loadu(const double* data) noexcept
        {
            return _mm_loadu_pd(data);
        }

        void store(double* data) const noexcept
        {
            _mm_store_pd(data, underlying_);
        }

        void storeu(double* data) const noexcept
        {
            _mm_storeu_pd(data, underlying_);
        }

        const double* data() const noexcept
        {
            return reinterpret_cast<const double*>(&underlying_);
        }

        double* data() noexcept
        {
            return reinterpret_cast<double*>(&underlying_);
        }
    };
}

#include "bool64x2.sse2.hpp"

namespace tue
{
    namespace detail_
    {
        inline float64x2 unary_plus_operator_s(const float64x2& s) noexcept
        {
            return s;
        }

        inline float64x2& pre_increment_operator_s(float64x2& s) noexcept
        {
            return s = _mm_add_pd(s, float64x2(1.0f));
        }

        inline float64x2 post_increment_operator_s(float64x2& s) noexcept
        {
            const auto result = s;
            s = _mm_add_pd(s, float64x2(1.0f));
            return result;
        }

        inline float64x2 unary_minus_operator_s(const float64x2& s) noexcept
        {
            return _mm_xor_pd(
                s, float64x2(binary_double(0x8000000000000000ull)));
        }

        inline float64x2& pre_decrement_operator_s(float64x2& s) noexcept
        {
            return s = _mm_sub_pd(s, float64x2(1.0f));
        }

        inline float64x2 post_decrement_operator_s(float64x2& s) noexcept
        {
            const auto result = s;
            s = _mm_sub_pd(s, float64x2(1.0f));
            return result;
        }

        inline float64x2 addition_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_add_pd(lhs, rhs);
        }

        inline float64x2 subtraction_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_sub_pd(lhs, rhs);
        }

        inline float64x2 multiplication_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_mul_pd(lhs, rhs);
        }

        inline float64x2 division_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_div_pd(lhs, rhs);
        }

        inline float64x2& addition_assignment_operator_ss(
            float64x2& lhs, const float64x2& rhs) noexcept
        {
            return lhs = _mm_add_pd(lhs, rhs);
        }

        inline float64x2& subtraction_assignment_operator_ss(
            float64x2& lhs, const float64x2& rhs) noexcept
        {
            return lhs = _mm_sub_pd(lhs, rhs);
        }

        inline float64x2& multiplication_assignment_operator_ss(
            float64x2& lhs, const float64x2& rhs) noexcept
        {
            return lhs = _mm_mul_pd(lhs, rhs);
        }

        inline float64x2& division_assignment_operator_ss(
            float64x2& lhs, const float64x2& rhs) noexcept
        {
            return lhs = _mm_div_pd(lhs, rhs);
        }

        inline bool equality_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_movemask_pd(_mm_cmpneq_pd(lhs, rhs)) == 0;
        }

        inline bool inequality_operator_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_movemask_pd(_mm_cmpneq_pd(lhs, rhs)) != 0;
        }

        inline void sincos_s(
            const float64x2& s,
            float64x2& sin_out,
            float64x2& cos_out) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // sincos_ps(). See the top of this file for details.
            __m128d x = s;

            __m128d xmm1, xmm2, xmm3 = _mm_setzero_pd(), sign_bit_sin, y;
            __m128i emm0, emm2, emm4;

            sign_bit_sin = x;

            /* take the absolute value */
            x = _mm_and_pd(
                x, _mm_set1_pd(binary_double(~0x8000000000000000ull)));

            /* extract the sign bit (upper one) */
            sign_bit_sin = _mm_and_pd(
                sign_bit_sin,
                _mm_set1_pd(binary_double(0x8000000000000000ull)));

            /* scale by 4/Pi */
            y = _mm_mul_pd(x, _mm_set1_pd(1.27323954473516));

            /* store the integer part of y in emm2 */
            emm2 = _mm_cvttpd_epi32(y);

            /* j=(j+1) & (~1) (see the cephes sources) */
            emm2 = _mm_add_epi32(emm2, _mm_set1_epi32(1));
            emm2 = _mm_and_si128(emm2, _mm_set1_epi32(~1));
            y = _mm_cvtepi32_pd(emm2);

            /* Convert to epi64 */
            emm2 = _mm_shuffle_epi32(emm2, _MM_SHUFFLE(3, 1, 2, 0));

            emm4 = emm2;

            /* get the swap sign flag for the sine */
            emm0 = _mm_and_si128(emm2, _mm_set1_epi64x(4));
            emm0 = _mm_slli_epi64(emm0, 61);
            __m128d swap_sign_bit_sin = _mm_castsi128_pd(emm0);

            /* get the polynom selection mask for the sine*/
            emm2 = _mm_and_si128(emm2, _mm_set1_epi64x(2));
            emm2 = _mm_cmpeq_epi32(emm2, _mm_setzero_si128());
            emm2 = _mm_shuffle_epi32(emm2, _MM_SHUFFLE(2, 2, 0, 0));
            __m128d poly_mask = _mm_castsi128_pd(emm2);

            /* The magic pass: "Extended precision modular arithmetic"
               x = ((x - y * DP1) - y * DP2) - y * DP3; */
            xmm1 = _mm_set1_pd(-0.78515625);
            xmm2 = _mm_set1_pd(-2.4187564849853515625e-4);
            xmm3 = _mm_set1_pd(-3.77489497744594108e-8);
            xmm1 = _mm_mul_pd(y, xmm1);
            xmm2 = _mm_mul_pd(y, xmm2);
            xmm3 = _mm_mul_pd(y, xmm3);
            x = _mm_add_pd(x, xmm1);
            x = _mm_add_pd(x, xmm2);
            x = _mm_add_pd(x, xmm3);

            /* get the sign flag for the cosine */
            emm4 = _mm_sub_epi64(emm4, _mm_set1_epi64x(2));
            emm4 = _mm_andnot_si128(emm4, _mm_set1_epi64x(4));
            emm4 = _mm_slli_epi64(emm4, 61);
            __m128d sign_bit_cos = _mm_castsi128_pd(emm4);

            sign_bit_sin = _mm_xor_pd(sign_bit_sin, swap_sign_bit_sin);

            /* Evaluate the first polynom  (0 <= x <= Pi/4) */
            __m128d z = _mm_mul_pd(x,x);
            y = _mm_set1_pd(2.443315711809948e-5);

            y = _mm_mul_pd(y, z);
            y = _mm_add_pd(y, _mm_set1_pd(-1.388731625493765e-3));
            y = _mm_mul_pd(y, z);
            y = _mm_add_pd(y, _mm_set1_pd(4.166664568298827e-2));
            y = _mm_mul_pd(y, z);
            y = _mm_mul_pd(y, z);
            __m128d tmp = _mm_mul_pd(z, _mm_set1_pd(0.5));
            y = _mm_sub_pd(y, tmp);
            y = _mm_add_pd(y, _mm_set1_pd(1.0));

            /* Evaluate the second polynom  (Pi/4 <= x <= 0) */
            __m128d y2 = _mm_set1_pd(-1.9515295891e-4);
            y2 = _mm_mul_pd(y2, z);
            y2 = _mm_add_pd(y2, _mm_set1_pd(8.3321608736e-3));
            y2 = _mm_mul_pd(y2, z);
            y2 = _mm_add_pd(y2, _mm_set1_pd(-1.6666654611e-1));
            y2 = _mm_mul_pd(y2, z);
            y2 = _mm_mul_pd(y2, x);
            y2 = _mm_add_pd(y2, x);

            /* select the correct result from the two polynoms */
            xmm3 = poly_mask;
            __m128d ysin2 = _mm_and_pd(xmm3, y2);
            __m128d ysin1 = _mm_andnot_pd(xmm3, y);
            y2 = _mm_sub_pd(y2,ysin2);
            y = _mm_sub_pd(y, ysin1);

            xmm1 = _mm_add_pd(ysin1,ysin2);
            xmm2 = _mm_add_pd(y,y2);

            /* update the sign */
            sin_out = _mm_xor_pd(xmm1, sign_bit_sin);
            cos_out = _mm_xor_pd(xmm2, sign_bit_cos);
        }

        inline float64x2 sin_s(const float64x2& s) noexcept
        {
            float64x2 sin, cos;
            sincos_s(s, sin, cos);
            return sin;
        }

        inline float64x2 cos_s(const float64x2& s) noexcept
        {
            float64x2 sin, cos;
            sincos_s(s, sin, cos);
            return cos;
        }

        inline float64x2 exp_s(const float64x2& s) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // exp_ps(). See the top of this file for details.
            __m128d x = s;

            __m128d tmp = _mm_setzero_pd(), fx;
            __m128i emm0;

            __m128d one = _mm_set1_pd(1.0);

            x = _mm_min_pd(x, _mm_set1_pd(88.3762626647949));
            x = _mm_max_pd(x, _mm_set1_pd(-88.3762626647949));

            /* express exp(x) as exp(g + n*log(2)) */
            fx = _mm_mul_pd(x, _mm_set1_pd(1.44269504088896341));
            fx = _mm_add_pd(fx, _mm_set1_pd(0.5));

            /* how to perform a floorf with SSE: just below */
            emm0 = _mm_cvttpd_epi32(fx);
            tmp = _mm_cvtepi32_pd(emm0);

            /* if greater, substract 1 */
            __m128d mask = _mm_cmpgt_pd(tmp, fx);
            mask = _mm_and_pd(mask, one);
            fx = _mm_sub_pd(tmp, mask);

            tmp = _mm_mul_pd(fx, _mm_set1_pd(0.693359375));
            __m128d z = _mm_mul_pd(fx, _mm_set1_pd(-2.12194440e-4));
            x = _mm_sub_pd(x, tmp);
            x = _mm_sub_pd(x, z);

            z = _mm_mul_pd(x, x);

            __m128d y = _mm_set1_pd(1.9875691500e-4);
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(1.3981999507e-3));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(8.3334519073e-3));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(4.1665795894e-2));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(1.6666665459e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(5.0000001201e-1));
            y = _mm_mul_pd(y, z);
            y = _mm_add_pd(y, x);
            y = _mm_add_pd(y, one);

            /* build 2^n */
            emm0 = _mm_cvttpd_epi32(fx);
            emm0 = _mm_shuffle_epi32(emm0, _MM_SHUFFLE(3, 1, 2, 0));
            emm0 = _mm_add_epi64(emm0, _mm_set1_epi64x(0x3FF));
            emm0 = _mm_slli_epi64(emm0, 52);
            __m128d pow2n = _mm_castsi128_pd(emm0);

            y = _mm_mul_pd(y, pow2n);
            return y;
        }

        inline float64x2 log_s(const float64x2& s) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // log_ps(). See the top of this file for details.
            __m128d x = s;

            __m128i emm0;

            __m128d one = _mm_set1_pd(1.0);

            __m128d invalid_mask = _mm_cmple_pd(x, _mm_setzero_pd());

            /* cut off denormalized stuff */
            x = _mm_max_pd(x, _mm_set1_pd(binary_double(1ull << 52ull)));

            /* part 1: x = frexpf(x, &e); */
            emm0 = _mm_srli_epi64(_mm_castpd_si128(x), 52);

            /* keep only the fractional part */
            x = _mm_and_pd(x, _mm_set1_pd(binary_double(~(0x7FFull << 52ull))));
            x = _mm_or_pd(x, _mm_set1_pd(0.5));

            emm0 = _mm_sub_epi64(emm0, _mm_set1_epi64x(0x3FF));
            emm0 = _mm_shuffle_epi32(emm0, _MM_SHUFFLE(3, 1, 2, 0));
            __m128d e = _mm_cvtepi32_pd(emm0);

            e = _mm_add_pd(e, one);

            /* part2:
            if( x < SQRTHF ) {
            e -= 1;
            x = x + x - 1.0;
            } else { x = x - 1.0; }
            */
            __m128d mask = _mm_cmplt_pd(x, _mm_set1_pd(0.707106781186547524));
            __m128d tmp = _mm_and_pd(x, mask);
            x = _mm_sub_pd(x, one);
            e = _mm_sub_pd(e, _mm_and_pd(one, mask));
            x = _mm_add_pd(x, tmp);

            __m128d z = _mm_mul_pd(x, x);

            __m128d y = _mm_set1_pd(7.0376836292e-2);
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(-1.1514610310e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(1.1676998740e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(-1.2420140846e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(1.4249322787e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(-1.6668057665e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(2.0000714765e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(-2.4999993993e-1));
            y = _mm_mul_pd(y, x);
            y = _mm_add_pd(y, _mm_set1_pd(3.3333331174e-1));
            y = _mm_mul_pd(y, x);

            y = _mm_mul_pd(y, z);

            tmp = _mm_mul_pd(e, _mm_set1_pd(-2.12194440e-4));
            y = _mm_add_pd(y, tmp);

            tmp = _mm_mul_pd(z, _mm_set1_pd(0.5));
            y = _mm_sub_pd(y, tmp);

            tmp = _mm_mul_pd(e, _mm_set1_pd(0.693359375));
            x = _mm_add_pd(x, y);
            x = _mm_add_pd(x, tmp);
            x = _mm_or_pd(x, invalid_mask); // negative arg will be NAN
            return x;
        }

        inline float64x2 abs_s(const float64x2& s) noexcept
        {
            return _mm_and_pd(
                s, float64x2(binary_double(0x7FFFFFFFFFFFFFFFull)));
        }

        inline float64x2 pow_ss(
            const float64x2& bases, const float64x2& exponents) noexcept
        {
            return exp_s(float64x2(_mm_mul_pd(log_s(bases), exponents)));
        }

        inline float64x2 recip_s(const float64x2& s) noexcept
        {
            return _mm_div_pd(_mm_set1_pd(1.0), s);
        }

        inline float64x2 sqrt_s(const float64x2& s) noexcept
        {
            return _mm_sqrt_pd(s);
        }

        inline float64x2 rsqrt_s(const float64x2& s) noexcept
        {
            return _mm_div_pd(_mm_set1_pd(1.0), _mm_sqrt_pd(s));
        }

        inline float64x2 min_ss(
            const float64x2& s1, const float64x2& s2) noexcept
        {
            return _mm_min_pd(s1, s2);
        }

        inline float64x2 max_ss(
            const float64x2& s1, const float64x2& s2) noexcept
        {
            return _mm_max_pd(s1, s2);
        }

        inline float64x2 mask_ss(
            const bool64x2& conditions,
            const float64x2& values) noexcept
        {
            return _mm_and_pd(conditions, values);
        }

        inline float64x2 select_sss(
            const bool64x2& conditions,
            const float64x2& values,
            const float64x2& otherwise) noexcept
        {
            return _mm_or_pd(
                _mm_and_pd(conditions, values),
                _mm_andnot_pd(conditions, otherwise));
        }

        inline bool64x2 less_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmplt_pd(lhs, rhs);
        }

        inline bool64x2 less_equal_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmple_pd(lhs, rhs);
        }

        inline bool64x2 greater_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmpgt_pd(lhs, rhs);
        }

        inline bool64x2 greater_equal_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmpge_pd(lhs, rhs);
        }

        inline bool64x2 equal_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmpeq_pd(lhs, rhs);
        }

        inline bool64x2 not_equal_ss(
            const float64x2& lhs, const float64x2& rhs) noexcept
        {
            return _mm_cmpneq_pd(lhs, rhs);
        }
    }
}
