//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "vec.hpp"

namespace tue
{
	template<typename T>
	class vec<T, 4>
	{
	private:
		struct { T data[4]; } impl_;

	public:
		vec() = default;

		constexpr vec(T x, T y, T z, T w) :
			impl_({ {x, y, z, w} }) {}

		explicit constexpr vec(T s) :
			impl_({ {s, s, s, s} }) {}

		template<typename U>
		explicit constexpr vec(const vec4<U>& other) :
			impl_({ {
				static_cast<T>(other[0]),
				static_cast<T>(other[1]),
				static_cast<T>(other[2]),
				static_cast<T>(other[3]),
			} }) {}

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

		static constexpr vec zero() { return{ T(0) }; }
		static constexpr vec x_axis() { return{ T(1), T(0), T(0), T(0) }; }
		static constexpr vec y_axis() { return{ T(0), T(1), T(0), T(0) }; }
		static constexpr vec z_axis() { return{ T(0), T(0), T(1), T(0) }; }
		static constexpr vec w_axis() { return{ T(0), T(0), T(0), T(1) }; }

		template<typename I>
		constexpr const T& operator[](I i) const { return impl_.data[i]; }

		template<typename I>
		T& operator[](I i) { return impl_.data[i]; }

		constexpr T x() const { return impl_.data[0]; }
		void set_x(T x) { impl_.data[0] = x; }

		constexpr T y() const { return impl_.data[1]; }
		void set_y(T y) { impl_.data[1] = y; }

		constexpr T z() const { return impl_.data[2]; }
		void set_z(T z) { impl_.data[2] = z; }

		constexpr T w() const { return impl_.data[3]; }
		void set_w(T w) { impl_.data[3] = w; }

		vec& operator++()
		{
			++impl_.data[0];
			++impl_.data[1];
			++impl_.data[2];
			++impl_.data[3];
			return *this;
		}

		vec& operator--()
		{
			--impl_.data[0];
			--impl_.data[1];
			--impl_.data[2];
			--impl_.data[3];
			return *this;
		}

		vec operator++(int)
		{
			const auto tmp = *this;
			++*this;
			return tmp;
		}

		vec operator--(int)
		{
			const auto tmp = *this;
			--*this;
			return tmp;
		}

		template<typename U>
		vec& operator+=(U other)
		{
			impl_.data[0] += other;
			impl_.data[1] += other;
			impl_.data[2] += other;
			impl_.data[3] += other;
			return *this;
		}

		template<typename U>
		vec& operator+=(vec4<U> other)
		{
			impl_.data[0] += other[0];
			impl_.data[1] += other[1];
			impl_.data[2] += other[2];
			impl_.data[3] += other[3];
			return *this;
		}

		template<typename U>
		vec& operator-=(U other)
		{
			impl_.data[0] -= other;
			impl_.data[1] -= other;
			impl_.data[2] -= other;
			impl_.data[3] -= other;
			return *this;
		}

		template<typename U>
		vec& operator-=(vec4<U> other)
		{
			impl_.data[0] -= other[0];
			impl_.data[1] -= other[1];
			impl_.data[2] -= other[2];
			impl_.data[3] -= other[3];
			return *this;
		}

		template<typename U>
		vec& operator*=(U other)
		{
			impl_.data[0] *= other;
			impl_.data[1] *= other;
			impl_.data[2] *= other;
			impl_.data[3] *= other;
			return *this;
		}

		template<typename U>
		vec& operator*=(vec4<U> other)
		{
			impl_.data[0] *= other[0];
			impl_.data[1] *= other[1];
			impl_.data[2] *= other[2];
			impl_.data[3] *= other[3];
			return *this;
		}

		template<typename U>
		vec& operator/=(U other)
		{
			impl_.data[0] /= other;
			impl_.data[1] /= other;
			impl_.data[2] /= other;
			impl_.data[3] /= other;
			return *this;
		}

		template<typename U>
		vec& operator/=(vec4<U> other)
		{
			impl_.data[0] /= other[0];
			impl_.data[1] /= other[1];
			impl_.data[2] /= other[2];
			impl_.data[3] /= other[3];
			return *this;
		}

		template<typename U>
		vec& operator%=(U other)
		{
			impl_.data[0] %= other;
			impl_.data[1] %= other;
			impl_.data[2] %= other;
			impl_.data[3] %= other;
			return *this;
		}

		template<typename U>
		vec& operator%=(vec4<U> other)
		{
			impl_.data[0] %= other[0];
			impl_.data[1] %= other[1];
			impl_.data[2] %= other[2];
			impl_.data[3] %= other[3];
			return *this;
		}

		template<typename U>
		vec& operator&=(U other)
		{
			impl_.data[0] &= other;
			impl_.data[1] &= other;
			impl_.data[2] &= other;
			impl_.data[3] &= other;
			return *this;
		}

		template<typename U>
		vec& operator&=(vec4<U> other)
		{
			impl_.data[0] &= other[0];
			impl_.data[1] &= other[1];
			impl_.data[2] &= other[2];
			impl_.data[3] &= other[3];
			return *this;
		}

		template<typename U>
		vec& operator|=(U other)
		{
			impl_.data[0] |= other;
			impl_.data[1] |= other;
			impl_.data[2] |= other;
			impl_.data[3] |= other;
			return *this;
		}

		template<typename U>
		vec& operator|=(vec4<U> other)
		{
			impl_.data[0] |= other[0];
			impl_.data[1] |= other[1];
			impl_.data[2] |= other[2];
			impl_.data[3] |= other[3];
			return *this;
		}

		template<typename U>
		vec& operator^=(U other)
		{
			impl_.data[0] ^= other;
			impl_.data[1] ^= other;
			impl_.data[2] ^= other;
			impl_.data[3] ^= other;
			return *this;
		}

		template<typename U>
		vec& operator^=(vec4<U> other)
		{
			impl_.data[0] ^= other[0];
			impl_.data[1] ^= other[1];
			impl_.data[2] ^= other[2];
			impl_.data[3] ^= other[3];
			return *this;
		}

		template<typename U>
		vec& operator<<=(U other)
		{
			impl_.data[0] <<= other;
			impl_.data[1] <<= other;
			impl_.data[2] <<= other;
			impl_.data[3] <<= other;
			return *this;
		}

		template<typename U>
		vec& operator<<=(vec4<U> other)
		{
			impl_.data[0] <<= other[0];
			impl_.data[1] <<= other[1];
			impl_.data[2] <<= other[2];
			impl_.data[3] <<= other[3];
			return *this;
		}
		
		template<typename U>
		vec& operator>>=(U other)
		{
			impl_.data[0] >>= other;
			impl_.data[1] >>= other;
			impl_.data[2] >>= other;
			impl_.data[3] >>= other;
			return *this;
		}

		template<typename U>
		vec& operator>>=(vec4<U> other)
		{
			impl_.data[0] >>= other[0];
			impl_.data[1] >>= other[1];
			impl_.data[2] >>= other[2];
			impl_.data[3] >>= other[3];
			return *this;
		}
	};
}
