//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

static_assert(sizeof(float) == 4, "float is not 32-bits wide");
static_assert(sizeof(double) == 8, "double is not 64-bits wide");

#include <cstdint>
#include <type_traits>

#include "sized_bool.hpp"

namespace tue
{
    /*!
     * \defgroup  simd_hpp <tue/simd.hpp>
     *
     * \brief     The `simd` class template and its associated utility structs
     *            and functions.
     * @{
     */

    /*!
     * \brief     Checks if a type can be used as the component type of an SIMD
     *            vector.
     * \details   Extends `std::integral_constant<bool, true>` for the following
     *            types and `std::integral_constant<bool, false>` otherwise:
     *            - `float`
     *            - `double`
     *            - `std::int8_t`
     *            - `std::int16_t`
     *            - `std::int32_t`
     *            - `std::int64_t`
     *            - `std::uint8_t`
     *            - `std::uint16_t`
     *            - `std::uint32_t`
     *            - `std::uint64_t`
     *            - `tue::bool8`
     *            - `tue::bool16`
     *            - `tue::bool32`
     *            - `tue::bool64`
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_simd_component;

    /*!
     * \brief     Checks if a type is an arithmetic type that can be used as the
     *            component type of an SIMD vector.
     * \details   Extends `std::integral_constant<bool, true>` for the following
     *            types and `std::integral_constant<bool, false>` otherwise:
     *            - `float`
     *            - `double`
     *            - `std::int8_t`
     *            - `std::int16_t`
     *            - `std::int32_t`
     *            - `std::int64_t`
     *            - `std::uint8_t`
     *            - `std::uint16_t`
     *            - `std::uint32_t`
     *            - `std::uint64_t`
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_arithmetic_simd_component;

    /*!
     * \brief     Checks if a type is a floating-point type that can be used as
     *            the component type of an SIMD vector.
     * \details   Extends `std::integral_constant<bool, true>` for the following
     *            types and `std::integral_constant<bool, false>` otherwise:
     *            - `float`
     *            - `double`
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_floating_point_simd_component;

    /*!
     * \brief     Checks if a type is an integral type that can be used as the
     *            component type of an SIMD vector.
     * \details   Extends `std::integral_constant<bool, true>` for the following
     *            types and `std::integral_constant<bool, false>` otherwise:
     *            - `std::int8_t`
     *            - `std::int16_t`
     *            - `std::int32_t`
     *            - `std::int64_t`
     *            - `std::uint8_t`
     *            - `std::uint16_t`
     *            - `std::uint32_t`
     *            - `std::uint64_t`
     *
     * \tparam T  The type to check.
     */
    template<typename T>
    struct is_integral_simd_component;

    /*!@}*/
}

#include "detail_/is_simd_component.hpp"
#include "detail_/is_arithmetic_simd_component.hpp"
#include "detail_/is_floating_point_simd_component.hpp"
#include "detail_/is_integral_simd_component.hpp"

namespace tue
{
    /*!
     * \addtogroup  simd_hpp
     * @{
     */

    /*!
     * \brief     An `N`-component SIMD vector.
     *
     * \details   `simd` has the same size requirements as `T[N]` and its
     *            alignment equals its size. It's accelerated by compiler and
     *            architecture-specific SIMD intrinsics where possible, but
     *            compatibility fallbacks are always available otherwise.
     *
     *            `simd` types may contain platform-specific implicit
     *            constructors and conversion operators for converting to and
     *            from the underlying SIMD intrinsic type. The current mapping
     *            is as follows:
     *
     *            <b>SSE</b>
     *            `simd` Type | SIMD Intrinsic
     *            ----------- | --------------
     *            `bool32x4`  | `__m128`
     *            `float32x4` | `__m128`
     *
     *            <b>SSE2</b>
     *            `simd` Type | SIMD Intrinsic
     *            ----------- | --------------
     *            `bool8x16`  | `__m128i`
     *            `bool16x8`  | `__m128i`
     *            `bool32x4`  | `__m128i` and `__m128`
     *            `bool64x2`  | `__m128i` and `__m128d`
     *            `int8x16`   | `__m128i`
     *            `int16x8`   | `__m128i`
     *            `int32x4`   | `__m128i`
     *            `int64x2`   | `__m128i`
     *            `uint8x16`  | `__m128i`
     *            `uint16x8`  | `__m128i`
     *            `uint32x4`  | `__m128i`
     *            `uint64x2`  | `__m128i`
     *            `float32x4` | `__m128`
     *            `float64x2` | `__m128d`
     *
     * \tparam T  The component type. `is_simd_component<T>::value` must be
     *            `true`.
     * \tparam N  The component count. Must be `2`, `4`, `8`, `16`, `32`, or
     *            `64`.
     */
    template<typename T, int N>
    class simd;

