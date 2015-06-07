[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/post-increment
==========================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// m++
template<typename T, int C, int R>
mat<T, C, R> operator++(mat<T, C, R>& m, int) noexcept;
```

Post-increments each and every component of the given
[`mat`](../../headers/mat.md) and returns a copy of the original value.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
