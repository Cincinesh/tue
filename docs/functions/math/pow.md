[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`pow`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
//
// Where T and U are arithmetic types, and PromotedT and PromotedU are
// determined as follows:
//
// - If T is a floating-type, PromotedT = T
// - If T is an integral type
//   - and U is an integral type, PromotedT = double
//   - and U is a floating-point type
//     - and sizeof(U) <= double, PromotedT = double
//     - and sizeof(U) > double, PromotedT = U
//
// - Swap T and U in the above rules to determine PromotedU
template<typename T, typename U>
decltype(PromotedT() * PromotedU()) pow(T base, U exponent) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const T& base,
    const vec<U, N>& exponent) noexcept
    -> vec<decltype(math::pow(base, exponent[0])), N>;

// (3)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const vec<T, N>& base,
    const U& exponent) noexcept
    -> vec<decltype(math::pow(base[0], exponent)), N>;

// (4)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const vec<T, N>& base,
    const vec<U, N>& exponent) noexcept
    -> vec<decltype(math::pow(base[0], exponent[0])), N>;

// (5)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const T& base,
    const mat<U, C, R>& exponent) noexcept
    -> mat<decltype(math::pow(base, exponent[0][0])), C, R>;

// (6)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const mat<T, C, R>& base,
    const U& exponent) noexcept
    -> mat<decltype(math::pow(base[0][0], exponent)), C, R>;

// (7)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const mat<T, C, R>& base,
    const mat<U, C, R>& exponent) noexcept
    -> mat<decltype(math::pow(base[0][0], exponent[0][0])), C, R>;

// (8)
// #include <tue/vec.hpp>
template<typename T, int N>
simd<T, N> pow(
    const simd<T, N>& base,
    const simd<T, N>& exponent) noexcept;
```

TODO.

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
