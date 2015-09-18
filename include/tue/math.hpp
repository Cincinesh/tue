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

#include "sized_bool.hpp"

namespace tue
{
    /**/
    namespace detail_
    {
        template<typename T, typename U>
        using pow_promote_t =
            std::conditional_t<
                std::is_floating_point<T>::value, T,
                std::conditional_t<
                    std::is_integral<U>::value, double,
                    std::conditional_t<
                        (sizeof(U) <= sizeof(double)), double, U>>>;

        template<typename T, typename U>
        using pow_return_t = decltype(std::pow(
            tue::detail_::pow_promote_t<T, U>(),
            tue::detail_::pow_promote_t<U, T>()));
    }

    /**/
    namespace math
    {
        /*!
         * \defgroup  math_hpp <tue/math.hpp>
         * \brief     Global math functions for arithmetic types.
         * @{
         */

        /*!
         * \brief     Computes the sine of `x` (measured in radians).
         * \tparam F  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The sine of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        sin(F x) noexcept
        {
            return std::sin(x);
        }

        /*!
         * \brief     Computes the sine of `x` (measured in radians).
         * \tparam I  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The sine of `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        sin(I x) noexcept
        {
            return std::sin(static_cast<double>(x));
        }

        /*!
         * \brief     Computes the cosine of `x` (measured in radians).
         * \tparam F  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The cosine of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        cos(F x) noexcept
        {
            return std::cos(x);
        }

        /*!
         * \brief     Computes the cosine of `x` (measured in radians).
         * \tparam I  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The cosine of `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        cos(I x) noexcept
        {
            return std::cos(static_cast<double>(x));
        }

        /*!
         * \brief          Computes the sine and cosine of `x` (measured in
         *                 radians).
         *
         * \tparam F       The type of parameter `x`.
         *
         * \param x        An angle (measured in radians).
         * \param sin_out  A reference to the value where the sine of `x` will
         *                 be stored.
         * \param cos_out  A reference to the value where the cosine of `x` will
         *                 be stored.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value>
        sincos(F x, F& sin_out, F& cos_out) noexcept
        {
            sin_out = std::sin(x);
            cos_out = std::cos(x);
        }

        /*!
         * \brief          Computes the sine and cosine of `x` (measured in
         *                 radians).
         *
         * \tparam I       The type of parameter `x`.
         *
         * \param x        An angle (measured in radians).
         * \param sin_out  A reference to the value where the sine of
         *                 `static_cast<double>(x)` will be stored.
         * \param cos_out  A reference to the value where the cosine of
         *                 `static_cast<double>(x)` will be stored.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value>
        sincos(I x, double& sin_out, double& cos_out) noexcept
        {
            const auto dx = static_cast<double>(x);
            sin_out = std::sin(dx);
            cos_out = std::cos(dx);
        }

        /*!
         * \brief     Computes the base-e exponential of `x`.
         * \tparam F  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The base-e exponential of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        exp(F x) noexcept
        {
            return std::exp(x);
        }

        /*!
         * \brief     Computes the base-e exponential of `x`.
         * \tparam I  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The base-e exponential of `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        exp(I x) noexcept
        {
            return std::exp(static_cast<double>(x));
        }

        /*!
         * \brief     Computes the base-e (natural) logarithm of `x`.
         * \tparam F  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The base-e (natural) logarithm of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        log(F x) noexcept
        {
            return std::log(x);
        }

        /*!
         * \brief     Computes the base-e (natural) logarithm of `x`.
         * \tparam I  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The base-e (natural) logarithm of
         *            `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        log(I x) noexcept
        {
            return std::log(static_cast<double>(x));
        }

        /*!
         * \brief     Computes the absolute value of `x`.
         * \tparam S  The type of parameter `x`.
         * \param x   A signed number.
         * \return    The absolute value of `x`.
         */
        template<typename S>
        inline std::enable_if_t<std::is_signed<S>::value, S>
        abs(S x) noexcept
        {
            return std::abs(x);
        }

        /*!
         * \brief     Computes the absolute value of `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   An unsigned number.
         * \return    The absolute value of `x`.
         */
        template<typename U>
        inline std::enable_if_t<std::is_unsigned<U>::value, U>
        abs(U x) noexcept
        {
            return x;
        }

