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

/*!
 * \defgroup  transform_hpp <tue/transform.hpp>
 *
 * \brief     Functions for generating and converting between different
 *            types of transformations.
 * \details
 *
 *     This library has a few different ways of representing
 *     3-dimensional rotations specifically:
 *
 *     - <b>An axis-angle pair</b>
 *       <br/>
 *       An axis-angle pair is just as the name implies: it's a rotation around
 *       a given axis. It can be represented by three scalars (the axis) and a
 *       fourth scalar (the angle) or by a `vec3` (the axis) and a scalar (the
 *       angle). All functions which take an axis-angle pair as their arguments
 *       assume the axis is normalized and the angle is measured in radians
 *       counter-clockwise around the axis.
 *
 *     - <b>An axis-angle vector</b>
 *       <br/>
 *       An axis-angle vector is just an axis-angle pair grouped together into a
 *       single `vec4`. The first three components make up the axis and the
 *       fourth component represents the angle.
 *
 *     - <b>A rotation vector</b>
 *       <br/>
 *       There are a couple ways to think about a rotation vector. It's
 *       represented by three separate scalars or a single `vec3`. You could
 *       imagine it as a more-compact version of an axis-angle pair; its
 *       direction represents the axis of rotation and its magnitude the angle
 *       (again, radians counter-clockwise around the axis). You could also
 *       imagine it as the composite of three separate rotations with each
 *       component representing an angle of rotation around the corresponding
 *       principal axis. Rotation vectors are most useful when rotations need to
 *       be interpolated and/or multiplied, such as when representing angular
 *       velocity.
 *
 *     - <b>A rotation quaternion</b>
 *       <br/>
 *       A rotation quaternion is a little more complicated. It's a
 *       four-component composite type (a `quat`). It's kind of like an
 *       axis-angle vector, but the entire vector is assumed to be normalized
 *       instead of just the axis. This is achieved by multiplying the
 *       normalized axis by `sin(angle/2)` and storing `cos(angle/2)` instead of
 *       the angle itself in the fourth component. Rotation quaternions are best
 *       used when representing an orientation in 3-dimensional space or when
 *       composing multiple rotations into one. Since they're defined by
 *       trigonometric functions, computationally expensive trigonometry isn't
 *       needed when using them to rotate vectors or when generating rotation
 *       matrices.
 *
 *     - <b>A rotation matrix</b>
 *       <br/>
 *       A rotation matrix is just a specific type of transformation matrix that
 *       can rotate vectors using matrix multiplication. It's useful for
 *       composing with other types of transformation matrices.
 */
namespace tue
{
    namespace transform
    {
        /*!
         * \addtogroup  transform_hpp
         * @{
         */

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
        inline vec4<decltype(tue::math::sin(std::declval<T>()))>
        axis_angle(const T& x, const T& y, const T& z) noexcept
        {
            const auto length2 = x*x + y*y + z*z;
            const auto nzmask = tue::math::not_equal(length2, T(0));
            const auto rangle = tue::math::rsqrt(length2);

            const auto axis_x = tue::math::mask(nzmask, x * rangle);
            const auto axis_y = tue::math::mask(nzmask, y * rangle);
            const auto axis_z = tue::math::select(nzmask, z * rangle, T(1));

            const auto angle =
                tue::math::mask(nzmask, tue::math::recip(rangle));

            return { axis_x, axis_y, axis_z, angle };
        }

        /*!
         * \brief     Converts a rotation vector to an axis-angle vector.
         * \details   If the rotation vector's length is `0`, returns
         *            `(0, 0, 1, 0)`.
         *
         * \tparam T  The rotation vector's component type.
         *
         * \param v   The rotation vector.
         *
         * \return    The axis-angle vector.
         */
        template<typename T>
        inline vec4<decltype(tue::math::sin(std::declval<T>()))>
        axis_angle(const vec3<T>& v) noexcept
        {
            return tue::transform::axis_angle(v[0], v[1], v[2]);
        }

