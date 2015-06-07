[Tuesday](../../../README.md)/[`size3d`](../../headers/size3d.md)/inequality operator
=====================================================================================
Provided by header [`<tue/size3d.hpp>`](../../headers/size3d.md)

```c++
// lhs != rhs
template<typename T, typename U>
constexpr bool operator!=(
    const size3d<T>& lhs,
    const size3d<T>& rhs) noexcept;
```

Returns `false` if the `width`'s, `heights`'s, and `depth`'s of two
[`size3d`](../../headers/size3d.md)'s compare equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
