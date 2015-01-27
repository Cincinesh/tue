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
	template<typename T>
	class quat;

	using fquat = quat<float>;
	using dquat = quat<double>;

	// -------
	// quat<T>
	// -------
	template<typename T>
	class quat
	{
	private:
		struct { T data[4]; } impl_;

	public:
		// -------------------
		// default constructor
		// -------------------
		quat() = default;

		// ----------------------
		// component constructors
		// ----------------------
		constexpr quat(const T& x, const T& y, const T& z, const T& w) :
			impl_({ { x, y, z, w } }) {}

		constexpr quat(const vec3<T>& v, const T& s) :
			impl_({ { v[0], v[1], v[2], s } }) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr quat(const quat<U>& other) :
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
		constexpr operator quat<U>() const
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
		static constexpr quat identity()
		{
			return{ T(0), T(0), T(0), T(1) };
		}

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

		// -
		// v
		// -
		constexpr vec3<T> v() const
		{
			return{
				impl_.data[0],
				impl_.data[1],
				impl_.data[2],
			};
		}
		
		void set_v(const T& x, const T& y, const T& z)
		{
			impl_.data[0] = x;
			impl_.data[1] = y;
			impl_.data[2] = z;
		}
		
		void set_v(const vec3<T>& v)
		{
			set_v(v[0], v[1], v[2]);
		}

		// -
		// s
		// -
		constexpr T s() const { return impl_.data[3]; }
		void set_s(const T& s) { impl_.data[3] = s; }

		// ----
		// q[i]
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
	};

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const quat<T>& lhs,
		const quat<U>& rhs)
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
		const quat<U>& rhs)
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
		inline auto length2(const quat<T>& q)
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
		inline auto length(const quat<T>& q)
		{
			return math::sqrt(math::length2(q));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline auto normalize(const quat<T>& q)
		{
			const auto l = math::length(q);
			return quat<decltype(l / l)>{
				delctype(l)(q[0]) / l,
					delctype(l)(q[1]) / l,
					delctype(l)(q[2]) / l,
					delctype(l)(q[3]) / l,
			};
		}
	}
}

#undef TUE_CONSTEXPR
