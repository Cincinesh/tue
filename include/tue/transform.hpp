//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <utility>

#include "math.hpp"
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
         * \tparam T  The component type of the rotation vector.
         * \param v   The rotation vector.
         * \return    The rotation vector converted to an axis-angle vector.
         */
        template<typename T>
        inline vec4<decltype(tue::math::sqrt(std::declval<T>()))>
        axis_angle(const vec3<T>& v) noexcept
        {
            using U = decltype(tue::math::length(v));
            const auto angle = tue::math::length(v);
            const auto axis = tue::math::select(
                tue::math::not_equal(angle, U(0)),
                vec3<U>(v) / angle,
                vec3<U>::z_axis());

            return { axis, angle };
        }

        /*!
         * \brief     Converts a rotation vector to an axis-angle vector.
         *
         * \tparam T  The component type of the rotation vector.
         *
         * \param x   The rotation vector's first component.
         * \param y   The rotation vector's second component.
         * \param z   The rotation vector's third component.
         *
         * \return    The rotation vector converted to an axis-angle vector.
         */
        template<typename T>
        inline vec4<decltype(tue::math::sqrt(std::declval<T>()))>
        axis_angle(const T& x, const T& y, const T& z) noexcept
        {
            return tue::transform::axis_angle(vec3<T>(x, y, z));
        }
    }
}
