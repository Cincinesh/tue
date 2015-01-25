//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../math.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// -------
	// vec2<T>
	// -------
	template<typename T>
	class vec<T, 2>
	{
	private:
		struct { T data[2]; } impl_;

	public:
		// -------------------
		// default constructor
		// -------------------
		vec() = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit constexpr vec(const T& s) :
			impl_({ { s, s } }) {}

		// ----------------------
		// component constructors
		// ----------------------
		constexpr vec(const T& x, const T& y) :
			impl_({ { x, y } }) {}

		// ---------------------
		// truncate constructors
		// ---------------------
		explicit constexpr vec(const vec3<T>& other) :
			impl_({ { other[0], other[1] } }) {}

		explicit constexpr vec(const vec4<T>& other) :
			impl_({ { other[0], other[1] } }) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr vec(const vec2<U>& other) :
			impl_({ {
				T(other[0]),
				T(other[1]),
			} }) {}

		// ----------------------------
		// implicit conversion operator
		// ----------------------------
		template<typename U>
		constexpr operator vec2<U>() const
		{
			return{
				impl_.data[0],
				impl_.data[1],
			};
		}

		// ---------------
		// factory methods
		// ---------------
		static constexpr vec zero() { return{ T(0), T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1) }; }

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
			return *this;
		}

		// ---
		// --v
		// ---
		vec& operator--()
		{
			--impl_.data[0];
			--impl_.data[1];
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
			return *this;
		}

		template<typename U>
		vec& operator+=(const vec2<U>& other)
		{
			impl_.data[0] += other[0];
			impl_.data[1] += other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator-=(const vec2<U>& other)
		{
			impl_.data[0] -= other[0];
			impl_.data[1] -= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator*=(const vec2<U>& other)
		{
			impl_.data[0] *= other[0];
			impl_.data[1] *= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator/=(const vec2<U>& other)
		{
			impl_.data[0] /= other[0];
			impl_.data[1] /= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator%=(const vec2<U>& other)
		{
			impl_.data[0] %= other[0];
			impl_.data[1] %= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator&=(const vec2<U>& other)
		{
			impl_.data[0] &= other[0];
			impl_.data[1] &= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator|=(const vec2<U>& other)
		{
			impl_.data[0] |= other[0];
			impl_.data[1] |= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator^=(const vec2<U>& other)
		{
			impl_.data[0] ^= other[0];
			impl_.data[1] ^= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator<<=(const vec2<U>& other)
		{
			impl_.data[0] <<= other[0];
			impl_.data[1] <<= other[1];
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
			return *this;
		}

		template<typename U>
		vec& operator>>=(const vec2<U>& other)
		{
			impl_.data[0] >>= other[0];
			impl_.data[1] >>= other[1];
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
			const T&,
			const T&)
		{
			return v;
		}

		static constexpr vec extend_(
			const vec3<T>& v,
			const T&,
			const T&)
		{
			return vec(v);
		}

		static constexpr vec extend_(
			const vec4<T>& v,
			const T&,
			const T&)
		{
			return vec(v);
		}
	};

	// --
	// +v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator+(const vec2<T>& v)
		-> vec2<decltype(+v[0])>
	{
		return{ +v[0], +v[1] };
	}

	// --
	// -v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator-(const vec2<T>& v)
		-> vec2<decltype(+v[0])>
	{
		return{ -v[0], -v[1] };
	}

	// --
	// ~v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator~(const vec2<T>& v)
		-> vec2<decltype(~v[0])>
	{
		return{ ~v[0], ~v[1] };
	}

	// ---------
	// lhs + rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs + rhs[0])>
	{
		return{
			lhs + rhs[0],
			lhs + rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] + rhs)>
	{
		return{
			lhs[0] + rhs,
			lhs[1] + rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] + rhs[0])>
	{
		return{
			lhs[0] + rhs[0],
			lhs[1] + rhs[1],
		};
	}

	// ---------
	// lhs - rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs - rhs[0])>
	{
		return{
			lhs - rhs[0],
			lhs - rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] - rhs)>
	{
		return{
			lhs[0] - rhs,
			lhs[1] - rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] - rhs[0])>
	{
		return{
			lhs[0] - rhs[0],
			lhs[1] - rhs[1],
		};
	}

	// ---------
	// lhs * rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs * rhs[0])>
	{
		return{
			lhs * rhs[0],
			lhs * rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] * rhs)>
	{
		return{
			lhs[0] * rhs,
			lhs[1] * rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] * rhs[0])>
	{
		return{
			lhs[0] * rhs[0],
			lhs[1] * rhs[1],
		};
	}

	// ---------
	// lhs / rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs / rhs[0])>
	{
		return{
			lhs / rhs[0],
			lhs / rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] / rhs)>
	{
		return{
			lhs[0] / rhs,
			lhs[1] / rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] / rhs[0])>
	{
		return{
			lhs[0] / rhs[0],
			lhs[1] / rhs[1],
		};
	}

	// ---------
	// lhs % rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs % rhs[0])>
	{
		return{
			lhs % rhs[0],
			lhs % rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] % rhs)>
	{
		return{
			lhs[0] % rhs,
			lhs[1] % rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] % rhs[0])>
	{
		return{
			lhs[0] % rhs[0],
			lhs[1] % rhs[1],
		};
	}

	// ---------
	// lhs & rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs & rhs[0])>
	{
		return{
			lhs & rhs[0],
			lhs & rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] & rhs)>
	{
		return{
			lhs[0] & rhs,
			lhs[1] & rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] & rhs[0])>
	{
		return{
			lhs[0] & rhs[0],
			lhs[1] & rhs[1],
		};
	}

	// ---------
	// lhs | rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs | rhs[0])>
	{
		return{
			lhs | rhs[0],
			lhs | rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] | rhs)>
	{
		return{
			lhs[0] | rhs,
			lhs[1] | rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] | rhs[0])>
	{
		return{
			lhs[0] | rhs[0],
			lhs[1] | rhs[1],
		};
	}

	// ---------
	// lhs ^ rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs ^ rhs[0])>
	{
		return{
			lhs ^ rhs[0],
			lhs ^ rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] ^ rhs)>
	{
		return{
			lhs[0] ^ rhs,
			lhs[1] ^ rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] ^ rhs[0])>
	{
		return{
			lhs[0] ^ rhs[0],
			lhs[1] ^ rhs[1],
		};
	}

	// ---------
	// lhs << rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs << rhs[0])>
	{
		return{
			lhs << rhs[0],
			lhs << rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] << rhs)>
	{
		return{
			lhs[0] << rhs,
			lhs[1] << rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] << rhs[0])>
	{
		return{
			lhs[0] << rhs[0],
			lhs[1] << rhs[1],
		};
	}

	// ---------
	// lhs >> rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const T& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs >> rhs[0])>
	{
		return{
			lhs >> rhs[0],
			lhs >> rhs[1],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec2<T>& lhs,
		const U& rhs)
		-> vec2<decltype(lhs[0] >> rhs)>
	{
		return{
			lhs[0] >> rhs,
			lhs[1] >> rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
		-> vec2<decltype(lhs[0] >> rhs[0])>
	{
		return{
			lhs[0] >> rhs[0],
			lhs[1] >> rhs[1],
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1];
	}

	// ----------
	// lhs != rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator!=(
		const vec2<T>& lhs,
		const vec2<U>& rhs)
	{
		return !(lhs == rhs);
	}

	// ----
	// math
	// ----
	namespace math
	{
		// --------
		// sincos()
		// --------
		template<typename T>
		inline void sincos(
			const vec2<T>& v,
			vec2<decltype(math::sin(v[0]))>& sin_result,
			vec2<decltype(math::cos(v[0]))>& cos_result)
		{
			math::sincos(v[0], sin_result[0], cos_result[0]);
			math::sincos(v[1], sin_result[1], cos_result[1]);
		}

		// -----
		// sin()
		// -----
		template<typename T>
		inline auto sin(const vec2<T>& v)
			-> vec2<decltype(math::sin(v[0]))>
		{
			return{
				math::sin(v[0]),
				math::sin(v[1]),
			};
		}

		// -----
		// cos()
		// -----
		template<typename T>
		inline auto cos(const vec2<T>& v)
			-> vec2<decltype(math::cos(v[0]))>
		{
			return{
				math::cos(v[0]),
				math::cos(v[1]),
			};
		}

		// -----
		// pow()
		// -----
		template<typename T, typename U>
		inline auto pow(
			const vec2<T>& base,
			const U& exponent)
			-> vec2<decltype(math::pow(base[0], exponent))>
		{
			return{
				math::pow(base[0], exponent),
				math::pow(base[1], exponent),
			};
		}

		template<typename T, typename U>
		inline auto pow(
			const vec2<T>& base,
			const vec2<U>& exponent)
			-> vec2<decltype(math::pow(base[0], exponent[0]))>
		{
			return{
				math::pow(base[0], exponent[0]),
				math::pow(base[1], exponent[1]),
			};
		}

		// -----
		// rcp()
		// -----
		template<typename T>
		inline auto rcp(const vec2<T>& v)
			-> vec2<decltype(math::rcp(v[0]))>
		{
			return{
				math::rcp(v[0]),
				math::rcp(v[1]),
			};
		}

		// ------
		// sqrt()
		// ------
		template<typename T>
		inline auto sqrt(const vec2<T>& v)
			-> vec2<decltype(math::sqrt(v[0]))>
		{
			return{
				math::sqrt(v[0]),
				math::sqrt(v[1]),
			};
		}

		// -------
		// rsqrt()
		// -------
		template<typename T>
		inline auto rsqrt(const vec2<T>& v)
			-> vec2<decltype(math::rsqrt(v[0]))>
		{
			return{
				math::rsqrt(v[0]),
				math::rsqrt(v[1]),
			};
		}

		// -----
		// min()
		// -----
		template<typename T>
		inline auto min(const vec2<T>& v1, const vec2<T>& v2)
			-> vec2<decltype(math::min(v1[0], v2[0]))>
		{
			return{
				math::min(v1[0], v2[0]),
				math::min(v1[1], v2[1]),
			};
		}

		// -----
		// max()
		// -----
		template<typename T>
		inline auto max(const vec2<T>& v1, const vec2<T>& v2)
			-> vec2<decltype(math::max(v1[0], v2[0]))>
		{
			return{
				math::max(v1[0], v2[0]),
				math::max(v1[1], v2[1]),
			};
		}

		// -----
		// abs()
		// -----
		template<typename T>
		inline auto abs(const vec2<T>& v)
			-> vec2<decltype(math::abs(v[0]))>
		{
			return{
				math::abs(v[0]),
				math::abs(v[1]),
			};
		}

		// -----
		// dot()
		// -----
		template<typename T, typename U>
		inline TUE_CONSTEXPR auto dot(
			const vec2<T>& lhs,
			const vec2<U>& rhs)
			-> decltype(lhs[0] * rhs[0])
		{
			return lhs[0] * rhs[0]
				+ lhs[1] * rhs[1];
		}

		// ---------
		// length2()
		// ---------
		template<typename T>
		inline auto length2(const vec2<T>& v)
			-> decltype(math::length2(v[0]))
		{
			return math::length2(v[0])
				+ math::length2(v[1]);
		}

		// --------
		// length()
		// --------
		template<typename T>
		inline auto length(const vec2<T>& v)
			-> decltype(math::sqrt(math::length2(v)))
		{
			return math::sqrt(math::length2(v));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline auto normalize(const vec2<T>& v)
			-> vec2<decltype(math::length(v))>
		{
			return vec2<decltype(math::length(v))>(v)
				/ math::length(v);
		}
	}
}

#undef TUE_CONSTEXPR
