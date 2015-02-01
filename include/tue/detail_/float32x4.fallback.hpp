//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <algorithm>
#include <cmath>

namespace tue
{
	// ---------
	// float32x4
	// ---------
	class float32x4
	{
	private:
		float x, y, z, w;

	public:
		// -------------------
		// default constructor
		// -------------------
		float32x4() noexcept = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit float32x4(float s) noexcept :
			x(s), y(s), z(s), w(s) {}

		// ---------------------
		// component constructor
		// ---------------------
		float32x4(float x, float y, float z, float w) noexcept :
			x(x), y(y), z(z), w(w) {}

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
			return{ array[0], array[1], array[2], array[3] };
		}

		static float32x4 loadu(const float* array) noexcept
		{
			// unaligned
			return load(array);
		}

		// -------
		// store()
		// -------
		void store(float* destination) const noexcept
		{
			destination[0] = x;
			destination[1] = y;
			destination[2] = z;
			destination[3] = w;
		}

		void storeu(float* destination) const noexcept
		{
			store(destination);
		}
	};

	// ----------------
	// prefix operators
	// ----------------
	inline float32x4 operator+(const float32x4& v) noexcept
	{
		float f[4];
		v.store(f);
		return{ +f[0], +f[1], +f[2], +f[3] };
	}

	inline float32x4 operator-(const float32x4& v) noexcept
	{
		float f[4];
		v.store(f);
		return{ -f[0], -f[1], -f[2], -f[3] };
	}

	inline float32x4 operator~(const float32x4& v) noexcept
	{
		unsigned int i[4];
		v.store(reinterpret_cast<float*>(&i));
		return float32x4::binary(~i[0], ~i[1], ~i[2], ~i[3]);
	}

	// --------------------
	// arithmetic operators
	// --------------------
	inline float32x4 operator+(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		float lf[4], rf[4];
		lhs.store(lf);
		rhs.store(rf);
		return{
			lf[0] + rf[0],
			lf[1] + rf[1],
			lf[2] + rf[2],
			lf[3] + rf[3],
		};
	}

	inline float32x4 operator-(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		float lf[4], rf[4];
		lhs.store(lf);
		rhs.store(rf);
		return{
			lf[0] - rf[0],
			lf[1] - rf[1],
			lf[2] - rf[2],
			lf[3] - rf[3],
		};
	}

	inline float32x4 operator*(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		float lf[4], rf[4];
		lhs.store(lf);
		rhs.store(rf);
		return{
			lf[0] * rf[0],
			lf[1] * rf[1],
			lf[2] * rf[2],
			lf[3] * rf[3],
		};
	}

	inline float32x4 operator/(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		float lf[4], rf[4];
		lhs.store(lf);
		rhs.store(rf);
		return{
			lf[0] / rf[0],
			lf[1] / rf[1],
			lf[2] / rf[2],
			lf[3] / rf[3],
		};
	}

	// -----------------
	// bitwise operators
	// -----------------
	inline float32x4 operator&(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		unsigned int li[4], ri[4];
		lhs.store(reinterpret_cast<float*>(&li));
		rhs.store(reinterpret_cast<float*>(&ri));
		return float32x4::binary(
			li[0] & ri[0],
			li[1] & ri[1],
			li[2] & ri[2],
			li[3] & ri[3]);
	}

	inline float32x4 operator|(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		unsigned int li[4], ri[4];
		lhs.store(reinterpret_cast<float*>(&li));
		rhs.store(reinterpret_cast<float*>(&ri));
		return float32x4::binary(
			li[0] | ri[0],
			li[1] | ri[1],
			li[2] | ri[2],
			li[3] | ri[3]);
	}

	inline float32x4 operator^(
		const float32x4& lhs,
		const float32x4& rhs) noexcept
	{
		unsigned int li[4], ri[4];
		lhs.store(reinterpret_cast<float*>(&li));
		rhs.store(reinterpret_cast<float*>(&ri));
		return float32x4::binary(
			li[0] ^ ri[0],
			li[1] ^ ri[1],
			li[2] ^ ri[2],
			li[3] ^ ri[3]);
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
		float lf[4], rf[4];
		lhs.store(lf);
		rhs.store(rf);
		return lf[0] == rf[0]
			&& lf[1] == rf[1]
			&& lf[2] == rf[2]
			&& lf[3] == rf[3];
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
		// -----
		// sin()
		// -----
		inline float32x4 sin(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::sin(f[0]),
				std::sin(f[1]),
				std::sin(f[2]),
				std::sin(f[3]),
			};
		}

		// -----
		// cos()
		// -----
		inline float32x4 cos(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::cos(f[0]),
				std::cos(f[1]),
				std::cos(f[2]),
				std::cos(f[3]),
			};
		}

		// --------
		// sincos()
		// --------
		inline void sincos(
			const float32x4& v,
			float32x4& sin_result,
			float32x4& cos_result) noexcept
		{
			sin_result = math::sin(v);
			cos_result = math::cos(v);
		}

		// -----
		// exp()
		// -----
		inline float32x4 exp(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::exp(f[0]),
				std::exp(f[1]),
				std::exp(f[2]),
				std::exp(f[3]),
			};
		}

		// -----
		// log()
		// -----
		inline float32x4 log(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::log(f[0]),
				std::log(f[1]),
				std::log(f[2]),
				std::log(f[3]),
			};
		}
		
		// -----
		// pow()
		// -----
		inline float32x4 pow(
			const float32x4& base,
			const float32x4& exponent) noexcept
		{
			float bf[4], ef[4];
			base.store(bf);
			exponent.store(ef);
			return{
				std::pow(bf[0], ef[0]),
				std::pow(bf[1], ef[1]),
				std::pow(bf[2], ef[2]),
				std::pow(bf[3], ef[3]),
			};
		}

		// -------
		// recip()
		// -------
		inline float32x4 recip(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				1 / f[0],
				1 / f[1],
				1 / f[2],
				1 / f[3],
			};
		}

		// ------
		// sqrt()
		// ------
		inline float32x4 sqrt(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::sqrt(f[0]),
				std::sqrt(f[1]),
				std::sqrt(f[2]),
				std::sqrt(f[3]),
			};
		}

		// -------
		// rsqrt()
		// -------
		inline float32x4 rsqrt(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				1 / std::sqrt(f[0]),
				1 / std::sqrt(f[1]),
				1 / std::sqrt(f[2]),
				1 / std::sqrt(f[3]),
			};
		}

		// -----
		// min()
		// -----
		inline float32x4 min(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			float f1[4], f2[4];
			v1.store(f1);
			v2.store(f2);
			return{
				std::min(f1[0], f2[0]),
				std::min(f1[1], f2[1]),
				std::min(f1[2], f2[2]),
				std::min(f1[3], f2[3]),
			};
		}

		// -----
		// max()
		// -----
		inline float32x4 max(
			const float32x4& v1,
			const float32x4& v2) noexcept
		{
			float f1[4], f2[4];
			v1.store(f1);
			v2.store(f2);
			return{
				std::max(f1[0], f2[0]),
				std::max(f1[1], f2[1]),
				std::max(f1[2], f2[2]),
				std::max(f1[3], f2[3]),
			};
		}

		// -----
		// abs()
		// -----
		inline float32x4 abs(const float32x4& v) noexcept
		{
			float f[4];
			v.store(f);
			return{
				std::abs(f[0]),
				std::abs(f[1]),
				std::abs(f[2]),
				std::abs(f[3]),
			};
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
			float f0[4], f1[4], f2[4], f3[4];
			v0.store(f0);
			v1.store(f1);
			v2.store(f2);
			v3.store(f3);
			v0 = { f0[0], f1[0], f2[0], f3[0] };
			v1 = { f0[1], f1[1], f2[1], f3[1] };
			v2 = { f0[2], f1[2], f2[2], f3[2] };
			v3 = { f0[3], f1[3], f2[3], f3[3] };
		}

		// ------------------------------
		// piecewise comparison functions
		// ------------------------------
		inline float32x4 isless(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] < rf[0] ? ~0 : 0,
				lf[1] < rf[1] ? ~0 : 0,
				lf[2] < rf[2] ? ~0 : 0,
				lf[3] < rf[3] ? ~0 : 0);
		}

		inline float32x4 islessequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] <= rf[0] ? ~0 : 0,
				lf[1] <= rf[1] ? ~0 : 0,
				lf[2] <= rf[2] ? ~0 : 0,
				lf[3] <= rf[3] ? ~0 : 0);
		}

		inline float32x4 isgreater(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] > rf[0] ? ~0 : 0,
				lf[1] > rf[1] ? ~0 : 0,
				lf[2] > rf[2] ? ~0 : 0,
				lf[3] > rf[3] ? ~0 : 0);
		}

		inline float32x4 isgreaterequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] >= rf[0] ? ~0 : 0,
				lf[1] >= rf[1] ? ~0 : 0,
				lf[2] >= rf[2] ? ~0 : 0,
				lf[3] >= rf[3] ? ~0 : 0);
		}

		inline float32x4 isequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] == rf[0] ? ~0 : 0,
				lf[1] == rf[1] ? ~0 : 0,
				lf[2] == rf[2] ? ~0 : 0,
				lf[3] == rf[3] ? ~0 : 0);
		}

		inline float32x4 isnotequal(
			const float32x4& lhs,
			const float32x4& rhs) noexcept
		{
			float lf[4], rf[4];
			lhs.store(lf);
			rhs.store(rf);
			return float32x4::binary(
				lf[0] != rf[0] ? ~0 : 0,
				lf[1] != rf[1] ? ~0 : 0,
				lf[2] != rf[2] ? ~0 : 0,
				lf[3] != rf[3] ? ~0 : 0);
		}
	}
}