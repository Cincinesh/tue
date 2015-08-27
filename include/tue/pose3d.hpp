//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "quat.hpp"
#include "vec.hpp"

namespace tue {

template<typename T>
class pose3d;

using fpose3d = pose3d<float>;
using dpose3d = pose3d<double>;

template<typename T>
class pose3d
{
public:
  using translation_type = vec3<T>;
  using rotation_type = quat<T>;
  using component_type = T;

private:
  vec3<T> translation_;
  quat<T> rotation_;

public:
  pose3d() noexcept = default;

  constexpr pose3d(const vec3<T>& translation, const quat<T>& rotation) noexcept
    : translation_(translation), rotation_(rotation) {
  }

  template<typename U>
  explicit constexpr pose3d(const pose3d<U>& other) noexcept
    : translation_(other.translation()),
      rotation_(other.rotation()) {
  }

  template<typename U>
  constexpr operator pose3d<U>() const noexcept {
    return { translation_, rotation_ };
  }

  static constexpr pose3d identity() noexcept {
    return { vec3<T>::zero(), quat<T>::identity() };
  }

  constexpr vec3<T> translation() const noexcept {
    return translation_;
  }

  void set_translation(const T& x, const T& y, const T& z) noexcept {
    translation_.set_x(x);
    translation_.set_y(y);
    translation_.set_z(z);
  }

  void set_translation(const vec3<T>& translation) noexcept {
    translation_ = translation;
  }

  constexpr quat<T> rotation() const noexcept {
    return rotation_;
  }

  void set_rotation(const quat<T>& rotation) noexcept {
    rotation_ = rotation;
  }
};

template<typename L, typename R>
inline constexpr bool operator==(
    const pose3d<L>& lhs,
    const pose3d<R>& rhs) noexcept {
  return lhs.translation() == rhs.translation()
      && lhs.rotation() == rhs.rotation();
}

template<typename L, typename R>
inline constexpr bool operator!=(
    const pose3d<L>& lhs,
    const pose3d<R>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

}
