//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstdint>

#include "../bool.hpp"
#include "../math.hpp"
#include "../simd.hpp"

namespace tue {

template<>
class simd<float, 4>
{
public:
  using component_type = float;

  static constexpr int component_count = 4;

private:
  float x, y, z, w;

public:
  simd() noexcept = default;

  simd(float x, float y, float z, float w) noexcept
    : x(x), y(y), z(z), w(w) {
  }

  explicit simd(float s) noexcept
    : x(s), y(s), z(s), w(s) {
  }

  static simd zero() noexcept {
    return float32x4(0.0f);
  }

  static float32x4 load(const float* array) noexcept {
    return { array[0], array[1], array[2], array[3] };
  }

  static float32x4 loadu(const float* array) noexcept {
    return load(array);
  }

  void store(float* destination) const noexcept {
    destination[0] = x;
    destination[1] = y;
    destination[2] = z;
    destination[3] = w;
  }

  void storeu(float* destination) const noexcept {
    store(destination);
  }

  float32x4 operator+() const noexcept {
    return { +x, +y, +z, +w };
  }

  float32x4 operator-() const noexcept {
    return { -x, -y, -z, -w };
  }

  float32x4 operator+(const float32x4& other) const noexcept {
    return {
      x + other.x,
      y + other.y,
      z + other.z,
      w + other.w,
    };
  }

  float32x4 operator-(const float32x4& other) const noexcept {
    return {
      x - other.x,
      y - other.y,
      z - other.z,
      w - other.w,
    };
  }

  float32x4 operator*(const float32x4& other) const noexcept {
    return {
      x * other.x,
      y * other.y,
      z * other.z,
      w * other.w,
    };
  }

  float32x4 operator/(const float32x4& other) const noexcept {
    return {
      x / other.x,
      y / other.y,
      z / other.z,
      w / other.w,
    };
  }

  float32x4& operator++() noexcept {
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
  }

  float32x4& operator--() noexcept {
    --x;
    --y;
    --z;
    --w;
    return *this;
  }

  float32x4 operator++(int) noexcept {
    return { x++, y++, z++, w++ };
  }

  float32x4 operator--(int) noexcept {
    return { x--, y--, z--, w-- };
  }

  float32x4& operator+=(const float32x4& other) noexcept {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  float32x4& operator-=(const float32x4& other) noexcept {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }

  float32x4& operator*=(const float32x4& other) noexcept {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
  }

  float32x4& operator/=(const float32x4& other) noexcept {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
  }

  bool operator==(const float32x4& other) const noexcept {
    return x == other.x
        && y == other.y
        && z == other.z
        && w == other.w;
  }

  bool operator!=(const float32x4& other) const noexcept {
    return !operator==(other);
  }
};

namespace math
{
  inline float32x4 sin(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::sin(f[0]),
      math::sin(f[1]),
      math::sin(f[2]),
      math::sin(f[3]),
    };
  }

  inline float32x4 cos(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::cos(f[0]),
      math::cos(f[1]),
      math::cos(f[2]),
      math::cos(f[3]),
    };
  }

