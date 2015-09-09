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
            const auto angle = tue::math::sqrt(x*x + y*y + z*z);
            using U = decltype(angle);

            const auto nzmask = tue::math::not_equal(angle, U(0));
            const auto axis_x = tue::math::select(nzmask, U(x) / angle, U(0));
            const auto axis_y = tue::math::select(nzmask, U(y) / angle, U(0));
            const auto axis_z = tue::math::select(nzmask, U(z) / angle, U(1));
            return { axis_x, axis_y, axis_z, angle };
        }

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
            return tue::transform::axis_angle(v[0], v[1], v[2]);
        }

        /*!
         * \brief         Converts an axis-angle pair to a rotation vector.
         *
         * \tparam T      The axis-angle component type.
         *
         * \param axis_x  The axis' first component.
         * \param axis_y  The axis' second component.
         * \param axis_z  The axis' third component.
         * \param angle   The angle.
         *
         * \return        The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<T>
        rotation_vec(
            const T& axis_x, const T& axis_y, const T& axis_z,
            const T& angle) noexcept
        {
            return {
                axis_x * angle,
                axis_y * angle,
                axis_z * angle,
            };
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
            return tue::transform::rotation_vec(
                axis[0], axis[1], axis[2], angle);
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
            return tue::transform::rotation_vec(
                v[0], v[1], v[2], v[3]);
        }

        /*!
         * \brief         Converts an axis-angle pair to a rotation quaternion.
         *
         * \tparam T      The axis-angle component type.
         *
         * \param axis_x  The axis' first component.
         * \param axis_y  The axis' second component.
         * \param axis_z  The axis' third component.
         * \param angle   The angle.
         *
         * \return        The rotation quaternion.
         */
        template<typename T>
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(
            const T& axis_x, const T& axis_y, const T& axis_z,
            const T& angle) noexcept
        {
            using U = decltype(tue::math::sin(angle));
            U s, c;
            tue::math::sincos(U(angle) / U(2), s, c);
            return { U(axis_x)*s, U(axis_y)*s, U(axis_z)*s, c };
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
            return tue::transform::rotation_quat(
                axis[0], axis[1], axis[2], angle);
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
            return tue::transform::rotation_quat(
                v[0], v[1], v[2], v[3]);
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
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(const T& x, const T& y, const T& z) noexcept
        {
            return tue::transform::rotation_quat(
                tue::transform::axis_angle(x, y, z));
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
        inline quat<decltype(tue::math::sin(std::declval<T>()))>
        rotation_quat(const vec3<T>& v) noexcept
        {
            return tue::transform::rotation_quat(
                tue::transform::axis_angle(v));
        }

        /*!
         * \brief     Computes a 2D translation matrix.
         * \details   The returned matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The type of parameters `x` and `y`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param x   The translation along the `x` dimension.
         * \param y   The translation along the `y` dimension.
         *
         * \return    A 2D translation matrix. Values beyond the requested
         *            matrix dimensions are truncated.
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
         * \details   The returned matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The component type of `v`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param v   The translation vector.
         *
         * \return    A 2D translation matrix. Values beyond the requested
         *            matrix dimensions are truncated.
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
            return tue::transform::translation_mat<T, C, R>(v[0], v[1]);
        }

        /*!
         * \brief     Computes a 3D translation matrix.
         * \details   The returned matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The type of parameters `x`, `y`, and `z`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 4. Defaults to 4.
         *
         * \param x   The translation along the `x` dimension.
         * \param y   The translation along the `y` dimension.
         * \param z   The translation along the `z` dimension.
         *
         * \return    A 3D translation matrix. Values beyond the requested
         *            matrix dimensions are truncated.
         *
         *            \code
         *            [ 1,  0,  0,  0 ]
         *            [ 0,  1,  0,  0 ]
         *            [ 0,  0,  1,  0 ]
         *            [ x,  y,  z,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 3 && R >= 4), mat<T, C, R>>
        translation_mat(const T& x, const T& y, const T& z) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                1, 0, 0, x,
                0, 1, 0, y,
                0, 0, 1, z,
                0, 0, 0, 1);
        }

        /*!
         * \brief     Computes a 3D translation matrix.
         * \details   The returned matrix might be the tranpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The component type of `v`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 4. Defaults to 4.
         *
         * \param v   The translation vector.
         *
         * \return    A 3D translation matrix. Values beyond the requested
         *            matrix dimensions are truncated.
         *
         *            \code
         *            [   1 ,    0 ,    0 ,  0 ]
         *            [   0 ,    1 ,    0 ,  0 ]
         *            [   0 ,    0 ,    1 ,  0 ]
         *            [ v[0],  v[1],  v[2],  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 3 && R >= 4), mat<T, C, R>>
        translation_mat(const vec3<T>& v) noexcept
        {
            return tue::transform::translation_mat<T, C, R>(v[0], v[1], v[2]);
        }

        /*!
         * \brief        Computes a 2D rotation matrix.
         * \details      The returned matrix might be the tranpose of what you
         *               expect from other libraries. This library generally
         *               prefers compound transformations be written from
         *               left-to-right instead of right-to-left.
         *
         * \tparam T     The type of parameter `angle`.
         * \tparam C     The column count of the returned matrix.
         *               Must be 2, 3, or 4. Defaults to 4.
         * \tparam R     The row count of the returned matrix.
         *               Must be 2, 3, or 4. Defaults to 4.
         *
         * \param angle  The rotation (measured in radians counter-clockwise).
         *
         * \return       A 2D rotation matrix. Values beyond the requested
         *               matrix dimensions are truncated.
         *
         *               \code
         *               [  cos(angle),  sin(angle),  0,  0 ]
         *               [ -sin(angle),  cos(angle),  0,  0 ]
         *               [           0,           0,  1,  0 ]
         *               [           0,           0,  0,  1 ]
         *               \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<(C >= 2 && R >= 2),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const T& angle) noexcept
        {
            using U = decltype(tue::math::sin(angle));
            U s, c;
            tue::math::sincos(angle, s, c);
            return tue::detail_::mat_utils<U, C, R>::create(
                c, -s, 0, 0,
                s,  c, 0, 0,
                0,  0, 1, 0,
                0,  0, 0, 1);
        }

        /*!
         * \brief         Computes a 3D rotation matrix from an axis-angle pair.
         * \details       The returned matrix might be the tranpose of what you
         *                expect from other libraries. This library generally
         *                prefers compound transformations be written from
         *                left-to-right instead of right-to-left.
         *
         * \tparam T      The axis-angle component type.
         * \tparam C      The column count of the returned matrix.
         *                Must be 2, 3, or 4. Defaults to 4.
         * \tparam R      The row count of the returned matrix.
         *                Must be 2, 3, or 4. Defaults to 4.
         *
         * \param axis_x  The axis' first component.
         * \param axis_y  The axis' second component.
         * \param axis_z  The axis' third component.
         * \param angle   The angle.
         *
         * \return        A 3D rotation matrix. Values beyond the requested
         *                matrix dimensions are truncated.
         *
         *                \code
         *                // Where x, y, and z make the axis of rotation
         *                // and s and c are sin(angle) and cos(angle).
         *
         *                [ xx(1-c) +  c,  xy(1-c) + zs,  xz(1-c) - ys,  0 ]
         *                [ xy(1-c) - zs,  yy(1-c) +  c,  yz(1-c) - xs,  0 ]
         *                [ xz(1-c) + ys,  yz(1-c) - xs,  zz(1-c) +  c,  0 ]
         *                [            0,             0,             0,  1 ]
         *                \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<(C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(
            const T& axis_x, const T& axis_y, const T& axis_z,
            const T& angle) noexcept
        {
            using U = decltype(tue::math::sin(angle));
            const auto x = U(axis_x);
            const auto y = U(axis_y);
            const auto z = U(axis_z);

            U s, c;
            tue::math::sincos(angle, s, c);
            const auto omc = U(1) - c;

            const auto xx = x * x;
            const auto xy = x * y;
            const auto xz = x * z;
            const auto xs = x * s;
            const auto yy = y * y;
            const auto yz = y * z;
            const auto ys = y * s;
            const auto zz = z * z;
            const auto zs = z * s;
            const auto xxomc = xx * omc;
            const auto xyomc = xy * omc;
            const auto xzomc = xz * omc;
            const auto yyomc = yy * omc;
            const auto yzomc = yz * omc;
            const auto zzomc = zz * omc;

            return tue::detail_::mat_utils<U, C, R>::create(
                xxomc +  c, xyomc - zs, xzomc + ys, 0,
                xyomc + zs, yyomc +  c, yzomc - xs, 0,
                xzomc - ys, yzomc + xs, zzomc +  c, 0,
                                           0, 0, 0, 1);
        }
    }
}
