//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../math.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

// The Tuesday C++ math and template library.
namespace tue
{
  // A CxR matrix with components of the given type.
  template<typename T, int C, int R>
  class mat;

  // A 2-component vector with components of the given type.
  template<typename T>
  class vec<T, 2>
  {
  private:
    struct { T data[2]; } impl_;

  public:
    // Constructs a new vec without a specific value.
    vec() noexcept = default;

    // Constructs a new vec with each component set to the given value.
    explicit constexpr vec(const T& s) noexcept
      : impl_({{ s, s }}) {}

    // Constructs a new vec with the given components.
    constexpr vec(const T& x, const T& y) noexcept
      : impl_({{ x, y }}) {}

    // Constructs a new vec by truncating another vec.
    explicit constexpr vec(const vec3<T>& other) noexcept
      : impl_({{ other[0], other[1] }}) {}

    // Constructs a new vec by truncating another vec.
    explicit constexpr vec(const vec4<T>& other) noexcept
      : impl_({{ other[0], other[1] }}) {}

    // Constructs a new vec that is the result of explicitly casting the
    // components of another vec to to the new component type.
    template<typename U>
    explicit constexpr vec(const vec2<U>& other) noexcept
      : impl_({{
          T(other[0]),
          T(other[1]),
        }}) {}

    // Returns a new vec that is the result of implicitly casting the
    // components of this vec to another type.
    template<typename U>
    constexpr operator vec2<U>() const noexcept
    {
      return {
        impl_.data[0],
        impl_.data[1],
      };
    }

    // Returns a vec with each component set to 0.
    static constexpr vec zero() noexcept
    {
      return { T(0), T(0) };
    }

    // Returns a vec with the x-component set to 1 and all other components
    // set to 0.
    static constexpr vec x_axis() noexcept
    {
      return { T(1), T(0) };
    }

    // Returns a vec with the y-component set to 1 and all other components
    // set to 0.
    static constexpr vec y_axis() noexcept
    {
      return { T(0), T(1) };
    }

    // Returns the first component of this vec.
    constexpr T x() const noexcept
    {
      return impl_.data[0];
    }

    // Sets the first component of this vec.
    void set_x(const T& x) noexcept
    {
      impl_.data[0] = x;
    }

    // Returns the second component of this vec.
    constexpr T y() const noexcept
    {
      return impl_.data[1];
    }

    // Sets the second component of this vec.
    void set_y(const T& y) noexcept
    {
      impl_.data[1] = y;
    }

    // Returns a reference to the component of this vec with the given index.
    template<typename I>
    T& operator[](const I& i) noexcept
    {
      return impl_.data[i];
    }

    // Returns a reference to the component of this vec with the given index.
    template<typename I>
    constexpr const T& operator[](const I& i) const noexcept
    {
      return impl_.data[i];
    }

    // Component-wise increments and returns a reference to this vec.
    vec& operator++() noexcept
    {
      ++impl_.data[0];
      ++impl_.data[1];
      return *this;
    }

    // Component-wise decrements and returns a reference to this vec.
    vec& operator--() noexcept
    {
      --impl_.data[0];
      --impl_.data[1];
      return *this;
    }

    // Component-wise increments this vec and returns the original value.
    vec operator++(int) noexcept
    {
      const auto orig = *this;
      ++*this;
      return orig;
    }

    // Component-wise decrements this vec and returns the original value.
    vec operator--(int) noexcept
    {
      const auto orig = *this;
      --*this;
      return orig;
    }

    // Component-wise adds a value to and returns a reference to this vec.
    template<typename U>
    vec& operator+=(const U& other) noexcept
    {
      impl_.data[0] += other;
      impl_.data[1] += other;
      return *this;
    }

    // Component-wise adds another vec to and returns a reference to this vec.
    template<typename U>
    vec& operator+=(const vec2<U>& other) noexcept
    {
      impl_.data[0] += other[0];
      impl_.data[1] += other[1];
      return *this;
    }

    // Component-wise subtracts a value from and returns a reference to this
    // vec.
    template<typename U>
    vec& operator-=(const U& other) noexcept
    {
      impl_.data[0] -= other;
      impl_.data[1] -= other;
      return *this;
    }

