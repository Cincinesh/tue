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

namespace tue {

template<typename T, int R>
class mat<T, 2, R>
{
public:
  using column_type = vec<T, R>;
  using row_type = vec<T, 2>;
  using component_type = T;

  static constexpr int column_count = 2;
  static constexpr int row_count = R;
  static constexpr int component_count = column_count * row_count;

private:
  struct { vec<T, R> columns[2]; } impl_;

public:
  mat() = default;

  explicit constexpr mat(const T& s) noexcept
    : impl_({{
        vec<T, R>(vec<T, 4>(s, T(0), T(0), T(0))),
        vec<T, R>(vec<T, 4>(T(0), s, T(0), T(0))),
      }}) {
  }

  constexpr mat(
      const vec<T, R>& column0,
      const vec<T, R>& column1) noexcept
    : impl_({{
        column0,
        column1,
      }}) {
  }

  template<int OtherR>
  explicit constexpr mat(const mat<T, 2, OtherR>& other) noexcept
    : impl_({{
        vec<T, R>::extend_(other[0], T(0), T(0)),
        vec<T, R>::extend_(other[1], T(0), T(0)),
      }}) {
  }

  template<int OtherR>
  explicit constexpr mat(const mat<T, 3, OtherR>& other) noexcept
    : impl_({{
        vec<T, R>::extend_(other[0], T(0), T(0)),
        vec<T, R>::extend_(other[1], T(0), T(0)),
      }}) {
  }

  template<int OtherR>
  explicit constexpr mat(const mat<T, 4, OtherR>& other) noexcept
    : impl_({{
        vec<T, R>::extend_(other[0], T(0), T(0)),
        vec<T, R>::extend_(other[1], T(0), T(0)),
      }}) {
  }

  template<typename U>
  explicit constexpr mat(const mat<U, 2, R>& other) noexcept
    : impl_({{
        vec<T, R>(other[0]),
        vec<T, R>(other[1]),
      }}) {
  }

  template<typename U>
  constexpr operator mat<U, 2, R>() const noexcept
  {
    return {
      impl_.columns[0],
      impl_.columns[1],
    };
  }

  static constexpr mat identity() noexcept {
    return mat(T(1));
  }

  static constexpr mat zero() noexcept {
    return mat(T(0));
  }

  template<typename I>
  constexpr vec<T, R> column(const I& i) const noexcept {
    return impl_.columns[i];
  }

  template<typename I>
  void set_column(const I& i, const vec<T, R>& column) noexcept {
    impl_.columns[i] = column;
  }

  template<typename J>
  constexpr vec<T, 2> row(const J& j) const noexcept {
    return {
      impl_.columns[0][j],
      impl_.columns[1][j],
    };
  }

  template<typename J>
  void set_row(const J& j, const vec<T, 2>& row) noexcept {
    impl_.columns[0][j] = row[0];
    impl_.columns[1][j] = row[1];
  }

  T* data() noexcept {
    return impl_.columns[0].data();
  }

  const T* data() const noexcept {
    return impl_.columns[0].data();
  }

  vec<T, R>* columns() noexcept {
    return impl_.columns;
  }

  const vec<T, R>* columns() const noexcept {
    return impl_.columns;
  }

  template<typename I>
  vec<T, R>& operator[](const I& i) noexcept {
    return impl_.columns[i];
  }

  template<typename I>
  constexpr const vec<T, R>& operator[](const I& i) const noexcept {
    return impl_.columns[i];
  }

  mat& operator++() noexcept {
    ++impl_.columns[0];
    ++impl_.columns[1];
    return *this;
  }

  mat& operator--() noexcept {
    --impl_.columns[0];
    --impl_.columns[1];
    return *this;
  }

  mat operator++(int) noexcept {
    const auto orig = *this;
    ++*this;
    return orig;
  }

  mat operator--(int) noexcept {
    const auto orig = *this;
    --*this;
    return orig;
  }

  template<typename U>
  mat& operator+=(const U& other) noexcept {
    impl_.columns[0] += other;
    impl_.columns[1] += other;
    return *this;
  }

