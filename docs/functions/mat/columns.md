[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/`columns`
=====================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
vec<T, R>* mat<T, C, R>::columns() noexcept;

template<typename T, int C, int R>
const vec<T, R>* mat<T, C, R>::columns() const noexcept;
```

Returns a pointer to this [`mat`](../../headers/mat.md)'s underlying column
array in the form of [`vec`](../../headers/vec.md)'s. To view this `mat` as an
array of individual components, use the [`data`](data.md) function instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
