//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

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
  bool32 x, y, z, w;

public:
  simd() noexcept = default;

  simd(bool32 x, bool32 y, bool32 z, bool32 w) noexcept
    : x(x), y(y), z(z), w(w) {
  }

  explicit simd(bool32 s) noexcept
    : x(s), y(s), z(s), w(s) {
  }

  static bool32x4 load(const bool32* array) noexcept {
    return { array[0], array[1], array[2], array[3] };
  }

  static bool32x4 loadu(const bool32* array) noexcept {
    return load(array);
  }

  void store(bool32* destination) const noexcept {
    destination[0] = x;
    destination[1] = y;
    destination[2] = z;
    destination[3] = w;
  }

  void storeu(bool32* destination) const noexcept {
    store(destination);
  }

  bool32x4 operator~() const noexcept {
    return {
      static_cast<bool32>(~x),
      static_cast<bool32>(~y),
      static_cast<bool32>(~z),
      static_cast<bool32>(~w),
    };
  }

  bool32x4 operator&(const bool32x4& other) const noexcept {
    return {
      static_cast<bool32>(x & other.x),
      static_cast<bool32>(y & other.y),
      static_cast<bool32>(z & other.z),
      static_cast<bool32>(w & other.w),
    };
  }

  bool32x4 operator|(const bool32x4& other) const noexcept {
    return {
      static_cast<bool32>(x | other.x),
      static_cast<bool32>(y | other.y),
      static_cast<bool32>(z | other.z),
      static_cast<bool32>(w | other.w),
    };
  }

  bool32x4 operator^(const bool32x4& other) const noexcept {
    return {
      static_cast<bool32>(x ^ other.x),
      static_cast<bool32>(y ^ other.y),
      static_cast<bool32>(z ^ other.z),
      static_cast<bool32>(w ^ other.w),
    };
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

  bool operator==(const bool32x4& other) const noexcept {
    return x == other.x
        && y == other.y
        && z == other.z
        && w == other.w;
  }

  bool operator!=(const bool32x4& other) const noexcept {
    return !operator==(other);
  }
};

namespace math
{
  inline bool32x4 not_equal(
      const bool32x4& lhs,
      const bool32x4& rhs) noexcept {
    return lhs ^ rhs;
  }

  inline bool32x4 equal(
      const bool32x4& lhs,
      const bool32x4& rhs) noexcept {
    return ~math::not_equal(lhs, rhs);
  }
}

}
