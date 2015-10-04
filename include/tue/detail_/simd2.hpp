//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

#include "../math.hpp"
#include "../simd.hpp"
#include "../sized_bool.hpp"

namespace tue
{
    template<typename T>
    class alignas(tue::detail_::alignof_simd<T, 2>()) simd<T, 2>
    {
        std::enable_if_t<is_simd_component<T>::value, T[2]> data_;

    public:
        using component_type = T;

        static constexpr int component_count = 2;

        static constexpr bool is_accelerated = false;

        simd() noexcept = default;

        explicit simd(T x) noexcept
        {
            this->data_[0] = x;
            this->data_[1] = x;
        }

        template<int M = 2, typename = std::enable_if_t<M == 2>>
        simd(T x, T y) noexcept
        {
            this->data_[0] = x;
            this->data_[1] = y;
        }

        template<int M = 2, typename = std::enable_if_t<M == 4>>
        inline simd(T x, T y, T z, T w) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 8>>
        inline simd(T s0, T s1, T s2, T s3, T s4, T s5, T s6, T s7) noexcept;

        template<int M = 2, typename = std::enable_if_t<M == 16>>
        inline simd(
            T s0, T s1, T  s2, T  s3, T  s4, T  s5, T  s6, T  s7,
            T s8, T s9, T s10, T s11, T s12, T s13, T s14, T s15) noexcept;

        template<typename U>
        explicit simd(const simd<U, 2>& s) noexcept
        {
            const auto sdata = reinterpret_cast<const U*>(&s);
            this->data_[0] = static_cast<T>(sdata[0]);
            this->data_[1] = static_cast<T>(sdata[1]);
        }

        static simd<T, 2> zero() noexcept
        {
            simd<T, 2> s;
            s.data_[0] = static_cast<T>(0);
            s.data_[1] = static_cast<T>(0);
            return s;
        }

        static simd<T, 2> load(const T* data) noexcept
        {
            simd<T, 2> s;
            s.data_[0] = data[0];
            s.data_[1] = data[1];
            return s;
        }

        static simd<T, 2> loadu(const T* data) noexcept
        {
            simd<T, 2> s;
            s.data_[0] = data[0];
            s.data_[1] = data[1];
            return s;
        }

        void store(T* data) const noexcept
        {
            data[0] = this->data_[0];
            data[1] = this->data_[1];
        }

        void storeu(T* data) const noexcept
        {
            data[0] = this->data_[0];
            data[1] = this->data_[1];
        }

        const T* data() const noexcept
        {
            return this->data_;
        }

        T* data() noexcept
        {
            return this->data_;
        }
    };

    namespace detail_
    {
        template<typename T>
        inline simd<T, 2> unary_plus_operator_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = +sdata[0];
            rdata[1] = +sdata[1];
            return result;
        }

        template<typename T>
        inline simd<T, 2>& pre_increment_operator_s(simd<T, 2>& s) noexcept
        {
            const auto sdata = s.data();
            ++sdata[0];
            ++sdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> post_increment_operator_s(simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = sdata[0]++;
            rdata[1] = sdata[1]++;
            return result;
        }

        template<typename T>
        inline simd<T, 2> unary_minus_operator_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = -sdata[0];
            rdata[1] = -sdata[1];
            return result;
        }

        template<typename T>
        inline simd<T, 2>& pre_decrement_operator_s(simd<T, 2>& s) noexcept
        {
            const auto sdata = s.data();
            --sdata[0];
            --sdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> post_decrement_operator_s(simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = sdata[0]--;
            rdata[1] = sdata[1]--;
            return result;
        }

        template<typename T>
        inline simd<T, 2> bitwise_not_operator_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = ~sdata[0];
            rdata[1] = ~sdata[1];
            return result;
        }

