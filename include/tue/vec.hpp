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

namespace tue
{
    /*!
     * \brief     An `N`-dimensional vector.
     * \details   `vec` has the same size and alignment requirements as `T[N]`.
     *
     * \tparam T  The component type.
     * \tparam N  The component count. Must be 2, 3, or 4.
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

    /**/
    template<typename T, int N>
    class vec
    {
        struct { std::enable_if_t<(N >= 2 && N <= 4), T> data[N]; } impl_;

    public:
        /*!
         * \brief  This `vec` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `vec` type's component count.
         */
        static constexpr int component_count = N;

        /*!
         * \brief  Default constructs each component.
         */
        vec() noexcept = default;

        /*!
         * \brief     Constructs each component with the same value.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to construct each component with.
         */
        template<typename U>
        inline explicit constexpr vec(const U& x) noexcept;

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         * \details  This overload is only available when `N` equals `2`.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         */
        inline constexpr vec(const T& x, const T& y) noexcept;

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         * \details  This overload is only available when `N` equals `3`.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         * \param z  The value to construct the third component with.
         */
        inline constexpr vec(const T& x, const T& y, const T& z) noexcept;

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         * \details  This overload is only available when `N` equals `4`.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         * \param z  The value to construct the third component with.
         * \param w  The value to construct the fourth component with.
         */
        inline constexpr vec(
            const T& x, const T& y, const T& z, const T& w) noexcept;

        /*!
         * \brief     Constructs each component with the value of the
         *            corresponding argument.
         * \details   This overload is only available when `N` equals `3`.
         *
         * \param xy  The values to construct the first two components with.
         * \param z   The value to construct the third component with.
         */
        inline constexpr vec(const vec2<T>& xy, const T& z) noexcept;

        /*!
         * \brief     Constructs each component with the value of the
         *            corresponding argument.
         * \details   This overload is only available when `N` equals `4`.
         *
         * \param xy  The values to construct the first two components with.
         * \param z   The value to construct the third component with.
         * \param w   The value to construct the fourth component with.
         */
        inline constexpr vec(
            const vec2<T>& xy, const T& z, const T& w) noexcept;

        /*!
         * \brief      Constructs each component with the value of the
         *             corresponding argument.
         * \details    This overload is only available when `N` equals `4`.
         *
         * \param xyz  The values to construct the first three components with.
         * \param w    The value to construct the fourth component with.
         */
        inline constexpr vec(const vec3<T>& xyz, const T& w) noexcept;

        /*!
         * \brief    Truncates a larger `vec`.
         * \details  This overload is only available when `N` is less than `3`.
         *           When `N` equals `3`, it is replaced by the automatically
         *           generated copy constructor.
         *
         * \param v  The larger `vec` to truncate.
         */
        inline explicit constexpr vec(const vec3<T>& v) noexcept;

        /*!
         * \brief    Truncates a larger `vec`.
         * \details  This overload is only available when `N` is less than `4`.
         *           When `N` equals `4`, it is replaced by the automatically
         *           generated copy constructor.
         *
         * \param v  The larger `vec` to truncate.
         */
        inline explicit constexpr vec(const vec4<T>& v) noexcept;

