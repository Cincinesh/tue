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

#include "../math.hpp"
#include "../nocopy_cast.hpp"
#include "../vec.hpp"

namespace tue
{
    template<typename T>
    class quat;

    template<typename T, int C, int R>
    class mat;

    template<typename T>
    class vec<T, 3>
    {
        struct
        {
            std::enable_if_t<is_vec_component<T>::value, T[3]> data;
        }
        impl_;

    public:
        using component_type = T;

        static constexpr int component_count = 3;

        vec() noexcept = default;

        explicit constexpr vec(const T& x) noexcept
        :
            impl_({{ x, x, x }})
        {
        }

        constexpr vec(const T& x, const T& y, const T& z) noexcept
        :
            impl_({{ x, y, z }})
        {
        }

        constexpr vec(const vec2<T>& xy, const T& z) noexcept
        :
            impl_({{ xy[0], xy[1], z }})
        {
        }

        template<int VN, typename = std::enable_if_t<(VN > 3)>>
        explicit constexpr vec(const vec<T, VN>& v) noexcept
        :
            impl_({{ v[0], v[1], v[2] }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec<U, 3>& v) noexcept
        :
            impl_({{ T(v[0]), T(v[1]), T(v[2]) }})
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

        constexpr vec2<T> xy() const noexcept
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

        constexpr vec2<T> rg() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
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
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            this->impl_.data[2] += x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator+=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            this->impl_.data[2] += v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            this->impl_.data[2] -= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator-=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            this->impl_.data[2] -= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            this->impl_.data[2] *= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator*=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            this->impl_.data[2] *= v[2];
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator*=(const quat<U>& q) noexcept
        {
            return (*this) = (*this) * q;
        }

        template<typename U>
        vec<T, 3>&
        operator*=(const mat<U, 3, 3>& m) noexcept
        {
            return (*this) = (*this) * m;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            this->impl_.data[2] /= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator/=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            this->impl_.data[2] /= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            this->impl_.data[2] %= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator%=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            this->impl_.data[2] %= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            this->impl_.data[2] &= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator&=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            this->impl_.data[2] &= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            this->impl_.data[2] |= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator|=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            this->impl_.data[2] |= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            this->impl_.data[2] ^= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator^=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            this->impl_.data[2] ^= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            this->impl_.data[2] <<= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator<<=(const vec<U, 3>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            this->impl_.data[2] <<= v[2];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, vec<T, 3>&>
        operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            this->impl_.data[2] >>= x;
            return *this;
        }

        template<typename U>
        vec<T, 3>&
        operator>>=(const vec<U, 3>& v) noexcept
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
        inline constexpr
            vec<decltype(+std::declval<T>()), 3>
        unary_plus_operator_v(const vec<T, 3>& v) noexcept
        {
            return { +v[0], +v[1], +v[2] };
        }

        template<typename T>
        inline constexpr
            vec<decltype(-std::declval<T>()), 3>
        unary_minus_operator_v(const vec<T, 3>& v) noexcept
        {
            return { -v[0], -v[1], -v[2] };
        }

        template<typename T>
        inline constexpr
            vec<decltype(~std::declval<T>()), 3>
        bitwise_not_operator_v(const vec<T, 3>& v) noexcept
        {
            return { ~v[0], ~v[1], ~v[2] };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() + std::declval<U>()), 3>
        addition_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
                lhs + rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() + std::declval<U>()), 3>
        addition_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
                lhs[2] + rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() + std::declval<U>()), 3>
        addition_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
                lhs[2] + rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() - std::declval<U>()), 3>
        subtraction_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
                lhs - rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() - std::declval<U>()), 3>
        subtraction_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
                lhs[2] - rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() - std::declval<U>()), 3>
        subtraction_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
                lhs[2] - rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        multiplication_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs * rhs[0],
                lhs * rhs[1],
                lhs * rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        multiplication_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] * rhs,
                lhs[1] * rhs,
                lhs[2] * rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        multiplication_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] * rhs[0],
                lhs[1] * rhs[1],
                lhs[2] * rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() / std::declval<U>()), 3>
        division_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs / rhs[0],
                lhs / rhs[1],
                lhs / rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() / std::declval<U>()), 3>
        division_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] / rhs,
                lhs[1] / rhs,
                lhs[2] / rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() / std::declval<U>()), 3>
        division_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] / rhs[0],
                lhs[1] / rhs[1],
                lhs[2] / rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() % std::declval<U>()), 3>
        modulo_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs % rhs[0],
                lhs % rhs[1],
                lhs % rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() % std::declval<U>()), 3>
        modulo_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] % rhs,
                lhs[1] % rhs,
                lhs[2] % rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() % std::declval<U>()), 3>
        modulo_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] % rhs[0],
                lhs[1] % rhs[1],
                lhs[2] % rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() & std::declval<U>()), 3>
        bitwise_and_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs & rhs[0],
                lhs & rhs[1],
                lhs & rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() & std::declval<U>()), 3>
        bitwise_and_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] & rhs,
                lhs[1] & rhs,
                lhs[2] & rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() & std::declval<U>()), 3>
        bitwise_and_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] & rhs[0],
                lhs[1] & rhs[1],
                lhs[2] & rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() | std::declval<U>()), 3>
        bitwise_or_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs | rhs[0],
                lhs | rhs[1],
                lhs | rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() | std::declval<U>()), 3>
        bitwise_or_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] | rhs,
                lhs[1] | rhs,
                lhs[2] | rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() | std::declval<U>()), 3>
        bitwise_or_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] | rhs[0],
                lhs[1] | rhs[1],
                lhs[2] | rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() ^ std::declval<U>()), 3>
        bitwise_xor_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs ^ rhs[0],
                lhs ^ rhs[1],
                lhs ^ rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() ^ std::declval<U>()), 3>
        bitwise_xor_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs,
                lhs[1] ^ rhs,
                lhs[2] ^ rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() ^ std::declval<U>()), 3>
        bitwise_xor_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs[0],
                lhs[1] ^ rhs[1],
                lhs[2] ^ rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() << std::declval<U>()), 3>
        bitwise_shift_left_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs << rhs[0],
                lhs << rhs[1],
                lhs << rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() << std::declval<U>()), 3>
        bitwise_shift_left_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] << rhs,
                lhs[1] << rhs,
                lhs[2] << rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() << std::declval<U>()), 3>
        bitwise_shift_left_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] << rhs[0],
                lhs[1] << rhs[1],
                lhs[2] << rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() >> std::declval<U>()), 3>
        bitwise_shift_right_operator_xv(
            const T& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs >> rhs[0],
                lhs >> rhs[1],
                lhs >> rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() >> std::declval<U>()), 3>
        bitwise_shift_right_operator_vx(
            const vec<T, 3>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] >> rhs,
                lhs[1] >> rhs,
                lhs[2] >> rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr
            vec<decltype(std::declval<T>() >> std::declval<U>()), 3>
        bitwise_shift_right_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return {
                lhs[0] >> rhs[0],
                lhs[1] >> rhs[1],
                lhs[2] >> rhs[2],
            };
        }

        template<typename T, typename U>
        inline constexpr bool
        equality_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1]
                && lhs[2] == rhs[2];
        }

        template<typename T, typename U>
        inline constexpr bool
        inequality_operator_vv(
            const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1]
                || lhs[2] != rhs[2];
        }

        template<typename T>
        inline vec<T, 3> sin_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::sin(v[0]),
                tue::math::sin(v[1]),
                tue::math::sin(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> cos_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::cos(v[0]),
                tue::math::cos(v[1]),
                tue::math::cos(v[2]),
            };
        }

        template<typename T>
        inline void sincos_v(
            const vec<T, 3>& v,
            vec<T, 3>& sin_out,
            vec<T, 3>& cos_out) noexcept
        {
            tue::math::sincos(v[0], sin_out[0], cos_out[0]);
            tue::math::sincos(v[1], sin_out[1], cos_out[1]);
            tue::math::sincos(v[2], sin_out[2], cos_out[2]);
        }

        template<typename T>
        inline vec<T, 3> exp_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::exp(v[0]),
                tue::math::exp(v[1]),
                tue::math::exp(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> log_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::log(v[0]),
                tue::math::log(v[1]),
                tue::math::log(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> abs_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::abs(v[0]),
                tue::math::abs(v[1]),
                tue::math::abs(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> pow_vv(
            const vec<T, 3>& bases, const vec<T, 3>& exponents) noexcept
        {
            return {
                tue::math::pow(bases[0], exponents[0]),
                tue::math::pow(bases[1], exponents[1]),
                tue::math::pow(bases[2], exponents[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> recip_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::recip(v[0]),
                tue::math::recip(v[1]),
                tue::math::recip(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> sqrt_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::sqrt(v[0]),
                tue::math::sqrt(v[1]),
                tue::math::sqrt(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> rsqrt_v(const vec<T, 3>& v) noexcept
        {
            return {
                tue::math::rsqrt(v[0]),
                tue::math::rsqrt(v[1]),
                tue::math::rsqrt(v[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> min_vv(
            const vec<T, 3>& v1, const vec<T, 3>& v2) noexcept
        {
            return {
                tue::math::min(v1[0], v2[0]),
                tue::math::min(v1[1], v2[1]),
                tue::math::min(v1[2], v2[2]),
            };
        }

        template<typename T>
        inline vec<T, 3> max_vv(
            const vec<T, 3>& v1, const vec<T, 3>& v2) noexcept
        {
            return {
                tue::math::max(v1[0], v2[0]),
                tue::math::max(v1[1], v2[1]),
                tue::math::max(v1[2], v2[2]),
            };
        }

        template<typename T, typename U>
        inline vec<U, 3> mask_vv(
            const vec<T, 3>& conditions,
            const vec<U, 3>& values) noexcept
        {
            return {
                tue::math::mask(conditions[0], values[0]),
                tue::math::mask(conditions[1], values[1]),
                tue::math::mask(conditions[2], values[2]),
            };
        }

        template<typename T, typename U>
        inline vec<U, 3> select_vvv(
            const vec<T, 3>& conditions,
            const vec<U, 3>& values,
            const vec<U, 3>& otherwise) noexcept
        {
            return {
                tue::math::select(conditions[0], values[0], otherwise[0]),
                tue::math::select(conditions[1], values[1], otherwise[1]),
                tue::math::select(conditions[2], values[2], otherwise[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::less(
                std::declval<T>(), std::declval<T>())),
            3>
        less_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::less(lhs[0], rhs[0]),
                tue::math::less(lhs[1], rhs[1]),
                tue::math::less(lhs[2], rhs[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::less_equal(
                std::declval<T>(), std::declval<T>())),
            3>
        less_equal_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::less_equal(lhs[0], rhs[0]),
                tue::math::less_equal(lhs[1], rhs[1]),
                tue::math::less_equal(lhs[2], rhs[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::greater(
                std::declval<T>(), std::declval<T>())),
            3>
        greater_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::greater(lhs[0], rhs[0]),
                tue::math::greater(lhs[1], rhs[1]),
                tue::math::greater(lhs[2], rhs[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::greater_equal(
                std::declval<T>(), std::declval<T>())),
            3>
        greater_equal_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::greater_equal(lhs[0], rhs[0]),
                tue::math::greater_equal(lhs[1], rhs[1]),
                tue::math::greater_equal(lhs[2], rhs[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::equal(
                std::declval<T>(), std::declval<T>())),
            3>
        equal_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::equal(lhs[0], rhs[0]),
                tue::math::equal(lhs[1], rhs[1]),
                tue::math::equal(lhs[2], rhs[2]),
            };
        }

        template<typename T>
        inline vec<
            decltype(tue::math::not_equal(
                std::declval<T>(), std::declval<T>())),
            3>
        not_equal_vv(
            const vec<T, 3>& lhs, const vec<T, 3>& rhs) noexcept
        {
            return {
                tue::math::not_equal(lhs[0], rhs[0]),
                tue::math::not_equal(lhs[1], rhs[1]),
                tue::math::not_equal(lhs[2], rhs[2]),
            };
        }

        template<typename T, typename U>
        inline constexpr
            decltype(std::declval<T>() * std::declval<U>())
        dot_vv(const vec<T, 3>& lhs, const vec<U, 3>& rhs) noexcept
        {
            return lhs[0] * rhs[0]
                 + lhs[1] * rhs[1]
                 + lhs[2] * rhs[2];
        }

        template<typename T>
        inline constexpr T
        length2_v(const vec<T, 3>& v) noexcept
        {
            return v[0] * v[0]
                 + v[1] * v[1]
                 + v[2] * v[2];
        }

        template<typename T>
        struct vec_utils<T, 3>
        {
            template<typename X, typename Y, typename Z, typename W>
            static constexpr vec<T, 3> create(
                const X& x, const Y& y, const Z& z, const W&) noexcept
            {
                return {
                    tue::nocopy_cast<T>(x),
                    tue::nocopy_cast<T>(y),
                    tue::nocopy_cast<T>(z),
                };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 3> create(
                const vec2<U>& v, const Z& z, const W&) noexcept
            {
                return {
                    tue::nocopy_cast<T>(v[0]),
                    tue::nocopy_cast<T>(v[1]),
                    tue::nocopy_cast<T>(z),
                };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 3> create(
                const vec<U, 3>& v, const Z&, const W&) noexcept
            {
                return {
                    tue::nocopy_cast<T>(v[0]),
                    tue::nocopy_cast<T>(v[1]),
                    tue::nocopy_cast<T>(v[2]),
                };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 3> create(
                const vec4<U>& v, const Z&, const W&) noexcept
            {
                return {
                    tue::nocopy_cast<T>(v[0]),
                    tue::nocopy_cast<T>(v[1]),
                    tue::nocopy_cast<T>(v[2]),
                };
            }
        };
    }
}
