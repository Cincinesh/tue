[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`set_r, set_g, set_b, set_a`
=============================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, int N>
void vec<T, N>::set_r(const T& r) noexcept;

template<typename T, int N>
void vec<T, N>::set_g(const T& g) noexcept;

// (vec<T, 3> and vec<T, 4> only)
template<typename T, int N>
void vec<T, N>::set_b(const T& b) noexcept;

// (vec<T, 4> only)
template<typename T, int N>
void vec<T, N>::set_a(const T& a) noexcept;
```

Sets the first, second, third, and fourth components of this
[`vec`](../../headers/vec.md). 

Aliases for the same components can also be modified via
[`set_x, set_y, set_z, set_w`](set_xyzw.md).

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