        /*!
         * \brief     Explicitly casts another `vec` to a new component type.
         * \tparam U  The component type of `v`.
         * \param v   The `vec` to cast from.
         */
        template<typename U>
        inline explicit constexpr vec(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Implicitly casts this `vec` to a new component type.
         * \tparam U  The new component type.
         * \return    A new `vec` with the new component type.
         */
        template<typename U>
        inline constexpr operator vec<U, N>() const noexcept;

        /*!
         * \brief   Returns a `vec` with each component set to `0`.
         * \return  A `vec` with each component set to `0`.
         */
        inline static constexpr vec<T, N> zero() noexcept;

        /*!
         * \brief   Returns a `vec` with the first component set to `1` and all
         *          other components set to `0`.
         *
         * \return  A `vec` with the first component set to `1` and all other
         *          components set to `0`.
         */
        inline static constexpr vec<T, N> x_axis() noexcept;

        /*!
         * \brief   Returns a `vec` with the second component set to `1` and all
         *          other components set to `0`.
         *
         * \return  A `vec` with the second component set to `1` and all other
         *          components set to `0`.
         */
        inline static constexpr vec<T, N> y_axis() noexcept;

        /*!
         * \brief    Returns a `vec` with the third component set to `1` and all
         *           other components set to `0`.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \return   A `vec` with the third component set to `1` and all other
         *           components set to `0`.
         */
        inline static constexpr vec<T, N> z_axis() noexcept;

        /*!
         * \brief    Returns a `vec` with the fourth component set to `1` and
         *           all other components set to `0`.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \return   A `vec` with the fourth component set to `1` and all other
         *           components set to `0`.
         */
        inline static constexpr vec<T, N> w_axis() noexcept;

        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        inline constexpr const T& operator[](const I& i) const noexcept;

        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        inline T& operator[](const I& i) noexcept;

        /*!
         * \brief   Returns a pointer to this `vec`'s underlying component
         *          array.
         *
         * \return  A pointer to this `vec`'s underlying component array.
         */
        inline const T* data() const noexcept;

        /*!
         * \brief   Returns a pointer to this `vec`'s underlying component
         *          array.
         *
         * \return  A pointer to this `vec`'s underlying component array.
         */
        inline T* data() noexcept;

        /*!
         * \brief   Returns a copy of this `vec`'s first component.
         * \return  A copy of this `vec`'s first component.
         */
        inline constexpr T x() const noexcept;

        /*!
         * \brief   Returns a copy of this `vec`'s second component.
         * \return  A copy of this `vec`'s second component.
         */
        inline constexpr T y() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s third component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \return   A copy of this `vec`'s third component.
         */
        inline constexpr T z() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s fourth component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \return   A copy of this `vec`'s fourth component.
         */
        inline constexpr T w() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first two components.
         * \return   A copy of this `vec`'s first two components.
         */
        inline constexpr vec2<T> xy() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first three components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \return   A copy of this `vec`'s first three components.
         */
        inline constexpr vec3<T> xyz() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first four components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \return   A copy of this `vec`'s first four components.
         */
        inline constexpr vec4<T> xyzw() const noexcept;

        /*!
         * \brief   Returns a copy of this `vec`'s first component.
         * \return  A copy of this `vec`'s first component.
         */
        inline constexpr T r() const noexcept;

        /*!
         * \brief   Returns a copy of this `vec`'s second component.
         * \return  A copy of this `vec`'s second component.
         */
        inline constexpr T g() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s third component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \return   A copy of this `vec`'s third component.
         */
        inline constexpr T b() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s fourth component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \return   A copy of this `vec`'s fourth component.
         */
        inline constexpr T a() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first two components.
         * \return   A copy of this `vec`'s first two components.
         */
        inline constexpr vec2<T> rg() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first three components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \return   A copy of this `vec`'s first three components.
         */
        inline constexpr vec3<T> rgb() const noexcept;

        /*!
         * \brief    Returns a copy of this `vec`'s first four components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \return   A copy of this `vec`'s first four components.
         */
        inline constexpr vec4<T> rgba() const noexcept;

        /*!
         * \brief    Sets this `vec`'s first component.
         * \param x  The new value for the first component.
         */
        inline void set_x(const T& x) noexcept;

        /*!
         * \brief    Sets this `vec`'s second component.
         * \param y  The new value for the second component.
         */
        inline void set_y(const T& y) noexcept;

        /*!
         * \brief    Sets this `vec`'s third component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \param z  The new value for the third component.
         */
        inline void set_z(const T& z) noexcept;

        /*!
         * \brief    Sets this `vec`'s fourth component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \param w  The new value for the fourth component.
         */
        inline void set_w(const T& w) noexcept;

        /*!
         * \brief    Sets this `vec`'s first two components.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         */
        inline void set_xy(const T& x, const T& y) noexcept;

        /*!
         * \brief     Sets this `vec`'s first two components.
         * \param xy  The new values for the first two components.
         */
        inline void set_xy(const vec2<T>& xy) noexcept;

        /*!
         * \brief    Sets this `vec`'s first three components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         * \param z  The new value for the third component.
         */
        inline void set_xyz(const T& x, const T& y, const T& z) noexcept;

        /*!
         * \brief     Sets this `vec`'s first three components.
         * \details   This overload is only available when `N` is greater than
         *            or equal to `3`.
         *
         * \param xy  The new values for the first two components.
         * \param z   The new value for the third component.
         */
        inline void set_xyz(const vec2<T>& xy, const T& z) noexcept;

        /*!
         * \brief      Sets this `vec`'s first three components.
         * \details    This overload is only available when `N` is greater than
         *             or equal to `3`.
         *
         * \param xyz  The new values for the first three components.
         */
        inline void set_xyz(const vec3<T>& xyz) noexcept;

        /*!
         * \brief    Sets this `vec`'s first four components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         * \param z  The new value for the third component.
         * \param w  The new value for the fourth component.
         */
        inline void set_xyzw(
            const T& x, const T& y, const T& z, const T& w) noexcept;

        /*!
         * \brief     Sets this `vec`'s first four components.
         * \details   This overload is only available when `N` is greater than
         *            or equal to `4`.
         *
         * \param xy  The new values for the first two components.
         * \param z   The new value for the third component.
         * \param w   The new value for the fourth component.
         */
        inline void set_xyzw(
            const vec2<T>& xy, const T& z, const T& w) noexcept;

        /*!
         * \brief      Sets this `vec`'s first four components.
         * \details    This overload is only available when `N` is greater than
         *             or equal to `4`.
         *
         * \param xyz  The new values for the first three components.
         * \param w    The new value for the fourth component.
         */
        inline void set_xyzw(const vec3<T>& xyz, const T& w) noexcept;

        /*!
         * \brief       Sets this `vec`'s first four components.
         * \details     This overload is only available when `N` is greater than
         *              or equal to `4`.
         *
         * \param xyzw  The new values for the first four components.
         */
        inline void set_xyzw(const vec4<T>& xyzw) noexcept;

        /*!
         * \brief    Sets this `vec`'s first component.
         * \param r  The new value for the first component.
         */
        inline void set_r(const T& r) noexcept;

        /*!
         * \brief    Sets this `vec`'s second component.
         * \param g  The new value for the second component.
         */
        inline void set_g(const T& g) noexcept;

        /*!
         * \brief    Sets this `vec`'s third component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \param b  The new value for the third component.
         */
        inline void set_b(const T& b) noexcept;

        /*!
         * \brief    Sets this `vec`'s fourth component.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \param a  The new value for the fourth component.
         */
        inline void set_a(const T& a) noexcept;

        /*!
         * \brief    Sets this `vec`'s first two components.
         *
         * \param r  The new value for the first component.
         * \param g  The new value for the second component.
         */
        inline void set_rg(const T& r, const T& g) noexcept;

        /*!
         * \brief     Sets this `vec`'s first two components.
         * \param rg  The new values for the first two components.
         */
        inline void set_rg(const vec2<T>& rg) noexcept;

        /*!
         * \brief    Sets this `vec`'s first three components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `3`.
         *
         * \param r  The new value for the first component.
         * \param g  The new value for the second component.
         * \param b  The new value for the third component.
         */
        inline void set_rgb(const T& r, const T& g, const T& b) noexcept;

        /*!
         * \brief     Sets this `vec`'s first three components.
         * \details   This overload is only available when `N` is greater than
         *            or equal to `3`.
         *
         * \param rg  The new values for the first two components.
         * \param b   The new value for the third component.
         */
        inline void set_rgb(const vec2<T>& rg, const T& b) noexcept;

        /*!
         * \brief      Sets this `vec`'s first three components.
         * \details    This overload is only available when `N` is greater than
         *             or equal to `3`.
         *
         * \param rgb  The new values for the first three components.
         */
        inline void set_rgb(const vec3<T>& rgb) noexcept;

        /*!
         * \brief    Sets this `vec`'s first four components.
         * \details  This overload is only available when `N` is greater than or
         *           equal to `4`.
         *
         * \param r  The new value for the first component.
         * \param g  The new value for the second component.
         * \param b  The new value for the third component.
         * \param a  The new value for the fourth component.
         */
        inline void set_rgba(
            const T& r, const T& g, const T& b, const T& a) noexcept;

        /*!
         * \brief     Sets this `vec`'s first four components.
         * \details   This overload is only available when `N` is greater than
         *            or equal to `4`.
         *
         * \param rg  The new values for the first two components.
         * \param b   The new value for the third component.
         * \param a   The new value for the fourth component.
         */
        inline void set_rgba(
            const vec2<T>& rg, const T& b, const T& a) noexcept;

        /*!
         * \brief      Sets this `vec`'s first four components.
         * \details    This overload is only available when `N` is greater than
         *             or equal to `4`.
         *
         * \param rgb  The new values for the first three components.
         * \param a    The new value for the fourth component.
         */
        inline void set_rgba(const vec3<T>& rgb, const T& a) noexcept;

        /*!
         * \brief       Sets this `vec`'s first four components.
         * \details     This overload is only available when `N` is greater than
         *              or equal to `4`.
         *
         * \param rgba  The new values for the first four components.
         */
        inline void set_rgba(const vec4<T>& rgba) noexcept;

        /*!
         * \brief   Pre-increments each component of this `vec`.
         * \return  A reference to this `vec`.
         */
        inline vec<T, N>& operator++() noexcept;

        /*!
         * \brief   Post-increments each component of this `vec`.
         * \return  A copy this `vec` before being incremented.
         */
        inline vec<T, N> operator++(int) noexcept;

        /*!
         * \brief   Pre-decrements each component of this `vec`.
         * \return  A reference to this `vec`.
         */
        inline vec<T, N>& operator--() noexcept;

        /*!
         * \brief   Post-decrements each component of this `vec`.
         * \return  A copy this `vec` before being decremented.
         */
        inline vec<T, N> operator--(int) noexcept;

        /*!
         * \brief     Adds `x` to each component of this `vec`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to add to each component of this `vec`.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator+=(const U& x) noexcept;

        /*!
         * \brief     Adds each component of `v` to the corresponding component
         *            of this `vec`.
         * \tparam U  The component type of `v`.
         * \param v   The values to add to each component of this `vec`.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator+=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Subtracts `x` from each component of this `vec`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to subtract from each component of this `vec`.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator-=(const U& x) noexcept;

        /*!
         * \brief     Subtracts each component of `v` from the corresponding
         *            component of this `vec`.
         * \tparam U  The component type of `v`.
         * \param v   The values to subtract from each component of this `vec`.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator-=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Multiplies each component of this `vec` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to multiply each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator*=(const U& x) noexcept;

        /*!
         * \brief     Multiplies each component of this `vec` by the
         *            corresponding component from `v`.
         * \tparam U  The component type of `v`.
         * \param v   The values to multiply each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator*=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Divides each component of this `vec` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to divide each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator/=(const U& x) noexcept;

        /*!
         * \brief     Divides each component of this `vec` by the corresponding
         *            component from `v`.
         * \tparam U  The component type of `v`.
         * \param v   The values to divide each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator/=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Modulos each component of this `vec` by `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to modulo each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator%=(const U& x) noexcept;

        /*!
         * \brief     Modulos each component of this `vec` by the corresponding
         *            component from `v`.
         * \tparam U  The component type of `v`.
         * \param v   The values to modulo each component of this `vec` by.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator%=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Bitwise ANDs each component of this `vec` with `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise AND each component of this `vec`
         *            with.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator&=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ANDs each component of this `vec` with the
         *            corresponding component from `v`.
         *
         * \tparam U  The component type of `v`.
         *
         * \param v   The values to bitwise AND each component of this `vec`
         *            with.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator&=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Bitwise ORs each component of this `vec` with `x`.
         * \tparam U  The type of parameter `x`.
         * \param x   The value to bitwise OR each component of this `vec` with.
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator|=(const U& x) noexcept;

        /*!
         * \brief     Bitwise ORs each component of this `vec` with the
         *            corresponding component from `v`.
         *
         * \tparam U  The component type of `v`.
         *
         * \param v   The values to bitwise OR each component of this `vec`
         *            with.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator|=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Bitwise XORs each component of this `vec` with `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise XOR each component of this `vec`
         *            with.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator^=(const U& x) noexcept;

        /*!
         * \brief     Bitwise XORs each component of this `vec` with the
         *            corresponding component from `v`.
         *
         * \tparam U  The component type of `v`.
         *
         * \param v   The values to bitwise XOR each component of this `vec`
         *            with.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator^=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Bitwise shifts left each component of this `vec` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise shift left each component of this
         *            `vec` by.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator<<=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts left each component of this `vec` by the
         *            corresponding component from `v`.
         *
         * \tparam U  The component type of `v`.
         *
         * \param v   The values to bitwise shift left each component of this
         *            `vec` by.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator<<=(const vec<U, N>& v) noexcept;

        /*!
         * \brief     Bitwise shifts right each component of this `vec` by `x`.
         *
         * \tparam U  The type of parameter `x`.
         *
         * \param x   The value to bitwise right left each component of this
         *            `vec` by.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator>>=(const U& x) noexcept;

        /*!
         * \brief     Bitwise shifts right each component of this `vec` by the
         *            corresponding component from `v`.
         *
         * \tparam U  The component type of `v`.
         *
         * \param v   The values to bitwise shift right each component of this
         *            `vec` by.
         *
         * \return    A reference to this `vec`.
         */
        template<typename U>
        inline vec<T, N>& operator>>=(const vec<U, N>& v) noexcept;
    };
}

#include "detail_/vec2.hpp"
#include "detail_/vec3.hpp"
#include "detail_/vec4.hpp"

namespace tue
{
    /*!
     * \brief     Computes the unary plus of each component of `v`.
     *
     * \tparam T  The component type of `v`.
     * \tparam N  The component count of `v`.
     *
     * \param v   A `vec`.
     *
     * \return    The unary plus of each component of `v`.
     */
    template<typename T, int N>
    inline constexpr vec<decltype(+std::declval<T>()), N>
    operator+(const vec<T, N>& v) noexcept
    {
        return tue::detail_::unary_plus_operator(v);
    }

