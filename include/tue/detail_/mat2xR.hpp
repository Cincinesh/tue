//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
#include "../math.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// ---------
	// mat2xR<T>
	// ---------
	template<typename T, int R>
	class mat<T, 2, R>
	{
	private:
		struct { vec<T, R> columns[2]; } impl_;

	public:
		// -------------------
		// default constructor
		// -------------------
		mat() = default;

		// ------------------
		// scalar constructor
		// ------------------
		explicit constexpr mat(const T& s) :
			impl_({ {
				vec<T, R>(vec<T, 4>(s, T(0), T(0), T(0))),
				vec<T, R>(vec<T, 4>(T(0), s, T(0), T(0))),
			} }) {}

		// ------------------
		// column constructor
		// ------------------
		constexpr mat(
			const vec<T, R>& column0,
			const vec<T, R>& column1) :
			impl_({ {
				column0,
				column1,
			} }) {}

		// --------------------------------
		// extend and truncate constructors
		// --------------------------------
		template<int OtherR>
		explicit constexpr mat(const mat<T, 2, OtherR>& other) :
			impl_({ {
				vec<T, R>::extend_(other[0], T(0), T(0)),
				vec<T, R>::extend_(other[1], T(0), T(0)),
			} }) {}

		template<int OtherR>
		explicit constexpr mat(const mat<T, 3, OtherR>& other) :
			impl_({ {
				vec<T, R>::extend_(other[0], T(0), T(0)),
				vec<T, R>::extend_(other[1], T(0), T(0)),
			} }) {}

		template<int OtherR>
		explicit constexpr mat(const mat<T, 4, OtherR>& other) :
			impl_({ {
				vec<T, R>::extend_(other[0], T(0), T(0)),
				vec<T, R>::extend_(other[1], T(0), T(0)),
			} }) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr mat(const mat<U, 2, R>& other) :
			impl_({ {
				vec<T, R>(other[0]),
				vec<T, R>(other[1]),
			} }) {}

		// ----------------------------
		// implicit conversion operator
		// ----------------------------
		template<typename U>
		constexpr operator mat<U, 2, R>() const
		{
			return{
				impl_.columns[0],
				impl_.columns[1],
			};
		}

		// ---------------
		// factory methods
		// ---------------
		static constexpr mat identity() { return mat(T(1)); }
		static constexpr mat zero() { return mat(T(0)); }

		// --------
		// column()
		// --------
		template<typename I>
		constexpr vec<T, R> column(const I& i) const
		{
			return impl_.columns[i];
		}

		template<typename I>
		void set_column(
			const I& i,
			const vec<T, R>& column)
		{
			impl_.columns[i] = column;
		}

		// --------
		// row()
		// --------
		template<typename J>
		constexpr vec<T, 2> row(const J& j) const
		{
			return{
				impl_.columns[0][j],
				impl_.columns[1][j],
			};
		}

		template<typename J>
		void set_row(
			const J& j,
			const vec<T, 2>& row)
		{
			impl_.columns[0][j] = row[0];
			impl_.columns[1][j] = row[1];
		}

		// ----
		// m[i]
		// ----
		template<typename I>
		vec<T, R>& operator[](const I& i)
		{
			return impl_.columns[i];
		}

		template<typename I>
		constexpr const vec<T, R>& operator[](const I& i) const
		{
			return impl_.columns[i];
		}

		// ---
		// ++m
		// ---
		mat& operator++()
		{
			++impl_.columns[0];
			++impl_.columns[1];
			return *this;
		}

		// ---
		// --m
		// ---
		mat& operator--()
		{
			--impl_.columns[0];
			--impl_.columns[1];
			return *this;
		}

		// ---
		// m++
		// ---
		mat operator++(int)
		{
			const auto tmp = *this;
			++*this;
			return tmp;
		}

		// ---
		// m--
		// ---
		mat operator--(int)
		{
			const auto tmp = *this;
			--*this;
			return tmp;
		}

		// ----------
		// m += other
		// ----------
		template<typename U>
		mat& operator+=(const U& other)
		{
			impl_.columns[0] += other;
			impl_.columns[1] += other;
			return *this;
		}

		template<typename U>
		mat& operator+=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] += other[0];
			impl_.columns[1] += other[1];
			return *this;
		}

		// ----------
		// m -= other
		// ----------
		template<typename U>
		mat& operator-=(const U& other)
		{
			impl_.columns[0] -= other;
			impl_.columns[1] -= other;
			return *this;
		}

		template<typename U>
		mat& operator-=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] -= other[0];
			impl_.columns[1] -= other[1];
			return *this;
		}

		// ----------
		// m *= other
		// ----------
		template<typename U>
		mat& operator*=(const U& other)
		{
			impl_.columns[0] *= other;
			impl_.columns[1] *= other;
			return *this;
		}

		template<typename U, int OtherC, int OtherR>
		mat& operator*=(const mat<U, OtherC, OtherR>& other)
		{
			return *this = *this * other;
		}

		// ----------
		// m /= other
		// ----------
		template<typename U>
		mat& operator/=(const U& other)
		{
			impl_.columns[0] /= other;
			impl_.columns[1] /= other;
			return *this;
		}

		template<typename U>
		mat& operator/=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] /= other[0];
			impl_.columns[1] /= other[1];
			return *this;
		}

		// ----------
		// m %= other
		// ----------
		template<typename U>
		mat& operator%=(const U& other)
		{
			impl_.columns[0] %= other;
			impl_.columns[1] %= other;
			return *this;
		}

		template<typename U>
		mat& operator%=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] %= other[0];
			impl_.columns[1] %= other[1];
			return *this;
		}

		// ----------
		// m &= other
		// ----------
		template<typename U>
		mat& operator&=(const U& other)
		{
			impl_.columns[0] &= other;
			impl_.columns[1] &= other;
			return *this;
		}

		template<typename U>
		mat& operator&=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] &= other[0];
			impl_.columns[1] &= other[1];
			return *this;
		}

		// ----------
		// m |= other
		// ----------
		template<typename U>
		mat& operator|=(const U& other)
		{
			impl_.columns[0] |= other;
			impl_.columns[1] |= other;
			return *this;
		}

		template<typename U>
		mat& operator|=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] |= other[0];
			impl_.columns[1] |= other[1];
			return *this;
		}

		// ----------
		// m ^= other
		// ----------
		template<typename U>
		mat& operator^=(const U& other)
		{
			impl_.columns[0] ^= other;
			impl_.columns[1] ^= other;
			return *this;
		}

		template<typename U>
		mat& operator^=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] ^= other[0];
			impl_.columns[1] ^= other[1];
			return *this;
		}

		// -----------
		// m <<= other
		// -----------
		template<typename U>
		mat& operator<<=(const U& other)
		{
			impl_.columns[0] <<= other;
			impl_.columns[1] <<= other;
			return *this;
		}

		template<typename U>
		mat& operator<<=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] <<= other[0];
			impl_.columns[1] <<= other[1];
			return *this;
		}

		// -----------
		// m >>= other
		// -----------
		template<typename U>
		mat& operator>>=(const U& other)
		{
			impl_.columns[0] >>= other;
			impl_.columns[1] >>= other;
			return *this;
		}

		template<typename U>
		mat& operator>>=(const mat<U, 2, R>& other)
		{
			impl_.columns[0] >>= other[0];
			impl_.columns[1] >>= other[1];
			return *this;
		}
	};

	// --
	// +m
	// --
	template<typename T, int R>
	inline TUE_CONSTEXPR auto operator+(const mat<T, 2, R>& m)
	{
		return mat<decltype(+m[0][0]), 2, R>(+m[0], +m[1]);
	}

	// --
	// -m
	// --
	template<typename T, int R>
	inline TUE_CONSTEXPR auto operator-(const mat<T, 2, R>& m)
	{
		return mat<decltype(-m[0][0]), 2, R>(-m[0], -m[1]);
	}

	// --
	// ~m
	// --
	template<typename T, int R>
	inline TUE_CONSTEXPR auto operator~(const mat<T, 2, R>& m)
	{
		return mat<decltype(~m[0][0]), 2, R>(~m[0], ~m[1]);
	}

	// ---------
	// lhs + rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator+(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs + rhs[0][0]), 2, R>{
			lhs + rhs[0],
			lhs + rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator+(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] + rhs), 2, R>{
			lhs[0] + rhs,
			lhs[1] + rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator+(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] + rhs[0][0]), 2, R>{
			lhs[0] + rhs[0],
			lhs[1] + rhs[1],
		};
	}

	// ---------
	// lhs - rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator-(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs - rhs[0][0]), 2, R>{
			lhs - rhs[0],
			lhs - rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator-(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] - rhs), 2, R>{
			lhs[0] - rhs,
			lhs[1] - rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator-(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] - rhs[0][0]), 2, R>{
			lhs[0] - rhs[0],
			lhs[1] - rhs[1],
		};
	}

	// ---------
	// lhs * rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator*(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs * rhs[0][0]), 2, R>{
			lhs * rhs[0],
			lhs * rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator*(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] * rhs), 2, R>{
			lhs[0] * rhs,
			lhs[1] * rhs,
		};
	}

	// ---------
	// lhs / rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator/(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs / rhs[0][0]), 2, R>{
			lhs / rhs[0],
			lhs / rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator/(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] / rhs), 2, R>{
			lhs[0] / rhs,
			lhs[1] / rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator/(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] / rhs[0][0]), 2, R>{
			lhs[0] / rhs[0],
			lhs[1] / rhs[1],
		};
	}

	// ---------
	// lhs % rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator%(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs % rhs[0][0]), 2, R>{
			lhs % rhs[0],
			lhs % rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator%(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] % rhs), 2, R>{
			lhs[0] % rhs,
			lhs[1] % rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator%(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] % rhs[0][0]), 2, R>{
			lhs[0] % rhs[0],
			lhs[1] % rhs[1],
		};
	}

	// ---------
	// lhs & rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator&(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs & rhs[0][0]), 2, R>{
			lhs & rhs[0],
			lhs & rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator&(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] & rhs), 2, R>{
			lhs[0] & rhs,
			lhs[1] & rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator&(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] & rhs[0][0]), 2, R>{
			lhs[0] & rhs[0],
			lhs[1] & rhs[1],
		};
	}

	// ---------
	// lhs | rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator|(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs | rhs[0][0]), 2, R>{
			lhs | rhs[0],
			lhs | rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator|(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] | rhs), 2, R>{
			lhs[0] | rhs,
			lhs[1] | rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator|(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] | rhs[0][0]), 2, R>{
			lhs[0] | rhs[0],
			lhs[1] | rhs[1],
		};
	}

	// ---------
	// lhs ^ rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator^(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs ^ rhs[0][0]), 2, R>{
			lhs ^ rhs[0],
			lhs ^ rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator^(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] ^ rhs), 2, R>{
			lhs[0] ^ rhs,
			lhs[1] ^ rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator^(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] ^ rhs[0][0]), 2, R>{
			lhs[0] ^ rhs[0],
			lhs[1] ^ rhs[1],
		};
	}

	// ---------
	// lhs << rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator<<(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs << rhs[0][0]), 2, R>{
			lhs << rhs[0],
			lhs << rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator<<(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] << rhs), 2, R>{
			lhs[0] << rhs,
			lhs[1] << rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator<<(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] << rhs[0][0]), 2, R>{
			lhs[0] << rhs[0],
			lhs[1] << rhs[1],
		};
	}

	// ---------
	// lhs >> rhs
	// ---------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator>>(
		const T& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs >> rhs[0][0]), 2, R>{
			lhs >> rhs[0],
			lhs >> rhs[1],
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator>>(
		const mat<T, 2, R>& lhs,
		const U& rhs)
	{
		return mat<decltype(lhs[0][0] >> rhs), 2, R>{
			lhs[0] >> rhs,
			lhs[1] >> rhs,
		};
	}

	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR auto operator>>(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return mat<decltype(lhs[0][0] >> rhs[0][0]), 2, R>{
			lhs[0] >> rhs[0],
			lhs[1] >> rhs[1],
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR bool operator==(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1];
	}

	// ----------
	// lhs != rhs
	// ----------
	template<typename T, typename U, int R>
	inline TUE_CONSTEXPR bool operator!=(
		const mat<T, 2, R>& lhs,
		const mat<U, 2, R>& rhs)
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
		template<typename T, int R>
		inline auto sin(const mat<T, 2, R>& m)
		{
			return  mat<decltype(math::sin(m[0][0])), 2, R>{
				math::sin(m[0]),
				math::sin(m[1]),
			};
		}

		// -----
		// cos()
		// -----
		template<typename T, int R>
		inline auto cos(const mat<T, 2, R>& m)
		{
			return mat<decltype(math::cos(m[0][0])), 2, R>{
				math::cos(m[0]),
				math::cos(m[1]),
			};
		}

		// --------
		// sincos()
		// --------
		template<typename T, int R>
		inline void sincos(
			const mat<T, 2, R>& m,
			decltype(math::sin(m))& sin_result,
			decltype(math::cos(m))& cos_result)
		{
			math::sincos(m[0], sin_result[0], cos_result[0]);
			math::sincos(m[1], sin_result[1], cos_result[1]);
		}

		// -----
		// pow()
		// -----
		template<typename T, typename U, int R>
		inline auto pow(
			const mat<T, 2, R>& base,
			const U& exponent)
		{
			return mat<decltype(math::pow(base[0][0], exponent)), 2, R>{
				math::pow(base[0], exponent),
				math::pow(base[1], exponent),
			};
		}

		template<typename T, typename U, int R>
		inline auto pow(
			const mat<T, 2, R>& base,
			const mat<U, 2, R>& exponent)
		{
			return mat<decltype(math::pow(base[0][0], exponent[0][0])), 2, R>{
				math::pow(base[0], exponent[0]),
				math::pow(base[1], exponent[1]),
			};
		}

		// -------
		// recip()
		// -------
		template<typename T, int R>
		inline auto recip(const mat<T, 2, R>& m)
		{
			return mat<decltype(math::recip(m[0][0])), 2, R>{
				math::recip(m[0]),
				math::recip(m[1]),
			};
		}

		// ------
		// sqrt()
		// ------
		template<typename T, int R>
		inline auto sqrt(const mat<T, 2, R>& m)
		{
			return mat<decltype(math::sqrt(m[0][0])), 2, R>{
				math::sqrt(m[0]),
				math::sqrt(m[1]),
			};
		}

		// -------
		// rsqrt()
		// -------
		template<typename T, int R>
		inline auto rsqrt(const mat<T, 2, R>& m)
		{
			return mat<decltype(math::rsqrt(m[0][0])), 2, R>{
				math::rsqrt(m[0]),
				math::rsqrt(m[1]),
			};
		}

		// -----
		// min()
		// -----
		template<typename T, int R>
		inline auto min(
			const mat<T, 2, R>& m1,
			const mat<T, 2, R>& m2)
		{
			return mat<decltype(math::min(m1[0][0], m2[0][0])), 2, R>{
				math::min(m1[0], m2[0]),
				math::min(m1[1], m2[1]),
			};
		}

		// -----
		// max()
		// -----
		template<typename T, int R>
		inline auto max(
			const mat<T, 2, R>& m1,
			const mat<T, 2, R>& m2)
		{
			return mat<decltype(math::max(m1[0][0], m2[0][0])), 2, R>{
				math::max(m1[0], m2[0]),
				math::max(m1[1], m2[1]),
			};
		}

		// -----
		// abs()
		// -----
		template<typename T, int R>
		inline auto abs(const mat<T, 2, R>& m)
		{
			return mat<decltype(math::abs(m[0][0])), 2, R>{
				math::abs(m[0]),
				math::abs(m[1]),
			};
		}

		// ----------
		// compmult()
		// ----------
		template<typename T, typename U, int R>
		inline TUE_CONSTEXPR auto compmult(
			const mat<T, 2, R>& lhs,
			const mat<U, 2, R>& rhs)
		{
			return mat<decltype(lhs[0][0] * rhs[0][0]), 2, R>{
				lhs[0] * rhs[0],
				lhs[1] * rhs[1],
			};
		}

		// -----------
		// transpose()
		// -----------
		template<typename T, int R>
		inline TUE_CONSTEXPR mat<T, 2, R> transpose(
			const mat<T, R, 2>& m)
		{
			return{
				m.row(0),
				m.row(1),
			};
		}
	}
}

#undef TUE_CONSTEXPR
#include "matmult.hpp"
