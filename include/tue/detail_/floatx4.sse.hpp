//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This file contains code based on Julien Pommier's neon_mathfun.h originally
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
#include "../simd.hpp"

#ifdef TUE_SSE2
#include <emmintrin.h>
#else
#include <mmintrin.h>
#endif

namespace tue {

class floatx4
{
public:
  using component_type = float;

  static constexpr int component_count = 4;

private:
  __m128 underlying_;

public:
  floatx4() noexcept = default;

  explicit floatx4(float s) noexcept
    : underlying_(_mm_set_ps1(s)) {
  }

  floatx4(float x, float y, float z, float w) noexcept
    : underlying_(_mm_setr_ps(x, y, z, w)) {
  }

  floatx4(__m128 underlying) noexcept
    : underlying_(underlying) {
  }

  operator __m128() const noexcept {
    return underlying_;
  }

  static floatx4 zero() noexcept {
    return _mm_setzero_ps();
  }

  static floatx4 load(const float* array) noexcept {
    return _mm_load_ps(array);
  }

  static floatx4 loadu(const float* array) noexcept {
    return _mm_loadu_ps(array);
  }

  void store(float* destination) const noexcept {
    _mm_store_ps(destination, underlying_);
  }

  void storeu(float* destination) const noexcept {
    _mm_storeu_ps(destination, underlying_);
  }

  floatx4 operator+() const noexcept {
    return underlying_;
  }

  floatx4 operator-() const noexcept {
    return _mm_xor_ps(underlying_, detail_::binary_m128(0x80000000u));
  }

  floatx4 operator+(const floatx4& other) const noexcept {
    return _mm_add_ps(underlying_, other);
  }

  floatx4 operator-(const floatx4& other) const noexcept {
    return _mm_sub_ps(underlying_, other);
  }

  floatx4 operator*(const floatx4& other) const noexcept {
    return _mm_mul_ps(underlying_, other);
  }

  floatx4 operator/(const floatx4& other) const noexcept {
    return _mm_div_ps(underlying_, other);
  }

  floatx4& operator++() noexcept {
    return *this = *this + floatx4(1.0f);
  }

  floatx4& operator--() noexcept {
    return *this = *this - floatx4(1.0f);
  }

  floatx4 operator++(int) noexcept {
    const auto result = *this;
    ++*this;
    return result;
  }

  floatx4 operator--(int) noexcept {
    const auto result = *this;
    --*this;
    return result;
  }

  floatx4& operator+=(const floatx4& other) noexcept {
    return *this = *this + other;
  }

  floatx4& operator-=(const floatx4& other) noexcept {
    return *this = *this - other;
  }

  floatx4& operator*=(const floatx4& other) noexcept {
    return *this = *this * other;
  }

  floatx4& operator/=(const floatx4& other) noexcept {
    return *this = *this / other;
  }

  bool operator==(const floatx4& other) const noexcept {
    return _mm_movemask_ps(_mm_cmpneq_ps(underlying_, other)) == 0;
  }

