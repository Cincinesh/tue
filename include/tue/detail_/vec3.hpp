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

namespace tue {

template<typename T, int C, int R>
class mat;

template<typename T>
class quat;

template<typename T>
class vec<T, 3>
{
public:
  using component_type = T;

  static constexpr int component_count = 3;

private:
  struct { T data[3]; } impl_;

public:
  vec() noexcept = default;

  constexpr vec(const T& x, const T& y, const T& z) noexcept
    : impl_({{ x, y, z }}) {
  }

  explicit constexpr vec(const T& s) noexcept
    : impl_({{ s, s, s }}) {
  }

  explicit constexpr vec(const vec2<T>& xy, const T& z) noexcept
    : impl_({{ xy[0], xy[1], z }}) {
  }

  explicit constexpr vec(const vec4<T>& other) noexcept
    : impl_({{ other[0], other[1], other[2] }}) {
  }

  template<typename U>
  explicit constexpr vec(const vec3<U>& other) noexcept
    : impl_({{
        T(other[0]),
        T(other[1]),
        T(other[2]),
      }}) {
  }

  template<typename U>
  constexpr operator vec3<U>() const noexcept {
    return {
      impl_.data[0],
      impl_.data[1],
      impl_.data[2],
    };
  }

  static constexpr vec zero() noexcept {
    return { T(0), T(0), T(0) };
  }

  static constexpr vec x_axis() noexcept {
    return { T(1), T(0), T(0) };
  }

  static constexpr vec y_axis() noexcept {
    return { T(0), T(1), T(0) };
  }

  static constexpr vec z_axis() noexcept {
    return { T(0), T(0), T(1) };
  }

  constexpr T x() const noexcept {
    return impl_.data[0];
  }

  void set_x(const T& x) noexcept {
    impl_.data[0] = x;
  }

  constexpr T y() const noexcept {
    return impl_.data[1];
  }

  void set_y(const T& y) noexcept {
    impl_.data[1] = y;
  }

  constexpr T z() const noexcept {
    return impl_.data[2];
  }

  void set_z(const T& z) noexcept {
    impl_.data[2] = z;
  }

  constexpr T r() const noexcept {
    return impl_.data[0];
  }

  void set_r(const T& r) noexcept {
    impl_.data[0] = r;
  }

  constexpr T g() const noexcept {
    return impl_.data[1];
  }

  void set_g(const T& g) noexcept {
    impl_.data[1] = g;
  }

  constexpr T b() const noexcept {
    return impl_.data[2];
  }

  void set_b(const T& b) noexcept {
    impl_.data[2] = b;
  }

  constexpr vec2<T> xy() const noexcept {
    return { x(), y() };
  }

  void set_xy(const vec2<T>& xy) noexcept {
    set_x(xy[0]);
    set_y(xy[1]);
  }

  void set_xy(const T& x, const T& y) noexcept {
    set_x(x);
    set_y(y);
  }

  constexpr vec2<T> rg() const noexcept {
    return { r(), g() };
  }

  void set_rg(const vec2<T>& rg) noexcept {
    set_r(rg[0]);
    set_g(rg[1]);
  }

  void set_rg(const T& r, const T& g) noexcept {
    set_r(r);
    set_g(g);
  }

  T* data() noexcept {
    return impl_.data;
  }

  const T* data() const noexcept {
    return impl_.data;
  }

  template<typename I>
  T& operator[](const I& i) noexcept {
    return impl_.data[i];
  }

  template<typename I>
  constexpr const T& operator[](const I& i) const noexcept {
    return impl_.data[i];
  }

  vec& operator++() noexcept {
    ++impl_.data[0];
    ++impl_.data[1];
    ++impl_.data[2];
    return *this;
  }

  vec& operator--() noexcept {
    --impl_.data[0];
    --impl_.data[1];
    --impl_.data[2];
    return *this;
  }

  vec operator++(int) noexcept {
    return {
      impl_.data[0]++,
      impl_.data[1]++,
      impl_.data[2]++,
    };
  }

  vec operator--(int) noexcept {
    return {
      impl_.data[0]--,
      impl_.data[1]--,
      impl_.data[2]--,
    };
  }

  template<typename U>
  vec& operator+=(const U& other) noexcept {
    impl_.data[0] += other;
    impl_.data[1] += other;
    impl_.data[2] += other;
    return *this;
  }

