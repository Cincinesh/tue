//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "math.hpp"
#include "vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

// The Tuesday C++ math and template library.
namespace tue
{
  // A quaternion with components of the given type.
  template<typename T>
  class quat;

  // A quaternion of float's.
  using fquat = quat<float>;

  // A quaternion of double's.
  using dquat = quat<double>;

  // A quaternion with components of the given type.
  template<typename T>
  class quat
  {
  private:
    struct { T data[4]; } impl_;

  public:
    // Constructs a new quat without a specific value.
    quat() noexcept = default;

    // Constructs a new quat with the given components.
    constexpr quat(const T& x, const T& y, const T& z, const T& w) noexcept
      : impl_({{ x, y, z, w }}) {}

    // Constructs a new quat with the given components.
    constexpr quat(const vec3<T>& v, const T& s) noexcept
      : impl_({{ v[0], v[1], v[2], s }}) {}

    // Constructs a new quat that is the result of explicitly casting the
    // components of another quat to to the new component type.
    template<typename U>
    explicit constexpr quat(const quat<U>& other) noexcept
    : impl_({{
        T(other[0]),
        T(other[1]),
        T(other[2]),
        T(other[3]),
      }}) {}

    // Returns a new quat that is the result of implicitly casting the
    // components of this quat to another type.
    template<typename U>
    constexpr operator quat<U>() const noexcept
    {
      return {
        impl_.data[0],
        impl_.data[1],
        impl_.data[2],
        impl_.data[3],
      };
    }

    // Returns a new quat with the vector part set to 0 and the scalar part set
    // to 1.
    static constexpr quat identity() noexcept
    {
      return { T(0), T(0), T(0), T(1) };
    }

    // Returns the first component of this quat.
    constexpr T x() const noexcept
    {
      return impl_.data[0];
    }

    // Sets the first component of this quat.
    void set_x(const T& x) noexcept
    {
      impl_.data[0] = x;
    }

    // Returns the second component of this quat.
    constexpr T y() const noexcept
    {
      return impl_.data[1];
    }

    // Sets the second component of this quat.
    void set_y(const T& y) noexcept
    {
      impl_.data[1] = y;
    }

    // Returns the third component of this quat.
    constexpr T z() const noexcept
    {
      return impl_.data[2];
    }

    // Sets the third component of this quat.
    void set_z(const T& z) noexcept
    {
      impl_.data[2] = z;
    }

    // Returns the fourth component of this quat.
    constexpr T w() const noexcept
    {
      return impl_.data[3];
    }

    // Sets the fourth component of this quat.
    void set_w(const T& w) noexcept
    {
      impl_.data[3] = w;
    }

    // Returns the vector component of this quat.
    constexpr vec3<T> v() const noexcept
    {
      return {
        impl_.data[0],
        impl_.data[1],
        impl_.data[2],
      };
    }

    // Sets the vector component of this quat.
    void set_v(const T& x, const T& y, const T& z) noexcept
    {
      impl_.data[0] = x;
      impl_.data[1] = y;
      impl_.data[2] = z;
    }

    // Sets the vector component of this quat.
    void set_v(const vec3<T>& v) noexcept
    {
      set_v(v[0], v[1], v[2]);
    }

    // Returns the scalar component of this quat.
    constexpr T s() const noexcept
    {
      return impl_.data[3];
    }

    // Sets the scalar component of this quat.
    void set_s(const T& s) noexcept
    {
      impl_.data[3] = s;
    }

    // Returns a pointer to this quat's underlying component array.
    T* data() noexcept
    {
      return impl_.data;
    }

    // Returns a pointer to this quat's underlying component array.
    const T* data() const noexcept
    {
      return impl_.data;
    }

    // Returns a reference to the component of this quat with the given index.
    template<typename I>
    T& operator[](const I& i) noexcept
    {
      return impl_.data[i];
    }

    // Returns a reference to the component of this quat with the given index.
    template<typename I>
    constexpr const T& operator[](const I& i) const noexcept
    {
      return impl_.data[i];
    }
  };

  // Retusn the grassman product of two quat's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator*(
      const quat<T>& lhs,
      const quat<U>& rhs) noexcept
  {
    return quat<decltype(lhs[0] * rhs[0])>{
      lhs.s()*rhs.v() + rhs.s()*lhs.v() + math::cross(lhs.v(), rhs.v()),
      lhs.s()*rhs.s() - math::dot(lhs.v(), rhs.v()),
    };
  }

  // Returns true if all the corresponding components of two quat's are equal
  // and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator==(
      const quat<T>& lhs,
      const quat<U>& rhs) noexcept
  {
    return lhs[0] == rhs[0]
        && lhs[1] == rhs[1]
        && lhs[2] == rhs[2]
        && lhs[3] == rhs[3];
  }

  // Returns true if any of the corresponding components of two quat's are not
  // equal and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator!=(
      const quat<T>& lhs,
      const quat<U>& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  // Non-member math functions.
  namespace math
  {
    // Returns the length (magnitude) squared of the given quat.
    template<typename T>
    inline auto length2(const quat<T>& q) noexcept
    {
      return math::length2(q[0])
          + math::length2(q[1])
          + math::length2(q[2])
          + math::length2(q[3]);
    }

    // Returns the length (magnitude) of the given quat.
    template<typename T>
    inline auto length(const quat<T>& q) noexcept
    {
      return math::sqrt(math::length2(q));
    }

    // Returns the given quat divided by its length (magnitude).
    template<typename T>
    inline auto normalize(const quat<T>& q) noexcept
    {
      const auto l = math::length(q);
      return quat<decltype(l / l)>{
        decltype(l)(q[0]) / l,
        decltype(l)(q[1]) / l,
        decltype(l)(q[2]) / l,
        decltype(l)(q[3]) / l,
      };
    }

    // Returns the conjugate of the given quat.
    template<typename T>
    inline TUE_CONSTEXPR quat<T> conjugate(const quat<T>& q) noexcept
    {
      return { -q.v(), q.s() };
    }

    // Returns the result of using the given quat to rotate the given vec.
    template<typename T, typename U>
    inline TUE_CONSTEXPR auto rotate(
        const quat<T>& q,
        const vec3<U>& v) noexcept
    {
      return (q * quat<U>(v, U(0)) * math::conjugate(q)).v();
    }

    // Returns a new quat that represents a rotation around the given axis by
    // the given angle.
    template<typename T>
    inline auto rotation_quat(const vec3<T>& axis, const T& radians) noexcept
    {
      using U = decltype(sin(radians));
      U s, c;
      math::sincos(U(radians) / U(2), s, c);
      return quat<U>(vec3<U>(axis) * s, c);
    }

    // Returns a new quat that represents a rotation around the given axis by
    // the given angle.
    template<typename T>
    inline auto rotation_quat(
        const T& axis_x,
        const T& axis_y,
        const T& axis_z,
        const T& radians) noexcept
    {
      return rotation_quat(vec3<T>(axis_x, axis_y, axis_z), radians);
    }

    // Returns a new quat that represents the same rotation as the given
    // rotation vector.
    template<typename T>
    inline auto rotation_quat(const vec3<T>& v) noexcept
    {
      using U = decltype(math::length(v));
      const U radians = math::length(v);
      const vec3<U> axis = vec3<U>(v) / radians;
      return rotation_quat(axis, radians);
    }

    // Returns a new quat that represents the same rotation as the given
    // rotation vector.
    template<typename T>
    inline auto rotation_quat(const T& x, const T& y, const T& z) noexcept
    {
      return rotation_quat(vec3<T>(x, y, z));
    }
  }
}

#undef TUE_CONSTEXPR
