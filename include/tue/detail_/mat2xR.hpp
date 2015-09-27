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

#include "../mat.hpp"
#include "../math.hpp"
#include "../vec.hpp"

namespace tue
{
    template<typename T, int R>
    class mat<T, 2, R>
    {
        struct
        {
            std::enable_if_t<
                is_vec_component<T>::value && (R >= 2 && R <= 4),
                vec<T, R>[2]>
            columns;
        }
        impl_;

    public:
        using component_type = T;

        static constexpr int column_count = 2;

        static constexpr int row_count = R;

        static constexpr int component_count = 2 * R;

        mat() noexcept = default;

        explicit constexpr mat(
            const T& x) noexcept
        :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(x, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, x, 0, 0),
            }})
        {
        }

        explicit constexpr mat(
            const vec<T, R>& c) noexcept
        :
            impl_({{ c, c }})
        {
        }

        constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1) noexcept
        :
            impl_({{ c0, c1 }})
        {
        }

        template<int MC, int MR>
        explicit constexpr mat(const mat<T, MC, MR>& m) noexcept
        :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(m[0], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[1], 0, 0),
            }})
        {
        }

        template<typename U>
        explicit constexpr mat(const mat<U, 2, R>& m) noexcept
        :
            impl_({{
                vec<T, R>(m[0]),
                vec<T, R>(m[1]),
            }})
        {
        }

        template<typename U>
        constexpr operator mat<U, 2, R>() const noexcept
        {
            return {
                this->impl_.columns[0],
                this->impl_.columns[1],
            };
        }

        static constexpr mat<T, 2, R> fill(const T& x) noexcept
        {
            return { vec<T, R>(x), vec<T, R>(x) };
        }

        static constexpr mat<T, 2, R> identity() noexcept
        {
            return {
                tue::detail_::vec_utils<T, R>::create(1, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 1, 0, 0),
            };
        }

        static constexpr mat<T, 2, R> zero() noexcept
        {
            return {
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 0),
            };
        }

        template<typename I>
        constexpr const vec<T, R>& operator[](const I& i) const noexcept
        {
            return this->impl_.columns[i];
        }

        template<typename I>
        vec<T, R>& operator[](const I& i) noexcept
        {
            return this->impl_.columns[i];
        }

        const T* data() const noexcept
        {
            return this->impl_.columns[0].data();
        }

        T* data() noexcept
        {
            return this->impl_.columns[0].data();
        }

        const vec<T, R>* columns() const noexcept
        {
            return this->impl_.columns;
        }

        vec<T, R>* columns() noexcept
        {
            return this->impl_.columns;
        }

        template<typename I>
        constexpr vec<T, R> column(const I& i) const noexcept
        {
            return this->impl_.columns[i];
        }

        template<typename I>
        void set_column(const I& i, const vec<T, R>& v) noexcept
        {
            this->impl_.columns[i] = v;
        }

        template<typename J>
        constexpr vec<T, 2> row(const J& j) const noexcept
        {
            return {
                this->impl_.columns[0][j],
                this->impl_.columns[1][j],
            };
        }

        template<typename J>
        void set_row(const J& j, const vec<T, 2>& v) noexcept
        {
            this->impl_.columns[0][j] = v[0];
            this->impl_.columns[1][j] = v[1];
        }

        mat<T, 2, R>& operator++() noexcept
        {
            ++this->impl_.columns[0];
            ++this->impl_.columns[1];
            return *this;
        }

        mat<T, 2, R> operator++(int) noexcept
        {
            return {
                this->impl_.columns[0]++,
                this->impl_.columns[1]++,
            };
        }

        mat<T, 2, R>& operator--() noexcept
        {
            --this->impl_.columns[0];
            --this->impl_.columns[1];
            return *this;
        }

        mat<T, 2, R> operator--(int) noexcept
        {
            return {
                this->impl_.columns[0]--,
                this->impl_.columns[1]--,
            };
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator+=(const U& x) noexcept
        {
            this->impl_.columns[0] += x;
            this->impl_.columns[1] += x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator+=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] += m[0];
            this->impl_.columns[1] += m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator-=(const U& x) noexcept
        {
            this->impl_.columns[0] -= x;
            this->impl_.columns[1] -= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator-=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] -= m[0];
            this->impl_.columns[1] -= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator*=(const U& x) noexcept
        {
            this->impl_.columns[0] *= x;
            this->impl_.columns[1] *= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator*=(const mat<U, 2, 2>& m) noexcept
        {
            return (*this) = (*this) * m;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator/=(const U& x) noexcept
        {
            this->impl_.columns[0] /= x;
            this->impl_.columns[1] /= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator/=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] /= m[0];
            this->impl_.columns[1] /= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator%=(const U& x) noexcept
        {
            this->impl_.columns[0] %= x;
            this->impl_.columns[1] %= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator%=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] %= m[0];
            this->impl_.columns[1] %= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator&=(const U& x) noexcept
        {
            this->impl_.columns[0] &= x;
            this->impl_.columns[1] &= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator&=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] &= m[0];
            this->impl_.columns[1] &= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator|=(const U& x) noexcept
        {
            this->impl_.columns[0] |= x;
            this->impl_.columns[1] |= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator|=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] |= m[0];
            this->impl_.columns[1] |= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator^=(const U& x) noexcept
        {
            this->impl_.columns[0] ^= x;
            this->impl_.columns[1] ^= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator^=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] ^= m[0];
            this->impl_.columns[1] ^= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator<<=(const U& x) noexcept
        {
            this->impl_.columns[0] <<= x;
            this->impl_.columns[1] <<= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator<<=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] <<= m[0];
            this->impl_.columns[1] <<= m[1];
            return *this;
        }

        template<typename U>
        std::enable_if_t<is_vec_component<U>::value, mat<T, 2, R>&>
        operator>>=(const U& x) noexcept
        {
            this->impl_.columns[0] >>= x;
            this->impl_.columns[1] >>= x;
            return *this;
        }

        template<typename U>
        mat<T, 2, R>&
        operator>>=(const mat<U, 2, R>& m) noexcept
        {
            this->impl_.columns[0] >>= m[0];
            this->impl_.columns[1] >>= m[1];
            return *this;
        }
    };

    namespace detail_
    {
        template<typename T, int R>
        inline constexpr
            mat<decltype(+std::declval<T>()), 2, R>
        unary_plus_operator_m(const mat<T, 2, R>& m) noexcept
        {
            return { +m[0], +m[1] };
        }

        template<typename T, int R>
        inline constexpr
            mat<decltype(-std::declval<T>()), 2, R>
        unary_minus_operator_m(const mat<T, 2, R>& m) noexcept
        {
            return { -m[0], -m[1] };
        }

        template<typename T, int R>
        inline constexpr
            mat<decltype(~std::declval<T>()), 2, R>
        bitwise_not_operator_m(const mat<T, 2, R>& m) noexcept
        {
            return { ~m[0], ~m[1] };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() + std::declval<U>()), 2, R>
        addition_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs + rhs[0],
                lhs + rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() + std::declval<U>()), 2, R>
        addition_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] + rhs,
                lhs[1] + rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() + std::declval<U>()), 2, R>
        addition_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] + rhs[0],
                lhs[1] + rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() - std::declval<U>()), 2, R>
        subtraction_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs - rhs[0],
                lhs - rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() - std::declval<U>()), 2, R>
        subtraction_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] - rhs,
                lhs[1] - rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() - std::declval<U>()), 2, R>
        subtraction_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] - rhs[0],
                lhs[1] - rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() * std::declval<U>()), 2, R>
        multiplication_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs * rhs[0],
                lhs * rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() * std::declval<U>()), 2, R>
        multiplication_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] * rhs,
                lhs[1] * rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() / std::declval<U>()), 2, R>
        division_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs / rhs[0],
                lhs / rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() / std::declval<U>()), 2, R>
        division_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] / rhs,
                lhs[1] / rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() / std::declval<U>()), 2, R>
        division_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] / rhs[0],
                lhs[1] / rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() % std::declval<U>()), 2, R>
        modulo_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs % rhs[0],
                lhs % rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() % std::declval<U>()), 2, R>
        modulo_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] % rhs,
                lhs[1] % rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() % std::declval<U>()), 2, R>
        modulo_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] % rhs[0],
                lhs[1] % rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() & std::declval<U>()), 2, R>
        bitwise_and_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs & rhs[0],
                lhs & rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() & std::declval<U>()), 2, R>
        bitwise_and_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] & rhs,
                lhs[1] & rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() & std::declval<U>()), 2, R>
        bitwise_and_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] & rhs[0],
                lhs[1] & rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() | std::declval<U>()), 2, R>
        bitwise_or_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs | rhs[0],
                lhs | rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() | std::declval<U>()), 2, R>
        bitwise_or_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] | rhs,
                lhs[1] | rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() | std::declval<U>()), 2, R>
        bitwise_or_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] | rhs[0],
                lhs[1] | rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() ^ std::declval<U>()), 2, R>
        bitwise_xor_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs ^ rhs[0],
                lhs ^ rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() ^ std::declval<U>()), 2, R>
        bitwise_xor_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs,
                lhs[1] ^ rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() ^ std::declval<U>()), 2, R>
        bitwise_xor_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] ^ rhs[0],
                lhs[1] ^ rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() << std::declval<U>()), 2, R>
        bitwise_shift_left_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs << rhs[0],
                lhs << rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() << std::declval<U>()), 2, R>
        bitwise_shift_left_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] << rhs,
                lhs[1] << rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() << std::declval<U>()), 2, R>
        bitwise_shift_left_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] << rhs[0],
                lhs[1] << rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() >> std::declval<U>()), 2, R>
        bitwise_shift_right_operator_xm(
            const T& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs >> rhs[0],
                lhs >> rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() >> std::declval<U>()), 2, R>
        bitwise_shift_right_operator_mx(
            const mat<T, 2, R>& lhs, const U& rhs) noexcept
        {
            return {
                lhs[0] >> rhs,
                lhs[1] >> rhs,
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() >> std::declval<U>()), 2, R>
        bitwise_shift_right_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] >> rhs[0],
                lhs[1] >> rhs[1],
            };
        }

        template<typename T, typename U, int R>
        inline constexpr bool
        equality_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1];
        }

        template<typename T, typename U, int R>
        inline constexpr bool
        inequality_operator_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return lhs[0] != rhs[0]
                || lhs[1] != rhs[1];
        }

        template<typename T, int R>
        inline mat<T, 2, R> sin_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::sin(m[0]),
                tue::math::sin(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> cos_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::cos(m[0]),
                tue::math::cos(m[1]),
            };
        }

        template<typename T, int R>
        inline void sincos_m(
            const mat<T, 2, R>& m,
            mat<T, 2, R>& sin_out,
            mat<T, 2, R>& cos_out) noexcept
        {
            tue::math::sincos(m[0], sin_out[0], cos_out[0]);
            tue::math::sincos(m[1], sin_out[1], cos_out[1]);
        }

        template<typename T, int R>
        inline mat<T, 2, R> exp_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::exp(m[0]),
                tue::math::exp(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> log_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::log(m[0]),
                tue::math::log(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> abs_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::abs(m[0]),
                tue::math::abs(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> pow_mm(
            const mat<T, 2, R>& bases, const mat<T, 2, R>& exponents) noexcept
        {
            return {
                tue::math::pow(bases[0], exponents[0]),
                tue::math::pow(bases[1], exponents[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> recip_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::recip(m[0]),
                tue::math::recip(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> sqrt_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::sqrt(m[0]),
                tue::math::sqrt(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> rsqrt_m(const mat<T, 2, R>& m) noexcept
        {
            return {
                tue::math::rsqrt(m[0]),
                tue::math::rsqrt(m[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> min_mm(
            const mat<T, 2, R>& m1, const mat<T, 2, R>& m2) noexcept
        {
            return {
                tue::math::min(m1[0], m2[0]),
                tue::math::min(m1[1], m2[1]),
            };
        }

        template<typename T, int R>
        inline mat<T, 2, R> max_mm(
            const mat<T, 2, R>& m1, const mat<T, 2, R>& m2) noexcept
        {
            return {
                tue::math::max(m1[0], m2[0]),
                tue::math::max(m1[1], m2[1]),
            };
        }

        template<typename T, typename U, int R>
        inline mat<U, 2, R> mask_mm(
            const mat<T, 2, R>& conditions,
            const mat<U, 2, R>& values) noexcept
        {
            return {
                tue::math::mask(conditions[0], values[0]),
                tue::math::mask(conditions[1], values[1]),
            };
        }

        template<typename T, typename U, int R>
        inline mat<U, 2, R> select_mmm(
            const mat<T, 2, R>& conditions,
            const mat<U, 2, R>& values,
            const mat<U, 2, R>& otherwise) noexcept
        {
            return {
                tue::math::select(conditions[0], values[0], otherwise[0]),
                tue::math::select(conditions[1], values[1], otherwise[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::less(
                std::declval<T>(), std::declval<T>())),
            2, R>
        less_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::less(lhs[0], rhs[0]),
                tue::math::less(lhs[1], rhs[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::less_equal(
                std::declval<T>(), std::declval<T>())),
            2, R>
        less_equal_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::less_equal(lhs[0], rhs[0]),
                tue::math::less_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::greater(
                std::declval<T>(), std::declval<T>())),
            2, R>
        greater_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::greater(lhs[0], rhs[0]),
                tue::math::greater(lhs[1], rhs[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::greater_equal(
                std::declval<T>(), std::declval<T>())),
            2, R>
        greater_equal_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::greater_equal(lhs[0], rhs[0]),
                tue::math::greater_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::equal(
                std::declval<T>(), std::declval<T>())),
            2, R>
        equal_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::equal(lhs[0], rhs[0]),
                tue::math::equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, int R>
        inline mat<
            decltype(tue::math::not_equal(
                std::declval<T>(), std::declval<T>())),
            2, R>
        not_equal_mm(
            const mat<T, 2, R>& lhs, const mat<T, 2, R>& rhs) noexcept
        {
            return {
                tue::math::not_equal(lhs[0], rhs[0]),
                tue::math::not_equal(lhs[1], rhs[1]),
            };
        }

        template<typename T, typename U, int R>
        inline constexpr
            mat<decltype(std::declval<T>() * std::declval<U>()), 2, R>
        comp_mult_mm(
            const mat<T, 2, R>& lhs, const mat<U, 2, R>& rhs) noexcept
        {
            return {
                lhs[0] * rhs[0],
                lhs[1] * rhs[1],
            };
        }

        template<typename T>
        inline constexpr mat<T, 2, 2>
        transpose_m(const mat<T, 2, 2>& m) noexcept
        {
            return {
                { m[0][0], m[1][0] },
                { m[0][1], m[1][1] },
            };
        }

        template<typename T>
        inline constexpr mat<T, 3, 2>
        transpose_m(const mat<T, 2, 3>& m) noexcept
        {
            return {
                { m[0][0], m[1][0] },
                { m[0][1], m[1][1] },
                { m[0][2], m[1][2] },
            };
        }

        template<typename T>
        inline constexpr mat<T, 4, 2>
        transpose_m(const mat<T, 2, 4>& m) noexcept
        {
            return {
                { m[0][0], m[1][0] },
                { m[0][1], m[1][1] },
                { m[0][2], m[1][2] },
                { m[0][3], m[1][3] },
            };
        }

        template<typename T, int R>
        struct mat_utils<T, 2, R>
        {
            template<
                typename M00, typename M01, typename M02, typename M03,
                typename M10, typename M11, typename M12, typename M13,
                typename M20, typename M21, typename M22, typename M23,
                typename M30, typename M31, typename M32, typename M33>
            static constexpr mat<T, 2, R> create(
                const M00& m00, const M01& m01, const M02& m02, const M03& m03,
                const M10& m10, const M11& m11, const M12& m12, const M13& m13,
                const M20&, const M21&, const M22&, const M23&,
                const M30&, const M31&, const M32&, const M33&) noexcept
            {
                return {
                    tue::detail_::vec_utils<T, R>::create(m00, m01, m02, m03),
                    tue::detail_::vec_utils<T, R>::create(m10, m11, m12, m13),
                };
            }
        };
    }
}
