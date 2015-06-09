[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/subscript operator
===================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// m[i]

template<typename T, int C, int R>
template<typename I>
vec<T, R>& mat<T, C, R>::operator[](const I& i) noexcept;

template<typename T, int C, int R>
template<typename I>
constexpr const vec<T, R>& mat<T, C, R>::operator[](const I& i) const noexcept;
```

Returns a reference to column `i` of this [`mat`](../../headers/mat.md) as a
[`vec`](../../headers/vec.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
