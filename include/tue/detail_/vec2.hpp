//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../vec.hpp"

namespace tue
{
    template<typename T>
    class vec<T, 2>
    {
        struct { T data[2]; } impl_;

    public:
        using component_type = T;

        static constexpr int component_count = 2;

        vec() noexcept = default;

        template<typename U>
        explicit constexpr vec(const U& x) noexcept :
            impl_({{ T(x), T(x) }})
        {
        }

        constexpr vec(const T& x, const T& y) noexcept :
            impl_({{ x, y }})
        {
        }

        explicit constexpr vec(const vec3<T>& other) noexcept :
            impl_({{ other[0], other[1] }})
        {
        }

        explicit constexpr vec(const vec4<T>& other) noexcept :
            impl_({{ other[0], other[1] }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec2<U>& other) noexcept :
            impl_({{ T(other[0]), T(other[1]) }})
        {
        }

        template<typename U>
        constexpr operator vec2<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        static constexpr vec2<T> zero() noexcept
        {
            return { T(0), T(0) };
        }

        static constexpr vec2<T> x_axis() noexcept
        {
            return { T(1), T(0) };
        }

        static constexpr vec2<T> y_axis() noexcept
        {
            return { T(0), T(1) };
        }

        constexpr T x() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T y() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T r() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T g() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr vec2<T> xy() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        constexpr vec2<T> rg() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        void set_x(const T& x) noexcept
        {
            this->impl_.data[0] = x;
        }

        void set_y(const T& y) noexcept
        {
            this->impl_.data[1] = y;
        }

        void set_r(const T& r) noexcept
        {
            this->impl_.data[0] = r;
        }

        void set_g(const T& g) noexcept
        {
            this->impl_.data[1] = g;
        }

        void set_xy(const T& x, const T& y) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
        }

        void set_xy(const vec2<T>& xy) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
        }

        void set_rg(const T& r, const T& g) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
        }

        void set_rg(const vec2<T>& rg) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
        }

        const T* data() const noexcept
        {
            return this->impl_.data;
        }

        T* data() noexcept
        {
            return this->impl_.data;
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

        vec2<T>& operator++() noexcept
        {
            ++this->impl_.data[0];
            ++this->impl_.data[1];
            return *this;
        }

        vec2<T> operator++(int) noexcept
        {
            return {
                this->impl_.data[0]++,
                this->impl_.data[1]++,
            };
        }

        vec2<T>& operator--() noexcept
        {
            --this->impl_.data[0];
            --this->impl_.data[1];
            return *this;
        }

        vec2<T> operator--(int) noexcept
        {
            return {
                this->impl_.data[0]--,
                this->impl_.data[1]--,
            };
        }

        template<typename U>
        vec2<T>& operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator+=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator-=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator*=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator/=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator%=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator&=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator|=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator^=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator<<=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            return *this;
        }

        template<typename U>
        vec2<T>& operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            return *this;
        }

        template<typename U>
        vec2<T>& operator>>=(const vec2<U>& v) noexcept
        {
            this->impl_.data[0] >>= v[0];
            this->impl_.data[1] >>= v[1];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T>
        inline constexpr vec2<decltype(+std::declval<T>())>
        unary_plus_operator(const vec2<T>& v) noexcept
        {
            return { +v[0], +v[1] };
        }

        template<typename T>
        inline constexpr vec2<decltype(-std::declval<T>())>
        unary_minus_operator(const vec2<T>& v) noexcept
        {
            return { -v[0], -v[1] };
        }

        template<typename T>
        inline constexpr vec2<decltype(~std::declval<T>())>
        bitwise_not_operator(const vec2<T>& v) noexcept
        {
            return { ~v[0], ~v[1] };
        }

        template<typename T>
        inline constexpr vec2<decltype(!std::declval<T>())>
        logical_not_operator(const vec2<T>& v) noexcept
        {
            return { !v[0], !v[1] };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const T& lhs, const vec2<U>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec2<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec2<T>& lhs, const vec2<U>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const T& lhs, const vec2<U>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec2<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec2<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec2<T>& lhs, const vec2<U>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr bool equality_operator(
            const vec2<T>& lhs, const vec2<U>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1];
        }

        template<typename T, typename U>
        inline constexpr bool inequality_operator(
            const vec2<T>& lhs, const vec2<U>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1];
        }
    }
}