  bool operator!=(const floatx4& other) const noexcept {
    return !(*this == other);
  }
};

namespace math
{
  inline void sincos(
      const floatx4& v,
      floatx4& sin_result,
      floatx4& cos_result) noexcept {
    // This sincos() implementation is based on Julien Pommier's
    // sincos_ps(). See the top of this file for details.
    __m128 x = v;

    __m128 xmm1, xmm2, xmm3 = _mm_setzero_ps(), sign_bit_sin, y;
#ifdef TUE_SSE2
    __m128i emm0, emm2, emm4;
#else
    __m64 mm0, mm1, mm2, mm3, mm4, mm5;
    union {
      __m64 mm[2];
      __m128 xmm;
    } u;
#endif

    sign_bit_sin = x;

    // Take the absolute value
    x = _mm_and_ps(x, detail_::binary_m128(~0x80000000u));

    // Extract the sign bit (upper one)
    sign_bit_sin = _mm_and_ps(sign_bit_sin, detail_::binary_m128(0x80000000u));

    // Scale by 4/Pi
    y = _mm_mul_ps(x, _mm_set_ps1(1.27323954473516f));

#ifdef TUE_SSE2
    // Store the integer part of y in emm2
    emm2 = _mm_cvttps_epi32(y);

    // j=(j+1) & (~1) (see the cephes sources)
    emm2 = _mm_add_epi32(emm2, _mm_set1_epi32(1));
    emm2 = _mm_and_si128(emm2, _mm_set1_epi32(~1));
    y = _mm_cvtepi32_ps(emm2);

    emm4 = emm2;

    // Get the swap sign flag for the sine
    emm0 = _mm_and_si128(emm2, _mm_set1_epi32(4));
    emm0 = _mm_slli_epi32(emm0, 29);
    __m128 swap_sign_bit_sin = _mm_castsi128_ps(emm0);

    // Get the polynom selection mask for the sine
    emm2 = _mm_and_si128(emm2, _mm_set1_epi32(2));
    emm2 = _mm_cmpeq_epi32(emm2, _mm_setzero_si128());
    __m128 poly_mask = _mm_castsi128_ps(emm2);
#else
    // Store the integer part of y in mm2:mm3
    xmm3 = _mm_movehl_ps(xmm3, y);
    mm2 = _mm_cvttps_pi32(y);
    mm3 = _mm_cvttps_pi32(xmm3);

    // j=(j+1) & (~1) (see the cephes sources)
    mm2 = _mm_add_pi32(mm2, _mm_set1_pi32(1));
    mm3 = _mm_add_pi32(mm3, _mm_set1_pi32(1));
    mm2 = _mm_and_si64(mm2, _mm_set1_pi32(~1));
    mm3 = _mm_and_si64(mm3, _mm_set1_pi32(~1));

    y = _mm_cvtpi32x2_ps(mm2, mm3);

    mm4 = mm2;
    mm5 = mm3;

    // Get the swap sign flag for the sine
    mm0 = _mm_and_si64(mm2, _mm_set1_pi32(4));
    mm1 = _mm_and_si64(mm3, _mm_set1_pi32(4));
    mm0 = _mm_slli_pi32(mm0, 29);
    mm1 = _mm_slli_pi32(mm1, 29);
    u.mm[0] = mm0;
    u.mm[1] = mm1;
    __m128 swap_sign_bit_sin = u.xmm;

    // Get the polynom selection mask for the sine
    mm2 = _mm_and_si64(mm2, _mm_set1_pi32(2));
    mm3 = _mm_and_si64(mm3, _mm_set1_pi32(2));
    mm2 = _mm_cmpeq_pi32(mm2, _mm_setzero_si64());
    mm3 = _mm_cmpeq_pi32(mm3, _mm_setzero_si64());
    u.mm[0] = mm2;
    u.mm[1] = mm3;
    __m128 poly_mask = u.xmm;
#endif

    // The magic pass: "Extended precision modular arithmetic"
    // x = ((x - y * DP1) - y * DP2) - y * DP3;
    xmm1 = _mm_set_ps1(-0.78515625f);
    xmm2 = _mm_set_ps1(-2.4187564849853515625e-4f);
    xmm3 = _mm_set_ps1(-3.77489497744594108e-8f);
    xmm1 = _mm_mul_ps(y, xmm1);
    xmm2 = _mm_mul_ps(y, xmm2);
    xmm3 = _mm_mul_ps(y, xmm3);
    x = _mm_add_ps(x, xmm1);
    x = _mm_add_ps(x, xmm2);
    x = _mm_add_ps(x, xmm3);

#ifdef TUE_SSE2
    emm4 = _mm_sub_epi32(emm4, _mm_set1_epi32(2));
    emm4 = _mm_andnot_si128(emm4, _mm_set1_epi32(4));
    emm4 = _mm_slli_epi32(emm4, 29);
    __m128 sign_bit_cos = _mm_castsi128_ps(emm4);
#else
    // Get the sign flag for the cosine
    mm4 = _mm_sub_pi32(mm4, _mm_set1_pi32(2));
    mm5 = _mm_sub_pi32(mm5, _mm_set1_pi32(2));
    mm4 = _mm_andnot_si64(mm4, _mm_set1_pi32(4));
    mm5 = _mm_andnot_si64(mm5, _mm_set1_pi32(4));
    mm4 = _mm_slli_pi32(mm4, 29);
    mm5 = _mm_slli_pi32(mm5, 29);
    u.mm[0] = mm4;
    u.mm[1] = mm5;
    __m128 sign_bit_cos = u.xmm;
    _mm_empty(); // Goodbye MMX
#endif

    sign_bit_sin = _mm_xor_ps(sign_bit_sin, swap_sign_bit_sin);

    // Evaluate the first polynom (0 <= x <= Pi/4)
    __m128 z = _mm_mul_ps(x,x);
    y = _mm_set_ps1(2.443315711809948e-5f);

    y = _mm_mul_ps(y, z);
    y = _mm_add_ps(y, _mm_set_ps1(-1.388731625493765e-3f));
    y = _mm_mul_ps(y, z);
    y = _mm_add_ps(y, _mm_set_ps1(4.166664568298827e-2f));
    y = _mm_mul_ps(y, z);
    y = _mm_mul_ps(y, z);
    __m128 tmp = _mm_mul_ps(z, _mm_set_ps1(0.5f));
    y = _mm_sub_ps(y, tmp);
    y = _mm_add_ps(y, _mm_set_ps1(1.0f));

    // Evaluate the second polynom (Pi/4 <= x <= 0)
    __m128 y2 = _mm_set_ps1(-1.9515295891e-4f);
    y2 = _mm_mul_ps(y2, z);
    y2 = _mm_add_ps(y2, _mm_set_ps1(8.3321608736e-3f));
    y2 = _mm_mul_ps(y2, z);
    y2 = _mm_add_ps(y2, _mm_set_ps1(-1.6666654611e-1f));
    y2 = _mm_mul_ps(y2, z);
    y2 = _mm_mul_ps(y2, x);
    y2 = _mm_add_ps(y2, x);

    // Select the correct result from the two polynoms
    xmm3 = poly_mask;
    __m128 ysin2 = _mm_and_ps(xmm3, y2);
    __m128 ysin1 = _mm_andnot_ps(xmm3, y);
    y2 = _mm_sub_ps(y2,ysin2);
    y = _mm_sub_ps(y, ysin1);

    xmm1 = _mm_add_ps(ysin1,ysin2);
    xmm2 = _mm_add_ps(y,y2);

    // Update the sign
    sin_result = _mm_xor_ps(xmm1, sign_bit_sin);
    cos_result = _mm_xor_ps(xmm2, sign_bit_cos);
  }

