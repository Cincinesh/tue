//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../mat.hpp"
#include "../vec.hpp"

namespace tue
{
    template<typename T, int R>
    class mat<T, 4, R>
    {
        struct { vec<T, R> columns[4]; } impl_;

    public:
        using component_type = T;

        static constexpr int column_count = 4;

        static constexpr int row_count = R;

        static constexpr int component_count = 4 * R;

        mat() noexcept = default;

        template<typename U>
        explicit constexpr mat(const U& x) noexcept;

        constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1,
            const vec<T, R>& c2,
            const vec<T, R>& c3) noexcept;

        template<typename MT, int MC, int MR>
        explicit constexpr mat(const mat<MT, MC, MR>& m) noexcept;

        template<typename U>
        constexpr operator mat<U, 4, R>() const noexcept;

        static constexpr mat<T, 4, R> identity() noexcept;

        static constexpr mat<T, 4, R> zero() noexcept;

        template<typename I>
        constexpr const vec<T, R>& operator[](const I& i) const noexcept;

        template<typename I>
        vec<T, R>& operator[](const I& i) noexcept;

        const T* data() const noexcept;

        T* data() noexcept;

        const vec<T, R>* columns() const noexcept;

        vec<T, R>* columns() noexcept;

        template<typename I>
        constexpr vec<T, R> column(const I& i) const noexcept;

        template<typename J>
        constexpr vec<T, 4> row(const J& j) const noexcept;

        mat<T, 4, R>& operator++() noexcept;

        mat<T, 4, R> operator++(int) noexcept;

        mat<T, 4, R>& operator--() noexcept;

        mat<T, 4, R> operator--(int) noexcept;

        template<typename U>
        mat<T, 4, R>& operator+=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator+=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator-=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator-=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator*=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator*=(const mat<U, 4, 4>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator/=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator/=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator%=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator%=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator&=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator&=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator|=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator|=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator^=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator^=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator<<=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator<<=(const mat<U, 4, R>& m) noexcept;

        template<typename U>
        mat<T, 4, R>& operator>>=(const U& x) noexcept;

        template<typename U>
        mat<T, 4, R>& operator>>=(const mat<U, 4, R>& m) noexcept;
    };
}
