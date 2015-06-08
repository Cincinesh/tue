[Tuesday](../../../README.md)/[`vec`](../../headers/vec.md)/multiplication
==========================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// lhs * rhs

template<typename T, typename U, int N>
constexpr auto operator*(
    const T& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(lhs * rhs[0]), N>;

template<typename T, typename U, int N>
constexpr auto operator*(
    const vec<T, N>& lhs,
    const U& rhs) noexcept
    -> vec<decltype(lhs[0] * rhs), N>;

template<typename T, typename U, int N>
constexpr auto operator*(
    const vec<T, N>& lhs,
    const vec<U, N>& rhs) noexcept
    -> vec<decltype(lhs[0] * rhs[0]), N>;
```

Returns the result of component-wise vector multiplication. If one argument is a
scalar, the result will be as if it were a [`vec`](../../headers/vec.md) with
each component set to the value of that scalar.

`vec`'s can also be operands in
[`quat multiplication`](../quat/multiplication.md) and
[`mat multiplication`](../mat/multiplication.md).

To calculate the dot product or the cross product of two `vec`'s, see
[`math::dot`](../../functions/math/dot.md) or
[`math::cross`](../../functions/math/cross.md) respectively.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