        /*!
         * \brief         Converts an axis-angle pair to a rotation vector.
         * \details       This function assumes the axis is normalized.
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
        inline constexpr vec3<decltype(tue::math::sin(std::declval<T>()))>
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
         * \details      This function assumes the axis is normalized.
         *
         * \tparam T     The axis-angle component type.
         *
         * \param axis   The axis.
         * \param angle  The angle.
         *
         * \return       The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<decltype(tue::math::sin(std::declval<T>()))>
        rotation_vec(const vec3<T>& axis, const T& angle) noexcept
        {
            return tue::transform::rotation_vec(
                axis[0], axis[1], axis[2], angle);
        }

        /*!
         * \brief     Converts an axis-angle vector to a rotation vector.
         * \details   This function assumes the axis is normalized.
         *
         * \tparam T  The axis-angle component type.
         *
         * \param v   The axis-angle vector.
         *
         * \return    The rotation vector.
         */
        template<typename T>
        inline constexpr vec3<decltype(tue::math::sin(std::declval<T>()))>
        rotation_vec(const vec4<T>& v) noexcept
        {
            return tue::transform::rotation_vec(
                v[0], v[1], v[2], v[3]);
        }

        /*!
         * \brief         Converts an axis-angle pair to a rotation quaternion.
         * \details       This function assumes the axis is normalized.
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
            T s, c;
            tue::math::sincos(angle / T(2), s, c);
            return { axis_x * s, axis_y * s, axis_z * s, c };
        }

        /*!
         * \brief        Converts an axis-angle pair to a rotation quaternion.
         * \details      This function assumes the axis is normalized.
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
         * \details   This function assumes the axis is normalized.
         *
         * \tparam T  The axis-angle component type.
         *
         * \param v   The axis-angle vector.
         *
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
         *
         * \param v   The rotation vector.
         *
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
         * \details   The returned matrix might be the transpose of what you
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
         * \param x   The translation along the `x` axis.
         * \param y   The translation along the `y` axis.
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
                1, 0, R == 3 ? x : T(0), R == 4 ? x : T(0),
                0, 1, R == 3 ? y : T(0), R == 4 ? y : T(0),
                0, 0,                1 ,                0 ,
                0, 0,                0 ,                1 );
        }

        /*!
         * \brief     Computes a 2D translation matrix.
         * \details   The returned matrix might be the transpose of what you
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
         * \details   The returned matrix might be the transpose of what you
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
         * \param x   The translation along the `x` axis.
         * \param y   The translation along the `y` axis.
         * \param z   The translation along the `z` axis.
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
         * \details   The returned matrix might be the transpose of what you
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
         * \details      The returned matrix might be the transpose of what you
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
        inline std::enable_if_t<
            (C >= 2 && R >= 2),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const T& angle) noexcept
        {
            T s, c;
            tue::math::sincos(angle, s, c);
            return tue::detail_::mat_utils<T, C, R>::create(
                c, -s, 0, 0,
                s,  c, 0, 0,
                0,  0, 1, 0,
                0,  0, 0, 1);
        }

        /*!
         * \brief         Computes a 3D rotation matrix from an axis-angle pair.
         * \details       This function assumes the axis is normalized.
         *                <br/>
         *                The returned matrix might be the transpose of what you
         *                expect from other libraries. This library generally
         *                prefers compound transformations be written from
         *                left-to-right instead of right-to-left.
         *
         * \tparam T      The axis-angle component type.
         * \tparam C      The column count of the returned matrix.
         *                Must be 3 or 4. Defaults to 4.
         * \tparam R      The row count of the returned matrix.
         *                Must be 3 or 4. Defaults to 4.
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
        inline std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(
            const T& axis_x, const T& axis_y, const T& axis_z,
            const T& angle) noexcept
        {
            T s, c;
            tue::math::sincos(angle, s, c);
            const auto omc = T(1) - c;

            const auto xx = axis_x * axis_x;
            const auto xy = axis_x * axis_y;
            const auto xz = axis_x * axis_z;
            const auto xs = axis_x * s;
            const auto yy = axis_y * axis_y;
            const auto yz = axis_y * axis_z;
            const auto ys = axis_y * s;
            const auto zz = axis_z * axis_z;
            const auto zs = axis_z * s;
            const auto xxomc = xx * omc;
            const auto xyomc = xy * omc;
            const auto xzomc = xz * omc;
            const auto yyomc = yy * omc;
            const auto yzomc = yz * omc;
            const auto zzomc = zz * omc;

            return tue::detail_::mat_utils<T, C, R>::create(
                xxomc +  c, xyomc - zs, xzomc + ys, 0,
                xyomc + zs, yyomc +  c, yzomc - xs, 0,
                xzomc - ys, yzomc + xs, zzomc +  c, 0,
                                           0, 0, 0, 1);
        }

        /*!
         * \brief        Computes a 3D rotation matrix from an axis-angle pair.
         * \details      This function assumes the axis is normalized.
         *               <br/>
         *               The returned matrix might be the transpose of what you
         *               expect from other libraries. This library generally
         *               prefers compound transformations be written from
         *               left-to-right instead of right-to-left.
         *
         * \tparam T     The axis-angle component type.
         * \tparam C     The column count of the returned matrix.
         *               Must be 3 or 4. Defaults to 4.
         * \tparam R     The row count of the returned matrix.
         *               Must be 3 or 4. Defaults to 4.
         *
         * \param axis   The axis.
         * \param angle  The angle.
         *
         * \return       A 3D rotation matrix. Values beyond the requested
         *               matrix dimensions are truncated.
         *
         *               \code
         *               // Where x, y, and z make the axis of rotation
         *               // and s and c are sin(angle) and cos(angle).
         *
         *               [ xx(1-c) +  c,  xy(1-c) + zs,  xz(1-c) - ys,  0 ]
         *               [ xy(1-c) - zs,  yy(1-c) +  c,  yz(1-c) - xs,  0 ]
         *               [ xz(1-c) + ys,  yz(1-c) - xs,  zz(1-c) +  c,  0 ]
         *               [            0,             0,             0,  1 ]
         *               \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const vec3<T>& axis, const T& angle) noexcept
        {
            return tue::transform::rotation_mat<T, C, R>(
                axis[0], axis[1], axis[2], angle);
        }

        /*!
         * \brief     Computes a 3D rotation matrix from an axis-angle vector.
         * \details   This function assumes the axis is normalized.
         *            <br/>
         *            The returned matrix might be the transpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The axis-angle component type.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param v   The axis-angle vector.
         *
         * \return    A 3D rotation matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            // Where x, y, and z make the axis of rotation
         *            // and s and c are sin(v[3]) and cos(v[3]).
         *
         *            [ xx(1-c) +  c,  xy(1-c) + zs,  xz(1-c) - ys,  0 ]
         *            [ xy(1-c) - zs,  yy(1-c) +  c,  yz(1-c) - xs,  0 ]
         *            [ xz(1-c) + ys,  yz(1-c) - xs,  zz(1-c) +  c,  0 ]
         *            [            0,             0,             0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const vec4<T>& v) noexcept
        {
            return tue::transform::rotation_mat<T, C, R>(
                v[0], v[1], v[2], v[3]);
        }

        /*!
         * \brief     Computes a 3D rotation matrix from a rotation vector.
         * \details   The returned matrix might be the transpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The rotation vector's component type.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param x   The rotation vector's first component.
         * \param y   The rotation vector's second component.
         * \param z   The rotation vector's third component.
         *
         * \return    A 3D rotation matrix.
         *
         *            \code
         *            return tue::transform::rotation_mat<T, C, R>(
         *                tue::transform::axis_angle(x, y, z));
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const T& x, const T& y, const T& z) noexcept
        {
            return tue::transform::rotation_mat<T, C, R>(
                tue::transform::axis_angle(x, y, z));
        }

        /*!
         * \brief     Computes a 3D rotation matrix from a rotation vector.
         * \details   The returned matrix might be the transpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The rotation vector's component type.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param v   The rotation vector.
         *
         * \return    A 3D rotation matrix.
         *
         *            \code
         *            return tue::transform::rotation_mat<T, C, R>(
         *                tue::transform::axis_angle(v));
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const vec3<T>& v) noexcept
        {
            return tue::transform::rotation_mat<T, C, R>(
                tue::transform::axis_angle(v));
        }

        /*!
         * \brief     Computes a 3D rotation matrix from a rotation quaternion.
         * \details   This function assumes the quaternion is normalized.
         *            <br/>
         *            The returned matrix might be the transpose of what you
         *            expect from other libraries. This library generally
         *            prefers compound transformations be written from
         *            left-to-right instead of right-to-left.
         *
         * \tparam T  The rotation quaternion's component type.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param q   The rotation quaternion.
         *
         * \return    A 3D rotation matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            // Where x, y, z, and w are the components of the rotation
         *            // quaternion.
         *
         *            [ 1 - 2yy - 2zz,      2xy + 2zw,      2xz - 2yw,  0 ]
         *            [     2xy - 2zw,  1 - 2xx - 2zz,      2yz + 2xw,  0 ]
         *            [     2xz + 2yw,      2yz - 2xw,  1 - 2xx - 2yy,  0 ]
         *            [             0,              0,              0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<
            (C >= 3 && R >= 3),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        rotation_mat(const quat<T>& q) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                T(1) - T(2)*q[1]*q[1] - T(2)*q[2]*q[2],
                       T(2)*q[0]*q[1] - T(2)*q[2]*q[3],
                       T(2)*q[0]*q[2] + T(2)*q[1]*q[3],
                0,
                       T(2)*q[0]*q[1] + T(2)*q[2]*q[3],
                T(1) - T(2)*q[0]*q[0] - T(2)*q[2]*q[2],
                       T(2)*q[1]*q[2] - T(2)*q[0]*q[3],
                0,
                       T(2)*q[0]*q[2] - T(2)*q[1]*q[3],
                       T(2)*q[1]*q[2] + T(2)*q[0]*q[3],
                T(1) - T(2)*q[0]*q[0] - T(2)*q[1]*q[1],
                0,
                0, 0, 0, 1);
        }

        /*!
         * \brief     Computes a 2D scale matrix.
         *
         * \tparam T  The type of parameters `x` and `y`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         *
         * \param x   The scale along the `x` axis.
         * \param y   The scale along the `y` axis.
         *
         * \return    A 2D scale matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            [ x,  0,  0,  0 ]
         *            [ 0,  y,  0,  0 ]
         *            [ 0,  0,  1,  0 ]
         *            [ 0,  0,  0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 2 && R >= 2), mat<T, C, R>>
        scale_mat(const T& x, const T& y) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1);
        }

        /*!
         * \brief     Computes a 2D scale matrix.
         *
         * \tparam T  The component type of `v`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 2, 3, or 4. Defaults to 4.
         *
         * \param v   The scale vector.
         *
         * \return    A 2D scale matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            [ v[0],    0 ,  0,  0 ]
         *            [   0 ,  v[1],  0,  0 ]
         *            [   0 ,    0 ,  1,  0 ]
         *            [   0 ,    0 ,  0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 2 && R >= 2), mat<T, C, R>>
        scale_mat(const vec2<T>& v) noexcept
        {
            return tue::transform::scale_mat<T, C, R>(v[0], v[1]);
        }

        /*!
         * \brief     Computes a 3D scale matrix.
         *
         * \tparam T  The type of parameters `x`, `y`, and `z`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param x   The scale along the `x` axis.
         * \param y   The scale along the `y` axis.
         * \param z   The scale along the `z` axis.
         *
         * \return    A 3D scale matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            [ x,  0,  0,  0 ]
         *            [ 0,  y,  0,  0 ]
         *            [ 0,  0,  z,  0 ]
         *            [ 0,  0,  0,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 3 && R >= 3), mat<T, C, R>>
        scale_mat(const T& x, const T& y, const T& z) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, z, 0,
                0, 0, 0, 1);
        }

        /*!
         * \brief     Computes a 3D scale matrix.
         *
         * \tparam T  The component type of `v`.
         * \tparam C  The column count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         * \tparam R  The row count of the returned matrix.
         *            Must be 3 or 4. Defaults to 4.
         *
         * \param v   The scale vector.
         *
         * \return    A 3D scale matrix. Values beyond the requested matrix
         *            dimensions are truncated.
         *
         *            \code
         *            [ v[0],    0 ,    0 ,  0 ]
         *            [   0 ,  v[1],    0 ,  0 ]
         *            [   0 ,    0 ,  v[2],  0 ]
         *            [   0 ,    0 ,    0 ,  1 ]
         *            \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<(C >= 3 && R >= 3), mat<T, C, R>>
        scale_mat(const vec3<T>& v) noexcept
        {
            return tue::transform::scale_mat<T, C, R>(v[0], v[1], v[2]);
        }

        /*!
         * \brief         Computes a 3D perspective matrix.
         * \details       The returned matrix might be the transpose of what you
         *                expect from other libraries. This library generally
         *                prefers compound transformations be written from
         *                left-to-right instead of right-to-left.
         *
         * \tparam T      The type of all four parameters.
         * \tparam C      The column count of the returned matrix.
         *                Must be 4. Defaults to 4.
         * \tparam R      The row count of the returned matrix.
         *                Must be 4. Defaults to 4.
         *
         * \param fovy    The vertical field of view (measured in radians).
         * \param aspect  The aspect ratio (width / height).
         * \param n       The distance to the near view plane.
         * \param f       The distance to the far view plane.
         *
         * \return        A 3D perspective matrix.
         *
         *                \code
         *                // Where s and c are sin(fovy/2) and cos(fovy/2)
         *
         *                [ c/s/aspect,    0,            0,   0 ]
         *                [          0,  c/s,            0,   0 ]
         *                [          0,    0,  (n+f)/(n-f),  -1 ]
         *                [          0,    0,  (2nf)/(n-f),   0 ]
         *                \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline std::enable_if_t<
            (C >= 4 && R >= 4),
            mat<decltype(tue::math::sin(std::declval<T>())), C, R>>
        perspective_mat(
            const T& fovy,
            const T& aspect,
            const T& n /* "near" conflicts with a WIN32 macro */,
            const T& f /* "far" conflicts with a WIN32 macro */) noexcept
        {
            T s, c;
            tue::math::sincos(fovy / T(2), s, c);
            const auto cot = c / s;

            const auto npf = n + f;
            const auto nmf = n - f;
            const auto ntf = n * f;

            return tue::detail_::mat_utils<T, C, R>::create(
                cot/aspect,         0, 0, 0,
                0, cot,                0, 0,
                0, 0, npf/nmf, T(2)*ntf/nmf,
                0, 0, -1,                 0);
        }

