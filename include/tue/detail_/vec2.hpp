//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../math.hpp"
#include "../simd.hpp"
#include "../vec.hpp"

namespace tue {

template<typename T, int C, int R>
class mat;

template<typename T>
class vec<T, 2>
{
public:
  using component_type = T;

  static constexpr int component_count = 2;

private:
  struct { T data[2]; } impl_;

public:
  vec() noexcept = default;

  constexpr vec(const T& x, const T& y) noexcept
    : impl_({{ x, y }}) {
  }

  explicit constexpr vec(const T& s) noexcept
    : impl_({{ s, s }}) {
  }

  explicit constexpr vec(const vec3<T>& other) noexcept
    : impl_({{ other[0], other[1] }}) {
  }

  explicit constexpr vec(const vec4<T>& other) noexcept
    : impl_({{ other[0], other[1] }}) {
  }

  template<typename U>
  explicit constexpr vec(const vec2<U>& other) noexcept
    : impl_({{
        T(other[0]),
        T(other[1]),
      }}) {
  }

  template<typename U>
  constexpr operator vec2<U>() const noexcept {
    return {
      impl_.data[0],
      impl_.data[1],
    };
  }

  static constexpr vec zero() noexcept {
    return { T(0), T(0) };
  }

  static constexpr vec x_axis() noexcept {
    return { T(1), T(0) };
  }

  static constexpr vec y_axis() noexcept {
    return { T(0), T(1) };
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
    return *this;
  }

  vec& operator--() noexcept {
    --impl_.data[0];
    --impl_.data[1];
    return *this;
  }

  vec operator++(int) noexcept {
    return {
      impl_.data[0]++,
      impl_.data[1]++,
    };
  }

  vec operator--(int) noexcept {
    return {
      impl_.data[0]--,
      impl_.data[1]--,
    };
  }

  template<typename U>
  vec& operator+=(const U& other) noexcept {
    impl_.data[0] += other;
    impl_.data[1] += other;
    return *this;
  }

  template<typename U>
  vec& operator+=(const vec2<U>& other) noexcept {
    impl_.data[0] += other[0];
    impl_.data[1] += other[1];
    return *this;
  }

  template<typename U>
  vec& operator-=(const U& other) noexcept {
    impl_.data[0] -= other;
    impl_.data[1] -= other;
    return *this;
  }

  template<typename U>
  vec& operator-=(const vec2<U>& other) noexcept {
    impl_.data[0] -= other[0];
    impl_.data[1] -= other[1];
    return *this;
  }

  template<typename U>
  vec& operator*=(const U& other) noexcept {
    impl_.data[0] *= other;
    impl_.data[1] *= other;
    return *this;
  }

  template<typename U>
  vec& operator*=(const vec2<U>& other) noexcept {
    impl_.data[0] *= other[0];
    impl_.data[1] *= other[1];
    return *this;
  }

  template<typename U>
  vec& operator*=(const mat<U, 2, 2>& other) noexcept {
    return *this = *this * other;
  }

  template<typename U>
  vec& operator/=(const U& other) noexcept {
    impl_.data[0] /= other;
    impl_.data[1] /= other;
    return *this;
  }

  template<typename U>
  vec& operator/=(const vec2<U>& other) noexcept {
    impl_.data[0] /= other[0];
    impl_.data[1] /= other[1];
    return *this;
  }

  template<typename U>
  vec& operator%=(const U& other) noexcept {
    impl_.data[0] %= other;
    impl_.data[1] %= other;
    return *this;
  }

  template<typename U>
  vec& operator%=(const vec2<U>& other) noexcept {
    impl_.data[0] %= other[0];
    impl_.data[1] %= other[1];
    return *this;
  }

  template<typename U>
  vec& operator&=(const U& other) noexcept {
    impl_.data[0] &= other;
    impl_.data[1] &= other;
    return *this;
  }

  template<typename U>
  vec& operator&=(const vec2<U>& other) noexcept {
    impl_.data[0] &= other[0];
    impl_.data[1] &= other[1];
    return *this;
  }

  template<typename U>
  vec& operator|=(const U& other) noexcept {
    impl_.data[0] |= other;
    impl_.data[1] |= other;
    return *this;
  }

  template<typename U>
  vec& operator|=(const vec2<U>& other) noexcept {
    impl_.data[0] |= other[0];
    impl_.data[1] |= other[1];
    return *this;
  }

  template<typename U>
  vec& operator^=(const U& other) noexcept {
    impl_.data[0] ^= other;
    impl_.data[1] ^= other;
    return *this;
  }

  template<typename U>
  vec& operator^=(const vec2<U>& other) noexcept {
    impl_.data[0] ^= other[0];
    impl_.data[1] ^= other[1];
    return *this;
  }

  template<typename U>
  vec& operator<<=(const U& other) noexcept {
    impl_.data[0] <<= other;
    impl_.data[1] <<= other;
    return *this;
  }

  template<typename U>
  vec& operator<<=(const vec2<U>& other) noexcept {
    impl_.data[0] <<= other[0];
    impl_.data[1] <<= other[1];
    return *this;
  }

