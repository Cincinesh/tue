[Tuesday](../../../README.md)/[`tue::pose2d`](../../headers/pose2d.md)/inequality operator
==========================================================================================
Provided by header [`<tue/pose2d.hpp>`](../../headers/pose2d.md)

```c++
// lhs != rhs
template<typename T, typename U>
constexpr bool operator!=(const pose2d<T>& lhs, const pose2d<U>& rhs) noexcept;
```

Returns `false` if the `translation`'s and `rotation`'s of two
[`pose2d`](../../headers/pose2d.md)'s compare equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
