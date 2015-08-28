//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

namespace tue
{
    /*!
     * \brief     An `N`-dimensional vector.
     * \tparam T  The component type.
     * \tparam N  The number of components. Must be 2, 3, or 4.
     */
    template<typename T, int N>
    class vec;

    /*!
     * \brief     A 2-dimensional vector.
     * \tparam T  The component type.
     */
    template<typename T>
    using vec2 = vec<T, 2>;

    /*!
     * \brief     A 3-dimensional vector.
     * \tparam T  The component type.
     */
    template<typename T>
    using vec3 = vec<T, 3>;

    /*!
     * \brief     A 4-dimensional vector.
     * \tparam T  The component type.
     */
    template<typename T>
    using vec4 = vec<T, 4>;

    /*!
     * \brief  A 2-dimensional vector with `float` components.
     */
    using fvec2 = vec2<float>;

    /*!
     * \brief  A 3-dimensional vector with `float` components.
     */
    using fvec3 = vec3<float>;

    /*!
     * \brief  A 4-dimensional vector with `float` components.
     */
    using fvec4 = vec4<float>;

    /*!
     * \brief  A 2-dimensional vector with `double` components.
     */
    using dvec2 = vec2<double>;

    /*!
     * \brief  A 3-dimensional vector with `double` components.
     */
    using dvec3 = vec3<double>;

    /*!
     * \brief  A 4-dimensional vector with `double` components.
     */
    using dvec4 = vec4<double>;

    /*!
     * \brief  A 2-dimensional vector with `int` components.
     */
    using ivec2 = vec2<int>;

    /*!
     * \brief  A 3-dimensional vector with `int` components.
     */
    using ivec3 = vec3<int>;

    /*!
     * \brief  A 4-dimensional vector with `int` components.
     */
    using ivec4 = vec4<int>;

    /*!
     * \brief  A 2-dimensional vector with `unsigned int` components.
     */
    using uvec2 = vec2<unsigned int>;

    /*!
     * \brief  A 3-dimensional vector with `unsigned int` components.
     */
    using uvec3 = vec3<unsigned int>;

    /*!
     * \brief  A 4-dimensional vector with `unsigned int` components.
     */
    using uvec4 = vec4<unsigned int>;

    /*!
     * \brief  A 2-dimensional vector with `bool` components.
     */
    using bvec2 = vec2<bool>;

    /*!
     * \brief  A 3-dimensional vector with `bool` components.
     */
    using bvec3 = vec3<bool>;

    /*!
     * \brief  A 4-dimensional vector with `bool` components.
     */
    using bvec4 = vec4<bool>;
}
