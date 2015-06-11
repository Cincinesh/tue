//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tue/simd.hpp>
#include <mon/test_case.hpp>

#include <tue/unused.hpp>

namespace {
using namespace tue;

TEST_CASE(default_constructor) {
  bool32x4 v;
  unused(v);
}

TEST_CASE(scalar_constructor) {
  test_assert(
      bool32x4(true32)
      == bool32x4(true32, true32, true32, true32));
  test_assert(
      bool32x4(false32)
      == bool32x4(false32, false32, false32, false32));
}

TEST_CASE(component_constructor) {
  const bool32x4 v1 = { true32, true32, false32, false32 };
  bool32 b[4];
  v1.storeu(b);
  test_assert(b[0] == true32);
  test_assert(b[1] == true32);
  test_assert(b[2] == false32);
  test_assert(b[3] == false32);

  const bool32x4 v2 = { true32, false32, true32, false32 };
  v2.storeu(b);
  test_assert(b[0] == true32);
  test_assert(b[1] == false32);
  test_assert(b[2] == true32);
  test_assert(b[3] == false32);
}

#if defined(TUE_SSE)
TEST_CASE(m128_converison_constructor) {
  const __m128 underlying1 = _mm_setr_ps(
      detail_::binary_float(true32),
      detail_::binary_float(true32),
      detail_::binary_float(false32),
      detail_::binary_float(false32));
  const bool32x4 v1(underlying1);
  test_assert(v1 == bool32x4(true32, true32, false32, false32));

  const __m128 underlying2 = _mm_setr_ps(
      detail_::binary_float(true32),
      detail_::binary_float(false32),
      detail_::binary_float(true32),
      detail_::binary_float(false32));
  const bool32x4 v2(underlying2);
  test_assert(v2 == bool32x4(true32, false32, true32, false32));
}

TEST_CASE(m128_converison_operator) {
  const __m128 underlying1 = bool32x4(true32, true32, false32, false32);
  bool32 result[4];
  _mm_storeu_ps(reinterpret_cast<float*>(result), underlying1);
  test_assert(result[0] == true32);
  test_assert(result[1] == true32);
  test_assert(result[2] == false32);
  test_assert(result[3] == false32);

  const __m128 underlying2 = bool32x4(true32, false32, true32, false32);
  _mm_storeu_ps(reinterpret_cast<float*>(result), underlying2);
  test_assert(result[0] == true32);
  test_assert(result[1] == false32);
  test_assert(result[2] == true32);
  test_assert(result[3] == false32);
}
#endif

#if defined(TUE_SSE2)
TEST_CASE(m128i_converison_constructor) {
  const __m128i underlying1 = _mm_setr_epi32(true32, true32, false32, false32);
  const bool32x4 v1(underlying1);
  test_assert(v1 == bool32x4(true32, true32, false32, false32));

  const __m128i underlying2 = _mm_setr_epi32(true32, false32, true32, false32);
  const bool32x4 v2(underlying2);
  test_assert(v2 == bool32x4(true32, false32, true32, false32));
}

TEST_CASE(m128i_converison_operator) {
  const __m128i underlying1 = bool32x4(true32, true32, false32, false32);
  bool32 result[4];
  _mm_storeu_si128(reinterpret_cast<__m128i*>(result), underlying1);
  test_assert(result[0] == true32);
  test_assert(result[1] == true32);
  test_assert(result[2] == false32);
  test_assert(result[3] == false32);

  const __m128 underlying2 = bool32x4(true32, false32, true32, false32);
  _mm_storeu_ps(reinterpret_cast<float*>(result), underlying2);
  test_assert(result[0] == true32);
  test_assert(result[1] == false32);
  test_assert(result[2] == true32);
  test_assert(result[3] == false32);
}
#endif

TEST_CASE(load) {
  alignas(16) const bool32 array1[4] = { true32, true32, false32, false32 };
  const auto v1 = bool32x4::load(array1);
  test_assert(v1 == bool32x4(true32, true32, false32, false32));

  alignas(16) const bool32 array2[4] = { true32, false32, true32, false32 };
  const auto v2 = bool32x4::load(array2);
  test_assert(v2 == bool32x4(true32, false32, true32, false32));
}

TEST_CASE(loadu) {
  alignas(16) const bool32 array1[5] =
      { true32, true32, true32, false32, false32 };
  const auto v1 = bool32x4::loadu(array1 + 1);
  test_assert(v1 == bool32x4(true32, true32, false32, false32));

  alignas(16) const bool32 array2[5] =
      { false32, true32, false32, true32, false32 };
  const auto v2 = bool32x4::loadu(array2 + 1);
  test_assert(v2 == bool32x4(true32, false32, true32, false32));
}

TEST_CASE(store) {
  const bool32x4 v1(true32, true32, false32, false32);
  alignas(16) bool32 result[4];
  v1.store(result);
  test_assert(result[0] == true32);
  test_assert(result[1] == true32);
  test_assert(result[2] == false32);
  test_assert(result[3] == false32);

  const bool32x4 v2(true32, false32, true32, false32);
  v2.store(result);
  test_assert(result[0] == true32);
  test_assert(result[1] == false32);
  test_assert(result[2] == true32);
  test_assert(result[3] == false32);
}

TEST_CASE(storeu) {
  const bool32x4 v1(true32, true32, false32, false32);
  alignas(16) bool32 result[5];
  v1.storeu(result + 1);
  test_assert(result[1] == true32);
  test_assert(result[2] == true32);
  test_assert(result[3] == false32);
  test_assert(result[4] == false32);

  const bool32x4 v2(true32, false32, true32, false32);
  v2.storeu(result + 1);
  test_assert(result[1] == true32);
  test_assert(result[2] == false32);
  test_assert(result[3] == true32);
  test_assert(result[4] == false32);
}

TEST_CASE(not_operator) {
  const bool32x4 v1(true32, true32, false32, false32);
  test_assert(~v1 == bool32x4(false32, false32, true32, true32));

  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(~v2 == bool32x4(false32, true32, false32, true32));
}

TEST_CASE(and_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 & v2) == bool32x4(false32, false32, false32, false32));
  test_assert((v1 & v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v1 & v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v2 & v3) == bool32x4(false32, false32, false32, false32));
  test_assert((v2 & v4) == bool32x4(false32, false32, false32, false32));
  test_assert((v3 & v4) == bool32x4(false32, false32, false32, false32));
}