    /*!
     * \brief     A 2-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd2 = simd<T, 2>;

    /*!
     * \brief     A 4-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd4 = simd<T, 4>;

    /*!
     * \brief     An 8-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd8 = simd<T, 8>;

    /*!
     * \brief     A 16-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd16 = simd<T, 16>;

    /*!
     * \brief     A 32-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd32 = simd<T, 32>;

    /*!
     * \brief     A 64-component SIMD vector.
     *
     * \tparam T  The component type.
     */
    template<typename T>
    using simd64 = simd<T, 64>;

    /*!
     * \brief  A 2-component SIMD vector with `float` components.
     */
    using float32x2 = simd2<float>;

    /*!
     * \brief  A 4-component SIMD vector with `float` components.
     */
    using float32x4 = simd4<float>;

    /*!
     * \brief  An 8-component SIMD vector with `float` components.
     */
    using float32x8 = simd8<float>;

    /*!
     * \brief  A 16-component SIMD vector with `float` components.
     */
    using float32x16 = simd16<float>;

    /*!
     * \brief  A 2-component SIMD vector with `double` components.
     */
    using float64x2 = simd2<double>;

    /*!
     * \brief  A 4-component SIMD vector with `double` components.
     */
    using float64x4 = simd4<double>;

    /*!
     * \brief  An 8-component SIMD vector with `double` components.
     */
    using float64x8 = simd8<double>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int8_t` components.
     */
    using int8x2 = simd2<std::int8_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int8_t` components.
     */
    using int8x4 = simd4<std::int8_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::int8_t` components.
     */
    using int8x8 = simd8<std::int8_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::int8_t` components.
     */
    using int8x16 = simd16<std::int8_t>;

    /*!
     * \brief  A 32-component SIMD vector with `std::int8_t` components.
     */
    using int8x32 = simd32<std::int8_t>;

    /*!
     * \brief  A 64-component SIMD vector with `std::int8_t` components.
     */
    using int8x64 = simd64<std::int8_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int16_t` components.
     */
    using int16x2 = simd2<std::int16_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int16_t` components.
     */
    using int16x4 = simd4<std::int16_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::int16_t` components.
     */
    using int16x8 = simd8<std::int16_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::int16_t` components.
     */
    using int16x16 = simd16<std::int16_t>;

