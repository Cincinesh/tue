[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`comp_mult`
=====================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T and U are both arithmetic types
template<typename T, typename U>
constexpr decltype(T() * U()) comp_mult(T lhs, U rhs) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto comp_mult(
    const vec<T, N>& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(math::comp_mult(lhs[0], rhs[0])), N>;

// (3)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
constexpr auto comp_mult(
    const mat<T, C, R>& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> mat<decltype(math::comp_mult(lhs[0][0], rhs[0][0])), C, R>;

// (4)
// #include <tue/simd.hpp>
template<typename T, typename U, int N>
auto comp_mult(
    const simd<T, N>& lhs,
    const simd<U, N>& rhs) noexcept
    -> simd<decltype(math::comp_mult(T(), U())), N>;
```

1. Returns the result of multiplying the two given numbers. This function is
   provided for uniformity with the other overloads below.

2. Returns the result of passing each corresponding pair of components from the
   two given [`vec`](../../headers/vec.md)'s to `tue::math::comp_mult`.

3. Returns the result of passing each corresponding pair of components from the
   two given [`mat`](../../headers/mat.md)'s to `tue::math::comp_mult`.

4. Returns the result of passing each corresponding pair of components from the
   two given [`simd`](../../headers/simd.md)'s to `tue::math::comp_mult`.

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
