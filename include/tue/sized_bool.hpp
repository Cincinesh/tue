//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

namespace tue
{
    /*!
     * \defgroup  sized_bool_hpp <tue/sized_bool.hpp>
     *
     * \brief     The sized boolean types and their associated utility structs
     *            and functions.
     * @{
     */

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

    /**/
    namespace detail_
    {
        template<std::size_t Size> struct sized_bool_utils;
        template<> struct sized_bool_utils<1> { using type = bool8; };
        template<> struct sized_bool_utils<2> { using type = bool16; };
        template<> struct sized_bool_utils<4> { using type = bool32; };
        template<> struct sized_bool_utils<8> { using type = bool64; };
    }

    /*!
     * \brief        A type alias for the sized boolean type (`bool8`, `bool16`,
     *               `bool32`, or `bool64`) with the given size.
     *
     * \tparam Size  The desired sized boolean type size (in bytes).
     */
    template<std::size_t Size>
    using sized_bool_t = typename detail_::sized_bool_utils<Size>::type;

    /*!
     * \brief     Checks if a type is a sized boolean type.
     * \details   Extends `std::integral_constant<bool, true>` for the following
     *            types and `std::integral_constant<bool, false>` otherwise:
     *            - `tue::bool8`
     *            - `tue::bool16`
     *            - `tue::bool32`
     *            - `tue::bool64`
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_sized_bool;

    /*!@}*/
}

#include "detail_/is_sized_bool.hpp"

namespace tue
{
    /*!
     * \addtogroup  sized_bool_hpp
     * @{
     */

    /*!
     * \brief     Computes the bitwise NOT of `b`.
     *
     * \tparam T  The type of parameter 'b'.
     *
     * \param b   A sized boolean value.
     *
     * \return    The bitwise NOT of `b`.
     */
    template<typename T>
    inline constexpr std::enable_if_t<is_sized_bool<T>::value, T>
    operator~(T b) noexcept
    {
        using U = std::underlying_type_t<T>;
        return T(~U(b));
    }

    /*!
     * \brief      Computes the bitwise AND of `lhs` and `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of `lhs` and `rhs`.
     */
    template<typename T>
    inline constexpr std::enable_if_t<is_sized_bool<T>::value, T>
    operator&(T lhs, T rhs) noexcept
    {
        using U = std::underlying_type_t<T>;
        return T(U(lhs) & U(rhs));
    }

    /*!
     * \brief      Computes the bitwise OR of `lhs` and `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of `lhs` and `rhs`.
     */
    template<typename T>
    inline constexpr std::enable_if_t<is_sized_bool<T>::value, T>
    operator|(T lhs, T rhs) noexcept
    {
        using U = std::underlying_type_t<T>;
        return T(U(lhs) | U(rhs));
    }

    /*!
     * \brief      Computes the bitwise XOR of `lhs` and `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of `lhs` and `rhs`.
     */
    template<typename T>
    inline constexpr std::enable_if_t<is_sized_bool<T>::value, T>
    operator^(T lhs, T rhs) noexcept
    {
        using U = std::underlying_type_t<T>;
        return T(U(lhs) ^ U(rhs));
    }

    /*!
     * \brief      Bitwise ANDs `lhs` with `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T>
    inline std::enable_if_t<is_sized_bool<T>::value, T&>
    operator&=(T& lhs, T rhs) noexcept
    {
        return lhs = lhs & rhs;
    }

    /*!
     * \brief      Bitwise ORs `lhs` with `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T>
    inline std::enable_if_t<is_sized_bool<T>::value, T&>
    operator|=(T& lhs, T rhs) noexcept
    {
        return lhs = lhs | rhs;
    }

    /*!
     * \brief      Bitwise XORs `lhs` with `rhs`.
     *
     * \tparam T   The type of parameters `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T>
    inline std::enable_if_t<is_sized_bool<T>::value, T&>
    operator^=(T& lhs, T rhs) noexcept
    {
        return lhs = lhs ^ rhs;
    }
}