        /*!
         * \brief         Computes an orthographic projection matrix.
         * \details       The returned matrix might be the transpose of what you
         *                expect from other libraries. This library generally
         *                prefers compound transformations be written from
         *                left-to-right instead of right-to-left.
         *
         * \tparam T      The type of all four parameters.
         * \tparam C      The column count of the returned matrix.
         *                Must be 3 or 4. Defaults to 4.
         * \tparam R      The row count of the returned matrix.
         *                Must be 4. Defaults to 4.
         *
         * \param width   The orthographic projection width.
         * \param height  The orthographic projection height.
         * \param n       The distance to the near view plane.
         * \param f       The distance to the far view plane.
         *
         * \return        An orthographic projection matrix.
         *
         *                \code
         *                [ 2/width,         0,            0,  0 ]
         *                [       0,  2/height,            0,  0 ]
         *                [       0,         0,    (2)/(n-f),  0 ]
         *                [       0,         0,  (n+f)/(n-f),  1 ]
         *                \endcode
         */
        template<typename T, int C = 4, int R = 4>
        inline constexpr std::enable_if_t<
            (C >= 3 && R >= 4),
            mat<decltype(tue::math::recip(std::declval<T>())), C, R>>
        ortho_mat(
            const T& width,
            const T& height,
            const T& n /* "near" conflicts with a WIN32 macro */,
            const T& f /* "far" conflicts with a WIN32 macro */) noexcept
        {
            return tue::detail_::mat_utils<T, C, R>::create(
                T(2)/width,           0, 0, 0,
                0, T(2)/height,          0, 0,
                0, 0, T(2)/(n-f), (n+f)/(n-f),
                0, 0, 0,                    1);
        }

        /*!@}*/
    }
}
