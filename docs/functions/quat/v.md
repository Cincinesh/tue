[Tuesday](../../../README.md)/[`quat`](../../headers/quat.md)/`v`
=================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
constexpr vec3<T> quat<T>::v() const noexcept;
```

Returns a copy of the first three components (i.e. the vector part, as opposed
to the scalar part [`s`](s.md)) of this [`quat`](../../headers/quat.md) in the
form of a [`vec3`](../../headers/vec.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
