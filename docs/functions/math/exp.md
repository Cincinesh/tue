[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`exp`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is a floating-point type
template<typename T>
T exp(T x) noexcept;

// (2)
// #include <tue/math.hpp>
// Where T is an integral type
template<typename T>
double exp(T x) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
auto exp(const vec<T, N>& v) noexcept
    -> vec<decltype(math::exp(v[0])), N>;

// (4)
// #include <tue/mat.hpp>
template<typename T, int C, int R>
auto exp(const mat<T, C, R>& m) noexcept
    -> mat<decltype(math::exp(m[0][0])), C, R>;

// (5)
// #include <tue/simd.hpp>
template<typename T, int N>
auto exp(const simd<T, N>& v) noexcept
    -> simd<decltype(math::exp(T())), N>;
```

1. Returns the base-e exponential function of `x`, i.e., `e` to the `x`.

2. Same as above after first converting `x` to a `double`.

3. Returns the result of passing each component of the given
   [`vec`](../../headers/vec.md) to `tue::math::exp`.

4. Returns the result of passing each component of the given
   [`mat`](../../headers/mat.md) to `tue::math::exp`.

5. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::exp`.

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
