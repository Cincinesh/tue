//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace tue {

class boolx4
{
public:
  using component_type = bool;

  static constexpr int component_count = 4;

private:
  bool x, y, z, w;

public:
  boolx4() noexcept = default;

  boolx4(bool x, bool y, bool z, bool w) noexcept
    : x(x), y(y), z(z), w(w) {
  }

  explicit boolx4(bool s) noexcept
    : x(s), y(s), z(s), w(s) {
  }

  boolx4 operator~() const noexcept {
    return { !x, !y, !z, !w };
  }

  boolx4 operator&(const boolx4& other) const noexcept {
    return {
      x && other.x,
      y && other.y,
      z && other.z,
      w && other.w,
    };
  }

  boolx4 operator|(const boolx4& other) const noexcept {
    return {
      x || other.x,
      y || other.y,
      z || other.z,
      w || other.w,
    };
  }

  boolx4 operator^(const boolx4& other) const noexcept {
    return {
      x != other.x,
      y != other.y,
      z != other.z,
      w != other.w,
    };
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

  bool operator==(const boolx4& other) const noexcept {
    return x == other.x
        && y == other.y
        && z == other.z
        && w == other.w;
  }

  bool operator!=(const boolx4& other) const noexcept {
    return !operator==(other);
  }
};

}
