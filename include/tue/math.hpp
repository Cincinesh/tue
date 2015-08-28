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

/**
 * The Tuesday namespace.
 */
namespace tue
{
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

    /**
     * Math functions.
     */
    namespace math
    {
        /**
         * \brief     Computes the cosine of `x` (measured in radians).
         * \tparam T  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The cosine of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        cos(T x) noexcept
        {
            return std::cos(x);
        }

        /**
         * \brief     Computes the cosine of `x` (measured in radians).
         * \tparam T  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The cosine of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        cos(T x) noexcept
        {
            return std::cos(static_cast<double>(x));
        }

        /**
         * \brief     Computes the sine of `x` (measured in radians).
         * \tparam T  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The sine of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        sin(T x) noexcept
        {
            return std::sin(x);
        }

        /**
         * \brief     Computes the sine of `x` (measured in radians).
         * \tparam T  The type of parameter `x`.
         * \param x   An angle (measured in radians).
         * \return    The sine of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        sin(T x) noexcept
        {
            return std::sin(static_cast<double>(x));
        }

        /**
         * \brief          Computes the sine and cosine of `x` (measured in
         *                 radians).
         *
         * \tparam T       The type of parameter `x`.
         * \param x        An angle (measured in radians).
         * \param sin_out  A reference to the value where the sine of `x` will
         *                 be stored.
         * \param cos_out  A reference to the value where the cosine of `x` will
         *                 be stored.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value>
        sincos(T x, T& sin_out, T& cos_out) noexcept
        {
            sin_out = std::sin(x);
            cos_out = std::cos(x);
        }

        /**
         * \brief          Computes the sine and cosine of `x` (measured in
         *                 radians).
         *
         * \tparam T       The type of parameter `x`.
         * \param x        An angle (measured in radians).
         * \param sin_out  A reference to the value where the sine of
         *                 `static_cast<double>(x)` will be stored.
         * \param cos_out  A reference to the value where the cosine of
         *                 `static_cast<double>(x)` will be stored.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value>
        sincos(T x, double& sin_out, double& cos_out) noexcept
        {
            const auto dx = static_cast<double>(x);
            sin_out = std::sin(dx);
            cos_out = std::cos(dx);
        }

        /**
         * \brief     Computes the base-e exponential of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The base-e exponential of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        exp(T x) noexcept
        {
            return std::exp(x);
        }

        /**
         * \brief     Computes the base-e exponential of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The base-e exponential of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        exp(T x) noexcept
        {
            return std::exp(static_cast<double>(x));
        }

        /**
         * \brief     Computes the base-e (natural) logarithm of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The base-e (natural) logarithm of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        log(T x) noexcept
        {
            return std::log(x);
        }

        /**
         * \brief     Computes the base-e (natural) logarithm of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The base-e (natural) logarithm of
         *            `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        log(T x) noexcept
        {
            return std::log(static_cast<double>(x));
        }

        /**
         * \brief     Computes the absolute value of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A signed number.
         * \return    The absolute value of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_signed<T>::value, T>
        abs(T x) noexcept
        {
            return std::abs(x);
        }

        /**
         * \brief     Computes the absolute value of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An unsigned number.
         * \return    The absolute value of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_unsigned<T>::value, T>
        abs(T x) noexcept
        {
            return x;
        }

        /**
         * \brief     Computes `x` raised to the power `y`.
         * \tparam T  The type of parameter `x`.
         * \tparam U  The type of parameter `y`.
         * \param x   A number.
         * \param y   Another number.
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

        /**
         * \brief     Computes the reciprocal of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The reciprocal of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        recip(T x) noexcept
        {
            return 1 / x;
        }

        /**
         * \brief     Computes the reciprocal of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The reciprocal of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        recip(T x) noexcept
        {
            return 1 / static_cast<double>(x);
        }

        /**
         * \brief     Computes the reciprocal square root of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The reciprocal square root of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        rsqrt(T x) noexcept
        {
            return 1 / std::sqrt(x);
        }

        /**
         * \brief     Computes the reciprocal square root of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The reciprocal square root of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        rsqrt(T x) noexcept
        {
            return 1 / std::sqrt(static_cast<double>(x));
        }

        /**
         * \brief     Computes the nonnegative square root of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   A floating-point number.
         * \return    The nonnegative square root of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        sqrt(T x) noexcept
        {
            return std::sqrt(x);
        }

        /**
         * \brief     Computes the nonnegative square root of `x`.
         * \tparam T  The type of parameter `x`.
         * \param x   An integral number.
         * \return    The nonnegative square root of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        sqrt(T x) noexcept
        {
            return std::sqrt(static_cast<double>(x));
        }

        /**
         * \brief     Determines the maximum numeric value of the arguments.
         * \tparam T  The type of parameters `x` and `y`.
         * \param x   A number.
         * \param y   Another number.
         * \return    The maximum numeric value of the arguments.
         */
        template<typename T>
        inline std::enable_if_t<std::is_arithmetic<T>::value, T>
        max(T x, T y) noexcept
        {
            return std::max(x, y);
        }

        /**
         * \brief     Determines the minimum numeric value of the arguments.
         * \tparam T  The type of parameters `x` and `y`.
         * \param x   A number.
         * \param y   Another number.
         * \return    The minimum numeric value of the arguments.
         */
        template<typename T>
        inline std::enable_if_t<std::is_arithmetic<T>::value, T>
        min(T x, T y) noexcept
        {
            return std::min(x, y);
        }
    }
}