    /*!
     * \brief     Computes the unary minus of each component of `v`.
     *
     * \tparam T  The component type of `v`.
     * \tparam N  The component count of `v`.
     *
     * \param v   A `vec`.
     *
     * \return    The unary minus of each component of `v`.
     */
    template<typename T, int N>
    inline constexpr vec<decltype(-std::declval<T>()), N>
    operator-(const vec<T, N>& v) noexcept
    {
        return tue::detail_::unary_minus_operator(v);
    }

    /*!
     * \brief     Computes the bitwise NOT of each component of `v`.
     *
     * \tparam T  The component type of `v`.
     * \tparam N  The component count of `v`.
     *
     * \param v   A `vec`.
     *
     * \return    The bitwise NOT of each component of `v`.
     */
    template<typename T, int N>
    inline constexpr vec<decltype(~std::declval<T>()), N>
    operator~(const vec<T, N>& v) noexcept
    {
        return tue::detail_::bitwise_not_operator(v);
    }

    /*!
     * \brief     Computes the logical NOT of each component of `v`.
     *
     * \tparam T  The component type of `v`.
     * \tparam N  The component count of `v`.
     *
     * \param v   A `vec`.
     *
     * \return    The logical NOT of each component of `v`.
     */
    template<typename T, int N>
    inline constexpr vec<decltype(!std::declval<T>()), N>
    operator!(const vec<T, N>& v) noexcept
    {
        return tue::detail_::logical_not_operator(v);
    }

