//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

// The Tuesday C++ math and template library.
namespace tue
{
  // A 2-dimensional size (width and height) with components of the given
  // type.
  template<typename T>
  class size2d;

  // A 2-dimensional size (width and height) with float components.
  using fsize2d = size2d<float>;

  // A 2-dimensional size (width and height) with double components.
  using dsize2d = size2d<double>;

  // A 2-dimensional size (width and height) with int components.
  using isize2d = size2d<int>;

  // A 2-dimensional size (width and height) with unsigned int components.
  using usize2d = size2d<unsigned int>;

  // A 2-dimensional size (width and height) with components of the given
  // type.
  template<typename T>
  class size2d
  {
  public:
    using component_type = T;

  private:
    T width_;

    T height_;

  public:
    // Constructs a new size2d without a specific value.
    size2d() noexcept = default;

    // Constructs a new size2d with the given components.
    explicit constexpr size2d(
        const T& width,
        const T& height) noexcept
      : width_(width),
        height_(height) {}

    // Constructs a new size2d that is the result of explicitly casting the
    // components of another size2d to to the new component type.
    template<typename U>
    explicit constexpr size2d(
        const size2d<U>& other) noexcept
      : width_(T(other.width())),
        height_(T(other.height())) {}

    // Returns a new size2d that is the result of implicitly casting the
    // components of this size2d to another type.
    template<typename U>
    constexpr operator size2d<U>() const noexcept
    {
      return size2d<U>(width_, height_);
    }

    // Returns the width component of this size2d.
    constexpr T width() const noexcept
    {
      return width_;
    }

    // Sets the width component of this size2d.
    void set_width(const T& width) noexcept
    {
      width_ = width;
    }

    // Returns the height component of this size2d.
    constexpr T height() const noexcept
    {
      return height_;
    }

    // Sets the height component of this size2d.
    void set_height(const T& height) noexcept
    {
      height_ = height;
    }
  };

  // Returns true if all the corresponding components of two size2d's are
  // equal and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator==(
      const size2d<T>& lhs,
      const size2d<U>& rhs) noexcept
  {
    return lhs.width() == rhs.width()
        && lhs.height() == rhs.height();
  }

  // Returns true if any of the corresponding components of two size2d's are
  // not equal and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator!=(
      const size2d<T>& lhs,
      const size2d<U>& rhs) noexcept
  {
    return !(lhs == rhs);
  }
}

#undef TUE_CONSTEXPR
