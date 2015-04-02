//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <xmmintrin.h>

namespace tue {

class boolx4
{
public:
  using component_type = bool;

  static constexpr int component_count = 4;

private:
  __m128 underlying_;

  static float bool_to_float_(bool b) noexcept {
    const unsigned int value = b ? ~0u : 0u;
    return reinterpret_cast<const float&>(value);
  }

public:
  boolx4() noexcept = default;

  boolx4(bool x, bool y, bool z, bool w) noexcept
    : underlying_(_mm_setr_ps(
          bool_to_float_(x),
          bool_to_float_(y),
          bool_to_float_(z),
          bool_to_float_(w))) {
  }

  explicit boolx4(bool b) noexcept
    : underlying_(_mm_set_ps1(bool_to_float_(b))) {
  }

  boolx4(__m128 underlying) noexcept
    : underlying_(underlying) {
  }

  operator __m128() const noexcept {
    return underlying_;
  }

  boolx4 operator~() const noexcept {
    return _mm_xor_ps(underlying_, detail_::binary_m128(~0u));
  }

  boolx4 operator&(const boolx4& other) const noexcept {
    return _mm_and_ps(underlying_, other);
  }

  boolx4 operator|(const boolx4& other) const noexcept {
    return _mm_or_ps(underlying_, other);
  }

  boolx4 operator^(const boolx4& other) const noexcept {
    return _mm_xor_ps(underlying_, other);
  }

  boolx4& operator&=(const boolx4& other) noexcept {
      return *this = *this & other;
  }

  boolx4& operator|=(const boolx4& other) noexcept {
      return *this = *this | other;
  }

  boolx4& operator^=(const boolx4& other) noexcept {
      return *this = *this ^ other;
  }

  bool operator!=(const boolx4& other) const noexcept {
    return _mm_movemask_ps(_mm_xor_ps(underlying_, other)) != 0;
  }

  bool operator==(const boolx4& other) const noexcept {
    return !operator!=(other);
  }
};

}
