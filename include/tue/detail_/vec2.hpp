//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

#include "../vec.hpp"

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
		// ------------
		// constructors
		// ------------
		vec() = default;

		constexpr vec(const T& x, const T& y) :
			impl_({ { x, y } }) {}

		explicit constexpr vec(const T& s) :
			impl_({ { s, s } }) {}

		template<typename U>
		explicit constexpr vec(const vec2<U>& other) :
			impl_({ {
				static_cast<T>(other[0]),
				static_cast<T>(other[1]),
			} }) {}

		// ---------------
		// factory methods
		// ---------------
		static constexpr vec zero() { return{ T(0), T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1) }; }

		// --------------------
		// conversion operators
		// --------------------
		template<typename U>
		constexpr operator vec2<U>() const
		{
			return{
				impl_.data[0],
				impl_.data[1],
			};
		}

		// ----------
		// properties
		// ----------
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

		constexpr T x() const { return impl_.data[0]; }
		void set_x(const T& x) { impl_.data[0] = x; }

		constexpr T y() const { return impl_.data[1]; }
		void set_y(const T& y) { impl_.data[1] = y; }

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
}

#undef TUE_CONSTEXPR