  template<typename U>
  mat& operator+=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] += other[0];
    impl_.columns[1] += other[1];
    return *this;
  }

  template<typename U>
  mat& operator-=(const U& other) noexcept {
    impl_.columns[0] -= other;
    impl_.columns[1] -= other;
    return *this;
  }

  template<typename U>
  mat& operator-=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] -= other[0];
    impl_.columns[1] -= other[1];
    return *this;
  }

  template<typename U>
  mat& operator*=(const U& other) noexcept {
    impl_.columns[0] *= other;
    impl_.columns[1] *= other;
    return *this;
  }

  template<typename U, int OtherC, int OtherR>
  mat& operator*=(const mat<U, OtherC, OtherR>& other) noexcept {
    return *this = *this * other;
  }

  template<typename U>
  mat& operator/=(const U& other) noexcept {
    impl_.columns[0] /= other;
    impl_.columns[1] /= other;
    return *this;
  }

  template<typename U>
  mat& operator/=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] /= other[0];
    impl_.columns[1] /= other[1];
    return *this;
  }

  template<typename U>
  mat& operator%=(const U& other) noexcept {
    impl_.columns[0] %= other;
    impl_.columns[1] %= other;
    return *this;
  }

  template<typename U>
  mat& operator%=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] %= other[0];
    impl_.columns[1] %= other[1];
    return *this;
  }

  template<typename U>
  mat& operator&=(const U& other) noexcept {
    impl_.columns[0] &= other;
    impl_.columns[1] &= other;
    return *this;
  }

  template<typename U>
  mat& operator&=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] &= other[0];
    impl_.columns[1] &= other[1];
    return *this;
  }

  template<typename U>
  mat& operator|=(const U& other) noexcept {
    impl_.columns[0] |= other;
    impl_.columns[1] |= other;
    return *this;
  }

  template<typename U>
  mat& operator|=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] |= other[0];
    impl_.columns[1] |= other[1];
    return *this;
  }

  template<typename U>
  mat& operator^=(const U& other) noexcept {
    impl_.columns[0] ^= other;
    impl_.columns[1] ^= other;
    return *this;
  }

  template<typename U>
  mat& operator^=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] ^= other[0];
    impl_.columns[1] ^= other[1];
    return *this;
  }

  template<typename U>
  mat& operator<<=(const U& other) noexcept {
    impl_.columns[0] <<= other;
    impl_.columns[1] <<= other;
    return *this;
  }

  template<typename U>
  mat& operator<<=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] <<= other[0];
    impl_.columns[1] <<= other[1];
    return *this;
  }

  template<typename U>
  mat& operator>>=(const U& other) noexcept {
    impl_.columns[0] >>= other;
    impl_.columns[1] >>= other;
    return *this;
  }

  template<typename U>
  mat& operator>>=(const mat<U, 2, R>& other) noexcept {
    impl_.columns[0] >>= other[0];
    impl_.columns[1] >>= other[1];
    return *this;
  }
};

template<typename T, int R>
inline TUE_CONSTEXPR auto operator+(const mat<T, 2, R>& m) noexcept {
  return mat<decltype(+m[0][0]), 2, R>(+m[0], +m[1]);
}

template<typename T, int R>
inline TUE_CONSTEXPR auto operator-(const mat<T, 2, R>& m) noexcept {
  return mat<decltype(-m[0][0]), 2, R>(-m[0], -m[1]);
}