  inline floatx4 sin(const floatx4& v) noexcept {
    floatx4 sin_result, cos_result;
    sincos(v, sin_result, cos_result);
    return sin_result;
  }

  inline floatx4 cos(const floatx4& v) noexcept {
    floatx4 sin_result, cos_result;
    sincos(v, sin_result, cos_result);
    return cos_result;
  }

  inline floatx4 exp(const floatx4& v) noexcept {
    // This exp() implementation is based on Julien Pommier's exp_ps(). See
    // the top of this file for details.
    __m128 x = v;

    __m128 tmp = _mm_setzero_ps(), fx;
#ifdef TUE_SSE2
    __m128i emm0;
#else
    __m64 mm0, mm1;
    union {
      __m64 mm[2];
      __m128 xmm;
    } u;
#endif

    __m128 one = _mm_set_ps1(1.0f);

    x = _mm_min_ps(x, _mm_set_ps1(88.3762626647949f));
    x = _mm_max_ps(x, _mm_set_ps1(-88.3762626647949f));

    // Express exp(x) as exp(g + n*log(2))
    fx = _mm_mul_ps(x, _mm_set_ps1(1.44269504088896341f));
    fx = _mm_add_ps(fx, _mm_set_ps1(0.5f));

    // How to perform a floorf with SSE: just below
#ifndef TUE_SSE2
    // Step 1: Cast to int
    tmp = _mm_movehl_ps(tmp, fx);
    mm0 = _mm_cvttps_pi32(fx);
    mm1 = _mm_cvttps_pi32(tmp);
    // Step 2: Cast back to float
    tmp = _mm_cvtpi32x2_ps(mm0, mm1);
#else
    emm0 = _mm_cvttps_epi32(fx);
    tmp  = _mm_cvtepi32_ps(emm0);
#endif

    // If greater, substract 1
    __m128 mask = _mm_cmpgt_ps(tmp, fx);
    mask = _mm_and_ps(mask, one);
    fx = _mm_sub_ps(tmp, mask);

    tmp = _mm_mul_ps(fx, _mm_set_ps1(0.693359375f));
    __m128 z = _mm_mul_ps(fx, _mm_set_ps1(-2.12194440e-4f));
    x = _mm_sub_ps(x, tmp);
    x = _mm_sub_ps(x, z);

    z = _mm_mul_ps(x,x);

    __m128 y = _mm_set_ps1(1.9875691500e-4f);
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(1.3981999507e-3f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(8.3334519073e-3f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(4.1665795894e-2f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(1.6666665459e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(5.0000001201e-1f));
    y = _mm_mul_ps(y, z);
    y = _mm_add_ps(y, x);
    y = _mm_add_ps(y, one);

    // Build 2^n
#ifndef TUE_SSE2
    z = _mm_movehl_ps(z, fx);
    mm0 = _mm_cvttps_pi32(fx);
    mm1 = _mm_cvttps_pi32(z);
    mm0 = _mm_add_pi32(mm0, _mm_set1_pi32(0x7F));
    mm1 = _mm_add_pi32(mm1, _mm_set1_pi32(0x7F));
    mm0 = _mm_slli_pi32(mm0, 23);
    mm1 = _mm_slli_pi32(mm1, 23);
    u.mm[0] = mm0;
    u.mm[1] = mm1;
    __m128 pow2n = u.xmm;
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

  inline floatx4 log(const floatx4& v) noexcept {
    // This log() implementation is based on Julien Pommier's log_ps(). See
    // the top of this file for details.
    __m128 x = v;

#ifdef TUE_SSE2
    __m128i emm0;
#else
    __m64 mm0, mm1;
    union {
      __m64 mm[2];
      __m128 xmm;
    } u;
#endif

    __m128 one = _mm_set_ps1(1.0f);

    __m128 invalid_mask = _mm_cmple_ps(x, _mm_setzero_ps());

    // Cut off denormalized stuff
    x = _mm_max_ps(x, detail_::binary_m128(0x00800000u));

#ifndef TUE_SSE2
    // Part 1: x = frexpf(x, &e);
    u.xmm = x;
    mm0 = _mm_srli_pi32(u.mm[0], 23);
    mm1 = _mm_srli_pi32(u.mm[1], 23);
#else
    emm0 = _mm_srli_epi32(_mm_castps_si128(x), 23);
#endif
    // Keep only the fractional part
    x = _mm_and_ps(x, detail_::binary_m128(~0x7F800000u));
    x = _mm_or_ps(x, _mm_set_ps1(0.5f));

#ifndef TUE_SSE2
    // Now e=mm0:mm1 contain the really base-2 exponent
    mm0 = _mm_sub_pi32(mm0, _mm_set1_pi32(0x7F));
    mm1 = _mm_sub_pi32(mm1, _mm_set1_pi32(0x7F));
    __m128 e = _mm_cvtpi32x2_ps(mm0, mm1);
    _mm_empty(); // Bye bye MMX
#else
    emm0 = _mm_sub_epi32(emm0, _mm_set1_epi32(0x7F));
    __m128 e = _mm_cvtepi32_ps(emm0);
#endif

    e = _mm_add_ps(e, one);

    // Part 2:
    // if (x < SQRTHF) {
    //   e -= 1;
    //   x = x + x - 1.0;
    // } else {
    //   x = x - 1.0;
    // }
    __m128 mask = _mm_cmplt_ps(x, _mm_set_ps1(0.707106781186547524f));
    __m128 tmp = _mm_and_ps(x, mask);
    x = _mm_sub_ps(x, one);
    e = _mm_sub_ps(e, _mm_and_ps(one, mask));
    x = _mm_add_ps(x, tmp);

    __m128 z = _mm_mul_ps(x,x);

    __m128 y = _mm_set_ps1(7.0376836292e-2f);
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(-1.1514610310e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(1.1676998740e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(-1.2420140846e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(1.4249322787e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(-1.6668057665e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(2.0000714765e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(-2.4999993993e-1f));
    y = _mm_mul_ps(y, x);
    y = _mm_add_ps(y, _mm_set_ps1(3.3333331174e-1f));
    y = _mm_mul_ps(y, x);

    y = _mm_mul_ps(y, z);

    tmp = _mm_mul_ps(e, _mm_set_ps1(-2.12194440e-4f));
    y = _mm_add_ps(y, tmp);

    tmp = _mm_mul_ps(z, _mm_set_ps1(0.5f));
    y = _mm_sub_ps(y, tmp);

    tmp = _mm_mul_ps(e, _mm_set_ps1(0.693359375f));
    x = _mm_add_ps(x, y);
    x = _mm_add_ps(x, tmp);
    x = _mm_or_ps(x, invalid_mask); // Negative arg will be NaN
    return x;
  }

  inline floatx4 pow(const floatx4& base, const floatx4& exponent) noexcept {
    return math::exp(exponent * math::log(base));
  }

  inline floatx4 recip(const floatx4& v) noexcept {
    return _mm_rcp_ps(v);
  }

  inline floatx4 sqrt(const floatx4& v) noexcept {
    return _mm_sqrt_ps(v);
  }

  inline floatx4 rsqrt(const floatx4& v) noexcept {
    return _mm_rsqrt_ps(v);
  }

  inline floatx4 min(const floatx4& v1, const floatx4& v2) noexcept {
    return _mm_min_ps(v1, v2);
  }

  inline floatx4 max(const floatx4& v1, const floatx4& v2) noexcept {
    return _mm_max_ps(v1, v2);
  }

  inline floatx4 abs(const floatx4& v) noexcept {
    return _mm_and_ps(v, detail_::binary_m128(0x7FFFFFFFu));
  }

  inline floatx4 dot(const floatx4& lhs, const floatx4& rhs) noexcept {
    return lhs * rhs;
  }

  inline floatx4 length2(const floatx4& v) noexcept {
    return v * v;
  }

  inline floatx4 length(const floatx4& v) noexcept {
    return math::abs(v);
  }

  inline floatx4 normalize(const floatx4& v) noexcept {
    const auto sign_bit = _mm_and_ps(v, detail_::binary_m128(0x80000000u));
    return _mm_or_ps(sign_bit, floatx4(1.0f));
  }

  inline floatx4 comp_mult(const floatx4& lhs, const floatx4& rhs) noexcept {
    return lhs * rhs;
  }

  inline void transpose(
      floatx4& v0,
      floatx4& v1,
      floatx4& v2,
      floatx4& v3) noexcept {
    _MM_TRANSPOSE4_PS(v0, v1, v2, v3);
  }

  inline floatx4 select(const floatx4& v, const boolx4& mask) noexcept {
    return _mm_and_ps(v, mask);
  }

  inline boolx4 less(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmplt_ps(lhs, rhs);
  }

  inline boolx4 less_equal(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmple_ps(lhs, rhs);
  }

  inline boolx4 greater(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmpgt_ps(lhs, rhs);
  }

  inline boolx4 greater_equal(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmpge_ps(lhs, rhs);
  }

  inline boolx4 equal(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmpeq_ps(lhs, rhs);
  }

  inline boolx4 not_equal(const floatx4& lhs, const floatx4& rhs) noexcept {
    return _mm_cmpneq_ps(lhs, rhs);
  }
}

}
