//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstdint>

namespace tue
{
    /*!
     * \brief  An 8-bit boolean value.
     */
    enum bool8 : std::uint8_t
    {
        /*!
         * \brief  An 8-bit boolean value with all 8 bits set to 1 (true).
         */
        true8 = UINT8_C(0xFF),

        /*!
         * \brief  An 8-bit boolean value with all 8 bits set to 0 (false).
         */
        false8 = UINT8_C(0x00),
    };

    /*!
     * \brief  A 16-bit boolean value.
     */
    enum bool16 : std::uint16_t
    {
        /*!
         * \brief  A 16-bit boolean value with all 16 bits set to 1 (true).
         */
        true16 = UINT16_C(0xFFFF),

        /*!
         * \brief  A 16-bit boolean value with all 16 bits set to 0 (false).
         */
        false16 = UINT16_C(0x0000),
    };

    /*!
     * \brief  A 32-bit boolean value.
     */
    enum bool32 : std::uint32_t
    {
        /*!
         * \brief  A 32-bit boolean value with all 32 bits set to 1 (true).
         */
        true32 = UINT32_C(0xFFFFFFFF),

        /*!
         * \brief  A 32-bit boolean value with all 32 bits set to 0 (false).
         */
        false32 = UINT32_C(0x00000000),
    };

    /*!
     * \brief  A 64-bit boolean value.
     */
    enum bool64 : std::uint64_t
    {
        /*!
         * \brief  A 64-bit boolean value with all 64 bits set to 1 (true).
         */
        true64 = UINT64_C(0xFFFFFFFFFFFFFFFF),

        /*!
         * \brief  A 64-bit boolean value with all 64 bits set to 0 (false).
         */
        false64 = UINT64_C(0x0000000000000000),
    };
}
