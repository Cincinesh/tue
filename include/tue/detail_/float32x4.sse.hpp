//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/*
  This file contains code based on Julien Pommier's sse_mathfun.h
  originally published at:

  http://gruntthepeon.free.fr/ssemath/

  Under the following license:

  Copyright (C) 2007  Julien Pommier

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not
     be misrepresented as being the original software.
  3. This notice may not be removed or altered from any source
     distribution.

  (this is the zlib license)
*/

#pragma once

#include "simd.hpp"

#include <xmmintrin.h>

#ifdef __SSE2__
#include <emmintrin.h>
#else
#include <mmintrin.h>
#endif

namespace tue
{
	// ---------
	// float32x4
	// ---------
	class float32x4
	{
	private:
		__m128 underlying_;

	public:
		// -------------------
		// default constructor
		// -------------------
		float32x4() noexcept = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit float32x4(float s) noexcept :
			underlying_(_mm_set_ps1(s)) {}

		// ---------------------
		// component constructor
		// ---------------------
		float32x4(float x, float y, float z, float w) noexcept :
			underlying_(_mm_setr_ps(x, y, z, w)) {}

		// ---------------------------------
		// underlying conversion constructor
		// ---------------------------------
		float32x4(__m128 underlying) noexcept :
			underlying_(underlying) {}

		// ------------------------------
		// underlying conversion operator
		// ------------------------------
		operator __m128() const noexcept { return underlying_; }

		// ---------------
		// factory methods
		// ---------------
		static float32x4 zero() noexcept
		{
			return _mm_setzero_ps();
		}

		static float32x4 binary(unsigned int i) noexcept
		{
			return _mm_set_ps1(reinterpret_cast<float&>(i));
		}

		static float32x4 binary(
			unsigned int x,
			unsigned int y,
			unsigned int z,
			unsigned int w) noexcept
		{
			return _mm_setr_ps(
				reinterpret_cast<float&>(x),
				reinterpret_cast<float&>(y),
				reinterpret_cast<float&>(z),
				reinterpret_cast<float&>(w));
		}

		static float32x4 load(const float* array) noexcept
		{
			return _mm_load_ps(array);
		}

		static float32x4 loadu(const float* array) noexcept
		{
			return _mm_loadu_ps(array);
		}

		// -------
		// store()
		// -------
		void store(float* destination) const noexcept
		{
			_mm_store_ps(destination, underlying_);
		}

		void storeu(float* destination) const noexcept
		{
			_mm_storeu_ps(destination, underlying_);
		}
	};

	// ----------------
	// prefix operators
	// ----------------
	inline float32x4 operator+(const float32x4& v) noexcept
	{
		return v;
	}

	inline float32x4 operator-(const float32x4& v) noexcept
	{
		return _mm_xor_ps(v, float32x4::binary(0x80000000));
	}

	inline float32x4 operator~(const float32x4& v) noexcept
	{
		return _mm_xor_ps(v, float32x4::binary(0xFFFFFFFF));
	}

	// --------------------
	// arithmetic operators
	// --------------------
	inline float32x4 operator+(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_add_ps(lhs, rhs);
	}

	inline float32x4 operator-(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_sub_ps(lhs, rhs);
	}

	inline float32x4 operator*(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_mul_ps(lhs, rhs);
	}

	inline float32x4 operator/(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_div_ps(lhs, rhs);
	}

	// -----------------
	// bitwise operators
	// -----------------
	inline float32x4 operator&(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_and_ps(lhs, rhs);
	}

	inline float32x4 operator|(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_or_ps(lhs, rhs);
	}

	inline float32x4 operator^(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_xor_ps(lhs, rhs);
	}

	// ---------------------------------
	// increment and decrement operators
	// ---------------------------------
	inline float32x4& operator++(float32x4& v) noexcept
	{
		return v = v + float32x4(1.0f);
	}

