[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`not_equal`
=====================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T and U are both arithmetic types
template<typename T, typename U>
constexpr bool not_equal(T lhs, U rhs) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto not_equal(
    const vec<T, N>& lhs,
    const vec<T, N>& rhs) noexcept
    -> vec<decltype(math::not_equal(lhs[0], rhs[0])), N>;

// (3)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
constexpr auto not_equal(
    const mat<T, C, R>& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> mat<decltype(math::not_equal(lhs[0][0], rhs[0][0])), C, R>;

// (4)
// #include <tue/simd.hpp>
// Where boolX is a sized bool type matching the size of T,
// e.g., if T is float, boolX is bool32.
template<typename T, int N>
simd<boolX, N> not_equal(
    const simd<T, N>& lhs,
    const simd<T, N>& rhs) noexcept;
```

1. Returns `false` if the two given numbers are equal and `true` otherwise. This
   function is provided for uniformity with the other overloads below.

2. Returns the result of passing each corresponding pair of components from the
   two given [`vec`](../../headers/vec.md)'s to `tue::math::not_equal`.

3. Returns the result of passing each corresponding pair of components from the
   two given [`mat`](../../headers/mat.md)'s to `tue::math::not_equal`.

4. Returns the result of passing each corresponding pair of components from the
   two given [`simd`](../../headers/simd.md)'s to `tue::math::not_equal`
   converted to the appropriate sized bool type.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
