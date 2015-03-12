//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cmath>
#include "math.hpp"
#include "vec.hpp"

namespace tue {

template<typename T>
class quat;

using fquat = quat<float>;
using dquat = quat<double>;

template<typename T>
class quat
{
public:
  using component_type = T;

private:
  struct { T data[4]; } impl_;

public:
  quat() noexcept = default;

  constexpr quat(const T& x, const T& y, const T& z, const T& w) noexcept
    : impl_({{ x, y, z, w }}) {
  }

  constexpr quat(const vec3<T>& v, const T& s) noexcept
    : impl_({{ v[0], v[1], v[2], s }}) {
  }

  template<typename U>
  explicit constexpr quat(const quat<U>& other) noexcept
  : impl_({{
      T(other[0]),
      T(other[1]),
      T(other[2]),
      T(other[3]),
    }}) {
  }

  template<typename U>
  constexpr operator quat<U>() const noexcept {
    return {
      impl_.data[0],
      impl_.data[1],
      impl_.data[2],
      impl_.data[3],
    };
  }

  static constexpr quat identity() noexcept {
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

  constexpr vec3<T> v() const noexcept {
    return {
      impl_.data[0],
      impl_.data[1],
      impl_.data[2],
    };
  }

  void set_v(const T& x, const T& y, const T& z) noexcept {
    impl_.data[0] = x;
    impl_.data[1] = y;
    impl_.data[2] = z;
  }

  void set_v(const vec3<T>& v) noexcept {
    set_v(v[0], v[1], v[2]);
  }

  constexpr T s() const noexcept {
    return impl_.data[3];
  }

  void set_s(const T& s) noexcept {
    impl_.data[3] = s;
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
};

template<typename T, typename U>
inline constexpr auto operator*(
    const quat<T>& lhs,
    const quat<U>& rhs) noexcept {
  return quat<decltype(lhs[0] * rhs[0])>{
    lhs.s()*rhs.v() + rhs.s()*lhs.v() + math::cross(lhs.v(), rhs.v()),
    lhs.s()*rhs.s() - math::dot(lhs.v(), rhs.v()),
  };
}

template<typename T, typename U>
inline constexpr auto operator*(
    const vec3<T>& v,
    const quat<U>& q) noexcept {
  return (q * quat<T>(v, T(0)) * math::conjugate(q)).v();
}

template<typename T, typename U>
inline constexpr bool operator==(
    const quat<T>& lhs,
    const quat<U>& rhs) noexcept {
  return lhs[0] == rhs[0]
      && lhs[1] == rhs[1]
      && lhs[2] == rhs[2]
      && lhs[3] == rhs[3];
}

template<typename T, typename U>
inline constexpr bool operator!=(
    const quat<T>& lhs,
    const quat<U>& rhs) noexcept {
  return !(lhs == rhs);
}

namespace math
{
  template<typename T>
  inline auto length2(const quat<T>& q) noexcept {
    return math::length2(q[0])
        + math::length2(q[1])
        + math::length2(q[2])
        + math::length2(q[3]);
  }

  template<typename T>
  inline auto length(const quat<T>& q) noexcept {
    return math::sqrt(math::length2(q));
  }

  template<typename T>
  inline auto normalize(const quat<T>& q) noexcept {
    const auto l = math::length(q);
    return quat<decltype(l / l)>{
      decltype(l)(q[0]) / l,
      decltype(l)(q[1]) / l,
      decltype(l)(q[2]) / l,
      decltype(l)(q[3]) / l,
    };
  }

  template<typename T>
  inline constexpr quat<T> conjugate(const quat<T>& q) noexcept {
    return { -q.v(), q.s() };
  }

  template<typename T>
  inline auto rotation_quat(const vec3<T>& axis, const T& angle) noexcept {
    using U = decltype(sin(angle));
    U s, c;
    math::sincos(U(angle) / U(2), s, c);
    return quat<U>(vec3<U>(axis) * s, c);
  }

  template<typename T>
  inline auto rotation_quat(
      const T& axis_x,
      const T& axis_y,
      const T& axis_z,
      const T& angle) noexcept {
    return math::rotation_quat(vec3<T>(axis_x, axis_y, axis_z), angle);
  }

  template<typename T>
  inline auto rotation_quat(const vec4<T>& v) noexcept {
    return math::rotation_quat(v.xyz(), v.w());
  }

  template<typename T>
  inline auto rotation_quat(const vec3<T>& v) noexcept {
    return math::rotation_quat(math::axis_angle(v));
  }

  template<typename T>
  inline auto rotation_quat(const T& x, const T& y, const T& z) noexcept {
    return math::rotation_quat(vec3<T>(x, y, z));
  }

  template<typename T>
  inline auto axis_angle(const quat<T>& q) noexcept {
    using U = decltype(std::acos(q.s()));
    const U angle = U(2) * std::acos(q.s());
    return vec4<U>(math::normalize(q.v()), angle);
  }

  template<typename T>
  inline auto rotation_vec(const quat<T>& q) noexcept {
    return math::rotation_vec(math::axis_angle(q));
  }
}

}
