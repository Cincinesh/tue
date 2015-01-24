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
	// vec4<T>
	// -------
	template<typename T>
	class vec<T, 4>
	{
	private:
		struct { T data[4]; } impl_;

	public:
		// ------------
		// constructors
		// ------------
		vec() = default;

		constexpr vec(const T& x, const T& y, const T& z, const T& w) :
			impl_({ {x, y, z, w} }) {}

		explicit constexpr vec(const T& s) :
			impl_({ {s, s, s, s} }) {}

		template<typename U>
		explicit constexpr vec(const vec4<U>& other) :
			impl_({ {
				static_cast<T>(other[0]),
				static_cast<T>(other[1]),
				static_cast<T>(other[2]),
				static_cast<T>(other[3]),
			} }) {}

		// ---------------
		// factory methods
		// ---------------
		static constexpr vec zero() { return{ T(0), T(0), T(0), T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0), T(0), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1), T(0), T(0) }; }
		static constexpr vec z_axis() { return{ T(0), T(0), T(1), T(0) }; }
		static constexpr vec w_axis() { return{ T(0), T(0), T(0), T(1) }; }

		// --------------------
		// conversion functions
		// --------------------
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

		constexpr T z() const { return impl_.data[2]; }
		void set_z(const T& z) { impl_.data[2] = z; }

		constexpr T w() const { return impl_.data[3]; }
		void set_w(const T& w) { impl_.data[3] = w; }

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
	};

	// --
	// +v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator+(const vec4<T>& v)
	-> vec4<decltype(+v[0])>
	{
		return{ +v[0], +v[1], +v[2], +v[3] };
	}

	// --
	// -v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator-(const vec4<T>& v)
	-> vec4<decltype(+v[0])>
	{
		return{ -v[0], -v[1], -v[2], -v[3] };
	}

	// ---------
	// lhs + rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const T& lhs,
		const vec4<U>& rhs)
	-> vec4<decltype(lhs + rhs[0])>
	{
		return{
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
	-> vec4<decltype(lhs[0] + rhs)>
	{
		return{
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
	-> vec4<decltype(lhs[0] + rhs[0])>
	{
		return{
			lhs[0] + rhs[0],
			lhs[1] + rhs[1],
			lhs[2] + rhs[2],
			lhs[3] + rhs[3],
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(const vec4<T>& lhs, const vec4<U>& rhs)
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
	inline TUE_CONSTEXPR bool operator!=(const vec4<T>& lhs, const vec4<U>& rhs)
	{
		return !(lhs == rhs);
	}
}

#undef TUE_CONSTEXPR
