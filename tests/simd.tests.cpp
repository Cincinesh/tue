//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/simd.hpp>
#include <mon/test_case.hpp>

#include <cstdint>
#include <type_traits>
#include <tue/sized_bool.hpp>
#include <tue/unused.hpp>

namespace
{
    using namespace tue;

    template<typename Alias, typename T, int N>
    struct common_simd_tests
    {
        static simd<T, N> test_simd() noexcept
        {
            simd<T, N> s;
            for (int i = 0; i < N; ++i)
            {
                s.data()[i] = static_cast<T>(i);
            }
            return s;
        }

        static void TEST_CASE_alias()
        {
            test_assert((std::is_same<Alias, simd<T, N>>::value));
        }

        static void TEST_CASE_size()
        {
            test_assert(sizeof(simd<T, N>) == sizeof(T) * N);
        }

        static void TEST_CASE_alignment()
        {
            test_assert(alignof(simd<T, N>) == sizeof(T) * N);
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
            simd<T, N> s = test_simd();
            alignas(simd<T, N>) T data[N];
            s.store(data);
            for (int i = 0; i < N; ++i)
            {
                data[i] = s.data()[i];
            }
        }

        static void TEST_CASE_storeu()
        {
            simd<T, N> s = test_simd();
            alignas(simd<T, N>) T data[N + 1];
            s.store(data + 1);
            for (int i = 0; i < N; ++i)
            {
                data[i + 1] = s.data()[i];
            }
        }

        static void TEST_CASE_data()
        {
            const simd<T, N> cs = test_simd();
            const T* cdata = cs.data();
            test_assert(cdata == static_cast<const void*>(&cs));

            simd<T, N> s;
            T* data = s.data();
            test_assert(data == static_cast<void*>(&s));
        }

        static void run_all()
        {
            TEST_CASE_alias();
            TEST_CASE_size();
            TEST_CASE_alignment();
            TEST_CASE_component_type();
            TEST_CASE_component_count();
            TEST_CASE_default_constructor();
            TEST_CASE_zero();
            TEST_CASE_load();
            TEST_CASE_loadu();
            TEST_CASE_store();
            TEST_CASE_storeu();
            TEST_CASE_data();
        }
    };

    template<typename Alias, typename T, int N>
    struct arithmetic_simd_tests
    {
        static simd<T, N> test_simd() noexcept
        {
            simd<T, N> s;
            for (int i = 0; i < N; ++i)
            {
                s.data()[i] = static_cast<T>(i * (i%2==0 ? 1 : -1));
            }
            return s;
        }

        static void TEST_CASE_scalar_constructor()
        {
            const simd<T, N> s(1.2L);
            for (int i = 0; i < N; ++i)
            {
                test_assert(s.data()[i] == static_cast<T>(1.2L));
            }
        }

        template<int M = N>
        static std::enable_if_t<M == 2> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = { static_cast<T>(1.2L), static_cast<T>(3.4L) };
            test_assert(s.data()[0] == static_cast<T>(1.2L));
            test_assert(s.data()[1] == static_cast<T>(3.4L));
        }

        template<int M = N>
        static std::enable_if_t<M == 4> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(1.2L),
                static_cast<T>(3.4L),
                static_cast<T>(5.6L),
                static_cast<T>(7.8L),
            };

            test_assert(s.data()[0] == static_cast<T>(1.2L));
            test_assert(s.data()[1] == static_cast<T>(3.4L));
            test_assert(s.data()[2] == static_cast<T>(5.6L));
            test_assert(s.data()[3] == static_cast<T>(7.8L));
        }

        template<int M = N>
        static std::enable_if_t<(M > 4)> TEST_CASE_component_constructor()
        {
        }

        // TODO: Explicit cast tests

        static void TEST_CASE_unary_plus_operator()
        {
            const simd<T, N> s1 = test_simd();
            const simd<T, N> s2 = +s1;
            for (int i = 0; i < N; ++i)
            {
                test_assert(s2.data()[i] == +s1.data()[i]);
            }
        }

        static void TEST_CASE_pre_increment_operator()
        {
            simd<T, N> s = test_simd();
            test_assert(&(++s) == &s);
            test_assert((s == test_simd() + simd<T, N>(1)));
        }

        static void TEST_CASE_post_increment_operator()
        {
            simd<T, N> s1 = test_simd();
            const simd<T, N> s2 = s1++;
            test_assert((s1 == test_simd() + simd<T, N>(1)));
            test_assert((s2 == test_simd()));
        }

        template<typename U = T>
        static std::enable_if_t<std::is_signed<U>::value>
        TEST_CASE_unary_minus_operator()
        {
            const simd<T, N> s1 = test_simd();
            const simd<T, N> s2 = -s1;
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
            simd<T, N> s = test_simd();
            test_assert(&(--s) == &s);
            test_assert((s == test_simd() - simd<T, N>(1)));
        }

        static void TEST_CASE_post_decrement_operator()
        {
            simd<T, N> s1 = test_simd();
            const simd<T, N> s2 = s1--;
            test_assert((s1 == test_simd() - simd<T, N>(1)));
            test_assert((s2 == test_simd()));
        }

        static void run_all()
        {
            common_simd_tests<Alias, T, N>::run_all();
            TEST_CASE_scalar_constructor();
            TEST_CASE_component_constructor();
            TEST_CASE_unary_plus_operator();
            TEST_CASE_pre_increment_operator();
            TEST_CASE_post_increment_operator();
            TEST_CASE_unary_minus_operator();
            TEST_CASE_pre_decrement_operator();
            TEST_CASE_post_decrement_operator();
        }
    };

    template<typename Alias, typename T, int N>
    struct bool_simd_tests
    {

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
            const simd<T, N> s = { static_cast<T>(12LL), static_cast<T>(34LL) };
            test_assert(s.data()[0] == static_cast<T>(12LL));
            test_assert(s.data()[1] == static_cast<T>(34LL));
        }

        template<int M = N>
        static std::enable_if_t<M == 4> TEST_CASE_component_constructor()
        {
            const simd<T, N> s = {
                static_cast<T>(12LL),
                static_cast<T>(34LL),
                static_cast<T>(56LL),
                static_cast<T>(78LL),
            };

            test_assert(s.data()[0] == static_cast<T>(12LL));
            test_assert(s.data()[1] == static_cast<T>(34LL));
            test_assert(s.data()[2] == static_cast<T>(56LL));
            test_assert(s.data()[3] == static_cast<T>(78LL));
        }

        template<int M = N>
        static std::enable_if_t<(M > 4)> TEST_CASE_component_constructor()
        {
        }

        // TODO: Explicit cast tests

        static void run_all()
        {
            common_simd_tests<Alias, T, N>::run_all();
            TEST_CASE_scalar_constructor();
            TEST_CASE_component_constructor();
        }
    };

#define FLOAT_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        arithmetic_simd_tests<Alias, T, N>::run_all(); \
    }

#define INT_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        arithmetic_simd_tests<Alias, T, N>::run_all(); \
    }

#define BOOL_SIMD_TEST_CASES(Alias, T, N) \
    TEST_CASE(Alias) \
    { \
        bool_simd_tests<Alias, T, N>::run_all(); \
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
