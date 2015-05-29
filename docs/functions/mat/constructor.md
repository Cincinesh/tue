`tue::mat::mat` (constructor)
=============================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (1)
template<typename T, int C, int R>
mat<T, C, R>::mat() noexcept = default;

// (2)
template<typename T, int C, int R>
explicit constexpr mat<T, C, R>::mat(const T& s) noexcept;

// (3)
template<typename T, int C, int R>
template<OtherC, OtherR>
explicit constexpr mat<T, C, R>::mat(
    const mat<T, OtherC, OtherR>& other) noexcept;

// (4)
template<typename T, int C, int R>
template<typename U>
explicit constexpr mat<T, C, R>::mat(
    const mat<U, C, R>& other) noexcept;

// (5) (mat<T, 2, R> only)
template<typename T, int R>
constexpr mat<T, 2, R>::mat(
    const vec<T, R>& column0,
    const vec<T, R>& column1) noexcept

// (6) (mat<T, 3, R> only)
template<typename T, int R>
constexpr mat<T, 3, R>::mat(
    const vec<T, R>& column0,
    const vec<T, R>& column1,
    const vec<T, R>& column2) noexcept

// (7) (mat<T, 4, R> only)
template<typename T, int R>
constexpr mat<T, 4, R>::mat(
    const vec<T, R>& column0,
    const vec<T, R>& column1,
    const vec<T, R>& column2,
    const vec<T, R>& column3) noexcept
```

1) Default-constructs a new [`mat`](../../headers/mat.md)

2) Constructs a new `mat` with every component of the main diagonal set to `s`
   and all other components initialized to `0`.

3) Constructs a new `mat` using the corresponding components of another `mat`
   with the same component type but different dimensions. Unspecified components
   will be initialized to `0`. Unused components will be ignored.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
