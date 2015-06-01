`tue::pose3d` conversion
========================
Provided by header [`<tue/pose3d.hpp>`](../../headers/pose3d.md)

```c++
template<typename T>
template<typename U>
constexpr pose3d<T>::operator pose3d<U>() const noexcept;
```

Implicitly converts the `translation` and `rotation` of this
[`pose3d`](../../headers/pose3d.md) to the component type of another `pose3d`.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To avoid such warnings,
use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
