[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`length2`
===================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is a floating-point type
template<typename T>
T length2(T x) noexcept;

// (2)
// #include <tue/math.hpp>
// Where T is an integral type
template<typename T>
double length2(T x) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
auto length2(const vec<T, N>& v) noexcept
    -> decltype(math::length2(v[0]));

// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
auto length2(const simd<T, N>& v) noexcept
    -> simd<decltype(math::length2(T())), N>;
```

1. Returns the result of the given number times itself. This function is
   provided for uniformity with the `vec` overload below.

2. Same as above after first converting `x` to a `double`.

2. Returns the length squared of the given [`vec`](../../headers/vec.md), i.e.,
   the sum of each of its components squared.

3. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::length2`. Note: this operates
   on each component individually unlike the `vec` overload above.

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
