[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`sincos`
==================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is a floating-point type
template<typename T>
void sincos(T x, T& sin_out, T& cos_out) noexcept;

// (2)
// #include <tue/math.hpp>
// Where T is an integral type
template<typename T>
void sincos(T x, double& sin_out, double& cos_out) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
void sincos(
    const vec<T, N>& v,
    decltype(math::sin(v))& sin_result,
    decltype(math::cos(v))& cos_result) noexcept;

// (4)
// #include <tue/mat.hpp>
template<typename T, int N>
void sincos(
    const mat<T, N>& v,
    decltype(math::sin(v))& sin_result,
    decltype(math::cos(v))& cos_result) noexcept;

// (5)
// #include <tue/simd.hpp>
template<typename T, int N>
void sincos(
    const simd<T, N>& v,
    decltype(math::sin(v))& sin_result,
    decltype(math::cos(v))& cos_result) noexcept;
```

1. Computes the trigonometric sine and cosine of the given angle in radians and
   stores the results in the given reference arguments.

2. Same as above after first converting `x` to a `double`.

3. Calls `tue::math::sincos` on each corresponding triple of components from the
   given [`vec`](../../headers/vec.md)'s.

4. Calls `tue::math::sincos` on each corresponding triple of components from the
   given [`mat`](../../headers/mat.md)'s.

5. Calls `tue::math::sincos` on each corresponding triple of components from the
   given [`simd`](../../headers/simd.md)'s.

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
