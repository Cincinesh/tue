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

#include <type_traits>

#include "../../../simd.hpp"

#ifdef TUE_SSE2
#include <emmintrin.h>
#else
#include <mmintrin.h>
#endif

namespace tue
{
    template<>
    class alignas(tue::detail_::alignof_simd<float, 4>())
    simd<float, 4>
    {
        __m128 underlying_;

    private:
        template<typename U>
        static float32x4 explicit_cast(const simd<U, 4>& s) noexcept
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
            underlying_(_mm_set1_ps(x))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 2>>
        inline simd(
            float x, float y) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 4>>
        inline simd(
            float x, float y, float z, float w) noexcept
        :
            underlying_(_mm_setr_ps(x, y, z, w))
        {
        }

        template<int M = 4, typename = std::enable_if_t<M == 8>>
        inline simd(
            float s0, float s1, float s2, float s3,
            float s4, float s5, float s6, float s7) noexcept;

        template<int M = 4, typename = std::enable_if_t<M == 16>>
        inline simd(
            float  s0, float  s1, float  s2, float  s3,
            float  s4, float  s5, float  s6, float  s7,
            float  s8, float  s9, float s10, float s11,
            float s12, float s13, float s14, float s15) noexcept;

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

        static float32x4 zero() noexcept
        {
            return _mm_setzero_ps();
        }

        static float32x4 load(const float* data) noexcept
        {
            return _mm_load_ps(data);
        }

        static float32x4 loadu(const float* data) noexcept
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
}

#include "bool32x4.sse.hpp"

namespace tue
{
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
            return _mm_xor_ps(s, float32x4(binary_float(0x80000000u)));
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

#ifndef TUE_SSE2
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4799)
#endif
        inline void copy_mm_to_xmm(
            const __m64& mm0, const __m64& mm1, __m128& xmm) noexcept
        {
            union
            {
                __m64 mm[2];
                __m128 xmm;
            }
            u;
            u.mm[0] = mm0;
            u.mm[1] = mm1;
            xmm = u.xmm;
        }

        inline void copy_xmm_to_mm(
            const __m128& xmm, __m64& mm0, __m64& mm1) noexcept
        {
            union
            {
                __m128 xmm;
                __m64 mm[2];
            }
            u;
            u.xmm = xmm;
            mm0 = u.mm[0];
            mm1 = u.mm[1];
        }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#endif

        inline void sincos_s(
            const float32x4& s,
            float32x4& sin_out,
            float32x4& cos_out) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // sincos_ps(). See the top of this file for details.
            __m128 x = s;

            __m128 xmm1, xmm2, xmm3 = _mm_setzero_ps(), sign_bit_sin, y;
#ifdef TUE_SSE2
            __m128i emm0, emm2, emm4;
#else
            __m64 mm0, mm1, mm2, mm3, mm4, mm5;
#endif
            sign_bit_sin = x;

            /* take the absolute value */
            x = _mm_and_ps(x, _mm_set1_ps(binary_float(~0x80000000)));

            /* extract the sign bit (upper one) */
            sign_bit_sin = _mm_and_ps(
                sign_bit_sin, _mm_set1_ps(binary_float(0x80000000)));

            /* scale by 4/Pi */
            y = _mm_mul_ps(x, _mm_set1_ps(1.27323954473516f));

#ifdef TUE_SSE2
            /* store the integer part of y in emm2 */
            emm2 = _mm_cvttps_epi32(y);

            /* j=(j+1) & (~1) (see the cephes sources) */
            emm2 = _mm_add_epi32(emm2, _mm_set1_epi32(1));
            emm2 = _mm_and_si128(emm2, _mm_set1_epi32(~1));
            y = _mm_cvtepi32_ps(emm2);

            emm4 = emm2;

            /* get the swap sign flag for the sine */
            emm0 = _mm_and_si128(emm2, _mm_set1_epi32(4));
            emm0 = _mm_slli_epi32(emm0, 29);
            __m128 swap_sign_bit_sin = _mm_castsi128_ps(emm0);

            /* get the polynom selection mask for the sine*/
            emm2 = _mm_and_si128(emm2, _mm_set1_epi32(2));
            emm2 = _mm_cmpeq_epi32(emm2, _mm_setzero_si128());
            __m128 poly_mask = _mm_castsi128_ps(emm2);

