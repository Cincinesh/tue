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
            test_assert((simd<T, N>::component_count == N));
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
            simd<T, N> s;
            for (int i = 0; i < N; ++i)
            {
                s.data()[i] = static_cast<T>(i);
            }

            const auto& cs = s;
            alignas(simd<T, N>) T data[N];
            cs.store(data);
            for (int i = 0; i < N; ++i)
            {
                data[i] = cs.data()[i];
            }
        }

        static void TEST_CASE_storeu()
        {
            simd<T, N> s;
            for (int i = 0; i < N; ++i)
            {
                s.data()[i] = static_cast<T>(i);
            }

            const auto& cs = s;
            alignas(simd<T, N>) T data[N + 1];
            cs.store(data + 1);
            for (int i = 0; i < N; ++i)
            {
                data[i + 1] = cs.data()[i];
            }
        }

        static void TEST_CASE_data()
        {
            const simd<T, N> cs(0);
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

        static void run_all()
        {
            common_simd_tests<Alias, T, N>;
            TEST_CASE_scalar_constructor();
            TEST_CASE_component_constructor();
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
            common_simd_tests<Alias, T, N>;
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
    FLOAT_SIMD_TEST_CASES(float64x2, double, 2)
    FLOAT_SIMD_TEST_CASES(float64x4, double, 4)
    INT_SIMD_TEST_CASES(int32x2, std::int32_t, 2)
    INT_SIMD_TEST_CASES(int32x4, std::int32_t, 4)
    INT_SIMD_TEST_CASES(int64x2, std::int64_t, 2)
    INT_SIMD_TEST_CASES(int64x4, std::int64_t, 4)
    INT_SIMD_TEST_CASES(uint32x2, std::uint32_t, 2)
    INT_SIMD_TEST_CASES(uint32x4, std::uint32_t, 4)
    INT_SIMD_TEST_CASES(uint64x2, std::uint64_t, 2)
    INT_SIMD_TEST_CASES(uint64x4, std::uint64_t, 4)
    BOOL_SIMD_TEST_CASES(bool32x2, bool32, 2)
    BOOL_SIMD_TEST_CASES(bool32x4, bool32, 4)
    BOOL_SIMD_TEST_CASES(bool64x2, bool64, 2)
    BOOL_SIMD_TEST_CASES(bool64x4, bool64, 4)
}
