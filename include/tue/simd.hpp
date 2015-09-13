//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstdint>
#include <type_traits>

#include "sized_bool.hpp"

namespace tue
{
    /*!
     * \brief     An `N`-component SIMD vector.
     * \details   `simd` has the same size requirements as `T[N]` and its
     *            alignment equals its size.
     *
     * \tparam T  The component type. Must be a sized boolean type or an
     *            arithmetic type other than `bool`.
     * \tparam N  The component count. Must be 2 or 4.
     */
    template<typename T, int N>
    class simd;

    /*!
     * \brief     A 2-component SIMD vector.
     * \tparam T  The component type.
     */
    template<typename T>
    using simd2 = simd<T, 2>;

    /*!
     * \brief     A 4-component SIMD vector.
     * \tparam T  The component type.
     */
    template<typename T>
    using simd4 = simd<T, 4>;

    /*!
     * \brief  A 2-component SIMD vector with `float` components.
     */
    using float32x2 = simd2<float>;

    /*!
     * \brief  A 4-component SIMD vector with `float` components.
     */
    using float32x4 = simd4<float>;

    /*!
     * \brief  A 2-component SIMD vector with `double` components.
     */
    using float64x2 = simd2<double>;

    /*!
     * \brief  A 4-component SIMD vector with `double` components.
     */
    using float64x4 = simd4<double>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int32_t` components.
     */
    using int32x2 = simd2<std::int32_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int32_t` components.
     */
    using int32x4 = simd4<std::int32_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int64_t` components.
     */
    using int64x2 = simd2<std::int64_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int64_t` components.
     */
    using int64x4 = simd4<std::int64_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x2 = simd2<std::uint32_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x4 = simd4<std::uint32_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint64_t` components.
     */
    using uint64x2 = simd2<std::uint64_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint64_t` components.
     */
    using uint64x4 = simd4<std::uint64_t>;

    /*!
     * \brief  A 2-component SIMD vector with `bool32` components.
     */
    using bool32x2 = simd2<bool32>;

    /*!
     * \brief  A 4-component SIMD vector with `bool32` components.
     */
    using bool32x4 = simd4<bool32>;

    /*!
     * \brief  A 2-component SIMD vector with `bool64` components.
     */
    using bool64x2 = simd2<bool64>;

    /*!
     * \brief  A 4-component SIMD vector with `bool64` components.
     */
    using bool64x4 = simd4<bool64>;

    /**/
    template<typename T, int N>
    class alignas(sizeof(T) * N) simd
    {
        struct
        {
            std::enable_if_t<
                (is_sized_bool<T>::value
                    || (std::is_arithmetic<T>::value
                        && !std::is_same<T, bool>::value))
                && (N == 2 || N == 4),
                T>
                data[N];
        }
        impl_;

    public:
        /*!
         * \brief  This `simd` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `simd` type's component count.
         */
        static constexpr int component_count = N;

        /*!
         * \brief  Default constructs each component.
         */
        simd() noexcept = default;

        /*!
         * \brief    Constructs each component with the same value.
         * \param x  The value to construct each component with.
         */
        inline explicit simd(T x) noexcept;

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         * \details  This overload is only available when `N` equals `2`.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         */
        inline simd(std::enable_if_t<N == 2, T> x, T y) noexcept;

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
        inline simd(std::enable_if_t<N == 4, T> x, T y, T z, T w) noexcept;

        /*!
         * \brief     Explicitly casts another `simd` to a new component type.
         * \tparam U  The component type of `s`.
         * \param s   The `simd` to cast from.
         */
        template<typename U>
        inline explicit simd(const simd<U, N>& s) noexcept;

        /*!
         * \brief   Returns an `simd` with each component set to `0`.
         * \return  An `simd` with each component set to `0`.
         */
        inline static simd<T, N> zero() noexcept;

        /*!
         * \brief   Returns a pointer to this `simd`'s underlying component
         *          array.
         *
         * \return  A pointer to this `simd`'s underlying component array.
         */
        inline const T* data() const noexcept;

