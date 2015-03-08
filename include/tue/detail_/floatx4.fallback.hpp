//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../math.hpp"
#include "../simd.hpp"

namespace tue {

class floatx4
{
public:
  using component_type = float;

  static constexpr int component_count = 4;

private:
  float x, y, z, w;

public:
  floatx4() noexcept = default;

  explicit floatx4(float s) noexcept
    : x(s), y(s), z(s), w(s) {
  }

  floatx4(float x, float y, float z, float w) noexcept
    : x(x), y(y), z(z), w(w) {
  }

  static floatx4 zero() noexcept {
    return floatx4(0.0f);
  }

  static floatx4 load(const float* array) noexcept {
    return { array[0], array[1], array[2], array[3] };
  }

  static floatx4 loadu(const float* array) noexcept {
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

  floatx4 operator+() const noexcept {
    return { +x, +y, +z, +w };
  }

  floatx4 operator-() const noexcept {
    return { -x, -y, -z, -w };
  }

  floatx4 operator+(const floatx4& other) const noexcept {
    return {
      x + other.x,
      y + other.y,
      z + other.z,
      w + other.w,
    };
  }

  floatx4 operator-(const floatx4& other) const noexcept {
    return {
      x - other.x,
      y - other.y,
      z - other.z,
      w - other.w,
    };
  }

  floatx4 operator*(const floatx4& other) const noexcept {
    return {
      x * other.x,
      y * other.y,
      z * other.z,
      w * other.w,
    };
  }

  floatx4 operator/(const floatx4& other) const noexcept {
    return {
      x / other.x,
      y / other.y,
      z / other.z,
      w / other.w,
    };
  }

  floatx4& operator++() noexcept {
    ++x;
    ++y;
    ++z;
    ++w;
    return *this;
  }

  floatx4& operator--() noexcept {
    --x;
    --y;
    --z;
    --w;
    return *this;
  }

  floatx4 operator++(int) noexcept {
    return { x++, y++, z++, w++ };
  }

  floatx4 operator--(int) noexcept {
    return { x--, y--, z--, w-- };
  }

  floatx4& operator+=(const floatx4& other) noexcept {
    x += other.x;
    y += other.y;
    z += other.z;
    w += other.w;
    return *this;
  }

  floatx4& operator-=(const floatx4& other) noexcept {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    w -= other.w;
    return *this;
  }

  floatx4& operator*=(const floatx4& other) noexcept {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    w *= other.w;
    return *this;
  }

  floatx4& operator/=(const floatx4& other) noexcept {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    w /= other.w;
    return *this;
  }

  bool operator==(const floatx4& other) const noexcept {
    return x == other.x
        && y == other.y
        && z == other.z
        && w == other.w;
  }

  bool operator!=(const floatx4& other) const noexcept {
    return !(*this == other);
  }
};

namespace math
{
  inline floatx4 sin(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::sin(f[0]),
      math::sin(f[1]),
      math::sin(f[2]),
      math::sin(f[3]),
    };
  }

  inline floatx4 cos(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::cos(f[0]),
      math::cos(f[1]),
      math::cos(f[2]),
      math::cos(f[3]),
    };
  }

  inline void sincos(
      const floatx4& v,
      floatx4& sin_result,
      floatx4& cos_result) noexcept {
    sin_result = math::sin(v);
    cos_result = math::cos(v);
  }

