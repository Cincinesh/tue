//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

// This file contains code based on Julien Pommier's neon_mathfun.h originally
// published at http://gruntthepeon.free.fr/ssemath/neon_mathfun.html under
// the following license:
//
// Copyright (C) 2011 Julien Pommier
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

#include "simd.hpp"

#include <arm_neon.h>

// The Tuesday C++ math and template library.
namespace tue
{
  // 4 parallel floats accelerated by SIMD intrinsics if possible.
  class float32x4
  {
  private:
    float32x4_t underlying_;

  public:
    // Constructs a new float32x4 without a specific value.
    float32x4() noexcept = default;

    // Constructs a new float32x4 with each component set to the given value.
    explicit float32x4(float s) noexcept
      : underlying_{ s, s, s, s } {}

    // Constructs a new float32x4 with the given values.
    float32x4(float x, float y, float z, float w) noexcept
      : underlying_{ x, y, z, w } {}

    // Constructs a new float32x4 from the given NEON float32x4_t.
    float32x4(float32x4_t underlying) noexcept
      : underlying_(underlying) {}

    // Returns the NEON float32x4_t corresponding to this float32x4.
    operator float32x4_t() const noexcept
    {
      return underlying_;
    }

    // Returns a float32x4 with each component set to 0.0f.
    static float32x4 zero() noexcept
    {
      return float32x4(0);
    }

    // Returns a new float32x4 with the binary representation of each
    // component set to the given value.
    static float32x4 binary(unsigned int i) noexcept
    {
      return float32x4(reinterpret_cast<float&>(i));
    }

    // Returns a new float32x4 with the given binary representations of the
    // values.
    static float32x4 binary(
        unsigned int x,
        unsigned int y,
        unsigned int z,
        unsigned int w) noexcept
    {
      return {
        reinterpret_cast<float&>(x),
        reinterpret_cast<float&>(y),
        reinterpret_cast<float&>(z),
        reinterpret_cast<float&>(w),
      };
    }

    // Returns a new float32x4 with values from the given 16-byte-aligned
    // array. If the array is not 16-byte-aligned or doesn't have at least 4
    // components, behavior is undefined.
    static float32x4 load(const float* array) noexcept
    {
      return vld1q_f32(array);
    }

    // Returns a new float32x4 with values from the given array. If the array
    // doesn't have at least 4 components, behavior is undefined.
    static float32x4 loadu(const float* array) noexcept
    {
      return load(array);
    }

    // Copies this float32x4 to the given 16-byte-aligned destination. If the
    // destination isn't 16-byte-aligned or doesn't have space for at least 4
    // components, behavior is undefined.
    void store(float* destination) const noexcept
    {
      vst1q_f32(destination, underlying_);
    }

    // Copies this float32x4 to the given destination. If the destination
    // doesn't have space for at least 4 components, behavior is undefined.
    void storeu(float* destination) const noexcept
    {
      store(destination);
    }
  };

  // Returns the component-wise unary plus of the given float32x4.
  inline float32x4 operator+(const float32x4& v) noexcept
  {
    return v;
  }

  // Returns the component-wise negation of the given float32x4.
  inline float32x4 operator-(const float32x4& v) noexcept
  {
    return vreinterpretq_f32_u32(veorq_u32(
        vreinterpretq_u32_f32(v),
        vdupq_n_u32(0x80000000u)));
  }

  // Returns the bitwise not of the given float32x4.
  inline float32x4 operator~(const float32x4& v) noexcept
  {
    return vreinterpretq_f32_u32(vmvnq_u32(
        vreinterpretq_u32_f32(v)));
  }

  // Returns the component-wise sum of two float32x4's.
  inline float32x4 operator+(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vaddq_f32(lhs, rhs);
  }

  // Returns the component-wise difference between two float32x4's.
  inline float32x4 operator-(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vsubq_f32(lhs, rhs);
  }

  // Returns the component-wise product of two float32's.
  inline float32x4 operator*(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vmulq_f32(lhs, rhs);
  }

  // Returns the component-wise quotient of two float32x4's.
  inline float32x4 operator/(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    float32x4_t r = vrecpeq_f32(rhs);
    r = vmulq_f32(vrecpsq_f32(rhs, r), r);
    return vmulq_f32(lhs, r);
  }

  // Returns the bitwise and of two float32x4's.
  inline float32x4 operator&(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vreinterpretq_f32_u32(vandq_u32(
        vreinterpretq_u32_f32(lhs),
        vreinterpretq_u32_f32(rhs)));
  }

