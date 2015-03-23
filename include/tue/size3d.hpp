//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace tue {

template<typename T>
class size3d;

using fsize3d = size3d<float>;
using dsize3d = size3d<double>;
using isize3d = size3d<int>;
using usize3d = size3d<unsigned int>;

template<typename T>
class size3d
{
public:
  using component_type = T;

private:
  T width_;
  T height_;
  T depth_;

public:
  size3d() noexcept = default;

  constexpr size3d(
      const T& width,
      const T& height,
      const T& depth) noexcept
    : width_(width), height_(height), depth_(depth) {
  }

  template<typename U>
  explicit constexpr size3d(const size3d<U>& other) noexcept
    : width_(T(other.width())),
      height_(T(other.height())),
      depth_(T(other.depth())) {
  }

  template<typename U>
  constexpr operator size3d<U>() const noexcept {
    return size3d<U>(width_, height_, depth_);
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

  constexpr T depth() const noexcept {
    return depth_;
  }

  void set_depth(const T& depth) noexcept {
    depth_ = depth;
  }
};

template<typename T, typename U>
inline constexpr bool operator==(
    const size3d<T>& lhs,
    const size3d<U>& rhs) noexcept {
  return lhs.width() == rhs.width()
      && lhs.height() == rhs.height()
      && lhs.depth() == rhs.depth();
}

template<typename T, typename U>
inline constexpr bool operator!=(
    const size3d<T>& lhs,
    const size3d<U>& rhs) noexcept {
  return !(lhs == rhs);
}

}
