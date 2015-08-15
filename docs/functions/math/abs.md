[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`abs`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// (Where T is an arithmetic type, signed or unsigned)
template<typename T>
T abs(T x) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, int N>
vec<T, N> abs(const vec<T, N>& v) noexcept;

// (3)
// #include <tue/mat.hpp>
template<typename T, int C, int R>
mat<T, C, R> abs(const mat<T, C, R>& m) noexcept;

// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
simd<T, N> abs(const simd<T, N>& v) noexcept;
```

1. Returns the absolute value of the given number. Unlike the C++ Standard
   Library, this function also accepts and returns unsigned types.

2. Returns the result of passing each component of the given
   [`vec`](../../headers/vec.md) to `tue::math::abs`.

3. Returns the result of passing each component of the given
   [`mat`](../../headers/mat.md) to `tue::math::abs`.

4. Returns the result of passing each component of the given
   [`simd`](../../headers/simd.md) to `tue::math::abs`.

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
