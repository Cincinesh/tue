//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <utility>

#include "../math.hpp"
#include "../vec.hpp"

namespace tue
{
    template<typename T>
    class vec<T, 4>
    {
        struct { T data[4]; } impl_;

    public:
        using component_type = T;

        static constexpr int component_count = 4;

        vec() noexcept = default;

        template<typename U>
        explicit constexpr vec(const U& x) noexcept :
            impl_({{ T(x), T(x), T(x), T(x) }})
        {
        }

        constexpr vec(const T& x, const T& y, const T& z, const T& w) noexcept :
            impl_({{ x, y, z, w }})
        {
        }

        constexpr vec(const vec2<T>& xy, const T& z, const T& w) noexcept :
            impl_({{ xy[0], xy[1], z, w }})
        {
        }

        constexpr vec(const vec3<T>& xyz, const T& w) noexcept :
            impl_({{ xyz[0], xyz[1], xyz[2], w }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec4<U>& other) noexcept :
            impl_({{ T(other[0]), T(other[1]), T(other[2]), T(other[3]) }})
        {
        }

        template<typename U>
        constexpr operator vec4<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        static constexpr vec4<T> zero() noexcept
        {
            return { T(0), T(0), T(0), T(0) };
        }

        static constexpr vec4<T> x_axis() noexcept
        {
            return { T(1), T(0), T(0), T(0) };
        }

        static constexpr vec4<T> y_axis() noexcept
        {
            return { T(0), T(1), T(0), T(0) };
        }

        static constexpr vec4<T> z_axis() noexcept
        {
            return { T(0), T(0), T(1), T(0) };
        }

        static constexpr vec4<T> w_axis() noexcept
        {
            return { T(0), T(0), T(0), T(1) };
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

        constexpr T w() const noexcept
        {
            return this->impl_.data[3];
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

        constexpr T a() const noexcept
        {
            return this->impl_.data[3];
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

        constexpr vec4<T> xyzw() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        constexpr vec4<T> rgba() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
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

        void set_w(const T& w) noexcept
        {
            this->impl_.data[3] = w;
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

        void set_a(const T& a) noexcept
        {
            this->impl_.data[3] = a;
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

        void set_xyzw(const T& x, const T& y, const T& z, const T& w) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec2<T>& xy, const T& z, const T& w) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
            this->impl_.data[2] = z;
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec3<T>& xyz, const T& w) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec4<T>& xyzw) noexcept
        {
            this->impl_.data[0] = xyzw[0];
            this->impl_.data[1] = xyzw[1];
            this->impl_.data[2] = xyzw[2];
            this->impl_.data[3] = xyzw[3];
        }

        void set_rgba(const T& r, const T& g, const T& b, const T& a) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
            this->impl_.data[2] = b;
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec2<T>& rg, const T& b, const T& a) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
            this->impl_.data[2] = b;
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec3<T>& rgb, const T& a) noexcept
        {
            this->impl_.data[0] = rgb[0];
            this->impl_.data[1] = rgb[1];
            this->impl_.data[2] = rgb[2];
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec4<T>& rgba) noexcept
        {
            this->impl_.data[0] = rgba[0];
            this->impl_.data[1] = rgba[1];
            this->impl_.data[2] = rgba[2];
            this->impl_.data[3] = rgba[3];
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

        vec4<T>& operator++() noexcept
        {
            ++this->impl_.data[0];
            ++this->impl_.data[1];
            ++this->impl_.data[2];
            ++this->impl_.data[3];
            return *this;
        }

        vec4<T> operator++(int) noexcept
        {
            return {
                this->impl_.data[0]++,
                this->impl_.data[1]++,
                this->impl_.data[2]++,
                this->impl_.data[3]++,
            };
        }

        vec4<T>& operator--() noexcept
        {
            --this->impl_.data[0];
            --this->impl_.data[1];
            --this->impl_.data[2];
            --this->impl_.data[3];
            return *this;
        }

        vec4<T> operator--(int) noexcept
        {
            return {
                this->impl_.data[0]--,
                this->impl_.data[1]--,
                this->impl_.data[2]--,
                this->impl_.data[3]--,
            };
        }

        template<typename U>
        vec4<T>& operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            this->impl_.data[2] += x;
            this->impl_.data[3] += x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator+=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            this->impl_.data[2] += v[2];
            this->impl_.data[3] += v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            this->impl_.data[2] -= x;
            this->impl_.data[3] -= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator-=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            this->impl_.data[2] -= v[2];
            this->impl_.data[3] -= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            this->impl_.data[2] *= x;
            this->impl_.data[3] *= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator*=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            this->impl_.data[2] *= v[2];
            this->impl_.data[3] *= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            this->impl_.data[2] /= x;
            this->impl_.data[3] /= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator/=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            this->impl_.data[2] /= v[2];
            this->impl_.data[3] /= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            this->impl_.data[2] %= x;
            this->impl_.data[3] %= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator%=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            this->impl_.data[2] %= v[2];
            this->impl_.data[3] %= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            this->impl_.data[2] &= x;
            this->impl_.data[3] &= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator&=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            this->impl_.data[2] &= v[2];
            this->impl_.data[3] &= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            this->impl_.data[2] |= x;
            this->impl_.data[3] |= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator|=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            this->impl_.data[2] |= v[2];
            this->impl_.data[3] |= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            this->impl_.data[2] ^= x;
            this->impl_.data[3] ^= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator^=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            this->impl_.data[2] ^= v[2];
            this->impl_.data[3] ^= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            this->impl_.data[2] <<= x;
            this->impl_.data[3] <<= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator<<=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            this->impl_.data[2] <<= v[2];
            this->impl_.data[3] <<= v[3];
            return *this;
        }

        template<typename U>
        vec4<T>& operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            this->impl_.data[2] >>= x;
            this->impl_.data[3] >>= x;
            return *this;
        }

