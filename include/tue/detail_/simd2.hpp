//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

#include "../simd.hpp"
#include "../sized_bool.hpp"

namespace tue
{
    template<typename T>
    class alignas(sizeof(T) * 2) simd<T, 2>
    {
        std::enable_if_t<
            (is_sized_bool<T>::value
                || (std::is_arithmetic<T>::value
                    && !std::is_same<T, bool>::value)),
            T[2]>
        data_;

    public:
        using component_type = T;

        static constexpr int component_count = 2;

        simd() noexcept = default;

        template<
            typename U,
            typename = std::enable_if_t<
                !is_sized_bool<T>::value || std::is_same<T, U>::value>>
        explicit simd(const U& x) noexcept
        {
            const auto y = static_cast<T>(x);
            this->data_[0] = y;
            this->data_[1] = y;
        }

        simd(T x, T y) noexcept
        {
            this->data_[0] = x;
            this->data_[1] = y;
        }

        template<typename U>
        explicit simd(const simd<U, 2>& s) noexcept
        {
            this->data_[0] = static_cast<T>(s.data()[0]);
            this->data_[1] = static_cast<T>(s.data()[1]);
        }

        static simd<T, 2> zero() noexcept
        {
            simd<T, 2> s;
            s.data_[0] = static_cast<T>(0);
            s.data_[1] = static_cast<T>(0);
            return s;
        }

        static simd<T, 2> load(const T* data) noexcept
        {
            simd<T, 2> s;
            s.data_[0] = data[0];
            s.data_[1] = data[1];
            return s;
        }

        static simd<T, 2> loadu(const T* data) noexcept
        {
            simd<T, 2> s;
            s.data_[0] = data[0];
            s.data_[1] = data[1];
            return s;
        }

        void store(T* data) const noexcept
        {
            data[0] = this->data_[0];
            data[1] = this->data_[1];
        }

        void storeu(T* data) const noexcept
        {
            data[0] = this->data_[0];
            data[1] = this->data_[1];
        }

        const T* data() const noexcept
        {
            return this->data_;
        }

        T* data() noexcept
        {
            return this->data_;
        }
    };
}