  // Returns the bitwise or of two float32x4's.
  inline float32x4 operator|(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vreinterpretq_f32_u32(vorrq_u32(
        vreinterpretq_u32_f32(lhs),
        vreinterpretq_u32_f32(rhs)));
  }

  // Returns the bitwise xor of two float32x4's.
  inline float32x4 operator^(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return vreinterpretq_f32_u32(veorq_u32(
        vreinterpretq_u32_f32(lhs),
        vreinterpretq_u32_f32(rhs)));
  }

  // Increments and returns a reference to the given float32x4.
  inline float32x4& operator++(float32x4& v) noexcept
  {
    return v = v + float32x4(1.0f);
  }

  // Decrements and returns a reference to the given float32x4.
  inline float32x4& operator--(float32x4& v) noexcept
  {
    return v = v - float32x4(1.0f);
  }

  // Increments the given float32x4 and returns the original value.
  inline float32x4 operator++(float32x4& v, int) noexcept
  {
    const auto orig = v;
    ++v;
    return orig;
  }

  // Decrements the given float32x4 and returns the original value.
  inline float32x4 operator--(float32x4& v, int) noexcept
  {
    const auto orig = v;
    --v;
    return orig;
  }

  // Adds the right-hand side float32x4 to the left-hand side float32x4 and
  // returns a reference to the left-hand side float32x4.
  inline float32x4& operator+=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs + rhs;
  }

  // Subtracts the right-hand side float32x4 from the left-hand side float32x4
  // and returns a reference to the left-hand side float32x4.
  inline float32x4& operator-=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs - rhs;
  }

  // Multiplies the left-hand side float32x4 by the right-hand side float32x4
  // and returns a reference to the left-hand side float32x4.
  inline float32x4& operator*=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs * rhs;
  }

  // Divides the left-hand side float32x4 by the right-hand side float32x4 and
  // returns a reference to the left-hand side float32x4.
  inline float32x4& operator/=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs / rhs;
  }

  // Bitwise and's the left-hand side float32x4 with the right-hand side
  // float32x4 and returns a reference to the left-hand side float32x4.
  inline float32x4& operator&=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs & rhs;
  }

  // Bitwise or's the left-hand side float32x4 with the right-hand side
  // float32x4 and returns a reference to the left-hand side float32x4.
  inline float32x4& operator|=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs | rhs;
  }

  // Bitwise xor's the left-hand side float32x4 with the right-hand side
  // float32x4 and returns a reference to the left-hand side float32x4.
  inline float32x4& operator^=(
      float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return lhs = lhs ^ rhs;
  }

  // Returns true if all the corresponding components of each float32x4 are
  // equal and false otherwise.
  inline bool operator==(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    uint32x4_t u4 = vceqq_f32(lhs, rhs);
    uint32x2_t u2 = vand_u32(vget_low_u32(u4), vget_high_u32(u4));
    u2 = vand_u32(u2, vext_u32(u2, u2, 1));
    u2 = vand_u32(u2, vdup_n_u32(1));
    return vget_lane_u32(u2, 0) != 0;
  }

  // Returns true if any of the corresponding components of each float32x4 are
  // not equal and false otherwise.
  inline bool operator!=(
      const float32x4& lhs,
      const float32x4& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  // Non-member math functions.
  namespace math
  {
    // Sets sin_result and cos_result to the component-wise trigonometric sine
    // and cosine respectively of the given float32x4.
    inline void sincos(
        const float32x4& v,
        float32x4& sin_result,
        float32x4& cos_result) noexcept
    {
      // This sincos() implementation is based on Julien Pommier's
      // sincos_ps(). See the top of this file for details.
      float32x4_t x = v;

      float32x4_t xmm1, xmm2, xmm3, y;
      uint32x4_t emm2;

      uint32x4_t sign_mask_sin, sign_mask_cos;
      sign_mask_sin = vcltq_f32(x, vdupq_n_f32(0.0f));
      x = vabsq_f32(x);

      // Scale by 4/Pi
      y = vmulq_f32(x, vdupq_n_f32(1.27323954473516f));

      // Store the integer part of y in mm0
      emm2 = vcvtq_u32_f32(y);

      // j=(j+1) & (~1) (see the cephes sources)
      emm2 = vaddq_u32(emm2, vdupq_n_u32(1u));
      emm2 = vandq_u32(emm2, vdupq_n_u32(~1u));
      y = vcvtq_f32_u32(emm2);

      // Get the polynom selection mask.
      // There is one polynom for 0 <= x <= Pi/4
      // and another one for Pi/4<x<=Pi/2.
      // Both branches will be computed.
      uint32x4_t poly_mask = vtstq_u32(emm2, vdupq_n_u32(2u));

      // The magic pass: "Extended precision modular arithmetic"
      // x = ((x - y * DP1) - y * DP2) - y * DP3;
      xmm1 = vmulq_n_f32(y, -0.78515625f);
      xmm2 = vmulq_n_f32(y, -2.4187564849853515625e-4f);
      xmm3 = vmulq_n_f32(y, -3.77489497744594108e-8f);
      x = vaddq_f32(x, xmm1);
      x = vaddq_f32(x, xmm2);
      x = vaddq_f32(x, xmm3);

      sign_mask_sin =
          veorq_u32(sign_mask_sin, vtstq_u32(emm2, vdupq_n_u32(4u)));
      sign_mask_cos =
          vtstq_u32(vsubq_u32(emm2, vdupq_n_u32(2u)), vdupq_n_u32(4u));

      // Evaluate the first polynom (0 <= x <= Pi/4) in y1,
      // and the second polynom     (Pi/4 <= x <= 0) in y2
      float32x4_t z = vmulq_f32(x, x);
      float32x4_t y1, y2;

      y1 = vmulq_n_f32(z, 2.443315711809948e-5f);
      y2 = vmulq_n_f32(z, -1.9515295891e-4f);
      y1 = vaddq_f32(y1, vdupq_n_f32(-1.388731625493765e-3f));
      y2 = vaddq_f32(y2, vdupq_n_f32(8.3321608736e-3f));
      y1 = vmulq_f32(y1, z);
      y2 = vmulq_f32(y2, z);
      y1 = vaddq_f32(y1, vdupq_n_f32(4.166664568298827e-2f));
      y2 = vaddq_f32(y2, vdupq_n_f32(4.166664568298827e-2f));
      y1 = vmulq_f32(y1, z);
      y2 = vmulq_f32(y2, z);
      y1 = vmulq_f32(y1, z);
      y2 = vmulq_f32(y2, x);
      y1 = vsubq_f32(y1, vmulq_f32(z, vdupq_n_f32(0.5f)));
      y2 = vaddq_f32(y2, x);
      y1 = vaddq_f32(y1, vdupq_n_f32(1.0f));

      // Select the correct result from the two polynoms
      float32x4_t ys = vbslq_f32(poly_mask, y1, y2);
      float32x4_t yc = vbslq_f32(poly_mask, y2, y1);
      sin_result = vbslq_f32(sign_mask_sin, vnegq_f32(ys), ys);
      cos_result = vbslq_f32(sign_mask_cos, yc, vnegq_f32(yc));
    }

    // Returns the component-wise trigonometric sine of the given float32x4.
    inline float32x4 sin(const float32x4& v) noexcept
    {
      float32x4 sin_result, cos_result;
      sincos(v, sin_result, cos_result);
      return sin_result;
    }

    // Returns the component-wise trigonometric cosine of the given float32x4.
    inline float32x4 cos(const float32x4& v) noexcept
    {
      float32x4 sin_result, cos_result;
      sincos(v, sin_result, cos_result);
      return cos_result;
    }

    // Returns the component-wise result of raising e (Euler's number) to the
    // given exponents.
    inline float32x4 exp(const float32x4& v) noexcept
    {
      // This exp() implementation is based on Julien Pommier's exp_ps(). See
      // the top of this file for details.
      float32x4_t x = v;

      float32x4_t tmp, fx;
      float32x4_t one = vdupq_n_f32(1.0f);
      x = vminq_f32(x, vdupq_n_f32(88.3762626647949f));
      x = vmaxq_f32(x, vdupq_n_f32(-88.3762626647949f));

      // Express exp(x) as exp(g + n*log(2))
      fx = vmlaq_f32(vdupq_n_f32(0.5f), x, vdupq_n_f32(1.44269504088896341f));

      // Perform a floorf
      tmp = vcvtq_f32_s32(vcvtq_s32_f32(fx));

      // If greater, subtract 1
      uint32x4_t mask = vcgtq_f32(tmp, fx);
      mask = vandq_u32(mask, vreinterpretq_u32_f32(one));

      fx = vsubq_f32(tmp, vreinterpretq_f32_u32(mask));

      tmp = vmulq_f32(fx, vdupq_n_f32(0.693359375f));
      float32x4_t z = vmulq_f32(fx, vdupq_n_f32(-2.12194440e-4f));
      x = vsubq_f32(x, tmp);
      x = vsubq_f32(x, z);

      static const float cephes_exp_p[6] = {
        1.9875691500e-4f,
        1.3981999507e-3f,
        8.3334519073e-3f,
        4.1665795894e-2f,
        1.6666665459e-1f,
        5.0000001201e-1f,
      };

      float32x4_t y = vld1q_dup_f32(cephes_exp_p + 0);
      float32x4_t c1 = vld1q_dup_f32(cephes_exp_p + 1);
      float32x4_t c2 = vld1q_dup_f32(cephes_exp_p + 2);
      float32x4_t c3 = vld1q_dup_f32(cephes_exp_p + 3);
      float32x4_t c4 = vld1q_dup_f32(cephes_exp_p + 4);
      float32x4_t c5 = vld1q_dup_f32(cephes_exp_p + 5);

      y = vmulq_f32(y, x);
      z = vmulq_f32(x, x);
      y = vaddq_f32(y, c1);
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, c2);
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, c3);
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, c4);
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, c5);

      y = vmulq_f32(y, z);
      y = vaddq_f32(y, x);
      y = vaddq_f32(y, one);

      // Build 2^n
      int32x4_t mm;
      mm = vcvtq_s32_f32(fx);
      mm = vaddq_s32(mm, vdupq_n_s32(0x7F));
      mm = vshlq_n_s32(mm, 23);
      float32x4_t pow2n = vreinterpretq_f32_s32(mm);

      y = vmulq_f32(y, pow2n);
      return y;
    }

    // Returns the component-wise natural log of the given float32x4.
    inline float32x4 log(const float32x4& v) noexcept
    {
      // This log() implementation is based on Julien Pommier's log_ps(). See
      // the top of this file for details.
      float32x4_t x = v;

      float32x4_t one = vdupq_n_f32(1.0f);

      // Force flush to zero on denormal values
      x = vmaxq_f32(x, vdupq_n_f32(0.0f));
      uint32x4_t invalid_mask = vcleq_f32(x, vdupq_n_f32(0.0f));

      int32x4_t ux = vreinterpretq_s32_f32(x);
      int32x4_t emm0 = vshrq_n_s32(ux, 23);

      // Keep only the fractional part
      ux = vandq_s32(ux, vdupq_n_s32(~0x7F800000));
      ux = vorrq_s32(ux, vreinterpretq_s32_f32(vdupq_n_f32(0.5f)));
      x = vreinterpretq_f32_s32(ux);

      emm0 = vsubq_s32(emm0, vdupq_n_s32(0x7F));
      float32x4_t e = vcvtq_f32_s32(emm0);

      e = vaddq_f32(e, one);

      // Part 2:
      // if (x < SQRTHF) {
      //   e -= 1;
      //   x = x + x - 1.0;
      // } else {
      //   x = x - 1.0;
      // }
      uint32x4_t mask = vcltq_f32(x, vdupq_n_f32(0.707106781186547524f));
      float32x4_t tmp =
          vreinterpretq_f32_u32(vandq_u32(vreinterpretq_u32_f32(x), mask));
      x = vsubq_f32(x, one);
      e = vsubq_f32(e, vreinterpretq_f32_u32(vandq_u32(
              vreinterpretq_u32_f32(one), mask)));
      x = vaddq_f32(x, tmp);

      float32x4_t z = vmulq_f32(x,x);

      float32x4_t y = vdupq_n_f32(7.0376836292E-2f);
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(- 1.1514610310E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(1.1676998740E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(- 1.2420140846E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(+ 1.4249322787E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(- 1.6668057665E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(+ 2.0000714765E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(- 2.4999993993E-1f));
      y = vmulq_f32(y, x);
      y = vaddq_f32(y, vdupq_n_f32(+ 3.3333331174E-1f));
      y = vmulq_f32(y, x);

      y = vmulq_f32(y, z);

      tmp = vmulq_f32(e, vdupq_n_f32(-2.12194440e-4f));
      y = vaddq_f32(y, tmp);

      tmp = vmulq_f32(z, vdupq_n_f32(0.5f));
      y = vsubq_f32(y, tmp);

      tmp = vmulq_f32(e, vdupq_n_f32(0.693359375f));
      x = vaddq_f32(x, y);
      x = vaddq_f32(x, tmp);
      x = vreinterpretq_f32_u32(vorrq_u32(
              vreinterpretq_u32_f32(x), invalid_mask));
              // Negative arg will be NaN

      return x;
    }

    // Returns the component-wise result of raising the given bases to the
    // given exponents.
    inline float32x4 pow(
        const float32x4& base,
        const float32x4& exponent) noexcept
    {
      return math::exp(exponent * math::log(base));
    }

    // Returns the component-wise reciprocal of the given float32x4.
    inline float32x4 recip(const float32x4& v) noexcept
    {
      const float32x4_t r = vrecpeq_f32(v);
      return vmulq_f32(vrecpsq_f32(v, r), r);
    }

    // Returns the component-wise reciprocal square root of the given
    // float32x4.
    inline float32x4 rsqrt(const float32x4& v) noexcept
    {
      const float32x4_t r = vrsqrteq_f32(v);
      return vmulq_f32(vrsqrtsq_f32(v, r), r);
    }

    // Returns the component-wise square root of the given float32x4.
    inline float32x4 sqrt(const float32x4& v) noexcept
    {
      return math::recip(math::rsqrt(v));
    }

    // Returns the component-wise minimum of two float32x4's.
    inline float32x4 min(
        const float32x4& v1,
        const float32x4& v2) noexcept
    {
      return vminq_f32(v1, v2);
    }

    // Returns the component-wise maximum of two float32x4's.
    inline float32x4 max(
        const float32x4& v1,
        const float32x4& v2) noexcept
    {
      return vmaxq_f32(v1, v2);
    }

    // Returns the component-wise absolute value of the given float32x4.
    inline float32x4 abs(const float32x4& v) noexcept
    {
      return v & float32x4::binary(0x7FFFFFFFu);
    }

    // Returns the component-wise product of two float32x4's.
    inline float32x4 dot(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return lhs * rhs;
    }

    // Returns the component-wise square of the given float32x4.
    inline float32x4 length2(const float32x4& v) noexcept
    {
      return v * v;
    }

    // Returns the component-wise absolute value of the given float32x4.
    inline float32x4 length(const float32x4& v) noexcept
    {
      return math::abs(v);
    }

    // Returns the component-wise result of dividing the given float32x4 by
    // its absolute value.
    inline float32x4 normalize(const float32x4& v) noexcept
    {
      const float32x4 sign_bit = v & float32x4::binary(0x80000000u);
      return sign_bit | float32x4(1.0f);
    }

    // Treats the 4 given float32x4's as the columns of a 4x4 matrix and
    // transposes the matrix.
    inline void transpose(
        float32x4& v0,
        float32x4& v1,
        float32x4& v2,
        float32x4& v3) noexcept
    {
      float32x4x2_t tmp1 = vtrnq_f32(v0, v1);
      v0 = tmp1.val[0];
      v1 = tmp1.val[1];

      tmp1 = vtrnq_f32(v2, v3);
      v2 = tmp1.val[0];
      v3 = tmp1.val[1];

      float32x2_t tmp2 = vget_high_f32(v0);
      v0 = vcombine_f32(vget_low_f32(v0), vget_low_f32(v2));
      v2 = vcombine_f32(tmp2, vget_high_f32(v2));

      tmp2 = vget_high_f32(v1);
      v1 = vcombine_f32(vget_low_f32(v1), vget_low_f32(v3));
      v3 = vcombine_f32(tmp2, vget_high_f32(v3));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is less than the right-hand side float32x4.
    // 0xFFFFFFFF corresponds to true. 0x00000000 corresponds to false.
    inline float32x4 isless(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return vreinterpretq_f32_u32(vcltq_f32(lhs, rhs));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is less than or equal to the right-hand side
    // float32x4. 0xFFFFFFFF corresponds to true. 0x00000000 corresponds to
    // false.
    inline float32x4 islessequal(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return vreinterpretq_f32_u32(vcleq_f32(lhs, rhs));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is greater than the right-hand side float32x4.
    // 0xFFFFFFFF corresponds to true. 0x00000000 corresponds to false.
    inline float32x4 isgreater(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return vreinterpretq_f32_u32(vcgtq_f32(lhs, rhs));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is greater than or equal to the right-hand
    // side float32x4. 0xFFFFFFFF corresponds to true. 0x00000000 corresponds
    // to false.
    inline float32x4 isgreaterequal(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return vreinterpretq_f32_u32(vcgeq_f32(lhs, rhs));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is equal to the right-hand side float32x4.
    // 0xFFFFFFFF corresponds to true. 0x00000000 corresponds to false.
    inline float32x4 isequal(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return vreinterpretq_f32_u32(vceqq_f32(lhs, rhs));
    }

    // Returns the component-wise result of checking whether or not the
    // left-hand side float32x4 is not equal to the right-hand side float32x4.
    // 0xFFFFFFFF corresponds to true. 0x00000000 corresponds to false.
    inline float32x4 isnotequal(
        const float32x4& lhs,
        const float32x4& rhs) noexcept
    {
      return ~isequal(lhs, rhs);
    }
  }
}
