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

        explicit constexpr vec(const vec3<T>& v) noexcept :
            impl_({{ v[0], v[1] }})
        {
        }

        explicit constexpr vec(const vec4<T>& v) noexcept :
            impl_({{ v[0], v[1] }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec<U, 2>& v) noexcept :
            impl_({{ T(v[0]), T(v[1]) }})
        {
        }

        template<typename U>
        constexpr operator vec<U, 2>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        static constexpr vec<T, 2> zero() noexcept
        {
            return { T(0), T(0) };
        }

        static constexpr vec<T, 2> x_axis() noexcept
        {
            return { T(1), T(0) };
        }

        static constexpr vec<T, 2> y_axis() noexcept
        {
            return { T(0), T(1) };
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

        constexpr vec2<T> xy() const noexcept
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

        constexpr T r() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T g() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr vec2<T> rg() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
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

        vec<T, 2>& operator++() noexcept
        {
            ++this->impl_.data[0];
            ++this->impl_.data[1];
            return *this;
        }

        vec<T, 2> operator++(int) noexcept
        {
            return {
                this->impl_.data[0]++,
                this->impl_.data[1]++,
            };
        }

        vec<T, 2>& operator--() noexcept
        {
            --this->impl_.data[0];
            --this->impl_.data[1];
            return *this;
        }

        vec<T, 2> operator--(int) noexcept
        {
            return {
                this->impl_.data[0]--,
                this->impl_.data[1]--,
            };
        }

        template<typename U>
        vec<T, 2>& operator+=(const U& x) noexcept
        {
            this->impl_.data[0] += x;
            this->impl_.data[1] += x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator+=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] += v[0];
            this->impl_.data[1] += v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator-=(const U& x) noexcept
        {
            this->impl_.data[0] -= x;
            this->impl_.data[1] -= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator-=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] -= v[0];
            this->impl_.data[1] -= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator*=(const U& x) noexcept
        {
            this->impl_.data[0] *= x;
            this->impl_.data[1] *= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator*=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] *= v[0];
            this->impl_.data[1] *= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator*=(const mat<U, 2, 2>& m) noexcept
        {
            return (*this) = (*this) * m;
        }

        template<typename U>
        vec<T, 2>& operator/=(const U& x) noexcept
        {
            this->impl_.data[0] /= x;
            this->impl_.data[1] /= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator/=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] /= v[0];
            this->impl_.data[1] /= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator%=(const U& x) noexcept
        {
            this->impl_.data[0] %= x;
            this->impl_.data[1] %= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator%=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] %= v[0];
            this->impl_.data[1] %= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator&=(const U& x) noexcept
        {
            this->impl_.data[0] &= x;
            this->impl_.data[1] &= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator&=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] &= v[0];
            this->impl_.data[1] &= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator|=(const U& x) noexcept
        {
            this->impl_.data[0] |= x;
            this->impl_.data[1] |= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator|=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] |= v[0];
            this->impl_.data[1] |= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator^=(const U& x) noexcept
        {
            this->impl_.data[0] ^= x;
            this->impl_.data[1] ^= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator^=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] ^= v[0];
            this->impl_.data[1] ^= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator<<=(const U& x) noexcept
        {
            this->impl_.data[0] <<= x;
            this->impl_.data[1] <<= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator<<=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] <<= v[0];
            this->impl_.data[1] <<= v[1];
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator>>=(const U& x) noexcept
        {
            this->impl_.data[0] >>= x;
            this->impl_.data[1] >>= x;
            return *this;
        }

        template<typename U>
        vec<T, 2>& operator>>=(const vec<U, 2>& v) noexcept
        {
            this->impl_.data[0] >>= v[0];
            this->impl_.data[1] >>= v[1];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T>
        inline constexpr vec<decltype(+std::declval<T>()), 2>
        unary_plus_operator(const vec<T, 2>& v) noexcept
        {
            return { +v[0], +v[1] };
        }

        template<typename T>
        inline constexpr vec<decltype(-std::declval<T>()), 2>
        unary_minus_operator(const vec<T, 2>& v) noexcept
        {
            return { -v[0], -v[1] };
        }

        template<typename T>
        inline constexpr vec<decltype(~std::declval<T>()), 2>
        bitwise_not_operator(const vec<T, 2>& v) noexcept
        {
            return { ~v[0], ~v[1] };
        }

        template<typename T>
        inline constexpr vec<decltype(!std::declval<T>()), 2>
        logical_not_operator(const vec<T, 2>& v) noexcept
        {
            return { !v[0], !v[1] };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() + std::declval<U>()), 2>
        addition_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() + std::declval<U>()), 2>
        addition_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() + std::declval<U>()), 2>
        addition_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() - std::declval<U>()), 2>
        subtraction_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() - std::declval<U>()), 2>
        subtraction_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() - std::declval<U>()), 2>
        subtraction_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() * std::declval<U>()), 2>
        multiplication_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs * rhs[0],
                lhs * rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() * std::declval<U>()), 2>
        multiplication_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] * rhs,
                lhs[1] * rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() * std::declval<U>()), 2>
        multiplication_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] * rhs[0],
                lhs[1] * rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() / std::declval<U>()), 2>
        division_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs / rhs[0],
                lhs / rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() / std::declval<U>()), 2>
        division_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] / rhs,
                lhs[1] / rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() / std::declval<U>()), 2>
        division_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] / rhs[0],
                lhs[1] / rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() % std::declval<U>()), 2>
        modulo_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs % rhs[0],
                lhs % rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() % std::declval<U>()), 2>
        modulo_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] % rhs,
                lhs[1] % rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() % std::declval<U>()), 2>
        modulo_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] % rhs[0],
                lhs[1] % rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() & std::declval<U>()), 2>
        bitwise_and_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs & rhs[0],
                lhs & rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() & std::declval<U>()), 2>
        bitwise_and_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] & rhs,
                lhs[1] & rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() & std::declval<U>()), 2>
        bitwise_and_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] & rhs[0],
                lhs[1] & rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() | std::declval<U>()), 2>
        bitwise_or_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs | rhs[0],
                lhs | rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() | std::declval<U>()), 2>
        bitwise_or_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] | rhs,
                lhs[1] | rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() | std::declval<U>()), 2>
        bitwise_or_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] | rhs[0],
                lhs[1] | rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() ^ std::declval<U>()), 2>
        bitwise_xor_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs ^ rhs[0],
                lhs ^ rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() ^ std::declval<U>()), 2>
        bitwise_xor_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs,
                lhs[1] ^ rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() ^ std::declval<U>()), 2>
        bitwise_xor_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs[0],
                lhs[1] ^ rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() << std::declval<U>()), 2>
        bitwise_shift_left_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs << rhs[0],
                lhs << rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() << std::declval<U>()), 2>
        bitwise_shift_left_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] << rhs,
                lhs[1] << rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() << std::declval<U>()), 2>
        bitwise_shift_left_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] << rhs[0],
                lhs[1] << rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() >> std::declval<U>()), 2>
        bitwise_shift_right_operator(
            const T& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs >> rhs[0],
                lhs >> rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() >> std::declval<U>()), 2>
        bitwise_shift_right_operator(
            const vec<T, 2>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] >> rhs,
                lhs[1] >> rhs,
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            std::declval<T>() >> std::declval<U>()), 2>
        bitwise_shift_right_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                lhs[0] >> rhs[0],
                lhs[1] >> rhs[1],
            };
        }

        template<typename T, typename U>
        inline constexpr bool equality_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1];
        }

        template<typename T, typename U>
        inline constexpr bool inequality_operator(
            const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1];
        }

        template<typename T>
        inline vec<decltype(tue::math::sin(std::declval<T>())), 2>
        sin(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::sin(v[0]),
                tue::math::sin(v[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::cos(std::declval<T>())), 2>
        cos(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::cos(v[0]),
                tue::math::cos(v[1]),
            };
        }

        template<typename T>
        inline void sincos(
            const vec<T, 2>& v,
            decltype(tue::detail_::sin(v))& sin_out,
            decltype(tue::detail_::cos(v))& cos_out) noexcept
        {
            tue::math::sincos(v[0], sin_out[0], cos_out[0]);
            tue::math::sincos(v[1], sin_out[1], cos_out[1]);
        }

        template<typename T>
        inline vec<decltype(tue::math::exp(std::declval<T>())), 2>
        exp(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::exp(v[0]),
                tue::math::exp(v[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::log(std::declval<T>())), 2>
        log(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::log(v[0]),
                tue::math::log(v[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::abs(std::declval<T>())), 2>
        abs(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::abs(v[0]),
                tue::math::abs(v[1]),
            };
        }

        template<typename T, typename U>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), 2>
        pow(const T& base, const vec<U, 2>& exponents) noexcept
        {
            return {
                tue::math::pow(base, exponents[0]),
                tue::math::pow(base, exponents[1]),
            };
        }

        template<typename T, typename U>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), 2>
        pow(const vec<T, 2>& bases, const U& exponent) noexcept
        {
            return {
                tue::math::pow(bases[0], exponent),
                tue::math::pow(bases[1], exponent),
            };
        }

        template<typename T, typename U>
        inline vec<decltype(
            tue::math::pow(std::declval<T>(), std::declval<U>())), 2>
        pow(const vec<T, 2>& bases, const vec<U, 2>& exponents) noexcept
        {
            return {
                tue::math::pow(bases[0], exponents[0]),
                tue::math::pow(bases[1], exponents[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::recip(std::declval<T>())), 2>
        recip(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::recip(v[0]),
                tue::math::recip(v[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::sqrt(std::declval<T>())), 2>
        sqrt(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::sqrt(v[0]),
                tue::math::sqrt(v[1]),
            };
        }

        template<typename T>
        inline vec<decltype(tue::math::rsqrt(std::declval<T>())), 2>
        rsqrt(const vec<T, 2>& v) noexcept
        {
            return {
                tue::math::rsqrt(v[0]),
                tue::math::rsqrt(v[1]),
            };
        }

        template<typename T>
        inline vec<T, 2> min(const vec<T, 2>& v1, const vec<T, 2>& v2) noexcept
        {
            return {
                tue::math::min(v1[0], v2[0]),
                tue::math::min(v1[1], v2[1]),
            };
        }

        template<typename T>
        inline vec<T, 2> max(const vec<T, 2>& v1, const vec<T, 2>& v2) noexcept
        {
            return {
                tue::math::max(v1[0], v2[0]),
                tue::math::max(v1[1], v2[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        dot(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return lhs[0] * rhs[0]
                 + lhs[1] * rhs[1];
        }

        template<typename T>
        inline constexpr T length2(const vec<T, 2>& v) noexcept
        {
            return v[0] * v[0]
                 + v[1] * v[1];
        }

        template<typename T, typename U>
        inline constexpr vec<U, 2> select(
            const vec<T, 2>& conditions,
            const vec<U, 2>& values,
            const vec<U, 2>& otherwise) noexcept
        {
            return {
                tue::math::select(conditions[0], values[0], otherwise[0]),
                tue::math::select(conditions[1], values[1], otherwise[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::less(std::declval<T>(), std::declval<U>())), 2>
        less(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::less(lhs[0], rhs[0]),
                tue::math::less(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::less_equal(std::declval<T>(), std::declval<U>())), 2>
        less_equal(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::less_equal(lhs[0], rhs[0]),
                tue::math::less_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::greater(std::declval<T>(), std::declval<U>())), 2>
        greater(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::greater(lhs[0], rhs[0]),
                tue::math::greater(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::greater_equal(std::declval<T>(), std::declval<U>())), 2>
        greater_equal(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::greater_equal(lhs[0], rhs[0]),
                tue::math::greater_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::equal(std::declval<T>(), std::declval<U>())), 2>
        equal(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::equal(lhs[0], rhs[0]),
                tue::math::equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U>
        inline constexpr vec<decltype(
            tue::math::not_equal(std::declval<T>(), std::declval<U>())), 2>
        not_equal(const vec<T, 2>& lhs, const vec<U, 2>& rhs) noexcept
        {
            return {
                tue::math::not_equal(lhs[0], rhs[0]),
                tue::math::not_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T>
        struct vec_utils<T, 2>
        {
            template<typename X, typename Y, typename Z, typename W>
            static constexpr vec<T, 2> create(
                const X& x, const Y& y, const Z&, const W&) noexcept
            {
                return { T(x), T(y) };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 2> create(
                const vec<U, 2>& v, const Z&, const W&) noexcept
            {
                return { T(v[0]), T(v[1]) };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 2> create(
                const vec3<U>& v, const Z&, const W&) noexcept
            {
                return { T(v[0]), T(v[1]) };
            }

            template<typename U, typename Z, typename W>
            static constexpr vec<T, 2> create(
                const vec4<U>& v, const Z&, const W&) noexcept
            {
                return { T(v[0]), T(v[1]) };
            }
        };
    }
}
