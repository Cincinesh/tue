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

        explicit constexpr vec(const vec4<T>& v) noexcept :
            impl_({{ v[0], v[1], v[2] }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec3<U>& v) noexcept :
            impl_({{ T(v[0]), T(v[1]), T(v[2]) }})
        {
        }

        template<typename U>
        constexpr operator vec3<U>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        static constexpr vec3<T> zero() noexcept
        {
            return { T(0), T(0), T(0) };
        }

        static constexpr vec3<T> x_axis() noexcept
        {
            return { T(1), T(0), T(0) };
        }

        static constexpr vec3<T> y_axis() noexcept
        {
            return { T(0), T(1), T(0) };
        }

        static constexpr vec3<T> z_axis() noexcept
        {
            return { T(0), T(0), T(1) };
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

        vec3<T>& operator++() noexcept
        {
            ++this->impl_.data[0];
            ++this->impl_.data[1];
            ++this->impl_.data[2];
            return *this;
        }

        vec3<T> operator++(int) noexcept
        {
            return {
                this->impl_.data[0]++,
                this->impl_.data[1]++,
                this->impl_.data[2]++,
            };
        }

        vec3<T>& operator--() noexcept
        {
            --this->impl_.data[0];
            --this->impl_.data[1];
            --this->impl_.data[2];
            return *this;
        }

        vec3<T> operator--(int) noexcept
        {
            return {
                this->impl_.data[0]--,
                this->impl_.data[1]--,
                this->impl_.data[2]--,
            };
        }

        template<typename U>
        vec3<T>& operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            this->impl_.data[2] += x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator+=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            this->impl_.data[2] += v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            this->impl_.data[2] -= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator-=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            this->impl_.data[2] -= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            this->impl_.data[2] *= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator*=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            this->impl_.data[2] *= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            this->impl_.data[2] /= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator/=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            this->impl_.data[2] /= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            this->impl_.data[2] %= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator%=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            this->impl_.data[2] %= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            this->impl_.data[2] &= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator&=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            this->impl_.data[2] &= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            this->impl_.data[2] |= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator|=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            this->impl_.data[2] |= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            this->impl_.data[2] ^= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator^=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            this->impl_.data[2] ^= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            this->impl_.data[2] <<= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator<<=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            this->impl_.data[2] <<= v[2];
            return *this;
        }

        template<typename U>
        vec3<T>& operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            this->impl_.data[2] >>= x;
            return *this;
        }

        template<typename U>
        vec3<T>& operator>>=(const vec3<U>& v) noexcept
        {
            this->impl_.data[0] >>= v[0];
            this->impl_.data[1] >>= v[1];
            this->impl_.data[2] >>= v[2];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T>
        inline constexpr vec3<decltype(+std::declval<T>())>
        unary_plus_operator(const vec3<T>& v) noexcept
        {
            return { +v[0], +v[1], +v[2] };
        }

        template<typename T>
        inline constexpr vec3<decltype(-std::declval<T>())>
        unary_minus_operator(const vec3<T>& v) noexcept
        {
            return { -v[0], -v[1], -v[2] };
        }

        template<typename T>
        inline constexpr vec3<decltype(~std::declval<T>())>
        bitwise_not_operator(const vec3<T>& v) noexcept
        {
            return { ~v[0], ~v[1], ~v[2] };
        }

        template<typename T>
        inline constexpr vec3<decltype(!std::declval<T>())>
        logical_not_operator(const vec3<T>& v) noexcept
        {
            return { !v[0], !v[1], !v[2] };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
                lhs + rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
                lhs[2] + rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() + std::declval<U>())>
        addition_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
                lhs[2] + rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
                lhs - rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
                lhs[2] - rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() - std::declval<U>())>
        subtraction_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
                lhs[2] - rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs * rhs[0],
                lhs * rhs[1],
                lhs * rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] * rhs,
                lhs[1] * rhs,
                lhs[2] * rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() * std::declval<U>())>
        multiplication_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] * rhs[0],
                lhs[1] * rhs[1],
                lhs[2] * rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs / rhs[0],
                lhs / rhs[1],
                lhs / rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] / rhs,
                lhs[1] / rhs,
                lhs[2] / rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() / std::declval<U>())>
        division_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] / rhs[0],
                lhs[1] / rhs[1],
                lhs[2] / rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs % rhs[0],
                lhs % rhs[1],
                lhs % rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] % rhs,
                lhs[1] % rhs,
                lhs[2] % rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() % std::declval<U>())>
        modulo_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] % rhs[0],
                lhs[1] % rhs[1],
                lhs[2] % rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs & rhs[0],
                lhs & rhs[1],
                lhs & rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] & rhs,
                lhs[1] & rhs,
                lhs[2] & rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() & std::declval<U>())>
        bitwise_and_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] & rhs[0],
                lhs[1] & rhs[1],
                lhs[2] & rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs | rhs[0],
                lhs | rhs[1],
                lhs | rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] | rhs,
                lhs[1] | rhs,
                lhs[2] | rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() | std::declval<U>())>
        bitwise_or_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] | rhs[0],
                lhs[1] | rhs[1],
                lhs[2] | rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs ^ rhs[0],
                lhs ^ rhs[1],
                lhs ^ rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs,
                lhs[1] ^ rhs,
                lhs[2] ^ rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() ^ std::declval<U>())>
        bitwise_xor_operator(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs[0],
                lhs[1] ^ rhs[1],
                lhs[2] ^ rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs << rhs[0],
                lhs << rhs[1],
                lhs << rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] << rhs,
                lhs[1] << rhs,
                lhs[2] << rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() << std::declval<U>())>
        bitwise_shift_left_operator(
            const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] << rhs[0],
                lhs[1] << rhs[1],
                lhs[2] << rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const T& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs >> rhs[0],
                lhs >> rhs[1],
                lhs >> rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const vec3<T>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] >> rhs,
                lhs[1] >> rhs,
                lhs[2] >> rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(std::declval<T>() >> std::declval<U>())>
        bitwise_shift_right_operator(
            const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                lhs[0] >> rhs[0],
                lhs[1] >> rhs[1],
                lhs[2] >> rhs[2],
            };
        }

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

        template<typename T>
        inline vec3<decltype(tue::math::sin(std::declval<T>()))>
        sin(const vec3<T>& v) noexcept
        {
            return {
                tue::math::sin(v[0]),
                tue::math::sin(v[1]),
                tue::math::sin(v[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::cos(std::declval<T>()))>
        cos(const vec3<T>& v) noexcept
        {
            return {
                tue::math::cos(v[0]),
                tue::math::cos(v[1]),
                tue::math::cos(v[2]),
            };
        }

        template<typename T>
        inline void sincos(
            const vec3<T>& v,
            decltype(tue::detail_::sin(v))& sin_out,
            decltype(tue::detail_::cos(v))& cos_out) noexcept
        {
            tue::math::sincos(v[0], sin_out[0], cos_out[0]);
            tue::math::sincos(v[1], sin_out[1], cos_out[1]);
            tue::math::sincos(v[2], sin_out[2], cos_out[2]);
        }

        template<typename T>
        inline vec3<decltype(tue::math::exp(std::declval<T>()))>
        exp(const vec3<T>& v) noexcept
        {
            return {
                tue::math::exp(v[0]),
                tue::math::exp(v[1]),
                tue::math::exp(v[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::log(std::declval<T>()))>
        log(const vec3<T>& v) noexcept
        {
            return {
                tue::math::log(v[0]),
                tue::math::log(v[1]),
                tue::math::log(v[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::abs(std::declval<T>()))>
        abs(const vec3<T>& v) noexcept
        {
            return {
                tue::math::abs(v[0]),
                tue::math::abs(v[1]),
                tue::math::abs(v[2]),
            };
        }

        template<typename T, typename U>
        inline vec3<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>()))>
        pow(const T& base, const vec3<U>& exponents) noexcept
        {
            return {
                tue::math::pow(base, exponents[0]),
                tue::math::pow(base, exponents[1]),
                tue::math::pow(base, exponents[2]),
            };
        }

        template<typename T, typename U>
        inline vec3<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>()))>
        pow(const vec3<T>& bases, const U& exponent) noexcept
        {
            return {
                tue::math::pow(bases[0], exponent),
                tue::math::pow(bases[1], exponent),
                tue::math::pow(bases[2], exponent),
            };
        }

        template<typename T, typename U>
        inline vec3<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>()))>
        pow(const vec3<T>& bases, const vec3<U>& exponents) noexcept
        {
            return {
                tue::math::pow(bases[0], exponents[0]),
                tue::math::pow(bases[1], exponents[1]),
                tue::math::pow(bases[2], exponents[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::recip(std::declval<T>()))>
        recip(const vec3<T>& v) noexcept
        {
            return {
                tue::math::recip(v[0]),
                tue::math::recip(v[1]),
                tue::math::recip(v[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::sqrt(std::declval<T>()))>
        sqrt(const vec3<T>& v) noexcept
        {
            return {
                tue::math::sqrt(v[0]),
                tue::math::sqrt(v[1]),
                tue::math::sqrt(v[2]),
            };
        }

        template<typename T>
        inline vec3<decltype(tue::math::rsqrt(std::declval<T>()))>
        rsqrt(const vec3<T>& v) noexcept
        {
            return {
                tue::math::rsqrt(v[0]),
                tue::math::rsqrt(v[1]),
                tue::math::rsqrt(v[2]),
            };
        }

        template<typename T>
        inline vec3<T> min(const vec3<T>& v1, const vec3<T>& v2) noexcept
        {
            return {
                tue::math::min(v1[0], v2[0]),
                tue::math::min(v1[1], v2[1]),
                tue::math::min(v1[2], v2[2]),
            };
        }

        template<typename T>
        inline vec3<T> max(const vec3<T>& v1, const vec3<T>& v2) noexcept
        {
            return {
                tue::math::max(v1[0], v2[0]),
                tue::math::max(v1[1], v2[1]),
                tue::math::max(v1[2], v2[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        dot(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return lhs[0] * rhs[0]
                 + lhs[1] * rhs[1]
                 + lhs[2] * rhs[2];
        }

        template<typename T>
        inline constexpr T length2(const vec3<T>& v) noexcept
        {
            return v[0] * v[0]
                 + v[1] * v[1]
                 + v[2] * v[2];
        }

        template<typename T, typename U>
        inline constexpr vec3<U> select(
            const vec3<T>& conditions,
            const vec3<U>& values,
            const vec3<U>& otherwise) noexcept
        {
            return {
                tue::math::select(conditions[0], values[0], otherwise[0]),
                tue::math::select(conditions[1], values[1], otherwise[1]),
                tue::math::select(conditions[2], values[2], otherwise[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::less(std::declval<T>(), std::declval<U>()))>
        less(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::less(lhs[0], rhs[0]),
                tue::math::less(lhs[1], rhs[1]),
                tue::math::less(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::less_equal(std::declval<T>(), std::declval<U>()))>
        less_equal(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::less_equal(lhs[0], rhs[0]),
                tue::math::less_equal(lhs[1], rhs[1]),
                tue::math::less_equal(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::greater(std::declval<T>(), std::declval<U>()))>
        greater(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::greater(lhs[0], rhs[0]),
                tue::math::greater(lhs[1], rhs[1]),
                tue::math::greater(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::greater_equal(std::declval<T>(), std::declval<U>()))>
        greater_equal(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::greater_equal(lhs[0], rhs[0]),
                tue::math::greater_equal(lhs[1], rhs[1]),
                tue::math::greater_equal(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::equal(std::declval<T>(), std::declval<U>()))>
        equal(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::equal(lhs[0], rhs[0]),
                tue::math::equal(lhs[1], rhs[1]),
                tue::math::equal(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec3<decltype(
            tue::math::not_equal(std::declval<T>(), std::declval<U>()))>
        not_equal(const vec3<T>& lhs, const vec3<U>& rhs) noexcept
        {
            return {
                tue::math::not_equal(lhs[0], rhs[0]),
                tue::math::not_equal(lhs[1], rhs[1]),
                tue::math::not_equal(lhs[2], rhs[2]),
            };
        }
    }
}
