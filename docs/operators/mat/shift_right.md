[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/bitwise shift right
====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// lhs >> rhs

template<typename T, typename U, int C, int R>
constexpr auto operator>>(
    const T& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> mat<decltype(lhs >> rhs[0][0]), C, R>;

template<typename T, typename U, int C, int R>
constexpr auto operator>>(
    const mat<T, C, R>& lhs,
    const U& rhs) noexcept
    -> mat<decltype(lhs[0][0] >> rhs), C, R>;

template<typename T, typename U, int C, int R>
constexpr auto operator>>(
    const mat<T, C, R>& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> mat<decltype(lhs[0][0] >> rhs[0][0]), C, R>;
```

Returns the result of a component-wise bitwise shift right. If one argument is a
scalar, the result will be as if it were a [`mat`](../../headers/mat.md) with
each component set to the value of that scalar.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
