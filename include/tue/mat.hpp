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

#include "math.hpp"
#include "vec.hpp"

namespace tue
{
    /*!
     * \defgroup  mat_hpp <tue/mat.hpp>
     *
     * \brief     The `mat` class template and its associated functions.
     *
     * @{
     */

    /*!
     * \brief     A column-major matrix.
     * \details   `mat` have the same size and alignment requirements as
     *            `vec<T, R>[C]`.
     *
     * \tparam T  The component type. `is_vec_component<T>::value` must be
     *            `true`.
     * \tparam C  The column count. Must be `2`, `3`, or `4`.
     * \tparam R  The row count. Must be `2`, `3`, or `4`.
     */
    template<typename T, int C, int R>
    class mat;

    /*!
     * \brief     A 2x2 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x2 = mat<T, 2, 2>;

    /*!
     * \brief     A 2x3 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x3 = mat<T, 2, 3>;

    /*!
     * \brief     A 2x4 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat2x4 = mat<T, 2, 4>;

    /*!
     * \brief     A 3x2 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x2 = mat<T, 3, 2>;

    /*!
     * \brief     A 3x3 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x3 = mat<T, 3, 3>;

    /*!
     * \brief     A 3x4 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat3x4 = mat<T, 3, 4>;

    /*!
     * \brief     A 4x2 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat4x2 = mat<T, 4, 2>;

    /*!
     * \brief     A 4x3 matrix.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using mat4x3 = mat<T, 4, 3>;

    /*!
     * \brief     A 4x4 matrix.
     *
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
            std::enable_if_t<
                is_vec_component<T>::value
                    && (C >= 2 && C <= 4 && R >= 2 && R <= 4),
                vec<T, R>[C]>
            columns;
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
         * \name Constructors, Conversions, and Factory Functions
         * @{
         */
        /*!
         * \brief  Default constructs each component.
         */
        mat() noexcept = default;

        /*!
         * \brief    Constructs each component along the main diagonal with the
         *           same value, and all other components with `0`.
         *
         * \param x  The value to construct the main diagonal with.
         */
        inline explicit constexpr mat(
            const T& x) noexcept;

        /*!
         * \brief    Constructs each column with the same values.
         *
         * \param c  The values to construct each column with.
         */
        inline explicit constexpr mat(
            const vec<T, R>& c) noexcept;

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
         * \brief      Explicitly casts another `mat` to a new size.
         * \details    If the new `mat` is larger than `m` in either dimension,
         *             the new components without corresponding components in
         *             `m` will be constructed with `1` along the main diagonal
         *             and `0` otherwise. If the new `mat` is smaller in either
         *             dimension, the components from `m` without corresponding
         *             components in the new `mat` will be ignored.
         *
         * \tparam MC  The column count of `m`.
         * \tparam MR  The row count of `m`.
         *
         * \param m    The `mat` to cast from.
         */
        template<int MC, int MR>
        inline explicit constexpr mat(const mat<T, MC, MR>& m) noexcept;

