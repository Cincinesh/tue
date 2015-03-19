//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace tue {

template<typename T>
class size2d;

using fsize2d = size2d<float>;
using dsize2d = size2d<double>;
using isize2d = size2d<int>;
using usize2d = size2d<unsigned int>;

template<typename T>
class size2d
{
public:
  using component_type = T;

private:
  T width_;
  T height_;

public:
  size2d() noexcept = default;

  explicit constexpr size2d(const T& width, const T& height) noexcept
    : width_(width), height_(height) {
  }

  template<typename U>
  explicit constexpr size2d(const size2d<U>& other) noexcept
    : width_(T(other.width())), height_(T(other.height())) {
  }

  template<typename U>
  constexpr operator size2d<U>() const noexcept {
    return size2d<U>(width_, height_);
  }

  constexpr T width() const noexcept {
    return width_;
  }

  void set_width(const T& width) noexcept {
    width_ = width;
  }

  constexpr T height() const noexcept {
    return height_;
  }

  void set_height(const T& height) noexcept {
    height_ = height;
  }
};

template<typename T, typename U>
inline constexpr bool operator==(
    const size2d<T>& lhs,
    const size2d<U>& rhs) noexcept {
  return lhs.width() == rhs.width()
      && lhs.height() == rhs.height();
}

template<typename T, typename U>
inline constexpr bool operator!=(
    const size2d<T>& lhs,
    const size2d<U>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

}
