//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <cstddef>
#include <functional>
#include <type_traits>
#include <utility>

#include "detail_/is_vec_component.hpp"
#include "size2d.hpp"

/*!
 * \defgroup  size3d_hpp <tue/size3d.hpp>
 *
 * \brief     The `size3d` class template and its associated functions.
 */
namespace tue
{
    template<typename T>
    class size2d;

    /*!
     * \addtogroup  size3d_hpp
     * @{
     */

    /*!
     * \brief     An 3-dimensional size (width, height, and depth).
     * \details   `size3d` has the same size and alignment requirements as
     *            `T[3]`.
     *
     * \tparam T  The component type. `is_vec_component<T>::value` must be
     *            `true`.
     */
    template<typename T>
    class size3d;

    /*!
     * \brief  A `size3d` with `float` components.
     */
    using fsize3d = size3d<float>;

    /*!
     * \brief  A `size3d` with `double` components.
     */
    using dsize3d = size3d<double>;

    /*!
     * \brief  A `size3d` with `int` components.
     */
    using isize3d = size3d<int>;

    /*!
     * \brief  A `size3d` with `unsigned int` components.
     */
    using usize3d = size3d<unsigned int>;

    /**/
    template<typename T>
    class size3d
    {
        struct
        {
            std::enable_if_t<is_vec_component<T>::value, T[3]> data;
        }
        impl_;

    public:
        /*!
         * \brief  This `size3d` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `size3d` type's component count.
         */
        static constexpr int component_count = 3;

        /*!
         * \name Constructors, Conversions, and Factory Functions
         * @{
         */
        /*!
         * \brief  Default constructs each component.
         */
        size3d() noexcept = default;

        /*!
         * \brief    Constructs each component with the same value.
         *
         * \param x  The value to construct each component with.
         */
        explicit constexpr size3d(const T& x) noexcept
        :
            impl_({{ x, x, x }})
        {
        }

        /*!
         * \brief         Constructs each component with the value of the
         *                corresponding argument.
         *
         * \param width   The value to construct the `width` component with.
         * \param height  The value to construct the `height` component with.
         * \param depth   The value to construct the `depth` component with.
         */
        constexpr size3d(
            const T& width, const T& height, const T& depth) noexcept
        :
            impl_({{ width, height, depth }})
        {
        }

        /*!
         * \brief        Constructs each component with the value of the
         *               corresponding argument.
         *
         * \param width_height  The values to construct the `width` and `height`
         *                      components with.
         *
         * \param depth  The value to construct the `depth` component with.
         */
        constexpr size3d(const size2d<T>& width_height, const T& depth) noexcept
        :
            impl_({{ width_height[0], width_height[1], depth }})
        {
        }

        /*!
         * \brief        Explicitly casts another `size3d` to a new component
         *               type.
         *
         * \tparam U     The component type of `other`.
         *
         * \param other  The `size3d` to cast from.
         */
        template<typename U>
        explicit constexpr size3d(const size3d<U>& other) noexcept
        :
            impl_({{ T(other[0]), T(other[1]), T(other[2]) }})
        {
        }

        /*!
         * \brief     Implicitly casts this `size3d` to a new component type.
         *
         * \tparam U  The new component type.
         *
         * \return    A new `size3d` with the new component type.
         */
        template<typename U>
        constexpr operator size3d<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        static constexpr size3d<T> zero() noexcept
        {
            return { T(0), T(0), T(0) };
        }

        template<typename I>
        constexpr const T& operator[](const I& i) const noexcept
        {
            return this->impl_.data[i];
        }

        template<typename I>
        T& operator[](const I& i) noexcept
        {
            return this->impl_.data[i];
        }

        const T* data() const noexcept
        {
            return this->impl_.data;
        }

        T* data() noexcept
        {
            return this->impl_.data;
        }

        constexpr T width() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T height() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T depth() const noexcept
        {
            return this->impl_.data[2];
        }

        constexpr size2d<T> width_height() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        constexpr size3d<T> width_height_depth() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        void set_width(const T& width) noexcept
        {
            this->impl_.data[0] = width;
        }

        void set_height(const T& height) noexcept
        {
            this->impl_.data[1] = height;
        }

        void set_depth(const T& depth) noexcept
        {
            this->impl_.data[2] = depth;
        }

        void set_width_height(const T& width, const T& height) noexcept
        {
            this->impl_.data[0] = width;
            this->impl_.data[1] = height;
        }

        void set_width_height(const size2d<T>& width_height) noexcept
        {
            this->impl_.data[0] = width_height[0];
            this->impl_.data[1] = width_height[1];
        }

        void set_width_height_depth(
            const T& width, const T& height, const T& depth) noexcept
        {
            this->impl_.data[0] = width;
            this->impl_.data[1] = height;
            this->impl_.data[2] = depth;
        }

        void set_width_height_depth(
            const size2d<T>& width_height, const T& depth) noexcept
        {
            this->impl_.data[0] = width_height[0];
            this->impl_.data[1] = width_height[1];
            this->impl_.data[2] = depth;
        }

        void set_width_height_depth(
            const size3d<T>& width_height_depth) noexcept
        {
            this->impl_.data[0] = width_height_depth[0];
            this->impl_.data[1] = width_height_depth[1];
            this->impl_.data[2] = width_height_depth[2];
        }
    };

    template<typename T, typename U>
    inline constexpr bool operator==(
        const size3d<T>& lhs, const size3d<U>& rhs) noexcept
    {
        return lhs[0] == rhs[0]
            && lhs[1] == rhs[1]
            && lhs[2] == rhs[2];
    }

    template<typename T, typename U>
    inline constexpr bool operator!=(
        const size3d<T>& lhs, const size3d<U>& rhs) noexcept
    {
        return lhs[0] != rhs[0]
            || lhs[1] != rhs[1]
            || lhs[2] != rhs[2];
    }

    template<typename T>
    inline void swap(size3d<T>& size1, size3d<T>& size2) noexcept
    {
        using std::swap;
        swap(size1[0], size2[0]);
        swap(size1[1], size2[1]);
        swap(size1[2], size2[2]);
    }
}

namespace std
{
    template<typename T>
    inline void swap(tue::size3d<T>& size1, tue::size3d<T>& size2) noexcept
    {
        tue::swap(size1, size2);
    }

    template<typename T>
    struct hash<tue::size3d<T>>
    {
        inline std::size_t operator()(const tue::size3d<T>& size) const noexcept
        {
            std::hash<T> hashT;
            return hashT(size[0]) ^ hashT(size[1]) ^ hashT(size[2]);
        }
    };
}
