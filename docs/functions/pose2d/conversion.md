`tue::pose2d` conversion
========================
Provided by header [`<tue/pose2d.hpp>`](../../headers/pose2d.md)

```c++
template<typename T>
template<typename U>
constexpr pose2d<T>::operator pose2d<U>() const noexcept;
```

Implicitly converts the `translation` and `rotation` of this
[`pose2d`](../../headers/pose2d.md) to the component type of another `pose2d`.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