  template<typename U>
  vec& operator>>=(const U& other) noexcept {
    impl_.data[0] >>= other;
    impl_.data[1] >>= other;
    return *this;
  }

  template<typename U>
  vec& operator>>=(const vec2<U>& other) noexcept {
    impl_.data[0] >>= other[0];
    impl_.data[1] >>= other[1];
    return *this;
  }
};

template<typename T>
inline constexpr auto operator+(const vec2<T>& v) noexcept {
  return vec2<decltype(+v[0])>(+v[0], +v[1]);
}

template<typename T>
inline constexpr auto operator-(const vec2<T>& v) noexcept {
  return vec2<decltype(-v[0])>(-v[0], -v[1]);
}

template<typename T>
inline constexpr auto operator~(const vec2<T>& v) noexcept {
  return vec2<decltype(~v[0])>(~v[0], ~v[1]);
}

template<typename T, typename U>
inline constexpr auto operator+(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs + rhs[0])>{
    lhs + rhs[0],
    lhs + rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator+(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] + rhs)>{
    lhs[0] + rhs,
    lhs[1] + rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator+(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] + rhs[0])>{
    lhs[0] + rhs[0],
    lhs[1] + rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs - rhs[0])>{
    lhs - rhs[0],
    lhs - rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] - rhs)>{
    lhs[0] - rhs,
    lhs[1] - rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator-(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] - rhs[0])>{
    lhs[0] - rhs[0],
    lhs[1] - rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs * rhs[0])>{
    lhs * rhs[0],
    lhs * rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] * rhs)>{
    lhs[0] * rhs,
    lhs[1] * rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] * rhs[0])>{
    lhs[0] * rhs[0],
    lhs[1] * rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs / rhs[0])>{
    lhs / rhs[0],
    lhs / rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] / rhs)>{
    lhs[0] / rhs,
    lhs[1] / rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator/(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] / rhs[0])>{
    lhs[0] / rhs[0],
    lhs[1] / rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs % rhs[0])>{
    lhs % rhs[0],
    lhs % rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] % rhs)>{
    lhs[0] % rhs,
    lhs[1] % rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator%(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] % rhs[0])>{
    lhs[0] % rhs[0],
    lhs[1] % rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs & rhs[0])>{
    lhs & rhs[0],
    lhs & rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] & rhs)>{
    lhs[0] & rhs,
    lhs[1] & rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator&(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] & rhs[0])>{
    lhs[0] & rhs[0],
    lhs[1] & rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs | rhs[0])>{
    lhs | rhs[0],
    lhs | rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] | rhs)>{
    lhs[0] | rhs,
    lhs[1] | rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator|(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] | rhs[0])>{
    lhs[0] | rhs[0],
    lhs[1] | rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs ^ rhs[0])>{
    lhs ^ rhs[0],
    lhs ^ rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] ^ rhs)>{
    lhs[0] ^ rhs,
    lhs[1] ^ rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator^(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] ^ rhs[0])>{
    lhs[0] ^ rhs[0],
    lhs[1] ^ rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs << rhs[0])>{
    lhs << rhs[0],
    lhs << rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] << rhs)>{
    lhs[0] << rhs,
    lhs[1] << rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator<<(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] << rhs[0])>{
    lhs[0] << rhs[0],
    lhs[1] << rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const T& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs >> rhs[0])>{
    lhs >> rhs[0],
    lhs >> rhs[1],
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const vec2<T>& lhs,
    const U& rhs) noexcept {
  return vec2<decltype(lhs[0] >> rhs)>{
    lhs[0] >> rhs,
    lhs[1] >> rhs,
  };
}

template<typename T, typename U>
inline constexpr auto operator>>(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return vec2<decltype(lhs[0] >> rhs[0])>{
    lhs[0] >> rhs[0],
    lhs[1] >> rhs[1],
  };
}

template<typename T, typename U>
inline constexpr bool operator==(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return lhs[0] == rhs[0]
      && lhs[1] == rhs[1];
}