            /* get the sign flag for the cosine */
            emm4 = _mm_sub_epi32(emm4, _mm_set1_epi32(2));
            emm4 = _mm_andnot_si128(emm4, _mm_set1_epi32(4));
            emm4 = _mm_slli_epi32(emm4, 29);
            __m128 sign_bit_cos = _mm_castsi128_ps(emm4);
#else
            /* store the integer part of y in mm2:mm3 */
            xmm3 = _mm_movehl_ps(xmm3, y);
            mm2 = _mm_cvttps_pi32(y);
            mm3 = _mm_cvttps_pi32(xmm3);

            /* j=(j+1) & (~1) (see the cephes sources) */
            mm2 = _mm_add_pi32(mm2, _mm_set1_pi32(1));
            mm3 = _mm_add_pi32(mm3, _mm_set1_pi32(1));
            mm2 = _mm_and_si64(mm2, _mm_set1_pi32(~1));
            mm3 = _mm_and_si64(mm3, _mm_set1_pi32(~1));

            y = _mm_cvtpi32x2_ps(mm2, mm3);

            mm4 = mm2;
            mm5 = mm3;

            /* get the swap sign flag for the sine */
            mm0 = _mm_and_si64(mm2, _mm_set1_pi32(4));
            mm1 = _mm_and_si64(mm3, _mm_set1_pi32(4));
            mm0 = _mm_slli_pi32(mm0, 29);
            mm1 = _mm_slli_pi32(mm1, 29);
            __m128 swap_sign_bit_sin;
            copy_mm_to_xmm(mm0, mm1, swap_sign_bit_sin);

            /* get the polynom selection mask for the sine */
            mm2 = _mm_and_si64(mm2, _mm_set1_pi32(2));
            mm3 = _mm_and_si64(mm3, _mm_set1_pi32(2));
            mm2 = _mm_cmpeq_pi32(mm2, _mm_setzero_si64());
            mm3 = _mm_cmpeq_pi32(mm3, _mm_setzero_si64());
            __m128 poly_mask;
            copy_mm_to_xmm(mm2, mm3, poly_mask);

            /* get the sign flag for the cosine */
            mm4 = _mm_sub_pi32(mm4, _mm_set1_pi32(2));
            mm5 = _mm_sub_pi32(mm5, _mm_set1_pi32(2));
            mm4 = _mm_andnot_si64(mm4, _mm_set1_pi32(4));
            mm5 = _mm_andnot_si64(mm5, _mm_set1_pi32(4));
            mm4 = _mm_slli_pi32(mm4, 29);
            mm5 = _mm_slli_pi32(mm5, 29);
            __m128 sign_bit_cos;
            copy_mm_to_xmm(mm4, mm5, sign_bit_cos);
            _mm_empty(); /* good-bye mmx */
#endif
            sign_bit_sin = _mm_xor_ps(sign_bit_sin, swap_sign_bit_sin);

            /* The magic pass: "Extended precision modular arithmetic"
               x = ((x - y * DP1) - y * DP2) - y * DP3; */
            xmm1 = _mm_set1_ps(-0.78515625f);
            xmm2 = _mm_set1_ps(-2.4187564849853515625e-4f);
            xmm3 = _mm_set1_ps(-3.77489497744594108e-8f);
            xmm1 = _mm_mul_ps(y, xmm1);
            xmm2 = _mm_mul_ps(y, xmm2);
            xmm3 = _mm_mul_ps(y, xmm3);
            x = _mm_add_ps(x, xmm1);
            x = _mm_add_ps(x, xmm2);
            x = _mm_add_ps(x, xmm3);

            /* Evaluate the first polynom  (0 <= x <= Pi/4) */
            __m128 z = _mm_mul_ps(x,x);
            y = _mm_set1_ps(2.443315711809948e-5f);

            y = _mm_mul_ps(y, z);
            y = _mm_add_ps(y, _mm_set1_ps(-1.388731625493765e-3f));
            y = _mm_mul_ps(y, z);
            y = _mm_add_ps(y, _mm_set1_ps(4.166664568298827e-2f));
            y = _mm_mul_ps(y, z);
            y = _mm_mul_ps(y, z);
            __m128 tmp = _mm_mul_ps(z, _mm_set1_ps(0.5f));
            y = _mm_sub_ps(y, tmp);
            y = _mm_add_ps(y, _mm_set1_ps(1.0f));

