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
     * \defgroup  quat_hpp <tue/quat.hpp>
     *
     * \brief     The `quat` class template and its associated functions.
     *
     * @{
     */

    /*!
     * \brief     A quaternion.
     * \details   `quat` has the same size and alignment requirements as `T[4]`.
     *            The first three components represent the vector part of the
     *            quaternion. The fourth component represents the scalar part.
     *
     * \tparam T  The component type. `is_vec_component<T>::value` must be
     *            `true`.
     */
    template<typename T>
    class quat;

    /*!
     * \brief  A quaternion with `float` components.
     */
    using fquat = quat<float>;

    /*!
     * \brief  A quaternion with `double` components.
     */
    using dquat = quat<double>;

    /**/
    template<typename T>
    class quat
    {
        struct
        {
            std::enable_if_t<is_vec_component<T>::value, T[4]> data;
        }
        impl_;

    public:
        /*!
         * \brief  This `quat` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `quat` type's component count.
         */
        static constexpr int component_count = 4;

        /*!
         * \name Constructors, Conversions, and Factory Functions
         * @{
         */
        /*!
         * \brief  Default constructs each component.
         */
        quat() noexcept = default;

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         * \param z  The value to construct the third component with.
         * \param w  The value to construct the fourth component with.
         */
        constexpr quat(
            const T& x, const T& y, const T& z, const T& w) noexcept
        :
            impl_({{ x, y, z, w }})
        {
        }

        /*!
         * \brief      Constructs each component with the value of the
         *             corresponding argument.
         *
         * \param xyz  The values to construct the first three components with.
         * \param w    The value to construct the fourth component with.
         */
        constexpr quat(
            const vec3<T>& xyz, const T& w) noexcept
        :
            impl_({{ xyz[0], xyz[1], xyz[2], w }})
        {
        }

        /*!
         * \brief       Explicitly casts a `vec4` to a `quat`.
         *
         * \param xyzw  The `vec` to cast from.
         */
        explicit constexpr quat(
            const vec4<T>& xyzw) noexcept
        :
            impl_({{ xyzw[0], xyzw[1], xyzw[2], xyzw[3] }})
        {
        }

        /*!
         * \brief     Explicitly casts another `quat` to a new component type.
         *
         * \tparam U  The component type of `q`.
         *
         * \param q   The `quat` to cast from.
         */
        template<typename U>
        explicit constexpr quat(const quat<U>& q) noexcept
        :
            impl_({{ T(q[0]), T(q[1]), T(q[2]), T(q[3]) }})
        {
        }

        /*!
         * \brief     Implicitly casts this `quat` to a new component type.
         *
         * \tparam U  The new component type.
         *
         * \return    A new `quat` with the new component type.
         */
        template<typename U>
        constexpr operator quat<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        /*!
         * \brief   Returns a `quat` with the fourth component set to `1` and
         *          all other components set to `0`.
         *
         * \return  A `quat` with the fourth component set to `1` and all other
         *          components set to `0`.
         */
        static constexpr quat<T> identity() noexcept
        {
            return { T(0), T(0), T(0), T(1) };
        }

        /*!@}*/
        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         *
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        constexpr const T& operator[](const I& i) const noexcept
        {
            return this->impl_.data[i];
        }

        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         *
         * \tparam I  The index type.
         *
         * \param i   The index.
         *
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        T& operator[](const I& i) noexcept
        {
            return this->impl_.data[i];
        }

        /*!
         * \brief   Returns a pointer to this `quat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `quat`'s underlying component array.
         */
        const T* data() const noexcept
        {
            return this->impl_.data;
        }

        /*!
         * \brief   Returns a pointer to this `quat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `quat`'s underlying component array.
         */
        T* data() noexcept
        {
            return this->impl_.data;
        }

        /*!
         * \brief   Returns a copy of this `quat`'s first component.
         *
         * \return  A copy of this `quat`'s first component.
         */
        constexpr T x() const noexcept
        {
            return this->impl_.data[0];
        }

        /*!
         * \brief   Returns a copy of this `quat`'s second component.
         *
         * \return  A copy of this `quat`'s second component.
         */
        constexpr T y() const noexcept
        {
            return this->impl_.data[1];
        }

        /*!
         * \brief   Returns a copy of this `quat`'s third component.
         *
         * \return  A copy of this `quat`'s third component.
         */
        constexpr T z() const noexcept
        {
            return this->impl_.data[2];
        }

        /*!
         * \brief   Returns a copy of this `quat`'s fourth component.
         *
         * \return  A copy of this `quat`'s fourth component.
         */
        constexpr T w() const noexcept
        {
            return this->impl_.data[3];
        }

        /*!
         * \brief   Returns a copy of this `quat`'s first three components.
         *
         * \return  A copy of this `quat`'s first three components.
         */
        constexpr vec3<T> xyz() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        /*!
         * \brief   Returns a copy of this `quat`'s four components.
         *
         * \return  A copy of this `quat`'s four components.
         */
        constexpr vec4<T> xyzw() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        /*!
         * \brief    Sets this `quat`'s first component.
         *
         * \param x  The new value for the first component.
         */
        void set_x(const T& x) noexcept
        {
            this->impl_.data[0] = x;
        }

        /*!
         * \brief    Sets this `quat`'s second component.
         *
         * \param y  The new value for the second component.
         */
        void set_y(const T& y) noexcept
        {
            this->impl_.data[1] = y;
        }

        /*!
         * \brief    Sets this `quat`'s third component.
         *
         * \param z  The new value for the third component.
         */
        void set_z(const T& z) noexcept
        {
            this->impl_.data[2] = z;
        }

        /*!
         * \brief    Sets this `quat`'s fourth component.
         *
         * \param w  The new value for the fourth component.
         */
        void set_w(const T& w) noexcept
        {
            this->impl_.data[3] = w;
        }

        /*!
         * \brief    Sets this `quat`'s first three components.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         * \param z  The new value for the third component.
         */
        void set_xyz(const T& x, const T& y, const T& z) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
        }

        /*!
         * \brief      Sets this `quat`'s first three components.
         *
         * \param xyz  The new values for the first three components.
         */
        void set_xyz(const vec3<T>& xyz) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
        }

        /*!
         * \brief    Sets this `quat`'s four components.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         * \param z  The new value for the third component.
         * \param w  The new value for the fourth component.
         */
        void set_xyzw(const T& x, const T& y, const T& z, const T& w) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
            this->impl_.data[3] = w;
        }

        /*!
         * \brief      Sets this `quat`'s four components.
         *
         * \param xyz  The new values for the first three components.
         * \param w    The new value for the fourth component.
         */
        void set_xyzw(const vec3<T>& xyz, const T& w) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
            this->impl_.data[3] = w;
        }

        /*!
         * \brief       Sets this `quat`'s four components.
         *
         * \param xyzw  The new values for the four components.
         */
        void set_xyzw(const vec4<T>& xyzw) noexcept
        {
            this->impl_.data[0] = xyzw[0];
            this->impl_.data[1] = xyzw[1];
            this->impl_.data[2] = xyzw[2];
            this->impl_.data[3] = xyzw[3];
        }

        /*!
         * \brief   Returns a copy of this `quat`'s first three components.
         *
         * \return  A copy of this `quat`'s first three components.
         */
        constexpr vec3<T> v() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        /*!
         * \brief   Returns a copy of this `quat`'s fourth component.
         *
         * \return  A copy of this `quat`'s fourth component.
         */
        constexpr T s() const noexcept
        {
            return this->impl_.data[3];
        }

        /*!
         * \brief    Sets this `quat`'s first three components.
         *
         * \param x  The new value for the first component.
         * \param y  The new value for the second component.
         * \param z  The new value for the third component.
         */
        void set_v(const T& x, const T& y, const T& z) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
        }

        /*!
         * \brief    Sets this `quat`'s first three components.
         *
         * \param v  The new values for the first three components.
         */
        void set_v(const vec3<T>& v) noexcept
        {
            this->impl_.data[0] = v[0];
            this->impl_.data[1] = v[1];
            this->impl_.data[2] = v[2];
        }

        /*!
         * \brief    Sets this `quat`'s fourth component.
         *
         * \param s  The new value for the fourth component.
         */
        void set_s(const T& s) noexcept
        {
            this->impl_.data[3] = s;
        }

        /*!
         * \brief     Rotates this `quat` by `q`.
         * \details   The operand order might be the opposite of what you expect
         *            from other libraries. This library generally prefers
         *            compound transformations be written from left-to-right
         *            instead of right-to-left.
         *
         * \tparam U  The component type of `q`.
         *
         * \param q   A rotation `quat`.
         *
         * \return    A reference to this `quat`.
         */
        template<typename U>
        quat<T>& operator*=(const quat<U>& q) noexcept
        {
            return (*this) = (*this) * q;
        }
    };

    /*!
     * \brief      Computes a copy of `lhs` rotated by `rhs`.
     * \details    The operand order might be the opposite of what you expect
     *             from other libraries. This library generally prefers compound
     *             transformations be written from left-to-right instead of
     *             right-to-left.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A copy of `lhs` rotated by `rhs`.
     */
    template<typename T, typename U>
    inline constexpr quat<decltype(std::declval<T>() * std::declval<U>())>
    operator*(const quat<T>& lhs, const quat<U>& rhs) noexcept
    {
        return {
            rhs.s()*lhs.v() + lhs.s()*rhs.v()
                + tue::math::cross(rhs.v(), lhs.v()),
            rhs.s()*lhs.s()
                - tue::math::dot(rhs.v(), lhs.v()),
        };
    }

    /*!
     * \brief      Computes a copy of `lhs` rotated by `rhs`.
     * \details    The operand order might be the opposite of what you expect
     *             from other libraries. This library generally prefers compound
     *             transformations be written from left-to-right instead of
     *             right-to-left.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A copy of `lhs` rotated by `rhs`.
     */
    template<typename T, typename U>
    inline constexpr vec3<decltype(std::declval<T>() * std::declval<U>())>
    operator*(const vec3<T>& lhs, const quat<U>& rhs) noexcept
    {
        return (rhs
                * quat<T>(lhs, T(0))
                * quat<U>(-rhs[0], -rhs[1], -rhs[2], rhs[3])
            ).v();
    }

    /*!
     * \brief      Determines whether or not two `quat`'s compare equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if all the corresponding pairs of components compare
     *             equal and `false` otherwise.
     */
    template<typename T, typename U>
    inline constexpr bool
    operator==(const quat<T>& lhs, const quat<U>& rhs) noexcept
    {
        return lhs[0] == rhs[0]
            && lhs[1] == rhs[1]
            && lhs[2] == rhs[2]
            && lhs[3] == rhs[3];
    }

    /*!
     * \brief      Determines whether or not two `quat`'s compare not equal.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam U   The component type of `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if at least one of the corresponding pairs of
     *             components compares not equal and `false` otherwise.
     */
    template<typename T, typename U>
    inline constexpr bool
    operator!=(const quat<T>& lhs, const quat<U>& rhs) noexcept
    {
        return lhs[0] != rhs[0]
            || lhs[1] != rhs[1]
            || lhs[2] != rhs[2]
            || lhs[3] != rhs[3];
    }

    /*!@}*/
    namespace math
    {
        /*!
         * \addtogroup  quat_hpp
         * @{
         */

        /*!
         * \brief     Computes a normalized copy of `q`.
         *
         * \tparam T  The component type of `q`.
         *
         * \param q   A `quat`.
         *
         * \return    A normalized copy of `q`.
         */
        template<typename T>
        inline quat<T> normalize(const quat<T>& q) noexcept
        {
            const auto length2 = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];
            const auto rlength = tue::math::rsqrt(length2);
            return {
                q[0] * rlength,
                q[1] * rlength,
                q[2] * rlength,
                q[3] * rlength,
            };
        }

        /*!
         * \brief     Computes the conjugate of `q`.
         *
         * \tparam T  The component type of `q`.
         *
         * \param q   A `quat`.
         *
         * \return    The conjugate of `q`.
         */
        template<typename T>
        inline constexpr quat<T> conjugate(const quat<T>& q) noexcept
        {
            return { -q[0], -q[1], -q[2], q[3] };
        }

        /*!@}*/
    }
}
