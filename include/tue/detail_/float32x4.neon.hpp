//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

/*
  This file contains code based on Julien Pommier's neon_mathfun.h
  originally published at:

  http://gruntthepeon.free.fr/ssemath/neon_mathfun.html

  Under the following license:

  Copyright (C) 2011  Julien Pommier

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

#include <arm_neon.h>

namespace tue
{
	// ---------
	// float32x4
	// ---------
	class float32x4
	{
	private:
		float32x4_t underlying_;

	public:
		// -------------------
		// default constructor
		// -------------------
		float32x4() noexcept = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit float32x4(float s) noexcept :
			underlying_{ s, s, s, s } {}

		// ---------------------
		// component constructor
		// ---------------------
		float32x4(float x, float y, float z, float w) noexcept :
			underlying_{ x, y, z, w } {}

		// ---------------------------------
		// underlying conversion constructor
		// ---------------------------------
		float32x4(float32x4_t underlying) noexcept :
			underlying_(underlying) {}

		// ------------------------------
		// underlying conversion operator
		// ------------------------------
		operator float32x4_t() const noexcept { return underlying_; }

		// ---------------
		// factory methods
		// ---------------
		static float32x4 zero() noexcept
		{
			return float32x4(0);
		}

		static float32x4 binary(unsigned int i) noexcept
		{
			return float32x4(reinterpret_cast<float&>(i));
		}

		static float32x4 binary(
			unsigned int x,
			unsigned int y,
			unsigned int z,
			unsigned int w) noexcept
		{
			return{
				reinterpret_cast<float&>(x),
				reinterpret_cast<float&>(y),
				reinterpret_cast<float&>(z),
				reinterpret_cast<float&>(w),
			};
		}

		static float32x4 load(const float* array) noexcept
		{
			return vld1q_f32(array);
		}

		static float32x4 loadu(const float* array) noexcept
		{
			return vld1q_f32(array);
		}

		// -------
		// store()
		// -------
		void store(float* destination) const noexcept
		{
			vst1q_f32(destination, underlying_);
		}

		void storeu(float* destination) const noexcept
		{
			vst1q_f32(destination, underlying_);
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
		const uint32x4_t result = veorq_u32(
			reinterpret_cast<const uint32x4_t&>(v),
			vdupq_n_u32(0x80000000));
		return reinterpret_cast<const float32x4&>(result);
	}

	inline float32x4 operator~(const float32x4& v) noexcept
	{
		const uint32x4_t result = vmvnq_u32(
			reinterpret_cast<const uint32x4_t&>(v));
		return reinterpret_cast<const float32x4&>(result);
	}

	// --------------------
	// arithmetic operators
	// --------------------
	inline float32x4 operator+(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return vaddq_f32(lhs, rhs);
	}

	inline float32x4 operator-(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return vsubq_f32(lhs, rhs);
	}

	inline float32x4 operator*(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		return vmulq_f32(lhs, rhs);
	}

	inline float32x4 operator/(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		float32x4_t r = vrecpeq_f32(rhs);
		r = vmulq_f32(vrecpsq_f32(rhs, r), r);
		return vmulq_f32(lhs, r);
	}

	// -----------------
	// bitwise operators
	// -----------------
	inline float32x4 operator&(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		const uint32x4_t result = vandq_u32(
			reinterpret_cast<const uint32x4_t&>(lhs),
			reinterpret_cast<const uint32x4_t&>(rhs));
		return reinterpret_cast<const float32x4&>(result);
	}

	inline float32x4 operator|(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		const uint32x4_t result = vorrq_u32(
			reinterpret_cast<const uint32x4_t&>(lhs),
			reinterpret_cast<const uint32x4_t&>(rhs));
		return reinterpret_cast<const float32x4&>(result);
	}

	inline float32x4 operator^(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		const uint32x4_t result = veorq_u32(
			reinterpret_cast<const uint32x4_t&>(lhs),
			reinterpret_cast<const uint32x4_t&>(rhs));
		return reinterpret_cast<const float32x4&>(result);
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
		uint32x4_t i4 = vceqq_f32(lhs, rhs);
		uint32x2_t i2 = vand_u32(vget_low_u32(i4), vget_high_u32(i4));
		i2 = vand_u32(i2, vext_u32(i2, i2, 1));
		i2 = vand_u32(i2, vdup_n_u32(1));
		return vget_lane_u32(i2, 0) != 0;
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

			// TODO
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

			// TODO
			return float32x4(0.0f);
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

			// TODO
			return float32x4(0.0f);
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
			const float32x4_t r = vrecpeq_f32(v);
			return vmulq_f32(vrecpsq_f32(v, r), r);
		}

		// -------
		// rsqrt()
		// -------
		inline float32x4 rsqrt(const float32x4& v) noexcept
		{
			const float32x4_t r = vrsqrteq_f32(v);
			return vmulq_f32(vrsqrtsq_f32(v, r), r);
		}

		// ------
		// sqrt()
		// ------
		inline float32x4 sqrt(const float32x4& v) noexcept
		{
			return math::recip(math::rsqrt(v));
		}

		// -----
		// min()
		// -----
		inline float32x4 min(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			return vminq_f32(v1, v2);
		}

		// -----
		// max()
		// -----
		inline float32x4 max(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			return vmaxq_f32(v1, v2);
		}

		// -----
		// abs()
		// -----
		inline float32x4 abs(const float32x4& v) noexcept
		{
			return v & float32x4::binary(0x7FFFFFFF);
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
			return v * math::rsqrt(math::length2(v));
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
			float32x4x2_t tmp1 = vtrnq_f32(v0, v1);
			v0 = reinterpret_cast<float32x4*>(&tmp1)[0];
			v1 = reinterpret_cast<float32x4*>(&tmp1)[1];
			
			tmp1 = vtrnq_f32(v2, v3);
			v2 = reinterpret_cast<float32x4*>(&tmp1)[0];
			v3 = reinterpret_cast<float32x4*>(&tmp1)[1];

			float32x2_t tmp2 = vget_high_f32(v0);
			v0 = vcombine_f32(vget_low_f32(v0), vget_low_f32(v2));
			v2 = vcombine_f32(tmp2, vget_high_f32(v2));
			
			tmp2 = vget_high_f32(v1);
			v1 = vcombine_f32(vget_low_f32(v1), vget_low_f32(v3));
			v3 = vcombine_f32(tmp2, vget_high_f32(v3));
		}

		// ------------------------------
		// piecewise comparison functions
		// ------------------------------
		inline float32x4 isless(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			const uint32x4_t result = vcltq_f32(lhs, rhs);
			return reinterpret_cast<const float32x4&>(result);
		}

		inline float32x4 islessequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			const uint32x4_t result = vcleq_f32(lhs, rhs);
			return reinterpret_cast<const float32x4&>(result);
		}

		inline float32x4 isgreater(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			const uint32x4_t result = vcgtq_f32(lhs, rhs);
			return reinterpret_cast<const float32x4&>(result);
		}

		inline float32x4 isgreaterequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			const uint32x4_t result = vcgeq_f32(lhs, rhs);
			return reinterpret_cast<const float32x4&>(result);
		}

		inline float32x4 isequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			const uint32x4_t result = vceqq_f32(lhs, rhs);
			return reinterpret_cast<const float32x4&>(result);
		}

		inline float32x4 isnotequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			return ~isequal(lhs, rhs);
		}
	}
}
