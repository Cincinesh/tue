//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstdint>
#include <xmmintrin.h>

namespace tue {

namespace detail_
{
  inline __m128 binary_m128(std::uint32_t value) noexcept {
    return _mm_load1_ps(reinterpret_cast<const float*>(&value));
  }
}

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

  explicit boolx4(bool b) noexcept
    : underlying_(_mm_set_ps1(bool_to_float_(b))) {
  }

  boolx4(bool x, bool y, bool z, bool w) noexcept
    : underlying_(_mm_setr_ps(
          bool_to_float_(x),
          bool_to_float_(y),
          bool_to_float_(z),
          bool_to_float_(w))) {
  }

  boolx4(__m128 underlying) noexcept
    : underlying_(underlying) {
  }

  operator __m128() const noexcept {
    return underlying_;
  }
};

inline boolx4 operator&(const boolx4& lhs, const boolx4& rhs) noexcept {
  return _mm_and_ps(lhs, rhs);
}

inline boolx4 operator|(const boolx4& lhs, const boolx4& rhs) noexcept {
  return _mm_or_ps(lhs, rhs);
}

inline boolx4 operator^(const boolx4& lhs, const boolx4& rhs) noexcept {
  return _mm_xor_ps(lhs, rhs);
}

inline boolx4 operator~(const boolx4& v) noexcept {
  return _mm_xor_ps(v, detail_::binary_m128(0xFFFFFFFFu));
}

}
