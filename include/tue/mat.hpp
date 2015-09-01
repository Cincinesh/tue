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
     * \brief     A 2-dimensional matrix.
     * \details   `mat`'s are laid out in column-major order. They have the same
     *            size and alignment requirements as `vec<T, R>[C]`.
     *
     * \tparam T  The component type.
     * \tparam C  The column count. Must be 2, 3, or 4.
     * \tparam R  The row count. Must be 2, 3, or 4.
     */
    template<typename T, int C, int R>
    class mat;

    /*!
     * \brief     A 2x2 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x2 = mat<T, 2, 2>;

    /*!
     * \brief     A 2x3 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x3 = mat<T, 2, 3>;

    /*!
     * \brief     A 2x4 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x4 = mat<T, 2, 4>;

    /*!
     * \brief     A 3x2 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x2 = mat<T, 3, 2>;

    /*!
     * \brief     A 3x3 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x3 = mat<T, 3, 3>;

    /*!
     * \brief     A 3x4 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x4 = mat<T, 3, 4>;

    /*!
     * \brief     A 4x2 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat4x2 = mat<T, 4, 2>;

    /*!
     * \brief     A 4x3 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat4x3 = mat<T, 4, 3>;

    /*!
     * \brief     A 4x4 matrix.
     * \tparam T  The component type.
     */
    template<typename T>
    using mat4x4 = mat<T, 4, 4>;
}
