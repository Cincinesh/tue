[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`set_xyz, set_rgb`
===================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// (vec<T, 4> only)

template<typename T, int N>
void vec<T, N>::set_xyz(const vec3<T>& xyz) noexcept;

template<typename T, int N>
void vec<T, N>::set_rgb(const vec3<T>& xyz) noexcept;

template<typename T, int N>
void vec<T, N>::set_xyz(const T& x, const T& y, const T& z) noexcept;

template<typename T, int N>
void vec<T, N>::set_rgb(const T& r, const T& g, const T& b) noexcept;
```

Sets the first three components of this [`vec`](../../headers/vec.md), either
using a whole `vec3` or individual component values.

These functions are only available when `N > 3`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
