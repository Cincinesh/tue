//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/simd.hpp>
#include "tue.tests.hpp"

#include <cstddef>
#include <cstdint>
#include <type_traits>
#include <type_traits>
#include <tue/math.hpp>
#include <tue/sized_bool.hpp>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    /*
     * Utility classes
     */
    TEST_CASE(is_simd_component)
    {
        test_assert(is_simd_component<bool>::value == false);
        test_assert(is_simd_component<float>::value == true);
        test_assert(is_simd_component<double>::value == true);
        test_assert(is_simd_component<std::int8_t>::value == true);
        test_assert(is_simd_component<std::int16_t>::value == true);
        test_assert(is_simd_component<std::int32_t>::value == true);
        test_assert(is_simd_component<std::int64_t>::value == true);
        test_assert(is_simd_component<std::uint8_t>::value == true);
        test_assert(is_simd_component<std::uint16_t>::value == true);
        test_assert(is_simd_component<std::uint32_t>::value == true);
        test_assert(is_simd_component<std::uint64_t>::value == true);
        test_assert(is_simd_component<bool8>::value == true);
        test_assert(is_simd_component<bool16>::value == true);
        test_assert(is_simd_component<bool32>::value == true);
        test_assert(is_simd_component<bool64>::value == true);
        test_assert((is_simd_component<simd<float, 4>>::value == false));
    }

    TEST_CASE(is_arithmetic_simd_component)
    {
        test_assert(is_arithmetic_simd_component<bool>::value == false);
        test_assert(is_arithmetic_simd_component<float>::value == true);
        test_assert(is_arithmetic_simd_component<double>::value == true);
        test_assert(is_arithmetic_simd_component<std::int8_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::int16_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::int32_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::int64_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::uint8_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::uint16_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::uint32_t>::value == true);
        test_assert(is_arithmetic_simd_component<std::uint64_t>::value == true);
        test_assert(is_arithmetic_simd_component<bool8>::value == false);
        test_assert(is_arithmetic_simd_component<bool16>::value == false);
        test_assert(is_arithmetic_simd_component<bool32>::value == false);
        test_assert(is_arithmetic_simd_component<bool64>::value == false);
        test_assert((
            is_arithmetic_simd_component<simd<float, 4>>::value == false));
    }

    TEST_CASE(is_floating_point_simd_component)
    {
        test_assert(
            is_floating_point_simd_component<bool>::value == false);
        test_assert(
            is_floating_point_simd_component<float>::value == true);
        test_assert(
            is_floating_point_simd_component<double>::value == true);
        test_assert(
            is_floating_point_simd_component<std::int8_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::int16_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::int32_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::int64_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::uint8_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::uint16_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::uint32_t>::value == false);
        test_assert(
            is_floating_point_simd_component<std::uint64_t>::value == false);
        test_assert(
            is_floating_point_simd_component<bool8>::value == false);
        test_assert(
            is_floating_point_simd_component<bool16>::value == false);
        test_assert(
            is_floating_point_simd_component<bool32>::value == false);
        test_assert(
            is_floating_point_simd_component<bool64>::value == false);
        test_assert((
            is_floating_point_simd_component<simd<float, 4>>::value == false));
    }

    TEST_CASE(is_integral_simd_component)
    {
        test_assert(is_integral_simd_component<bool>::value == false);
        test_assert(is_integral_simd_component<float>::value == false);
        test_assert(is_integral_simd_component<double>::value == false);
        test_assert(is_integral_simd_component<std::int8_t>::value == true);
        test_assert(is_integral_simd_component<std::int16_t>::value == true);
        test_assert(is_integral_simd_component<std::int32_t>::value == true);
        test_assert(is_integral_simd_component<std::int64_t>::value == true);
        test_assert(is_integral_simd_component<std::uint8_t>::value == true);
        test_assert(is_integral_simd_component<std::uint16_t>::value == true);
        test_assert(is_integral_simd_component<std::uint32_t>::value == true);
        test_assert(is_integral_simd_component<std::uint64_t>::value == true);
        test_assert(is_integral_simd_component<bool8>::value == false);
        test_assert(is_integral_simd_component<bool16>::value == false);
        test_assert(is_integral_simd_component<bool32>::value == false);
        test_assert(is_integral_simd_component<bool64>::value == false);
        test_assert((
            is_integral_simd_component<simd<float, 4>>::value == false));
    }

    /*
     * Common SIMD Tests
     */
    template<typename Alias, typename T, int N>
    struct common_simd_tests
    {
        template<typename U = T>
        static const simd<U, N>& test_simd() noexcept
        {
            static bool initialized = false;
            static simd<U, N> s;
            if (!initialized)
            {
                for (int i = 0; i < N; ++i)
                {
                    s.data()[i] = static_cast<U>(i+1);
                }
                initialized = true;
            }
            return s;
        }

        static const simd<T, N>& test_simd2() noexcept
        {
            static bool initialized = false;
            static simd<T, N> s;
            if (!initialized)
            {
                for (int i = 0; i < N; ++i)
                {
                    s.data()[i] = static_cast<T>((i+1)*2);
                }
                initialized = true;
            }
            return s;
        }

        static void TEST_CASE_alias()
        {
            test_assert((std::is_same<Alias, simd<T, N>>::value));
        }

        static void TEST_CASE_size()
        {
            test_assert(sizeof(simd<T, N>) == sizeof(T[N]));
        }

        static void TEST_CASE_alignment()
        {
            test_assert((
                alignof(simd<T, N>) == tue::detail_::alignof_simd<T, N>()));
        }

        static void TEST_CASE_component_type()
        {
            test_assert((std::is_same<
                typename simd<T, N>::component_type, T>::value));
        }

        static void TEST_CASE_component_count()
        {
            constexpr auto component_count = simd<T, N>::component_count;
            test_assert(component_count == N);
        }

        static void TEST_CASE_is_accelerated()
        {
            constexpr auto is_accelerated = simd<T, N>::is_accelerated;
            test_assert((std::is_same<decltype(is_accelerated), bool>::value));
        }

        static void TEST_CASE_default_constructor()
        {
            simd<T, N> s;
            unused(s);
        }

        static void TEST_CASE_scalar_constructor()
        {
            const simd<T, N> s(static_cast<T>(12LL));
            for (int i = 0; i < N; ++i)
            {
                test_assert(s.data()[i] == static_cast<T>(12LL));
            }
        }

        template<int M = N>
        static std::enable_if_t<M == 2> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(1LL),
                static_cast<T>(2LL),
            };

            test_assert(s.data()[0] == static_cast<T>(1LL));
            test_assert(s.data()[1] == static_cast<T>(2LL));
        }

        template<int M = N>
        static std::enable_if_t<M == 4> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(1LL),
                static_cast<T>(2LL),
                static_cast<T>(3LL),
                static_cast<T>(4LL),
            };

            test_assert(s.data()[0] == static_cast<T>(1LL));
            test_assert(s.data()[1] == static_cast<T>(2LL));
            test_assert(s.data()[2] == static_cast<T>(3LL));
            test_assert(s.data()[3] == static_cast<T>(4LL));
        }

        template<int M = N>
        static std::enable_if_t<M == 8> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(1LL),
                static_cast<T>(2LL),
                static_cast<T>(3LL),
                static_cast<T>(4LL),
                static_cast<T>(5LL),
                static_cast<T>(6LL),
                static_cast<T>(7LL),
                static_cast<T>(8LL),
            };

            test_assert(s.data()[0] == static_cast<T>(1LL));
            test_assert(s.data()[1] == static_cast<T>(2LL));
            test_assert(s.data()[2] == static_cast<T>(3LL));
            test_assert(s.data()[3] == static_cast<T>(4LL));
            test_assert(s.data()[4] == static_cast<T>(5LL));
            test_assert(s.data()[5] == static_cast<T>(6LL));
            test_assert(s.data()[6] == static_cast<T>(7LL));
            test_assert(s.data()[7] == static_cast<T>(8LL));
        }

        template<int M = N>
        static std::enable_if_t<M == 16> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(1LL),
                static_cast<T>(2LL),
                static_cast<T>(3LL),
                static_cast<T>(4LL),
                static_cast<T>(5LL),
                static_cast<T>(6LL),
                static_cast<T>(7LL),
                static_cast<T>(8LL),
                static_cast<T>(9LL),
                static_cast<T>(10LL),
                static_cast<T>(11LL),
                static_cast<T>(12LL),
                static_cast<T>(13LL),
                static_cast<T>(14LL),
                static_cast<T>(15LL),
                static_cast<T>(16LL),
            };

            test_assert(s.data()[0] == static_cast<T>(1LL));
            test_assert(s.data()[1] == static_cast<T>(2LL));
            test_assert(s.data()[2] == static_cast<T>(3LL));
            test_assert(s.data()[3] == static_cast<T>(4LL));
            test_assert(s.data()[4] == static_cast<T>(5LL));
            test_assert(s.data()[5] == static_cast<T>(6LL));
            test_assert(s.data()[6] == static_cast<T>(7LL));
            test_assert(s.data()[7] == static_cast<T>(8LL));
            test_assert(s.data()[8] == static_cast<T>(9LL));
            test_assert(s.data()[9] == static_cast<T>(10LL));
            test_assert(s.data()[10] == static_cast<T>(11LL));
            test_assert(s.data()[11] == static_cast<T>(12LL));
            test_assert(s.data()[12] == static_cast<T>(13LL));
            test_assert(s.data()[13] == static_cast<T>(14LL));
            test_assert(s.data()[14] == static_cast<T>(15LL));
            test_assert(s.data()[15] == static_cast<T>(16LL));
        }

        template<int M = N>
        static std::enable_if_t<(M > 16)> TEST_CASE_component_constructor()
        {
        }

        template<typename U = T>
        static std::enable_if_t<!is_sized_bool<U>::value>
        TEST_CASE_explicit_cast_from_float_simd()
        {
            const auto s1 = test_simd<float>();
            const simd<T, N> s2(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == static_cast<T>(s1.data()[i]));
            }

            const auto s3 = test_simd<double>();
            const simd<T, N> s4(s3);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s4.data()[i] == static_cast<T>(s3.data()[i]));
            }
        }

        template<typename U = T>
        static std::enable_if_t<is_sized_bool<U>::value>
        TEST_CASE_explicit_cast_from_float_simd()
        {
        }

        static void TEST_CASE_explicit_cast_from_int_simd()
        {
            const auto s1 = test_simd<std::int8_t>();
            const simd<T, N> s2(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == static_cast<T>(s1.data()[i]));
            }

            const auto s3 = test_simd<std::int16_t>();
            const simd<T, N> s4(s3);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s4.data()[i] == static_cast<T>(s3.data()[i]));
            }

            const auto s5 = test_simd<std::int32_t>();
            const simd<T, N> s6(s5);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s6.data()[i] == static_cast<T>(s5.data()[i]));
            }

            const auto s7 = test_simd<std::int64_t>();
            const simd<T, N> s8(s7);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s8.data()[i] == static_cast<T>(s7.data()[i]));
            }
        }

        static void TEST_CASE_explicit_cast_from_uint_simd()
        {
            const auto s1 = test_simd<std::uint8_t>();
            const simd<T, N> s2(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == static_cast<T>(s1.data()[i]));
            }

            const auto s3 = test_simd<std::uint16_t>();
            const simd<T, N> s4(s3);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s4.data()[i] == static_cast<T>(s3.data()[i]));
            }

            const auto s5 = test_simd<std::uint32_t>();
            const simd<T, N> s6(s5);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s6.data()[i] == static_cast<T>(s5.data()[i]));
            }

            const auto s7 = test_simd<std::uint64_t>();
            const simd<T, N> s8(s7);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s8.data()[i] == static_cast<T>(s7.data()[i]));
            }
        }

        template<typename U = T>
        static std::enable_if_t<!std::is_floating_point<U>::value>
        TEST_CASE_explicit_cast_from_bool_simd()
        {
            const auto s1 = test_simd<bool8>();
            const simd<T, N> s2(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == static_cast<T>(s1.data()[i]));
            }

            const auto s3 = test_simd<bool16>();
            const simd<T, N> s4(s3);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s4.data()[i] == static_cast<T>(s3.data()[i]));
            }

            const auto s5 = test_simd<bool32>();
            const simd<T, N> s6(s5);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s6.data()[i] == static_cast<T>(s5.data()[i]));
            }

            const auto s7 = test_simd<bool64>();
            const simd<T, N> s8(s7);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s8.data()[i] == static_cast<T>(s7.data()[i]));
            }
        }

        template<typename U = T>
        static std::enable_if_t<std::is_floating_point<U>::value>
        TEST_CASE_explicit_cast_from_bool_simd()
        {
        }

        static void TEST_CASE_zero()
        {
            const auto s = simd<T, N>::zero();
            for (int i = 0; i < N; ++i)
            {
                test_assert(s.data()[i] == static_cast<T>(0));
            }
        }

        static void TEST_CASE_load()
        {
            alignas(simd<T, N>) T data[N];
            for (int i = 0; i < N; ++i)
            {
                data[i] = static_cast<T>(i);
            }

            const auto* cdata = data;
            const auto s = simd<T, N>::load(cdata);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s.data()[i] == cdata[i]);
            }
        }

        static void TEST_CASE_loadu()
        {
            alignas(simd<T, N>) T data[N + 1];
            for (int i = 0; i < N; ++i)
            {
                data[i + 1] = static_cast<T>(i);
            }

            const auto* cdata = data;
            const auto s = simd<T, N>::loadu(cdata + 1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s.data()[i] == cdata[i + 1]);
            }
        }

        static void TEST_CASE_store()
        {
            auto s = test_simd();
            alignas(simd<T, N>) T data[N];
            s.store(data);
            for (int i = 0; i < N; ++i)
            {
                data[i] = s.data()[i];
            }
        }

        static void TEST_CASE_storeu()
        {
            auto s = test_simd();
            alignas(simd<T, N>) T data[N + 1];
            s.storeu(data + 1);
            for (int i = 0; i < N; ++i)
            {
                data[i + 1] = s.data()[i];
            }
        }

        static void TEST_CASE_data()
        {
            const auto cs = test_simd();
            const T* cdata = cs.data();
            test_assert(cdata == static_cast<const void*>(&cs));

            simd<T, N> s;
            T* data = s.data();
            test_assert(data == static_cast<void*>(&s));
        }

        static void TEST_CASE_equality_operator()
        {
            const simd<T, N> cs1 = test_simd();

            simd<T, N> s2 = cs1;
            const auto& cs2 = s2;
            test_assert((cs1 == cs2) == true);

            for (int i = 0; i < N; ++i)
            {
                s2 = cs1;
                s2.data()[i] = static_cast<T>(0);
                test_assert((cs1 == cs2) == false);
            }
        }

        static void TEST_CASE_inequality_operator()
        {
            const simd<T, N> cs1 = test_simd();

            simd<T, N> s2 = cs1;
            const auto& cs2 = s2;
            test_assert((cs1 != cs2) == false);

            for (int i = 0; i < N; ++i)
            {
                s2 = cs1;
                s2.data()[i] = static_cast<T>(0);
                test_assert((cs1 != cs2) == true);
            }
        }

        static void TEST_CASE_mask()
        {
            simd<sized_bool_t<sizeof(T)>, N> c;
            for (int i = 0; i < N; ++i)
            {
                c.data()[i] = static_cast<sized_bool_t<sizeof(T)>>(
                    i%2==0 ? 0LL : ~0LL);
            }
            const auto& conditions = c;

            const auto values = test_simd();
            const auto s1 = math::mask(conditions, values);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] == math::mask(
                    conditions.data()[i],
                    values.data()[i]));
            }
        }

        static void TEST_CASE_select()
        {
            simd<sized_bool_t<sizeof(T)>, N> c;
            for (int i = 0; i < N; ++i)
            {
                c.data()[i] = static_cast<sized_bool_t<sizeof(T)>>(
                    i%2==0 ? 0LL : ~0LL);
            }
            const auto& conditions = c;

            const auto values = test_simd();
            const auto otherwise = test_simd2();
            const auto s2 = math::select(conditions, values, otherwise);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == math::select(
                    conditions.data()[i],
                    values.data()[i],
                    otherwise.data()[i]));
            }
        }

        static void TEST_CASE_equal()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::equal(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] == s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void TEST_CASE_not_equal()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::not_equal(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] != s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void run_all()
        {
            TEST_CASE_alias();
            TEST_CASE_size();
            TEST_CASE_alignment();
            TEST_CASE_component_type();
            TEST_CASE_component_count();
            TEST_CASE_default_constructor();
            TEST_CASE_scalar_constructor();
            TEST_CASE_component_constructor();
            TEST_CASE_explicit_cast_from_float_simd();
            TEST_CASE_explicit_cast_from_int_simd();
            TEST_CASE_explicit_cast_from_uint_simd();
            TEST_CASE_explicit_cast_from_bool_simd();
            TEST_CASE_zero();
            TEST_CASE_load();
            TEST_CASE_loadu();
            TEST_CASE_store();
            TEST_CASE_storeu();
            TEST_CASE_data();
            TEST_CASE_equality_operator();
            TEST_CASE_inequality_operator();
            TEST_CASE_mask();
            TEST_CASE_select();
            TEST_CASE_equal();
            TEST_CASE_not_equal();
        }
    };

    /*
     * Arithmetic SIMD Tests
     */
    template<typename Alias, typename T, int N>
    struct arithmetic_simd_tests : public common_simd_tests<Alias, T, N>
    {
        static const simd<T, N>& test_simd() noexcept
        {
            static bool initialized = false;
            static simd<T, N> s;
            if (!initialized)
            {
                for (int i = 0; i < N; ++i)
                {
                    s.data()[i] = static_cast<T>((i+1) * (i%2==0 ? 1 : -1));
                }
                initialized = true;
            }
            return s;
        }

        static const simd<T, N>& test_simd2() noexcept
        {
            static bool initialized = false;
            static simd<T, N> s;
            if (!initialized)
            {
                for (int i = 0; i < N; ++i)
                {
                    s.data()[i] = static_cast<T>((i+1)*2 * (i%2==0 ? -1 : 1));
                }
                initialized = true;
            }
            return s;
        }

        static const simd<T, N>& test_simd_abs() noexcept
        {
            static bool initialized = false;
            static simd<T, N> s;
            if (!initialized)
            {
                s = math::abs(test_simd());
                initialized = true;
            }
            return s;
        }

        template<typename U = T>
        static std::enable_if_t<std::is_signed<U>::value>
        TEST_CASE_unary_plus_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = +s1;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == +s1.data()[i]);
            }
        }

        template<typename U = T>
        static std::enable_if_t<!std::is_signed<U>::value>
        TEST_CASE_unary_plus_operator()
        {
        }

        static void TEST_CASE_pre_increment_operator()
        {
            auto s = test_simd();
            test_assert(&(++s) == &s);
            test_assert((s == test_simd() + simd<T, N>(1)));
        }

        static void TEST_CASE_post_increment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = s1++;
            test_assert((s1 == test_simd() + simd<T, N>(1)));
            test_assert((s2 == test_simd()));
        }

        template<typename U = T>
        static std::enable_if_t<std::is_signed<U>::value>
        TEST_CASE_unary_minus_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = -s1;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == -s1.data()[i]);
            }
        }

        template<typename U = T>
        static std::enable_if_t<!std::is_signed<U>::value>
        TEST_CASE_unary_minus_operator()
        {
        }

        static void TEST_CASE_pre_decrement_operator()
        {
            auto s = test_simd();
            test_assert(&(--s) == &s);
            test_assert((s == test_simd() - simd<T, N>(1)));
        }

        static void TEST_CASE_post_decrement_operator()
        {
            auto s1 = test_simd();
            const auto s2 = s1--;
            test_assert((s1 == test_simd() - simd<T, N>(1)));
            test_assert((s2 == test_simd()));
        }

        static void TEST_CASE_addition_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 + s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] + s2.data()[i]));
            }
        }

        static void TEST_CASE_subtraction_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 - s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] - s2.data()[i]));
            }
        }

        static void TEST_CASE_multiplication_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 * s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] * s2.data()[i]));
            }
        }

        static void TEST_CASE_division_operator()
        {
            const auto s1 = test_simd2();
            const auto s2 = test_simd();
            const auto s3 = s1 / s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] / s2.data()[i]));
            }
        }

        static void TEST_CASE_addition_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 += s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] + s2.data()[i]));
            }
        }

        static void TEST_CASE_subtraction_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 -= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] - s2.data()[i]));
            }
        }

        static void TEST_CASE_multiplication_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 *= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] * s2.data()[i]));
            }
        }

        static void TEST_CASE_division_assignment_operator()
        {
            auto s1 = test_simd2();
            const auto s2 = test_simd();
            test_assert(&(s1 /= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd2().data()[i] / s2.data()[i]));
            }
        }

        static void TEST_CASE_abs()
        {
            const auto s1 = test_simd();
            const auto s2 = math::abs(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == math::abs(s1.data()[i]));
            }
        }

        static void TEST_CASE_min()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::min(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    math::min(s1.data()[i], s2.data()[i]));
            }
        }

        static void TEST_CASE_max()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::max(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    math::max(s1.data()[i], s2.data()[i]));
            }
        }

        static void TEST_CASE_less()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::less(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] < s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void TEST_CASE_less_equal()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::less_equal(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] <= s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void TEST_CASE_greater()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::greater(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] > s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void TEST_CASE_greater_equal()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = math::greater_equal(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<sized_bool_t<sizeof(T)>>(
                        s1.data()[i] >= s2.data()[i] ? ~0LL : 0LL));
            }
        }

        static void run_all()
        {
            common_simd_tests<Alias, T, N>::run_all();
            TEST_CASE_unary_plus_operator();
            TEST_CASE_pre_increment_operator();
            TEST_CASE_post_increment_operator();
            TEST_CASE_unary_minus_operator();
            TEST_CASE_pre_decrement_operator();
            TEST_CASE_post_decrement_operator();
            TEST_CASE_addition_operator();
            TEST_CASE_subtraction_operator();
            TEST_CASE_multiplication_operator();
            TEST_CASE_division_operator();
            TEST_CASE_addition_assignment_operator();
            TEST_CASE_subtraction_assignment_operator();
            TEST_CASE_multiplication_assignment_operator();
            TEST_CASE_division_assignment_operator();
            TEST_CASE_abs();
            TEST_CASE_min();
            TEST_CASE_max();
            TEST_CASE_less();
            TEST_CASE_less_equal();
            TEST_CASE_greater();
            TEST_CASE_greater_equal();
        }
    };

    /*
     * Floating-point SIMD Tests
     */
    template<typename Alias, typename T, int N>
    struct float_simd_tests : public arithmetic_simd_tests<Alias, T, N>
    {
        using arithmetic_simd_tests<Alias, T, N>::test_simd;
        using arithmetic_simd_tests<Alias, T, N>::test_simd2;
        using arithmetic_simd_tests<Alias, T, N>::test_simd_abs;

        static void TEST_CASE_sin()
        {
            const auto s1 = test_simd();
            const auto s2 = math::sin(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::sin(s1.data()[i])));
            }
        }

        static void TEST_CASE_cos()
        {
            const auto s1 = test_simd();
            const auto s2 = math::cos(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::cos(s1.data()[i])));
            }
        }

        static void TEST_CASE_sincos()
        {
            const auto s = test_simd();
            simd<T, N> sin_out, cos_out;
            math::sincos(s, sin_out, cos_out);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    sin_out.data()[i], math::sin(s.data()[i])));
                test_assert(nearly_equal(
                    cos_out.data()[i], math::cos(s.data()[i])));
            }
        }

        static void TEST_CASE_exp()
        {
            const auto s1 = test_simd();
            const auto s2 = math::exp(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::exp(s1.data()[i])));
            }
        }

        static void TEST_CASE_log()
        {
            const auto s1 = test_simd_abs();
            const auto s2 = math::log(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::log(s1.data()[i])));
            }
        }

        static void TEST_CASE_pow()
        {
            const auto s1 = test_simd_abs();
            const auto s2 = test_simd2();
            const auto s3 = math::pow(s1, s2);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s3.data()[i], math::pow(s1.data()[i], s2.data()[i])));
            }
        }

        static void TEST_CASE_recip()
        {
            const auto s1 = test_simd();
            const auto s2 = math::recip(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::recip(s1.data()[i])));
            }
        }

        static void TEST_CASE_sqrt()
        {
            const auto s1 = test_simd_abs();
            const auto s2 = math::sqrt(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::sqrt(s1.data()[i])));
            }
        }

        static void TEST_CASE_rsqrt()
        {
            const auto s1 = test_simd_abs();
            const auto s2 = math::rsqrt(s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(nearly_equal(
                    s2.data()[i], math::rsqrt(s1.data()[i])));
            }
        }

        static void run_all()
        {
            arithmetic_simd_tests<Alias, T, N>::run_all();
            TEST_CASE_sin();
            TEST_CASE_cos();
            TEST_CASE_sincos();
            TEST_CASE_exp();
            TEST_CASE_log();
            TEST_CASE_pow();
            TEST_CASE_recip();
            TEST_CASE_sqrt();
            TEST_CASE_rsqrt();
        }
    };

    /*
     * Integral SIMD Tests
     */
    template<typename Alias, typename T, int N>
    struct int_simd_tests : public arithmetic_simd_tests<Alias, T, N>
    {
        using arithmetic_simd_tests<Alias, T, N>::test_simd;
        using arithmetic_simd_tests<Alias, T, N>::test_simd2;
        using arithmetic_simd_tests<Alias, T, N>::test_simd_abs;

        static void TEST_CASE_bitwise_not_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = ~s1;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == static_cast<T>(~s1.data()[i]));
            }
        }

        static void TEST_CASE_modulo_operator()
        {
            const auto s1 = test_simd2();
            const auto s2 = test_simd();
            const auto s3 = s1 % s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] % s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_and_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 & s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] & s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_or_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 | s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] | s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_xor_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = test_simd2();
            const auto s3 = s1 ^ s2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s3.data()[i] ==
                    static_cast<T>(s1.data()[i] ^ s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_shift_left_operator()
        {
            const auto s1 = test_simd();
            const auto s2 = s1 << 2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] ==
                    static_cast<T>(s1.data()[i] << 2));
            }
        }

        static void TEST_CASE_bitwise_shift_right_operator()
        {
            const auto s1 = test_simd_abs();
            const auto s2 = s1 >> 2;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] ==
                    static_cast<T>(s1.data()[i] >> 2));
            }
        }

        static void TEST_CASE_modulo_assignment_operator()
        {
            auto s1 = test_simd2();
            const auto s2 = test_simd();
            test_assert(&(s1 %= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd2().data()[i] % s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_and_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 &= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] & s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_or_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 |= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] | s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_xor_assignment_operator()
        {
            auto s1 = test_simd();
            const auto s2 = test_simd2();
            test_assert(&(s1 ^= s2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] ^ s2.data()[i]));
            }
        }

        static void TEST_CASE_bitwise_shift_left_assignment_operator()
        {
            auto s1 = test_simd();
            test_assert(&(s1 <<= 2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd().data()[i] << 2));
            }
        }

        static void TEST_CASE_bitwise_shift_right_assignment_operator()
        {
            auto s1 = test_simd_abs();
            test_assert(&(s1 >>= 2) == &s1);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s1.data()[i] ==
                    static_cast<T>(test_simd_abs().data()[i] >> 2));
            }
        }

        static void run_all()
        {
            arithmetic_simd_tests<Alias, T, N>::run_all();
            TEST_CASE_bitwise_not_operator();
            TEST_CASE_modulo_operator();
            TEST_CASE_bitwise_and_operator();
            TEST_CASE_bitwise_or_operator();
            TEST_CASE_bitwise_xor_operator();
            TEST_CASE_bitwise_shift_left_operator();
            TEST_CASE_bitwise_shift_right_operator();
            TEST_CASE_modulo_assignment_operator();
            TEST_CASE_bitwise_and_assignment_operator();
            TEST_CASE_bitwise_or_assignment_operator();
            TEST_CASE_bitwise_xor_assignment_operator();
            TEST_CASE_bitwise_shift_left_assignment_operator();
            TEST_CASE_bitwise_shift_right_assignment_operator();
        }
    };

