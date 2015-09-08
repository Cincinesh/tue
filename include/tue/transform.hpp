//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>
#include <utility>

#include "mat.hpp"
#include "math.hpp"
#include "quat.hpp"
#include "vec.hpp"

namespace tue
{
    /*!
     * \brief  Functions for generating and converting between different types
     *         of transformations.
     */
    namespace transform
    {
        /*!
         * \brief     Converts a rotation vector to an axis-angle vector.
         * \details   If the rotation vector's length is `0`, returns
         *            `(0, 0, 1, 0)`.
         *
         * \tparam T  The rotation vector's component type.
         * \param v   The rotation vector.
         * \return    The axis-angle vector.
         */
        template<typename T>
        inline vec4<decltype(tue::math::sqrt(std::declval<T>()))>
        axis_angle(const vec3<T>& v) noexcept
        {
            using U = decltype(tue::math::length(v));
            const auto angle = tue::math::length(v);
            const auto axis = tue::math::select(
                tue::math::not_equal(angle, U(0)),
                v / angle,
                vec3<U>::z_axis());

            return { axis, angle };
        }

        /*!
         * \brief     Converts a rotation vector to an axis-angle vector.
         * \details   If the rotation vector's length is `0`, returns
         *            `(0, 0, 1, 0)`.
         *
         * \tparam T  The rotation vector's component type.
         *
         * \param x   The rotation vector's first component.
         * \param y   The rotation vector's second component.
         * \param z   The rotation vector's third component.
         *
         * \return    The axis-angle vector.
         */
        template<typename T>
        inline vec4<decltype(tue::math::sqrt(std::declval<T>()))>
        axis_angle(const T& x, const T& y, const T& z) noexcept
        {
            return tue::transform::axis_angle(vec3<T>(x, y, z));
        }

