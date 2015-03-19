//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
#include "../math.hpp"
#include "../pose2d.hpp"
#include "../pose3d.hpp"
#include "../quat.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue {

namespace math
{
  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> translation_mat(
      const T& x, const T& y) noexcept {
    return {
      { T(1), T(0), T(0),    x },
      { T(0), T(1), T(0),    y },
      { T(0), T(0), T(1), T(0) },
      { T(0), T(0), T(0), T(1) },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> translation_mat(
      const vec2<T>& xy) noexcept {
    return translation_mat(xy.x(), xy.y());
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> translation_mat(
      const T& x, const T& y, const T& z) noexcept {
    return {
      { T(1), T(0), T(0),    x },
      { T(0), T(1), T(0),    y },
      { T(0), T(0), T(1),    z },
      { T(0), T(0), T(0), T(1) },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> translation_mat(
      const vec3<T>& xyz) noexcept {
    return translation_mat(xyz.x(), xyz.y(), xyz.z());
  }

  template<typename T>
  inline auto rotation_mat(const T& angle) noexcept {
    using U = decltype(math::sin(angle));
    U s, c;
    math::sincos(angle, s, c);
    return mat<U, 4, 4>{
      {    c,   -s, U(0), U(0) },
      {    s,    c, U(0), U(0) },
      { U(0), U(0), U(1), U(0) },
      { U(0), U(0), U(0), U(1) },
    };
  }

  template<typename T>
  inline auto rotation_mat(
      const T& axis_x,
      const T& axis_y,
      const T& axis_z,
      const T& angle) noexcept {
    using U = decltype(math::sin(angle));
    const U x = static_cast<U>(axis_x);
    const U y = static_cast<U>(axis_y);
    const U z = static_cast<U>(axis_z);

    U s, c;
    math::sincos(angle, s, c);
    const U omc = U(1) - c;

    const U xx = x * x;
    const U xy = x * y;
    const U xz = x * z;
    const U xs = x * s;
    const U yy = y * y;
    const U yz = y * z;
    const U ys = y * s;
    const U zz = z * z;
    const U zs = z * s;
    const U xxomc = xx * omc;
    const U xyomc = xy * omc;
    const U xzomc = xz * omc;
    const U yyomc = yy * omc;
    const U yzomc = yz * omc;
    const U zzomc = zz * omc;

    return mat<U, 4, 4>{
      { xxomc + c, xyomc - zs, xzomc + ys, U(0) },
      { xyomc + zs, yyomc + c, yzomc - xs, U(0) },
      { xzomc - ys, yzomc + xs, zzomc + c, U(0) },
      {                  U(0), U(0), U(0), U(1) },
    };
  }

  template<typename T>
  inline auto rotation_mat(const vec3<T>& axis, const T& angle) noexcept {
    return rotation_mat(axis.x(), axis.y(), axis.z(), angle);
  }

  template<typename T>
  inline auto rotation_mat(const vec4<T>& v) noexcept {
    return rotation_mat(v.x(), v.y(), v.z(), v.w());
  }

  template<typename T>
  inline auto rotation_mat(const T& x, const T& y, const T& z) noexcept {
    return math::rotation_mat(math::axis_angle(x, y, z));
  }

  template<typename T>
  inline auto rotation_mat(const vec3<T>& v) noexcept {
    return math::rotation_mat(math::axis_angle(v));
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> rotation_mat(const quat<T>& q) noexcept {
    return {
      {
        T(1) - T(2)*q.y()*q.y() - T(2)*q.z()*q.z(),
        T(2)*q.x()*q.y() - T(2)*q.z()*q.w(),
        T(2)*q.x()*q.z() + T(2)*q.y()*q.w(),
        T(0),
      }, {
        T(2)*q.x()*q.y() + T(2)*q.z()*q.w(),
        T(1) - T(2)*q.x()*q.x() - T(2)*q.z()*q.z(),
        T(2)*q.y()*q.z() - T(2)*q.x()*q.w(),
        T(0),
      }, {
        T(2)*q.x()*q.z() - T(2)*q.y()*q.w(),
        T(2)*q.y()*q.z() + T(2)*q.x()*q.w(),
        T(1) - T(2)*q.x()*q.x() - T(2)*q.y()*q.y(),
        T(0),
      }, {
        T(0), T(0), T(0), T(1),
      },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> scale_mat(
      const T& x, const T& y) noexcept {
    return {
      {    x, T(0), T(0), T(0) },
      { T(0),    y, T(0), T(0) },
      { T(0), T(0), T(1), T(0) },
      { T(0), T(0), T(0), T(1) },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> scale_mat(
      const vec2<T>& xy) noexcept {
    return scale_mat(xy.x(), xy.y());
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> scale_mat(
      const T& x, const T& y, const T& z) noexcept {
    return {
      {    x, T(0), T(0), T(0) },
      { T(0),    y, T(0), T(0) },
      { T(0), T(0),    z, T(0) },
      { T(0), T(0), T(0), T(1) },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR mat<T, 4, 4> scale_mat(
      const vec3<T>& xyz) noexcept {
    return scale_mat(xyz.x(), xyz.y(), xyz.z());
  }

  template<typename T>
  inline auto pose_mat(
      const vec2<T>& translation,
      const T& rotation) noexcept {
    return rotation_mat(rotation)
        * translation_mat(translation);
  }

  template<typename T>
  inline auto pose_mat(
      const pose2d<T>& pose) noexcept {
    return pose_mat(pose.translation(), pose.rotation());
  }

  template<typename T>
  inline auto pose_mat(
      const vec3<T>& translation,
      const vec4<T>& rotation) noexcept {
    return rotation_mat(rotation)
        * translation_mat(translation);
  }

  template<typename T>
  inline auto pose_mat(
      const vec3<T>& translation,
      const vec3<T>& rotation_axis,
      const T& rotation_angle) noexcept {
    return rotation_mat(rotation_axis, rotation_angle)
        * translation_mat(translation);
  }

  template<typename T>
  inline auto pose_mat(
      const vec3<T>& translation,
      const vec3<T>& rotation) noexcept {
    return rotation_mat(rotation)
        * translation_mat(translation);
  }

  template<typename T>
  inline TUE_CONSTEXPR auto pose_mat(
      const vec3<T>& translation,
      const quat<T>& rotation) noexcept {
    return rotation_mat(rotation)
        * translation_mat(translation);
  }

  template<typename T>
  inline TUE_CONSTEXPR auto pose_mat(
      const pose3d<T>& pose) noexcept {
    return pose_mat(pose.translation(), pose.rotation());
  }

  template<typename T>
  inline auto view_mat(
      const vec2<T>& translation,
      const T& rotation) noexcept {
    return translation_mat(-translation)
        * rotation_mat(-rotation);
  }

  template<typename T>
  inline auto view_mat(
      const pose2d<T>& pose) noexcept {
    return view_mat(pose.translation(), pose.rotation());
  }

  template<typename T>
  inline auto view_mat(
      const vec3<T>& translation,
      const vec4<T>& rotation) noexcept {
    return translation_mat(-translation)
        * rotation_mat(rotation.xyz(), -rotation.a());
  }

  template<typename T>
  inline auto view_mat(
      const vec3<T>& translation,
      const vec3<T>& rotation_axis,
      const T& rotation_angle) noexcept {
    return translation_mat(-translation)
        * rotation_mat(rotation_axis, -rotation_angle);
  }

  template<typename T>
  inline auto view_mat(
      const vec3<T>& translation,
      const vec3<T>& rotation) noexcept {
    return translation_mat(-translation)
        * rotation_mat(-rotation);
  }

  template<typename T>
  inline TUE_CONSTEXPR auto view_mat(
      const vec3<T>& translation,
      const quat<T>& rotation) noexcept {
    return translation_mat(-translation)
        * rotation_mat(math::conjugate(rotation));
  }

  template<typename T>
  inline TUE_CONSTEXPR auto view_mat(
      const pose3d<T>& pose) noexcept {
    return view_mat(pose.translation(), pose.rotation());
  }

  template<typename T>
  inline auto perspective_mat(
      const T& fovy,
      const T& aspect,
      const T& near,
      const T& far) {
    using U = decltype(math::sin(fovy));
    U s, c;
    math::sincos(U(fovy) / U(2), s, c);
    const U f = c / s;
    const U nmf = U(near - far);
    return mat<U, 4, 4>{
      { f / U(aspect),                             U(0), U(0), U(0) },
      { U(0), f,                                         U(0), U(0) },
      { U(0), U(0), U(near + far) / nmf, U(2) * U(near * far) / nmf },
      { U(0), U(0), U(-1),                                     U(0) },
    };
  }

  template<typename T>
  inline TUE_CONSTEXPR auto ortho_mat(
      const T& width,
      const T& height,
      const T& near,
      const T& far) {
    using U = decltype(math::sin(width));
    return mat<U, 4, 4>{
      { U(2) / U(width),                                U(0), U(0), U(0) },
      { U(0), U(2) / U(height),                               U(0), U(0) },
      { U(0), U(0), U(2) / U(far - near), U(far + near) / U(far - near)  },
      { U(0), U(0), U(0),                                           U(1) },
    };
  }
}

}

#undef TUE_CONSTEXPR