        /*!
         * \brief     Explicitly casts another `mat` to a new component type.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The `mat` to cast from.
         */
        template<typename U>
        inline explicit constexpr mat(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Implicitly casts this `mat` to a new component type.
         *
         * \tparam U  The new component type.
         *
         * \return    A new `mat` with the new component type.
         */
        template<typename U>
        inline constexpr operator mat<U, C, R>() const noexcept;

        /*!
         * \brief    Returns a `mat` with each component constructed with the
         *           same value.
         *
         * \param x  The value to construct each component with.
         *
         * \return   A `mat` with each component constructed with the same
         *           value.
         */
        inline static constexpr mat<T, C, R> fill(const T& x) noexcept;

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
         *
         * \return  A `mat` with each component set to `0`.
         */
        inline static constexpr mat<T, C, R> zero() noexcept;

        /*!@}*/
        /*!
         * \brief     Returns a reference to the column at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         *
         * \return    A reference to the column at the given index.
         */
        template<typename I>
        inline constexpr const vec<T, R>& operator[](const I& i) const noexcept;

        /*!
         * \brief     Returns a reference to the column at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         *
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
         *
         * \return  A pointer to this `mat`'s underlying column array.
         */
        inline const vec<T, R>* columns() const noexcept;

        /*!
         * \brief   Returns a pointer to this `mat`'s underlying column array.
         *
         * \return  A pointer to this `mat`'s underlying column array.
         */
        inline vec<T, R>* columns() noexcept;

        /*!
         * \brief     Returns a copy of the column at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         *
         * \return    A copy of the column at the given index.
         */
        template<typename I>
        inline constexpr vec<T, R> column(const I& i) const noexcept;

        /*!
         * \brief     Sets the values of the column at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         * \param v   The new values for the column.
         */
        template<typename I>
        inline void set_column(const I& i, const vec<T, R>& v) noexcept;

        /*!
         * \brief     Returns a copy of the row at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam J  The index type.
         *
         * \param j   The index.
         *
         * \return    A copy of the row at the given index.
         */
        template<typename J>
        inline constexpr vec<T, C> row(const J& j) const noexcept;

        /*!
         * \brief     Sets the values of the row at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam J  The index type.
         *
         * \param j   The index.
         * \param v   The new values for the row.
         */
        template<typename J>
        inline void set_row(const J& j, const vec<T, C>& v) noexcept;

        /*!
         * \brief   Pre-increments each component of this `mat`.
         *
         * \return  A reference to this `mat`.
         */
        inline mat<T, C, R>& operator++() noexcept;

        /*!
         * \brief   Post-increments each component of this `mat`.
         *
         * \return  A copy of this `mat` before being incremented.
         */
        inline mat<T, C, R> operator++(int) noexcept;

        /*!
         * \brief   Pre-decrements each component of this `mat`.
         *
         * \return  A reference to this `mat`.
         */
        inline mat<T, C, R>& operator--() noexcept;

        /*!
         * \brief   Post-decrements each component of this `mat`.
         *
         * \return  A copy of this `mat` before being decremented.
         */
        inline mat<T, C, R> operator--(int) noexcept;

        /*!
         * \brief     Adds `x` to each component of this `mat`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to add to each component of this `mat`.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator+=(const U& x) noexcept;

        /*!
         * \brief     Adds each component of `m` to the corresponding component
         *            of this `mat`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to add to each component of this `mat`.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator+=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Subtracts `x` from each component of this `mat`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to subtract from each component of this `mat`.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator-=(const U& x) noexcept;

        /*!
         * \brief     Subtracts each component of `m` from the corresponding
         *            component of this `mat`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to subtract from each component of this `mat`.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator-=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Multiplies each component of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to multiply each component of this `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator*=(const U& x) noexcept;

        /*!
         * \brief     Matrix multiplies this mat by `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator*=(const mat<U, C, C>& m) noexcept;

        /*!
         * \brief     Divides each component of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to divide each component of this `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator/=(const U& x) noexcept;

        /*!
         * \brief     Divides each component of this `mat` by the corresponding
         *            component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to divide each component of this `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator/=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Modulos each component of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to modulo each component of this `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator%=(const U& x) noexcept;

        /*!
         * \brief     Modulos each component of this `mat` by the corresponding
         *            component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to modulo each component of this `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator%=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise ANDs each component of this `mat` with `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise AND each component of this `mat`
         *            with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator&=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ANDs each component of this `mat` with the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to bitwise AND each component of this `mat`
         *            with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator&=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise ORs each component of this `mat` with `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise OR each component of this `mat` with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator|=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ORs each component of this `mat` with the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to bitwise OR each component of this `mat`
         *            with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator|=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise XORs each component of this `mat` with `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise XOR each component of this `mat`
         *            with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator^=(const U& x) noexcept;

        /*!
         * \brief     Bitwise XORs each component of this `mat` with the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to bitwise XOR each component of this `mat`
         *            with.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator^=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise shifts left each component of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise shift left each component of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator<<=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts left each component of this `mat` by the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to bitwise shift left each component of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator<<=(const mat<U, C, R>& m) noexcept;

        /*!
         * \brief     Bitwise shifts right each component of this `mat` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise shift right each component of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline std::enable_if_t<is_vec_component<U>::value, mat<T, C, R>&>
        operator>>=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts right each component of this `mat` by the
         *            corresponding component from `m`.
         *
         * \tparam U  The component type of `m`.
         *
         * \param m   The values to bitwise shift right each component of this
         *            `mat` by.
         *
         * \return    A reference to this `mat`.
         */
        template<typename U>
        inline mat<T, C, R>&
        operator>>=(const mat<U, C, R>& m) noexcept;
    };

