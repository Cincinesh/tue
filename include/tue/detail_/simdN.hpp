//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../simd.hpp"
#include "../sized_bool.hpp"

namespace tue
{
    namespace detail_
    {
        template<typename T, int N>
        inline simd<T, N> unary_plus_operator_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::unary_plus_operator_s(simpl[0]);
            rimpl[1] = tue::detail_::unary_plus_operator_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N>& pre_increment_operator_s(simd<T, N>& s) noexcept
        {
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            tue::detail_::pre_increment_operator_s(simpl[0]);
            tue::detail_::pre_increment_operator_s(simpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> post_increment_operator_s(simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::post_increment_operator_s(simpl[0]);
            rimpl[1] = tue::detail_::post_increment_operator_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> unary_minus_operator_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::unary_minus_operator_s(simpl[0]);
            rimpl[1] = tue::detail_::unary_minus_operator_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N>& pre_decrement_operator_s(simd<T, N>& s) noexcept
        {
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            tue::detail_::pre_decrement_operator_s(simpl[0]);
            tue::detail_::pre_decrement_operator_s(simpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> post_decrement_operator_s(simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::post_decrement_operator_s(simpl[0]);
            rimpl[1] = tue::detail_::post_decrement_operator_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_not_operator_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::bitwise_not_operator_s(simpl[0]);
            rimpl[1] = tue::detail_::bitwise_not_operator_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> addition_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::addition_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::addition_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> subtraction_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::subtraction_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::subtraction_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> multiplication_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::multiplication_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::multiplication_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> division_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::division_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::division_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> modulo_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::modulo_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::modulo_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_and_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::bitwise_and_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::bitwise_and_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_or_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::bitwise_or_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::bitwise_or_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_xor_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);

            simpl[0] = tue::detail_::bitwise_xor_operator_ss(
                limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::bitwise_xor_operator_ss(
                limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_shift_left_operator_si(
            const simd<T, N>& lhs, int rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);

            simpl[0] = tue::detail_::bitwise_shift_left_operator_si(
                limpl[0], rhs);
            simpl[1] = tue::detail_::bitwise_shift_left_operator_si(
                limpl[1], rhs);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N> bitwise_shift_right_operator_si(
            const simd<T, N>& lhs, int rhs) noexcept
        {
            simd<T, N> s;
            const auto simpl = reinterpret_cast<simd<T, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);

            simpl[0] = tue::detail_::bitwise_shift_right_operator_si(
                limpl[0], rhs);
            simpl[1] = tue::detail_::bitwise_shift_right_operator_si(
                limpl[1], rhs);
            return s;
        }

        template<typename T, int N>
        inline simd<T, N>& addition_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::addition_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::addition_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& subtraction_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::subtraction_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::subtraction_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& multiplication_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::multiplication_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::multiplication_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& division_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::division_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::division_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& modulo_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::modulo_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::modulo_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& bitwise_and_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::bitwise_and_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::bitwise_and_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& bitwise_or_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::bitwise_or_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::bitwise_or_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& bitwise_xor_assignment_operator_ss(
            simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            tue::detail_::bitwise_xor_assignment_operator_ss(
                limpl[0], rimpl[0]);
            tue::detail_::bitwise_xor_assignment_operator_ss(
                limpl[1], rimpl[1]);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& bitwise_shift_left_assignment_operator_si(
            simd<T, N>& lhs, int rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            tue::detail_::bitwise_shift_left_assignment_operator_si(
                limpl[0], rhs);
            tue::detail_::bitwise_shift_left_assignment_operator_si(
                limpl[1], rhs);
            return lhs;
        }

        template<typename T, int N>
        inline simd<T, N>& bitwise_shift_right_assignment_operator_si(
            simd<T, N>& lhs, int rhs) noexcept
        {
            const auto limpl = reinterpret_cast<simd<T, N/2>*>(&lhs);
            tue::detail_::bitwise_shift_right_assignment_operator_si(
                limpl[0], rhs);
            tue::detail_::bitwise_shift_right_assignment_operator_si(
                limpl[1], rhs);
            return lhs;
        }

        template<typename T, int N>
        inline bool equality_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            return tue::detail_::equality_operator_ss(limpl[0], rimpl[0])
                && tue::detail_::equality_operator_ss(limpl[1], rimpl[1]);
        }

        template<typename T, int N>
        inline bool inequality_operator_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            return tue::detail_::inequality_operator_ss(limpl[0], rimpl[0])
                || tue::detail_::inequality_operator_ss(limpl[1], rimpl[1]);
        }

        template<typename T, int N>
        inline simd<T, N> sin_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::sin_s(simpl[0]);
            rimpl[1] = tue::detail_::sin_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> cos_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::cos_s(simpl[0]);
            rimpl[1] = tue::detail_::cos_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline void sincos_s(
            const simd<T, N>& s,
            simd<T, N>& sin_out,
            simd<T, N>& cos_out) noexcept
        {
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            const auto sout = reinterpret_cast<simd<T, N/2>*>(&sin_out);
            const auto cout = reinterpret_cast<simd<T, N/2>*>(&cos_out);
            tue::detail_::sincos_s(simpl[0], sout[0], cout[0]);
            tue::detail_::sincos_s(simpl[1], sout[1], cout[1]);
        }

        template<typename T, int N>
        inline simd<T, N> exp_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::exp_s(simpl[0]);
            rimpl[1] = tue::detail_::exp_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> log_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::log_s(simpl[0]);
            rimpl[1] = tue::detail_::log_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> abs_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::abs_s(simpl[0]);
            rimpl[1] = tue::detail_::abs_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> pow_ss(
            const simd<T, N>& bases, const simd<T, N>& exponents) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(
                &result);
            const auto bimpl = reinterpret_cast<const simd<T, N/2>*>(
                &bases);
            const auto eimpl = reinterpret_cast<const simd<T, N/2>*>(
                &exponents);

            rimpl[0] = tue::detail_::pow_ss(bimpl[0], eimpl[0]);
            rimpl[1] = tue::detail_::pow_ss(bimpl[1], eimpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> recip_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::recip_s(simpl[0]);
            rimpl[1] = tue::detail_::recip_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> sqrt_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::sqrt_s(simpl[0]);
            rimpl[1] = tue::detail_::sqrt_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> rsqrt_s(const simd<T, N>& s) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl = reinterpret_cast<const simd<T, N/2>*>(&s);
            rimpl[0] = tue::detail_::rsqrt_s(simpl[0]);
            rimpl[1] = tue::detail_::rsqrt_s(simpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> min_ss(
            const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl1 = reinterpret_cast<const simd<T, N/2>*>(&s1);
            const auto simpl2 = reinterpret_cast<const simd<T, N/2>*>(&s2);
            rimpl[0] = tue::detail_::min_ss(simpl1[0], simpl2[0]);
            rimpl[1] = tue::detail_::min_ss(simpl1[1], simpl2[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<T, N> max_ss(
            const simd<T, N>& s1, const simd<T, N>& s2) noexcept
        {
            simd<T, N> result;
            const auto rimpl = reinterpret_cast<simd<T, N/2>*>(&result);
            const auto simpl1 = reinterpret_cast<const simd<T, N/2>*>(&s1);
            const auto simpl2 = reinterpret_cast<const simd<T, N/2>*>(&s2);
            rimpl[0] = tue::detail_::max_ss(simpl1[0], simpl2[0]);
            rimpl[1] = tue::detail_::max_ss(simpl1[1], simpl2[1]);
            return result;
        }

        template<typename T, typename U, int N>
        inline simd<U, N> mask_ss(
            const simd<T, N>& conditions,
            const simd<U, N>& values) noexcept
        {
            simd<U, N> result;
            const auto rimpl = reinterpret_cast<simd<U, N/2>*>(
                &result);
            const auto cimpl = reinterpret_cast<const simd<T, N/2>*>(
                &conditions);
            const auto vimpl = reinterpret_cast<const simd<U, N/2>*>(
                &values);

            rimpl[0] = tue::detail_::mask_ss(cimpl[0], vimpl[0]);
            rimpl[1] = tue::detail_::mask_ss(cimpl[1], vimpl[1]);
            return result;
        }

        template<typename T, typename U, int N>
        inline simd<U, N> select_sss(
            const simd<T, N>& conditions,
            const simd<U, N>& values,
            const simd<U, N>& otherwise) noexcept
        {
            simd<U, N> result;
            const auto rimpl = reinterpret_cast<simd<U, N/2>*>(
                &result);
            const auto cimpl = reinterpret_cast<const simd<T, N/2>*>(
                &conditions);
            const auto vimpl = reinterpret_cast<const simd<U, N/2>*>(
                &values);
            const auto oimpl = reinterpret_cast<const simd<U, N/2>*>(
                &otherwise);

            rimpl[0] = tue::detail_::select_sss(cimpl[0], vimpl[0], oimpl[0]);
            rimpl[1] = tue::detail_::select_sss(cimpl[1], vimpl[1], oimpl[1]);
            return result;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> less_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::less_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::less_ss(limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> less_equal_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::less_equal_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::less_equal_ss(limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> greater_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::greater_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::greater_ss(limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> greater_equal_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::greater_equal_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::greater_equal_ss(limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> equal_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::equal_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::equal_ss(limpl[1], rimpl[1]);
            return s;
        }

        template<typename T, int N>
        inline simd<sized_bool_t<sizeof(T)>, N> not_equal_ss(
            const simd<T, N>& lhs, const simd<T, N>& rhs) noexcept
        {
            using U = sized_bool_t<sizeof(T)>;
            simd<U, N> s;
            const auto simpl = reinterpret_cast<simd<U, N/2>*>(&s);
            const auto limpl = reinterpret_cast<const simd<T, N/2>*>(&lhs);
            const auto rimpl = reinterpret_cast<const simd<T, N/2>*>(&rhs);
            simpl[0] = tue::detail_::not_equal_ss(limpl[0], rimpl[0]);
            simpl[1] = tue::detail_::not_equal_ss(limpl[1], rimpl[1]);
            return s;
        }
    }
}