    // Component-wise subtracts another vec from and returns a reference to
    // this vec.
    template<typename U>
    vec& operator-=(const vec2<U>& other) noexcept
    {
      impl_.data[0] -= other[0];
      impl_.data[1] -= other[1];
      return *this;
    }

    // Component-wise multiplies this vec by a value and returns a reference
    // to this vec.
    template<typename U>
    vec& operator*=(const U& other) noexcept
    {
      impl_.data[0] *= other;
      impl_.data[1] *= other;
      return *this;
    }

    // Component-wise multiplies this vec by another vec and returns a
    // reference to this vec.
    template<typename U>
    vec& operator*=(const vec2<U>& other) noexcept
    {
      impl_.data[0] *= other[0];
      impl_.data[1] *= other[1];
      return *this;
    }

    // Multiplies this row vec by the given matrix and returns a reference to
    // this vec.
    template<typename U>
    vec& operator*=(const mat<U, 2, 2>& other) noexcept
    {
      return *this = *this * other;
    }

    // Component-wise divides this vec by a value and returns a reference to
    // this vec.
    template<typename U>
    vec& operator/=(const U& other) noexcept
    {
      impl_.data[0] /= other;
      impl_.data[1] /= other;
      return *this;
    }

    // Component-wise divides this vec by another vec and returns a reference
    // to this vec.
    template<typename U>
    vec& operator/=(const vec2<U>& other) noexcept
    {
      impl_.data[0] /= other[0];
      impl_.data[1] /= other[1];
      return *this;
    }

    // Component-wise modulo-assigns this vec with a value and returns a
    // reference to this vec.
    template<typename U>
    vec& operator%=(const U& other) noexcept
    {
      impl_.data[0] %= other;
      impl_.data[1] %= other;
      return *this;
    }

    // Component-wise modulo-assigns this vec with another vec and returns a
    // reference to this vec.
    template<typename U>
    vec& operator%=(const vec2<U>& other) noexcept
    {
      impl_.data[0] %= other[0];
      impl_.data[1] %= other[1];
      return *this;
    }

    // Bitwise and-assigns a value with the components of and returns a
    // reference to this vec.
    template<typename U>
    vec& operator&=(const U& other) noexcept
    {
      impl_.data[0] &= other;
      impl_.data[1] &= other;
      return *this;
    }

    // Bitwise and-assigns the components of another vec with the
    // corresponding components of and returns a reference to this vec.
    template<typename U>
    vec& operator&=(const vec2<U>& other) noexcept
    {
      impl_.data[0] &= other[0];
      impl_.data[1] &= other[1];
      return *this;
    }

    // Bitwise or-assigns a value with the components of and returns a
    // reference to this vec.
    template<typename U>
    vec& operator|=(const U& other) noexcept
    {
      impl_.data[0] |= other;
      impl_.data[1] |= other;
      return *this;
    }

    // Bitwise or-assigns the components of another vec with the
    // corresponding components of and returns a reference to this vec.
    template<typename U>
    vec& operator|=(const vec2<U>& other) noexcept
    {
      impl_.data[0] |= other[0];
      impl_.data[1] |= other[1];
      return *this;
    }

    // Bitwise xor-assigns a value with the components of and returns a
    // reference to this vec.
    template<typename U>
    vec& operator^=(const U& other) noexcept
    {
      impl_.data[0] ^= other;
      impl_.data[1] ^= other;
      return *this;
    }

    // Bitwise xor-assigns the components of another vec with the
    // corresponding components of and returns a reference to this vec.
    template<typename U>
    vec& operator^=(const vec2<U>& other) noexcept
    {
      impl_.data[0] ^= other[0];
      impl_.data[1] ^= other[1];
      return *this;
    }

    // Bitwise shift left-assigns a value to the components of and returns a
    // reference to this vec.
    template<typename U>
    vec& operator<<=(const U& other) noexcept
    {
      impl_.data[0] <<= other;
      impl_.data[1] <<= other;
      return *this;
    }

