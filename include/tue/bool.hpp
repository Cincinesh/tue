//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstdint>

namespace tue {

enum bool8 : std::uint8_t {
  true8 = UINT8_C(0xFF),
  false8 = UINT8_C(0x00),
};

enum bool16 : std::uint16_t {
  true16 = UINT16_C(0xFFFF),
  false16 = UINT16_C(0x0000),
};

enum bool32 : std::uint32_t {
  true32 = UINT32_C(0xFFFFFFFF),
  false32 = UINT32_C(0x00000000),
};

enum bool64 : std::uint64_t {
  true64 = UINT64_C(0xFFFFFFFFFFFFFFFF),
  false64 = UINT64_C(0x0000000000000000),
};

}
