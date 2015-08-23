[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`pow`
===============================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
// Where T and U are arithmetic types, and PromotedT and PromotedU are
// determined as in the description below.
template<typename T, typename U>
decltype(PromotedT() * PromotedU()) pow(T base, U exponent) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const T& base,
    const vec<U, N>& exponent) noexcept
    -> vec<decltype(math::pow(base, exponent[0])), N>;

// (3)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const vec<T, N>& base,
    const U& exponent) noexcept
    -> vec<decltype(math::pow(base[0], exponent)), N>;

// (4)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
auto pow(
    const vec<T, N>& base,
    const vec<U, N>& exponent) noexcept
    -> vec<decltype(math::pow(base[0], exponent[0])), N>;

// (5)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const T& base,
    const mat<U, C, R>& exponent) noexcept
    -> mat<decltype(math::pow(base, exponent[0][0])), C, R>;

// (6)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const mat<T, C, R>& base,
    const U& exponent) noexcept
    -> mat<decltype(math::pow(base[0][0], exponent)), C, R>;

// (7)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
auto pow(
    const mat<T, C, R>& base,
    const mat<U, C, R>& exponent) noexcept
    -> mat<decltype(math::pow(base[0][0], exponent[0][0])), C, R>;

// (8)
// #include <tue/simd.hpp>
template<typename T, int N>
auto pow(
    const simd<T, N>& base,
    const simd<T, N>& exponent) noexcept
    -> simd<decltype(math::pow(T(), T())), N>;
```

1. Returns the value of `base` raised to the `exponent` power. If an argument
   type is an integral type, it will be converted to type `double` unless the
   other argument type is a floating-point type larger than `double`, in which
   case it will be converted to that type. For example, `pow(int, float)` will
   be converted to `pow(double, float)`, but `pow(int, long double)` will be
   converted to `pow(long double, long double)`.

2. Returns the result of passing `base` and each component of `exponent` to
   `tue::math::pow`.

3. Returns the result of passing each component of `base` along with `exponent`
   to `tue::math::pow`.

4. Returns the result of passing each corresponding pair of components in `base`
   and `exponent` to `tue::math::pow`.

5. Returns the result of passing `base` and each component of `exponent` to
   `tue::math::pow`.

6. Returns the result of passing each component of `base` along with `exponent`
   to `tue::math::pow`.

7. Returns the result of passing each corresponding pair of components in `base`
   and `exponent` to `tue::math::pow`.

8. Returns the result of passing each corresponding pair of components in `base`
   and `exponent` to `tue::math::pow`.

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