  inline floatx4 exp(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::exp(f[0]),
      math::exp(f[1]),
      math::exp(f[2]),
      math::exp(f[3]),
    };
  }

  inline floatx4 log(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::log(f[0]),
      math::log(f[1]),
      math::log(f[2]),
      math::log(f[3]),
    };
  }

  inline floatx4 pow(
      const floatx4& base,
      const floatx4& exponent) noexcept {
    float bf[4], ef[4];
    base.store(bf);
    exponent.store(ef);
    return {
      math::pow(bf[0], ef[0]),
      math::pow(bf[1], ef[1]),
      math::pow(bf[2], ef[2]),
      math::pow(bf[3], ef[3]),
    };
  }

  inline floatx4 recip(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      1.0f / f[0],
      1.0f / f[1],
      1.0f / f[2],
      1.0f / f[3],
    };
  }

  inline floatx4 sqrt(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::sqrt(f[0]),
      math::sqrt(f[1]),
      math::sqrt(f[2]),
      math::sqrt(f[3]),
    };
  }

  inline floatx4 rsqrt(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      1.0f / math::sqrt(f[0]),
      1.0f / math::sqrt(f[1]),
      1.0f / math::sqrt(f[2]),
      1.0f / math::sqrt(f[3]),
    };
  }

  inline floatx4 min(const floatx4& v1, const floatx4& v2) noexcept {
    float f1[4], f2[4];
    v1.store(f1);
    v2.store(f2);
    return {
      math::min(f1[0], f2[0]),
      math::min(f1[1], f2[1]),
      math::min(f1[2], f2[2]),
      math::min(f1[3], f2[3]),
    };
  }

  inline floatx4 max(const floatx4& v1, const floatx4& v2) noexcept {
    float f1[4], f2[4];
    v1.store(f1);
    v2.store(f2);
    return {
      math::max(f1[0], f2[0]),
      math::max(f1[1], f2[1]),
      math::max(f1[2], f2[2]),
      math::max(f1[3], f2[3]),
    };
  }

  inline floatx4 abs(const floatx4& v) noexcept {
    float f[4];
    v.store(f);
    return {
      math::abs(f[0]),
      math::abs(f[1]),
      math::abs(f[2]),
      math::abs(f[3]),
    };
  }

  inline floatx4 dot(const floatx4& lhs, const floatx4& rhs) noexcept {
    return lhs * rhs;
  }

  inline floatx4 length2(const floatx4& v) noexcept {
    return v * v;
  }

  inline floatx4 length(const floatx4& v) noexcept {
    return math::abs(v);
  }

  inline floatx4 normalize(const floatx4& v) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    return {
      math::normalize(f[0]),
      math::normalize(f[1]),
      math::normalize(f[2]),
      math::normalize(f[3]),
    };
  }

  inline void transpose(
      floatx4& v0,
      floatx4& v1,
      floatx4& v2,
      floatx4& v3) noexcept {
    float f0[4], f1[4], f2[4], f3[4];
    v0.store(f0);
    v1.store(f1);
    v2.store(f2);
    v3.store(f3);
    v0 = { f0[0], f1[0], f2[0], f3[0] };
    v1 = { f0[1], f1[1], f2[1], f3[1] };
    v2 = { f0[2], f1[2], f2[2], f3[2] };
    v3 = { f0[3], f1[3], f2[3], f3[3] };
  }

  inline floatx4 select(const floatx4& v, const boolx4& mask) noexcept {
    const auto f = reinterpret_cast<const float*>(&v);
    const auto b = reinterpret_cast<const bool*>(&mask);
    return {
      b[0] ? f[0] : 0.0f,
      b[1] ? f[1] : 0.0f,
      b[2] ? f[2] : 0.0f,
      b[3] ? f[3] : 0.0f,
    };
  }

  inline boolx4 less(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] < rf[0],
      lf[1] < rf[1],
      lf[2] < rf[2],
      lf[3] < rf[3],
    };
  }

  inline boolx4 less_equal(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] <= rf[0],
      lf[1] <= rf[1],
      lf[2] <= rf[2],
      lf[3] <= rf[3],
    };
  }

  inline boolx4 greater(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] > rf[0],
      lf[1] > rf[1],
      lf[2] > rf[2],
      lf[3] > rf[3],
    };
  }

  inline boolx4 greater_equal(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] >= rf[0],
      lf[1] >= rf[1],
      lf[2] >= rf[2],
      lf[3] >= rf[3],
    };
  }

  inline boolx4 equal(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] == rf[0],
      lf[1] == rf[1],
      lf[2] == rf[2],
      lf[3] == rf[3],
    };
  }

  inline boolx4 not_equal(
      const floatx4& lhs,
      const floatx4& rhs) noexcept {
    float lf[4], rf[4];
    lhs.store(lf);
    rhs.store(rf);
    return {
      lf[0] != rf[0],
      lf[1] != rf[1],
      lf[2] != rf[2],
      lf[3] != rf[3],
    };
  }
}

}