    /*!@}*/
    namespace detail_
    {
        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column2(const mat<T, 2, MR>&) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(0, 0, 1, 0);
        }

        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column2(const mat<T, 3, MR>& m) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(m[2], 1, 0);
        }

        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column2(const mat<T, 4, MR>& m) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(m[2], 1, 0);
        }

        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column3(const mat<T, 2, MR>&) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(0, 0, 0, 1);
        }

        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column3(const mat<T, 3, MR>&) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(0, 0, 0, 1);
        }

        template<typename T, int R, int MR>
        inline constexpr vec<T, R> mat_column3(const mat<T, 4, MR>& m) noexcept
        {
            return tue::detail_::vec_utils<T, R>::create(m[3], 0, 1);
        }

        template<typename T, int C, int R>
        struct mat_utils;
    }
}

#include "detail_/mat2xR.hpp"
#include "detail_/mat3xR.hpp"
#include "detail_/mat4xR.hpp"
#include "detail_/matmult.hpp"

#define shift_left <<
#define shift_right >> // Because ">>" inside template args confuses Doxygen

namespace tue
{
    /*!
     * \addtogroup  mat_hpp
     * @{
     */

    /*!
     * \brief     Computes the unary plus of each component of `m`.
     *
     * \tparam T  The component type of `m`.
     * \tparam C  The column count of `m`.
     * \tparam R  The row count of `m`.
     *
     * \param m   A `mat`.
     *
     * \return    The unary plus of each component of `m`.
     */
    template<typename T, int C, int R>
    inline constexpr
        mat<decltype(+std::declval<T>()), C, R>
    operator+(const mat<T, C, R>& m) noexcept
    {
        return tue::detail_::unary_plus_operator_m(m);
    }

    /*!
     * \brief     Computes the unary minus of each component of `m`.
     *
     * \tparam T  The component type of `m`.
     * \tparam C  The column count of `m`.
     * \tparam R  The row count of `m`.
     *
     * \param m   A `mat`.
     *
     * \return    The unary minus of each component of `m`.
     */
    template<typename T, int C, int R>
    inline constexpr
        mat<decltype(-std::declval<T>()), C, R>
    operator-(const mat<T, C, R>& m) noexcept
    {
        return tue::detail_::unary_minus_operator_m(m);
    }

    /*!
     * \brief     Computes the bitwise NOT of each component of `m`.
     *
     * \tparam T  The component type of `m`.
     * \tparam C  The column count of `m`.
     * \tparam R  The row count of `m`.
     *
     * \param m   A `mat`.
     *
     * \return    The bitwise NOT of each component of `m`.
     */
    template<typename T, int C, int R>
    inline constexpr
        mat<decltype(~std::declval<T>()), C, R>
    operator~(const mat<T, C, R>& m) noexcept
    {
        return tue::detail_::bitwise_not_operator_m(m);
    }