	inline float32x4& operator--(float32x4& v) noexcept
	{
		return v = v - float32x4(1.0f);
	}

	inline float32x4 operator++(float32x4& v, int) noexcept
	{
		const auto result = v;
		++v;
		return result;
	}

	inline float32x4 operator--(float32x4& v, int) noexcept
	{
		const auto result = v;
		--v;
		return result;
	}

	// -------------------------------
	// arithmetic assignment operators
	// -------------------------------
	inline float32x4& operator+=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs + rhs;
	}

	inline float32x4& operator-=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs - rhs;
	}

	inline float32x4& operator*=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs * rhs;
	}

	inline float32x4& operator/=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs / rhs;
	}

	// ----------------------------
	// bitwise assignment operators
	// ----------------------------
	inline float32x4& operator&=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs & rhs;
	}

	inline float32x4& operator|=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs | rhs;
	}

	inline float32x4& operator^=(
		float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return lhs = lhs ^ rhs;
	}

	// --------------------
	// comparison operators
	// --------------------
	inline bool operator==(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return _mm_movemask_ps(_mm_cmpeq_ps(lhs, rhs)) == 0b1111;
	}

	inline bool operator!=(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	// ------
	// math()
	// ------
	namespace math
	{
		// --------
		// sincos()
		// --------
		inline void sincos(
			const float32x4& v,
			float32x4& sin_result,
			float32x4& cos_result) noexcept
		{
			/*
			  This sincos() implementation is based on Julien Pommier's sincos_ps().
			  See the top of this file for details.
			*/
			__m128 x = v;
			__m128 xmm1, xmm2, xmm3 = _mm_setzero_ps(), sign_bit_sin, y;
#ifdef __SSE2__
			__m128i emm0, emm2, emm4;
#else
			__m64 mm0, mm1, mm2, mm3, mm4, mm5;
			union {
				__m64 mm[2];
				__m128 xmm;
			} u;
#endif
			sign_bit_sin = x;
			/* take the absolute value */
			x = _mm_and_ps(x, float32x4::binary(~0x80000000));
			/* extract the sign bit (upper one) */
			sign_bit_sin = _mm_and_ps(sign_bit_sin,
				float32x4::binary(0x80000000));

			/* scale by 4/Pi */
			y = _mm_mul_ps(x, _mm_set_ps1(1.27323954473516));

#ifdef __SSE2__
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
			u.mm[0] = mm0;
			u.mm[1] = mm1;
			__m128 swap_sign_bit_sin = u.xmm;

			/* get the polynom selection mask for the sine */

			mm2 = _mm_and_si64(mm2, _mm_set1_pi32(2));
			mm3 = _mm_and_si64(mm3, _mm_set1_pi32(2));
			mm2 = _mm_cmpeq_pi32(mm2, _mm_setzero_si64());
			mm3 = _mm_cmpeq_pi32(mm3, _mm_setzero_si64());
			u.mm[0] = mm2;
			u.mm[1] = mm3;
			__m128 poly_mask = u.xmm;
#endif

			/* The magic pass: "Extended precision modular arithmetic"
			   x = ((x - y * DP1) - y * DP2) - y * DP3; */
			xmm1 = _mm_set_ps1(-0.78515625);
			xmm2 = _mm_set_ps1(-2.4187564849853515625e-4);
			xmm3 = _mm_set_ps1(-3.77489497744594108e-8);
			xmm1 = _mm_mul_ps(y, xmm1);
			xmm2 = _mm_mul_ps(y, xmm2);
			xmm3 = _mm_mul_ps(y, xmm3);
			x = _mm_add_ps(x, xmm1);
			x = _mm_add_ps(x, xmm2);
			x = _mm_add_ps(x, xmm3);

#ifdef __SSE2__
			emm4 = _mm_sub_epi32(emm4, _mm_set1_epi32(2));
			emm4 = _mm_andnot_si128(emm4, _mm_set1_epi32(4));
			emm4 = _mm_slli_epi32(emm4, 29);
			__m128 sign_bit_cos = _mm_castsi128_ps(emm4);
#else
			/* get the sign flag for the cosine */
			mm4 = _mm_sub_pi32(mm4, _mm_set1_pi32(2));
			mm5 = _mm_sub_pi32(mm5, _mm_set1_pi32(2));
			mm4 = _mm_andnot_si64(mm4, _mm_set1_pi32(4));
			mm5 = _mm_andnot_si64(mm5, _mm_set1_pi32(4));
			mm4 = _mm_slli_pi32(mm4, 29);
			mm5 = _mm_slli_pi32(mm5, 29);
			u.mm[0] = mm4;
			u.mm[1] = mm5;
			__m128 sign_bit_cos = u.xmm;
			_mm_empty(); /* good-bye mmx */
#endif

			sign_bit_sin = _mm_xor_ps(sign_bit_sin, swap_sign_bit_sin);

			/* Evaluate the first polynom  (0 <= x <= Pi/4) */
			__m128 z = _mm_mul_ps(x,x);
			y = _mm_set_ps1(2.443315711809948E-005);

			y = _mm_mul_ps(y, z);
			y = _mm_add_ps(y, _mm_set_ps1(-1.388731625493765E-003));
			y = _mm_mul_ps(y, z);
			y = _mm_add_ps(y, _mm_set_ps1(4.166664568298827E-002));
			y = _mm_mul_ps(y, z);
			y = _mm_mul_ps(y, z);
			__m128 tmp = _mm_mul_ps(z, _mm_set_ps1(0.5f));
			y = _mm_sub_ps(y, tmp);
			y = _mm_add_ps(y, _mm_set_ps1(1.0f));

			/* Evaluate the second polynom  (Pi/4 <= x <= 0) */

			__m128 y2 = _mm_set_ps1(-1.9515295891E-4);
			y2 = _mm_mul_ps(y2, z);
			y2 = _mm_add_ps(y2, _mm_set_ps1(8.3321608736E-3));
			y2 = _mm_mul_ps(y2, z);
			y2 = _mm_add_ps(y2, _mm_set_ps1(-1.6666654611E-1));
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
			sin_result = _mm_xor_ps(xmm1, sign_bit_sin);
			cos_result = _mm_xor_ps(xmm2, sign_bit_cos);
		}

		// -----
		// sin()
		// -----
		inline float32x4 sin(const float32x4& v) noexcept
		{
			float32x4 sin_result, cos_result;
			sincos(v, sin_result, cos_result);
			return sin_result;
		}

		// -----
		// cos()
		// -----
		inline float32x4 cos(const float32x4& v) noexcept
		{
			float32x4 sin_result, cos_result;
			sincos(v, sin_result, cos_result);
			return cos_result;
		}

		// -----
		// exp()
		// -----
		inline float32x4 exp(const float32x4& v) noexcept
		{
			/*
			  This exp() implementation is based on Julien Pommier's exp_ps().
			  See the top of this file for details.
			*/
			__m128 x = v;
			__m128 tmp = _mm_setzero_ps(), fx;
#ifdef __SSE2__
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

			/* express exp(x) as exp(g + n*log(2)) */
			fx = _mm_mul_ps(x, _mm_set_ps1(1.44269504088896341));
			fx = _mm_add_ps(fx, _mm_set_ps1(0.5f));

			/* how to perform a floorf with SSE: just below */
#ifndef __SSE2__
			/* step 1 : cast to int */
			tmp = _mm_movehl_ps(tmp, fx);
			mm0 = _mm_cvttps_pi32(fx);
			mm1 = _mm_cvttps_pi32(tmp);
			/* step 2 : cast back to float */
			tmp = _mm_cvtpi32x2_ps(mm0, mm1);
#else
			emm0 = _mm_cvttps_epi32(fx);
			tmp  = _mm_cvtepi32_ps(emm0);
#endif
			/* if greater, substract 1 */
			__m128 mask = _mm_cmpgt_ps(tmp, fx);
			mask = _mm_and_ps(mask, one);
			fx = _mm_sub_ps(tmp, mask);

			tmp = _mm_mul_ps(fx, _mm_set_ps1(0.693359375));
			__m128 z = _mm_mul_ps(fx, _mm_set_ps1(-2.12194440e-4));
			x = _mm_sub_ps(x, tmp);
			x = _mm_sub_ps(x, z);

			z = _mm_mul_ps(x,x);

			__m128 y = _mm_set_ps1(1.9875691500E-4);
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(1.3981999507E-3));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(8.3334519073E-3));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(4.1665795894E-2));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(1.6666665459E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(5.0000001201E-1));
			y = _mm_mul_ps(y, z);
			y = _mm_add_ps(y, x);
			y = _mm_add_ps(y, one);

			/* build 2^n */
