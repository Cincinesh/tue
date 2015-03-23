//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../math.hpp"
#include "../vec.hpp"

namespace tue {

template<typename T, int C, int R>
class mat;

template<typename T>
class vec<T, 4>
{
public:
  using component_type = T;

  static constexpr int component_count = 4;

private:
  struct { T data[4]; } impl_;

public:
  vec() noexcept = default;

  constexpr vec(const T& x, const T& y, const T& z, const T& w) noexcept
    : impl_({{ x, y, z, w }}) {
  }

  explicit constexpr vec(const T& s) noexcept
    : impl_({{ s, s, s, s }}) {
  }

  constexpr vec(const vec2<T>& xy, const T& z, const T& w) noexcept
    : impl_({{ xy[0], xy[1], z, w }}) {
  }

  constexpr vec(const vec3<T>& xyz, const T& w) noexcept
    : impl_({{ xyz[0], xyz[1], xyz[2], w }}) {
  }

  template<typename U>
  explicit constexpr vec(const vec4<U>& other) noexcept
    : impl_({{
        T(other[0]),
        T(other[1]),
        T(other[2]),
        T(other[3]),
      }}) {
  }

  template<typename U>
  constexpr operator vec4<U>() const noexcept {
    return {
      impl_.data[0],
      impl_.data[1],
      impl_.data[2],
      impl_.data[3],
    };
  }

  static constexpr vec zero() noexcept {
    return { T(0), T(0), T(0), T(0) };
  }

  static constexpr vec x_axis() noexcept {
    return { T(1), T(0), T(0), T(0) };
  }

  static constexpr vec y_axis() noexcept {
    return { T(0), T(1), T(0), T(0) };
  }

  static constexpr vec z_axis() noexcept {
    return { T(0), T(0), T(1), T(0) };
  }