    /*!
     * \brief      Computes the sums of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() + std::declval<U>()), C, R>>
    operator+(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::addition_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the sums of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() + std::declval<U>()), C, R>>
    operator+(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::addition_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the sums of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of each component of `lhs` and each corresponding
     *             component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() + std::declval<U>()), C, R>
    operator+(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::addition_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() - std::declval<U>()), C, R>>
    operator-(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::subtraction_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() - std::declval<U>()), C, R>>
    operator-(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::subtraction_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between each component of `lhs` and
     *             each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() - std::declval<U>()), C, R>
    operator-(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::subtraction_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() * std::declval<U>()), C, R>>
    operator*(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() * std::declval<U>()), C, R>>
    operator*(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the matrix product of `lhs` and `rhs`.
     * \details    `lhs` is treated like a matrix with a single row.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The component count of `lhs` and row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The matrix product of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        vec<decltype(std::declval<T>() * std::declval<U>()), C>
    operator*(const vec<T, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_vm(lhs, rhs);
    }

    /*!
     * \brief      Computes the matrix product of `lhs` and `rhs`.
     * \details    `rhs` is treated like a matrix with a single column.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `lhs` and component count of `rhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The matrix product of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        vec<decltype(std::declval<T>() * std::declval<U>()), R>
    operator*(const mat<T, C, R>& lhs, const vec<U, C>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_mv(lhs, rhs);
    }

    /*!
     * \brief      Computes the matrix product of `lhs` and `rhs`.
     * \details    To compute the component-wise product, use
     *             `tue::math::comp_mult()` instead.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The matrix product of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int N, int R>
    inline constexpr
        mat<decltype(std::declval<T>() * std::declval<U>()), C, R>
    operator*(const mat<T, N, R>& lhs, const mat<U, C, N>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of `lhs` over each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of `lhs` over each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() / std::declval<U>()), C, R>>
    operator/(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::division_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of each component of `lhs` over `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of each component of `lhs` over `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() / std::declval<U>()), C, R>>
    operator/(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::division_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() / std::declval<U>()), C, R>
    operator/(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::division_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of `lhs` over each component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of `lhs` over each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() % std::declval<U>()), C, R>>
    operator%(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::modulo_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of each component of `lhs` over `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of each component of `lhs` over `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() % std::declval<U>()), C, R>>
    operator%(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::modulo_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() % std::declval<U>()), C, R>
    operator%(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::modulo_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() & std::declval<U>()), C, R>>
    operator&(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() & std::declval<U>()), C, R>>
    operator&(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() & std::declval<U>()), C, R>
    operator&(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() | std::declval<U>()), C, R>>
    operator|(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() | std::declval<U>()), C, R>>
    operator|(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() | std::declval<U>()), C, R>
    operator|(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() ^ std::declval<U>()), C, R>>
    operator^(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() ^ std::declval<U>()), C, R>>
    operator^(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() ^ std::declval<U>()), C, R>
    operator^(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of `lhs` by each component
     *             of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts left of `lhs` by each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() shift_left std::declval<U>()), C, R>>
    operator<<(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of each component of `lhs`
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts left of each component of `lhs` by `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() shift_left std::declval<U>()), C, R>>
    operator<<(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts left of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() shift_left std::declval<U>()), C, R>
    operator<<(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of `lhs` by each component
     *             of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of `rhs`.
     * \tparam R   The row count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts right of `lhs` by each component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<T>::value,
        mat<decltype(std::declval<T>() shift_right std::declval<U>()), C, R>>
    operator>>(const T& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator_xm(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam C   The column count of `lhs`.
     * \tparam R   The row count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts right of each component of `lhs` by `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr std::enable_if_t<
        is_vec_component<U>::value,
        mat<decltype(std::declval<T>() shift_right std::declval<U>()), C, R>>
    operator>>(const mat<T, C, R>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator_mx(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts right of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr
        mat<decltype(std::declval<T>() shift_right std::declval<U>()), C, R>
    operator>>(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Determines whether or not two `mat`'s compare equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if all the corresponding pairs of components compare
     *             equal and `false` otherwise.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr bool
    operator==(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::equality_operator_mm(lhs, rhs);
    }

    /*!
     * \brief      Determines whether or not two `mat`'s compare not equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam C   The column count of both `lhs` and `rhs`.
     * \tparam R   The row count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if at least one of the corresponding pairs of
     *             components compares not equal and `false` otherwise.
     */
    template<typename T, typename U, int C, int R>
    inline constexpr bool
    operator!=(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
    {
        return tue::detail_::inequality_operator_mm(lhs, rhs);
    }

    /*!@}*/
    namespace math
    {
        /*!
         * \addtogroup  mat_hpp
         * @{
         */

        /*!
         * \brief     Computes `tue::math::sin()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::sin()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> sin(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::sin_m(m);
        }

        /*!
         * \brief     Computes `tue::math::cos()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::cos()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> cos(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::cos_m(m);
        }

        /*!
         * \brief          Computes `tue::math::sincos()` for each component of
         *                 `m`.
         *
         * \tparam T       The component type of `m`.
         * \tparam C       The column count of `m`.
         * \tparam R       The row count of `m`.
         *
         * \param m        A `mat`.
         * \param sin_out  A reference to the `mat` to store the `sin()` results
         *                 in.
         * \param cos_out  A reference to the `mat` to store the `cos()` results
         *                 in.
         */
        template<typename T, int C, int R>
        inline void sincos(
            const mat<T, C, R>& m,
            mat<T, C, R>& sin_out,
            mat<T, C, R>& cos_out) noexcept
        {
            tue::detail_::sincos_m(m, sin_out, cos_out);
        }

        /*!
         * \brief     Computes `tue::math::exp()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::exp()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> exp(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::exp_m(m);
        }

        /*!
         * \brief     Computes `tue::math::log()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::log()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> log(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::log_m(m);
        }

        /*!
         * \brief     Computes `tue::math::abs()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::abs()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> abs(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::abs_m(m);
        }

        /*!
         * \brief            Computes `tue::math::pow()` for each component of
         *                   `bases` and each corresponding component of
         *                   `exponents`.
         *
         * \tparam T         The component type of both `bases` and `exponents`.
         * \tparam C         The column count of both `bases` and `exponents`.
         * \tparam R         The row count of both `bases` and `exponents`.
         *
         * \param bases      The bases.
         * \param exponents  The exponents.
         *
         * \return           `tue::math::pow()` for each component of `bases`
         *                   and each corresponding component of `exponents`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> pow(
            const mat<T, C, R>& bases, const mat<T, C, R>& exponents) noexcept
        {
            return tue::detail_::pow_mm(bases, exponents);
        }

        /*!
         * \brief     Computes `tue::math::recip()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::recip()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> recip(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::recip_m(m);
        }

        /*!
         * \brief     Computes `tue::math::sqrt()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::sqrt()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> sqrt(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::sqrt_m(m);
        }

        /*!
         * \brief     Computes `tue::math::rsqrt()` for each component of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    `tue::math::rsqrt()` for each component of `m`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> rsqrt(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::rsqrt_m(m);
        }

        /*!
         * \brief     Computes `tue::math::min()` for each corresponding pair of
         *            components from `m1` and `m2`.
         *
         * \tparam T  The component type of both `m1` and `m2`.
         * \tparam C  The column count of both `m1` and `m2`.
         * \tparam R  The row count of both `m1` and `m2`.
         *
         * \param m1  A `mat`.
         * \param m2  Another `mat`.
         *
         * \return    `tue::math::min()` for each corresponding pair of
         *            components from `m1` and `m2`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> min(
            const mat<T, C, R>& m1, const mat<T, C, R>& m2) noexcept
        {
            return tue::detail_::min_mm(m1, m2);
        }

        /*!
         * \brief     Computes `tue::math::max()` for each corresponding pair of
         *            components from `m1` and `m2`.
         *
         * \tparam T  The component type of both `m1` and `m2`.
         * \tparam C  The column count of both `m1` and `m2`.
         * \tparam R  The row count of both `m1` and `m2`.
         *
         * \param m1  A `mat`.
         * \param m2  Another `mat`.
         *
         * \return    `tue::math::max()` for each corresponding pair of
         *            components from `m1` and `m2`.
         */
        template<typename T, int C, int R>
        inline mat<T, C, R> max(
            const mat<T, C, R>& m1, const mat<T, C, R>& m2) noexcept
        {
            return tue::detail_::max_mm(m1, m2);
        }

        /*!
         * \brief             Computes `tue::math::mask()` for each
         *                    corresponding pair of components from `conditions`
         *                    and `values`.
         *
         * \tparam T          The component type of `conditions`.
         * \tparam U          The component type of `values`.
         * \tparam C          The column count of both `conditions` and
         *                    `values`.
         * \tparam R          The row count of both `conditions` and `values`.
         *
         * \param conditions  A `mat`.
         * \param values      Another `mat`.
         *
         * \return            `tue::math::mask()` for each corresponding pair of
         *                    components from `conditions` and `values`.
         */
        template<typename T, typename U, int C, int R>
        inline mat<U, C, R> mask(
            const mat<T, C, R>& conditions,
            const mat<U, C, R>& values) noexcept
        {
            return tue::detail_::mask_mm(conditions, values);
        }

        /*!
         * \brief             Computes `tue::math::select()` for each
         *                    corresponding trio of components from
         *                    `conditions`, `values`, and `otherwise`.
         *
         * \tparam T          The component type of `conditions`.
         * \tparam U          The component type of both `values` and
         *                    `otherwise`.
         * \tparam C          The column count of all three parameters.
         * \tparam R          The row count of all three parameters.
         *
         * \param conditions  A `mat`.
         * \param values      Another `mat`.
         * \param otherwise   Another `mat`.
         *
         * \return            `tue::math::select()` for each corresponding trio
         *                    of components from `conditions`, `values`, and
         *                    `otherwise`.
         */
        template<typename T, typename U, int C, int R>
        inline mat<U, C, R> select(
            const mat<T, C, R>& conditions,
            const mat<U, C, R>& values,
            const mat<U, C, R>& otherwise) noexcept
        {
            return tue::detail_::select_mmm(conditions, values, otherwise);
        }

        /*!
         * \brief      Computes `tue::math::less()` for each corresponding pair
         *             of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::less(
                std::declval<T>(), std::declval<T>())),
            C, R>
        less(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::less_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::less_equal()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less_equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::less_equal(
                std::declval<T>(), std::declval<T>())),
            C, R>
        less_equal(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::less_equal_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::greater(
                std::declval<T>(), std::declval<T>())),
            C, R>
        greater(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::greater_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater_equal()` for each
         *             corresponding pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater_equal()` for each corresponding pair
         *             of components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::greater_equal(
                std::declval<T>(), std::declval<T>())),
            C, R>
        greater_equal(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::greater_equal_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::equal()` for each corresponding pair
         *             of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::equal(
                std::declval<T>(), std::declval<T>())),
            C, R>
        equal(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::equal_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::not_equal()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::not_equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int C, int R>
        inline mat<
            decltype(tue::math::not_equal(
                std::declval<T>(), std::declval<T>())),
            C, R>
        not_equal(const mat<T, C, R>& lhs, const mat<T, C, R>& rhs) noexcept
        {
            return tue::detail_::not_equal_mm(lhs, rhs);
        }

        /*!
         * \brief      Computes the products of each component of `lhs` and each
         *             corresponding component of `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam C   The column count of both `lhs` and `rhs`.
         * \tparam R   The row count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     The products of each component of `lhs` and each
         *             corresponding component of `rhs`.
         */
        template<typename T, typename U, int C, int R>
        inline constexpr
            mat<decltype(std::declval<T>() * std::declval<U>()), C, R>
        comp_mult(const mat<T, C, R>& lhs, const mat<U, C, R>& rhs) noexcept
        {
            return tue::detail_::comp_mult_mm(lhs, rhs);
        }

        /*!
         * \brief     Computes the transpose of `m`.
         *
         * \tparam T  The component type of `m`.
         * \tparam C  The column count of `m`.
         * \tparam R  The row count of `m`.
         *
         * \param m   A `mat`.
         *
         * \return    The transpose of `m`.
         */
        template<typename T, int C, int R>
        inline constexpr
            mat<T, R, C>
        transpose(const mat<T, C, R>& m) noexcept
        {
            return tue::detail_::transpose_m(m);
        }

        /*!@}*/
    }
}

#undef shift_right
#undef shift_left
