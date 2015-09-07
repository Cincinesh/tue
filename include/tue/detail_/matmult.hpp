//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <utility>

#include "../mat.hpp"
#include "../vec.hpp"

namespace tue
{
    namespace detail_
    {
        template<typename T, typename U, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mv(
            const mat<T, 2, R>& lhs, const vec<U, 2>& rhs, int j) noexcept
        {
            return lhs[0][j] * rhs[0]
                 + lhs[1][j] * rhs[1];
        }

        template<typename T, typename U, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mv(
            const mat<T, 3, R>& lhs, const vec<U, 3>& rhs, int j) noexcept
        {
            return lhs[0][j] * rhs[0]
                 + lhs[1][j] * rhs[1]
                 + lhs[2][j] * rhs[2];
        }

        template<typename T, typename U, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mv(
            const mat<T, 4, R>& lhs, const vec<U, 4>& rhs, int j) noexcept
        {
            return lhs[0][j] * rhs[0]
                 + lhs[1][j] * rhs[1]
                 + lhs[2][j] * rhs[2]
                 + lhs[3][j] * rhs[3];
        }

        template<typename T, typename U, int C, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mm(
            const mat<T, 2, R>& lhs, const mat<U, C, 2>& rhs,
            int i, int j) noexcept
        {
            return lhs[0][j] * rhs[i][0]
                 + lhs[1][j] * rhs[i][1];
        }

        template<typename T, typename U, int C, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mm(
            const mat<T, 3, R>& lhs, const mat<U, C, 3>& rhs,
            int i, int j) noexcept
        {
            return lhs[0][j] * rhs[i][0]
                 + lhs[1][j] * rhs[i][1]
                 + lhs[2][j] * rhs[i][2];
        }

        template<typename T, typename U, int C, int R>
        inline constexpr decltype(std::declval<T>() * std::declval<U>())
        matmult_component_mm(
            const mat<T, 4, R>& lhs, const mat<U, C, 4>& rhs,
            int i, int j) noexcept
        {
            return lhs[0][j] * rhs[i][0]
                 + lhs[1][j] * rhs[i][1]
                 + lhs[2][j] * rhs[i][2]
                 + lhs[3][j] * rhs[i][3];
        }

        template<typename T, typename U, int C, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 2>
        matmult_column_mm(
            const mat<T, N, 2>& lhs, const mat<U, C, N>& rhs, int i) noexcept
        {
            return {
                tue::detail_::matmult_component_mm(lhs, rhs, i, 0),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 1),
            };
        }

        template<typename T, typename U, int C, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        matmult_column_mm(
            const mat<T, N, 3>& lhs, const mat<U, C, N>& rhs, int i) noexcept
        {
            return {
                tue::detail_::matmult_component_mm(lhs, rhs, i, 0),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 1),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 2),
            };
        }

        template<typename T, typename U, int C, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 4>
        matmult_column_mm(
            const mat<T, N, 4>& lhs, const mat<U, C, N>& rhs, int i) noexcept
        {
            return {
                tue::detail_::matmult_component_mm(lhs, rhs, i, 0),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 1),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 2),
                tue::detail_::matmult_component_mm(lhs, rhs, i, 3),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 2>
        multiplication_operator_vm(
            const vec<T, N>& lhs, const mat<U, 2, N>& rhs) noexcept
        {
            return {
                tue::detail_::dot_vv(lhs, rhs[0]),
                tue::detail_::dot_vv(lhs, rhs[1]),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        multiplication_operator_vm(
            const vec<T, N>& lhs, const mat<U, 3, N>& rhs) noexcept
        {
            return {
                tue::detail_::dot_vv(lhs, rhs[0]),
                tue::detail_::dot_vv(lhs, rhs[1]),
                tue::detail_::dot_vv(lhs, rhs[2]),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 4>
        multiplication_operator_vm(
            const vec<T, N>& lhs, const mat<U, 4, N>& rhs) noexcept
        {
            return {
                tue::detail_::dot_vv(lhs, rhs[0]),
                tue::detail_::dot_vv(lhs, rhs[1]),
                tue::detail_::dot_vv(lhs, rhs[2]),
                tue::detail_::dot_vv(lhs, rhs[3]),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 2>
        multiplication_operator_mv(
            const mat<T, N, 2>& lhs, const vec<U, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_component_mv(lhs, rhs, 0),
                tue::detail_::matmult_component_mv(lhs, rhs, 1),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 3>
        multiplication_operator_mv(
            const mat<T, N, 3>& lhs, const vec<U, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_component_mv(lhs, rhs, 0),
                tue::detail_::matmult_component_mv(lhs, rhs, 1),
                tue::detail_::matmult_component_mv(lhs, rhs, 2),
            };
        }

        template<typename T, typename U, int N>
        inline constexpr vec<decltype(std::declval<T>() * std::declval<U>()), 4>
        multiplication_operator_mv(
            const mat<T, N, 4>& lhs, const vec<U, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_component_mv(lhs, rhs, 0),
                tue::detail_::matmult_component_mv(lhs, rhs, 1),
                tue::detail_::matmult_component_mv(lhs, rhs, 2),
                tue::detail_::matmult_component_mv(lhs, rhs, 3),
            };
        }

        template<typename T, typename U, int N, int R>
        inline constexpr mat<decltype(
            std::declval<T>() * std::declval<U>()), 2, R>
        multiplication_operator_mm(
            const mat<T, N, R>& lhs, const mat<U, 2, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_column_mm(lhs, rhs, 0),
                tue::detail_::matmult_column_mm(lhs, rhs, 1),
            };
        }

        template<typename T, typename U, int N, int R>
        inline constexpr mat<decltype(
            std::declval<T>() * std::declval<U>()), 3, R>
        multiplication_operator_mm(
            const mat<T, N, R>& lhs, const mat<U, 3, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_column_mm(lhs, rhs, 0),
                tue::detail_::matmult_column_mm(lhs, rhs, 1),
                tue::detail_::matmult_column_mm(lhs, rhs, 2),
            };
        }

        template<typename T, typename U, int N, int R>
        inline constexpr mat<decltype(
            std::declval<T>() * std::declval<U>()), 4, R>
        multiplication_operator_mm(
            const mat<T, N, R>& lhs, const mat<U, 4, N>& rhs) noexcept
        {
            return {
                tue::detail_::matmult_column_mm(lhs, rhs, 0),
                tue::detail_::matmult_column_mm(lhs, rhs, 1),
                tue::detail_::matmult_column_mm(lhs, rhs, 2),
                tue::detail_::matmult_column_mm(lhs, rhs, 3),
            };
        }
    }
}
