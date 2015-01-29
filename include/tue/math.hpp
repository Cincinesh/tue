//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

namespace tue
{
	namespace math
	{
		// --------
		// sincos()
		// --------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		void>::type sincos(
			T x,
			T& sin_out,
			T& cos_out) noexcept
		{
			sin_out = std::sin(x);
			cos_out = std::cos(x);
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		void>::type sincos(
			T x,
			double& sin_out,
			double& cos_out) noexcept
		{
			math::sincos(static_cast<double>(x), sin_out, cos_out);
		}

		// -----
		// sin()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type sin(T x) noexcept
		{
			return std::sin(x);
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type sin(T x) noexcept
		{
			return math::sin(static_cast<double>(x));
		}

		// -----
		// cos()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type cos(T x) noexcept
		{
			return std::cos(x);
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type cos(T x) noexcept
		{
			return math::cos(static_cast<double>(x));
		}

		// ------
		// pow()
		// ------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type pow(T base, T exponent) noexcept
		{
			return std::pow(base, exponent);
		}

		template<typename T, typename U>
		inline typename std::enable_if<
			std::is_arithmetic<T>::value
			&& std::is_arithmetic<U>::value
			&& !std::is_same<T, long double>::value
			&& !std::is_same<U, long double>::value,
		double>::type pow(T base, U exponent) noexcept
		{
			return math::pow(
				static_cast<double>(base),
				static_cast<double>(exponent));
		}

		template<typename T, typename U>
		inline typename std::enable_if<
			std::is_arithmetic<T>::value
			&& std::is_arithmetic<U>::value
			&& (std::is_same<T, long double>::value
				^ std::is_same<U, long double>::value),
		long double>::type pow(T base, U exponent) noexcept
		{
			return math::pow(
				static_cast<long double>(base),
				static_cast<long double>(exponent));
		}

		// -----
		// rcp()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type rcp(T x) noexcept
		{
			return 1 / x;
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type rcp(T x) noexcept
		{
			return math::rcp(static_cast<double>(x));
		}

		// ------
		// sqrt()
		// ------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type sqrt(T x) noexcept
		{
			return std::sqrt(x);
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type sqrt(T x) noexcept
		{
			return math::sqrt(static_cast<double>(x));
		}

		// -------
		// rsqrt()
		// -------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type rsqrt(T x) noexcept
		{
			return math::rcp(math::sqrt(x));
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type rsqrt(T x) noexcept
		{
			return math::rsqrt(static_cast<double>(x));
		}

		// -----
		// min()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_arithmetic<T>::value,
		T>::type min(T x1, T x2)
		{
			return std::min(x1, x2);
		}

		// -----
		// max()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_arithmetic<T>::value,
		T>::type max(T x1, T x2)
		{
			return std::max(x1, x2);
		}

		// -----
		// abs()
		// -----
		template<typename T>
		inline typename std::enable_if<std::is_signed<T>::value,
		T>::type abs(T x) noexcept
		{
			return static_cast<T>(std::abs(x));
		}

		template<typename T>
		inline typename std::enable_if<std::is_unsigned<T>::value,
		T>::type abs(T x) noexcept
		{
			return x;
		}

		// -----
		// dot()
		// -----
		template<typename T, typename U>
		inline constexpr typename std::enable_if<
			std::is_arithmetic<T>::value
			&& std::is_arithmetic<U>::value,
		decltype(T() * U())>::type dot(T lhs, U rhs) noexcept
		{
			return lhs * rhs;
		}

		// ---------
		// length2()
		// ---------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type length2(T x) noexcept
		{
			return x * x;
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type length2(T x) noexcept
		{
			return math::length2(static_cast<double>(x));
		}

		// --------
		// length()
		// --------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type length(T x) noexcept
		{
			return math::sqrt(math::length2(x));
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type length(T x) noexcept
		{
			return math::length(static_cast<double>(x));
		}

		// -----------
		// normalize()
		// -----------
		template<typename T>
		inline typename std::enable_if<std::is_floating_point<T>::value,
		T>::type normalize(T x) noexcept
		{
			return x / math::length(x);
		}

		template<typename T>
		inline typename std::enable_if<std::is_integral<T>::value,
		double>::type normalize(T x) noexcept
		{
			return math::normalize(static_cast<double>(x));
		}
	}
}
