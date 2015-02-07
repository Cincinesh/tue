//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
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
  // A 4xR matrix with components of the given type.
  template<typename T, int R>
  class mat<T, 4, R>
  {
  private:
    struct { vec<T, R> columns[4]; } impl_;

  public:
    // Constructs a new mat without a specific value.
    mat() = default;

    // Constructs a new mat with the main diagonal set to the given value and
    // all other components set to 0.
    explicit constexpr mat(const T& s) noexcept
      : impl_({{
          vec<T, R>(vec<T, 4>(s, T(0), T(0), T(0))),
          vec<T, R>(vec<T, 4>(T(0), s, T(0), T(0))),
          vec<T, R>(vec<T, 4>(T(0), T(0), s, T(0))),
          vec<T, R>(vec<T, 4>(T(0), T(0), T(0), s)),
        }}) {}

    // Constructs a new mat with the given columns.
    constexpr mat(
        const vec<T, R>& column0,
        const vec<T, R>& column1,
        const vec<T, R>& column2,
        const vec<T, R>& column3) noexcept
      : impl_({{
          column0,
          column1,
          column2,
          column3,
        }}) {}

    // Constructs a new mat by identity-extending and or truncating another
    // mat.
    template<int OtherR>
    explicit constexpr mat(const mat<T, 2, OtherR>& other) noexcept
      : impl_({{
          vec<T, R>::extend_(other[0], T(0), T(0)),
          vec<T, R>::extend_(other[1], T(0), T(0)),
          vec<T, R>(vec<T, 4>(T(0), T(0), T(1), T(0))),
          vec<T, R>(vec<T, 4>(T(0), T(0), T(0), T(1))),
        }}) {}
    
    // Constructs a new mat by identity-extending and or truncating another
    // mat.
    template<int OtherR>
    explicit constexpr mat(const mat<T, 3, OtherR>& other) noexcept
      : impl_({{
          vec<T, R>::extend_(other[0], T(0), T(0)),
          vec<T, R>::extend_(other[1], T(0), T(0)),
          vec<T, R>::extend_(other[2], T(1), T(0)),
          vec<T, R>(vec<T, 4>(T(0), T(0), T(0), T(1))),
        }}) {}

    // Constructs a new mat by identity-extending and or truncating another
    // mat.
    template<int OtherR>
    explicit constexpr mat(const mat<T, 4, OtherR>& other) noexcept
      : impl_({{
          vec<T, R>::extend_(other[0], T(0), T(0)),
          vec<T, R>::extend_(other[1], T(0), T(0)),
          vec<T, R>::extend_(other[2], T(1), T(0)),
          vec<T, R>::extend_(other[3], T(0), T(1)),
        }}) {}

    // Constructs a new mat that is the result of explicitly casting the
    // components of another mat to to the new component type.
    template<typename U>
    explicit constexpr mat(const mat<U, 4, R>& other) noexcept
      : impl_({{
          vec<T, R>(other[0]),
          vec<T, R>(other[1]),
          vec<T, R>(other[2]),
          vec<T, R>(other[3]),
        }}) {}

    // Returns a new mat that is the result of implicitly casting the
    // components of this mat to another type.
    template<typename U>
    constexpr operator mat<U, 4, R>() const noexcept
    {
      return {
        impl_.columns[0],
        impl_.columns[1],
        impl_.columns[2],
        impl_.columns[3],
      };
    }

    // Returns a mat with the main diagonal set to 1 and all other components
    // set to 0.
    static constexpr mat identity() noexcept
    {
      return mat(T(1));
    }

    // Returns a mat with all the component set to 0.
    static constexpr mat zero() noexcept
    {
      return mat(T(0));
    }

    // Returns the column with the given index.
    template<typename I>
    constexpr vec<T, R> column(const I& i) const noexcept
    {
      return impl_.columns[i];
    }

    // Sets the column with the given index.
    template<typename I>
    void set_column(
        const I& i,
        const vec<T, R>& column) noexcept
    {
      impl_.columns[i] = column;
    }

    // Returns the row with the given index.
    template<typename J>
    constexpr vec<T, 4> row(const J& j) const noexcept
    {
      return {
        impl_.columns[0][j],
        impl_.columns[1][j],
        impl_.columns[2][j],
        impl_.columns[3][j],
      };
    }

    // Sets the row with the given index.
    template<typename J>
    void set_row(
        const J& j,
        const vec<T, 4>& row) noexcept
    {
      impl_.columns[0][j] = row[0];
      impl_.columns[1][j] = row[1];
      impl_.columns[2][j] = row[2];
      impl_.columns[3][j] = row[3];
    }

    // Returns a reference to the column with the given index.
    template<typename I>
    vec<T, R>& operator[](const I& i) noexcept
    {
      return impl_.columns[i];
    }

    // Returns a reference to the column with the given index.
    template<typename I>
    constexpr const vec<T, R>& operator[](const I& i) const noexcept
    {
      return impl_.columns[i];
    }

    // Component-wise increments and returns a reference to this mat.
    mat& operator++() noexcept
    {
      ++impl_.columns[0];
      ++impl_.columns[1];
      ++impl_.columns[2];
      ++impl_.columns[3];
      return *this;
    }

    // Component-wise decrements and returns a reference to this mat.
    mat& operator--() noexcept
    {
      --impl_.columns[0];
      --impl_.columns[1];
      --impl_.columns[2];
      --impl_.columns[3];
      return *this;
    }

    // Component-wise increments this mat and returns the original value.
    mat operator++(int) noexcept
    {
      const auto orig = *this;
      ++*this;
      return orig;
    }

    // Component-wise decrements this mat and returns the original value.
    mat operator--(int) noexcept
    {
      const auto orig = *this;
      --*this;
      return orig;
    }

    // Component-wise adds a value to and returns a reference to this mat.
    template<typename U>
    mat& operator+=(const U& other) noexcept
    {
      impl_.columns[0] += other;
      impl_.columns[1] += other;
      impl_.columns[2] += other;
      impl_.columns[3] += other;
      return *this;
    }

    // Component-wise adds another mat to and returns a reference to this mat.
    template<typename U>
    mat& operator+=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] += other[0];
      impl_.columns[1] += other[1];
      impl_.columns[2] += other[2];
      impl_.columns[3] += other[3];
      return *this;
    }

    // Component-wise subtracts a value from and returns a reference to this
    // mat.
    template<typename U>
    mat& operator-=(const U& other) noexcept
    {
      impl_.columns[0] -= other;
      impl_.columns[1] -= other;
      impl_.columns[2] -= other;
      impl_.columns[3] -= other;
      return *this;
    }

    // Component-wise subtracts another mat from and returns a reference to
    // this mat.
    template<typename U>
    mat& operator-=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] -= other[0];
      impl_.columns[1] -= other[1];
      impl_.columns[2] -= other[2];
      impl_.columns[3] -= other[3];
      return *this;
    }

    // Component-wise multiplies this mat by a value and returns a reference
    // to this mat.
    template<typename U>
    mat& operator*=(const U& other) noexcept
    {
      impl_.columns[0] *= other;
      impl_.columns[1] *= other;
      impl_.columns[2] *= other;
      impl_.columns[3] *= other;
      return *this;
    }

    // Multiplies this math by another mat and returns a reference to this
    // mat.
    template<typename U, int OtherC, int OtherR>
    mat& operator*=(const mat<U, OtherC, OtherR>& other) noexcept
    {
      return *this = *this * other;
    }

    // Component-wise divides this mat by a value and returns a reference to
    // this mat.
    template<typename U>
    mat& operator/=(const U& other) noexcept
    {
      impl_.columns[0] /= other;
      impl_.columns[1] /= other;
      impl_.columns[2] /= other;
      impl_.columns[3] /= other;
      return *this;
    }

    // Component-wise divides this mat by another mat and returns a reference
    // to this mat.
    template<typename U>
    mat& operator/=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] /= other[0];
      impl_.columns[1] /= other[1];
      impl_.columns[2] /= other[2];
      impl_.columns[3] /= other[3];
      return *this;
    }

    // Component-wise modulo-assigns this mat with a value and returns a
    // reference to this mat.
    template<typename U>
    mat& operator%=(const U& other) noexcept
    {
      impl_.columns[0] %= other;
      impl_.columns[1] %= other;
      impl_.columns[2] %= other;
      impl_.columns[3] %= other;
      return *this;
    }

    // Component-wise modulo-assigns this mat with another mat and returns a
    // reference to this mat.
    template<typename U>
    mat& operator%=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] %= other[0];
      impl_.columns[1] %= other[1];
      impl_.columns[2] %= other[2];
      impl_.columns[3] %= other[3];
      return *this;
    }

    // Bitwise and-assigns a value with the components of and returns a
    // reference to this mat.
    template<typename U>
    mat& operator&=(const U& other) noexcept
    {
      impl_.columns[0] &= other;
      impl_.columns[1] &= other;
      impl_.columns[2] &= other;
      impl_.columns[3] &= other;
      return *this;
    }

    // Bitwise and-assigns the components of another mat with the
    // corresponding components of and returns a reference to this mat.
    template<typename U>
    mat& operator&=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] &= other[0];
      impl_.columns[1] &= other[1];
      impl_.columns[2] &= other[2];
      impl_.columns[3] &= other[3];
      return *this;
    }

    // Bitwise or-assigns a value with the components of and returns a
    // reference to this mat.
    template<typename U>
    mat& operator|=(const U& other) noexcept
    {
      impl_.columns[0] |= other;
      impl_.columns[1] |= other;
      impl_.columns[2] |= other;
      impl_.columns[3] |= other;
      return *this;
    }

    // Bitwise or-assigns the components of another mat with the
    // corresponding components of and returns a reference to this mat.
    template<typename U>
    mat& operator|=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] |= other[0];
      impl_.columns[1] |= other[1];
      impl_.columns[2] |= other[2];
      impl_.columns[3] |= other[3];
      return *this;
    }

    // Bitwise xor-assigns a value with the components of and returns a
    // reference to this mat.
    template<typename U>
    mat& operator^=(const U& other) noexcept
    {
      impl_.columns[0] ^= other;
      impl_.columns[1] ^= other;
      impl_.columns[2] ^= other;
      impl_.columns[3] ^= other;
      return *this;
    }

    // Bitwise xor-assigns the components of another mat with the
    // corresponding components of and returns a reference to this mat.
    template<typename U>
    mat& operator^=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] ^= other[0];
      impl_.columns[1] ^= other[1];
      impl_.columns[2] ^= other[2];
      impl_.columns[3] ^= other[3];
      return *this;
    }

    // Bitwise shift left-assigns a value to the components of and returns a
    // reference to this mat.
    template<typename U>
    mat& operator<<=(const U& other) noexcept
    {
      impl_.columns[0] <<= other;
      impl_.columns[1] <<= other;
      impl_.columns[2] <<= other;
      impl_.columns[3] <<= other;
      return *this;
    }

    // Bitwise shift left-assigns the components of another mat to the
    // corresponding components of and returns a reference to this mat.
    template<typename U>
    mat& operator<<=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] <<= other[0];
      impl_.columns[1] <<= other[1];
      impl_.columns[2] <<= other[2];
      impl_.columns[3] <<= other[3];
      return *this;
    }

    // Bitwise shift right-assigns a value to the components of and returns a
    // reference to this mat.
    template<typename U>
    mat& operator>>=(const U& other) noexcept
    {
      impl_.columns[0] >>= other;
      impl_.columns[1] >>= other;
      impl_.columns[2] >>= other;
      impl_.columns[3] >>= other;
      return *this;
    }

    // Bitwise shift right-assigns the components of another mat to the
    // corresponding components of and returns a reference to this mat.
    template<typename U>
    mat& operator>>=(const mat<U, 4, R>& other) noexcept
    {
      impl_.columns[0] >>= other[0];
      impl_.columns[1] >>= other[1];
      impl_.columns[2] >>= other[2];
      impl_.columns[3] >>= other[3];
      return *this;
    }
  };

  // Returns the component-wise unary plus of the given mat.
  template<typename T, int R>
  inline TUE_CONSTEXPR auto operator+(const mat<T, 4, R>& m) noexcept
  {
    return mat<decltype(+m[0][0]), 4, R>(+m[0], +m[1], +m[2], +m[3]);
  }

  // Returns the component-wise negation of the given mat.
  template<typename T, int R>
  inline TUE_CONSTEXPR auto operator-(const mat<T, 4, R>& m) noexcept
  {
    return mat<decltype(-m[0][0]), 4, R>(-m[0], -m[1], -m[2], -m[3]);
  }

  // Returns the bitwise not of the given mat.
  template<typename T, int R>
  inline TUE_CONSTEXPR auto operator~(const mat<T, 4, R>& m) noexcept
  {
    return mat<decltype(~m[0][0]), 4, R>(~m[0], ~m[1], ~m[2], ~m[3]);
  }

  // Returns the component-wise sum of a value and a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator+(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs + rhs[0][0]), 4, R>{
      lhs + rhs[0],
      lhs + rhs[1],
      lhs + rhs[2],
      lhs + rhs[3],
    };
  }

  // Returns the component-wise sum of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator+(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] + rhs), 4, R>{
      lhs[0] + rhs,
      lhs[1] + rhs,
      lhs[2] + rhs,
      lhs[3] + rhs,
    };
  }

  // Returns the component-wise sum of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator+(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] + rhs[0][0]), 4, R>{
      lhs[0] + rhs[0],
      lhs[1] + rhs[1],
      lhs[2] + rhs[2],
      lhs[3] + rhs[3],
    };
  }

  // Returns the component-wise difference between a value and a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator-(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs - rhs[0][0]), 4, R>{
      lhs - rhs[0],
      lhs - rhs[1],
      lhs - rhs[2],
      lhs - rhs[3],
    };
  }

  // Returns the component-wise difference between a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator-(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] - rhs), 4, R>{
      lhs[0] - rhs,
      lhs[1] - rhs,
      lhs[2] - rhs,
      lhs[3] - rhs,
    };
  }

  // Returns the component-wise difference between two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator-(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] - rhs[0][0]), 4, R>{
      lhs[0] - rhs[0],
      lhs[1] - rhs[1],
      lhs[2] - rhs[2],
      lhs[3] - rhs[3],
    };
  }

  // Returns the component-wise product of a value and a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator*(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs * rhs[0][0]), 4, R>{
      lhs * rhs[0],
      lhs * rhs[1],
      lhs * rhs[2],
      lhs * rhs[3],
    };
  }

  // Returns the component-wise product of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator*(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] * rhs), 4, R>{
      lhs[0] * rhs,
      lhs[1] * rhs,
      lhs[2] * rhs,
      lhs[3] * rhs,
    };
  }

  // Returns the component-wise quotient of a value and a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator/(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs / rhs[0][0]), 4, R>{
      lhs / rhs[0],
      lhs / rhs[1],
      lhs / rhs[2],
      lhs / rhs[3],
    };
  }

  // Returns the component-wise quotient of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator/(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] / rhs), 4, R>{
      lhs[0] / rhs,
      lhs[1] / rhs,
      lhs[2] / rhs,
      lhs[3] / rhs,
    };
  }

  // Returns the component-wise quotient of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator/(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] / rhs[0][0]), 4, R>{
      lhs[0] / rhs[0],
      lhs[1] / rhs[1],
      lhs[2] / rhs[2],
      lhs[3] / rhs[3],
    };
  }

  // Returns the component-wise modulus of a value and a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator%(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs % rhs[0][0]), 4, R>{
      lhs % rhs[0],
      lhs % rhs[1],
      lhs % rhs[2],
      lhs % rhs[3],
    };
  }

  // Returns the component-wise modulus of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator%(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] % rhs), 4, R>{
      lhs[0] % rhs,
      lhs[1] % rhs,
      lhs[2] % rhs,
      lhs[3] % rhs,
    };
  }

  // Returns the component-wise modulus of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator%(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] % rhs[0][0]), 4, R>{
      lhs[0] % rhs[0],
      lhs[1] % rhs[1],
      lhs[2] % rhs[2],
      lhs[3] % rhs[3],
    };
  }

  // Returns the bitwise and of a value and the components of a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator&(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs & rhs[0][0]), 4, R>{
      lhs & rhs[0],
      lhs & rhs[1],
      lhs & rhs[2],
      lhs & rhs[3],
    };
  }

  // Returns the bitwise and of the components of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator&(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] & rhs), 4, R>{
      lhs[0] & rhs,
      lhs[1] & rhs,
      lhs[2] & rhs,
      lhs[3] & rhs,
    };
  }

  // Returns the bitwise and of the components of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator&(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] & rhs[0][0]), 4, R>{
      lhs[0] & rhs[0],
      lhs[1] & rhs[1],
      lhs[2] & rhs[2],
      lhs[3] & rhs[3],
    };
  }

  // Returns the bitwise or of a value and the components of a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator|(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs | rhs[0][0]), 4, R>{
      lhs | rhs[0],
      lhs | rhs[1],
      lhs | rhs[2],
      lhs | rhs[3],
    };
  }

  // Returns the bitwise or of the components of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator|(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] | rhs), 4, R>{
      lhs[0] | rhs,
      lhs[1] | rhs,
      lhs[2] | rhs,
      lhs[3] | rhs,
    };
  }

  // Returns the bitwise or of the components of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator|(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] | rhs[0][0]), 4, R>{
      lhs[0] | rhs[0],
      lhs[1] | rhs[1],
      lhs[2] | rhs[2],
      lhs[3] | rhs[3],
    };
  }

  // Returns the bitwise xor of a value and the components of a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator^(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs ^ rhs[0][0]), 4, R>{
      lhs ^ rhs[0],
      lhs ^ rhs[1],
      lhs ^ rhs[2],
      lhs ^ rhs[3],
    };
  }

  // Returns the bitwise xor of the components of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator^(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] ^ rhs), 4, R>{
      lhs[0] ^ rhs,
      lhs[1] ^ rhs,
      lhs[2] ^ rhs,
      lhs[3] ^ rhs,
    };
  }

  // Returns the bitwise xor of the components of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator^(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] ^ rhs[0][0]), 4, R>{
      lhs[0] ^ rhs[0],
      lhs[1] ^ rhs[1],
      lhs[2] ^ rhs[2],
      lhs[3] ^ rhs[3],
    };
  }

  // Returns the bitwise shift left of a value and the components of a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator<<(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs << rhs[0][0]), 4, R>{
      lhs << rhs[0],
      lhs << rhs[1],
      lhs << rhs[2],
      lhs << rhs[3],
    };
  }

  // Returns the bitwise shift left of the components of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator<<(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] << rhs), 4, R>{
      lhs[0] << rhs,
      lhs[1] << rhs,
      lhs[2] << rhs,
      lhs[3] << rhs,
    };
  }

  // Returns the bitwise shift left of the components of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator<<(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] << rhs[0][0]), 4, R>{
      lhs[0] << rhs[0],
      lhs[1] << rhs[1],
      lhs[2] << rhs[2],
      lhs[3] << rhs[3],
    };
  }

  // Returns the bitwise shift right of a value and the components of a mat.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator>>(
      const T& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs >> rhs[0][0]), 4, R>{
      lhs >> rhs[0],
      lhs >> rhs[1],
      lhs >> rhs[2],
      lhs >> rhs[3],
    };
  }

  // Returns the bitwise shift right of the components of a mat and a value.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator>>(
      const mat<T, 4, R>& lhs,
      const U& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] >> rhs), 4, R>{
      lhs[0] >> rhs,
      lhs[1] >> rhs,
      lhs[2] >> rhs,
      lhs[3] >> rhs,
    };
  }

  // Returns the bitwise shift right of the components of two mat's.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto operator>>(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return mat<decltype(lhs[0][0] >> rhs[0][0]), 4, R>{
      lhs[0] >> rhs[0],
      lhs[1] >> rhs[1],
      lhs[2] >> rhs[2],
      lhs[3] >> rhs[3],
    };
  }

  // Returns true if all the corresponding components of each two mat's are
  // equal and false otherwise.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR bool operator==(
          const mat<T, 4, R>& lhs,
          const mat<U, 4, R>& rhs) noexcept
  {
    return lhs[0] == rhs[0]
        && lhs[1] == rhs[1]
        && lhs[2] == rhs[2]
        && lhs[3] == rhs[3];
  }

  // Returns true if any of the corresponding components of two mat's are
  // not equal and false otherwise.
  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR bool operator!=(
      const mat<T, 4, R>& lhs,
      const mat<U, 4, R>& rhs) noexcept
  {
    return !(lhs == rhs);
  }

  // Non-member math functions.
  namespace math
  {
    // Returns the component-wise trigonometric sine of the given mat.
    template<typename T, int R>
    inline auto sin(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::sin(m[0][0])), 4, R>{
        math::sin(m[0]),
        math::sin(m[1]),
        math::sin(m[2]),
        math::sin(m[3]),
      };
    }

    // Returns the component-wise trigonometric cosine of the given mat.
    template<typename T, int R>
    inline auto cos(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::cos(m[0][0])), 4, R>{
        math::cos(m[0]),
        math::cos(m[1]),
        math::cos(m[2]),
        math::cos(m[3]),
      };
    }

    // Sets sin_result and cos_result to the component-wise trigonometric sine
    // and cosine respectively of the given mat.
    template<typename T, int R>
    inline void sincos(
        const mat<T, 4, R>& m,
        decltype(math::sin(m))& sin_result,
        decltype(math::cos(m))& cos_result) noexcept
    {
      math::sincos(m[0], sin_result[0], cos_result[0]);
      math::sincos(m[1], sin_result[1], cos_result[1]);
      math::sincos(m[2], sin_result[2], cos_result[2]);
      math::sincos(m[3], sin_result[3], cos_result[3]);
    }

    // Returns the component-wise result of raising e (Euler's number) to the
    // given exponents.
    template<typename T, int R>
    inline auto exp(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::exp(m[0][0])), 4, R>{
        math::exp(m[0]),
        math::exp(m[1]),
        math::exp(m[2]),
        math::exp(m[3]),
      };
    }

    // Returns the component-wise natural log of the given mat.
    template<typename T, int R>
    inline auto log(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::log(m[0][0])), 4, R>{
        math::log(m[0]),
        math::log(m[1]),
        math::log(m[2]),
        math::log(m[3]),
      };
    }

    // Returns the result of raising each component of base to the given
    // exponent.
    template<typename T, typename U, int R>
    inline auto pow(
        const mat<T, 4, R>& base,
        const U& exponent) noexcept
    {
      return mat<decltype(math::pow(base[0][0], exponent)), 4, R>{
        math::pow(base[0], exponent),
        math::pow(base[1], exponent),
        math::pow(base[2], exponent),
        math::pow(base[3], exponent),
      };
    }

    // Returns the result of raising each component of base to the
    // corresponding component of exponent.
    template<typename T, typename U, int R>
    inline auto pow(
        const mat<T, 4, R>& base,
        const mat<U, 4, R>& exponent) noexcept
    {
      return mat<decltype(math::pow(base[0][0], exponent[0][0])), 4, R>{
        math::pow(base[0], exponent[0]),
        math::pow(base[1], exponent[1]),
        math::pow(base[2], exponent[2]),
        math::pow(base[3], exponent[3]),
      };
    }

    // Returns the component-wise reciprocal of the given mat.
    template<typename T, int R>
    inline auto recip(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::recip(m[0][0])), 4, R>{
        math::recip(m[0]),
        math::recip(m[1]),
        math::recip(m[2]),
        math::recip(m[3]),
      };
    }

    // Returns the component-wise square root of the given mat.
    template<typename T, int R>
    inline auto sqrt(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::sqrt(m[0][0])), 4, R>{
        math::sqrt(m[0]),
        math::sqrt(m[1]),
        math::sqrt(m[2]),
        math::sqrt(m[3]),
      };
    }

    // Returns the component-wise reciprocal square root of the given mat.
    template<typename T, int R>
    inline auto rsqrt(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::rsqrt(m[0][0])), 4, R>{
        math::rsqrt(m[0]),
        math::rsqrt(m[1]),
        math::rsqrt(m[2]),
        math::rsqrt(m[3]),
      };
    }

    // Returns the component-wise minimum of two mat's.
    template<typename T, int R>
    inline auto min(
        const mat<T, 4, R>& m1,
        const mat<T, 4, R>& m2) noexcept
    {
      return mat<decltype(math::min(m1[0][0], m2[0][0])), 4, R>{
        math::min(m1[0], m2[0]),
        math::min(m1[1], m2[1]),
        math::min(m1[2], m2[2]),
        math::min(m1[3], m2[3]),
      };
    }

    // Returns the component-wise maximum of two mat's.
    template<typename T, int R>
    inline auto max(
        const mat<T, 4, R>& m1,
        const mat<T, 4, R>& m2) noexcept
    {
      return mat<decltype(math::max(m1[0][0], m2[0][0])), 4, R>{
        math::max(m1[0], m2[0]),
        math::max(m1[1], m2[1]),
        math::max(m1[2], m2[2]),
        math::max(m1[3], m2[3]),
      };
    }

    // Returns the component-wise absolute value of the given mat.
    template<typename T, int R>
    inline auto abs(const mat<T, 4, R>& m) noexcept
    {
      return mat<decltype(math::abs(m[0][0])), 4, R>{
        math::abs(m[0]),
        math::abs(m[1]),
        math::abs(m[2]),
        math::abs(m[3]),
      };
    }

    // Returns the component-wise product of two mat's.
  template<typename T, typename U, int R>
    inline TUE_CONSTEXPR auto compmult(
        const mat<T, 4, R>& lhs,
        const mat<U, 4, R>& rhs) noexcept
    {
      return mat<decltype(lhs[0][0] * rhs[0][0]), 4, R>{
        lhs[0] * rhs[0],
        lhs[1] * rhs[1],
        lhs[2] * rhs[2],
        lhs[3] * rhs[3],
      };
    }

    // Returns the transpose of the given mat.
    template<typename T, int R>
    inline TUE_CONSTEXPR mat<T, 4, R> transpose(
        const mat<T, R, 4>& m) noexcept
    {
      return {
        m.row(0),
        m.row(1),
        m.row(2),
        m.row(3),
      };
    }
  }
}

#undef TUE_CONSTEXPR
#include "matmult.hpp"
