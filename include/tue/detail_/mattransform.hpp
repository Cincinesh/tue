//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
#include "../math.hpp"
#include "../quat.hpp"
#include "../vec.hpp"

// The Tuesday C++ math and template library.
namespace tue
{
  // Non-member math functions.
  namespace math
  {
    // Returns a 2-dimensional translation matrix.
    template<typename T>
    inline mat<T, 3, 2> translation_mat(
        const T& x, const T& y) noexcept
    {
      return {
        { T(1), T(0) },
        { T(0), T(1) },
        {    x,    y },
      };
    }

    // Returns a 2-dimensional translation matrix.
    template<typename T>
    inline mat<T, 3, 2> translation_mat(
        const vec2<T>& xy) noexcept
    {
      return translation_mat(xy.x(), xy.y());
    }

    // Returns a 3-dimensional translation matrix.
    template<typename T>
    inline mat<T, 4, 3> translation_mat(
        const T& x, const T& y, const T& z) noexcept
    {
      return {
        { T(1), T(0), T(0) },
        { T(0), T(1), T(0) },
        { T(0), T(0), T(1) },
        {    x,    y,    z },
      };
    }

    // Returns a 3-dimensional translation matrix.
    template<typename T>
    inline mat<T, 4, 3> translation_mat(
        const vec3<T>& xyz) noexcept
    {
      return translation_mat(xyz.x(), xyz.y(), xyz.z());
    }

    // Returns a 2-dimensional rotation matrix.
    template<typename T>
    inline auto rotation_mat(const T& radians) noexcept
    {
      using U = decltype(math::sin(radians));
      U s, c;
      math::sincos(radians, s, c);

      return mat<U, 2, 2>{
        {  c, s },
        { -s, c },
      };
    }

    // Returns a 3-dimensional rotation matrix around the given axis.
    template<typename T>
    inline auto rotation_mat(
        const T& axis_x,
        const T& axis_y,
        const T& axis_z,
        const T& radians) noexcept
    {
      using U = decltype(math::sin(radians));
      const U x = static_cast<U>(axis_x);
      const U y = static_cast<U>(axis_y);
      const U z = static_cast<U>(axis_z);

      U s, c;
      math::sincos(radians, s, c);
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

      return mat<U, 3, 3>{
        { xxomc + c, xyomc + zs, xzomc - ys },
        { xyomc - zs, yyomc + c, yzomc + xs },
        { xzomc + ys, yzomc - xs, zzomc + c },
      };
    }

    // Returns a 3-dimensional rotation matrix around the given axis.
    template<typename T>
    inline auto rotation_mat(
        const vec3<T>& axis,
        const T& radians) noexcept
    {
      return rotation_mat(axis.x(), axis.y(), axis.z(), radians);
    }

    // Returns a 3-dimensional rotation matrix around the given axis-angle
    // vector.
    template<typename T>
    inline auto rotation_mat(const vec4<T>& v) noexcept
    {
      return rotation_mat(v.x(), v.y(), v.z(), v.w());
    }

    // Returns a 3-dimensional rotation matrix.
    template<typename T>
    inline mat<T, 3, 3> rotation_mat(const quat<T>& q) noexcept
    {
      const T x = q.x();
      const T y = q.y();
      const T z = q.z();
      const T w = q.w();
      const T xx2 = x * x * T(2);
      const T xy2 = x * y * T(2);
      const T xz2 = x * z * T(2);
      const T xw2 = x * w * T(2);
      const T yy2 = y * y * T(2);
      const T yz2 = y * z * T(2);
      const T yw2 = y * w * T(2);
      const T zz2 = z * z * T(2);
      const T zw2 = z * w * T(2);
      return {
        { T(1) - yy2 - zz2, xy2 - zw2, xz2 + yw2 },
        { xy2 + zw2, T(1) - xx2 - zz2, yz2 - xw2 },
        { xz2 - yw2, yz2 + xw2, T(1) - xx2 - yy2 },
      };
    }

    // Returns a 2-dimensional scale matrix.
    template<typename T>
    inline mat<T, 2, 2> scale_mat(
        const T& x, const T& y) noexcept
    {
      return {
        { x, T(0) },
        { T(0), y },
      };
    }

    // Returns a 2-dimensional scale matrix.
    template<typename T>
    inline mat<T, 2, 2> scale_mat(
        const vec2<T>& xy) noexcept
    {
      return scale_mat(xy.x(), xy.y());
    }

    // Returns a 3-dimensional scale matrix.
    template<typename T>
    inline mat<T, 3, 3> scale_mat(
        const T& x, const T& y, const T& z) noexcept
    {
      return {
        { x, T(0), T(0) },
        { T(0), y, T(0) },
        { T(0), T(0), z },
      };
    }

    // Returns a 3-dimensional scale matrix.
    template<typename T>
    inline mat<T, 3, 3> scale_mat(
        const vec3<T>& xyz) noexcept
    {
      return scale_mat(xyz.x(), xyz.y(), xyz.z());
    }

    // Returns a 2-dimensional view matrix.
    template<typename T>
    inline mat<T, 3, 2> view_mat(
        const vec2<T>& translation,
        const T& rotation) noexcept
    {
      return rotation_mat(-rotation)
          * translation_mat(-translation);
    }

    // Returns a 3-dimensional view matrix.
    template<typename T>
    inline mat<T, 4, 3> view_mat(
        const vec3<T>& translation,
        const quat<T>& rotation) noexcept
    {
      return rotation_mat(math::conjugate(rotation))
          * translation_mat(-translation);
    }

    // Returns a perspective projection matrix.
    template<typename T>
    inline auto perspective_mat(
        const T& fovy,
        const T& aspect,
        const T& near,
        const T& far)
    {
      using U = decltype(math::sin(fovy));
      U s, c;
      math::sincos(U(fovy) / U(2), s, c);
      const U f = c / s;
      const U nmf = static_cast<U>(near - far);

      return mat<U, 4, 4>{
        { f / U(aspect),              U(0), U(0), U( 0) },
        { U(0),                          f, U(0), U( 0) },
        { U(0), U(0),        U(near + far) / nmf, U(-1) },
        { U(0), U(0), U(2) * U(near * far) / nmf, U( 0) },
      };
    }

    // Returns an orthographic projection matrix.
    template<typename T>
    inline auto ortho_mat(
        const T& width,
        const T& height,
        const T& near,
        const T& far)
    {
      using U = decltype(math::sin(width));

      return mat<U, 3, 3>{
        { U(2) / U(width),      U(0), U(0) },
        { U(0), U(2) / U(height),     U(0) },
        { U(0), U(0), U(2) / U(near - far) },
      };
    }
  }
}