    /*!
     * \brief      Computes the sums of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() + std::declval<U>()), N>
    operator+(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::addition_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the sums of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() + std::declval<U>()), N>
    operator+(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::addition_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the sums of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of each component of `lhs` and each corresponding
     *             component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() + std::declval<U>()), N>
    operator+(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::addition_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() - std::declval<U>()), N>
    operator-(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::subtraction_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() - std::declval<U>()), N>
    operator-(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::subtraction_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between each component of `lhs` and
     *             each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() - std::declval<U>()), N>
    operator-(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::subtraction_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), N>
    operator*(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), N>
    operator*(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::multiplication_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), N>
    operator*(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of `lhs` over each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of `lhs` over each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() / std::declval<U>()), N>
    operator/(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::division_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of each component of `lhs` over `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of each component of `lhs` over `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() / std::declval<U>()), N>
    operator/(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::division_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() / std::declval<U>()), N>
    operator/(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::division_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of `lhs` over each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of `lhs` over each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() % std::declval<U>()), N>
    operator%(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::modulo_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of each component of `lhs` over `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of each component of `lhs` over `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() % std::declval<U>()), N>
    operator%(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::modulo_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() % std::declval<U>()), N>
    operator%(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::modulo_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() & std::declval<U>()), N>
    operator&(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() & std::declval<U>()), N>
    operator&(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() & std::declval<U>()), N>
    operator&(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of `lhs` and each component of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() | std::declval<U>()), N>
    operator|(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of each component of `lhs` and `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() | std::declval<U>()), N>
    operator|(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() | std::declval<U>()), N>
    operator|(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of `lhs` and each component of
     *             `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of `lhs` and each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() ^ std::declval<U>()), N>
    operator^(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of each component of `lhs` and
     *             `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of each component of `lhs` and `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() ^ std::declval<U>()), N>
    operator^(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(std::declval<T>() ^ std::declval<U>()), N>
    operator^(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator(lhs, rhs);
    }

#define shift_left <<
#define shift_right >> // Because ">>" inside template args confuses Doxygen

    /*!
     * \brief      Computes the bitwise shifts left of `lhs` by each component
     *             of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift left of `lhs` by each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_left std::declval<U>()), N>
    operator<<(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of each component of `lhs`
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift left of each component of `lhs` by `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_left std::declval<U>()), N>
    operator<<(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift left of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_left std::declval<U>()), N>
    operator<<(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of `lhs` by each component
     *             of `rhs`.
     *
     * \tparam T   The type of parameter `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift right of `lhs` by each component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_right std::declval<U>()), N>
    operator>>(const T& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The type of parameter `rhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift right of each component of `lhs` by `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_right std::declval<U>()), N>
    operator>>(const vec<T, N>& lhs, const U& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shift right of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, typename U, int N>
    inline constexpr vec<decltype(
        std::declval<T>() shift_right std::declval<U>()), N>
    operator>>(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator(lhs, rhs);
    }

#undef shift_right
#undef shift_left

    /*!
     * \brief      Determines whether or not two `vec`'s compare equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if all the corresponding pairs of components compare
     *             equal and `false` otherwise.
     */
    template<typename T, typename U, int N>
    inline constexpr bool operator==(
        const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::equality_operator(lhs, rhs);
    }

