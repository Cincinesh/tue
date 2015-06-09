[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`x, y, z, w`
=============================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, int N>
constexpr T vec<T, N>::x() const noexcept;

template<typename T, int N>
constexpr T vec<T, N>::y() const noexcept;

// (vec<T, 3> and vec<T, 4> only)
template<typename T, int N>
constexpr T vec<T, N>::z() const noexcept;

// (vec<T, 4> only)
template<typename T, int N>
constexpr T vec<T, N>::w() const noexcept;
```

Returns copies of the first, second, third, and fourth components of this
[`vec`](../../headers/vec.md).

Aliases for the same components can also be accessed via
[`r, g, b, a`](rgba.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
