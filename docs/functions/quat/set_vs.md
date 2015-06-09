[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/`set_v, set_s`
=================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// (1)
template<typename T>
void quat<T>::set_v(const vec3<T>& v) noexcept;

// (2)
template<typename T>
void quat<T>::set_v(const T& x, const T& y, const T& z) noexcept;

// (3)
template<typename T>
void quat<T>::set_s(const T& s) noexcept;
```

1. Sets the first three components (i.e. the vector part) of this
   [`quat`](../../headers/quat.md) using a whole [`vec3`](../../headers/vec.md).

2. Sets the first three components (i.e. the vector part) of this `quat` using
   individual component values.

3. Sets the fourth component (i.e. the scalar part) of this `quat`.

Aliases for the same components can also be modified via
[`set_x, set_y, set_z, set_w`](set_xyzw.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
