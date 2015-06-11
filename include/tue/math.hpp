//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

namespace tue {

namespace math
{
  constexpr float pi = 3.14159265358979323846264338327950288f;

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type sin(T x) noexcept {
    return std::sin(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type sin(T x) noexcept {
    return math::sin(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type cos(T x) noexcept {
    return std::cos(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type cos(T x) noexcept {
    return math::cos(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  void>::type sincos(T x, T& sin_out, T& cos_out) noexcept {
    sin_out = std::sin(x);
    cos_out = std::cos(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  void>::type sincos(T x, double& sin_out, double& cos_out) noexcept {
    math::sincos(static_cast<double>(x), sin_out, cos_out);
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type exp(T x) noexcept {
    return std::exp(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type exp(T x) noexcept {
    return math::exp(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type log(T x) noexcept {
    return std::log(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type log(T x) noexcept {
    return math::log(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type pow(T base, T exponent) noexcept {
    return std::pow(base, exponent);
  }

  template<typename T, typename U>
  inline typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value
      && !std::is_same<T, long double>::value
      && !std::is_same<U, long double>::value,
  double>::type pow(T base, U exponent) noexcept {
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
  long double>::type pow(T base, U exponent) noexcept {
    return math::pow(
        static_cast<long double>(base),
        static_cast<long double>(exponent));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type recip(T x) noexcept {
    return 1 / x;
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type recip(T x) noexcept {
    return math::recip(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type sqrt(T x) noexcept {
    return std::sqrt(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type sqrt(T x) noexcept {
    return math::sqrt(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type rsqrt(T x) noexcept {
    return math::recip(math::sqrt(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type rsqrt(T x) noexcept {
    return math::rsqrt(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_arithmetic<T>::value,
  T>::type min(T x1, T x2) noexcept {
    return std::min(x1, x2);
  }

  template<typename T>
  inline typename std::enable_if<std::is_arithmetic<T>::value,
  T>::type max(T x1, T x2) noexcept {
    return std::max(x1, x2);
  }

  template<typename T>
  inline typename std::enable_if<std::is_signed<T>::value,
  T>::type abs(T x) noexcept {
    return static_cast<T>(std::abs(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_unsigned<T>::value,
  T>::type abs(T x) noexcept {
    return x;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  decltype(T() * U())>::type dot(T lhs, U rhs) noexcept {
    return lhs * rhs;
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type length2(T x) noexcept {
    return x * x;
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type length2(T x) noexcept {
    return math::length2(static_cast<double>(x));
  }

  template<typename T>
  inline typename std::enable_if<std::is_floating_point<T>::value,
  T>::type length(T x) noexcept {
    return math::abs(x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type length(T x) noexcept {
    return math::length(static_cast<double>(x));
  }

  inline float normalize(float x) noexcept {
    return ::copysignf(1.0f, x);
  }

  inline double normalize(double x) noexcept {
    return ::copysign(1.0, x);
  }

  inline long double normalize(long double x) noexcept {
    return ::copysignl(1.0L, x);
  }

  template<typename T>
  inline typename std::enable_if<std::is_integral<T>::value,
  double>::type normalize(T x) noexcept {
    return math::normalize(static_cast<double>(x));
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  decltype(T() * U())>::type comp_mult(T lhs, U rhs) noexcept {
    return lhs * rhs;
  }

  template<typename T>
  inline constexpr typename std::enable_if<std::is_arithmetic<T>::value,
  T>::type transpose(T x) noexcept {
    return x;
  }

  template<typename T>
  inline constexpr T select(
      bool condition,
      const T& value,
      const T& otherwise = T(0)) noexcept {
    return condition ? value : otherwise;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type less(T lhs, U rhs) noexcept {
    return lhs < rhs;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type less_equal(T lhs, U rhs) noexcept {
    return lhs <= rhs;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type greater(T lhs, U rhs) noexcept {
    return lhs > rhs;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type greater_equal(T lhs, U rhs) noexcept {
    return lhs >= rhs;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type equal(T lhs, U rhs) noexcept {
    return lhs == rhs;
  }

  template<typename T, typename U>
  inline constexpr typename std::enable_if<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool>::type not_equal(T lhs, U rhs) noexcept {
    return lhs != rhs;
  }
}

}
