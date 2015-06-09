[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/`v, s`
=========================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// (1)
template<typename T>
constexpr vec3<T> quat<T>::v() const noexcept;

// (2)
template<typename T>
constexpr T quat<T>::s() const noexcept;
```

1. Returns a copy of the first three components (i.e. the vector part) of this
   [`quat`](../../headers/quat.md) in the form of a
   [`vec3`](../../headers/vec.md).

2. Returns a copy of the fourth component (i.e. the scalar part) of this `quat`.

Aliases for the same components can also be accessed via
[`x, y, z, w`](xyzw.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
