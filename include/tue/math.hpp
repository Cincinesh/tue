//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

namespace tue {

namespace detail_
{
  template<typename T, typename U>
  using pow_promote_t =
    std::conditional_t<
        std::is_floating_point<T>::value, T,
        std::conditional_t<
            std::is_integral<U>::value, double,
            std::conditional_t<
                (sizeof(U) <= sizeof(double)), double, U>>>;
}

namespace math
{
  constexpr float pi = 3.14159265358979323846264338327950288f;

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> sin(T x) noexcept {
    return std::sin(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> sin(T x) noexcept {
    return math::sin(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> cos(T x) noexcept {
    return std::cos(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> cos(T x) noexcept {
    return math::cos(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  void> sincos(T x, T& sin_out, T& cos_out) noexcept {
    sin_out = std::sin(x);
    cos_out = std::cos(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  void> sincos(T x, double& sin_out, double& cos_out) noexcept {
    math::sincos(static_cast<double>(x), sin_out, cos_out);
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> exp(T x) noexcept {
    return std::exp(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> exp(T x) noexcept {
    return math::exp(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> log(T x) noexcept {
    return std::log(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> log(T x) noexcept {
    return math::log(static_cast<double>(x));
  }

  template<typename T, typename U>
  inline std::enable_if_t<(
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value),
  decltype(detail_::pow_promote_t<T, U>() * detail_::pow_promote_t<U, T>())>
  pow(T base, U exponent) noexcept {
    return std::pow(
        static_cast<detail_::pow_promote_t<T, U>>(base),
        static_cast<detail_::pow_promote_t<U, T>>(exponent));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> recip(T x) noexcept {
    return 1 / x;
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> recip(T x) noexcept {
    return math::recip(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> sqrt(T x) noexcept {
    return std::sqrt(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> sqrt(T x) noexcept {
    return math::sqrt(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> rsqrt(T x) noexcept {
    return math::recip(math::sqrt(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> rsqrt(T x) noexcept {
    return math::rsqrt(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_arithmetic<T>::value,
  T> min(T x1, T x2) noexcept {
    return std::min(x1, x2);
  }

  template<typename T>
  inline std::enable_if_t<std::is_arithmetic<T>::value,
  T> max(T x1, T x2) noexcept {
    return std::max(x1, x2);
  }

  template<typename T>
  inline std::enable_if_t<std::is_signed<T>::value,
  T> abs(T x) noexcept {
    return static_cast<T>(std::abs(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_unsigned<T>::value,
  T> abs(T x) noexcept {
    return x;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  decltype(T() * U())> dot(T lhs, U rhs) noexcept {
    return lhs * rhs;
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> length2(T x) noexcept {
    return x * x;
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> length2(T x) noexcept {
    return math::length2(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> length(T x) noexcept {
    return math::abs(x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> length(T x) noexcept {
    return math::length(static_cast<double>(x));
  }

  template<typename T>
  inline std::enable_if_t<std::is_floating_point<T>::value,
  T> normalize(T x) noexcept {
      return std::copysign(T(1), x);
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value,
  double> normalize(T x) noexcept {
    return math::normalize(static_cast<double>(x));
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  decltype(T() * U())> comp_mult(T lhs, U rhs) noexcept {
    return lhs * rhs;
  }

  template<typename T>
  inline constexpr std::enable_if_t<std::is_arithmetic<T>::value,
  T> transpose(T x) noexcept {
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
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> less(T lhs, U rhs) noexcept {
    return lhs < rhs;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> less_equal(T lhs, U rhs) noexcept {
    return lhs <= rhs;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> greater(T lhs, U rhs) noexcept {
    return lhs > rhs;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> greater_equal(T lhs, U rhs) noexcept {
    return lhs >= rhs;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> equal(T lhs, U rhs) noexcept {
    return lhs == rhs;
  }

  template<typename T, typename U>
  inline constexpr std::enable_if_t<
      std::is_arithmetic<T>::value
      && std::is_arithmetic<U>::value,
  bool> not_equal(T lhs, U rhs) noexcept {
    return lhs != rhs;
  }
}

}
