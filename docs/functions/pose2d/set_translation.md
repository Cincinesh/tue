`tue::pose2d::set_translation`
======================
Provided by header [`<tue/pose2d.hpp>`](../../headers/pose2d.md)

```c++
template<typename T>
void pose2d<T>::set_translation(const vec2<T>& translation) noexcept;

template<typename T>
void pose2d<T>::set_translation(const T& x, const T& y) noexcept;
```

Sets the `translation` of this [`pose2d`](../../headers/pose2d.md) either using
a whole [`vec2`](../../headers/vec.md) or individual component values.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