        template<typename T>
        inline simd<T, 2> addition_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] + rdata[0];
            sdata[1] = ldata[1] + rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> subtraction_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] - rdata[0];
            sdata[1] = ldata[1] - rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> multiplication_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] * rdata[0];
            sdata[1] = ldata[1] * rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> division_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] / rdata[0];
            sdata[1] = ldata[1] / rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> modulo_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] % rdata[0];
            sdata[1] = ldata[1] % rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> bitwise_and_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] & rdata[0];
            sdata[1] = ldata[1] & rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> bitwise_or_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] | rdata[0];
            sdata[1] = ldata[1] | rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> bitwise_xor_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] ^ rdata[0];
            sdata[1] = ldata[1] ^ rdata[1];
            return s;
        }

        template<typename T>
        inline simd<T, 2> bitwise_shift_left_operator_si(
            const simd<T, 2>& lhs, int rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            sdata[0] = ldata[0] << rhs;
            sdata[1] = ldata[1] << rhs;
            return s;
        }

        template<typename T>
        inline simd<T, 2> bitwise_shift_right_operator_si(
            const simd<T, 2>& lhs, int rhs) noexcept
        {
            simd<T, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            sdata[0] = ldata[0] >> rhs;
            sdata[1] = ldata[1] >> rhs;
            return s;
        }

        template<typename T>
        inline simd<T, 2>& addition_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] += rdata[0];
            ldata[1] += rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& subtraction_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] -= rdata[0];
            ldata[1] -= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& multiplication_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] *= rdata[0];
            ldata[1] *= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& division_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] /= rdata[0];
            ldata[1] /= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& modulo_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] %= rdata[0];
            ldata[1] %= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& bitwise_and_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] &= rdata[0];
            ldata[1] &= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& bitwise_or_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] |= rdata[0];
            ldata[1] |= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& bitwise_xor_assignment_operator_ss(
            simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            ldata[0] ^= rdata[0];
            ldata[1] ^= rdata[1];
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& bitwise_shift_left_assignment_operator_si(
            simd<T, 2>& lhs, int rhs) noexcept
        {
            const auto ldata = lhs.data();
            ldata[0] <<= rhs;
            ldata[1] <<= rhs;
            return lhs;
        }

        template<typename T>
        inline simd<T, 2>& bitwise_shift_right_assignment_operator_si(
            simd<T, 2>& lhs, int rhs) noexcept
        {
            const auto ldata = lhs.data();
            ldata[0] >>= rhs;
            ldata[1] >>= rhs;
            return lhs;
        }

        template<typename T>
        inline bool equality_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            return ldata[0] == rdata[0] && ldata[1] == rdata[1];
        }

        template<typename T>
        inline bool inequality_operator_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            return ldata[0] != rdata[0] || ldata[1] != rdata[1];
        }

        template<typename T>
        inline simd<T, 2> sin_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::sin(sdata[0]);
            rdata[1] = tue::math::sin(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> cos_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::cos(sdata[0]);
            rdata[1] = tue::math::cos(sdata[1]);
            return result;
        }

        template<typename T>
        inline void sincos_s(
            const simd<T, 2>& s,
            simd<T, 2>& sin_out,
            simd<T, 2>& cos_out) noexcept
        {
            const auto sdata = s.data();
            const auto sout = sin_out.data();
            const auto cout = cos_out.data();
            tue::math::sincos(sdata[0], sout[0], cout[0]);
            tue::math::sincos(sdata[1], sout[1], cout[1]);
        }

        template<typename T>
        inline simd<T, 2> exp_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::exp(sdata[0]);
            rdata[1] = tue::math::exp(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> log_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::log(sdata[0]);
            rdata[1] = tue::math::log(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> abs_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::abs(sdata[0]);
            rdata[1] = tue::math::abs(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> pow_ss(
            const simd<T, 2>& bases, const simd<T, 2>& exponents) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto bdata = bases.data();
            const auto edata = exponents.data();
            rdata[0] = tue::math::pow(bdata[0], edata[0]);
            rdata[1] = tue::math::pow(bdata[1], edata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> recip_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::recip(sdata[0]);
            rdata[1] = tue::math::recip(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> sqrt_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::sqrt(sdata[0]);
            rdata[1] = tue::math::sqrt(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> rsqrt_s(const simd<T, 2>& s) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata = s.data();
            rdata[0] = tue::math::rsqrt(sdata[0]);
            rdata[1] = tue::math::rsqrt(sdata[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> min_ss(
            const simd<T, 2>& s1, const simd<T, 2>& s2) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata1 = s1.data();
            const auto sdata2 = s2.data();
            rdata[0] = tue::math::min(sdata1[0], sdata2[0]);
            rdata[1] = tue::math::min(sdata1[1], sdata2[1]);
            return result;
        }

        template<typename T>
        inline simd<T, 2> max_ss(
            const simd<T, 2>& s1, const simd<T, 2>& s2) noexcept
        {
            simd<T, 2> result;
            const auto rdata = result.data();
            const auto sdata1 = s1.data();
            const auto sdata2 = s2.data();
            rdata[0] = tue::math::max(sdata1[0], sdata2[0]);
            rdata[1] = tue::math::max(sdata1[1], sdata2[1]);
            return result;
        }

        template<typename T, typename U>
        inline simd<U, 2> mask_ss(
            const simd<T, 2>& conditions,
            const simd<U, 2>& values) noexcept
        {
            simd<U, 2> result;
            const auto rdata = result.data();
            const auto cdata = conditions.data();
            const auto vdata = values.data();
            rdata[0] = cdata[0] ? vdata[0] : U(0);
            rdata[1] = cdata[1] ? vdata[1] : U(0);
            return result;
        }

        template<typename T, typename U>
        inline simd<U, 2> select_sss(
            const simd<T, 2>& conditions,
            const simd<U, 2>& values,
            const simd<U, 2>& otherwise) noexcept
        {
            simd<U, 2> result;
            const auto rdata = result.data();
            const auto cdata = conditions.data();
            const auto vdata = values.data();
            const auto odata = otherwise.data();
            rdata[0] = cdata[0] ? vdata[0] : odata[0];
            rdata[1] = cdata[1] ? vdata[1] : odata[1];
            return result;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> less_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] < rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] < rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> less_equal_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] <= rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] <= rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> greater_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] > rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] > rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> greater_equal_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] >= rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] >= rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> equal_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] == rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] == rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }

        template<typename T>
        inline simd<sized_bool_t<sizeof(T)>, 2> not_equal_ss(
            const simd<T, 2>& lhs, const simd<T, 2>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, 2> s;
            const auto sdata = s.data();
            const auto ldata = lhs.data();
            const auto rdata = rhs.data();
            sdata[0] = ldata[0] != rdata[0] ? U(~0LL) : U(0LL);
            sdata[1] = ldata[1] != rdata[1] ? U(~0LL) : U(0LL);
            return s;
        }
    }
}