            /* Evaluate the second polynom  (Pi/4 <= x <= 0) */
            __m128 y2 = _mm_set1_ps(-1.9515295891e-4f);
            y2 = _mm_mul_ps(y2, z);
            y2 = _mm_add_ps(y2, _mm_set1_ps(8.3321608736e-3f));
            y2 = _mm_mul_ps(y2, z);
            y2 = _mm_add_ps(y2, _mm_set1_ps(-1.6666654611e-1f));
            y2 = _mm_mul_ps(y2, z);
            y2 = _mm_mul_ps(y2, x);
            y2 = _mm_add_ps(y2, x);

            /* select the correct result from the two polynoms */
            xmm3 = poly_mask;
            __m128 ysin2 = _mm_and_ps(xmm3, y2);
            __m128 ysin1 = _mm_andnot_ps(xmm3, y);
            y2 = _mm_sub_ps(y2,ysin2);
            y = _mm_sub_ps(y, ysin1);

            xmm1 = _mm_add_ps(ysin1,ysin2);
            xmm2 = _mm_add_ps(y,y2);

            /* update the sign */
            sin_out = _mm_xor_ps(xmm1, sign_bit_sin);
            cos_out = _mm_xor_ps(xmm2, sign_bit_cos);
        }

        inline float32x4 sin_s(const float32x4& s) noexcept
        {
            float32x4 sin, cos;
            sincos_s(s, sin, cos);
            return sin;
        }

        inline float32x4 cos_s(const float32x4& s) noexcept
        {
            float32x4 sin, cos;
            sincos_s(s, sin, cos);
            return cos;
        }

        inline float32x4 exp_s(const float32x4& s) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // exp_ps(). See the top of this file for details.
            __m128 x = s;

            __m128 tmp = _mm_setzero_ps(), fx;
#ifdef TUE_SSE2
            __m128i emm0;
#else
            __m64 mm0, mm1;
#endif
            __m128 one = _mm_set1_ps(1.0f);

            x = _mm_min_ps(x, _mm_set1_ps(88.3762626647949f));
            x = _mm_max_ps(x, _mm_set1_ps(-88.3762626647949f));

            /* express exp(x) as exp(g + n*log(2)) */
            fx = _mm_mul_ps(x, _mm_set1_ps(1.44269504088896341f));
            fx = _mm_add_ps(fx, _mm_set1_ps(0.5f));

            /* how to perform a floorf with SSE: just below */
#ifndef TUE_SSE2
            /* step 1 : cast to int */
            tmp = _mm_movehl_ps(tmp, fx);
            mm0 = _mm_cvttps_pi32(fx);
            mm1 = _mm_cvttps_pi32(tmp);

            /* step 2 : cast back to float */
            tmp = _mm_cvtpi32x2_ps(mm0, mm1);
            _mm_empty();
#else
            emm0 = _mm_cvttps_epi32(fx);
            tmp = _mm_cvtepi32_ps(emm0);
