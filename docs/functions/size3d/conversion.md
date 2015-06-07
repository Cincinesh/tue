[Tuesday](../../../README.md)/[`size3d`](../../headers/size3d.md)/conversion
============================================================================
Provided by header [`<tue/size3d.hpp>`](../../headers/size3d.md)

```c++
template<typename T>
template<typename U>
constexpr size3d<T>::operator size3d<U>() const noexcept;
```

Implicitly converts all the components of this
[`size3d`](../../headers/size3d.md) to the component type of another `size3d`.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
