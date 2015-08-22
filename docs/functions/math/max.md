[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`max`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is an arithmetic type
template<typename T>
T max(T x1, T x2) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, int N>
auto max(
    const vec<T, N>& v1,
    const vec<T, N>& v2)
    -> vec<decltype(math::max(lhs[0], rhs[0])), N>;

// (3)
// #include <tue/mat.hpp>
template<typename T, int C, int R>
auto max(
    const mat<T, C, R>& m1,
    const mat<T, C, R>& m2)
    -> mat<decltype(math::max(lhs[0][0], rhs[0][0])), C, R>;

// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
simd<T, N> max(
    const simd<T, N>& lhs,
    const simd<T, N>& rhs);
```

1. Returns the maximum of the two given numbers. This function is provided for
   uniformity with the other overloads below.

2. Returns the result of passing each corresponding pair of components from the
   two given [`vec`](../../headers/vec.md)'s to `tue::math::max`.

3. Returns the result of passing each corresponding pair of components from the
   two given [`mat`](../../headers/mat.md)'s to `tue::math::max`.

4. Returns the result of passing each corresponding pair of components from the
   two given [`simd`](../../headers/simd.md)'s to `tue::math::max`.

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
