//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>
#include "../mat.hpp"
#include "../math.hpp"
#include "../pose2d.hpp"
#include "../pose3d.hpp"
#include "../quat.hpp"
#include "../simd.hpp"
#include "../vec.hpp"

namespace tue {

namespace math
{
  template<typename T, int C = 4, int R = 4>
  inline constexpr std::enable_if_t<(R >= 3),
  mat<T, C, R>> translation_mat(
      const T& x, const T& y) noexcept {
    return detail_::mat_utils<T, C, R>::create(
        T(1), T(0), R == 3 ? x : T(0),    x,
        T(0), T(1), R == 3 ? y : T(0),    y,
        T(0), T(0),              T(1), T(0),
        T(0), T(0),              T(0), T(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto translation_mat(const vec2<T>& xy) noexcept {
    return translation_mat<T, C, R>(xy.x(), xy.y());
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr std::enable_if_t<(C >= 3 && R >= 4),
  mat<T, C, R>> translation_mat(
      const T& x, const T& y, const T& z) noexcept {
    return detail_::mat_utils<T, C, R>::create(
        T(1), T(0), T(0),    x,
        T(0), T(1), T(0),    y,
        T(0), T(0), T(1),    z,
        T(0), T(0), T(0), T(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto translation_mat(const vec3<T>& xyz) noexcept {
    return translation_mat<T, C, R>(xyz.x(), xyz.y(), xyz.z());
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(const T& angle) noexcept
      -> mat<decltype(math::sin(angle)), C, R> {
    using U = decltype(math::sin(angle));
    U s, c;
    math::sincos(angle, s, c);
    return detail_::mat_utils<U, C, R>::create(
           c,   -s, U(0), U(0),
           s,    c, U(0), U(0),
        U(0), U(0), U(1), U(0),
        U(0), U(0), U(0), U(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(
      const T& axis_x,
      const T& axis_y,
      const T& axis_z,
      const T& angle) noexcept
      -> std::enable_if_t<(C >= 3 && R >= 3),
         mat<decltype(math::sin(angle)), C, R>> {
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

    return detail_::mat_utils<U, C, R>::create(
        xxomc + c, xyomc - zs, xzomc + ys, U(0),
        xyomc + zs, yyomc + c, yzomc - xs, U(0),
        xzomc - ys, yzomc + xs, zzomc + c, U(0),
                         U(0), U(0), U(0), U(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(const vec3<T>& axis, const T& angle) noexcept {
    return rotation_mat<T, C, R>(axis.x(), axis.y(), axis.z(), angle);
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(const vec4<T>& axis_angle) noexcept {
    return rotation_mat<T, C, R>(axis_angle.xyz(), axis_angle.w());
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(const T& x, const T& y, const T& z) noexcept {
    return math::rotation_mat<T, C, R>(math::axis_angle(x, y, z));
  }

  template<typename T, int C = 4, int R = 4>
  inline auto rotation_mat(const vec3<T>& v) noexcept {
    return math::rotation_mat<T, C, R>(math::axis_angle(v));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr std::enable_if_t<(C >= 3 && R >= 3),
  mat<T, C, R>> rotation_mat(const quat<T>& q) noexcept {
    return detail_::mat_utils<T, C, R>::create(
        T(1) - T(2)*q.y()*q.y() - T(2)*q.z()*q.z(),
        T(2)*q.x()*q.y() - T(2)*q.z()*q.w(),
        T(2)*q.x()*q.z() + T(2)*q.y()*q.w(),
        T(0),
        T(2)*q.x()*q.y() + T(2)*q.z()*q.w(),
        T(1) - T(2)*q.x()*q.x() - T(2)*q.z()*q.z(),
        T(2)*q.y()*q.z() - T(2)*q.x()*q.w(),
        T(0),
        T(2)*q.x()*q.z() - T(2)*q.y()*q.w(),
        T(2)*q.y()*q.z() + T(2)*q.x()*q.w(),
        T(1) - T(2)*q.x()*q.x() - T(2)*q.y()*q.y(),
        T(0),
        T(0), T(0), T(0), T(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr mat<T, C, R> scale_mat(const T& x, const T& y) noexcept {
    return detail_::mat_utils<T, C, R>::create(
           x, T(0), T(0), T(0),
        T(0),    y, T(0), T(0),
        T(0), T(0), T(1), T(0),
        T(0), T(0), T(0), T(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto scale_mat(const vec2<T>& xy) noexcept {
    return scale_mat<T, C, R>(xy.x(), xy.y());
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr std::enable_if_t<(C >= 3 && R >= 3),
  mat<T, C, R>> scale_mat(const T& x, const T& y, const T& z) noexcept {
    return detail_::mat_utils<T, C, R>::create(
           x, T(0), T(0), T(0),
        T(0),    y, T(0), T(0),
        T(0), T(0),    z, T(0),
        T(0), T(0), T(0), T(1));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto scale_mat(const vec3<T>& xyz) noexcept {
    return scale_mat<T, C, R>(xyz.x(), xyz.y(), xyz.z());
  }

  template<typename T, int C = 4, int R = 4>
  inline auto pose_mat(
      const vec2<T>& translation,
      const T& rotation) noexcept {
    return rotation_mat<T, R, R>(rotation)
        * translation_mat<T, C, R>(translation);
  }

  template<typename T, int C = 4, int R = 4>
  inline auto pose_mat(const pose2d<T>& pose) noexcept {
    return pose_mat<T, C, R>(pose.translation(), pose.rotation());
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto pose_mat(
      const vec3<T>& translation,
      const quat<T>& rotation) noexcept {
    return rotation_mat<T, R, R>(rotation)
        * translation_mat<T, C, R>(translation);
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto pose_mat(const pose3d<T>& pose) noexcept {
    return pose_mat<T, C, R>(pose.translation(), pose.rotation());
  }

  template<typename T, int C = 4, int R = 4>
  inline auto view_mat(
      const vec2<T>& translation,
      const T& rotation) noexcept {
    return translation_mat<T, C, R>(-translation)
        * rotation_mat<T, C, C>(-rotation);
  }

  template<typename T, int C = 4, int R = 4>
  inline auto view_mat(const pose2d<T>& pose) noexcept {
    return view_mat<T, C, R>(pose.translation(), pose.rotation());
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto view_mat(
      const vec3<T>& translation,
      const quat<T>& rotation) noexcept {
    return translation_mat<T, C, R>(-translation)
        * rotation_mat<T, C, C>(math::conjugate(rotation));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto view_mat(const pose3d<T>& pose) noexcept {
    return view_mat<T, C, R>(pose.translation(), pose.rotation());
  }

  template<typename T, int C = 4, int R = 4>
  inline auto perspective_mat(
      const T& fovy,
      const T& aspect,
      const T& near,
      const T& far) noexcept
      -> std::enable_if_t<(C >= 4 && R >= 4),
         mat<decltype(math::sin(fovy)), C, R>> {
    using U = decltype(math::sin(fovy));
    U s, c;
    math::sincos(U(fovy) / U(2), s, c);
    const U f = c / s;
    const U nmf = U(near - far);
    return detail_::mat_utils<U, C, R>::create(
        f / U(aspect),                             U(0), U(0), U(0),
        U(0), f,                                         U(0), U(0),
        U(0), U(0), U(near + far) / nmf, U(2) * U(near * far) / nmf,
        U(0), U(0), U(-1),                                     U(0));
  }

  template<typename T, int C = 4, int R = 4>
  inline constexpr auto ortho_mat(
      const T& width,
      const T& height,
      const T& near,
      const T& far) noexcept
      -> std::enable_if_t<(C >= 3 && R >= 4),
         mat<decltype(math::recip(width)), C, R>>  {
    using U = decltype(math::recip(width));
    const U nmf = U(near - far);
    return detail_::mat_utils<U, C, R>::create(
        U(2) / U(width),           U(0), U(0), U(0),
        U(0), U(2) / U(height),          U(0), U(0),
        U(0), U(0), U(2) / nmf, U(near + far) / nmf,
        U(0), U(0), U(0),                      U(1));
  }
}

}
