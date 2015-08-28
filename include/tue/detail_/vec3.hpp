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
    class vec<T, 3>
    {
        struct { T data[3]; } impl_;

    public:
        using component_type = T;

        static constexpr int component_count = 3;

        vec() noexcept = default;

        template<typename U>
        explicit constexpr vec(const U& x) noexcept :
            impl_({{ T(x), T(x), T(x) }})
        {
        }

        constexpr vec(const T& x, const T& y, const T& z) noexcept :
            impl_({{ x, y, z }})
        {
        }

        constexpr vec(const vec2<T>& xy, const T& z) noexcept :
            impl_({{ xy[0], xy[1], z }})
        {
        }

        explicit constexpr vec(const vec4<T>& other) noexcept :
            impl_({{ other[0], other[1], other[2] }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec<U, 3>& other) noexcept :
            impl_({{ T(other[0]), T(other[1]), T(other[2]) }})
        {
        }

        template<typename U>
        constexpr operator vec<U, 3>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        static constexpr vec<T, 3> zero() noexcept
        {
            return { T(0), T(0), T(0) };
        }

        static constexpr vec<T, 3> x_axis() noexcept
        {
            return { T(1), T(0), T(0) };
        }

        static constexpr vec<T, 3> y_axis() noexcept
        {
            return { T(0), T(1), T(0) };
        }

        static constexpr vec<T, 3> z_axis() noexcept
        {
            return { T(0), T(0), T(1) };
        }

        constexpr T x() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T y() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T z() const noexcept
        {
            return this->impl_.data[2];
        }

        constexpr T r() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T g() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T b() const noexcept
        {
            return this->impl_.data[2];
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

        constexpr vec3<T> xyz() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        constexpr vec3<T> rgb() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
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

        void set_z(const T& z) noexcept
        {
            this->impl_.data[2] = z;
        }

        void set_r(const T& r) noexcept
        {
            this->impl_.data[0] = r;
        }

        void set_g(const T& g) noexcept
        {
            this->impl_.data[1] = g;
        }

        void set_b(const T& b) noexcept
        {
            this->impl_.data[2] = b;
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

        void set_xyz(const T& x, const T& y, const T& z) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
        }

        void set_xyz(const vec2<T>& xy, const T& z) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
            this->impl_.data[2] = z;
        }

        void set_xyz(const vec3<T>& xyz) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
        }

        void set_rgb(const T& r, const T& g, const T& b) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
            this->impl_.data[2] = b;
        }

        void set_rgb(const vec2<T>& rg, const T& b) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
            this->impl_.data[2] = b;
        }

        void set_rgb(const vec3<T>& rgb) noexcept
        {
            this->impl_.data[0] = rgb[0];
            this->impl_.data[1] = rgb[1];
            this->impl_.data[2] = rgb[2];
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

        vec<T, 3>& operator++() noexcept
        {
            ++this->impl_.data[0];
            ++this->impl_.data[1];
            ++this->impl_.data[2];
            return *this;
        }

        vec<T, 3> operator++(int) noexcept
        {
            return {
                this->impl_.data[0]++,
                this->impl_.data[1]++,
                this->impl_.data[2]++,
            };
        }

        vec<T, 3>& operator--() noexcept
        {
            --this->impl_.data[0];
            --this->impl_.data[1];
            --this->impl_.data[2];
            return *this;
        }

        vec<T, 3> operator--(int) noexcept
        {
            return {
                this->impl_.data[0]--,
                this->impl_.data[1]--,
                this->impl_.data[2]--,
            };
        }

        template<typename U>
        vec<T, 3>& operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            this->impl_.data[2] += x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator+=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            this->impl_.data[2] += v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            this->impl_.data[2] -= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator-=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            this->impl_.data[2] -= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            this->impl_.data[2] *= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator*=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            this->impl_.data[2] *= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            this->impl_.data[2] /= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator/=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            this->impl_.data[2] /= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            this->impl_.data[2] %= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator%=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            this->impl_.data[2] %= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            this->impl_.data[2] &= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator&=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            this->impl_.data[2] &= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            this->impl_.data[2] |= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator|=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            this->impl_.data[2] |= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            this->impl_.data[2] ^= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator^=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            this->impl_.data[2] ^= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            this->impl_.data[2] <<= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator<<=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            this->impl_.data[2] <<= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            this->impl_.data[2] >>= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>& operator>>=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] >>= v[0];
            this->impl_.data[1] >>= v[1];
            this->impl_.data[2] >>= v[2];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T, typename U>
        inline constexpr bool equality_operator(
            const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1]
                && lhs[2] == rhs[2];
        }

        template<typename T, typename U>
        inline constexpr bool inequality_operator(
            const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1]
                || lhs[2] != rhs[2];
        }
    }
}
