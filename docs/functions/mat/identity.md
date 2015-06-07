[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/`identity` (static)
===============================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C, int R>
constexpr mat<T, C, R> mat<T, C, R>::identity() noexcept
```

Creates a new [`mat`](../../headers/mat.md) with each component of the main
diagonal set to `1` and all other components set to `0`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
