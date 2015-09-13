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

    /*!
     * \brief        Provides type aliases and constants for the sized boolean
     *               type (`bool8`, `bool16`, `bool32`, or `bool64`) with the
     *               given size.
     *
     * \tparam Size  The desired sized boolean type size (in bytes).
     */
    template<std::size_t Size>
    struct sized_bool_traits
    {
    private:
        using boolX = bool;
        using uintX_t = unsigned int;

        static constexpr bool trueX = true;
        static constexpr bool falseX = false;

        std::enable_if_t<Size == 1 || Size == 2 || Size == 4 || Size == 8>
        impl_;

    public:
        /*!
         * \brief    The sized boolean type with the given size.
         * \details  See `tue::sized_bool_t` for an easier way to access this
         *           type alias.
         */
        using type = boolX;

        /*!
         * \brief  The exact-width unsigned integral type with the given size.
         */
        using uint_t = uintX_t;

        /*!
         * \brief  The given size.
         */
        static constexpr std::size_t size = Size;

        /*!
         * \brief  The `true` value for the sized boolean type with the given
         *         size.
         */
        static constexpr boolX true_value = trueX;

        /*!
         * \brief  The `false` value for the sized boolean type with the given
         *         size.
         */
        static constexpr boolX false_value = falseX;
    };

    /*!
     * \brief        A type alias for the sized boolean type (`bool8`, `bool16`,
     *               `bool32`, or `bool64`) with the given size.
     *
     * \tparam Size  The desired sized boolean type size (in bytes).
     */
    template<std::size_t Size>
    using sized_bool_t = typename sized_bool_traits<Size>::type;

    /*!
     * \brief     Checks if a type is a sized boolean type (`bool8`, `bool16`,
     *            `bool32`, or `bool64`).
     * \details   Extends `std::integral_constant<bool, true>` if true and
     *            `std::integral_constant<bool, false>` otherwise.
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_sized_bool;
}

#include "detail_/sized_bool_traits.hpp"
#include "detail_/is_sized_bool.hpp"

namespace tue
{
    /*!
     * \brief      Computes the bitwise AND of `lhs` and `rhs`.
     *
     * \tparam T   The type of the parameters.
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
        return tue::detail_::bitwise_and_operator_bb(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of `lhs` and `rhs`.
     *
     * \tparam T   The type of the parameters.
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
        return tue::detail_::bitwise_or_operator_bb(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of `lhs` and `rhs`.
     *
     * \tparam T   The type of the parameters.
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
        return tue::detail_::bitwise_xor_operator_bb(lhs, rhs);
    }

    namespace math
    {
        /*!
         * \brief            Selects a return value based on `condition`.
         *
         * \tparam T         The condition type.
         * \tparam U         The return type.
         *
         * \param condition  The condition.
         * \param value      The return value when condition is `true`.
         *
         * \return           `value` or `0` depending on `condition`.
         */
        template<typename T, typename U>
        inline constexpr std::enable_if_t<
            is_sized_bool<T>::value
                && (std::is_arithmetic<U>::value || is_sized_bool<U>::value)
                && sizeof(T) == sizeof(U),
            U>
        select(T condition, U value) noexcept
        {
            return tue::detail_::select_bx(condition, value);
        }

        /*!
         * \brief            Selects a return value based on `condition`.
         *
         * \tparam T         The condition type.
         * \tparam U         The return type.
         *
         * \param condition  The condition.
         * \param value      The return value when condition is `true`.
         * \param otherwise  The return value when condition is `false`.
         *
         * \return           `value` or `otherwise` depending on `condition`.
         */
        template<typename T, typename U>
        inline constexpr std::enable_if_t<
            is_sized_bool<T>::value
                && (std::is_arithmetic<U>::value || is_sized_bool<U>::value)
                && sizeof(T) == sizeof(U),
            U>
        select(T condition, U value, U otherwise) noexcept
        {
            return tue::detail_::select_bxx(condition, value, otherwise);
        }
    }
}