  inline void sincos(
      const float32x4& v,
      float32x4& sin_result,
      float32x4& cos_result) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    const auto sf = reinterpret_cast<float*>(&sin_result);
    const auto cf = reinterpret_cast<float*>(&cos_result);
    math::sincos(f[0], sf[0], cf[0]);
    math::sincos(f[1], sf[1], cf[1]);
    math::sincos(f[2], sf[2], cf[2]);
    math::sincos(f[3], sf[3], cf[3]);
  }

  inline float32x4 exp(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::exp(f[0]),
      math::exp(f[1]),
      math::exp(f[2]),
      math::exp(f[3]),
    };
  }

  inline float32x4 log(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::log(f[0]),
      math::log(f[1]),
      math::log(f[2]),
      math::log(f[3]),
    };
  }

  inline float32x4 pow(
      const float32x4& base,
      const float32x4& exponent) noexcept {
    const auto bf = reinterpret_cast<const float*>(&base);
    const auto ef = reinterpret_cast<const float*>(&exponent);
    return {
      math::pow(bf[0], ef[0]),
      math::pow(bf[1], ef[1]),
      math::pow(bf[2], ef[2]),
      math::pow(bf[3], ef[3]),
    };
  }

  inline float32x4 recip(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::recip(f[0]),
      math::recip(f[1]),
      math::recip(f[2]),
      math::recip(f[3]),
    };
  }

  inline float32x4 sqrt(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::sqrt(f[0]),
      math::sqrt(f[1]),
      math::sqrt(f[2]),
      math::sqrt(f[3]),
    };
  }

  inline float32x4 rsqrt(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::rsqrt(f[0]),
      math::rsqrt(f[1]),
      math::rsqrt(f[2]),
      math::rsqrt(f[3]),
    };
  }

  inline float32x4 min(const float32x4& v1, const float32x4& v2) noexcept {
    const auto f1 = reinterpret_cast<const float*>(&v1);
    const auto f2 = reinterpret_cast<const float*>(&v2);
    return {
      math::min(f1[0], f2[0]),
      math::min(f1[1], f2[1]),
      math::min(f1[2], f2[2]),
      math::min(f1[3], f2[3]),
    };
  }

  inline float32x4 max(const float32x4& v1, const float32x4& v2) noexcept {
    const auto f1 = reinterpret_cast<const float*>(&v1);
    const auto f2 = reinterpret_cast<const float*>(&v2);
    return {
      math::max(f1[0], f2[0]),
      math::max(f1[1], f2[1]),
      math::max(f1[2], f2[2]),
      math::max(f1[3], f2[3]),
    };
  }

  inline float32x4 abs(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::abs(f[0]),
      math::abs(f[1]),
      math::abs(f[2]),
      math::abs(f[3]),
    };
  }

  inline float32x4 dot(const float32x4& lhs, const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::dot(lf[0], rf[0]),
      math::dot(lf[1], rf[1]),
      math::dot(lf[2], rf[2]),
      math::dot(lf[3], rf[3]),
    };
  }

  inline float32x4 length2(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::length2(f[0]),
      math::length2(f[1]),
      math::length2(f[2]),
      math::length2(f[3]),
    };
  }

  inline float32x4 length(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::length(f[0]),
      math::length(f[1]),
      math::length(f[2]),
      math::length(f[3]),
    };
  }

  inline float32x4 normalize(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::normalize(f[0]),
      math::normalize(f[1]),
      math::normalize(f[2]),
      math::normalize(f[3]),
    };
  }

  inline float32x4 comp_mult(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::comp_mult(lf[0], rf[0]),
      math::comp_mult(lf[1], rf[1]),
      math::comp_mult(lf[2], rf[2]),
      math::comp_mult(lf[3], rf[3]),
    };
  }

  inline float32x4 transpose(const float32x4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::transpose(f[0]),
      math::transpose(f[1]),
      math::transpose(f[2]),
      math::transpose(f[3]),
    };
  }

  inline float32x4 select(
      const bool32x4& condition,
      const float32x4& value) noexcept {
    const auto c = reinterpret_cast<const std::uint32_t*>(&condition);
    const auto v = reinterpret_cast<const std::uint32_t*>(&value);
    return {
      detail_::binary_float(c[0] & v[0]),
      detail_::binary_float(c[1] & v[1]),
      detail_::binary_float(c[2] & v[2]),
      detail_::binary_float(c[3] & v[3]),
    };
  }

  inline float32x4 select(
      const bool32x4& condition,
      const float32x4& value,
      const float32x4& otherwise) noexcept {
    const auto c = reinterpret_cast<const std::uint32_t*>(&condition);
    const auto v = reinterpret_cast<const std::uint32_t*>(&value);
    const auto o = reinterpret_cast<const std::uint32_t*>(&otherwise);
    return {
      detail_::binary_float((c[0] & v[0]) | (~c[0] & o[0])),
      detail_::binary_float((c[1] & v[1]) | (~c[1] & o[1])),
      detail_::binary_float((c[2] & v[2]) | (~c[2] & o[2])),
      detail_::binary_float((c[3] & v[3]) | (~c[3] & o[3])),
    };
  }

  inline bool32x4 less(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::less(lf[0], rf[0]) ? true32 : false32,
      math::less(lf[1], rf[1]) ? true32 : false32,
      math::less(lf[2], rf[2]) ? true32 : false32,
      math::less(lf[3], rf[3]) ? true32 : false32,
    };
  }

  inline bool32x4 less_equal(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::less_equal(lf[0], rf[0]) ? true32 : false32,
      math::less_equal(lf[1], rf[1]) ? true32 : false32,
      math::less_equal(lf[2], rf[2]) ? true32 : false32,
      math::less_equal(lf[3], rf[3]) ? true32 : false32,
    };
  }

  inline bool32x4 greater(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::greater(lf[0], rf[0]) ? true32 : false32,
      math::greater(lf[1], rf[1]) ? true32 : false32,
      math::greater(lf[2], rf[2]) ? true32 : false32,
      math::greater(lf[3], rf[3]) ? true32 : false32,
    };
  }

  inline bool32x4 greater_equal(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::greater_equal(lf[0], rf[0]) ? true32 : false32,
      math::greater_equal(lf[1], rf[1]) ? true32 : false32,
      math::greater_equal(lf[2], rf[2]) ? true32 : false32,
      math::greater_equal(lf[3], rf[3]) ? true32 : false32,
    };
  }

  inline bool32x4 equal(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::equal(lf[0], rf[0]) ? true32 : false32,
      math::equal(lf[1], rf[1]) ? true32 : false32,
      math::equal(lf[2], rf[2]) ? true32 : false32,
      math::equal(lf[3], rf[3]) ? true32 : false32,
    };
  }

  inline bool32x4 not_equal(
      const float32x4& lhs,
      const float32x4& rhs) noexcept {
    const auto lf = reinterpret_cast<const float*>(&lhs);
    const auto rf = reinterpret_cast<const float*>(&rhs);
    return {
      math::not_equal(lf[0], rf[0]) ? true32 : false32,
      math::not_equal(lf[1], rf[1]) ? true32 : false32,
      math::not_equal(lf[2], rf[2]) ? true32 : false32,
      math::not_equal(lf[3], rf[3]) ? true32 : false32,
    };
  }
}

}
