[Tuesday](../../../README.md)/[`pose3d`](../../headers/pose3d.md)/inequality operator
=====================================================================================
Provided by header [`<tue/pose3d.hpp>`](../../headers/pose3d.md)

```c++
// lhs != rhs
template<typename T, typename U>
constexpr bool operator!=(const pose3d<T>& lhs, const pose3d<U>& rhs) noexcept;
```

Returns `false` if the `translation`'s and `rotation`'s of two
[`pose3d`](../../headers/pose3d.md)'s compare equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
