[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`transpose`
=====================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T is an arithmetic type
template<typename T>
constexpr T transpose(T x) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, int N>
constexpr vec<T, N> transpose(const vec<T, N>& v) noexcept;

// (3)
// #include <tue/mat.hpp>
template<typename T, int C, int R>
constexpr mat<T, C, R> transpose(const mat<T, R, C>& m) noexcept;

// (4)
// #include <tue/simd.hpp>
template<typename T, int N>
simd<T, N> transpose(const simd<T, N>& v) noexcept;
```

1. Returns a copy of the given value. This function is provided for uniformity
   with the `mat` overload below.

2. Returns a copy of the given [`vec`](../../headers/vec.md). This function is
   provided for uniformity with the `mat` overload below.

3. Returns the transpose of the given [`mat`](../../headers/mat.md), i.e., a
   matrix whose columns equal the rows of the input matrix.

4. Returns a copy of the given [`simd`](../../headers/simd.md). This function is
   provided for uniformity with the `mat` overload above.

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
