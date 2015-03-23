//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "size2d.hpp"
#include "vec.hpp"

namespace tue {

template<typename P, typename S = P>
class rect;

using frect = rect<float>;
using drect = rect<double>;
using irect = rect<int>;
using urect = rect<unsigned int>;
using iurect = rect<int, unsigned int>;

template<typename P, typename S>
class rect
{
public:
  using position_type = vec2<P>;
  using position_component_type = P;
  using size_type = size2d<S>;
  using size_component_type = S;

private:
  vec2<P> position_;
  size2d<S> size_;

public:
  rect() noexcept = default;

  constexpr rect(
      const P& x, const P& y,
      const S& width, const S& height) noexcept
    : position_(x, y),
      size_(width, height) {
  }

  constexpr rect(
      const P& x, const P& y,
      const size2d<S>& size) noexcept
    : position_(x, y),
      size_(size) {
  }

  constexpr rect(
      const vec2<P>& position,
      const S& width, const S& height) noexcept
    : position_(position),
      size_(width, height) {
  }

  constexpr rect(
      const vec2<P>& position,
      const size2d<S>& size) noexcept
    : position_(position),
      size_(size) {
  }

  template<typename OtherP, typename OtherS>
  explicit constexpr rect(const rect<OtherP, OtherS>& other) noexcept
    : position_(other.position()),
      size_(other.size()) {
  }

  template<typename OtherP, typename OtherS>
  constexpr operator rect<OtherP, OtherS>() const noexcept {
    return rect<OtherP, OtherS>(position_, size_);
  }

  constexpr vec2<P> position() const noexcept {
    return position_;
  }

  void set_position(const P& x, const P& y) noexcept {
    position_.set_x(x);
    position_.set_y(y);
  }

  void set_position(const vec2<P>& position) noexcept {
    position_ = position;
  }

  constexpr P x() const noexcept {
    return position_.x();
  }

  void set_x(const P& x) noexcept {
    position_.set_x(x);
  }

  constexpr P y() const noexcept {
    return position_.y();
  }

  void set_y(const P& y) noexcept {
    position_.set_y(y);
  }

  constexpr size2d<S> size() const noexcept {
    return size_;
  }

  void set_size(const S& width, const S& height) noexcept {
    size_.set_width(width);
    size_.set_height(height);
  }

  void set_size(const size2d<S>& size) noexcept {
    size_ = size;
  }

  constexpr S width() const noexcept {
    return size_.width();
  }

  void set_width(const S& width) noexcept {
    size_.set_width(width);
  }

  constexpr S height() const noexcept {
    return size_.height();
  }

  void set_height(const S& height) noexcept {
    size_.set_height(height);
  }
};

template<typename LP, typename LS, typename RP, typename RS>
inline constexpr bool operator==(
    const rect<LP, LS>& lhs,
    const rect<RP, RS>& rhs) noexcept {
  return lhs.position() == rhs.position()
      && lhs.size() == rhs.size();
}

template<typename LP, typename LS, typename RP, typename RS>
inline constexpr bool operator!=(
    const rect<LP, LS>& lhs,
    const rect<RP, RS>& rhs) noexcept {
  return !operator==(lhs, rhs);
}

}