#endif
            /* if greater, substract 1 */
            __m128 mask = _mm_cmpgt_ps(tmp, fx);
            mask = _mm_and_ps(mask, one);
            fx = _mm_sub_ps(tmp, mask);

            tmp = _mm_mul_ps(fx, _mm_set1_ps(0.693359375f));
            __m128 z = _mm_mul_ps(fx, _mm_set1_ps(-2.12194440e-4f));
            x = _mm_sub_ps(x, tmp);
            x = _mm_sub_ps(x, z);

            z = _mm_mul_ps(x, x);

            __m128 y = _mm_set1_ps(1.9875691500e-4f);
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(1.3981999507e-3f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(8.3334519073e-3f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(4.1665795894e-2f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(1.6666665459e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(5.0000001201e-1f));
            y = _mm_mul_ps(y, z);
            y = _mm_add_ps(y, x);
            y = _mm_add_ps(y, one);

            /* build 2^n */
#ifndef TUE_SSE2
            z = _mm_movehl_ps(z, fx);
            mm0 = _mm_cvttps_pi32(fx);
            mm1 = _mm_cvttps_pi32(z);
            mm0 = _mm_add_pi32(mm0, _mm_set1_pi32(0x7F));
            mm1 = _mm_add_pi32(mm1, _mm_set1_pi32(0x7F));
            mm0 = _mm_slli_pi32(mm0, 23);
            mm1 = _mm_slli_pi32(mm1, 23);

            __m128 pow2n;
            copy_mm_to_xmm(mm0, mm1, pow2n);
            _mm_empty();
#else
            emm0 = _mm_cvttps_epi32(fx);
            emm0 = _mm_add_epi32(emm0, _mm_set1_epi32(0x7F));
            emm0 = _mm_slli_epi32(emm0, 23);
            __m128 pow2n = _mm_castsi128_ps(emm0);
#endif
            y = _mm_mul_ps(y, pow2n);
            return y;
        }

        inline float32x4 log_s(const float32x4& s) noexcept
        {
            // This function's implementation is based on Julien Pommier's
            // log_ps(). See the top of this file for details.
            __m128 x = s;

#ifdef TUE_SSE2
            __m128i emm0;
#else
            __m64 mm0, mm1;
#endif
            __m128 one = _mm_set1_ps(1.0f);

            __m128 invalid_mask = _mm_cmple_ps(x, _mm_setzero_ps());

            /* cut off denormalized stuff */
            x = _mm_max_ps(x, _mm_set1_ps(binary_float(0x00800000)));

            /* part 1: x = frexpf(x, &e); */
#ifndef TUE_SSE2
            copy_xmm_to_mm(x, mm0, mm1);
            mm0 = _mm_srli_pi32(mm0, 23);
            mm1 = _mm_srli_pi32(mm1, 23);

            /* now e=mm0:mm1 contain the really base-2 exponent */
            mm0 = _mm_sub_pi32(mm0, _mm_set1_pi32(0x7F));
            mm1 = _mm_sub_pi32(mm1, _mm_set1_pi32(0x7F));
            __m128 e = _mm_cvtpi32x2_ps(mm0, mm1);
            _mm_empty(); /* bye bye mmx */
#else
            emm0 = _mm_srli_epi32(_mm_castps_si128(x), 23);

            emm0 = _mm_sub_epi32(emm0, _mm_set1_epi32(0x7F));
            __m128 e = _mm_cvtepi32_ps(emm0);
#endif
            e = _mm_add_ps(e, one);

            /* keep only the fractional part */
            x = _mm_and_ps(x, _mm_set1_ps(binary_float(~0x7f800000)));
            x = _mm_or_ps(x, _mm_set1_ps(0.5f));

            /* part2:
            if( x < SQRTHF ) {
            e -= 1;
            x = x + x - 1.0;
            } else { x = x - 1.0; }
            */
            __m128 mask = _mm_cmplt_ps(x, _mm_set1_ps(0.707106781186547524f));
            __m128 tmp = _mm_and_ps(x, mask);
            x = _mm_sub_ps(x, one);
            e = _mm_sub_ps(e, _mm_and_ps(one, mask));
            x = _mm_add_ps(x, tmp);

            __m128 z = _mm_mul_ps(x, x);

            __m128 y = _mm_set1_ps(7.0376836292e-2f);
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(-1.1514610310e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(1.1676998740e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(-1.2420140846e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(1.4249322787e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(-1.6668057665e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(2.0000714765e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(-2.4999993993e-1f));
            y = _mm_mul_ps(y, x);
            y = _mm_add_ps(y, _mm_set1_ps(3.3333331174e-1f));
            y = _mm_mul_ps(y, x);

            y = _mm_mul_ps(y, z);

            tmp = _mm_mul_ps(e, _mm_set1_ps(-2.12194440e-4f));
            y = _mm_add_ps(y, tmp);

            tmp = _mm_mul_ps(z, _mm_set1_ps(0.5f));
            y = _mm_sub_ps(y, tmp);

            tmp = _mm_mul_ps(e, _mm_set1_ps(0.693359375f));
            x = _mm_add_ps(x, y);
            x = _mm_add_ps(x, tmp);
            x = _mm_or_ps(x, invalid_mask); // negative arg will be NAN
            return x;
        }

        inline float32x4 abs_s(const float32x4& s) noexcept
        {
            return _mm_and_ps(s, float32x4(binary_float(0x7FFFFFFF)));
        }

        inline float32x4 pow_ss(
            const float32x4& bases, const float32x4& exponents) noexcept
        {
            return exp_s(float32x4(_mm_mul_ps(log_s(bases), exponents)));
        }

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

        inline float32x4 mask_ss(
            const bool32x4& conditions,
            const float32x4& values) noexcept
        {
            return _mm_and_ps(conditions, values);
        }

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