    /*!
     * \brief  A 32-component SIMD vector with `std::int16_t` components.
     */
    using int16x32 = simd32<std::int16_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int32_t` components.
     */
    using int32x2 = simd2<std::int32_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int32_t` components.
     */
    using int32x4 = simd4<std::int32_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::int32_t` components.
     */
    using int32x8 = simd8<std::int32_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::int32_t` components.
     */
    using int32x16 = simd16<std::int32_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::int64_t` components.
     */
    using int64x2 = simd2<std::int64_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::int64_t` components.
     */
    using int64x4 = simd4<std::int64_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::int64_t` components.
     */
    using int64x8 = simd8<std::int64_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x2 = simd2<std::uint8_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x4 = simd4<std::uint8_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x8 = simd8<std::uint8_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x16 = simd16<std::uint8_t>;

    /*!
     * \brief  A 32-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x32 = simd32<std::uint8_t>;

    /*!
     * \brief  A 64-component SIMD vector with `std::uint8_t` components.
     */
    using uint8x64 = simd64<std::uint8_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint16_t` components.
     */
    using uint16x2 = simd2<std::uint16_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint16_t` components.
     */
    using uint16x4 = simd4<std::uint16_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::uint16_t` components.
     */
    using uint16x8 = simd8<std::uint16_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::uint16_t` components.
     */
    using uint16x16 = simd16<std::uint16_t>;

    /*!
     * \brief  A 32-component SIMD vector with `std::uint16_t` components.
     */
    using uint16x32 = simd32<std::uint16_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x2 = simd2<std::uint32_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x4 = simd4<std::uint32_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x8 = simd8<std::uint32_t>;

    /*!
     * \brief  A 16-component SIMD vector with `std::uint32_t` components.
     */
    using uint32x16 = simd16<std::uint32_t>;

    /*!
     * \brief  A 2-component SIMD vector with `std::uint64_t` components.
     */
    using uint64x2 = simd2<std::uint64_t>;

    /*!
     * \brief  A 4-component SIMD vector with `std::uint64_t` components.
     */
    using uint64x4 = simd4<std::uint64_t>;

    /*!
     * \brief  An 8-component SIMD vector with `std::uint64_t` components.
     */
    using uint64x8 = simd8<std::uint64_t>;

    /*!
     * \brief  A 2-component SIMD vector with `bool8` components.
     */
    using bool8x2 = simd2<bool8>;

    /*!
     * \brief  A 4-component SIMD vector with `bool8` components.
     */
    using bool8x4 = simd4<bool8>;

    /*!
     * \brief  An 8-component SIMD vector with `bool8` components.
     */
    using bool8x8 = simd8<bool8>;

    /*!
     * \brief  A 16-component SIMD vector with `bool8` components.
     */
    using bool8x16 = simd16<bool8>;

    /*!
     * \brief  A 32-component SIMD vector with `bool8` components.
     */
    using bool8x32 = simd32<bool8>;

    /*!
     * \brief  A 64-component SIMD vector with `bool8` components.
     */
    using bool8x64 = simd64<bool8>;

    /*!
     * \brief  A 2-component SIMD vector with `bool16` components.
     */
    using bool16x2 = simd2<bool16>;

    /*!
     * \brief  A 4-component SIMD vector with `bool16` components.
     */
    using bool16x4 = simd4<bool16>;

    /*!
     * \brief  An 8-component SIMD vector with `bool16` components.
     */
    using bool16x8 = simd8<bool16>;

    /*!
     * \brief  A 16-component SIMD vector with `bool16` components.
     */
    using bool16x16 = simd16<bool16>;

    /*!
     * \brief  A 32-component SIMD vector with `bool16` components.
     */
    using bool16x32 = simd32<bool16>;

    /*!
     * \brief  A 2-component SIMD vector with `bool32` components.
     */
    using bool32x2 = simd2<bool32>;

    /*!
     * \brief  A 4-component SIMD vector with `bool32` components.
     */
    using bool32x4 = simd4<bool32>;

    /*!
     * \brief  An 8-component SIMD vector with `bool32` components.
     */
    using bool32x8 = simd8<bool32>;

    /*!
     * \brief  A 16-component SIMD vector with `bool32` components.
     */
    using bool32x16 = simd16<bool32>;

    /*!
     * \brief  A 2-component SIMD vector with `bool64` components.
     */
    using bool64x2 = simd2<bool64>;

    /*!
     * \brief  A 4-component SIMD vector with `bool64` components.
     */
    using bool64x4 = simd4<bool64>;

    /*!
     * \brief  An 8-component SIMD vector with `bool64` components.
     */
    using bool64x8 = simd8<bool64>;

    /*!@}*/
    namespace detail_
    {
        template<typename T, int N>
        inline constexpr std::size_t alignof_simd() noexcept
        {
#ifdef __GNUC__
            return (sizeof(T) * N) < 128 ? (sizeof(T) * N) : 128;
#else
            return (sizeof(T) * N);
#endif
        }
    }
}

#include "detail_/simd2.hpp"

namespace tue
{
    /*!
     * \addtogroup  simd_hpp
     * @{
     */
    template<typename T, int N>
    class alignas(tue::detail_::alignof_simd<T, N>()) simd
    {
        std::enable_if_t<
            is_simd_component<T>::value
                && (N == 4 || N == 8 || N == 16 || N == 32 || N == 64),
            simd<T, N/2>[2]>
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
         * \brief  Whether or not this type is accelerated by SIMD intrinsics.
         */
        static constexpr bool is_accelerated = false;

        /*!
         * \name Constructors, Conversions, and Factory Functions
         * @{
         */
        /*!
         * \brief  Default constructs each component.
         */
        simd() noexcept = default;

        /*!
         * \brief     Constructs each component with the same value.
         *
         * \param x   The value to construct each component with.
         */
        explicit simd(T x) noexcept
        {
            const auto y = simd<T, N/2>(x);
            this->impl_[0] = y;
            this->impl_[1] = y;
        }

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         * \details  This overload is only available when `N` equals `2`.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         */
        template<int M = N, typename = std::enable_if_t<M == 2>>
        simd(T x, T y) noexcept
        {
            this->impl_[0] = simd<T, 1>(x);
            this->impl_[1] = simd<T, 1>(y);
        }

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
        template<int M = N, typename = std::enable_if_t<M == 4>>
        simd(T x, T y, T z, T w) noexcept
        {
            this->impl_[0] = simd<T, 2>(x, y);
            this->impl_[1] = simd<T, 2>(z, w);
        }

        /*!
         * \brief     Constructs each component with the value of the
         *            corresponding argument.
         * \details   This overload is only available when `N` equals `8`.
         *
         * \param s0  The value to construct the first component with.
         * \param s1  The value to construct the second component with.
         * \param s2  The value to construct the third component with.
         * \param s3  The value to construct the fourth component with.
         * \param s4  The value to construct the fifth component with.
         * \param s5  The value to construct the sixth component with.
         * \param s6  The value to construct the seventh component with.
         * \param s7  The value to construct the eighth component with.
         */
        template<int M = N, typename = std::enable_if_t<M == 8>>
        simd(T s0, T s1, T s2, T s3, T s4, T s5, T s6, T s7) noexcept
        {
            this->impl_[0] = simd<T, 4>(s0, s1, s2, s3);
            this->impl_[1] = simd<T, 4>(s4, s5, s6, s7);
        }

        /*!
         * \brief      Constructs each component with the value of the
         *             corresponding argument.
         * \details    This overload is only available when `N` equals `16`.
         *
         * \param s0   The value to construct the first component with.
         * \param s1   The value to construct the second component with.
         * \param s2   The value to construct the third component with.
         * \param s3   The value to construct the fourth component with.
         * \param s4   The value to construct the fifth component with.
         * \param s5   The value to construct the sixth component with.
         * \param s6   The value to construct the seventh component with.
         * \param s7   The value to construct the eighth component with.
         * \param s8   The value to construct the ninth component with.
         * \param s9   The value to construct the tenth component with.
         * \param s10  The value to construct the eleventh component with.
         * \param s11  The value to construct the twelfth component with.
         * \param s12  The value to construct the thirteenth component with.
         * \param s13  The value to construct the fourteenth component with.
         * \param s14  The value to construct the fifteenth component with.
         * \param s15  The value to construct the sixteenth component with.
         */
        template<int M = N, typename = std::enable_if_t<M == 16>>
        simd(
            T s0, T s1, T  s2, T  s3, T  s4, T  s5, T  s6, T  s7,
            T s8, T s9, T s10, T s11, T s12, T s13, T s14, T s15) noexcept
        {
            this->impl_[0] = simd<T, 8>(s0, s1,  s2,  s3,  s4,  s5,  s6,  s7);
            this->impl_[1] = simd<T, 8>(s8, s9, s10, s11, s12, s13, s14, s15);
        }

        /*!
         * \brief     Explicitly casts another `simd` to a new component type.
         *
         * \tparam U  The component type of `s`.
         *
         * \param s   The `simd` to cast from.
         */
        template<typename U>
        explicit simd(const simd<U, N>& s) noexcept
        {
            const auto simpl = reinterpret_cast<const simd<U, N/2>*>(&s);
            this->impl_[0] = simd<T, N/2>(simpl[0]);
            this->impl_[1] = simd<T, N/2>(simpl[1]);
        }

        /*!
         * \brief   Returns an `simd` with each component set to `0`.
         *
         * \return  An `simd` with each component set to `0`.
         */
        static simd<T, N> zero() noexcept
        {
            simd<T, N> s;
            s.impl_[0] = simd<T, N/2>::zero();
            s.impl_[1] = simd<T, N/2>::zero();
            return s;
        }

        /*!
         * \brief       Loads the given aligned component array into a new
         *              `simd`.
         * \details     The source array must have the same alignment as this
         *              `simd` type. If the source array is null, unaligned, or
         *              doesn't contain at least `N` components, behavior is
         *              undefined.
         *
         * \param data  The source component array.
         *
         * \return      The new `simd`.
         */
        static simd<T, N> load(const T* data) noexcept
        {
            simd<T, N> s;
            s.impl_[0] = simd<T, N/2>::load(data);
            s.impl_[1] = simd<T, N/2>::load(data + N/2);
            return s;
        }

        /*!
         * \brief       Loads the given unaligned component array into a new
         *              `simd`.
         * \details     If the source array is null or doesn't contain at least
         *              `N` components, behavior is undefined.
         *
         * \param data  The source component array.
         *
         * \return      The new `simd`.
         */
        static simd<T, N> loadu(const T* data) noexcept
        {
            simd<T, N> s;
            s.impl_[0] = simd<T, N/2>::loadu(data);
            s.impl_[1] = simd<T, N/2>::loadu(data + N/2);
            return s;
        }

        /*!@}*/
        /*!
         * \brief       Store's this `simd`'s underlying component array in
         *              the given aligned component array.
         * \details     The destination array must have the same alignment as
         *              this `simd` type. If the destination array is null,
         *              unaligned, or doesn't contain room for all `N`
         *              components, behavior is undefined.
         *
         * \param data  The destination component array.
         */
        void store(T* data) const noexcept
        {
            this->impl_[0].store(data);
            this->impl_[1].store(data + N/2);
        }

        /*!
         * \brief       Store's this `simd`'s underlying component array in
         *              the given unaligned component array.
         * \details     If the destination array is null or doesn't contain room
         *              for all `N` components, behavior is undefined.
         *
         * \param data  The destination component array.
         */
        void storeu(T* data) const noexcept
        {
            this->impl_[0].storeu(data);
            this->impl_[1].storeu(data + N/2);
        }

        /*!
         * \brief   Returns a pointer to this `simd`'s underlying component
         *          array.
         *
         * \return  A pointer to this `simd`'s underlying component array.
         */
        const T* data() const noexcept
        {
            return this->impl_[0].data();
        }

        /*!
         * \brief   Returns a pointer to this `simd`'s underlying component
         *          array.
         *
         * \return  A pointer to this `simd`'s underlying component array.
         */
        T* data() noexcept
        {
            return this->impl_[0].data();
        }
    };

    /*!@}*/
}

#include "detail_/simdN.hpp"
#include "detail_/simd_support.hpp"
#include "detail_/simd_specializations.hpp"

namespace tue
{
    /*!
     * \addtogroup  simd_hpp
     * @{
     */

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
    inline std::enable_if_t<std::is_signed<T>::value, simd<T, N>>
    operator+(const simd<T, N>& s) noexcept
    {
        return tue::detail_::unary_plus_operator_s(s);
    }

    /*!
     * \brief     Pre-increments each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    A reference to `s`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator++(simd<T, N>& s) noexcept
    {
        return tue::detail_::pre_increment_operator_s(s);
    }

    /*!
     * \brief     Post-increments each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    A copy of `s` before being incremented.
     */
    template<typename T, int N>
    inline simd<T, N> operator++(simd<T, N>& s, int) noexcept
    {
        return tue::detail_::post_increment_operator_s(s);
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
    inline std::enable_if_t<std::is_signed<T>::value, simd<T, N>>
    operator-(const simd<T, N>& s) noexcept
    {
        return tue::detail_::unary_minus_operator_s(s);
    }

    /*!
     * \brief     Pre-decrements each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    A reference to `s`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator--(simd<T, N>& s) noexcept
    {
        return tue::detail_::pre_decrement_operator_s(s);
    }

    /*!
     * \brief     Post-decrements each component of `s`.
     *
     * \tparam T  The component type of `s`.
     * \tparam N  The component count of `s`.
     *
     * \param s   An `simd`.
     *
     * \return    A copy of `s` before being decremented.
     */
    template<typename T, int N>
    inline simd<T, N> operator--(simd<T, N>& s, int) noexcept
    {
        return tue::detail_::post_decrement_operator_s(s);
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
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts left of each component of `lhs` by `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator<<(
        const simd<T, N>& lhs, int rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_operator_si(lhs, rhs);
    }