    // Bitwise shift left-assigns the components of another vec to the
    // corresponding components of and returns a reference to this vec.
    template<typename U>
    vec& operator<<=(const vec2<U>& other) noexcept
    {
      impl_.data[0] <<= other[0];
      impl_.data[1] <<= other[1];
      return *this;
    }

    // Bitwise shift right-assigns a value to the components of and returns a
    // reference to this vec.
    template<typename U>
    vec& operator>>=(const U& other) noexcept
    {
      impl_.data[0] >>= other;
      impl_.data[1] >>= other;
      return *this;
    }

    // Bitwise shift right-assigns the components of another vec to the
    // corresponding components of and returns a reference to this vec.
    template<typename U>
    vec& operator>>=(const vec2<U>& other) noexcept
    {
      impl_.data[0] >>= other[0];
      impl_.data[1] >>= other[1];
      return *this;
    }

  private:
    /// Private helpers for matrix classes
    template<typename U, int C, int R>
    friend class mat;

    static constexpr vec extend_(
        const vec2<T>& v,
        const T&,
        const T&) noexcept
    {
      return v;
    }

    static constexpr vec extend_(
        const vec3<T>& v,
        const T&,
        const T&) noexcept
    {
      return vec(v);
    }

    static constexpr vec extend_(
        const vec4<T>& v,
        const T&,
        const T&) noexcept
    {
      return vec(v);
    }
  };

  // Returns the component-wise unary plus of the given vec.
  template<typename T>
  inline TUE_CONSTEXPR auto operator+(const vec2<T>& v) noexcept
  {
    return vec2<decltype(+v[0])>(+v[0], +v[1]);
  }

  // Returns the component-wise negation of the given vec.
  template<typename T>
  inline TUE_CONSTEXPR auto operator-(const vec2<T>& v) noexcept
  {
    return vec2<decltype(-v[0])>(-v[0], -v[1]);
  }

  // Returns the bitwise not of the given vec.
  template<typename T>
  inline TUE_CONSTEXPR auto operator~(const vec2<T>& v) noexcept
  {
    return vec2<decltype(~v[0])>(~v[0], ~v[1]);
  }

