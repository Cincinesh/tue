[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/conversion
=============================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
template<typename U>
constexpr quat<T>::operator quat<U>() const noexcept;
```

Implicitly converts all the components of this [`quat`](../../headers/quat.md)
to the component type of another `quat`.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
