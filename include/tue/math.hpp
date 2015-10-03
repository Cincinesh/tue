//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <type_traits>

#include "detail_/is_arithmetic_simd_component.hpp"
#include "detail_/is_floating_point_simd_component.hpp"
#include "detail_/is_simd_component.hpp"
#include "sized_bool.hpp"

/*!
 * \defgroup  math_hpp <tue/math.hpp>
 *
 * \brief     Global math functions for basic scalar types.
 *
 * \details   The allowable types are restricted to those which can be used as
 *            SIMD components.
 */
namespace tue
{
    namespace detail_
    {
        template<typename T>
        inline std::enable_if_t<std::is_signed<T>::value, T>
        abs(T x) noexcept
        {
            return std::abs(x);
        }

        template<typename U>
        inline std::enable_if_t<std::is_unsigned<U>::value, U>
        abs(U x) noexcept
        {
            return x;
        }
    }

    namespace math
    {
        /*!
         * \addtogroup  math_hpp
         * @{
         */

        /*!
         * \brief     Computes the sine of `x` (measured in radians).
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The sine of `x` (measured in radians).
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        sin(T x) noexcept
        {
            return std::sin(x);
        }

        /*!
         * \brief     Computes the cosine of `x` (measured in radians).
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The cosine of `x` (measured in radians).
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        cos(T x) noexcept
        {
            return std::cos(x);
        }

        /*!
         * \brief          Computes the sine and cosine of `x` (measured in
         *                 radians).
         *
         * \tparam T       The type of parameter `x`.
         *
         * \param x        A floating-point number.
         * \param sin_out  A reference to the value where the sine of `x`
         *                 (measured in radians) will be stored.
         * \param cos_out  A reference to the value where the cosine of `x`
         *                 (measured in radians) will be stored.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value>
        sincos(T x, T& sin_out, T& cos_out) noexcept
        {
            sin_out = std::sin(x);
            cos_out = std::cos(x);
        }

        /*!
         * \brief     Computes the base-e exponential of `x`.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The base-e exponential of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        exp(T x) noexcept
        {
            return std::exp(x);
        }

        /*!
         * \brief     Computes the base-e (natural) logarithm of `x`.
         * \details   If `x` is negative, behavior is undefined.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The base-e (natural) logarithm of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        log(T x) noexcept
        {
            return std::log(x);
        }

        /*!
         * \brief     Computes the absolute value of `x`.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A number.
         *
         * \return    The absolute value of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_arithmetic_simd_component<T>::value, T>
        abs(T x) noexcept
        {
            return tue::detail_::abs(x);
        }

        /*!
         * \brief     Computes `x` raised to the power `y`.
         * \details   If `x` is negative, behavior is undefined.
         *
         * \tparam T  The type of parameters `x` and `y`.
         *
         * \param x   A floating-point number.
         * \param y   Another floating-point number.
         *
         * \return    `x` raised to the power `y`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        pow(T x, T y) noexcept
        {
            return std::pow(x, y);
        }

        /*!
         * \brief     Computes the reciprocal of `x`.
         * \details   If `x` equals `0`, behavior is undefined.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The reciprocal of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        recip(T x) noexcept
        {
            return 1 / x;
        }

        /*!
         * \brief     Computes the nonnegative square root of `x`.
         * \details   If `x` is negative, behavior is undefined.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The nonnegative square root of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        sqrt(T x) noexcept
        {
            return std::sqrt(x);
        }

        /*!
         * \brief     Computes the reciprocal of the nonnegative square root of
         *            `x`.
         * \details   If `x` is less than or equal to `0`, behavior is
         *            undefined.
         *
         * \tparam T  The type of parameter `x`.
         *
         * \param x   A floating-point number.
         *
         * \return    The reciprocal of the nonnegative square root of `x`.
         */
        template<typename T>
        inline std::enable_if_t<is_floating_point_simd_component<T>::value, T>
        rsqrt(T x) noexcept
        {
            return 1 / std::sqrt(x);
        }

        /*!
         * \brief     Determines the minimum numeric value of the arguments.
         *
         * \tparam T  The type of parameters `x` and `y`.
         *
         * \param x   A number.
         * \param y   Another number.
         *
         * \return    The minimum numeric value of the arguments.
         */
        template<typename T>
        inline std::enable_if_t<is_arithmetic_simd_component<T>::value, T>
        min(T x, T y) noexcept
        {
            return std::min(x, y);
        }

