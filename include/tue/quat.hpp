//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "math.hpp"
#include "vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// -------
	// quat<T>
	// -------
	template<typename T>
	class quat;

	using fquat = quat<float>;
	using dquat = quat<double>;

	template<typename T>
	class quat
	{
	private:
		struct { T data[4]; } impl_;

	public:
		// -------------------
		// default constructor
		// -------------------
		quat() noexcept = default;

		// ----------------------
		// component constructors
		// ----------------------
		constexpr quat(
			const T& x,
			const T& y,
			const T& z,
			const T& w) noexcept :
			impl_({ { x, y, z, w } }) {}

		constexpr quat(const vec3<T>& v, const T& s) noexcept :
			impl_({ { v[0], v[1], v[2], s } }) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr quat(const quat<U>& other) noexcept :
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
		constexpr operator quat<U>() const noexcept
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
		static constexpr quat identity() noexcept
		{
			return{ T(0), T(0), T(0), T(1) };
		}

		// -
		// x
		// -
		constexpr T x() const noexcept { return impl_.data[0]; }
		void set_x(const T& x) noexcept { impl_.data[0] = x; }

		// -
		// y
		// -
		constexpr T y() const noexcept { return impl_.data[1]; }
		void set_y(const T& y) noexcept { impl_.data[1] = y; }

		// -
		// z
		// -
		constexpr T z() const noexcept { return impl_.data[2]; }
		void set_z(const T& z) noexcept { impl_.data[2] = z; }

		// -
		// w
		// -
		constexpr T w() const noexcept { return impl_.data[3]; }
		void set_w(const T& w) noexcept { impl_.data[3] = w; }

		// -
		// v
		// -
		constexpr vec3<T> v() const noexcept
		{
			return{
				impl_.data[0],
				impl_.data[1],
				impl_.data[2],
			};
		}
		
		void set_v(const T& x, const T& y, const T& z) noexcept
		{
			impl_.data[0] = x;
			impl_.data[1] = y;
			impl_.data[2] = z;
		}
		
		void set_v(const vec3<T>& v) noexcept
		{
			set_v(v[0], v[1], v[2]);
		}

		// -
		// s
		// -
		constexpr T s() const noexcept { return impl_.data[3]; }
		void set_s(const T& s) noexcept { impl_.data[3] = s; }

		// ----
		// q[i]
		// ----
		template<typename I>
		T& operator[](const I& i) noexcept
		{
			return impl_.data[i];
		}

		template<typename I>
		constexpr const T& operator[](const I& i) const noexcept
		{
			return impl_.data[i];
		}
	};

	// ---------
	// lhs * rhs
	// ---------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const quat<T>& lhs,
		const quat<U>& rhs) noexcept
	{
		return quat<decltype(lhs[0] * rhs[0])>{
			lhs.s() * rhs.v() + rhs.s() * lhs.v()
				+ math::cross(lhs.v(), rhs.v()),
			lhs.s() * rhs.s() - math::dot(lhs.v(), rhs.v()),
		};
	}

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const quat<T>& lhs,
		const quat<U>& rhs) noexcept
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
		const quat<T>& lhs,
		const quat<U>& rhs) noexcept
	{
		return !(lhs == rhs);
	}

	// ----
	// math
	// ----
	namespace math
	{
		// ---------
		// length2()
		// ---------
		template<typename T>
		inline auto length2(const quat<T>& q) noexcept
		{
			return math::length2(q[0])
				+ math::length2(q[1])
				+ math::length2(q[2])
				+ math::length2(q[3]);
		}

		// --------
		// length()
		// --------
		template<typename T>
		inline auto length(const quat<T>& q) noexcept
		{
			return math::sqrt(math::length2(q));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline auto normalize(const quat<T>& q) noexcept
		{
			const auto l = math::length(q);
			return quat<decltype(l / l)>{
				decltype(l)(q[0]) / l,
				decltype(l)(q[1]) / l,
				decltype(l)(q[2]) / l,
				decltype(l)(q[3]) / l,
			};
		}

		// -----------
		// conjugate()
		// -----------
		template<typename T>
		inline TUE_CONSTEXPR quat<T> conjugate(const quat<T>& q) noexcept
		{
			return{ -q.v(), q.s() };
		}

		// --------
		// rotate()
		// --------
		template<typename T, typename U>
		inline TUE_CONSTEXPR auto rotate(
			const quat<T>& q,
			const vec3<U>& v) noexcept
		{
			return (q * quat<U>(v, U(0)) * math::conjugate(q)).v();
		}
	}
}

#undef TUE_CONSTEXPR
