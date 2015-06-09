[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`xyz`
======================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// (vec<T, 4> only)
template<typename T, int N>
constexpr vec3<T> vec<T, N>::xyz() const noexcept;
```

Returns a copy of the first three components of this
[`vec`](../../headers/vec.md) in the form of a `vec3`. This function is only
available when `N > 3`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