        template<typename U>
        vec4<T>& operator>>=(const vec4<U>& v) noexcept
        {
            this->impl_.data[0] >>= v[0];
            this->impl_.data[1] >>= v[1];
            this->impl_.data[2] >>= v[2];
            this->impl_.data[3] >>= v[3];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T>
        inline constexpr vec4<decltype(+std::declval<T>())>
        unary_plus_operator(const vec4<T>& v) noexcept
        {
            return { +v[0], +v[1], +v[2], +v[3] };
        }

        template<typename T>
        inline constexpr vec4<decltype(-std::declval<T>())>
        unary_minus_operator(const vec4<T>& v) noexcept
        {
            return { -v[0], -v[1], -v[2], -v[3] };
        }

        template<typename T>
        inline constexpr vec4<decltype(~std::declval<T>())>
        bitwise_not_operator(const vec4<T>& v) noexcept
        {
            return { ~v[0], ~v[1], ~v[2], ~v[3] };
        }

        template<typename T>
        inline constexpr vec4<decltype(!std::declval<T>())>
        logical_not_operator(const vec4<T>& v) noexcept
        {
            return { !v[0], !v[1], !v[2], !v[3] };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
                lhs + rhs[2],
                lhs + rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
                lhs[2] + rhs,
                lhs[3] + rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
                lhs[2] + rhs[2],
                lhs[3] + rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
                lhs - rhs[2],
                lhs - rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
                lhs[2] - rhs,
                lhs[3] - rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
                lhs[2] - rhs[2],
                lhs[3] - rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs * rhs[0],
                lhs * rhs[1],
                lhs * rhs[2],
                lhs * rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] * rhs,
                lhs[1] * rhs,
                lhs[2] * rhs,
                lhs[3] * rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] * rhs[0],
                lhs[1] * rhs[1],
                lhs[2] * rhs[2],
                lhs[3] * rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs / rhs[0],
                lhs / rhs[1],
                lhs / rhs[2],
                lhs / rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] / rhs,
                lhs[1] / rhs,
                lhs[2] / rhs,
                lhs[3] / rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] / rhs[0],
                lhs[1] / rhs[1],
                lhs[2] / rhs[2],
                lhs[3] / rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs % rhs[0],
                lhs % rhs[1],
                lhs % rhs[2],
                lhs % rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] % rhs,
                lhs[1] % rhs,
                lhs[2] % rhs,
                lhs[3] % rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] % rhs[0],
                lhs[1] % rhs[1],
                lhs[2] % rhs[2],
                lhs[3] % rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs & rhs[0],
                lhs & rhs[1],
                lhs & rhs[2],
                lhs & rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] & rhs,
                lhs[1] & rhs,
                lhs[2] & rhs,
                lhs[3] & rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] & rhs[0],
                lhs[1] & rhs[1],
                lhs[2] & rhs[2],
                lhs[3] & rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs | rhs[0],
                lhs | rhs[1],
                lhs | rhs[2],
                lhs | rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] | rhs,
                lhs[1] | rhs,
                lhs[2] | rhs,
                lhs[3] | rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] | rhs[0],
                lhs[1] | rhs[1],
                lhs[2] | rhs[2],
                lhs[3] | rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs ^ rhs[0],
                lhs ^ rhs[1],
                lhs ^ rhs[2],
                lhs ^ rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs,
                lhs[1] ^ rhs,
                lhs[2] ^ rhs,
                lhs[3] ^ rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs[0],
                lhs[1] ^ rhs[1],
                lhs[2] ^ rhs[2],
                lhs[3] ^ rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs << rhs[0],
                lhs << rhs[1],
                lhs << rhs[2],
                lhs << rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] << rhs,
                lhs[1] << rhs,
                lhs[2] << rhs,
                lhs[3] << rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] << rhs[0],
                lhs[1] << rhs[1],
                lhs[2] << rhs[2],
                lhs[3] << rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const T& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs >> rhs[0],
                lhs >> rhs[1],
                lhs >> rhs[2],
                lhs >> rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const vec4<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] >> rhs,
                lhs[1] >> rhs,
                lhs[2] >> rhs,
                lhs[3] >> rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec4<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return {
                lhs[0] >> rhs[0],
                lhs[1] >> rhs[1],
                lhs[2] >> rhs[2],
                lhs[3] >> rhs[3],
            };
        }

        template<typename T, typename U>
        inline constexpr bool equality_operator(
            const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1]
                && lhs[2] == rhs[2]
                && lhs[3] == rhs[3];
        }

        template<typename T, typename U>
        inline constexpr bool inequality_operator(
            const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1]
                || lhs[2] != rhs[2]
                || lhs[3] != rhs[3];
        }

        template<typename T>
        inline vec4<decltype(tue::math::sin(std::declval<T>()))>
        sin(const vec4<T>& v) noexcept
        {
            return {
                tue::math::sin(v[0]),
                tue::math::sin(v[1]),
                tue::math::sin(v[2]),
                tue::math::sin(v[3]),
            };
        }

        template<typename T>
        inline vec4<decltype(tue::math::cos(std::declval<T>()))>
        cos(const vec4<T>& v) noexcept
        {
            return {
                tue::math::cos(v[0]),
                tue::math::cos(v[1]),
                tue::math::cos(v[2]),
                tue::math::cos(v[3]),
            };
        }

        template<typename T>
        inline void sincos(
            const vec4<T>& v,
            decltype(tue::math::sin(v))& sin_out,
            decltype(tue::math::cos(v))& cos_out) noexcept
        {
            tue::math::sincos(v[0], sin_out[0], cos_out[0]);
            tue::math::sincos(v[1], sin_out[1], cos_out[1]);
            tue::math::sincos(v[2], sin_out[2], cos_out[2]);
            tue::math::sincos(v[3], sin_out[3], cos_out[3]);
        }

        template<typename T>
        inline vec4<decltype(tue::math::exp(std::declval<T>()))>
        exp(const vec4<T>& v) noexcept
        {
            return {
                tue::math::exp(v[0]),
                tue::math::exp(v[1]),
                tue::math::exp(v[2]),
                tue::math::exp(v[3]),
            };
        }

        template<typename T>
        inline vec4<decltype(tue::math::log(std::declval<T>()))>
        log(const vec4<T>& v) noexcept
        {
            return {
                tue::math::log(v[0]),
                tue::math::log(v[1]),
                tue::math::log(v[2]),
                tue::math::log(v[3]),
            };
        }
    }
}