        /*!
         * \brief   Returns a pointer to this `simd`'s underlying component
         *          array.
         *
         * \return  A pointer to this `simd`'s underlying component array.
         */
        inline T* data() noexcept;

        /*!
         * \brief   Pre-increments each component of this `simd`.
         * \return  A reference to this `simd`.
         */
        inline simd<T, N>& operator++() noexcept;

        /*!
         * \brief   Post-increments each component of this `simd`.
         * \return  A copy of this `simd` before being incremented.
         */
        inline simd<T, N> operator++(int) noexcept;

        /*!
         * \brief   Pre-decrements each component of this `simd`.
         * \return  A reference to this `simd`.
         */
        inline simd<T, N>& operator--() noexcept;

        /*!
         * \brief   Post-decrements each component of this `simd`.
         * \return  A copy of this `simd` before being decremented.
         */
        inline simd<T, N> operator--(int) noexcept;

        /*!
         * \brief     Adds each component of `s` to the corresponding component
         *            of this `simd`.
         * \param s   The values to add to each component of this `simd`.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator+=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Subtracts each component of `s` from the corresponding
         *            component of this `simd`.
         * \param s   The values to subtract from each component of this `simd`.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator-=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Multiplies each component of this `simd` by the
         *            corresponding component of `s`.
         * \param s   The values to multiply each component of this `simd` by.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator*=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Divides each component of this `simd` by the corresponding
         *            component of `s`.
         * \param s   The values to divide each component of this `simd` by.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator/=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Modulos each component of this `simd` by the corresponding
         *            component of `s`.
         * \param s   The values to modulo each component of this `simd` by.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator%=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Bitwise ANDs each component of this `simd` with the
         *            corresponding component from `s`.
         * \param s   The values to bitwise AND each component of this `simd`
         *            with.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator&=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Bitwise ORs each component of this `simd` with the
         *            corresponding component from `s`.
         * \param s   The values to bitwise OR each component of this `simd`
         *            with.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator|=(const simd<T, N>& s) noexcept;

        /*!
         * \brief     Bitwise XORs each component of this `simd` with the
         *            corresponding component from `s`.
         * \param s   The values to bitwise XOR each component of this `simd`
         *            with.
         * \return    A reference to this `simd`.
         */
        inline simd<T, N>& operator^=(const simd<T, N>& s) noexcept;
    };
}

#include "detail_/simd2.hpp"
#include "detail_/simdN.hpp"

namespace tue
{
    /*!
     * \brief     Computes the unary plus of each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    The unary plus of each component of `s`.
     */
    template<typename T, int N>
    inline simd<T, N> operator+(const simd<T, N>& s) noexcept
    {
        return tue::detail_::unary_plus_operator_s(s);
    }

    /*!
     * \brief     Computes the unary minus of each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    The unary minus of each component of `s`.
     */
    template<typename T, int N>
    inline simd<T, N> operator-(const simd<T, N>& s) noexcept
    {
        return tue::detail_::unary_minus_operator_s(s);
    }

    /*!
     * \brief     Computes the bitwise NOT of each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    The bitwise NOT of each component of `s`.
     */
    template<typename T, int N>
    inline simd<T, N> operator~(const simd<T, N>& s) noexcept
    {
        return tue::detail_::bitwise_not_operator_s(s);
    }

