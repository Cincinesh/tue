[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`normalize`
=====================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is a floating-point type
template<typename T>
T normalize(T x) noexcept;

// (2)
// #include <tue/math.hpp>
// Where T is an integral type
template<typename T>
double normalize(T x) noexcept;

// (3)
// #include <tue/vec.hpp>
template<typename T, int N>
auto normalize(const vec<T, N>& v) noexcept
    -> vec<decltype(math::normalize(v)), N>;
// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
auto normalize(const simd<T, N>& v) noexcept
    -> simd<decltype(math::normalize(T())), N>;
```

1. Returns `+1` or `-1` to match the sign of the given number. This function is
   provided for uniformity with the `vec` overload below.

2. Same as above after first converting `x` to a `double`.

3. Returns a [`vec`](../../headers/vec.md) in the same direction as the given
   `vec` but with a length of `1`.

5. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::normalize`. Note: this
   operates on each component individually unlike the `vec` overload above.

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
