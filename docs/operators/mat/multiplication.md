[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/multiplication
==========================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

Scalar multiplication
---------------------
```c++
// lhs * rhs

template<typename T, typename U, int C, int R>
constexpr auto operator*(
    const T& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> mat<decltype(lhs * rhs[0][0]), C, R>;

template<typename T, typename U, int C, int R>
constexpr auto operator*(
    const mat<T, C, R>& lhs,
    const U& rhs) noexcept
    -> mat<decltype(lhs[0][0] * rhs), C, R>;
```

Returns the result of component-wise matrix multiplication, i.e., the result of
multiplying each component of the [`mat`](../../headers/mat.md) argument by the
value of the scalar argument.

Matrix multiplication
---------------------
```c++
// lhs * rhs

template<typename T, typename U, int C, int R>
constexpr auto operator*(
    const vec<T, R>& lhs,
    const mat<U, C, R>& rhs) noexcept
    -> vec<decltype(lhs[0] * rhs[0][0]), C>;

template<typename T, typename U, int C, int R>
constexpr auto operator*(
    const mat<T, C, R>& lhs,
    const vec<U, C>& rhs) noexcept
    -> vec<decltype(lhs[0][0] * rhs[0]), R>;

template<typename T, typename U, int C, int R, int X>
constexpr auto operator*(
    const mat<T, X, R>& lhs,
    const mat<U, C, X>& rhs) noexcept
    -> vec<decltype(lhs[0][0] * rhs[0][0]), C, R>;
```

Returns the result of matrix multiplication. The number of columns in the
left-hand side argument must match the number of rows in the right-hand side
argument.

If the left-hand side argument is a [`vec`](../../headers/vec.md), it will be
interpreted as a matrix with one row.

If the right-hand side argument is a `vec`, it will be interpreted as a matrix
with one column.

To perform component-wise matrix multiplication, use
[`tue::math::comp_mult`](../../functions/math/comp_mult.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
