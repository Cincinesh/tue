[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/bitwise XOR
============================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// lhs ^ rhs

template<typename T, typename U, int N>
constexpr auto operator^(
    const T& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(lhs ^ rhs[0]), N>;

template<typename T, typename U, int N>
constexpr auto operator^(
    const vec<T, N>& lhs,
    const U& rhs) noexcept
    -> vec<decltype(lhs[0] ^ rhs), N>;

template<typename T, typename U, int N>
constexpr auto operator^(
    const vec<T, N>& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(lhs[0] ^ rhs[0]), N>;
```

Returns the result of a component-wise bitwise XOR operation. If one argument is
a scalar, the result will be as if it were a [`vec`](../../headers/vec.md) with
each component set to the value of that scalar.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
