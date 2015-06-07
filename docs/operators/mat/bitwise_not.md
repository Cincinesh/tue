[Tuesday](../../../README.md)/[`mat`](../../headers/mat.md)/bitwise NOT
=======================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// ~m
template<typename T, int C, int R>
constexpr auto operator~(const mat<T, C, R>& m) noexcept
    -> mat<decltype(~m[0][0]), C, R>;
```

Returns the result of performing a bitwise NOT on each and every component of
the given [`mat`](../../headers/mat.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