    /*!
     * \brief      Computes the bitwise shifts right of each component of `lhs`
     *             by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     The bitwise shifts right of each component of `lhs` by `rhs`.
     */
    template<typename T, int N>
    inline simd<T, N> operator>>(
        const simd<T, N>& lhs, int rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_operator_si(lhs, rhs);
    }

    /*!
     * \brief      Adds each component of `rhs` to each corresponding component
     *             of `lhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator+=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::addition_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Subtracts each component of `rhs` from each corresponding
     *             component of `lhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator-=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::subtraction_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Multiplies each component of `lhs` by each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator*=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::multiplication_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Divides each component of `lhs` by each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator/=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::division_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Modulos each component of `lhs` by each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator%=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::modulo_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Bitwise ANDs each component of `lhs` with each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator&=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_and_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Bitwise ORs each component of `lhs` with each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator|=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_or_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Bitwise XORs each component of `lhs` with each corresponding
     *             component of `rhs`.
     *
     * \tparam T   The component type of both `lhs` and `rhs`.
     * \tparam N   The component count of both `lhs` and `rhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator^=(
        simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::bitwise_xor_assignment_operator_ss(lhs, rhs);
    }

    /*!
     * \brief      Bitwise shifts left each component of `lhs` by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator<<=(
        simd<T, N>& lhs, int rhs) noexcept
    {
        return tue::detail_::bitwise_shift_left_assignment_operator_si(
            lhs, rhs);
    }

    /*!
     * \brief      Bitwise shifts right each component of `lhs` by `rhs`.
     *
     * \tparam T   The component type of `lhs`.
     * \tparam N   The component count of `lhs`.
     *
     * \param lhs  The left-hand side operand.
     * \param rhs  The right-hand side operand.
     *
     * \return     A reference to `lhs`.
     */
    template<typename T, int N>
    inline simd<T, N>& operator>>=(
        simd<T, N>& lhs, int rhs) noexcept
    {
        return tue::detail_::bitwise_shift_right_assignment_operator_si(
            lhs, rhs);
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
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
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
     * \return     `true` if at least one of the corresponding pairs of
     *             components compares not equal and `false` otherwise.
     */
    template<typename T, int N>
    inline bool operator!=(
        const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
    {
        return tue::detail_::inequality_operator_ss(lhs, rhs);
    }

    /*!@}*/
    namespace math
    {
        /*!
         * \addtogroup  simd_hpp
         * @{
         */

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
         * \param sin_out  A reference to the `simd` to store the `sin()`
         *                 results in.
         * \param cos_out  A reference to the `simd` to store the `cos()`
         *                 results in.
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
        inline std::enable_if_t<std::is_arithmetic<T>::value, simd<T, N>>
        abs(const simd<T, N>& s) noexcept
        {
            return tue::detail_::abs_s(s);
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
        template<typename T, int N>
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
         *            components from `s1` and `s2`.
         *
         * \tparam T  The component type of both `s1` and `s2`.
         * \tparam N  The component count of both `s1` and `s2`.
         *
         * \param s1  An `simd`.
         * \param s2  Another `simd`.
         *
         * \return    `tue::math::min()` for each corresponding pair of
         *            components from `s1` and `s2`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_arithmetic<T>::value, simd<T, N>>
        min(const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            return tue::detail_::min_ss(s1, s2);
        }

        /*!
         * \brief     Computes `tue::math::max()` for each corresponding pair of
         *            components from `s1` and `s2`.
         *
         * \tparam T  The component type of both `s1` and `s2`.
         * \tparam N  The component count of both `s1` and `s2`.
         *
         * \param s1  An `simd`.
         * \param s2  Another `simd`.
         *
         * \return    `tue::math::max()` for each corresponding pair of
         *            components from `s1` and `s2`.
         */
        template<typename T, int N>
        inline std::enable_if_t<std::is_arithmetic<T>::value, simd<T, N>>
        max(const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            return tue::detail_::max_ss(s1, s2);
        }

        /*!
         * \brief             Computes `tue::math::mask()` for each
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
         * \return            `tue::math::mask()` for each corresponding pair of
         *                    components from `conditions` and `values`.
         */
        template<typename T, typename U, int N>
        inline std::enable_if_t<
            is_sized_bool<T>::value && sizeof(T) == sizeof(U), simd<U, N>>
        mask(
            const simd<T, N>& conditions,
            const simd<U, N>& values) noexcept
        {
            return tue::detail_::mask_ss(conditions, values);
        }

        /*!
         * \brief             Computes `tue::math::select()` for each
         *                    corresponding trio of components from
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
         * \return            `tue::math::select()` for each corresponding trio
         *                    of components from `conditions`, `values`, and
         *                    `otherwise`.
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
         *             of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        less(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::less_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::less_equal()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::less_equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        less_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::less_equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        greater(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::greater_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::greater_equal()` for each
         *             corresponding pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::greater_equal()` for each corresponding pair
         *             of components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        greater_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::greater_equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::equal()` for each corresponding pair
         *             of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::equal_ss(lhs, rhs);
        }

        /*!
         * \brief      Computes `tue::math::not_equal()` for each corresponding
         *             pair of components from `lhs` and `rhs`.
         *
         * \tparam T   The component type of both `lhs` and `rhs`.
         * \tparam N   The component count of both `lhs` and `rhs`.
         *
         * \param lhs  The left-hand side operand.
         * \param rhs  The right-hand side operand.
         *
         * \return     `tue::math::not_equal()` for each corresponding pair of
         *             components from `lhs` and `rhs`.
         */
        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N>
        not_equal(const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            return tue::detail_::not_equal_ss(lhs, rhs);
        }

        /*!@}*/
    }
}
