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
	// vec3<T>
	// -------
	template<typename T>
	class vec<T, 3>
	{
	private:
		struct { T data[3]; } impl_;

	public:
		// ------------
		// constructors
		// ------------
		vec() = default;

		constexpr vec(const T& x, const T& y, const T& z) :
			impl_({ { x, y, z } }) {}

		explicit constexpr vec(const T& s) :
			impl_({ { s, s, s } }) {}

		explicit constexpr vec(const vec2<T>& xy, const T& z) :
			impl_({ { xy[0], xy[1], z } }) {}

		explicit constexpr vec(const vec4<T>& other) :
			impl_({ { other[0], other[1], other[2] } }) {}

		template<typename U>
		explicit constexpr vec(const vec3<U>& other) :
			impl_({ {
				static_cast<T>(other[0]),
				static_cast<T>(other[1]),
				static_cast<T>(other[2]),
			} }) {}

		// ---------------
		// factory methods
		// ---------------
		static constexpr vec zero() { return{ T(0), T(0), T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1), T(0) }; }
		static constexpr vec z_axis() { return{ T(0), T(0), T(1) }; }

		// --------------------
		// conversion operators
		// --------------------
		template<typename U>
		constexpr operator vec3<U>() const
		{
			return{
				impl_.data[0],
				impl_.data[1],
				impl_.data[2],
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

		constexpr vec2<T> xy() const { return vec2<T>(*this); }
		void set_xy(const T& x, const T& y)
		{
			impl_.data[0] = x;
			impl_.data[1] = y;
		}
		void set_xy(const vec2<T>& xy) { set_xy(xy[0], xy[1]); }

		// ---
		// ++v
		// ---
		vec& operator++()
		{
			++impl_.data[0];
			++impl_.data[1];
			++impl_.data[2];
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
			return *this;
		}

		template<typename U>
		vec& operator+=(const vec3<U>& other)
		{
			impl_.data[0] += other[0];
			impl_.data[1] += other[1];
			impl_.data[2] += other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator-=(const vec3<U>& other)
		{
			impl_.data[0] -= other[0];
			impl_.data[1] -= other[1];
			impl_.data[2] -= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator*=(const vec3<U>& other)
		{
			impl_.data[0] *= other[0];
			impl_.data[1] *= other[1];
			impl_.data[2] *= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator/=(const vec3<U>& other)
		{
			impl_.data[0] /= other[0];
			impl_.data[1] /= other[1];
			impl_.data[2] /= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator%=(const vec3<U>& other)
		{
			impl_.data[0] %= other[0];
			impl_.data[1] %= other[1];
			impl_.data[2] %= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator&=(const vec3<U>& other)
		{
			impl_.data[0] &= other[0];
			impl_.data[1] &= other[1];
			impl_.data[2] &= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator|=(const vec3<U>& other)
		{
			impl_.data[0] |= other[0];
			impl_.data[1] |= other[1];
			impl_.data[2] |= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator^=(const vec3<U>& other)
		{
			impl_.data[0] ^= other[0];
			impl_.data[1] ^= other[1];
			impl_.data[2] ^= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator<<=(const vec3<U>& other)
		{
			impl_.data[0] <<= other[0];
			impl_.data[1] <<= other[1];
			impl_.data[2] <<= other[2];
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
			return *this;
		}

		template<typename U>
		vec& operator>>=(const vec3<U>& other)
		{
			impl_.data[0] >>= other[0];
			impl_.data[1] >>= other[1];
			impl_.data[2] >>= other[2];
			return *this;
		}
	};

	// --
	// +v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator+(const vec3<T>& v)
		-> vec3<decltype(+v[0])>
	{
		return{ +v[0], +v[1], +v[2] };
	}

	// --
	// -v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator-(const vec3<T>& v)
		-> vec3<decltype(+v[0])>
	{
		return{ -v[0], -v[1], -v[2] };
	}

	// --
	// ~v
	// --
	template<typename T>
	inline TUE_CONSTEXPR auto operator~(const vec3<T>& v)
		-> vec3<decltype(~v[0])>
	{
		return{ ~v[0], ~v[1], ~v[2] };
	}

	// ---------
	// lhs + rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs + rhs[0])>
	{
		return{
			lhs + rhs[0],
			lhs + rhs[1],
			lhs + rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] + rhs)>
	{
		return{
			lhs[0] + rhs,
			lhs[1] + rhs,
			lhs[2] + rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator+(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] + rhs[0])>
	{
		return{
			lhs[0] + rhs[0],
			lhs[1] + rhs[1],
			lhs[2] + rhs[2],
		};
	}

	// ---------
	// lhs - rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs - rhs[0])>
	{
		return{
			lhs - rhs[0],
			lhs - rhs[1],
			lhs - rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] - rhs)>
	{
		return{
			lhs[0] - rhs,
			lhs[1] - rhs,
			lhs[2] - rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator-(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] - rhs[0])>
	{
		return{
			lhs[0] - rhs[0],
			lhs[1] - rhs[1],
			lhs[2] - rhs[2],
		};
	}

	// ---------
	// lhs * rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs * rhs[0])>
	{
		return{
			lhs * rhs[0],
			lhs * rhs[1],
			lhs * rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] * rhs)>
	{
		return{
			lhs[0] * rhs,
			lhs[1] * rhs,
			lhs[2] * rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] * rhs[0])>
	{
		return{
			lhs[0] * rhs[0],
			lhs[1] * rhs[1],
			lhs[2] * rhs[2],
		};
	}

	// ---------
	// lhs / rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs / rhs[0])>
	{
		return{
			lhs / rhs[0],
			lhs / rhs[1],
			lhs / rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] / rhs)>
	{
		return{
			lhs[0] / rhs,
			lhs[1] / rhs,
			lhs[2] / rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator/(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] / rhs[0])>
	{
		return{
			lhs[0] / rhs[0],
			lhs[1] / rhs[1],
			lhs[2] / rhs[2],
		};
	}

	// ---------
	// lhs % rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs % rhs[0])>
	{
		return{
			lhs % rhs[0],
			lhs % rhs[1],
			lhs % rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] % rhs)>
	{
		return{
			lhs[0] % rhs,
			lhs[1] % rhs,
			lhs[2] % rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator%(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] % rhs[0])>
	{
		return{
			lhs[0] % rhs[0],
			lhs[1] % rhs[1],
			lhs[2] % rhs[2],
		};
	}

	// ---------
	// lhs & rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs & rhs[0])>
	{
		return{
			lhs & rhs[0],
			lhs & rhs[1],
			lhs & rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] & rhs)>
	{
		return{
			lhs[0] & rhs,
			lhs[1] & rhs,
			lhs[2] & rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator&(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] & rhs[0])>
	{
		return{
			lhs[0] & rhs[0],
			lhs[1] & rhs[1],
			lhs[2] & rhs[2],
		};
	}

	// ---------
	// lhs | rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs | rhs[0])>
	{
		return{
			lhs | rhs[0],
			lhs | rhs[1],
			lhs | rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] | rhs)>
	{
		return{
			lhs[0] | rhs,
			lhs[1] | rhs,
			lhs[2] | rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator|(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] | rhs[0])>
	{
		return{
			lhs[0] | rhs[0],
			lhs[1] | rhs[1],
			lhs[2] | rhs[2],
		};
	}

	// ---------
	// lhs ^ rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs ^ rhs[0])>
	{
		return{
			lhs ^ rhs[0],
			lhs ^ rhs[1],
			lhs ^ rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] ^ rhs)>
	{
		return{
			lhs[0] ^ rhs,
			lhs[1] ^ rhs,
			lhs[2] ^ rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator^(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] ^ rhs[0])>
	{
		return{
			lhs[0] ^ rhs[0],
			lhs[1] ^ rhs[1],
			lhs[2] ^ rhs[2],
		};
	}

	// ---------
	// lhs << rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs << rhs[0])>
	{
		return{
			lhs << rhs[0],
			lhs << rhs[1],
			lhs << rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] << rhs)>
	{
		return{
			lhs[0] << rhs,
			lhs[1] << rhs,
			lhs[2] << rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator<<(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] << rhs[0])>
	{
		return{
			lhs[0] << rhs[0],
			lhs[1] << rhs[1],
			lhs[2] << rhs[2],
		};
	}

	// ---------
	// lhs >> rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const T& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs >> rhs[0])>
	{
		return{
			lhs >> rhs[0],
			lhs >> rhs[1],
			lhs >> rhs[2],
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec3<T>& lhs,
		const U& rhs)
		-> vec3<decltype(lhs[0] >> rhs)>
	{
		return{
			lhs[0] >> rhs,
			lhs[1] >> rhs,
			lhs[2] >> rhs,
		};
	}

	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator>>(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
		-> vec3<decltype(lhs[0] >> rhs[0])>
	{
		return{
			lhs[0] >> rhs[0],
			lhs[1] >> rhs[1],
			lhs[2] >> rhs[2],
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
	{
		return lhs[0] == rhs[0]
			&& lhs[1] == rhs[1]
			&& lhs[2] == rhs[2];
	}

	// ----------
	// lhs != rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator!=(
		const vec3<T>& lhs,
		const vec3<U>& rhs)
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
			const vec3<T>& v,
			vec3<decltype(math::sin(v[0]))>& sin_result,
			vec3<decltype(math::cos(v[0]))>& cos_result)
		{
			math::sincos(v[0], sin_result[0], cos_result[0]);
			math::sincos(v[1], sin_result[1], cos_result[1]);
			math::sincos(v[2], sin_result[2], cos_result[2]);
		}

		// -----
		// sin()
		// -----
		template<typename T>
		inline auto sin(const vec3<T>& v)
			-> vec3<decltype(math::sin(v[0]))>
		{
			return{
				math::sin(v[0]),
				math::sin(v[1]),
				math::sin(v[2]),
			};
		}

		// -----
		// cos()
		// -----
		template<typename T>
		inline auto cos(const vec3<T>& v)
			-> vec3<decltype(math::cos(v[0]))>
		{
			return{
				math::cos(v[0]),
				math::cos(v[1]),
				math::cos(v[2]),
			};
		}

		// -----
		// pow()
		// -----
		template<typename T, typename U>
		inline auto pow(
			const vec3<T>& base,
			const U& exponent)
			-> vec3<decltype(math::pow(base[0], exponent))>
		{
			return{
				math::pow(base[0], exponent),
				math::pow(base[1], exponent),
				math::pow(base[2], exponent),
			};
		}

		template<typename T, typename U>
		inline auto pow(
			const vec3<T>& base,
			const vec3<U>& exponent)
			-> vec3<decltype(math::pow(base[0], exponent[0]))>
		{
			return{
				math::pow(base[0], exponent[0]),
				math::pow(base[1], exponent[1]),
				math::pow(base[2], exponent[2]),
			};
		}

		// -----
		// rcp()
		// -----
		template<typename T>
		inline auto rcp(const vec3<T>& v)
			-> vec3<decltype(math::rcp(v[0]))>
		{
			return{
				math::rcp(v[0]),
				math::rcp(v[1]),
				math::rcp(v[2]),
			};
		}

		// ------
		// sqrt()
		// ------
		template<typename T>
		inline auto sqrt(const vec3<T>& v)
			-> vec3<decltype(math::sqrt(v[0]))>
		{
			return{
				math::sqrt(v[0]),
				math::sqrt(v[1]),
				math::sqrt(v[2]),
			};
		}

		// -------
		// rsqrt()
		// -------
		template<typename T>
		inline auto rsqrt(const vec3<T>& v)
			-> vec3<decltype(math::rsqrt(v[0]))>
		{
			return{
				math::rsqrt(v[0]),
				math::rsqrt(v[1]),
				math::rsqrt(v[2]),
			};
		}

		// -----
		// min()
		// -----
		template<typename T>
		inline auto min(const vec3<T>& v1, const vec3<T>& v2)
			-> vec3<decltype(math::min(v1[0], v2[0]))>
		{
			return{
				math::min(v1[0], v2[0]),
				math::min(v1[1], v2[1]),
				math::min(v1[2], v2[2]),
			};
		}

		// -----
		// max()
		// -----
		template<typename T>
		inline auto max(const vec3<T>& v1, const vec3<T>& v2)
			-> vec3<decltype(math::max(v1[0], v2[0]))>
		{
			return{
				math::max(v1[0], v2[0]),
				math::max(v1[1], v2[1]),
				math::max(v1[2], v2[2]),
			};
		}

		// -----
		// abs()
		// -----
		template<typename T>
		inline auto abs(const vec3<T>& v)
			-> vec3<decltype(math::abs(v[0]))>
		{
			return{
				math::abs(v[0]),
				math::abs(v[1]),
				math::abs(v[2]),
			};
		}

		// -----
		// dot()
		// -----
		template<typename T, typename U>
		inline TUE_CONSTEXPR auto dot(
			const vec3<T>& lhs,
			const vec3<U>& rhs)
			-> decltype(lhs[0] * rhs[0])
		{
			return lhs[0] * rhs[0]
				+ lhs[1] * rhs[1]
				+ lhs[2] * rhs[2];
		}

		// -------
		// cross()
		// -------
		template<typename T, typename U>
		inline TUE_CONSTEXPR auto cross(
			const vec3<T>& lhs,
			const vec3<U>& rhs)
			-> vec3<decltype(lhs[0] * rhs[0])>
		{
			return{
				lhs[1] * rhs[2] - lhs[2] * rhs[1],
				lhs[2] * rhs[0] - lhs[0] * rhs[2],
				lhs[0] * rhs[1] - lhs[1] * rhs[0],
			};
		}

		// ---------
		// length2()
		// ---------
		template<typename T>
		inline auto length2(const vec3<T>& v)
			-> decltype(math::length2(v[0]))
		{
			return math::length2(v[0])
				+ math::length2(v[1])
				+ math::length2(v[2]);
		}

		// --------
		// length()
		// --------
		template<typename T>
		inline auto length(const vec3<T>& v)
			-> decltype(math::sqrt(math::length2(v)))
		{
			return math::sqrt(math::length2(v));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline auto normalize(const vec3<T>& v)
			-> vec3<decltype(math::length(v))>
		{
			return vec3<decltype(math::length(v))>(v)
				/ math::length(v);
		}
	}
}

#undef TUE_CONSTEXPR
