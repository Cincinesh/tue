//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstdint>

namespace tue {

enum bool8 : std::uint8_t {
  true8 = 0xFFu,
  false8 = 0x00u,
};

enum bool16 : std::uint16_t {
  true16 = 0xFFFFu,
  false16 = 0x0000u,
};

enum bool32 : std::uint32_t {
  true32 = 0xFFFFFFFFul,
  false32 = 0x00000000ul,
};

enum bool64 : std::uint64_t {
  true64 = 0xFFFFFFFFFFFFFFFFull,
  false64 = 0x0000000000000000ull,
};

}