        /*!
         * \brief     Computes `x` raised to the power `y`.
         *
         * \tparam T  The type of parameter `x`.
         * \tparam U  The type of parameter `y`.
         *
         * \param x   A number.
         * \param y   Another number.
         *
         * \return    `x` raised to the power `y`. If `T` and/or `U` are
         *            integral types, `x` and/or `y` will be explicitly cast to
         *            floating-point values as follows:
         *            - If both types are integral types, cast both values to
         *              `double`.
         *            - If one type is an integral type and the other a
         *              floating-point type, cast the integral value to `double`
         *              or to the floating-point type of the other value
         *              (whichever has higher-precision).
         */
        template<typename T, typename U>
        inline std::enable_if_t<(
            std::is_arithmetic<T>::value && std::is_arithmetic<U>::value),
            tue::detail_::pow_return_t<T, U>>
        pow(T x, U y) noexcept
        {
            return std::pow(
                static_cast<tue::detail_::pow_promote_t<T, U>>(x),
                static_cast<tue::detail_::pow_promote_t<U, T>>(y));
        }

        /*!
         * \brief     Computes the reciprocal of `x`.
         * \tparam F  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The reciprocal of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        recip(F x) noexcept
        {
            return 1 / x;
        }

        /*!
         * \brief     Computes the reciprocal of `x`.
         * \tparam I  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The reciprocal of `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        recip(I x) noexcept
        {
            return 1 / static_cast<double>(x);
        }

        /*!
         * \brief     Computes the nonnegative square root of `x`.
         * \tparam F  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The nonnegative square root of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        sqrt(F x) noexcept
        {
            return std::sqrt(x);
        }

        /*!
         * \brief     Computes the nonnegative square root of `x`.
         * \tparam I  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The nonnegative square root of `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        sqrt(I x) noexcept
        {
            return std::sqrt(static_cast<double>(x));
        }

        /*!
         * \brief     Computes the reciprocal nonnegative square root of `x`.
         * \tparam F  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The reciprocal nonnegative square root of `x`.
         */
        template<typename F>
        inline std::enable_if_t<std::is_floating_point<F>::value, F>
        rsqrt(F x) noexcept
        {
            return 1 / std::sqrt(x);
        }

        /*!
         * \brief     Computes the reciprocal nonnegative square root of `x`.
         * \tparam I  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The reciprocal nonnegative square root of
         *            `static_cast<double>(x)`.
         */
        template<typename I>
        inline std::enable_if_t<std::is_integral<I>::value, double>
        rsqrt(I x) noexcept
        {
            return 1 / std::sqrt(static_cast<double>(x));
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
        inline std::enable_if_t<std::is_arithmetic<T>::value, T>
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
        inline std::enable_if_t<std::is_arithmetic<T>::value, T>
        max(T x, T y) noexcept
        {
            return std::max(x, y);
        }

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
        inline std::enable_if_t<
            is_sized_bool<T>::value
            && (std::is_arithmetic<U>::value || is_sized_bool<U>::value)
            && sizeof(U) == sizeof(T), U>
        select(T condition, U value) noexcept
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
         * \param value      The return value when condition is `true`.
         * \param otherwise  The return value when condition is `false`.
         *
         * \return           `value` or `otherwise` depending on `condition`.
         */
        template<typename T, typename U>
        inline std::enable_if_t<
            is_sized_bool<T>::value
            && (std::is_arithmetic<U>::value || is_sized_bool<U>::value)
            && sizeof(U) == sizeof(T), U>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value, sized_bool_t<sizeof(T)>>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value, sized_bool_t<sizeof(T)>>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value, sized_bool_t<sizeof(T)>>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value, sized_bool_t<sizeof(T)>>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value || is_sized_bool<T>::value,
            sized_bool_t<sizeof(T)>>
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
        inline constexpr std::enable_if_t<
            std::is_arithmetic<T>::value || is_sized_bool<T>::value,
            sized_bool_t<sizeof(T)>>
        not_equal(T lhs, T rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            return lhs != rhs ? U(~0LL) : U(0LL);
        }

        /*/!@}*/
    }
}
