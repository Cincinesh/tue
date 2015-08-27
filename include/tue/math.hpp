//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cmath>
#include <cstdlib>
#include <type_traits>

/**
 * The Tuesday namespace.
 */
namespace tue
{
    /**
     * Math functions.
     */
    namespace math
    {
        /**
         * \brief    Computes the cosine of `x` (measured in radians).
         * \param x  An angle (measured in radians).
         * \return   The cosine of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        cos(T x) noexcept
        {
            return std::cos(x);
        }

        /**
         * \brief    Computes the cosine of `x` (measured in radians).
         * \param x  An angle (measured in radians).
         * \return   The cosine of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        cos(T x) noexcept
        {
            return std::cos(static_cast<double>(x));
        }

        /**
         * \brief    Computes the sine of `x` (measured in radians).
         * \param x  An angle (measured in radians).
         * \return   The sine of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        sin(T x) noexcept
        {
            return std::sin(x);
        }

        /**
         * \brief    Computes the sine of `x` (measured in radians).
         * \param x  An angle (measured in radians).
         * \return   The sine of `static_cast<double>(x)`.
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
            ::tue::math::sincos(static_cast<double>(x), sin_out, cos_out);
        }

        /**
         * \brief    Computes the base-e exponential of `x`.
         * \param x  A floating-point number.
         * \return   The base-e exponential of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        exp(T x) noexcept
        {
            return std::exp(x);
        }

        /**
         * \brief    Computes the base-e exponential of `x`.
         * \param x  An integral number.
         * \return   The base-e exponential of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        exp(T x) noexcept
        {
            return std::exp(static_cast<double>(x));
        }

        /**
         * \brief    Computes the base-e (natural) logarithm of `x`.
         * \param x  A floating-point number.
         * \return   The base-e (natural) logarithm of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_floating_point<T>::value, T>
        log(T x) noexcept
        {
            return std::log(x);
        }

        /**
         * \brief    Computes the base-e (natural) logarithm of `x`.
         * \param x  An integral number.
         * \return   The base-e (natural) logarithm of `static_cast<double>(x)`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_integral<T>::value, double>
        log(T x) noexcept
        {
            return std::log(static_cast<double>(x));
        }

        /**
         * \brief    Computes the absolute value of `x`.
         * \param x  A signed number.
         * \return   The absolute value of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_signed<T>::value, T>
        abs(T x) noexcept
        {
            return std::abs(x);
        }

        /**
         * \brief    Computes the absolute value of `x`.
         * \param x  An unsigned number.
         * \return   The absolute value of `x`.
         */
        template<typename T>
        inline std::enable_if_t<std::is_unsigned<T>::value, T>
        abs(T x) noexcept
        {
            return x;
        }
    }
}