    /*!
     * \brief      Determines whether or not two `vec`'s compare not equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if at least one of the corresponding pairs of
     *             components compares not equal and `false` otherwise.
     */
    template<typename T, typename U, int N>
    inline constexpr bool operator!=(
        const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
    {
        return tue::detail_::inequality_operator(lhs, rhs);
    }

    /**/
    namespace math
    {
        /*!
         * \brief     Computes `tue::math::sin()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::sin()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::sin(std::declval<T>())), N>
        sin(const vec<T, N>& v) noexcept
        {
            return tue::detail_::sin(v);
        }

        /*!
         * \brief     Computes `tue::math::cos()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::cos()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::cos(std::declval<T>())), N>
        cos(const vec<T, N>& v) noexcept
        {
            return tue::detail_::cos(v);
        }

        /*!
         * \brief          Computes `tue::math::sincos()` for each component of
         *                 `v`.
         *
         * \tparam T       The component type of `v`.
         * \tparam N       The component count of `v`.
         *
         * \param v        A `vec`.
         * \param sin_out  A reference to the `vec` to store the `sin()` results
         *                 in.
         * \param cos_out  A reference to the `vec` to store the `cos()` results
         *                 in.
         */
        template<typename T, int N>
        inline void sincos(
            const vec<T, N>& v,
            decltype(tue::math::sin(v))& sin_out,
            decltype(tue::math::sin(v))& cos_out) noexcept
        {
            tue::detail_::sincos(v, sin_out, cos_out);
        }

        /*!
         * \brief     Computes `tue::math::exp()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::exp()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::exp(std::declval<T>())), N>
        exp(const vec<T, N>& v) noexcept
        {
            return tue::detail_::exp(v);
        }

        /*!
         * \brief     Computes `tue::math::log()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::log()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::log(std::declval<T>())), N>
        log(const vec<T, N>& v) noexcept
        {
            return tue::detail_::log(v);
        }

        /*!
         * \brief     Computes `tue::math::abs()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::abs()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::abs(std::declval<T>())), N>
        abs(const vec<T, N>& v) noexcept
        {
            return tue::detail_::abs(v);
        }

        /*!
         * \brief            Computes `tue::math::pow()` for `base` and each
         *                   component of `exponents`.
         *
         * \tparam T         The type of parameter `base`.
         * \tparam U         The component type of `exponents`.
         * \tparam N         The component count of `exponents`.
         *
         * \param base       The base.
         * \param exponents  The exponents.
         *
         * \return           `tue::math::pow()` for `base` and each component of
         *                   `exponents`.
         */
        template<typename T, typename U, int N>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), N>
        pow(const T& base, const vec<U, N>& exponents) noexcept
        {
            return tue::detail_::pow(base, exponents);
        }

        /*!
         * \brief           Computes `tue::math::pow()` for each component of
         *                  `bases` and `exponent`.
         *
         * \tparam T        The component type of `bases`.
         * \tparam U        The type of parameter `exponent`.
         * \tparam N        The component count of `bases`.
         *
         * \param bases     The bases.
         * \param exponent  The exponent.
         *
         * \return          `tue::math::pow()` for each component of `bases` and
         *                  `exponent`.
         */
        template<typename T, typename U, int N>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), N>
        pow(const vec<T, N>& bases, const U& exponent) noexcept
        {
            return tue::detail_::pow(bases, exponent);
        }