  // Returns the component-wise sum of a value and a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator+(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs + rhs[0])>{
      lhs + rhs[0],
      lhs + rhs[1],
    };
  }

  // Returns the component-wise sum of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator+(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] + rhs)>{
      lhs[0] + rhs,
      lhs[1] + rhs,
    };
  }

  // Returns the component-wise sum of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator+(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] + rhs[0])>{
      lhs[0] + rhs[0],
      lhs[1] + rhs[1],
    };
  }

  // Returns the component-wise difference between a value and a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator-(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs - rhs[0])>{
      lhs - rhs[0],
      lhs - rhs[1],
    };
  }

  // Returns the component-wise difference between a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator-(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] - rhs)>{
      lhs[0] - rhs,
      lhs[1] - rhs,
    };
  }

  // Returns the component-wise difference between two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator-(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] - rhs[0])>{
      lhs[0] - rhs[0],
      lhs[1] - rhs[1],
    };
  }

  // Returns the component-wise product of a value and a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator*(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs * rhs[0])>{
      lhs * rhs[0],
      lhs * rhs[1],
    };
  }

  // Returns the component-wise product of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator*(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] * rhs)>{
      lhs[0] * rhs,
      lhs[1] * rhs,
    };
  }

  // Returns the component-wise product of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator*(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] * rhs[0])>{
      lhs[0] * rhs[0],
      lhs[1] * rhs[1],
    };
  }

  // Returns the component-wise quotient of a value and a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator/(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs / rhs[0])>{
      lhs / rhs[0],
      lhs / rhs[1],
    };
  }

  // Returns the component-wise quotient of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator/(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] / rhs)>{
      lhs[0] / rhs,
      lhs[1] / rhs,
    };
  }

  // Returns the component-wise quotient of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator/(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] / rhs[0])>{
      lhs[0] / rhs[0],
      lhs[1] / rhs[1],
    };
  }

  // Returns the component-wise modulus of a value and a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator%(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs % rhs[0])>{
      lhs % rhs[0],
      lhs % rhs[1],
    };
  }

  // Returns the component-wise modulus of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator%(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] % rhs)>{
      lhs[0] % rhs,
      lhs[1] % rhs,
    };
  }

  // Returns the component-wise modulus of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator%(
    const vec2<T>& lhs,
    const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] % rhs[0])>{
      lhs[0] % rhs[0],
      lhs[1] % rhs[1],
    };
  }

  // Returns the bitwise and of a value and the components of a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator&(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs & rhs[0])>{
      lhs & rhs[0],
      lhs & rhs[1],
    };
  }

  // Returns the bitwise and of the components of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator&(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] & rhs)>{
      lhs[0] & rhs,
      lhs[1] & rhs,
    };
  }

  // Returns the bitwise and of the components of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator&(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] & rhs[0])>{
      lhs[0] & rhs[0],
      lhs[1] & rhs[1],
    };
  }

  // Returns the bitwise or of a value and the components of a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator|(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs | rhs[0])>{
      lhs | rhs[0],
      lhs | rhs[1],
    };
  }

  // Returns the bitwise or of the components of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator|(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] | rhs)>{
      lhs[0] | rhs,
      lhs[1] | rhs,
    };
  }

  // Returns the bitwise or of the components of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator|(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] | rhs[0])>{
      lhs[0] | rhs[0],
      lhs[1] | rhs[1],
    };
  }

  // Returns the bitwise xor of a value and the components of a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator^(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs ^ rhs[0])>{
      lhs ^ rhs[0],
      lhs ^ rhs[1],
    };
  }

  // Returns the bitwise xor of the components of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator^(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] ^ rhs)>{
      lhs[0] ^ rhs,
      lhs[1] ^ rhs,
    };
  }

  // Returns the bitwise xor of the components of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator^(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] ^ rhs[0])>{
      lhs[0] ^ rhs[0],
      lhs[1] ^ rhs[1],
    };
  }

  // Returns the bitwise shift left of a value and the components of a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator<<(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs << rhs[0])>{
      lhs << rhs[0],
      lhs << rhs[1],
    };
  }

  // Returns the bitwise shift left of the components of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator<<(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] << rhs)>{
      lhs[0] << rhs,
      lhs[1] << rhs,
    };
  }

  // Returns the bitwise shift left of the components of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator<<(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] << rhs[0])>{
      lhs[0] << rhs[0],
      lhs[1] << rhs[1],
    };
  }

  // Returns the bitwise shift right of a value and the components of a vec.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator>>(
      const T& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs >> rhs[0])>{
      lhs >> rhs[0],
      lhs >> rhs[1],
    };
  }

  // Returns the bitwise shift right of the components of a vec and a value.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator>>(
      const vec2<T>& lhs,
      const U& rhs) noexcept
  {
    return vec2<decltype(lhs[0] >> rhs)>{
      lhs[0] >> rhs,
      lhs[1] >> rhs,
    };
  }

  // Returns the bitwise shift right of the components of two vec's.
  template<typename T, typename U>
  inline TUE_CONSTEXPR auto operator>>(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return vec2<decltype(lhs[0] >> rhs[0])>{
      lhs[0] >> rhs[0],
      lhs[1] >> rhs[1],
    };
  }

  // Returns true if all the corresponding components of two vec's are equal
  // and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator==(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return lhs[0] == rhs[0]
        && lhs[1] == rhs[1];
  }

  // Returns true if any of the corresponding components of two vec's are not
  // equal and false otherwise.
  template<typename T, typename U>
  inline TUE_CONSTEXPR bool operator!=(
      const vec2<T>& lhs,
      const vec2<U>& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  // Non-member math functions.
  namespace math
  {
    // Returns the component-wise trigonometric sine of the given vec.
    template<typename T>
    inline auto sin(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::sin(v[0]))>{
        math::sin(v[0]),
        math::sin(v[1]),
      };
    }

    // Returns the component-wise trigonometric cosine of the given vec.
    template<typename T>
    inline auto cos(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::cos(v[0]))>{
        math::cos(v[0]),
        math::cos(v[1]),
      };
    }

    // Sets sin_result and cos_result to the component-wise trigonometric sine
    // and cosine respectively of the given vec.
    template<typename T>
    inline void sincos(
        const vec2<T>& v,
        decltype(math::sin(v))& sin_result,
        decltype(math::cos(v))& cos_result) noexcept
    {
      math::sincos(v[0], sin_result[0], cos_result[0]);
      math::sincos(v[1], sin_result[1], cos_result[1]);
    }

    // Returns the component-wise result of raising e (Euler's number) to the
    // given exponents.
    template<typename T>
    inline auto exp(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::exp(v[0]))>{
        math::exp(v[0]),
        math::exp(v[1]),
      };
    }

    // Returns the component-wise natural log of the given vec.
    template<typename T>
    inline auto log(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::log(v[0]))>{
        math::log(v[0]),
        math::log(v[1]),
      };
    }

    // Returns the result of raising each component of base to the given
    // exponent.
    template<typename T, typename U>
    inline auto pow(
        const vec2<T>& base,
        const U& exponent) noexcept
    {
      return vec2<decltype(math::pow(base[0], exponent))>{
        math::pow(base[0], exponent),
        math::pow(base[1], exponent),
      };
    }

    // Returns the result of raising each component of base to the
    // corresponding component of exponent.
    template<typename T, typename U>
    inline auto pow(
        const vec2<T>& base,
        const vec2<U>& exponent) noexcept
    {
      return vec2<decltype(math::pow(base[0], exponent[0]))>{
        math::pow(base[0], exponent[0]),
        math::pow(base[1], exponent[1]),
      };
    }

    // Returns the component-wise reciprocal of the given vec.
    template<typename T>
    inline auto recip(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::recip(v[0]))>{
        math::recip(v[0]),
        math::recip(v[1]),
      };
    }

    // Returns the component-wise square root of the given vec.
    template<typename T>
    inline auto sqrt(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::sqrt(v[0]))>{
        math::sqrt(v[0]),
        math::sqrt(v[1]),
      };
    }

    // Returns the component-wise reciprocal square root of the given vec.
    template<typename T>
    inline auto rsqrt(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::rsqrt(v[0]))>{
        math::rsqrt(v[0]),
        math::rsqrt(v[1]),
      };
    }

    // Returns the component-wise minimum of two vec's.
    template<typename T>
    inline auto min(
        const vec2<T>& v1,
        const vec2<T>& v2) noexcept
    {
      return vec2<decltype(math::min(v1[0], v2[0]))>{
        math::min(v1[0], v2[0]),
        math::min(v1[1], v2[1]),
      };
    }

    // Returns the component-wise maximum of two vec's.
    template<typename T>
    inline auto max(
        const vec2<T>& v1,
        const vec2<T>& v2) noexcept
    {
      return vec2<decltype(math::max(v1[0], v2[0]))>{
        math::max(v1[0], v2[0]),
        math::max(v1[1], v2[1]),
      };
    }

    // Returns the component-wise absolute value of the given vec.
    template<typename T>
    inline auto abs(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::abs(v[0]))>{
        math::abs(v[0]),
        math::abs(v[1]),
      };
    }

    // Returns the dot product of two vec's.
    template<typename T, typename U>
    inline TUE_CONSTEXPR auto dot(
        const vec2<T>& lhs,
        const vec2<U>& rhs) noexcept
    {
      return lhs[0] * rhs[0]
          + lhs[1] * rhs[1];
    }

    // Returns the length (magnitude) squared of the given vec.
    template<typename T>
    inline auto length2(const vec2<T>& v) noexcept
    {
      return math::length2(v[0])
          + math::length2(v[1]);
    }

    // Returns the length (magnitude) of the given vec.
    template<typename T>
    inline auto length(const vec2<T>& v) noexcept
    {
      return math::sqrt(math::length2(v));
    }

    // Returns the given vec divided by its length (magnitude).
    template<typename T>
    inline auto normalize(const vec2<T>& v) noexcept
    {
      return vec2<decltype(math::length(v))>(v) / math::length(v);
    }
  }
}

#undef TUE_CONSTEXPR
