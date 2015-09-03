//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

#include "vec.hpp"

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

    /*!
     * \brief  A 2x2 matrix with `float` components.
     */
    using fmat2x2 = mat2x2<float>;

    /*!
     * \brief  A 2x3 matrix with `float` components.
     */
    using fmat2x3 = mat2x3<float>;

    /*!
     * \brief  A 2x4 matrix with `float` components.
     */
    using fmat2x4 = mat2x4<float>;

    /*!
     * \brief  A 3x2 matrix with `float` components.
     */
    using fmat3x2 = mat3x2<float>;

    /*!
     * \brief  A 3x3 matrix with `float` components.
     */
    using fmat3x3 = mat3x3<float>;

    /*!
     * \brief  A 3x4 matrix with `float` components.
     */
    using fmat3x4 = mat3x4<float>;

    /*!
     * \brief  A 4x2 matrix with `float` components.
     */
    using fmat4x2 = mat4x2<float>;

    /*!
     * \brief  A 4x3 matrix with `float` components.
     */
    using fmat4x3 = mat4x3<float>;

    /*!
     * \brief  A 4x4 matrix with `float` components.
     */
    using fmat4x4 = mat4x4<float>;

    /*!
     * \brief  A 2x2 matrix with `double` components.
     */
    using dmat2x2 = mat2x2<double>;

    /*!
     * \brief  A 2x3 matrix with `double` components.
     */
    using dmat2x3 = mat2x3<double>;

    /*!
     * \brief  A 2x4 matrix with `double` components.
     */
    using dmat2x4 = mat2x4<double>;

    /*!
     * \brief  A 3x2 matrix with `double` components.
     */
    using dmat3x2 = mat3x2<double>;

    /*!
     * \brief  A 3x3 matrix with `double` components.
     */
    using dmat3x3 = mat3x3<double>;

    /*!
     * \brief  A 3x4 matrix with `double` components.
     */
    using dmat3x4 = mat3x4<double>;

    /*!
     * \brief  A 4x2 matrix with `double` components.
     */
    using dmat4x2 = mat4x2<double>;

    /*!
     * \brief  A 4x3 matrix with `double` components.
     */
    using dmat4x3 = mat4x3<double>;

    /*!
     * \brief  A 4x4 matrix with `double` components.
     */
    using dmat4x4 = mat4x4<double>;

    /**/
    template<typename T, int C, int R>
    class mat
    {
        struct
        {
            std::enable_if_t<(C >= 2 && C <= 4 && R >= 2 && R <= 4), vec<T, R>>
            columns[C];
        }
        impl_;

    public:
        /*!
         * \brief  This `mat` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `mat` type's column count.
         */
        static constexpr int column_count = C;

        /*!
         * \brief  This `mat` type's row count.
         */
        static constexpr int row_count = R;

        /*!
         * \brief  This `mat` type's component count.
         */
        static constexpr int component_count = C * R;

        /*!
         * \brief  Default constructs each component.
         */
        mat() noexcept = default;

        /*!
         * \brief     Constructs each component along the main diagonal with the
         *            same value, and all other components with `0`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to construct the main diagonal with.
         */
        template<typename U>
        inline explicit constexpr mat(const U& x) noexcept;

        /*!
         * \brief     Constructs a `mat` with the given columns.
         * \details   This overload is only available when `C` equals `2`.
         *
         * \param c0  The first column.
         * \param c1  The second column.
         */
        inline constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1) noexcept;

        /*!
         * \brief     Constructs a `mat` with the given columns.
         * \details   This overload is only available when `C` equals `3`.
         *
         * \param c0  The first column.
         * \param c1  The second column.
         * \param c2  The third column.
         */
        inline constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1,
            const vec<T, R>& c2) noexcept;

        /*!
         * \brief     Constructs a `mat` with the given columns.
         * \details   This overload is only available when `C` equals `4`.
         *
         * \param c0  The first column.
         * \param c1  The second column.
         * \param c2  The third column.
         * \param c3  The fourth column.
         */
        inline constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1,
            const vec<T, R>& c2,
            const vec<T, R>& c3) noexcept;

        /*!
         * \brief      Explicitly casts another `mat` to a new size and/or
         *             component type.
         * \details    If the new `mat` is larger than `m` in either dimension,
         *             the new components without corresponding components in
         *             `m` will be constructed with `1` along the main diagonal
         *             and `0` otherwise. If the new `mat` is smaller in either
         *             dimension, the components from `m` without corresponding
         *             components in the new `mat` will be ignored.
         *
         * \tparam MT  The component type of `m`.
         * \tparam MC  The column count of `m`.
         * \tparam MR  The row count of `m`.
         *
         * \param m    The `mat` to cast from.
         */
        template<typename MT, int MC, int MR>
        inline explicit constexpr mat(const mat<MT, MC, MR>& m) noexcept;

        /*!
         * \brief     Implicitly casts this `mat` to a new component type.
         * \tparam U  The new component type.
         * \return    A new `mat` with the new component type.
         */
        template<typename U>
        inline constexpr operator mat<U, C, R>() const noexcept;

        /*!
         * \brief   Returns a `mat` with the main diagonal set to `1` and all
         *          other components set to `0`.
         *
         * \return  A `mat` with the main diagonal set to `1` and all other
         *          components set to `0`.
         */
        inline static constexpr mat<T, C, R> identity() noexcept;

        /*!
         * \brief   Returns a `mat` with each component set to `0`.
         * \return  A `mat` with each component set to `0`.
         */
        inline static constexpr mat<T, C, R> zero() noexcept;

        /*!
         * \brief     Returns a reference to the column at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the column at the given index.
         */
        template<typename I>
        inline constexpr const vec<T, R>& operator[](const I& i) const noexcept;

        /*!
         * \brief     Returns a reference to the column at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the column at the given index.
         */
        template<typename I>
        inline vec<T, R>& operator[](const I& i) noexcept;

        /*!
         * \brief   Returns a pointer to this `mat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `mat`'s underlying component array.
         */
        inline const T* data() const noexcept;

        /*!
         * \brief   Returns a pointer to this `mat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `mat`'s underlying component array.
         */
        inline T* data() noexcept;

        /*!
         * \brief   Returns a pointer to this `mat`'s underlying column array.
         * \return  A pointer to this `mat`'s underlying column array.
         */
        inline const vec<T, R>* columns() const noexcept;

        /*!
         * \brief   Returns a pointer to this `mat`'s underlying column array.
         * \return  A pointer to this `mat`'s underlying column array.
         */
        inline vec<T, R>* columns() noexcept;

        /*!
         * \brief     Returns a copy of the column at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A copy of the column at the given index.
         */
        template<typename I>
        inline constexpr vec<T, R> column(const I& i) const noexcept;

        /*!
         * \brief     Returns a copy of the row at the given index.
         * \details   No bounds checking is performed.
         * \tparam J  The index type.
         * \param j   The index.
         * \return    A copy of the row at the given index.
         */
        template<typename J>
        inline constexpr vec<T, C> row(const J& j) const noexcept;

        /*!
         * \brief     Sets the values of the column at the given index.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         * \param v   The new values for the column.
         */
        template<typename I>
        inline void set_column(const I& i, const vec<T, R>& v) noexcept;

        /*!
         * \brief     Sets the values of the row at the given index.
         *
         * \tparam J  The index type.
         *
         * \param j   The index.
         * \param v   The new values for the row.
         */
        template<typename J>
        inline void set_row(const J& j, const vec<T, C>& v) noexcept;

        /*!
         * \brief   Pre-increments each column of this `mat`.
         * \return  A reference to this `mat`.
         */
        inline mat<T, C, R>& operator++() noexcept;

        /*!
         * \brief   Post-increments each column of this `mat`.
         * \return  A copy of this `mat` before being incremented.
         */
        inline mat<T, C, R> operator++(int) noexcept;

        /*!
         * \brief   Pre-decrements each column of this `mat`.
         * \return  A reference to this `mat`.
         */
        inline mat<T, C, R>& operator--() noexcept;

        /*!
         * \brief   Post-decrements each column of this `mat`.
         * \return  A copy of this `mat` before being decremented.
         */
        inline mat<T, C, R> operator--(int) noexcept;

        /*!
         * \brief     Adds `x` to each column of this `mat`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to add to each column of this `mat`.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator+=(const U& x) noexcept;

        /*!
         * \brief     Adds each column of `m` to the corresponding column of
         *            this `mat`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to add to each column of this `mat`.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator+=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Subtracts `x` from each column of this `mat`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to subtract from each column of this `mat`.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator-=(const U& x) noexcept;

        /*!
         * \brief     Subtracts each column of `m` from the corresponding
         *            component of this `mat`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to subtract from each column of this `mat`.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator-=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Multiplies each column of this `mat` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to multiply each column of this `mat` by.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator*=(const U& x) noexcept;

        /*!
         * \brief     Multiplies this mat by `m`.
         * \tparam U  The component type of `m`.
         * \param m   A `mat`.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator*=(const mat<U, C, C>& m) noexcept;

        /*!
         * \brief     Divides each column of this `mat` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to divide each column of this `mat` by.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator/=(const U& x) noexcept;

        /*!
         * \brief     Divides each column of this `mat` by the corresponding
         *            component from `m`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to divide each column of this `mat` by.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator/=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Modulos each column of this `mat` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to modulo each column of this `mat` by.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator%=(const U& x) noexcept;

        /*!
         * \brief     Modulos each column of this `mat` by the corresponding
         *            component from `m`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to modulo each column of this `mat` by.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator%=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise ANDs each column of this `mat` with `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to bitwise AND each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator&=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ANDs each column of this `mat` with the
         *            corresponding component from `m`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to bitwise AND each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator&=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise ORs each column of this `mat` with `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to bitwise OR each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator|=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ORs each column of this `mat` with the
         *            corresponding component from `m`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to bitwise OR each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator|=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise XORs each column of this `mat` with `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to bitwise XOR each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator^=(const U& x) noexcept;

        /*!
         * \brief     Bitwise XORs each column of this `mat` with the
         *            corresponding component from `m`.
         * \tparam U  The component type of `m`.
         * \param m   The columns to bitwise XOR each column of this `mat` with.
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator^=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise shifts left each column of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise shift left each column of this `mat`
         *            by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator<<=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts left each column of this `mat` by the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The columns to bitwise shift left each column of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator<<=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise shifts right each column of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise right left each column of this `mat`
         *            by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator>>=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts right each column of this `mat` by the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The columns to bitwise shift right each column of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>& operator>>=(const mat<U, C, R>& m) noexcept;
    };
}

#include "detail_/mat4xR.hpp"
