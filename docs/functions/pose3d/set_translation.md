`tue::pose3d::set_translation`
==============================
Provided by header [`<tue/pose3d.hpp>`](../../headers/pose3d.md)

```c++
template<typename T>
void pose3d<T>::set_translation(const vec3<T>& translation) noexcept;

template<typename T>
void pose3d<T>::set_translation(const T& x, const T& y, const T& z) noexcept;
```

Sets the `translation` of this [`pose3d`](../../headers/pose3d.md) either using
a whole [`vec3`](../../headers/vec.md) or individual component values.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
