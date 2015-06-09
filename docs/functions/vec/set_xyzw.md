[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`set_x, set_y, set_z, set_w`
=============================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, int N>
void vec<T, N>::set_x(const T& x) noexcept;

template<typename T, int N>
void vec<T, N>::set_y(const T& y) noexcept;

// (vec<T, 3> and vec<T, 4> only)
template<typename T, int N>
void vec<T, N>::set_z(const T& z) noexcept;

// (vec<T, 4> only)
template<typename T, int N>
void vec<T, N>::set_w(const T& w) noexcept;
```

Sets the first, second, third, and fourth components of this
[`vec`](../../headers/vec.md).

Aliases for the same components can also be modified via
[`set_r, set_g, set_b, set_a`](set_rgba.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
