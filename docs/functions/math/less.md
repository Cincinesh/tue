[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`less`
================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// (Where T and U are both arithmetic types)
template<typename T, typename U>
constexpr bool less(T lhs, U rhs) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto less(
    const vec<T, N>& lhs,
    const vec<T, N>& rhs)
    -> vec<decltype(math::less(lhs[0], rhs[0])), N>;

// (3)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
constexpr auto less(
    const mat<T, C, R>& lhs,
    const mat<U, C, R>& rhs)
    -> mat<decltype(math::less(lhs[0][0], rhs[0][0])), C, R>;

// (4)
// #include <tue/simd.hpp>
// (Where boolX is a sized bool type matching the size of T,
//  e.g., if T is float, boolX is bool32)
template<typename T, int N>
constexpr simd<boolX, N> less(
    const simd<T, N>& lhs,
    const simd<T, N>& rhs);
```

1. Returns `true` if `lhs` is less than `rhs` and `false` otherwise. This
   function is provided for uniformity with the other overloads below.

2. Returns the result of passing each corresponding pair of components from the
   two given [`vec`](../../headers/vec.md)'s to `tue::math::less`.

3. Returns the result of passing each corresponding pair of components from the
   two given [`mat`](../../headers/mat.md)'s to `tue::math::less`.

4. Returns the result of passing each corresponding pair of components from the
   two given [`simd`](../../headers/simd.md)'s to `tue::math::less` converted to
   the appropriate sized bool type.

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
