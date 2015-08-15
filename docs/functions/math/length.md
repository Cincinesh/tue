[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`length`
==================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// (Where T is a floating-point type)
template<typename T>
T length(T x) noexcept;

// (2)
// #include <tue/math.hpp>
// (Where T is an integral type)
template<typename T>
double length(T x) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
constexpr auto length(const vec<T, N>& v) noexcept
    -> decltype(math::sqrt(math::length2(v)));

// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
simd<T, N> length(const simd<T, N>& v) noexcept;
```

1. Returns the absolute value of the given number. This function is provided for
   uniformity with the `vec` overload below.

2. Same as above after first converting `x` to a `double`.

2. Returns the length of the given [`vec`](../../headers/vec.md), i.e., the
   square root of the sum of each of its components squared.

3. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::length`. Note: this is NOT the
   vector length like the `vec` overload above.

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
