`tue::quat::set_v`
==================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
void quat<T>::set_v(const vec3<T>& v) noexcept;

template<typename T>
void quat<T>::set_v(const T& x, const T& y, const T& z) noexcept;
```

Sets the first three components (i.e. the vector part, as opposed to the scalar
part [`set_s()`](set_s.md)) of this [`quat`](../../headers/quat.md), either
using a whole [`vec3`](../../headers/vec.md) or individual component values.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