template<typename T, typename U>
inline constexpr bool operator!=(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

namespace math
{
  template<typename T>
  inline auto sin(const vec2<T>& v) noexcept {
    return vec2<decltype(math::sin(v[0]))>{
      math::sin(v[0]),
      math::sin(v[1]),
    };
  }

  template<typename T>
  inline auto cos(const vec2<T>& v) noexcept {
    return vec2<decltype(math::cos(v[0]))>{
      math::cos(v[0]),
      math::cos(v[1]),
    };
  }

  template<typename T>
  inline void sincos(
      const vec2<T>& v,
      decltype(math::sin(v))& sin_result,
      decltype(math::cos(v))& cos_result) noexcept {
    math::sincos(v[0], sin_result[0], cos_result[0]);
    math::sincos(v[1], sin_result[1], cos_result[1]);
  }

  template<typename T>
  inline auto exp(const vec2<T>& v) noexcept {
    return vec2<decltype(math::exp(v[0]))>{
      math::exp(v[0]),
      math::exp(v[1]),
    };
  }

  template<typename T>
  inline auto log(const vec2<T>& v) noexcept {
    return vec2<decltype(math::log(v[0]))>{
      math::log(v[0]),
      math::log(v[1]),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec2<T>& base,
      const U& exponent) noexcept {
    return vec2<decltype(math::pow(base[0], exponent))>{
      math::pow(base[0], exponent),
      math::pow(base[1], exponent),
    };
  }

  template<typename T, typename U>
  inline auto pow(
      const vec2<T>& base,
      const vec2<U>& exponent) noexcept {
    return vec2<decltype(math::pow(base[0], exponent[0]))>{
      math::pow(base[0], exponent[0]),
      math::pow(base[1], exponent[1]),
    };
  }

  template<typename T>
  inline auto recip(const vec2<T>& v) noexcept {
    return vec2<decltype(math::recip(v[0]))>{
      math::recip(v[0]),
      math::recip(v[1]),
    };
  }

  template<typename T>
  inline auto sqrt(const vec2<T>& v) noexcept {
    return vec2<decltype(math::sqrt(v[0]))>{
      math::sqrt(v[0]),
      math::sqrt(v[1]),
    };
  }

  template<typename T>
  inline auto rsqrt(const vec2<T>& v) noexcept {
    return vec2<decltype(math::rsqrt(v[0]))>{
      math::rsqrt(v[0]),
      math::rsqrt(v[1]),
    };
  }

  template<typename T>
  inline auto min(
      const vec2<T>& v1,
      const vec2<T>& v2) noexcept {
    return vec2<decltype(math::min(v1[0], v2[0]))>{
      math::min(v1[0], v2[0]),
      math::min(v1[1], v2[1]),
    };
  }

  template<typename T>
  inline auto max(
      const vec2<T>& v1,
      const vec2<T>& v2) noexcept {
    return vec2<decltype(math::max(v1[0], v2[0]))>{
      math::max(v1[0], v2[0]),
      math::max(v1[1], v2[1]),
    };
  }

  template<typename T>
  inline auto abs(const vec2<T>& v) noexcept {
    return vec2<decltype(math::abs(v[0]))>{
      math::abs(v[0]),
      math::abs(v[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto dot(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return lhs[0] * rhs[0]
        + lhs[1] * rhs[1];
  }

  template<typename T>
  inline auto length2(const vec2<T>& v) noexcept {
    return math::length2(v[0])
        + math::length2(v[1]);
  }

  template<typename T>
  inline auto length(const vec2<T>& v) noexcept {
    return math::sqrt(math::length2(v));
  }

  template<typename T>
  inline auto normalize(const vec2<T>& v) noexcept {
    return vec2<decltype(math::length(v))>(v) / math::length(v);
  }

  template<typename T, typename U>
  inline constexpr auto comp_mult(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::comp_mult(lhs[0], rhs[0]))>{
      math::comp_mult(lhs[0], rhs[0]),
      math::comp_mult(lhs[1], rhs[1]),
    };
  }

  template<typename T>
  inline constexpr vec2<T> transpose(const vec2<T>& v) noexcept {
    return v;
  }

  template<typename T, typename U>
  inline constexpr auto select(
      const T& condition,
      const vec2<U>& value,
      const vec2<U>& otherwise = vec2<U>::zero()) noexcept {
    return vec2<decltype(math::select(condition, value[0], otherwise[0]))>{
      math::select(condition, value[0], otherwise[0]),
      math::select(condition, value[1], otherwise[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto select(
      const vec2<T>& condition,
      const vec2<U>& value,
      const vec2<U>& otherwise = vec2<U>::zero()) noexcept {
    return vec2<decltype(math::select(condition[0], value[0], otherwise[0]))>{
      math::select(condition[0], value[0], otherwise[0]),
      math::select(condition[1], value[1], otherwise[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto less(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::less(lhs[0], rhs[0]))>{
      math::less(lhs[0], rhs[0]),
      math::less(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto less_equal(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::less_equal(lhs[0], rhs[0]))>{
      math::less_equal(lhs[0], rhs[0]),
      math::less_equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto greater(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::greater(lhs[0], rhs[0]))>{
      math::greater(lhs[0], rhs[0]),
      math::greater(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto greater_equal(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::greater_equal(lhs[0], rhs[0]))>{
      math::greater_equal(lhs[0], rhs[0]),
      math::greater_equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto equal(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::equal(lhs[0], rhs[0]))>{
      math::equal(lhs[0], rhs[0]),
      math::equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U>
  inline constexpr auto not_equal(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept {
    return vec2<decltype(math::not_equal(lhs[0], rhs[0]))>{
      math::not_equal(lhs[0], rhs[0]),
      math::not_equal(lhs[1], rhs[1]),
    };
  }
}

namespace detail_
{
    template<typename T>
    struct vec_utils<T, 2>
    {
        static constexpr vec<T, 2> resize(
            const vec<T, 2>& v, const T&, const T&) noexcept
        {
            return v;
        }

        static constexpr vec<T, 2> resize(
            const vec<T, 3>& v, const T&, const T&) noexcept
        {
            return vec<T, 2>(v);
        }

        static constexpr vec<T, 2> resize(
            const vec<T, 4>& v, const T&, const T&) noexcept
        {
            return vec<T, 2>(v);
        }
    };
}

}
