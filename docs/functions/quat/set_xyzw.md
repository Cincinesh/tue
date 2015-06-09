[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/`set_x, set_y, set_z, set_w`
===============================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
void quat<T>::set_x(const T& x) noexcept;

template<typename T>
void quat<T>::set_y(const T& y) noexcept;

template<typename T>
void quat<T>::set_z(const T& z) noexcept;

template<typename T>
void quat<T>::set_w(const T& w) noexcept;
```

Sets the first, second, third, and fourth components of this
[`quat`](../../headers/quat.md).

Aliases for the same components can also be modified via
[`set_v, set_s`](set_vs.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