        /*!
         * \brief            Computes `tue::math::pow()` for each component of
         *                   `bases` and each corresponding component of
         *                   `exponents`.
         *
         * \tparam T         The component type of `bases`.
         * \tparam U         The component type of `exponents`.
         * \tparam N         The component count of `bases` and `exponents`.
         *
         * \param bases      The bases.
         * \param exponents  The exponents.
         *
         * \return           `tue::math::pow()` for each component of `bases`
         *                   and each corresponding component of `exponents`.
         */
        template<typename T, typename U, int N>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), N>
        pow(const vec<T, N>& bases, const vec<U, N>& exponents) noexcept
        {
            return tue::detail_::pow(bases, exponents);
        }

        /*!
         * \brief     Computes `tue::math::recip()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::recip()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::recip(std::declval<T>())), N>
        recip(const vec<T, N>& v) noexcept
        {
            return tue::detail_::recip(v);
        }

        /*!
         * \brief     Computes `tue::math::sqrt()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::sqrt()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::sqrt(std::declval<T>())), N>
        sqrt(const vec<T, N>& v) noexcept
        {
            return tue::detail_::sqrt(v);
        }

        /*!
         * \brief     Computes `tue::math::rsqrt()` for each component of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    `tue::math::rsqrt()` for each component of `v`.
         */
        template<typename T, int N>
        inline vec<decltype(tue::math::rsqrt(std::declval<T>())), N>
        rsqrt(const vec<T, N>& v) noexcept
        {
            return tue::detail_::rsqrt(v);
        }