  static constexpr vec w_axis() noexcept {
    return { T(0), T(0), T(0), T(1) };
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

  constexpr T w() const noexcept {
    return impl_.data[3];
  }

  void set_w(const T& w) noexcept {
    impl_.data[3] = w;
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

  constexpr T a() const noexcept {
    return impl_.data[3];
  }

  void set_a(const T& a) noexcept {
    impl_.data[3] = a;
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
    return{ r(), g() };
  }

  void set_rg(const vec2<T>& rg) noexcept {
    set_r(rg[0]);
    set_g(rg[1]);
  }

  void set_rg(const T& r, const T& g) noexcept {
    set_r(r);
    set_g(g);
  }

  constexpr vec3<T> xyz() const noexcept {
    return { x(), y(), z() };
  }

  void set_xyz(const vec3<T>& xyz) noexcept {
    set_x(xyz[0]);
    set_y(xyz[1]);
    set_z(xyz[2]);
  }

  void set_xyz(const T& x, const T& y, const T& z) noexcept {
    set_x(x);
    set_y(y);
    set_z(z);
  }

  constexpr vec3<T> rgb() const noexcept {
    return { r(), g(), b() };
  }

  void set_rgb(const vec3<T>& rgb) noexcept {
    set_r(rgb[0]);
    set_g(rgb[1]);
    set_b(rgb[2]);
  }

  void set_rgb(const T& r, const T& g, const T& b) noexcept {
    set_r(r);
    set_g(g);
    set_b(b);
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
    ++impl_.data[3];
    return *this;
  }

  vec& operator--() noexcept {
    --impl_.data[0];
    --impl_.data[1];
    --impl_.data[2];
    --impl_.data[3];
    return *this;
  }

  vec operator++(int) noexcept {
    return {
      impl_.data[0]++,
      impl_.data[1]++,
      impl_.data[2]++,
      impl_.data[3]++,
    };
  }

  vec operator--(int) noexcept {
    return {
      impl_.data[0]--,
      impl_.data[1]--,
      impl_.data[2]--,
      impl_.data[3]--,
    };
  }

  template<typename U>
  vec& operator+=(const U& other) noexcept {
    impl_.data[0] += other;
    impl_.data[1] += other;
    impl_.data[2] += other;
    impl_.data[3] += other;
    return *this;
  }

  template<typename U>
  vec& operator+=(const vec4<U>& other) noexcept {
    impl_.data[0] += other[0];
    impl_.data[1] += other[1];
    impl_.data[2] += other[2];
    impl_.data[3] += other[3];
    return *this;
  }

  template<typename U>
  vec& operator-=(const U& other) noexcept {
    impl_.data[0] -= other;
    impl_.data[1] -= other;
    impl_.data[2] -= other;
    impl_.data[3] -= other;
    return *this;
  }

  template<typename U>
  vec& operator-=(const vec4<U>& other) noexcept {
    impl_.data[0] -= other[0];
    impl_.data[1] -= other[1];
    impl_.data[2] -= other[2];
    impl_.data[3] -= other[3];
    return *this;
  }

  template<typename U>
  vec& operator*=(const U& other) noexcept {
    impl_.data[0] *= other;
    impl_.data[1] *= other;
    impl_.data[2] *= other;
    impl_.data[3] *= other;
    return *this;
  }

  template<typename U>
  vec& operator*=(const vec4<U>& other) noexcept {
    impl_.data[0] *= other[0];
    impl_.data[1] *= other[1];
    impl_.data[2] *= other[2];
    impl_.data[3] *= other[3];
    return *this;
  }

  template<typename U>
  vec& operator*=(const mat<U, 4, 4>& other) noexcept {
    return *this = *this * other;
  }

  template<typename U>
  vec& operator/=(const U& other) noexcept {
    impl_.data[0] /= other;
    impl_.data[1] /= other;
    impl_.data[2] /= other;
    impl_.data[3] /= other;
    return *this;
  }

  template<typename U>
  vec& operator/=(const vec4<U>& other) noexcept {
    impl_.data[0] /= other[0];
    impl_.data[1] /= other[1];
    impl_.data[2] /= other[2];
    impl_.data[3] /= other[3];
    return *this;
  }

  template<typename U>
  vec& operator%=(const U& other) noexcept {
    impl_.data[0] %= other;
    impl_.data[1] %= other;
    impl_.data[2] %= other;
    impl_.data[3] %= other;
    return *this;
  }

  template<typename U>
  vec& operator%=(const vec4<U>& other) noexcept {
    impl_.data[0] %= other[0];
    impl_.data[1] %= other[1];
    impl_.data[2] %= other[2];
    impl_.data[3] %= other[3];
    return *this;
  }

  template<typename U>
  vec& operator&=(const U& other) noexcept {
    impl_.data[0] &= other;
    impl_.data[1] &= other;
    impl_.data[2] &= other;
    impl_.data[3] &= other;
    return *this;
  }

  template<typename U>
  vec& operator&=(const vec4<U>& other) noexcept {
    impl_.data[0] &= other[0];
    impl_.data[1] &= other[1];
    impl_.data[2] &= other[2];
    impl_.data[3] &= other[3];
    return *this;
  }

  template<typename U>
  vec& operator|=(const U& other) noexcept {
    impl_.data[0] |= other;
    impl_.data[1] |= other;
    impl_.data[2] |= other;
    impl_.data[3] |= other;
    return *this;
  }

  template<typename U>
  vec& operator|=(const vec4<U>& other) noexcept {
    impl_.data[0] |= other[0];
    impl_.data[1] |= other[1];
    impl_.data[2] |= other[2];
    impl_.data[3] |= other[3];
    return *this;
  }

  template<typename U>
  vec& operator^=(const U& other) noexcept {
    impl_.data[0] ^= other;
    impl_.data[1] ^= other;
    impl_.data[2] ^= other;
    impl_.data[3] ^= other;
    return *this;
  }

  template<typename U>
  vec& operator^=(const vec4<U>& other) noexcept {
    impl_.data[0] ^= other[0];
    impl_.data[1] ^= other[1];
    impl_.data[2] ^= other[2];
    impl_.data[3] ^= other[3];
    return *this;
  }

  template<typename U>
  vec& operator<<=(const U& other) noexcept {
    impl_.data[0] <<= other;
    impl_.data[1] <<= other;
    impl_.data[2] <<= other;
    impl_.data[3] <<= other;
    return *this;
  }

  template<typename U>
  vec& operator<<=(const vec4<U>& other) noexcept {
    impl_.data[0] <<= other[0];
    impl_.data[1] <<= other[1];
    impl_.data[2] <<= other[2];
    impl_.data[3] <<= other[3];
    return *this;
  }

  template<typename U>
  vec& operator>>=(const U& other) noexcept {
    impl_.data[0] >>= other;
    impl_.data[1] >>= other;
    impl_.data[2] >>= other;
    impl_.data[3] >>= other;
    return *this;
  }

  template<typename U>
  vec& operator>>=(const vec4<U>& other) noexcept {
    impl_.data[0] >>= other[0];
    impl_.data[1] >>= other[1];
    impl_.data[2] >>= other[2];
    impl_.data[3] >>= other[3];
    return *this;
  }

private:
  template<typename U, int C, int R>
  friend class mat;

  static constexpr vec extend_(
      const vec2<T>& v,
      const T& z,
      const T& w) noexcept {
    return vec(v, z, w);
  }

  static constexpr vec extend_(
      const vec3<T>& v,
      const T&,
      const T& w) noexcept {
    return vec(v, w);
  }

  static constexpr vec extend_(
      const vec4<T>& v,
      const T&,
      const T&) noexcept {
    return v;
  }
};

template<typename T>
inline constexpr auto operator+(const vec4<T>& v) noexcept {
  return vec4<decltype(+v[0])>(+v[0], +v[1], +v[2], +v[3]);
}

template<typename T>
inline constexpr auto operator-(const vec4<T>& v) noexcept {
  return vec4<decltype(-v[0])>(-v[0], -v[1], -v[2], -v[3]);
}

template<typename T>
inline constexpr auto operator~(const vec4<T>& v) noexcept {
  return vec4<decltype(~v[0])>(~v[0], ~v[1], ~v[2], ~v[3]);
}

template<typename T, typename U>
inline constexpr auto operator+(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs + rhs[0])>{
    lhs + rhs[0],
    lhs + rhs[1],
    lhs + rhs[2],
    lhs + rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator+(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] + rhs)>{
    lhs[0] + rhs,
    lhs[1] + rhs,
    lhs[2] + rhs,
    lhs[3] + rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator+(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] + rhs[0])>{
    lhs[0] + rhs[0],
    lhs[1] + rhs[1],
    lhs[2] + rhs[2],
    lhs[3] + rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs - rhs[0])>{
    lhs - rhs[0],
    lhs - rhs[1],
    lhs - rhs[2],
    lhs - rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] - rhs)>{
    lhs[0] - rhs,
    lhs[1] - rhs,
    lhs[2] - rhs,
    lhs[3] - rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] - rhs[0])>{
    lhs[0] - rhs[0],
    lhs[1] - rhs[1],
    lhs[2] - rhs[2],
    lhs[3] - rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs * rhs[0])>{
    lhs * rhs[0],
    lhs * rhs[1],
    lhs * rhs[2],
    lhs * rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] * rhs)>{
    lhs[0] * rhs,
    lhs[1] * rhs,
    lhs[2] * rhs,
    lhs[3] * rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] * rhs[0])>{
    lhs[0] * rhs[0],
    lhs[1] * rhs[1],
    lhs[2] * rhs[2],
    lhs[3] * rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs / rhs[0])>{
    lhs / rhs[0],
    lhs / rhs[1],
    lhs / rhs[2],
    lhs / rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] / rhs)>{
    lhs[0] / rhs,
    lhs[1] / rhs,
    lhs[2] / rhs,
    lhs[3] / rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] / rhs[0])>{
    lhs[0] / rhs[0],
    lhs[1] / rhs[1],
    lhs[2] / rhs[2],
    lhs[3] / rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs % rhs[0])>{
    lhs % rhs[0],
    lhs % rhs[1],
    lhs % rhs[2],
    lhs % rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] % rhs)>{
    lhs[0] % rhs,
    lhs[1] % rhs,
    lhs[2] % rhs,
    lhs[3] % rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] % rhs[0])>{
    lhs[0] % rhs[0],
    lhs[1] % rhs[1],
    lhs[2] % rhs[2],
    lhs[3] % rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs & rhs[0])>{
    lhs & rhs[0],
    lhs & rhs[1],
    lhs & rhs[2],
    lhs & rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] & rhs)>{
    lhs[0] & rhs,
    lhs[1] & rhs,
    lhs[2] & rhs,
    lhs[3] & rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] & rhs[0])>{
    lhs[0] & rhs[0],
    lhs[1] & rhs[1],
    lhs[2] & rhs[2],
    lhs[3] & rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs | rhs[0])>{
    lhs | rhs[0],
    lhs | rhs[1],
    lhs | rhs[2],
    lhs | rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] | rhs)>{
    lhs[0] | rhs,
    lhs[1] | rhs,
    lhs[2] | rhs,
    lhs[3] | rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] | rhs[0])>{
    lhs[0] | rhs[0],
    lhs[1] | rhs[1],
    lhs[2] | rhs[2],
    lhs[3] | rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs ^ rhs[0])>{
    lhs ^ rhs[0],
    lhs ^ rhs[1],
    lhs ^ rhs[2],
    lhs ^ rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] ^ rhs)>{
    lhs[0] ^ rhs,
    lhs[1] ^ rhs,
    lhs[2] ^ rhs,
    lhs[3] ^ rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] ^ rhs[0])>{
    lhs[0] ^ rhs[0],
    lhs[1] ^ rhs[1],
    lhs[2] ^ rhs[2],
    lhs[3] ^ rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs << rhs[0])>{
    lhs << rhs[0],
    lhs << rhs[1],
    lhs << rhs[2],
    lhs << rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] << rhs)>{
    lhs[0] << rhs,
    lhs[1] << rhs,
    lhs[2] << rhs,
    lhs[3] << rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] << rhs[0])>{
    lhs[0] << rhs[0],
    lhs[1] << rhs[1],
    lhs[2] << rhs[2],
    lhs[3] << rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const T& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs >> rhs[0])>{
    lhs >> rhs[0],
    lhs >> rhs[1],
    lhs >> rhs[2],
    lhs >> rhs[3],
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const vec4<T>& lhs,
    const U& rhs) noexcept {
  return vec4<decltype(lhs[0] >> rhs)>{
    lhs[0] >> rhs,
    lhs[1] >> rhs,
    lhs[2] >> rhs,
    lhs[3] >> rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return vec4<decltype(lhs[0] >> rhs[0])>{
    lhs[0] >> rhs[0],
    lhs[1] >> rhs[1],
    lhs[2] >> rhs[2],
    lhs[3] >> rhs[3],
  };
}

template<typename T, typename U>
inline constexpr bool operator==(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return lhs[0] == rhs[0]
      && lhs[1] == rhs[1]
      && lhs[2] == rhs[2]
      && lhs[3] == rhs[3];
}

template<typename T, typename U>
inline constexpr bool operator!=(
    const vec4<T>& lhs,
    const vec4<U>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

namespace math
{
  template<typename T>
  inline auto sin(const vec4<T>& v) noexcept {
    return vec4<decltype(math::sin(v[0]))>{
      math::sin(v[0]),
      math::sin(v[1]),
      math::sin(v[2]),
      math::sin(v[3]),
    };
  }

  template<typename T>
  inline auto cos(const vec4<T>& v) noexcept {
    return vec4<decltype(math::cos(v[0]))>{
      math::cos(v[0]),
      math::cos(v[1]),
      math::cos(v[2]),
      math::cos(v[3]),
    };
  }

  template<typename T>
  inline void sincos(
      const vec4<T>& v,
      decltype(math::sin(v))& sin_result,
      decltype(math::cos(v))& cos_result) noexcept {
    math::sincos(v[0], sin_result[0], cos_result[0]);
    math::sincos(v[1], sin_result[1], cos_result[1]);
    math::sincos(v[2], sin_result[2], cos_result[2]);
    math::sincos(v[3], sin_result[3], cos_result[3]);
  }

  template<typename T>
  inline auto exp(const vec4<T>& v) noexcept {
    return vec4<decltype(math::exp(v[0]))>{
      math::exp(v[0]),
      math::exp(v[1]),
      math::exp(v[2]),
      math::exp(v[3]),
    };
  }

  template<typename T>
  inline auto log(const vec4<T>& v) noexcept {
    return vec4<decltype(math::log(v[0]))>{
      math::log(v[0]),
      math::log(v[1]),
      math::log(v[2]),
      math::log(v[3]),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec4<T>& base,
      const U& exponent) noexcept {
    return vec4<decltype(math::pow(base[0], exponent))>{
      math::pow(base[0], exponent),
      math::pow(base[1], exponent),
      math::pow(base[2], exponent),
      math::pow(base[3], exponent),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec4<T>& base,
      const vec4<U>& exponent) noexcept {
    return vec4<decltype(math::pow(base[0], exponent[0]))>{
      math::pow(base[0], exponent[0]),
      math::pow(base[1], exponent[1]),
      math::pow(base[2], exponent[2]),
      math::pow(base[3], exponent[3]),
    };
  }

  template<typename T>
  inline auto recip(const vec4<T>& v) noexcept {
    return vec4<decltype(math::recip(v[0]))>{
      math::recip(v[0]),
      math::recip(v[1]),
      math::recip(v[2]),
      math::recip(v[3]),
    };
  }

  template<typename T>
  inline auto sqrt(const vec4<T>& v) noexcept {
    return vec4<decltype(math::sqrt(v[0]))>{
      math::sqrt(v[0]),
      math::sqrt(v[1]),
      math::sqrt(v[2]),
      math::sqrt(v[3]),
    };
  }

  template<typename T>
  inline auto rsqrt(const vec4<T>& v) noexcept {
    return vec4<decltype(math::rsqrt(v[0]))>{
      math::rsqrt(v[0]),
      math::rsqrt(v[1]),
      math::rsqrt(v[2]),
      math::rsqrt(v[3]),
    };
  }

  template<typename T>
  inline auto min(
      const vec4<T>& v1,
      const vec4<T>& v2) noexcept {
    return vec4<decltype(math::min(v1[0], v2[0]))>{
      math::min(v1[0], v2[0]),
      math::min(v1[1], v2[1]),
      math::min(v1[2], v2[2]),
      math::min(v1[3], v2[3]),
    };
  }

  template<typename T>
  inline auto max(
      const vec4<T>& v1,
      const vec4<T>& v2) noexcept {
    return vec4<decltype(math::max(v1[0], v2[0]))>{
      math::max(v1[0], v2[0]),
      math::max(v1[1], v2[1]),
      math::max(v1[2], v2[2]),
      math::max(v1[3], v2[3]),
    };
  }

  template<typename T>
  inline auto abs(const vec4<T>& v) noexcept {
    return vec4<decltype(math::abs(v[0]))>{
      math::abs(v[0]),
      math::abs(v[1]),
      math::abs(v[2]),
      math::abs(v[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto dot(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return lhs[0] * rhs[0]
        + lhs[1] * rhs[1]
        + lhs[2] * rhs[2]
        + lhs[3] * rhs[3];
  }

  template<typename T>
  inline auto length2(const vec4<T>& v) noexcept {
    return math::length2(v[0])
        + math::length2(v[1])
        + math::length2(v[2])
        + math::length2(v[3]);
  }

  template<typename T>
  inline auto length(const vec4<T>& v) noexcept {
    return math::sqrt(math::length2(v));
  }

  template<typename T>
  inline auto normalize(const vec4<T>& v) noexcept {
    return vec4<decltype(math::length(v))>(v) / math::length(v);
  }

  template<typename T, typename U>
  inline constexpr auto comp_mult(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::comp_mult(lhs[0], rhs[0]))>{
      math::comp_mult(lhs[0], rhs[0]),
      math::comp_mult(lhs[1], rhs[1]),
      math::comp_mult(lhs[2], rhs[2]),
      math::comp_mult(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto select(
      const vec4<T>& condition,
      const vec4<U>& value,
      const vec4<U>& otherwise = vec4<U>::zero()) noexcept {
    return vec4<decltype(math::select(condition[0], value[0], otherwise[0]))>{
      math::select(condition[0], value[0], otherwise[0]),
      math::select(condition[1], value[1], otherwise[1]),
      math::select(condition[2], value[2], otherwise[2]),
      math::select(condition[3], value[3], otherwise[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto less(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::less(lhs[0], rhs[0]))>{
      math::less(lhs[0], rhs[0]),
      math::less(lhs[1], rhs[1]),
      math::less(lhs[2], rhs[2]),
      math::less(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto less_equal(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::less_equal(lhs[0], rhs[0]))>{
      math::less_equal(lhs[0], rhs[0]),
      math::less_equal(lhs[1], rhs[1]),
      math::less_equal(lhs[2], rhs[2]),
      math::less_equal(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto greater(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::greater(lhs[0], rhs[0]))>{
      math::greater(lhs[0], rhs[0]),
      math::greater(lhs[1], rhs[1]),
      math::greater(lhs[2], rhs[2]),
      math::greater(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto greater_equal(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::greater_equal(lhs[0], rhs[0]))>{
      math::greater_equal(lhs[0], rhs[0]),
      math::greater_equal(lhs[1], rhs[1]),
      math::greater_equal(lhs[2], rhs[2]),
      math::greater_equal(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto equal(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::equal(lhs[0], rhs[0]))>{
      math::equal(lhs[0], rhs[0]),
      math::equal(lhs[1], rhs[1]),
      math::equal(lhs[2], rhs[2]),
      math::equal(lhs[3], rhs[3]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto not_equal(
      const vec4<T>& lhs,
      const vec4<U>& rhs) noexcept {
    return vec4<decltype(math::not_equal(lhs[0], rhs[0]))>{
      math::not_equal(lhs[0], rhs[0]),
      math::not_equal(lhs[1], rhs[1]),
      math::not_equal(lhs[2], rhs[2]),
      math::not_equal(lhs[3], rhs[3]),
    };
  }

  template<typename T>
  inline auto axis_angle(const vec3<T>& v) noexcept {
    using U = decltype(math::length(v));
    const auto angle = math::length(v);
    const auto axis = math::select(
        math::not_equal(angle, U(0)),
        vec3<U>(v) / angle,
        vec3<U>::z_axis());
    return vec4<U>(axis, angle);
  }

  template<typename T>
  inline auto axis_angle(const T& x, const T& y, const T& z) noexcept {
    return math::axis_angle(vec3<T>(x, y, z));
  }
}

}