  template<typename U>
  vec& operator+=(const vec3<U>& other) noexcept {
    impl_.data[0] += other[0];
    impl_.data[1] += other[1];
    impl_.data[2] += other[2];
    return *this;
  }

  template<typename U>
  vec& operator-=(const U& other) noexcept {
    impl_.data[0] -= other;
    impl_.data[1] -= other;
    impl_.data[2] -= other;
    return *this;
  }

  template<typename U>
  vec& operator-=(const vec3<U>& other) noexcept {
    impl_.data[0] -= other[0];
    impl_.data[1] -= other[1];
    impl_.data[2] -= other[2];
    return *this;
  }

  template<typename U>
  vec& operator*=(const U& other) noexcept {
    impl_.data[0] *= other;
    impl_.data[1] *= other;
    impl_.data[2] *= other;
    return *this;
  }

  template<typename U>
  vec& operator*=(const vec3<U>& other) noexcept {
    impl_.data[0] *= other[0];
    impl_.data[1] *= other[1];
    impl_.data[2] *= other[2];
    return *this;
  }

  template<typename U>
  vec& operator*=(const quat<U>& other) noexcept {
    return *this = *this * other;
  }

  template<typename U>
  vec& operator*=(const mat<U, 3, 3>& other) noexcept {
    return *this = *this * other;
  }

  template<typename U>
  vec& operator/=(const U& other) noexcept {
    impl_.data[0] /= other;
    impl_.data[1] /= other;
    impl_.data[2] /= other;
    return *this;
  }

  template<typename U>
  vec& operator/=(const vec3<U>& other) noexcept {
    impl_.data[0] /= other[0];
    impl_.data[1] /= other[1];
    impl_.data[2] /= other[2];
    return *this;
  }

  template<typename U>
  vec& operator%=(const U& other) noexcept {
    impl_.data[0] %= other;
    impl_.data[1] %= other;
    impl_.data[2] %= other;
    return *this;
  }

  template<typename U>
  vec& operator%=(const vec3<U>& other) noexcept {
    impl_.data[0] %= other[0];
    impl_.data[1] %= other[1];
    impl_.data[2] %= other[2];
    return *this;
  }

  template<typename U>
  vec& operator&=(const U& other) noexcept {
    impl_.data[0] &= other;
    impl_.data[1] &= other;
    impl_.data[2] &= other;
    return *this;
  }

  template<typename U>
  vec& operator&=(const vec3<U>& other) noexcept {
    impl_.data[0] &= other[0];
    impl_.data[1] &= other[1];
    impl_.data[2] &= other[2];
    return *this;
  }

  template<typename U>
  vec& operator|=(const U& other) noexcept {
    impl_.data[0] |= other;
    impl_.data[1] |= other;
    impl_.data[2] |= other;
    return *this;
  }

  template<typename U>
  vec& operator|=(const vec3<U>& other) noexcept {
    impl_.data[0] |= other[0];
    impl_.data[1] |= other[1];
    impl_.data[2] |= other[2];
    return *this;
  }

  template<typename U>
  vec& operator^=(const U& other) noexcept {
    impl_.data[0] ^= other;
    impl_.data[1] ^= other;
    impl_.data[2] ^= other;
    return *this;
  }

  template<typename U>
  vec& operator^=(const vec3<U>& other) noexcept {
    impl_.data[0] ^= other[0];
    impl_.data[1] ^= other[1];
    impl_.data[2] ^= other[2];
    return *this;
  }

  template<typename U>
  vec& operator<<=(const U& other) noexcept {
    impl_.data[0] <<= other;
    impl_.data[1] <<= other;
    impl_.data[2] <<= other;
    return *this;
  }

  template<typename U>
  vec& operator<<=(const vec3<U>& other) noexcept {
    impl_.data[0] <<= other[0];
    impl_.data[1] <<= other[1];
    impl_.data[2] <<= other[2];
    return *this;
  }

  template<typename U>
  vec& operator>>=(const U& other) noexcept {
    impl_.data[0] >>= other;
    impl_.data[1] >>= other;
    impl_.data[2] >>= other;
    return *this;
  }