#define FLOAT_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        float_simd_tests<Alias, T, N>::run_all(); \
    }

#define INT_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        int_simd_tests<Alias, T, N>::run_all(); \
    }

#define BOOL_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        common_simd_tests<Alias, T, N>::run_all(); \
    }

    FLOAT_SIMD_TEST_CASES(float32x2, float, 2)
    FLOAT_SIMD_TEST_CASES(float32x4, float, 4)
    FLOAT_SIMD_TEST_CASES(float32x8, float, 8)
    FLOAT_SIMD_TEST_CASES(float32x16, float, 16)

    FLOAT_SIMD_TEST_CASES(float64x2, double, 2)
    FLOAT_SIMD_TEST_CASES(float64x4, double, 4)
    FLOAT_SIMD_TEST_CASES(float64x8, double, 8)

    INT_SIMD_TEST_CASES(int8x2, std::int8_t, 2)
    INT_SIMD_TEST_CASES(int8x4, std::int8_t, 4)
    INT_SIMD_TEST_CASES(int8x8, std::int8_t, 8)
    INT_SIMD_TEST_CASES(int8x16, std::int8_t, 16)
    INT_SIMD_TEST_CASES(int8x32, std::int8_t, 32)
    INT_SIMD_TEST_CASES(int8x64, std::int8_t, 64)

    INT_SIMD_TEST_CASES(int16x2, std::int16_t, 2)
    INT_SIMD_TEST_CASES(int16x4, std::int16_t, 4)
    INT_SIMD_TEST_CASES(int16x8, std::int16_t, 8)
    INT_SIMD_TEST_CASES(int16x16, std::int16_t, 16)
    INT_SIMD_TEST_CASES(int16x32, std::int16_t, 32)

    INT_SIMD_TEST_CASES(int32x2, std::int32_t, 2)
    INT_SIMD_TEST_CASES(int32x4, std::int32_t, 4)
    INT_SIMD_TEST_CASES(int32x8, std::int32_t, 8)
    INT_SIMD_TEST_CASES(int32x16, std::int32_t, 16)

    INT_SIMD_TEST_CASES(int64x2, std::int64_t, 2)
    INT_SIMD_TEST_CASES(int64x4, std::int64_t, 4)
    INT_SIMD_TEST_CASES(int64x8, std::int64_t, 8)

    INT_SIMD_TEST_CASES(uint8x2, std::uint8_t, 2)
    INT_SIMD_TEST_CASES(uint8x4, std::uint8_t, 4)
    INT_SIMD_TEST_CASES(uint8x8, std::uint8_t, 8)
    INT_SIMD_TEST_CASES(uint8x16, std::uint8_t, 16)
    INT_SIMD_TEST_CASES(uint8x32, std::uint8_t, 32)
    INT_SIMD_TEST_CASES(uint8x64, std::uint8_t, 64)

    INT_SIMD_TEST_CASES(uint16x2, std::uint16_t, 2)
    INT_SIMD_TEST_CASES(uint16x4, std::uint16_t, 4)
    INT_SIMD_TEST_CASES(uint16x8, std::uint16_t, 8)
    INT_SIMD_TEST_CASES(uint16x16, std::uint16_t, 16)
    INT_SIMD_TEST_CASES(uint16x32, std::uint16_t, 32)

    INT_SIMD_TEST_CASES(uint32x2, std::uint32_t, 2)
    INT_SIMD_TEST_CASES(uint32x4, std::uint32_t, 4)
    INT_SIMD_TEST_CASES(uint32x8, std::uint32_t, 8)
    INT_SIMD_TEST_CASES(uint32x16, std::uint32_t, 16)

    INT_SIMD_TEST_CASES(uint64x2, std::uint64_t, 2)
    INT_SIMD_TEST_CASES(uint64x4, std::uint64_t, 4)
    INT_SIMD_TEST_CASES(uint64x8, std::uint64_t, 8)

    BOOL_SIMD_TEST_CASES(bool8x2, bool8, 2)
    BOOL_SIMD_TEST_CASES(bool8x4, bool8, 4)
    BOOL_SIMD_TEST_CASES(bool8x8, bool8, 8)
    BOOL_SIMD_TEST_CASES(bool8x16, bool8, 16)
    BOOL_SIMD_TEST_CASES(bool8x32, bool8, 32)
    BOOL_SIMD_TEST_CASES(bool8x64, bool8, 64)

    BOOL_SIMD_TEST_CASES(bool16x2, bool16, 2)
    BOOL_SIMD_TEST_CASES(bool16x4, bool16, 4)
    BOOL_SIMD_TEST_CASES(bool16x8, bool16, 8)
    BOOL_SIMD_TEST_CASES(bool16x16, bool16, 16)
    BOOL_SIMD_TEST_CASES(bool16x32, bool16, 32)

    BOOL_SIMD_TEST_CASES(bool32x2, bool32, 2)
    BOOL_SIMD_TEST_CASES(bool32x4, bool32, 4)
    BOOL_SIMD_TEST_CASES(bool32x8, bool32, 8)
    BOOL_SIMD_TEST_CASES(bool32x16, bool32, 16)

    BOOL_SIMD_TEST_CASES(bool64x2, bool64, 2)
    BOOL_SIMD_TEST_CASES(bool64x4, bool64, 4)
    BOOL_SIMD_TEST_CASES(bool64x8, bool64, 8)
}
