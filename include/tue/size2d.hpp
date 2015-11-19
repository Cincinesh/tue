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

namespace tue
{
    template<typename T>
    class size2d;

    using fsize2d = size2d<float>;

    using dsize2d = size2d<double>;

    using isize2d = size2d<int>;

    using usize2d = size2d<unsigned int>;

    template<typename T>
    class size2d
    {
        struct
        {
            std::enable_if_t<is_vec_component<T>::value, T[2]> data;
        }
        impl_;

    public:
        using component_type = T;

        static constexpr int component_count = 2;

        size2d() noexcept = default;

        explicit constexpr size2d(const T& width_height) noexcept
        :
            impl_({{
                width_height,
                width_height,
            }})
        {
        }

        constexpr size2d(const T& width, const T& height) noexcept
        :
            impl_({{ width, height, depth }})
        {
        }

        constexpr size2d(const size2d<T>& width_height) noexcept
        :
            impl_({{ width_height[0], width_height[1] }})
        {
        }

        template<typename U>
        constexpr operator size2d<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        static constexpr size2d<T> zero() noexcept
        {
            return { T(0), T(0) };
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

        constexpr size2d<T> width_height() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
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
    };

    template<typename T, typename U>
    inline constexpr bool operator==(
        const size2d<T>& lhs, const size2d<U>& rhs) noexcept
    {
        return lhs[0] == rhs[0]
            && lhs[1] == rhs[1];;
    }

    template<typename T, typename U>
    inline constexpr bool operator!=(
        const size2d<T>& lhs, const size2d<U>& rhs) noexcept
    {
        return lhs[0] != rhs[0]
            || lhs[1] != rhs[1];
    }

    template<typename T>
    inline void swap(size2d<T>& size1, size2d<T>& size2) noexcept
    {
        using std::swap;
        swap(size1[0], size2[0]);
        swap(size1[1], size2[1]);
    }
}

namespace std
{
    template<typename T>
    inline void swap(tue::size2d<T>& size1, tue::size2d<T>& size2) noexcept
    {
        tue::swap(size1, size2);
    }
    
    template<typename T>
    struct hash<tue::size2d<T>>
    {
        inline std::size_t operator()(const tue::size2d<T>& size) const noexcept
        {
            std::hash<T> hashT;
            return hashT(size[0]) ^ hashT(size[1]);
        }
    };
}
