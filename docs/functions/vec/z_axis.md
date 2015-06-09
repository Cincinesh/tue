[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`z_axis` (static)
==================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// (vec<T, 3> and vec<T, 4> only)
template<typename T, int N>
constexpr vec<T, N> vec<T, N>::z_axis() noexcept
```

Creates a new [`vec`](../../headers/vec.md) with the third component set to `1`
and all other components set to `0`.

This function is only available when `N >= 3`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
