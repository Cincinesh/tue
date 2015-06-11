//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <xmmintrin.h>

#include "../bool.hpp"
#include "../simd.hpp"

namespace tue {

template<>
class simd<bool32, 4>
{
public:
  using component_type = bool32;

  static constexpr int component_count = 4;

private:
  __m128 underlying_;

public:
  simd() noexcept = default;

  simd(bool32 x, bool32 y, bool32 z, bool32 w) noexcept
    : underlying_(_mm_setr_ps(
          detail_::binary_float(x),
          detail_::binary_float(y),
          detail_::binary_float(z),
          detail_::binary_float(w))) {
  }

  explicit simd(bool32 b) noexcept
    : underlying_(_mm_set_ps1(detail_::binary_float(b))) {
  }

  simd(__m128 underlying) noexcept
    : underlying_(underlying) {
  }

  operator __m128() const noexcept {
    return underlying_;
  }

  static bool32x4 load(const bool32* array) noexcept {
    return _mm_load_ps(reinterpret_cast<const float*>(array));
  }

  static bool32x4 loadu(const bool32* array) noexcept {
    return _mm_loadu_ps(reinterpret_cast<const float*>(array));
  }

  void store(bool32* destination) const noexcept {
    _mm_store_ps(reinterpret_cast<float*>(destination), underlying_);
  }

  void storeu(bool32* destination) const noexcept {
    _mm_storeu_ps(reinterpret_cast<float*>(destination), underlying_);
  }

  bool32x4 operator~() const noexcept {
    return _mm_xor_ps(underlying_, bool32x4(true32));
  }

  bool32x4 operator&(const bool32x4& other) const noexcept {
    return _mm_and_ps(underlying_, other);
  }

  bool32x4 operator|(const bool32x4& other) const noexcept {
    return _mm_or_ps(underlying_, other);
  }

  bool32x4 operator^(const bool32x4& other) const noexcept {
    return _mm_xor_ps(underlying_, other);
  }

  bool32x4& operator&=(const bool32x4& other) noexcept {
      return *this = *this & other;
  }

  bool32x4& operator|=(const bool32x4& other) noexcept {
      return *this = *this | other;
  }

  bool32x4& operator^=(const bool32x4& other) noexcept {
      return *this = *this ^ other;
  }

  bool operator!=(const bool32x4& other) const noexcept {
    return _mm_movemask_ps(_mm_xor_ps(underlying_, other)) != 0;
  }

  bool operator==(const bool32x4& other) const noexcept {
    return !operator!=(other);
  }
};

}