    /*!
     * \brief      Computes the sums of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The sums of each component of `lhs` and each corresponding
     *             component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator+(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::addition_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the differences between each component of `lhs` and
     *             each corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The differences between each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator-(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::subtraction_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the products of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The products of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator*(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::multiplication_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The quotients of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator/(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::division_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The modulos of each component of `lhs` over each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator%(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::modulo_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise AND of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator&(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise OR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator|(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise XOR of each component of `lhs` and each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator^(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts left of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts left of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator<<(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by each corresponding component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts right of each component of `lhs` by each
     *             corresponding component of `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator>>(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Determines whether or not two `simd`'s compare equal.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if all the corresponding pairs of components compare
     *             equal and `false` otherwise.
     */
    template<typename T, int N>
    inline bool operator==(
        const simd<T, N>& lhs, const simd<U, N>& rhs) noexcept
    {
        return tue::detail_::equality_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Determines whether or not two `simd`'s compare not equal.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     `true` if all the corresponding pairs of components compare
     *            not  equal and `false` otherwise.
     */
    template<typename T, int N>
    inline bool operator!=(
        const simd<T, N>& lhs, const simd<U, N>& rhs) noexcept
    {
        return tue::detail_::inequality_operator_ss(lhs, rhs);
    }

    /**/
    namespace math
    {
        /*!
         * \brief     Computes `tue::math::sin()` for each component of `s`.
         * \details   The results may not match `tue::math::sin()` exactly, but
         *            will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::sin()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        sin(const simd<T, N>& s) noexcept
        {
            return tue::detail_::sin_s(s);
        }

        /*!
         * \brief     Computes `tue::math::cos()` for each component of `s`.
         * \details   The results may not match `tue::math::cos()` exactly, but
         *            will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::cos()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        cos(const simd<T, N>& s) noexcept
        {
            return tue::detail_::cos_s(s);
        }

        /*!
         * \brief          Computes `tue::math::sincos()` for each component of
         *                 `s`.
         * \details        The results may not match `tue::math::sincos()`
         *                 exactly, but will at least approximate the same
         *                 values.
         *
         * \tparam T       The component type of `s`.
         * \tparam N       The component count of `s`.
         *
         * \param s        An `simd`.
         * \param sin_out  A reference to the `simd` to store the `sin()` results
         *                 in.
         * \param cos_out  A reference to the `simd` to store the `cos()` results
         *                 in.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value>
        sincos(
            const simd<T, N>& s,
            simd<T, N>& sin_out,
            simd<T, N>& cos_out) noexcept
        {
            tue::detail_::sincos_s(s, sin_out, cos_out);
        }

        /*!
         * \brief     Computes `tue::math::exp()` for each component of `s`.
         * \details   The results may not match `tue::math::exp()` exactly, but
         *            will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::exp()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        exp(const simd<T, N>& s) noexcept
        {
            return tue::detail_::exp_s(s);
        }

        /*!
         * \brief     Computes `tue::math::log()` for each component of `s`.
         * \details   The results may not match `tue::math::log()` exactly, but
         *            will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::log()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        log(const simd<T, N>& s) noexcept
        {
            return tue::detail_::log_s(s);
        }

        /*!
         * \brief     Computes `tue::math::abs()` for each component of `s`.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::abs()` for each component of `s`.
         */
        template<typename T, int N>
        inline simd<T, N>
        abs(const simd<T, N>& s) noexcept
        {
            return tue::detail_::simd_s(s);
        }

        /*!
         * \brief            Computes `tue::math::pow()` for each component of
         *                   `bases` and each corresponding component of
         *                   `exponents`.
         * \details          The results may not match `tue::math::pow()`
         *                   exactly, but will at least approximate the same
         *                   values.
         *
         * \tparam T         The component type of both `bases` and `exponents`.
         * \tparam N         The component count of both `bases` and
         *                   `exponents`.
         *
         * \param bases      The bases.
         * \param exponents  The exponents.
         *
         * \return           `tue::math::pow()` for each component of `bases`
         *                   and each corresponding component of `exponents`.
         */
        template<typename T, typename U, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        pow(const simd<T, N>& bases, const simd<T, N>& exponents) noexcept
        {
            return tue::detail_::pow_ss(bases, exponents);
        }

        /*!
         * \brief     Computes `tue::math::recip()` for each component of `s`.
         * \details   The results may not match `tue::math::recip()` exactly,
         *            but will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::recip()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        recip(const simd<T, N>& s) noexcept
        {
            return tue::detail_::recip_s(s);
        }

        /*!
         * \brief     Computes `tue::math::sqrt()` for each component of `s`.
         * \details   The results may not match `tue::math::sqrt()` exactly, but
         *            will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::sqrt()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        sqrt(const simd<T, N>& s) noexcept
        {
            return tue::detail_::sqrt_s(s);
        }

        /*!
         * \brief     Computes `tue::math::rsqrt()` for each component of `s`.
         * \details   The results may not match `tue::math::rsqrt()` exactly,
         *            but will at least approximate the same values.
         *
         * \tparam T  The component type of `s`.
         * \tparam N  The component count of `s`.
         *
         * \param s   An `simd`.
         *
         * \return    `tue::math::rsqrt()` for each component of `s`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_floating_point<T>::value, simd<T, N>>
        rsqrt(const simd<T, N>& s) noexcept
        {
            return tue::detail_::rsqrt_s(s);
        }

        /*!
         * \brief     Computes `tue::math::min()` for each corresponding pair of
         *            components of `s1` and `s2`.
         *
         * \tparam T  The component type of both `s1` and `s2`.
         * \tparam N  The component count of both `s1` and `s2`.
         *
         * \param s1  An `simd`.
         * \param s2  Another `simd`.
         *
         * \return    `tue::math::min()` for each corresponding pair of
         *            components of `s1` and `s2`.
         */
        template<typename T, int N>
        inline simd<T, N>
        min(const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            return tue::detail_::min_ss(s1, s2);
        }

        /*!
         * \brief     Computes `tue::math::max()` for each corresponding pair of
         *            components of `s1` and `s2`.
         *
         * \tparam T  The component type of both `s1` and `s2`.
         * \tparam N  The component count of both `s1` and `s2`.
         *
         * \param s1  An `simd`.
         * \param s2  Another `simd`.
         *
         * \return    `tue::math::max()` for each corresponding pair of
         *            components of `s1` and `s2`.
         */
        template<typename T, int N>
        inline simd<T, N>
        max(const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            return tue::detail_::max_ss(s1, s2);
        }

        /*!
         * \brief             Computes `tue::math::select()` for each
         *                    corresponding pair of components from `conditions`
         *                    and `values`.
         *
         * \tparam T          The component type of `conditions`.
         * \tparam U          The component type of `values`.
         * \tparam N          The component count of both `conditions` and
         *                    `values`.
         *
         * \param conditions  An `simd`.
         * \param values      Another `simd`.
         *
         * \return            `tue::math::select()` for each corresponding
         *                    pair of components from `conditions` and `values`.
         */
        template<typename T, typename U, int N>
        inline std::enable_if_t<
            is_sized_bool<T>::value && sizeof(T) == sizeof(U), simd<U, N>>
        select(
            const simd<T, N>& conditions,
            const simd<U, N>& values) noexcept
        {
            return tue::detail_::select_ss(conditions, values);
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
         * \param conditions  An `simd`.
         * \param values      Another `simd`.
         * \param otherwise   Another `simd`.
         *
         * \return            `tue::math::select()` for each corresponding
         *                    triple of components from `conditions`, `values`,
         *                    and `otherwise`.
         */
        template<typename T, typename U, int N>
        inline std::enable_if_t<
            is_sized_bool<T>::value && sizeof(T) == sizeof(U), simd<U, N>>
        select(
            const simd<T, N>& conditions,
            const simd<U, N>& values,
            const simd<U, N>& otherwise) noexcept
        {
            return tue::detail_::select_sss(conditions, values, otherwise);
        }

        /*!
         * \brief      Computes `tue::math::less()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        less(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::less_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::less_equal()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less_equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        less_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::less_equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        greater(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::greater_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater_equal()` for each
         *             corresponding pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater_equal()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        greater_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::greater_equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::equal()` for each corresponding pair
         *             of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::not_equal()` for each corresponding
         *             pair of components of `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::not_equal()` for each corresponding pair of
         *             components of `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<T, N>
        not_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::not_equal_ss(lhs, rhs);
        }
    }
}