template<typename T, int R>
inline TUE_CONSTEXPR auto operator~(const mat<T, 2, R>& m) noexcept {
  return mat<decltype(~m[0][0]), 2, R>(~m[0], ~m[1]);
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator+(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs + rhs[0][0]), 2, R>{
    lhs + rhs[0],
    lhs + rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator+(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] + rhs), 2, R>{
    lhs[0] + rhs,
    lhs[1] + rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator+(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] + rhs[0][0]), 2, R>{
    lhs[0] + rhs[0],
    lhs[1] + rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator-(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs - rhs[0][0]), 2, R>{
    lhs - rhs[0],
    lhs - rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator-(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] - rhs), 2, R>{
    lhs[0] - rhs,
    lhs[1] - rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator-(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] - rhs[0][0]), 2, R>{
    lhs[0] - rhs[0],
    lhs[1] - rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator*(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs * rhs[0][0]), 2, R>{
    lhs * rhs[0],
    lhs * rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator*(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] * rhs), 2, R>{
    lhs[0] * rhs,
    lhs[1] * rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator/(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs / rhs[0][0]), 2, R>{
    lhs / rhs[0],
    lhs / rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator/(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] / rhs), 2, R>{
    lhs[0] / rhs,
    lhs[1] / rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator/(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] / rhs[0][0]), 2, R>{
    lhs[0] / rhs[0],
    lhs[1] / rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator%(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs % rhs[0][0]), 2, R>{
    lhs % rhs[0],
    lhs % rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator%(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] % rhs), 2, R>{
    lhs[0] % rhs,
    lhs[1] % rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator%(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] % rhs[0][0]), 2, R>{
    lhs[0] % rhs[0],
    lhs[1] % rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator&(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs & rhs[0][0]), 2, R>{
    lhs & rhs[0],
    lhs & rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator&(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] & rhs), 2, R>{
    lhs[0] & rhs,
    lhs[1] & rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator&(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] & rhs[0][0]), 2, R>{
    lhs[0] & rhs[0],
    lhs[1] & rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator|(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs | rhs[0][0]), 2, R>{
    lhs | rhs[0],
    lhs | rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator|(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] | rhs), 2, R>{
    lhs[0] | rhs,
    lhs[1] | rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator|(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] | rhs[0][0]), 2, R>{
    lhs[0] | rhs[0],
    lhs[1] | rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator^(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs ^ rhs[0][0]), 2, R>{
    lhs ^ rhs[0],
    lhs ^ rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator^(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] ^ rhs), 2, R>{
    lhs[0] ^ rhs,
    lhs[1] ^ rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator^(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] ^ rhs[0][0]), 2, R>{
    lhs[0] ^ rhs[0],
    lhs[1] ^ rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator<<(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs << rhs[0][0]), 2, R>{
    lhs << rhs[0],
    lhs << rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator<<(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] << rhs), 2, R>{
    lhs[0] << rhs,
    lhs[1] << rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator<<(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] << rhs[0][0]), 2, R>{
    lhs[0] << rhs[0],
    lhs[1] << rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator>>(
    const T& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs >> rhs[0][0]), 2, R>{
    lhs >> rhs[0],
    lhs >> rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator>>(
    const mat<T, 2, R>& lhs,
    const U& rhs) noexcept {
  return mat<decltype(lhs[0][0] >> rhs), 2, R>{
    lhs[0] >> rhs,
    lhs[1] >> rhs,
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR auto operator>>(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return mat<decltype(lhs[0][0] >> rhs[0][0]), 2, R>{
    lhs[0] >> rhs[0],
    lhs[1] >> rhs[1],
  };
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR bool operator==(
        const mat<T, 2, R>& lhs,
        const mat<U, 2, R>& rhs) noexcept {
  return lhs[0] == rhs[0]
      && lhs[1] == rhs[1];
}

template<typename T, typename U, int R>
inline TUE_CONSTEXPR bool operator!=(
    const mat<T, 2, R>& lhs,
    const mat<U, 2, R>& rhs) noexcept {
  return !(lhs == rhs);
}

namespace math
{
  template<typename T, int R>
  inline auto sin(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::sin(m[0][0])), 2, R>{
      math::sin(m[0]),
      math::sin(m[1]),
    };
  }

  template<typename T, int R>
  inline auto cos(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::cos(m[0][0])), 2, R>{
      math::cos(m[0]),
      math::cos(m[1]),
    };
  }

  template<typename T, int R>
  inline void sincos(
      const mat<T, 2, R>& m,
      decltype(math::sin(m))& sin_result,
      decltype(math::cos(m))& cos_result) noexcept {
    math::sincos(m[0], sin_result[0], cos_result[0]);
    math::sincos(m[1], sin_result[1], cos_result[1]);
  }

  template<typename T, int R>
  inline auto exp(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::exp(m[0][0])), 2, R>{
      math::exp(m[0]),
      math::exp(m[1]),
    };
  }

  template<typename T, int R>
  inline auto log(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::log(m[0][0])), 2, R>{
      math::log(m[0]),
      math::log(m[1]),
    };
  }

  template<typename T, typename U, int R>
  inline auto pow(
      const mat<T, 2, R>& base,
      const U& exponent) noexcept {
    return mat<decltype(math::pow(base[0][0], exponent)), 2, R>{
      math::pow(base[0], exponent),
      math::pow(base[1], exponent),
    };
  }

  template<typename T, typename U, int R>
  inline auto pow(
      const mat<T, 2, R>& base,
      const mat<U, 2, R>& exponent) noexcept {
    return mat<decltype(math::pow(base[0][0], exponent[0][0])), 2, R>{
      math::pow(base[0], exponent[0]),
      math::pow(base[1], exponent[1]),
    };
  }

  template<typename T, int R>
  inline auto recip(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::recip(m[0][0])), 2, R>{
      math::recip(m[0]),
      math::recip(m[1]),
    };
  }

  template<typename T, int R>
  inline auto sqrt(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::sqrt(m[0][0])), 2, R>{
      math::sqrt(m[0]),
      math::sqrt(m[1]),
    };
  }

  template<typename T, int R>
  inline auto rsqrt(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::rsqrt(m[0][0])), 2, R>{
      math::rsqrt(m[0]),
      math::rsqrt(m[1]),
    };
  }

  template<typename T, int R>
  inline auto min(
      const mat<T, 2, R>& m1,
      const mat<T, 2, R>& m2) noexcept {
    return mat<decltype(math::min(m1[0][0], m2[0][0])), 2, R>{
      math::min(m1[0], m2[0]),
      math::min(m1[1], m2[1]),
    };
  }

  template<typename T, int R>
  inline auto max(
      const mat<T, 2, R>& m1,
      const mat<T, 2, R>& m2) noexcept {
    return mat<decltype(math::max(m1[0][0], m2[0][0])), 2, R>{
      math::max(m1[0], m2[0]),
      math::max(m1[1], m2[1]),
    };
  }

  template<typename T, int R>
  inline auto abs(const mat<T, 2, R>& m) noexcept {
    return mat<decltype(math::abs(m[0][0])), 2, R>{
      math::abs(m[0]),
      math::abs(m[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto comp_mult(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(lhs[0][0] * rhs[0][0]), 2, R>{
      lhs[0] * rhs[0],
      lhs[1] * rhs[1],
    };
  }

  template<typename T, int R>
  inline TUE_CONSTEXPR mat<T, 2, R> transpose(
      const mat<T, R, 2>& m) noexcept {
    return {
      m.row(0),
      m.row(1),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto select(
      const mat<T, 2, R>& m,
      const mat<U, 2, R>& mask) noexcept {
    return mat<decltype(math::select(m[0][0], mask[0][0])), 2, R>{
      math::select(m[0], mask[0]),
      math::select(m[1], mask[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto less(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::less(lhs[0][0], rhs[0][0])), 2, R>{
      math::less(lhs[0], rhs[0]),
      math::less(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto less_equal(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::less_equal(lhs[0][0], rhs[0][0])), 2, R>{
      math::less_equal(lhs[0], rhs[0]),
      math::less_equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto greater(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::greater(lhs[0][0], rhs[0][0])), 2, R>{
      math::greater(lhs[0], rhs[0]),
      math::greater(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto greater_equal(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::greater_equal(lhs[0][0], rhs[0][0])), 2, R>{
      math::greater_equal(lhs[0], rhs[0]),
      math::greater_equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto equal(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::equal(lhs[0][0], rhs[0][0])), 2, R>{
      math::equal(lhs[0], rhs[0]),
      math::equal(lhs[1], rhs[1]),
    };
  }

  template<typename T, typename U, int R>
  inline TUE_CONSTEXPR auto not_equal(
      const mat<T, 2, R>& lhs,
      const mat<U, 2, R>& rhs) noexcept {
    return mat<decltype(math::not_equal(lhs[0][0], rhs[0][0])), 2, R>{
      math::not_equal(lhs[0], rhs[0]),
      math::not_equal(lhs[1], rhs[1]),
    };
  }
}

}

#undef TUE_CONSTEXPR
#include "matmult.hpp"
