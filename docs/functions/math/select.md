[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`select`
==================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/math.hpp>
template<typename T>
constexpr T select(
    bool condition,
    const T& value,
    const T& otherwise = T(0)) noexcept;

// (2)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto select(
    const T& condition,
    const vec<U, N>& value,
    const vec<U, N>& otherwise = vec<U, N>::zero()) noexcept
    -> vec<decltype(math::select(condition, value[0], otherwise[0])), N>;

// (3)
// #include <tue/vec.hpp>
template<typename T, typename U, int N>
constexpr auto select(
    const vec<T, N>& condition,
    const vec<U, N>& value,
    const vec<U, N>& otherwise = vec<U, N>::zero()) noexcept
    -> vec<decltype(math::select(condition[0], value[0], otherwise[0])), N>;

// (4)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
constexpr auto select(
    const T& condition,
    const mat<U, C, R>& value,
    const mat<U, C, R>& otherwise = mat<U, C, R>::zero()) noexcept {
    -> mat<decltype(
           math::select(condition, value[0][0], otherwise[0][0])), C, R>;

// (5)
// #include <tue/mat.hpp>
template<typename T, typename U, int C, int R>
constexpr auto select(
    const mat<T, C, R>& condition,
    const mat<U, C, R>& value,
    const mat<U, C, R>& otherwise = mat<U, C, R>::zero()) noexcept {
    -> mat<decltype(
           math::select(condition[0][0], value[0][0], otherwise[0][0])), C, R>;

// (6)
// #include <simd.hpp>
// Where boolX is a sized bool type matching the size of T,
// e.g., if T is float, boolX is bool32.
template<typename T, int N>
constexpr simd<T, N> select(
    const simd<boolX, N>& condition,
    const simd<T, N>& value) noexcept;

// (7)
// #include <simd.hpp>
// Where boolX is a sized bool type matching the size of T,
// e.g., if T is float, boolX is bool32.
template<typename T, int N>
constexpr simd<T, N> select(
    const simd<boolX, N>& condition,
    const simd<T, N>& value,
    const simd<T, N>& otherwise) noexcept;
```

1. If `condition` is `true`, returns `value`. Otherwise, returns `otherwise`.

2. Returns the result of passing `condition` and each corresponding pair of
   components from `value` and `otherwise` to `tue::math::select`.

3. Returns the result of passing each corresponding triple of components from
   `condition`, `value`, and `otherwise` to `tue::math::select`.

4. Returns the result of passing `condition` and each corresponding pair of
   components from `value` and `otherwise` to `tue::math::select`.

5. Returns the result of passing each corresponding triple of components from
   `condition`, `value`, and `otherwise` to `tue::math::select`.

6. Returns the result of passing each corresponding pair of components from
   `condition` and `value` to `tue::math::select` with an implicit `otherwise`
   value of `0`.

7. Returns the result of passing each corresponding triple of components from
   `condition`, `value`, and `otherwise` to `tue::math::select`.

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
