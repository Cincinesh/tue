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
        explicit constexpr mat(const U& x) noexcept :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(x, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, x, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, x, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, x),
            }})
        {
        }

        constexpr mat(
            const vec<T, R>& c0,
            const vec<T, R>& c1,
            const vec<T, R>& c2,
            const vec<T, R>& c3) noexcept :
            impl_({{ c0, c1, c2, c3 }})
        {
        }

        template<typename MT, int MR>
        explicit constexpr mat(const mat<MT, 2, MR>& m) noexcept :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(m[0], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[1], 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 1, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 1),
            }})
        {
        }

        template<typename MT, int MR>
        explicit constexpr mat(const mat<MT, 3, MR>& m) noexcept :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(m[0], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[1], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[2], 1, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 1),
            }})
        {
        }

        template<typename MT, int MR>
        explicit constexpr mat(const mat<MT, 4, MR>& m) noexcept :
            impl_({{
                tue::detail_::vec_utils<T, R>::create(m[0], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[1], 0, 0),
                tue::detail_::vec_utils<T, R>::create(m[2], 1, 0),
                tue::detail_::vec_utils<T, R>::create(m[3], 0, 1),
            }})
        {
        }

        template<typename U>
        constexpr operator mat<U, 4, R>() const noexcept
        {
            return {
                this->impl_.columns[0],
                this->impl_.columns[1],
                this->impl_.columns[2],
                this->impl_.columns[3],
            };
        }

        static constexpr mat<T, 4, R> identity() noexcept
        {
            return {
                tue::detail_::vec_utils<T, R>::create(1, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 1, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 1, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 1),
            };
        }

        static constexpr mat<T, 4, R> zero() noexcept
        {
            return {
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 0),
                tue::detail_::vec_utils<T, R>::create(0, 0, 0, 0),
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

        template<typename J>
        constexpr vec<T, 4> row(const J& j) const noexcept
        {
            return {
                this->impl_.columns[0][j],
                this->impl_.columns[1][j],
                this->impl_.columns[2][j],
                this->impl_.columns[3][j],
            };
        }

        mat<T, 4, R>& operator++() noexcept
        {
            ++this->impl_.columns[0];
            ++this->impl_.columns[1];
            ++this->impl_.columns[2];
            ++this->impl_.columns[3];
            return *this;
        }

        mat<T, 4, R> operator++(int) noexcept
        {
            return {
                this->impl_.columns[0]++,
                this->impl_.columns[1]++,
                this->impl_.columns[2]++,
                this->impl_.columns[3]++,
            };
        }

        mat<T, 4, R>& operator--() noexcept
        {
            --this->impl_.columns[0];
            --this->impl_.columns[1];
            --this->impl_.columns[2];
            --this->impl_.columns[3];
            return *this;
        }

        mat<T, 4, R> operator--(int) noexcept
        {
            return {
                this->impl_.columns[0]--,
                this->impl_.columns[1]--,
                this->impl_.columns[2]--,
                this->impl_.columns[3]--,
            };
        }

        template<typename U>
        mat<T, 4, R>& operator+=(const U& x) noexcept
        {
            this->impl_.columns[0] += x;
            this->impl_.columns[1] += x;
            this->impl_.columns[2] += x;
            this->impl_.columns[3] += x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator+=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] += m[0];
            this->impl_.columns[1] += m[1];
            this->impl_.columns[2] += m[2];
            this->impl_.columns[3] += m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator-=(const U& x) noexcept
        {
            this->impl_.columns[0] -= x;
            this->impl_.columns[1] -= x;
            this->impl_.columns[2] -= x;
            this->impl_.columns[3] -= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator-=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] -= m[0];
            this->impl_.columns[1] -= m[1];
            this->impl_.columns[2] -= m[2];
            this->impl_.columns[3] -= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator*=(const U& x) noexcept
        {
            this->impl_.columns[0] *= x;
            this->impl_.columns[1] *= x;
            this->impl_.columns[2] *= x;
            this->impl_.columns[3] *= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator*=(const mat<U, 4, 4>& m) noexcept
        {
            (*this) = (*this) * m;
        }

        template<typename U>
        mat<T, 4, R>& operator/=(const U& x) noexcept
        {
            this->impl_.columns[0] /= x;
            this->impl_.columns[1] /= x;
            this->impl_.columns[2] /= x;
            this->impl_.columns[3] /= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator/=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] /= m[0];
            this->impl_.columns[1] /= m[1];
            this->impl_.columns[2] /= m[2];
            this->impl_.columns[3] /= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator%=(const U& x) noexcept
        {
            this->impl_.columns[0] %= x;
            this->impl_.columns[1] %= x;
            this->impl_.columns[2] %= x;
            this->impl_.columns[3] %= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator%=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] %= m[0];
            this->impl_.columns[1] %= m[1];
            this->impl_.columns[2] %= m[2];
            this->impl_.columns[3] %= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator&=(const U& x) noexcept
        {
            this->impl_.columns[0] &= x;
            this->impl_.columns[1] &= x;
            this->impl_.columns[2] &= x;
            this->impl_.columns[3] &= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator&=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] &= m[0];
            this->impl_.columns[1] &= m[1];
            this->impl_.columns[2] &= m[2];
            this->impl_.columns[3] &= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator|=(const U& x) noexcept
        {
            this->impl_.columns[0] |= x;
            this->impl_.columns[1] |= x;
            this->impl_.columns[2] |= x;
            this->impl_.columns[3] |= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator|=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] |= m[0];
            this->impl_.columns[1] |= m[1];
            this->impl_.columns[2] |= m[2];
            this->impl_.columns[3] |= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator^=(const U& x) noexcept
        {
            this->impl_.columns[0] ^= x;
            this->impl_.columns[1] ^= x;
            this->impl_.columns[2] ^= x;
            this->impl_.columns[3] ^= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator^=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] ^= m[0];
            this->impl_.columns[1] ^= m[1];
            this->impl_.columns[2] ^= m[2];
            this->impl_.columns[3] ^= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator<<=(const U& x) noexcept
        {
            this->impl_.columns[0] <<= x;
            this->impl_.columns[1] <<= x;
            this->impl_.columns[2] <<= x;
            this->impl_.columns[3] <<= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator<<=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] <<= m[0];
            this->impl_.columns[1] <<= m[1];
            this->impl_.columns[2] <<= m[2];
            this->impl_.columns[3] <<= m[3];
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator>>=(const U& x) noexcept
        {
            this->impl_.columns[0] >>= x;
            this->impl_.columns[1] >>= x;
            this->impl_.columns[2] >>= x;
            this->impl_.columns[3] >>= x;
            return *this;
        }

        template<typename U>
        mat<T, 4, R>& operator>>=(const mat<U, 4, R>& m) noexcept
        {
            this->impl_.columns[0] >>= m[0];
            this->impl_.columns[1] >>= m[1];
            this->impl_.columns[2] >>= m[2];
            this->impl_.columns[3] >>= m[3];
            return *this;
        }
    };
}
