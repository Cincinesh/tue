[Tuesday](../../../README.md)/[`vec`](../../headers/vec.md)/conversion
======================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, int N>
template<typename U>
constexpr vec<T, N>::operator vec<U, N>() const noexcept;
```

Implicitly converts all the components of this [`vec`](../../headers/vec.md) to
the component type of another `vec` with the same component count.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
