//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "vec.hpp"

namespace tue {

template<typename T>
class pose2d;

using fpose2d = pose2d<float>;
using dpose2d = pose2d<double>;

template<typename T>
class pose2d
{
public:
  using translation_type = vec2<T>;
  using rotation_type = T;
  using component_type = T;

private:
  vec2<T> translation_;
  T rotation_;

public:
  pose2d() noexcept = default;

  constexpr pose2d(const vec2<T>& translation, const T& rotation) noexcept
    : translation_(translation), rotation_(rotation) {
  }

  template<typename U>
  explicit constexpr pose2d(const pose2d<U>& other) noexcept
    : translation_(other.translation()),
      rotation_(T(other.rotation())) {
  }

  template<typename U>
  constexpr operator pose2d<U>() const noexcept {
    return { translation_, rotation_ };
  }

  constexpr vec2<T> translation() const noexcept {
    return translation_;
  }

  void set_translation(const T& x, const T& y) noexcept {
    translation_.set_x(x);
    translation_.set_y(y);
  }

  void set_translation(const vec2<T>& translation) noexcept {
    translation_ = translation;
  }

  constexpr T rotation() const noexcept {
    return rotation_;
  }

  void set_rotation(const T& rotation) noexcept {
    rotation_ = rotation;
  }
};

template<typename T, typename U>
inline constexpr bool operator==(
    const pose2d<T>& lhs,
    const pose2d<U>& rhs) noexcept {
  return lhs.translation() == rhs.translation()
      && lhs.rotation() == rhs.rotation();
}

template<typename L, typename R>
inline constexpr bool operator!=(
    const pose2d<L>& lhs,
    const pose2d<R>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

}
