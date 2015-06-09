[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/`data`
==================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
T* mat<T, C, R>::data() noexcept;

template<typename T, int C, int R>
const T* mat<T, C, R>::data() const noexcept;
```

Returns a pointer to this [`mat`](../../headers/mat.md)'s underlying component
array. `mat` components are stored in column-major order. To view this `mat` as
an array of entire columns, use the [`columns`](columns.md) function instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
