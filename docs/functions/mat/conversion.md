`tue::mat` conversion
=====================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
template<typename U>
constexpr mat<T, C, R>::operator mat<U, C, R>() const noexcept;
```

Implicitly converts all the components of this [`mat`](../../headers/mat.md) to
the component type of another `mat` with the same dimensions.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
