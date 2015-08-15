[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`dot`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// (Where T and U are both arithmetic types)
template<typename T, typename U>
constexpr decltype(T() * U()) dot(T lhs, U rhs) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto dot(
    const vec<T, N>& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(lhs[0] * rhs[0]), N>;
```

1. Returns the result of multiplying the two given numbers. This function is
   provided for uniformity with the other overload below.

2. Returns the dot-product of the two given [`vec`](../../headers/vec.md)'s.

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