  template<typename U>
  vec& operator>>=(const vec3<U>& other) noexcept {
    impl_.data[0] >>= other[0];
    impl_.data[1] >>= other[1];
    impl_.data[2] >>= other[2];
    return *this;
  }

private:
  template<typename U, int C, int R>
  friend class mat;

  static constexpr vec extend_(
      const vec2<T>& v,
      const T& z,
      const T&) noexcept {
    return vec(v, z);
  }

  static constexpr vec extend_(
      const vec3<T>& v,
      const T&,
      const T&) noexcept {
    return v;
  }

  static constexpr vec extend_(
      const vec4<T>& v,
      const T&,
      const T&) noexcept {
    return vec(v);
  }
};

template<typename T>
inline TUE_CONSTEXPR auto operator+(const vec3<T>& v) noexcept {
  return vec3<decltype(+v[0])>(+v[0], +v[1], +v[2]);
}

template<typename T>
inline TUE_CONSTEXPR auto operator-(const vec3<T>& v) noexcept {
  return vec3<decltype(-v[0])>(-v[0], -v[1], -v[2]);
}

template<typename T>
inline TUE_CONSTEXPR auto operator~(const vec3<T>& v) noexcept {
  return vec3<decltype(~v[0])>(~v[0], ~v[1], ~v[2]);
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator+(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs + rhs[0])>{
    lhs + rhs[0],
    lhs + rhs[1],
    lhs + rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator+(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] + rhs)>{
    lhs[0] + rhs,
    lhs[1] + rhs,
    lhs[2] + rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator+(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] + rhs[0])>{
    lhs[0] + rhs[0],
    lhs[1] + rhs[1],
    lhs[2] + rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator-(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs - rhs[0])>{
    lhs - rhs[0],
    lhs - rhs[1],
    lhs - rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator-(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] - rhs)>{
    lhs[0] - rhs,
    lhs[1] - rhs,
    lhs[2] - rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator-(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] - rhs[0])>{
    lhs[0] - rhs[0],
    lhs[1] - rhs[1],
    lhs[2] - rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator*(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs * rhs[0])>{
    lhs * rhs[0],
    lhs * rhs[1],
    lhs * rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator*(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] * rhs)>{
    lhs[0] * rhs,
    lhs[1] * rhs,
    lhs[2] * rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator*(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] * rhs[0])>{
    lhs[0] * rhs[0],
    lhs[1] * rhs[1],
    lhs[2] * rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator/(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs / rhs[0])>{
    lhs / rhs[0],
    lhs / rhs[1],
    lhs / rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator/(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] / rhs)>{
    lhs[0] / rhs,
    lhs[1] / rhs,
    lhs[2] / rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator/(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] / rhs[0])>{
    lhs[0] / rhs[0],
    lhs[1] / rhs[1],
    lhs[2] / rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator%(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs % rhs[0])>{
    lhs % rhs[0],
    lhs % rhs[1],
    lhs % rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator%(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] % rhs)>{
    lhs[0] % rhs,
    lhs[1] % rhs,
    lhs[2] % rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator%(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] % rhs[0])>{
    lhs[0] % rhs[0],
    lhs[1] % rhs[1],
    lhs[2] % rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator&(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs & rhs[0])>{
    lhs & rhs[0],
    lhs & rhs[1],
    lhs & rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator&(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] & rhs)>{
    lhs[0] & rhs,
    lhs[1] & rhs,
    lhs[2] & rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator&(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] & rhs[0])>{
    lhs[0] & rhs[0],
    lhs[1] & rhs[1],
    lhs[2] & rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator|(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs | rhs[0])>{
    lhs | rhs[0],
    lhs | rhs[1],
    lhs | rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator|(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] | rhs)>{
    lhs[0] | rhs,
    lhs[1] | rhs,
    lhs[2] | rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator|(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] | rhs[0])>{
    lhs[0] | rhs[0],
    lhs[1] | rhs[1],
    lhs[2] | rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator^(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs ^ rhs[0])>{
    lhs ^ rhs[0],
    lhs ^ rhs[1],
    lhs ^ rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator^(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] ^ rhs)>{
    lhs[0] ^ rhs,
    lhs[1] ^ rhs,
    lhs[2] ^ rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator^(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] ^ rhs[0])>{
    lhs[0] ^ rhs[0],
    lhs[1] ^ rhs[1],
    lhs[2] ^ rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator<<(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs << rhs[0])>{
    lhs << rhs[0],
    lhs << rhs[1],
    lhs << rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator<<(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] << rhs)>{
    lhs[0] << rhs,
    lhs[1] << rhs,
    lhs[2] << rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator<<(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] << rhs[0])>{
    lhs[0] << rhs[0],
    lhs[1] << rhs[1],
    lhs[2] << rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator>>(
    const T& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs >> rhs[0])>{
    lhs >> rhs[0],
    lhs >> rhs[1],
    lhs >> rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator>>(
    const vec3<T>& lhs,
    const U& rhs) noexcept {
  return vec3<decltype(lhs[0] >> rhs)>{
    lhs[0] >> rhs,
    lhs[1] >> rhs,
    lhs[2] >> rhs,
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR auto operator>>(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return vec3<decltype(lhs[0] >> rhs[0])>{
    lhs[0] >> rhs[0],
    lhs[1] >> rhs[1],
    lhs[2] >> rhs[2],
  };
}

template<typename T, typename U>
inline TUE_CONSTEXPR bool operator==(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return lhs[0] == rhs[0]
      && lhs[1] == rhs[1]
      && lhs[2] == rhs[2];
}

template<typename T, typename U>
inline TUE_CONSTEXPR bool operator!=(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept {
  return !(lhs == rhs);
}

namespace math
{
  template<typename T>
  inline auto sin(const vec3<T>& v) noexcept {
    return vec3<decltype(math::sin(v[0]))>{
      math::sin(v[0]),
      math::sin(v[1]),
      math::sin(v[2]),
    };
  }

  template<typename T>
  inline auto cos(const vec3<T>& v) noexcept {
    return vec3<decltype(math::cos(v[0]))>{
      math::cos(v[0]),
      math::cos(v[1]),
      math::cos(v[2]),
    };
  }

  template<typename T>
  inline void sincos(
      const vec3<T>& v,
      decltype(math::sin(v))& sin_result,
      decltype(math::cos(v))& cos_result) noexcept {
    math::sincos(v[0], sin_result[0], cos_result[0]);
    math::sincos(v[1], sin_result[1], cos_result[1]);
    math::sincos(v[2], sin_result[2], cos_result[2]);
  }

  template<typename T>
  inline auto exp(const vec3<T>& v) noexcept {
    return vec3<decltype(math::exp(v[0]))>{
      math::exp(v[0]),
      math::exp(v[1]),
      math::exp(v[2]),
    };
  }

  template<typename T>
  inline auto log(const vec3<T>& v) noexcept {
    return vec3<decltype(math::log(v[0]))>{
      math::log(v[0]),
      math::log(v[1]),
      math::log(v[2]),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec3<T>& base,
      const U& exponent) noexcept {
    return vec3<decltype(math::pow(base[0], exponent))>{
      math::pow(base[0], exponent),
      math::pow(base[1], exponent),
      math::pow(base[2], exponent),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec3<T>& base,
      const vec3<U>& exponent) noexcept {
    return vec3<decltype(math::pow(base[0], exponent[0]))>{
      math::pow(base[0], exponent[0]),
      math::pow(base[1], exponent[1]),
      math::pow(base[2], exponent[2]),
    };
  }

  template<typename T>
  inline auto recip(const vec3<T>& v) noexcept {
    return vec3<decltype(math::recip(v[0]))>{
      math::recip(v[0]),
      math::recip(v[1]),
      math::recip(v[2]),
    };
  }

  template<typename T>
  inline auto sqrt(const vec3<T>& v) noexcept {
    return vec3<decltype(math::sqrt(v[0]))>{
      math::sqrt(v[0]),
      math::sqrt(v[1]),
      math::sqrt(v[2]),
    };
  }

  template<typename T>
  inline auto rsqrt(const vec3<T>& v) noexcept {
    return vec3<decltype(math::rsqrt(v[0]))>{
      math::rsqrt(v[0]),
      math::rsqrt(v[1]),
      math::rsqrt(v[2]),
    };
  }

  template<typename T>
  inline auto min(
      const vec3<T>& v1,
      const vec3<T>& v2) noexcept {
    return vec3<decltype(math::min(v1[0], v2[0]))>{
      math::min(v1[0], v2[0]),
      math::min(v1[1], v2[1]),
      math::min(v1[2], v2[2]),
    };
  }

  template<typename T>
  inline auto max(
      const vec3<T>& v1,
      const vec3<T>& v2) noexcept {
    return vec3<decltype(math::max(v1[0], v2[0]))>{
      math::max(v1[0], v2[0]),
      math::max(v1[1], v2[1]),
      math::max(v1[2], v2[2]),
    };
  }

  template<typename T>
  inline auto abs(const vec3<T>& v) noexcept {
    return vec3<decltype(math::abs(v[0]))>{
      math::abs(v[0]),
      math::abs(v[1]),
      math::abs(v[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto dot(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return lhs[0] * rhs[0]
        + lhs[1] * rhs[1]
        + lhs[2] * rhs[2];
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto cross(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec<decltype(lhs[1]*rhs[2] - lhs[2]*rhs[1]), 3>{
      lhs[1]*rhs[2] - lhs[2]*rhs[1],
      lhs[2]*rhs[0] - lhs[0]*rhs[2],
      lhs[0]*rhs[1] - lhs[1]*rhs[0],
    };
  }

  template<typename T>
  inline auto length2(const vec3<T>& v) noexcept {
    return math::length2(v[0])
        + math::length2(v[1])
        + math::length2(v[2]);
  }

  template<typename T>
  inline auto length(const vec3<T>& v) noexcept {
    return math::sqrt(math::length2(v));
  }

  template<typename T>
  inline auto normalize(const vec3<T>& v) noexcept {
    return vec3<decltype(math::length(v))>(v) / math::length(v);
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto comp_mult(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::comp_mult(lhs[0], rhs[0]))>{
      math::comp_mult(lhs[0], rhs[0]),
      math::comp_mult(lhs[1], rhs[1]),
      math::comp_mult(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto select(
      const vec3<T>& v,
      const vec3<U>& mask) noexcept {
    return vec3<decltype(math::select(v[0], mask[0]))>{
      math::select(v[0], mask[0]),
      math::select(v[1], mask[1]),
      math::select(v[2], mask[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto less(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::less(lhs[0], rhs[0]))>{
      math::less(lhs[0], rhs[0]),
      math::less(lhs[1], rhs[1]),
      math::less(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto less_equal(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::less_equal(lhs[0], rhs[0]))>{
      math::less_equal(lhs[0], rhs[0]),
      math::less_equal(lhs[1], rhs[1]),
      math::less_equal(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto greater(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::greater(lhs[0], rhs[0]))>{
      math::greater(lhs[0], rhs[0]),
      math::greater(lhs[1], rhs[1]),
      math::greater(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto greater_equal(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::greater_equal(lhs[0], rhs[0]))>{
      math::greater_equal(lhs[0], rhs[0]),
      math::greater_equal(lhs[1], rhs[1]),
      math::greater_equal(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto equal(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::equal(lhs[0], rhs[0]))>{
      math::equal(lhs[0], rhs[0]),
      math::equal(lhs[1], rhs[1]),
      math::equal(lhs[2], rhs[2]),
    };
  }

  template<typename T, typename U>
  inline TUE_CONSTEXPR auto not_equal(
      const vec3<T>& lhs,
      const vec3<U>& rhs) noexcept {
    return vec3<decltype(math::not_equal(lhs[0], rhs[0]))>{
      math::not_equal(lhs[0], rhs[0]),
      math::not_equal(lhs[1], rhs[1]),
      math::not_equal(lhs[2], rhs[2]),
    };
  }

  template<typename T>
  inline auto rotation_vec(const vec3<T>& axis, const T& angle) noexcept {
    return axis * angle;
  }

  template<typename T>
  inline auto rotation_vec(
      const T& axis_x,
      const T& axis_y,
      const T& axis_z,
      const T& angle) noexcept {
    return math::rotation_vec(vec3<T>(axis_x, axis_y, axis_z), angle);
  }

  template<typename T>
  inline auto rotation_vec(const vec4<T>& v) noexcept {
    return math::rotation_vec(v.xyz(), v.w());
  }
}

}

#undef TUE_CONSTEXPR
