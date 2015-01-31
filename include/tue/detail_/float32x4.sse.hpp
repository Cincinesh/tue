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

		static float32x4 load(const float* array)
		{
			return _mm_load_ps(array);
		}

		static float32x4 loadu(const float* array)
		{
			// unaligned
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
			// unaligned
			_mm_storeu_ps(destination, underlying_);
		}
	};

	// ----------------
	// prefix operators
	// ----------------
	inline float32x4 operator+(float32x4 v) noexcept
	{
		return v;
	}

	inline float32x4 operator-(float32x4 v) noexcept
	{
		const auto sign_bits_int = 0x80000000;
		const auto sign_bits = _mm_load_ps1(
			reinterpret_cast<const float*>(&sign_bits_int));
		return _mm_xor_ps(v, sign_bits);
	}

	inline float32x4 operator~(float32x4 v) noexcept
	{
		const auto all_bits_int = 0xFFFFFFFF;
		const auto all_bits = _mm_load_ps1(
			reinterpret_cast<const float*>(&all_bits_int));
		return _mm_xor_ps(v, all_bits);
	}

	// --------------------
	// arithmetic operators
	// --------------------
	inline float32x4 operator+(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_add_ps(lhs, rhs);
	}

	inline float32x4 operator-(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_sub_ps(lhs, rhs);
	}

	inline float32x4 operator*(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_mul_ps(lhs, rhs);
	}

	inline float32x4 operator/(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_div_ps(lhs, rhs);
	}

	// -----------------
	// bitwise operators
	// -----------------
	inline float32x4 operator&(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_and_ps(lhs, rhs);
	}

	inline float32x4 operator|(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_or_ps(lhs, rhs);
	}

	inline float32x4 operator^(float32x4 lhs, float32x4 rhs) noexcept
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
	inline float32x4& operator+=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs + rhs;
	}

	inline float32x4& operator-=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs - rhs;
	}

	inline float32x4& operator*=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs * rhs;
	}

	inline float32x4& operator/=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs / rhs;
	}

	// ----------------------------
	// bitwise assignment operators
	// ----------------------------
	inline float32x4& operator&=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs & rhs;
	}

	inline float32x4& operator|=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs | rhs;
	}

	inline float32x4& operator^=(float32x4& lhs, float32x4 rhs) noexcept
	{
		return lhs = lhs ^ rhs;
	}

	// --------------------
	// comparison operators
	// --------------------
	inline bool operator==(float32x4 lhs, float32x4 rhs) noexcept
	{
		return _mm_movemask_ps(_mm_cmpeq_ps(lhs, rhs)) == 0b1111;
	}

	inline bool operator!=(float32x4 lhs, float32x4 rhs) noexcept
	{
		return !(lhs == rhs);
	}

	// ------
	// math()
	// ------
	namespace math
	{
		// -----------------------
		// trigonometric functions
		// -----------------------
		inline void sincos(
			float32x4 v,
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
#endif

			sign_bit_sin = x;

			/* take the absolute value */
			const int inv_sign_mask = ~0x80000000;
			const __m128 ps_inv_sign_mask = _mm_load_ps1(
				reinterpret_cast<const float*>(&inv_sign_mask));
			x = _mm_and_ps(x, ps_inv_sign_mask);

			/* extract the sign bit (upper one) */
			const int sign_mask = 0x80000000;
			const __m128 ps_sign_mask = _mm_load_ps1(
				reinterpret_cast<const float*>(&sign_mask));
			sign_bit_sin = _mm_and_ps(sign_bit_sin, ps_sign_mask);

			/* scale by 4/Pi */
			y = _mm_mul_ps(x, _mm_set_ps1(1.27323954473516f));

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
			__m128 swap_sign_bit_sin;
			union {
				__m128 xmm;
				__m64 mm[2];
			}
			u1; u1.mm[0]=mm0; u1.mm[1]=mm1; swap_sign_bit_sin = u1.xmm;

			/* get the polynom selection mask for the sine */

			mm2 = _mm_and_si64(mm2, _mm_set1_pi32(2));
			mm3 = _mm_and_si64(mm3, _mm_set1_pi32(2));
			mm2 = _mm_cmpeq_pi32(mm2, _mm_setzero_si64());
			mm3 = _mm_cmpeq_pi32(mm3, _mm_setzero_si64());
			__m128 poly_mask;

			union {
				__m128 xmm;
				__m64 mm[2];
			}
			u2; u2.mm[0]=mm2; u2.mm[1]=mm3; poly_mask = u2.xmm;
#endif

			/* The magic pass: "Extended precision modular arithmetic"
			   x = ((x - y * DP1) - y * DP2) - y * DP3; */
			xmm1 = _mm_set_ps1(-0.78515625f);
			xmm2 = _mm_set_ps1(-2.4187564849853515625e-4f);
			xmm3 = _mm_set_ps1(-3.77489497744594108e-8f);
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
			__m128 sign_bit_cos;

			union {
				__m128 xmm;
				__m64 mm[2];
			}
			u3; u3.mm[0]=mm4; u3.mm[1]=mm5; sign_bit_cos = u3.xmm;
			_mm_empty(); /* good-bye mmx */
#endif

			sign_bit_sin = _mm_xor_ps(sign_bit_sin, swap_sign_bit_sin);

			/* Evaluate the first polynom  (0 <= x <= Pi/4) */
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

			/* Evaluate the second polynom  (Pi/4 <= x <= 0) */
			__m128 y2 = _mm_set_ps1(-1.9515295891e-4f);
			y2 = _mm_mul_ps(y2, z);
			y2 = _mm_add_ps(y2, _mm_set_ps1(8.3321608736e-3f));
			y2 = _mm_mul_ps(y2, z);
			y2 = _mm_add_ps(y2, _mm_set_ps1(-1.6666654611e-1f));
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

		inline float32x4 sin(float32x4 v) noexcept
		{
			float32x4 sin_result, cos_result;
			sincos(v, sin_result, cos_result);
			return sin_result;
		}

		inline float32x4 cos(float32x4 v) noexcept
		{
			float32x4 sin_result, cos_result;
			sincos(v, sin_result, cos_result);
			return cos_result;
		}
		
		// ---------------
		// power functions
		// ---------------
		//inline float32x4 pow(float32x4 base, float32x4 exponent) noexcept
		//{
		//
		//}

		inline float32x4 recip(float32x4 v) noexcept
		{
			return _mm_rcp_ps(v);
		}

		inline float32x4 sqrt(float32x4 v) noexcept
		{
			return _mm_sqrt_ps(v);
		}

		inline float32x4 rsqrt(float32x4 v) noexcept
		{
			return _mm_rsqrt_ps(v);
		}

		// -----------------------------
		// minimum and maximum functions
		// -----------------------------
		inline float32x4 min(float32x4 v1, float32x4 v2) noexcept
		{
			return _mm_min_ps(v1, v2);
		}

		inline float32x4 max(float32x4 v1, float32x4 v2) noexcept
		{
			return _mm_max_ps(v1, v2);
		}

		// -----------------------
		// absolute value function
		// -----------------------
		inline float32x4 abs(float32x4 v) noexcept
		{
			const auto non_sign_bits_int = 0x7FFFFFFF;
			const auto non_sign_bits = _mm_load_ps1(
				reinterpret_cast<const float*>(&non_sign_bits_int));
			return _mm_and_ps(v, non_sign_bits);
		}

		// -------------------
		// geometric functions
		// -------------------
		inline float32x4 dot(float32x4 lhs, float32x4 rhs) noexcept
		{
			return lhs * rhs;
		}

		inline float32x4 length2(float32x4 v) noexcept
		{
			return v * v;
		}

		inline float32x4 length(float32x4 v) noexcept
		{
			return math::sqrt(math::length2(v));
		}

		inline float32x4 normalize(float32x4 v) noexcept
		{
			return v / math::length(v);
		}

		inline void transpose(
			float32x4& v1,
			float32x4& v2,
			float32x4& v3,
			float32x4& v4)
		{
			_MM_TRANSPOSE4_PS(v1, v2, v3, v4);
		}

		// ------------------------------
		// piecewise comparison functions
		// ------------------------------
		inline float32x4 isless(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmplt_ps(lhs, rhs);
		}

		inline float32x4 islessequal(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmple_ps(lhs, rhs);
		}

		inline float32x4 isgreater(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmpgt_ps(lhs, rhs);
		}

		inline float32x4 isgreaterequal(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmpge_ps(lhs, rhs);
		}

		inline float32x4 isequal(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmpeq_ps(lhs, rhs);
		}

		inline float32x4 isnotequal(float32x4 lhs, float32x4 rhs) noexcept
		{
			return _mm_cmpneq_ps(lhs, rhs);
		}
	}
}
