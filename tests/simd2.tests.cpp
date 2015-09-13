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

    TEST_CASE(size)
    {
        test_assert(sizeof(simd2<short>) == sizeof(short) * 2);
        test_assert(sizeof(float32x2) == sizeof(float) * 2);
        test_assert(sizeof(float64x2) == sizeof(double) * 2);
        test_assert(sizeof(int32x2) == sizeof(std::int32_t) * 2);
        test_assert(sizeof(int64x2) == sizeof(std::int64_t) * 2);
        test_assert(sizeof(uint32x2) == sizeof(std::uint32_t) * 2);
        test_assert(sizeof(uint64x2) == sizeof(std::uint64_t) * 2);
        test_assert(sizeof(bool32x2) == sizeof(bool32) * 2);
        test_assert(sizeof(bool64x2) == sizeof(bool64) * 2);
    }

    TEST_CASE(alignment)
    {
        test_assert(alignof(simd2<short>) == sizeof(short) * 2);
        test_assert(alignof(float32x2) == sizeof(float) * 2);
        test_assert(alignof(float64x2) == sizeof(double) * 2);
        test_assert(alignof(int32x2) == sizeof(std::int32_t) * 2);
        test_assert(alignof(int64x2) == sizeof(std::int64_t) * 2);
        test_assert(alignof(uint32x2) == sizeof(std::uint32_t) * 2);
        test_assert(alignof(uint64x2) == sizeof(std::uint64_t) * 2);
        test_assert(alignof(bool32x2) == sizeof(bool32) * 2);
        test_assert(alignof(bool64x2) == sizeof(bool64) * 2);
    }

    TEST_CASE(component_type)
    {
        test_assert((std::is_same<
            typename simd2<short>::component_type, short>::value));
        test_assert((std::is_same<
            typename float32x2::component_type, float>::value));
        test_assert((std::is_same<
            typename float64x2::component_type, double>::value));
        test_assert((std::is_same<
            typename int32x2::component_type, std::int32_t>::value));
        test_assert((std::is_same<
            typename int64x2::component_type, std::int64_t>::value));
        test_assert((std::is_same<
            typename uint32x2::component_type, std::uint32_t>::value));
        test_assert((std::is_same<
            typename uint64x2::component_type, std::uint64_t>::value));
        test_assert((std::is_same<
            typename bool32x2::component_type, bool32>::value));
        test_assert((std::is_same<
            typename bool64x2::component_type, bool64>::value));
    }

    TEST_CASE(component_count)
    {
        test_assert(simd2<short>::component_count == 2);
        test_assert(float32x2::component_count == 2);
        test_assert(float64x2::component_count == 2);
        test_assert(int32x2::component_count == 2);
        test_assert(int64x2::component_count == 2);
        test_assert(uint32x2::component_count == 2);
        test_assert(uint64x2::component_count == 2);
        test_assert(bool32x2::component_count == 2);
        test_assert(bool64x2::component_count == 2);
    }

    TEST_CASE(default_constructor)
    {
        float64x2 s;
        unused(s);
    }

    TEST_CASE(scalar_constructor)
    {
        const float32x2 s(1.2);
        test_assert(s.data()[0] == 1.2f);
        test_assert(s.data()[1] == 1.2f);
    }

    TEST_CASE(individual_components_constructor)
    {
        const float64x2 s = { 1.2, 3.4 };
        test_assert(s.data()[0] == 1.2);
        test_assert(s.data()[1] == 3.4);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        const float64x2 s1(1.2, 3.4);
        const float32x2 s2(s1);
        test_assert(s2.data()[0] == 1.2f);
        test_assert(s2.data()[1] == 3.4f);
    }

    TEST_CASE(zero)
    {
        const auto s = float64x2::zero();
        test_assert(s.data()[0] == 0.0);
        test_assert(s.data()[1] == 0.0);
    }

    TEST_CASE(load)
    {
        alignas(16) double data[2] = { 1.2, 3.4 };
        const auto s = float64x2::load(data);
        test_assert(s.data()[0] == 1.2);
        test_assert(s.data()[1] == 3.4);
    }

    TEST_CASE(loadu)
    {
        alignas(16) double data[3] = { 0.0, 1.2, 3.4 };
        const auto s = float64x2::loadu(data + 1);
        test_assert(s.data()[0] == 1.2);
        test_assert(s.data()[1] == 3.4);
    }

    TEST_CASE(store)
    {
        const float64x2 s(1.2, 3.4);
        alignas(16) double data[2];
        s.store(data);
        test_assert(data[0] == 1.2);
        test_assert(data[1] == 3.4);
    }

    TEST_CASE(storeu)
    {
        const float64x2 s(1.2, 3.4);
        alignas(16) double data[3];
        s.storeu(data + 1);
        test_assert(data[1] == 1.2);
        test_assert(data[2] == 3.4);
    }

    TEST_CASE(data)
    {
        const float64x2 cs(1.2);
        const double* cdata = cs.data();
        test_assert(cdata == static_cast<const void*>(&cs));

        float64x2 s;
        double* data = s.data();
        test_assert(data == static_cast<void*>(&s));
    }
}
