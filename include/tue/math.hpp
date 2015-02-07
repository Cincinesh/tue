//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

// The Tuesday C++ math and template library.
namespace tue
{
  // Non-member math functions.
  namespace math
  {
    // Sets sin_result and cos_result to the trigonometric sine and cosine
    // respectively of the given number.
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

    // Sets sin_result and cos_result to the trigonometric sine and cosine
    // respectively of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    void>::type sincos(
        T x,
        double& sin_out,
        double& cos_out) noexcept
    {
      math::sincos(static_cast<double>(x), sin_out, cos_out);
    }

    // Returns the trigonometric sine of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type sin(T x) noexcept
    {
      return std::sin(x);
    }

    // Returns the trigonometric sine of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type sin(T x) noexcept
    {
      return math::sin(static_cast<double>(x));
    }

    // Returns the trigonometric cosine of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type cos(T x) noexcept
    {
      return std::cos(x);
    }

    // Returns the trigonometric cosine of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type cos(T x) noexcept
    {
      return math::cos(static_cast<double>(x));
    }

    // Returns the result of raising e (Euler's number) to the given exponent.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type exp(T x) noexcept
    {
      return std::exp(x);
    }

    // Returns the result of raising e (Euler's number) to the given exponent
    // cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type exp(T x) noexcept
    {
      return math::exp(static_cast<double>(x));
    }

    // Returns the natural log of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type log(T x) noexcept
    {
      return std::log(x);
    }

    // Returns the natural log of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type log(T x) noexcept
    {
      return math::log(static_cast<double>(x));
    }

    // Returns the result of raising the given base to the given exponent.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type pow(T base, T exponent) noexcept
    {
      return std::pow(base, exponent);
    }

    // Returns the result of raising the given base cast to double to the
    // given exponent cast to double.
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

    // Returns the result of raising the given base cast to long double to the
    // given exponent cast to long double.
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

    // Returns the reciprocal of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type recip(T x) noexcept
    {
      return 1 / x;
    }

    // Returns the reciprocal of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type recip(T x) noexcept
    {
      return math::recip(static_cast<double>(x));
    }

    // Returns the square root of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type sqrt(T x) noexcept
    {
      return std::sqrt(x);
    }

    // Returns the square root of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type sqrt(T x) noexcept
    {
      return math::sqrt(static_cast<double>(x));
    }

    // Returns the reciprocal square root of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type rsqrt(T x) noexcept
    {
      return math::recip(math::sqrt(x));
    }

    // Returns the reciprocal square root of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type rsqrt(T x) noexcept
    {
      return math::rsqrt(static_cast<double>(x));
    }

    // Returns the minimum of two numbers.
    template<typename T>
    inline typename std::enable_if<std::is_arithmetic<T>::value,
    T>::type min(T x1, T x2) noexcept
    {
      return std::min(x1, x2);
    }

    // Returns the maximum of two numbers.
    template<typename T>
    inline typename std::enable_if<std::is_arithmetic<T>::value,
    T>::type max(T x1, T x2) noexcept
    {
      return std::max(x1, x2);
    }

    // Returns the absolute value of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_signed<T>::value,
    T>::type abs(T x) noexcept
    {
      return static_cast<T>(std::abs(x));
    }

    // Returns the absolute value of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_unsigned<T>::value,
    T>::type abs(T x) noexcept
    {
      return x;
    }

    // Returns the product of two numbers.
    template<typename T, typename U>
    inline constexpr typename std::enable_if<
        std::is_arithmetic<T>::value
        && std::is_arithmetic<U>::value,
    decltype(T() * U())>::type dot(T lhs, U rhs) noexcept
    {
      return lhs * rhs;
    }

    // Returns the square of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type length2(T x) noexcept
    {
      return x * x;
    }

    // Returns the square of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type length2(T x) noexcept
    {
      return math::length2(static_cast<double>(x));
    }

    // Returns the absolute value of the given number.
    template<typename T>
    inline typename std::enable_if<std::is_floating_point<T>::value,
    T>::type length(T x) noexcept
    {
      return math::abs(x);
    }

    // Returns the absolute value of the given number cast to double.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type length(T x) noexcept
    {
      return math::length(static_cast<double>(x));
    }

    // Returns the result of dividing the given number by its absolute value.
    inline float normalize(float x) noexcept
    {
      return ::copysignf(1.0f, x);
    }

    // Returns the result of dividing the given number by its absolute value.
    inline double normalize(double x) noexcept
    {
      return ::copysign(1.0, x);
    }

    // Returns the result of dividing the given number by its absolute value.
    inline long double normalize(long double x) noexcept
    {
      return ::copysignl(1.0L, x);
    }

    // Returns the result of dividing the given number cast to double by its
    // absolute value.
    template<typename T>
    inline typename std::enable_if<std::is_integral<T>::value,
    double>::type normalize(T x) noexcept
    {
      return math::normalize(static_cast<double>(x));
    }
  }
}
