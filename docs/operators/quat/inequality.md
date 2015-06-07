[Tuesday](../../../README.md)/[`quat`](../../headers/quat.md)/inequality operator
=================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// lhs != rhs
template<typename T, typename U>
constexpr bool operator!=(
    const quat<T>& lhs,
    const quat<U>& rhs) noexcept;
```

Returns `false` if each and every corresponding component between two
[`quat`](../../headers/quat.md)'s are equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
