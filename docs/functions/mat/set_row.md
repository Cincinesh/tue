[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/`set_row`
==========================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
template<typename J>
void mat<T, C, R>::set_row(const J& j, const vec<T, C>& row) noexcept;
```

Sets the value of row `j` of this [`mat`](../../headers/mat.md) to that of
the given [`vec`](../../headers/vec.md). No bounds checking is performed.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
