[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`set_xy, set_rg`
=================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// (vec<T, 3> and vec<T, 4> only)

template<typename T, int N>
void vec<T, N>::set_xy(const vec2<T>& xy) noexcept;

template<typename T, int N>
void vec<T, N>::set_rg(const vec2<T>& rg) noexcept;

template<typename T, int N>
void vec<T, N>::set_xy(const T& x, const T& y) noexcept;

template<typename T, int N>
void vec<T, N>::set_rg(const T& r, const T& g) noexcept;
```

Sets the first two components of this [`vec`](../../headers/vec.md), either
using a whole `vec2` or individual component values.

These functions are only available when `N > 2`.

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