#ifndef __SSE2__
			z = _mm_movehl_ps(z, fx);
			mm0 = _mm_cvttps_pi32(fx);
			mm1 = _mm_cvttps_pi32(z);
			mm0 = _mm_add_pi32(mm0, _mm_set1_pi32(0x7f));
			mm1 = _mm_add_pi32(mm1, _mm_set1_pi32(0x7f));
			mm0 = _mm_slli_pi32(mm0, 23);
			mm1 = _mm_slli_pi32(mm1, 23);
			u.mm[0] = mm0;
			u.mm[1] = mm1;
			__m128 pow2n = u.xmm;
			_mm_empty();
#else
			emm0 = _mm_cvttps_epi32(fx);
			emm0 = _mm_add_epi32(emm0, _mm_set1_epi32(0x7f));
			emm0 = _mm_slli_epi32(emm0, 23);
			__m128 pow2n = _mm_castsi128_ps(emm0);
#endif
			y = _mm_mul_ps(y, pow2n);
			return y;
		}

		// -----
		// log()
		// -----
		inline float32x4 log(const float32x4& v) noexcept
		{
			/*
			  This log() implementation is based on Julien Pommier's log_ps().
			  See the top of this file for details.
			*/
			__m128 x = v;
#ifdef __SSE2__
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

			/* cut off denormalized stuff */
			x = _mm_max_ps(x, float32x4::binary(0x00800000));

#ifndef __SSE2__
			/* part 1: x = frexpf(x, &e); */
			u.xmm = x;
			mm0 = _mm_srli_pi32(u.mm[0], 23);
			mm1 = _mm_srli_pi32(u.mm[1], 23);
#else
			emm0 = _mm_srli_epi32(_mm_castps_si128(x), 23);
#endif
			/* keep only the fractional part */
			x = _mm_and_ps(x, float32x4::binary(~0x7f800000));
			x = _mm_or_ps(x, _mm_set_ps1(0.5f));

#ifndef __SSE2__
			/* now e=mm0:mm1 contain the really base-2 exponent */
			mm0 = _mm_sub_pi32(mm0, _mm_set1_pi32(0x7f));
			mm1 = _mm_sub_pi32(mm1, _mm_set1_pi32(0x7f));
			__m128 e = _mm_cvtpi32x2_ps(mm0, mm1);
			_mm_empty(); /* bye bye mmx */
#else
			emm0 = _mm_sub_epi32(emm0, _mm_set1_epi32(0x7f));
			__m128 e = _mm_cvtepi32_ps(emm0);
#endif

			e = _mm_add_ps(e, one);

			/* part2:
			   if( x < SQRTHF ) {
			     e -= 1;
			     x = x + x - 1.0;
			   } else { x = x - 1.0; }
			*/
			__m128 mask = _mm_cmplt_ps(x, _mm_set_ps1(0.707106781186547524));
			__m128 tmp = _mm_and_ps(x, mask);
			x = _mm_sub_ps(x, one);
			e = _mm_sub_ps(e, _mm_and_ps(one, mask));
			x = _mm_add_ps(x, tmp);

			__m128 z = _mm_mul_ps(x,x);

			__m128 y = _mm_set_ps1(7.0376836292E-2);
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(- 1.1514610310E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(1.1676998740E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(- 1.2420140846E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(+ 1.4249322787E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(- 1.6668057665E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(+ 2.0000714765E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(- 2.4999993993E-1));
			y = _mm_mul_ps(y, x);
			y = _mm_add_ps(y, _mm_set_ps1(+ 3.3333331174E-1));
			y = _mm_mul_ps(y, x);

			y = _mm_mul_ps(y, z);

			tmp = _mm_mul_ps(e, _mm_set_ps1(-2.12194440e-4));
			y = _mm_add_ps(y, tmp);

			tmp = _mm_mul_ps(z, _mm_set_ps1(0.5f));
			y = _mm_sub_ps(y, tmp);

			tmp = _mm_mul_ps(e, _mm_set_ps1(0.693359375));
			x = _mm_add_ps(x, y);
			x = _mm_add_ps(x, tmp);
			x = _mm_or_ps(x, invalid_mask); // negative arg will be NAN
			return x;
		}
		
		// -----
		// pow()
		// -----
		inline float32x4 pow(
			const float32x4& base,
			const float32x4& exponent) noexcept
		{
			return math::exp(exponent * math::log(base));
		}

		// -------
		// recip()
		// -------
		inline float32x4 recip(const float32x4& v) noexcept
		{
			return _mm_rcp_ps(v);
		}

		// ------
		// sqrt()
		// ------
		inline float32x4 sqrt(const float32x4& v) noexcept
		{
			return _mm_sqrt_ps(v);
		}

		// -------
		// rsqrt()
		// -------
		inline float32x4 rsqrt(const float32x4& v) noexcept
		{
			return _mm_rsqrt_ps(v);
		}

		// -----
		// min()
		// -----
		inline float32x4 min(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			return _mm_min_ps(v1, v2);
		}

		// -----
		// max()
		// -----
		inline float32x4 max(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			return _mm_max_ps(v1, v2);
		}

		// -----
		// abs()
		// -----
		inline float32x4 abs(const float32x4& v) noexcept
		{
			return _mm_and_ps(v, float32x4::binary(0x7FFFFFFF));
		}

		// -----
		// dot()
		// -----
		inline float32x4 dot(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return lhs * rhs;
		}

		// ---------
		// length2()
		// ---------
		inline float32x4 length2(const float32x4& v) noexcept
		{
			return v * v;
		}

		// --------
		// length()
		// --------
		inline float32x4 length(const float32x4& v) noexcept
		{
			return math::sqrt(math::length2(v));
		}

		// -----------
		// normalize()
		// -----------
		inline float32x4 normalize(const float32x4& v) noexcept
		{
			return v / math::length(v);
		}

		// -----------
		// transpose()
		// -----------
		inline void transpose(
			float32x4& v0,
			float32x4& v1,
			float32x4& v2,
			float32x4& v3) noexcept
		{
			_MM_TRANSPOSE4_PS(v0, v1, v2, v3);
		}

		// ------------------------------
		// piecewise comparison functions
		// ------------------------------
		inline float32x4 isless(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmplt_ps(lhs, rhs);
		}

		inline float32x4 islessequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmple_ps(lhs, rhs);
		}

		inline float32x4 isgreater(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmpgt_ps(lhs, rhs);
		}

		inline float32x4 isgreaterequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmpge_ps(lhs, rhs);
		}

		inline float32x4 isequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmpeq_ps(lhs, rhs);
		}

		inline float32x4 isnotequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return _mm_cmpneq_ps(lhs, rhs);
		}
	}
}
