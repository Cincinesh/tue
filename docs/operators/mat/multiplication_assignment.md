[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/multiplication assignment
==========================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (1) (m *= other)
template<typename T, typename U, int C, int R>
mat<T, C, R>& operator*=(mat<T, C, R>& m, const U& other) noexcept;

// (2) (v *= m)
template<typename T, typename U, int N>
vec<T, N>& operator*=(vec<T, N>& v, const mat<U, N, N>& other) noexcept;
```

1. Calculates [`m * other`](multiplication.md), stores the result in `m`, and
   returns a reference to `m`.

2. Calculates [`v * m`](multiplication.md), stores the result in `v`, and
   returns a reference to `v`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
