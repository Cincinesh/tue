[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`cos`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is a floating-point type
template<typename T>
T cos(T x) noexcept;

// (2)
// #include <tue/math.hpp>
// Where T is an integral type
template<typename T>
double cos(T x) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
auto cos(const vec<T, N>& v) noexcept
    -> vec<decltype(math::cos(v[0])), N>;

// (4)
// #include <tue/mat.hpp>
template<typename T, int C, int R>
auto cos(const mat<T, C, R>& m) noexcept
    -> mat<decltype(math::cos(m[0][0])), C, R>;

// (5)
// #include <tue/simd.hpp>
template<typename T, int N>
auto cos(const simd<T, N>& v) noexcept
    -> simd<decltype(math::cos(T())), N>;
```

1. Returns the cosine of the given value.

2. Same as above after first converting `x` to a `double`.

3. Returns the result of passing each component of the given
   [`vec`](../../headers/vec.md) to `tue::math::cos`.

4. Returns the result of passing each component of the given
   [`mat`](../../headers/mat.md) to `tue::math::cos`.

5. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::cos`.

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
