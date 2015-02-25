//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "size2d.hpp"
#include "vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

// The Tuesday C++ math and template library.
namespace tue
{
  // A rectangle defined by two position coordinates of type P and two size
  // dimensions of type S.
  template<typename P, typename S = P>
  class rect;

  // A rectangle defined by float position coordinates and size dimesions.
  using frect = rect<float>;

  // A rectangle defined by double position coordinates and size dimesions.
  using drect = rect<double>;

  // A rectangle defined by int position coordinates and size dimesions.
  using irect = rect<int>;

  // A rectangle defined by unsigned int position coordinates and size
  // dimesions.
  using urect = rect<unsigned int>;

  // A rectangle defined by unsigned int position coordinates and unsigned int
  // size dimensions.
  using iurect = rect<int, unsigned int>;

  // A rectangle defined by two position coordinates of type P and two size
  // dimensions of type S.
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
    // Constructs a new rect without a specific value.
    rect() noexcept = default;

    // Constructs a new rect with the given components.
    explicit constexpr rect(
        const P& x,
        const P& y,
        const S& width,
        const S& height) noexcept
      : position_(x, y),
        size_(width, height) {}

    // Constructs a new rect with the given components.
    explicit constexpr rect(
        const P& x,
        const P& y,
        const size2d<S>& size) noexcept
      : position_(x, y),
        size_(size) {}

    // Constructs a new rect with the given components.
    explicit constexpr rect(
        const vec2<P>& position,
        const S& width,
        const S& height) noexcept
      : position_(position),
        size_(width, height) {}

    // Constructs a new rect with the given components.
    explicit constexpr rect(
        const vec2<P>& position,
        const size2d<S>& size) noexcept
      : position_(position),
        size_(size) {}

    // Constructs a new rect that is the result of explicitly casting the
    // components of another rect to to the new component types.
    template<typename OtherP, typename OtherS>
    explicit constexpr rect(const rect<OtherP, OtherS>& other) noexcept
      : position_(other.position()),
        size_(other.size()) {}

    // Returns a new rect that is the result of implicitly casting the
    // components of this rect to other types.
    template<typename OtherP, typename OtherS>
    constexpr operator rect<OtherP, OtherS>() const noexcept
    {
      return rect<OtherP, OtherS>(position_, size_);
    }

    // Returns the position (coordinates) of this rect.
    constexpr vec2<P> position() const noexcept
    {
      return position_;
    }

    // Sets the position (coordinates) of this rect.
    void set_position(const P& x, const P& y) noexcept
    {
      position_.set_x(x);
      position_.set_y(y);
    }

    // Sets the position (coordinates) of this rect.
    void set_position(const vec2<P>& position) noexcept
    {
      position_ = position;
    }

    // Returns the x-component of this rect's position.
    constexpr P x() const noexcept
    {
      return position_.x();
    }

    // Sets the x-component of this rect's position.
    void set_x(const P& x) noexcept
    {
      position_.set_x(x);
    }

    // Returns the y-component of this rect's position.
    constexpr P y() const noexcept
    {
      return position_.y();
    }

    // Sets the y-component of this rect's position.
    void set_y(const P& y) noexcept
    {
      position_.set_y(y);
    }

    // Returns the size (dimensions) of this rect.
    constexpr size2d<S> size() const noexcept
    {
      return size_;
    }

    // Sets the size (dimensions) of this rect.
    void set_size(const S& width, const S& height) noexcept
    {
      size_.set_width(width);
      size_.set_height(height);
    }

    // Sets the size (dimensions) of this rect.
    void set_size(const size2d<S>& size) noexcept
    {
      size_ = size;
    }

    // Returns the width of this rect.
    constexpr S width() const noexcept
    {
      return size_.width();
    }

    // Sets the width of this rect.
    void set_width(const S& width) noexcept
    {
      size_.set_width(width);
    }

    // Returns the height of this rect.
    constexpr S height() const noexcept
    {
      return size_.height();
    }

    // Sets the height of this rect.
    void set_height(const S& height) noexcept
    {
      size_.set_height(height);
    }
  };

  // Returns true if all the corresponding components of two rect's are equal
  // and false otherwise.
  template<typename LP, typename LS, typename RP, typename RS>
  inline TUE_CONSTEXPR bool operator==(
      const rect<LP, LS>& lhs,
      const rect<RP, RS>& rhs) noexcept
  {
    return lhs.position() == rhs.position()
        && lhs.size() == rhs.size();
  }

  // Returns true if any of the corresponding components of two rect's are not
  // equal and false otherwise.
  template<typename LP, typename LS, typename RP, typename RS>
  inline TUE_CONSTEXPR bool operator!=(
      const rect<LP, LS>& lhs,
      const rect<RP, RS>& rhs) noexcept
  {
    return !(lhs == rhs);
  }
}

#undef TUE_CONSTEXPR