        /*!
         * \brief        Converts an axis-angle pair to a rotation vector.
         *
         * \tparam T     The axis-angle component type.
         *
         * \param axis   The axis.
         * \param angle  The angle.
         *
         * \return       The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<T>
        rotation_vec(const vec3<T>& axis, const T& angle) noexcept
        {
            return axis * angle;
        }

        /*!
         * \brief        Converts an axis-angle pair to a rotation vector.
         *
         * \tparam T     The axis-angle component type.
         *
         * \param x      The axis' first component.
         * \param y      The axis' second component.
         * \param z      The axis' third component.
         * \param angle  The angle.
         *
         * \return       The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<T>
        rotation_vec(
            const T& x, const T& y, const T& z,
            const T& angle) noexcept
        {
            return {
                x * angle,
                y * angle,
                z * angle,
            };
        }

        /*!
         * \brief     Converts an axis-angle vector to a rotation vector.
         * \tparam T  The axis-angle component type.
         * \param v   The axis-angle vector.
         * \return    The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<T>
        rotation_vec(const vec4<T>& v) noexcept
        {
            return {
                v[0] * v[3],
                v[1] * v[3],
                v[2] * v[3],
            };
        }

        /*!
         * \brief        Converts an axis-angle pair to a rotation quaternion.
         *
         * \tparam T     The axis-angle component type.
         *
         * \param axis   The axis.
         * \param angle  The angle.
         *
         * \return       The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(const vec3<T>& axis, const T& angle) noexcept
        {
            using U = decltype(tue::math::sin(angle));
            U s, c;
            tue::math::sincos(angle / U(2), s, c);
            return { axis * s, c };
        }

        /*!
         * \brief        Converts an axis-angle pair to a rotation quaternion.
         *
         * \tparam T     The axis-angle component type.
         *
         * \param x      The axis' first component.
         * \param y      The axis' second component.
         * \param z      The axis' third component.
         * \param angle  The angle.
         *
         * \return       The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(
            const T& x, const T& y, const T& z, const T& angle) noexcept
        {
            using U = decltype(tue::math::sin(angle));
            U s, c;
            tue::math::sincos(angle / U(2), s, c);
            return { x*s, y*s, z*s, c };
        }

        /*!
         * \brief     Converts an axis-angle vector to a rotation quaternion.
         * \tparam T  The axis-angle component type.
         * \param v   The axis-angle vector.
         * \return    The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(const vec4<T>& v) noexcept
        {
            using U = decltype(tue::math::sin(v[3]));
            U s, c;
            tue::math::sincos(v[3] / U(2), s, c);
            return { v[0]*s, v[1]*s, v[2]*s, c };
        }

        /*!
         * \brief     Converts a rotation vector to a rotation quaternion.
         * \details   If the rotation vector's length is `0`, returns
         *            `(0, 0, 0, 1)`.
         *
         * \tparam T  The rotation vector's component type.
         * \param v   The rotation vector.
         * \return    The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sqrt(std::declval<T>()))>
        rotation_quat(const vec3<T>& v) noexcept
        {
            return tue::transform::rotation_quat(
                tue::transform::axis_angle(v));
        }

        /*!
         * \brief     Converts a rotation vector to a rotation quaternion.
         * \details   If the rotation vector's length is `0`, returns
         *            `(0, 0, 0, 1)`.
         *
         * \tparam T  The rotation vector's component type.
         *
         * \param x   The rotation vector's first component.
         * \param y   The rotation vector's second component.
         * \param z   The rotation vector's third component.
         *
         * \return    The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sqrt(std::declval<T>()))>
        rotation_quat(const T& x, const T& y, const T& z) noexcept
        {
            return tue::transform::rotation_quat(
                tue::transform::axis_angle(x, y, z));
        }

        /*!
         * \brief     Computes a 2D translation matrix.
         * \details   The return matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The type of parameters `x` and `y`.
         * \tparam C  The column count of the returned matrix. Must be 2, 3, or
         *            4.
         * \tparam R  The row count of the returned matrix. Must be 3 or 4.
         *
         * \param x   The translation along the `x` dimension.
         * \param y   The translation along the `y` dimension.
         *
         * \return    A 2D translation matrix. Values beyond the requested
         *            dimensions will be truncated.
         *
         *            \code
         *            [              1,               0,  0,  0 ]
         *            [              0,               1,  0,  0 ]
         *            [ R == 3 ? x : 0,  R == 3 ? y : 0,  1,  0 ]
         *            [ R == 4 ? x : 0,  R == 4 ? y : 0,  0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 2 && R >= 3), mat<T, C, R>>
        translation_mat(const T& x, const T& y) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                1, 0, R == 3 ? x : 0, R == 4 ? x : 0,
                0, 1, R == 3 ? y : 0, R == 4 ? y : 0,
                0, 0,              1,              0,
                0, 0,              0,              1);
        }

        /*!
         * \brief     Computes a 2D translation matrix.
         * \details   The return matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The component type of `v`.
         * \tparam C  The column count of the returned matrix. Must be 2, 3, or
         *            4.
         * \tparam R  The row count of the returned matrix. Must be 3 or 4.
         *
         * \param v   The translation vector.
         *
         * \return    A 2D translation matrix. Values beyond the requested
         *            dimensions will be truncated.
         *
         *            \code
         *            [                 1,                  0,  0,  0 ]
         *            [                 0,                  1,  0,  0 ]
         *            [ R == 3 ? v[0] : 0,  R == 3 ? v[1] : 0,  1,  0 ]
         *            [ R == 4 ? v[0] : 0,  R == 4 ? v[1] : 0,  0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 2 && R >= 3), mat<T, C, R>>
        translation_mat(const vec2<T>& v) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                1, 0, R == 3 ? v[0] : 0, R == 4 ? v[0] : 0,
                0, 1, R == 3 ? v[1] : 0, R == 4 ? v[1] : 0,
                0, 0,                 1,                 0,
                0, 0,                 0,                 1);
        }
    }
}
