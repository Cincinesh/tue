[Tuesday](../../../README.md)/[`size2d`](../../headers/size2d.md)/inequality operator
=====================================================================================
Provided by header [`<tue/size2d.hpp>`](../../headers/size2d.md)

```c++
// lhs != rhs
template<typename T, typename U>
constexpr bool operator!=(
    const size2d<T>& lhs,
    const size2d<T>& rhs) noexcept;
```

Returns `false` if the `width`'s and `heights`'s of two
[`size2d`](../../headers/size2d.md)'s compare equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