        /*!
         * \brief     Computes `tue::math::min()` for each corresponding pair of
         *            components of `v1` and `v2`.
         *
         * \tparam T  The component type of `v1` and `v2`.
         * \tparam N  The component count of `v1` and `v2`.
         *
         * \param v1  A `vec`.
         * \param v2  Another `vec`.
         *
         * \return    `tue::math::min()` for each corresponding pair of
         *            components of `v1` and `v2`.
         */
        template<typename T, int N>
        inline vec<T, N> min(const vec<T, N>& v1, const vec<T, N>& v2) noexcept
        {
            return tue::detail_::min(v1, v2);
        }

        /*!
         * \brief     Computes `tue::math::max()` for each corresponding pair of
         *            components of `v1` and `v2`.
         *
         * \tparam T  The component type of `v1` and `v2`.
         * \tparam N  The component count of `v1` and `v2`.
         *
         * \param v1  A `vec`.
         * \param v2  Another `vec`.
         *
         * \return    `tue::math::max()` for each corresponding pair of
         *            components of `v1` and `v2`.
         */
        template<typename T, int N>
        inline vec<T, N> max(const vec<T, N>& v1, const vec<T, N>& v2) noexcept
        {
            return tue::detail_::max(v1, v2);
        }

        /*!
         * \brief      Computes the dot product of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     The dot product of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        dot(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::dot(lhs, rhs);
        }

        /*!
         * \brief      Computes the cross product of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     The cross product of `lhs` and `rhs`.
         */
        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() * std::declval<U>())>
        cross(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[1]*rhs[2] - lhs[2]*rhs[1],
                lhs[2]*rhs[0] - lhs[0]*rhs[2],
                lhs[0]*rhs[1] - lhs[1]*rhs[0],
            };
        }

        /*!
         * \brief     Computes the vector length of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    The vector length of `v`.
         */
        template<typename T, int N>
        inline decltype(tue::math::sqrt(std::declval<T>()))
        length(const vec<T, N>& v) noexcept
        {
            return tue::math::sqrt(tue::detail_::length2(v));
        }

        /*!
         * \brief     Computes the vector length squared of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    The vector length squared of `v`.
         */
        template<typename T, int N>
        inline constexpr T length2(const vec<T, N>& v) noexcept
        {
            return tue::detail_::length2(v);
        }

        /*!
         * \brief     Computes a normalized copy of `v`.
         *
         * \tparam T  The component type of `v`.
         * \tparam N  The component count of `v`.
         *
         * \param v   A `vec`.
         *
         * \return    A normalized copy of `v`.
         */
        template<typename T, int N>
        inline decltype(std::declval<vec<T, N>>()
                      / tue::math::length(std::declval<vec<T, N>>()))
        normalize(const vec<T, N>& v) noexcept
        {
            return v / tue::math::length(v);
        }

        /*!
         * \brief             Computes `tue::math::select()` for each
         *                    corresponding triple of components from
         *                    `conditions`, `values`, and `otherwise`.
         *
         * \tparam T          The component type of `conditions`.
         * \tparam U          The component type of `values` and `otherwise`.
         * \tparam N          The component count of all three parameters.
         *
         * \param conditions  A `vec`.
         * \param values      Another `vec`.
         * \param otherwise   Another `vec`.
         *
         * \return            `tue::math::select()` for each corresponding
         *                    triple of components from `conditions`, `values`,
         *                    and `otherwise`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<U, N> select(
            const vec<T, N>& conditions,
            const vec<U, N>& values,
            const vec<U, N>& otherwise = vec<U, N>(0)) noexcept
        {
            return tue::detail_::select(conditions, values, otherwise);
        }

        /*!
         * \brief      Computes `tue::math::less()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::less(std::declval<T>(), std::declval<U>())), N>
        less(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::less(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::less_equal()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less_equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::less_equal(std::declval<T>(), std::declval<U>())), N>
        less_equal(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::less_equal(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::greater(std::declval<T>(), std::declval<U>())), N>
        greater(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::greater(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater_equal()` for each
         *             corresponding pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater_equal()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::greater_equal(std::declval<T>(), std::declval<U>())), N>
        greater_equal(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::greater_equal(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::equal()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::equal(std::declval<T>(), std::declval<U>())), N>
        equal(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::equal(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::not_equal()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of `lhs`.
         * \tparam U   The component type of `rhs`.
         * \tparam N   The component count of `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::not_equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, typename U, int N>
        inline constexpr vec<decltype(
            tue::math::not_equal(std::declval<T>(), std::declval<U>())), N>
        not_equal(const vec<T, N>& lhs, const vec<U, N>& rhs) noexcept
        {
            return tue::detail_::not_equal(lhs, rhs);
        }
    }
}