        /*!
         * \brief     Determines the maximum numeric value of the arguments.
         *
         * \tparam T  The type of parameters `x` and `y`.
         *
         * \param x   A number.
         * \param y   Another number.
         *
         * \return    The maximum numeric value of the arguments.
         */
        template<typename T>
        inline std::enable_if_t<is_arithmetic_simd_component<T>::value, T>
        max(T x, T y) noexcept
        {
            return std::max(x, y);
        }

        /*!
         * \brief            Computes the bitwise AND of `condition` and
         *                   `value`.
         *
         * \tparam T         The condition type.
         * \tparam U         The return type.
         *
         * \param condition  The condition.
         * \param value      The return value when condition is `trueX` (where
         *                   `X` is the number of bits in `T`).
         *
         * \return           `value` or `0` depending on `condition`.
         */
        template<typename T, typename U>
        inline std::enable_if_t<
            is_sized_bool<T>::value
                && is_simd_component<U>::value
                && sizeof(T) == sizeof(U),
            U>
        mask(T condition, U value) noexcept
        {
            using V = std::underlying_type_t<T>;
            const auto result =
                V(condition) & reinterpret_cast<const V&>(value);

            return reinterpret_cast<const U&>(result);
        }

        /*!
         * \brief            Selects a return value based on `condition`.
         *
         * \tparam T         The condition type.
         * \tparam U         The return type.
         *
         * \param condition  The condition.
         * \param value      The return value when condition is `trueX` (where
         *                   `X` is the number of bits in `T`).
         * \param otherwise  The return value when condition is `falseX` (where
         *                   `X` is the number of bits in `T`).
         *
         * \return           `value` or `otherwise` depending on `condition`.
         */
        template<typename T, typename U>
        inline std::enable_if_t<
            is_sized_bool<T>::value
                && is_simd_component<U>::value
                && sizeof(T) == sizeof(U),
            U>
        select(T condition, U value, U otherwise) noexcept
        {
            using V = std::underlying_type_t<T>;
            const auto result =
                (V(condition) & reinterpret_cast<const V&>(value))
                | (~V(condition) & reinterpret_cast<const V&>(otherwise));

            return reinterpret_cast<const U&>(result);
        }

        /*!
         * \brief      Computes whether or not `lhs` is less than `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is less than `rhs` and `falseX`
         *             otherwise (where `X` is the number of bits in `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_arithmetic_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        less(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs < rhs ? U(~0LL) : U(0LL);
        }

        /*!
         * \brief      Computes whether or not `lhs` is less than or equal to
         *             `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is less than or equal to `rhs` and
         *             `falseX` otherwise (where `X` is the number of bits in
         *             `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_arithmetic_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        less_equal(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs <= rhs ? U(~0LL) : U(0LL);
        }

        /*!
         * \brief      Computes whether or not `lhs` is greater than `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is greater than `rhs` and `falseX`
         *             otherwise (where `X` is the number of bits in `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_arithmetic_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        greater(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs > rhs ? U(~0LL) : U(0LL);
        }

        /*!
         * \brief      Computes whether or not `lhs` is greater than or equal to
         *             `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is greater than or equal to `rhs` and
         *             `falseX` otherwise (where `X` is the number of bits in
         *             `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_arithmetic_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        greater_equal(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs >= rhs ? U(~0LL) : U(0LL);
        }

        /*!
         * \brief      Computes whether or not `lhs` is equal to `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is equal to `rhs` and `falseX` otherwise
         *             (where `X` is the number of bits in `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        equal(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs == rhs ? U(~0LL) : U(0LL);
        }

        /*!
         * \brief      Computes whether or not `lhs` is not equal to `rhs`.
         *
         * \tparam T   The type of parameters `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `trueX` if `lhs` is not equal to `rhs` and `falseX`
         *             otherwise (where `X` is the number of bits in `T`).
         */
        template<typename T>
        inline std::enable_if_t<
            is_simd_component<T>::value, sized_bool_t<sizeof(T)>>
        not_equal(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs != rhs ? U(~0LL) : U(0LL);
        }

        /*/!@}*/
    }
}
