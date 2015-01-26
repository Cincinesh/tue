//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../math.hpp"
#include "../unused.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// -------
	// vec4<T>
	// -------
	template<typename T>
	class vec<T, 4>
	{
	private:
		struct { T data[4]; } impl_;

	public:
		// -------------------
		// default constructor
		// -------------------
		vec() = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit constexpr vec(const T& s) :
			impl_({ { s, s, s, s } }) {}

		// ----------------------
		// component constructors
		// ----------------------
		constexpr vec(const T& x, const T& y, const T& z, const T& w) :
			impl_({ { x, y, z, w } }) {}

		explicit constexpr vec(const vec2<T>& xy, const T& z, const T& w) :
			impl_({ { xy[0], xy[1], z, w } }) {}

		explicit constexpr vec(const vec3<T>& xyz, const T& w) :
			impl_({ { xyz[0], xyz[1], xyz[2], w } }) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr vec(const vec4<U>& other) :
			impl_({ {
				T(other[0]),
				T(other[1]),
				T(other[2]),
				T(other[3]),
			} }) {}

		// ----------------------------
		// implicit conversion operator
		// ----------------------------
		template<typename U>
		constexpr operator vec4<U>() const
		{
			return{
				impl_.data[0],
				impl_.data[1],
				impl_.data[2],
				impl_.data[3],
			};
		}

		// ---------------
		// factory methods
		// ---------------
		static constexpr vec zero() { return{ T(0), T(0), T(0), T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0), T(0), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1), T(0), T(0) }; }
		static constexpr vec z_axis() { return{ T(0), T(0), T(1), T(0) }; }
		static constexpr vec w_axis() { return{ T(0), T(0), T(0), T(1) }; }

		// -
		// x
		// -
		constexpr T x() const { return impl_.data[0]; }
		void set_x(const T& x) { impl_.data[0] = x; }

		// -
		// y
		// -
		constexpr T y() const { return impl_.data[1]; }
		void set_y(const T& y) { impl_.data[1] = y; }

		// -
		// z
		// -
		constexpr T z() const { return impl_.data[2]; }
		void set_z(const T& z) { impl_.data[2] = z; }

		// -
		// w
		// -
		constexpr T w() const { return impl_.data[3]; }
		void set_w(const T& w) { impl_.data[3] = w; }

		// --
		// xy
		// --
		constexpr vec2<T> xy() const { return vec2<T>(*this); }
		
		void set_xy(const T& x, const T& y)
		{
			impl_.data[0] = x;
			impl_.data[1] = y;
		}
		
		void set_xy(const vec2<T>& xy)
		{
			set_xy(xy[0], xy[1]);
		}

		// ---
		// xyz
		// ---
		constexpr vec3<T> xyz() const { return vec3<T>(*this); }
		
		void set_xyz(const T& x, const T& y, const T& z)
		{
			impl_.data[0] = x;
			impl_.data[1] = y;
			impl_.data[2] = z;
		}
		
		void set_xyz(const vec3<T>& xyz)
		{
			set_xyz(xyz[0], xyz[1], xyz[2]);
		}

		// ----
		// v[i]
		// ----
		template<typename I>
		T& operator[](const I& i)
		{
			return impl_.data[i];
		}

		template<typename I>
		constexpr const T& operator[](const I& i) const
		{
			return impl_.data[i];
		}

		// ---
		// ++v
		// ---
		vec& operator++()
		{
			++impl_.data[0];
			++impl_.data[1];
			++impl_.data[2];
			++impl_.data[3];
			return *this;
		}

		// ---
		// --v
		// ---
		vec& operator--()
		{
			--impl_.data[0];
			--impl_.data[1];
			--impl_.data[2];
			--impl_.data[3];
			return *this;
		}

		// ---
		// v++
		// ---
		vec operator++(int)
		{
			const auto tmp = *this;
			++*this;
			return tmp;
		}

		// ---
		// v--
		// ---
		vec operator--(int)
		{
			const auto tmp = *this;
			--*this;
			return tmp;
		}

		// ----------
		// v += other
		// ----------
		template<typename U>
		vec& operator+=(const U& other)
		{
			impl_.data[0] += other;
			impl_.data[1] += other;
			impl_.data[2] += other;
			impl_.data[3] += other;
			return *this;
		}

		template<typename U>
		vec& operator+=(const vec4<U>& other)
		{
			impl_.data[0] += other[0];
			impl_.data[1] += other[1];
			impl_.data[2] += other[2];
			impl_.data[3] += other[3];
			return *this;
		}

		// ----------
		// v -= other
		// ----------
		template<typename U>
		vec& operator-=(const U& other)
		{
			impl_.data[0] -= other;
			impl_.data[1] -= other;
			impl_.data[2] -= other;
			impl_.data[3] -= other;
			return *this;
		}

		template<typename U>
		vec& operator-=(const vec4<U>& other)
		{
			impl_.data[0] -= other[0];
			impl_.data[1] -= other[1];
			impl_.data[2] -= other[2];
			impl_.data[3] -= other[3];
			return *this;
		}

		// ----------
		// v *= other
		// ----------
		template<typename U>
		vec& operator*=(const U& other)
		{
			impl_.data[0] *= other;
			impl_.data[1] *= other;
			impl_.data[2] *= other;
			impl_.data[3] *= other;
			return *this;
		}

		template<typename U>
		vec& operator*=(const vec4<U>& other)
		{
			impl_.data[0] *= other[0];
			impl_.data[1] *= other[1];
			impl_.data[2] *= other[2];
			impl_.data[3] *= other[3];
			return *this;
		}

		// ----------
		// v /= other
		// ----------
		template<typename U>
		vec& operator/=(const U& other)
		{
			impl_.data[0] /= other;
			impl_.data[1] /= other;
			impl_.data[2] /= other;
			impl_.data[3] /= other;
			return *this;
		}

		template<typename U>
		vec& operator/=(const vec4<U>& other)
		{
			impl_.data[0] /= other[0];
			impl_.data[1] /= other[1];
			impl_.data[2] /= other[2];
			impl_.data[3] /= other[3];
			return *this;
		}

		// ----------
		// v %= other
		// ----------
		template<typename U>
		vec& operator%=(const U& other)
		{
			impl_.data[0] %= other;
			impl_.data[1] %= other;
			impl_.data[2] %= other;
			impl_.data[3] %= other;
			return *this;
		}

		template<typename U>
		vec& operator%=(const vec4<U>& other)
		{
			impl_.data[0] %= other[0];
			impl_.data[1] %= other[1];
			impl_.data[2] %= other[2];
			impl_.data[3] %= other[3];
			return *this;
		}

		// ----------
		// v &= other
		// ----------
		template<typename U>
		vec& operator&=(const U& other)
		{
			impl_.data[0] &= other;
			impl_.data[1] &= other;
			impl_.data[2] &= other;
			impl_.data[3] &= other;
			return *this;
		}

		template<typename U>
		vec& operator&=(const vec4<U>& other)
		{
			impl_.data[0] &= other[0];
			impl_.data[1] &= other[1];
			impl_.data[2] &= other[2];
			impl_.data[3] &= other[3];
			return *this;
		}

		// ----------
		// v |= other
		// ----------
		template<typename U>
		vec& operator|=(const U& other)
		{
			impl_.data[0] |= other;
			impl_.data[1] |= other;
			impl_.data[2] |= other;
			impl_.data[3] |= other;
			return *this;
		}

		template<typename U>
		vec& operator|=(const vec4<U>& other)
		{
			impl_.data[0] |= other[0];
			impl_.data[1] |= other[1];
			impl_.data[2] |= other[2];
			impl_.data[3] |= other[3];
			return *this;
		}

		// ----------
		// v ^= other
		// ----------
		template<typename U>
		vec& operator^=(const U& other)
		{
			impl_.data[0] ^= other;
			impl_.data[1] ^= other;
			impl_.data[2] ^= other;
			impl_.data[3] ^= other;
			return *this;
		}

		template<typename U>
		vec& operator^=(const vec4<U>& other)
		{
			impl_.data[0] ^= other[0];
			impl_.data[1] ^= other[1];
			impl_.data[2] ^= other[2];
			impl_.data[3] ^= other[3];
			return *this;
		}

		// -----------
		// v <<= other
		// -----------
		template<typename U>
		vec& operator<<=(const U& other)
		{
			impl_.data[0] <<= other;
			impl_.data[1] <<= other;
			impl_.data[2] <<= other;
			impl_.data[3] <<= other;
			return *this;
		}

		template<typename U>
		vec& operator<<=(const vec4<U>& other)
		{
			impl_.data[0] <<= other[0];
			impl_.data[1] <<= other[1];
			impl_.data[2] <<= other[2];
			impl_.data[3] <<= other[3];
			return *this;
		}

		// -----------
		// v >>= other
		// -----------
		template<typename U>
		vec& operator>>=(const U& other)
		{
			impl_.data[0] >>= other;
			impl_.data[1] >>= other;
			impl_.data[2] >>= other;
			impl_.data[3] >>= other;
			return *this;
		}

		template<typename U>
		vec& operator>>=(const vec4<U>& other)
		{
			impl_.data[0] >>= other[0];
			impl_.data[1] >>= other[1];
			impl_.data[2] >>= other[2];
			impl_.data[3] >>= other[3];
			return *this;
		}

	private:
		// -----------------------------
		// private helpers for class mat
		// -----------------------------
		template<typename U, int C, int R>
		friend class mat;

		static constexpr vec extend_(
			const vec2<T>& v,
			const T& z,
			const T& w)
		{
			return vec(v, z, w);
		}

		static constexpr vec extend_(
			const vec3<T>& v,
			const T&,
			const T& w)
		{
			return vec(v, w);
		}

		static constexpr vec extend_(
			const vec4<T>& v,
			const T&,
			const T&)
		{
			return v;
		}
	};

	// --
	// +v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator+(const vec4<T>& v)
	{
		return vec4<decltype(+v[0])>(+v[0], +v[1], +v[2], +v[3]);
	}

	// --
	// -v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator-(const vec4<T>& v)
	{
		return vec4<decltype(-v[0])>(-v[0], -v[1], -v[2], -v[3]);
	}

	// --
	// ~v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator~(const vec4<T>& v)
	{
		return vec4<decltype(~v[0])>(~v[0], ~v[1], ~v[2], ~v[3]);
	}

	// ---------
	// lhs + rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs + rhs[0])>{
			lhs + rhs[0],
			lhs + rhs[1],
			lhs + rhs[2],
			lhs + rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] + rhs)>{
			lhs[0] + rhs,
			lhs[1] + rhs,
			lhs[2] + rhs,
			lhs[3] + rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] + rhs[0])>{
			lhs[0] + rhs[0],
			lhs[1] + rhs[1],
			lhs[2] + rhs[2],
			lhs[3] + rhs[3],
		};
	}

	// ---------
	// lhs - rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs - rhs[0])>{
			lhs - rhs[0],
			lhs - rhs[1],
			lhs - rhs[2],
			lhs - rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] - rhs)>{
			lhs[0] - rhs,
			lhs[1] - rhs,
			lhs[2] - rhs,
			lhs[3] - rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] - rhs[0])>{
			lhs[0] - rhs[0],
			lhs[1] - rhs[1],
			lhs[2] - rhs[2],
			lhs[3] - rhs[3],
		};
	}

	// ---------
	// lhs * rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs * rhs[0])>{
			lhs * rhs[0],
			lhs * rhs[1],
			lhs * rhs[2],
			lhs * rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] * rhs)>{
			lhs[0] * rhs,
			lhs[1] * rhs,
			lhs[2] * rhs,
			lhs[3] * rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] * rhs[0])>{
			lhs[0] * rhs[0],
			lhs[1] * rhs[1],
			lhs[2] * rhs[2],
			lhs[3] * rhs[3],
		};
	}

	// ---------
	// lhs / rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs / rhs[0])>{
			lhs / rhs[0],
			lhs / rhs[1],
			lhs / rhs[2],
			lhs / rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] / rhs)>{
			lhs[0] / rhs,
			lhs[1] / rhs,
			lhs[2] / rhs,
			lhs[3] / rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] / rhs[0])>{
			lhs[0] / rhs[0],
			lhs[1] / rhs[1],
			lhs[2] / rhs[2],
			lhs[3] / rhs[3],
		};
	}

	// ---------
	// lhs % rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs % rhs[0])>{
			lhs % rhs[0],
			lhs % rhs[1],
			lhs % rhs[2],
			lhs % rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] % rhs)>{
			lhs[0] % rhs,
			lhs[1] % rhs,
			lhs[2] % rhs,
			lhs[3] % rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] % rhs[0])>{
			lhs[0] % rhs[0],
			lhs[1] % rhs[1],
			lhs[2] % rhs[2],
			lhs[3] % rhs[3],
		};
	}

	// ---------
	// lhs & rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs & rhs[0])>{
			lhs & rhs[0],
			lhs & rhs[1],
			lhs & rhs[2],
			lhs & rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] & rhs)>{
			lhs[0] & rhs,
			lhs[1] & rhs,
			lhs[2] & rhs,
			lhs[3] & rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] & rhs[0])>{
			lhs[0] & rhs[0],
			lhs[1] & rhs[1],
			lhs[2] & rhs[2],
			lhs[3] & rhs[3],
		};
	}

	// ---------
	// lhs | rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs | rhs[0])>{
			lhs | rhs[0],
			lhs | rhs[1],
			lhs | rhs[2],
			lhs | rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] | rhs)>{
			lhs[0] | rhs,
			lhs[1] | rhs,
			lhs[2] | rhs,
			lhs[3] | rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] | rhs[0])>{
			lhs[0] | rhs[0],
			lhs[1] | rhs[1],
			lhs[2] | rhs[2],
			lhs[3] | rhs[3],
		};
	}

	// ---------
	// lhs ^ rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs ^ rhs[0])>{
			lhs ^ rhs[0],
			lhs ^ rhs[1],
			lhs ^ rhs[2],
			lhs ^ rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] ^ rhs)>{
			lhs[0] ^ rhs,
			lhs[1] ^ rhs,
			lhs[2] ^ rhs,
			lhs[3] ^ rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] ^ rhs[0])>{
			lhs[0] ^ rhs[0],
			lhs[1] ^ rhs[1],
			lhs[2] ^ rhs[2],
			lhs[3] ^ rhs[3],
		};
	}

	// ---------
	// lhs << rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs << rhs[0])>{
			lhs << rhs[0],
			lhs << rhs[1],
			lhs << rhs[2],
			lhs << rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] << rhs)>{
			lhs[0] << rhs,
			lhs[1] << rhs,
			lhs[2] << rhs,
			lhs[3] << rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] << rhs[0])>{
			lhs[0] << rhs[0],
			lhs[1] << rhs[1],
			lhs[2] << rhs[2],
			lhs[3] << rhs[3],
		};
	}

	// ---------
	// lhs >> rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const T& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs >> rhs[0])>{
			lhs >> rhs[0],
			lhs >> rhs[1],
			lhs >> rhs[2],
			lhs >> rhs[3],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec4<T>& lhs,
		const U& rhs)
	{
		return vec4<decltype(lhs[0] >> rhs)>{
			lhs[0] >> rhs,
			lhs[1] >> rhs,
			lhs[2] >> rhs,
			lhs[3] >> rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0] >> rhs[0])>{
			lhs[0] >> rhs[0],
			lhs[1] >> rhs[1],
			lhs[2] >> rhs[2],
			lhs[3] >> rhs[3],
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2]
			&& lhs[3] == rhs[3];
	}

	// ----------
	// lhs != rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator!=(
		const vec4<T>& lhs,
		const vec4<U>& rhs)
	{
		return !(lhs == rhs);
	}

	// ----
	// math
	// ----
	namespace math
	{
		// -----
		// sin()
		// -----
		template<typename T>
		inline auto sin(const vec4<T>& v)
		{
			return vec4<decltype(math::sin(v[0]))>{
				math::sin(v[0]),
				math::sin(v[1]),
				math::sin(v[2]),
				math::sin(v[3]),
			};
		}

		// -----
		// cos()
		// -----
		template<typename T>
		inline auto cos(const vec4<T>& v)
		{
			return vec4<decltype(math::cos(v[0]))>{
				math::cos(v[0]),
				math::cos(v[1]),
				math::cos(v[2]),
				math::cos(v[3]),
			};
		}

		// --------
		// sincos()
		// --------
		template<typename T>
		inline void sincos(
			const vec4<T>& v,
			decltype(math::sin(v))& sin_result,
			decltype(math::cos(v))& cos_result)
		{
			math::sincos(v[0], sin_result[0], cos_result[0]);
			math::sincos(v[1], sin_result[1], cos_result[1]);
			math::sincos(v[2], sin_result[2], cos_result[2]);
			math::sincos(v[3], sin_result[3], cos_result[3]);
		}

		// -----
		// pow()
		// -----
		template<typename T, typename U>
		inline auto pow(
			const vec4<T>& base,
			const U& exponent)
		{
			return vec4<decltype(math::pow(base[0], exponent))>{
				math::pow(base[0], exponent),
				math::pow(base[1], exponent),
				math::pow(base[2], exponent),
				math::pow(base[3], exponent),
			};
		}

		template<typename T, typename U>
		inline auto pow(
			const vec4<T>& base,
			const vec4<U>& exponent)
		{
			return vec4<decltype(math::pow(base[0], exponent[0]))>{
				math::pow(base[0], exponent[0]),
				math::pow(base[1], exponent[1]),
				math::pow(base[2], exponent[2]),
				math::pow(base[3], exponent[3]),
			};
		}

		// -----
		// rcp()
		// -----
		template<typename T>
		inline auto rcp(const vec4<T>& v)
		{
			return vec4<decltype(math::rcp(v[0]))>{
				math::rcp(v[0]),
				math::rcp(v[1]),
				math::rcp(v[2]),
				math::rcp(v[3]),
			};
		}

		// ------
		// sqrt()
		// ------
		template<typename T>
		inline auto sqrt(const vec4<T>& v)
		{
			return vec4<decltype(math::sqrt(v[0]))>{
				math::sqrt(v[0]),
				math::sqrt(v[1]),
				math::sqrt(v[2]),
				math::sqrt(v[3]),
			};
		}

		// -------
		// rsqrt()
		// -------
		template<typename T>
		inline auto rsqrt(const vec4<T>& v)
		{
			return vec4<decltype(math::rsqrt(v[0]))>{
				math::rsqrt(v[0]),
				math::rsqrt(v[1]),
				math::rsqrt(v[2]),
				math::rsqrt(v[3]),
			};
		}

		// -----
		// min()
		// -----
		template<typename T>
		inline auto min(const vec4<T>& v1, const vec4<T>& v2)
		{
			return vec4<decltype(math::min(v1[0], v2[0]))>{
				math::min(v1[0], v2[0]),
				math::min(v1[1], v2[1]),
				math::min(v1[2], v2[2]),
				math::min(v1[3], v2[3]),
			};
		}

		// -----
		// max()
		// -----
		template<typename T>
		inline auto max(const vec4<T>& v1, const vec4<T>& v2)
		{
			return vec4<decltype(math::max(v1[0], v2[0]))>{
				math::max(v1[0], v2[0]),
				math::max(v1[1], v2[1]),
				math::max(v1[2], v2[2]),
				math::max(v1[3], v2[3]),
			};
		}

		// -----
		// abs()
		// -----
		template<typename T>
		inline auto abs(const vec4<T>& v)
		{
			return vec4<decltype(math::abs(v[0]))>{
				math::abs(v[0]),
				math::abs(v[1]),
				math::abs(v[2]),
				math::abs(v[3]),
			};
		}

		// -----
		// dot()
		// -----
		template<typename T, typename U>
		inline TUE_CONSTEXPR auto dot(
			const vec4<T>& lhs,
			const vec4<U>& rhs)
		{
			return lhs[0] * rhs[0]
				+ lhs[1] * rhs[1]
				+ lhs[2] * rhs[2]
				+ lhs[3] * rhs[3];
		}

		// ---------
		// length2()
		// ---------
		template<typename T>
		inline auto length2(const vec4<T>& v)
		{
			return math::length2(v[0])
				+ math::length2(v[1])
				+ math::length2(v[2])
				+ math::length2(v[3]);
		}

		// --------
		// length()
		// --------
		template<typename T>
		inline auto length(const vec4<T>& v)
		{
			return math::sqrt(math::length2(v));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline auto normalize(const vec4<T>& v)
		{
			return vec4<decltype(math::length(v))>(v)
				/ math::length(v);
		}
	}
}

#undef TUE_CONSTEXPR
