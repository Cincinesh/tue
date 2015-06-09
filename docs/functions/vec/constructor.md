[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/constructor
============================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// (1)
template<typename T, int N>
vec<T, N>::vec() noexcept = default;

// (2)
template<typename T, int N>
explicit constexpr vec<T, N>::vec(
    const T& s) noexcept;

// (3)
template<typename T, int N>
template<typename U>
explicit constexpr vec<T, N>::vec(
    const vec<U, N>& other) noexcept;

// (4) (vec<T, 2> only)
template<typename T>
constexpr vec<T, 2>::vec(
    const T& x, const T& y) noexcept;

// (5) (vec<T, 3> only)
template<typename T>
constexpr vec<T, 3>::vec(
    const T& x, const T& y const T& z) noexcept;

// (6) (vec<T, 3> only)
template<typename T>
constexpr vec<T, 3>::vec(
    const vec2<T>& xy, const T& z) noexcept;

// (7) (vec<T, 4> only)
template<typename T>
constexpr vec<T, 4>::vec(
    const T& x, const T& y const T& z, const T& w) noexcept;

// (8) (vec<T, 4> only)
template<typename T>
constexpr vec<T, 4>::vec(
    const vec2<T>& xy, const T& z, const T& w) noexcept;

// (9) (vec<T, 4> only)
template<typename T>
constexpr vec<T, 4>::vec(
    const vec3<T>& xyz, const T& w) noexcept;

// (10) (OtherN must be > N)
template<typename T, int N>
template<int OtherN>
explicit constexpr vec<T, N>::vec(
    const vec<T, OtherN>& other) noexcept;
```

1. Default-constructs a new [`vec`](../../headers/vec.md).

2. Constructs a new `vec` with each and every component set to the value of `s`.

3. Explicitly converts the corresponding components of another `vec` with the
   same component count but a different component type to the new `vec`'s
   component type. Implicit [conversion](conversion.md) is also available.

4. Constructs a new `vec2` with the given component values.

5. Constructs a new `vec3` with the given component values.

6. Constructs a new `vec3` with the given component values.

7. Constructs a new `vec4` with the given component values.

8. Constructs a new `vec4` with the given component values.

9. Constructs a new `vec4` with the given component values.

10. Truncates a `vec` with the same component type but a greater component count
    to the new `vec`'s component count.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