TEST_CASE(or_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 | v2) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 | v3) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 | v4) == bool32x4(true32, true32, true32, true32));
  test_assert((v2 | v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 | v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v3 | v4) == bool32x4(true32, true32, true32, true32));
}

TEST_CASE(xor_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(false32, false32, false32, false32);
  const bool32x4 v3(true32, false32, true32, false32);
  const bool32x4 v4(false32, true32, false32, true32);
  test_assert((v1 ^ v2) == bool32x4(true32, true32, true32, true32));
  test_assert((v1 ^ v3) == bool32x4(false32, true32, false32, true32));
  test_assert((v1 ^ v4) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 ^ v3) == bool32x4(true32, false32, true32, false32));
  test_assert((v2 ^ v4) == bool32x4(false32, true32, false32, true32));
  test_assert((v3 ^ v4) == bool32x4(true32, true32, true32, true32));
}

TEST_CASE(and_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 &= v2) == &v1);
  test_assert(v1 == bool32x4(true32, false32, false32, false32));
}

TEST_CASE(or_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 |= v2) == &v1);
  test_assert(v1 == bool32x4(true32, true32, true32, false32));
}

TEST_CASE(xor_assignment_operator) {
  bool32x4 v1(true32, true32, false32, false32);
  const bool32x4 v2(true32, false32, true32, false32);
  test_assert(&(v1 ^= v2) == &v1);
  test_assert(v1 == bool32x4(false32, true32, true32, false32));
}

TEST_CASE(equality_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(true32, true32, true32, true32);
  const bool32x4 v3(false32, true32, true32, true32);
  const bool32x4 v4(true32, false32, true32, true32);
  const bool32x4 v5(true32, true32, false32, true32);
  const bool32x4 v6(true32, true32, true32, false32);
  test_assert((v1 == v2) == true);
  test_assert((v1 == v3) == false);
  test_assert((v1 == v4) == false);
  test_assert((v1 == v5) == false);
  test_assert((v1 == v6) == false);
}

TEST_CASE(inequality_operator) {
  const bool32x4 v1(true32, true32, true32, true32);
  const bool32x4 v2(true32, true32, true32, true32);
  const bool32x4 v3(false32, true32, true32, true32);
  const bool32x4 v4(true32, false32, true32, true32);
  const bool32x4 v5(true32, true32, false32, true32);
  const bool32x4 v6(true32, true32, true32, false32);
  test_assert((v1 != v2) == false);
  test_assert((v1 != v3) == true);
  test_assert((v1 != v4) == true);
  test_assert((v1 != v5) == true);
  test_assert((v1 != v6) == true);
}

}
