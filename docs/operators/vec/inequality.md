[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/inequality operator
====================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// lhs != rhs
template<typename T, typename U, int N>
constexpr bool operator!=(
    const vec<T, N>& lhs,
    const vec<U, N>& rhs) noexcept;
```

Returns `false` if each and every corresponding component between two
[`vec`](../../headers/vec.md)'s are equal and `true` otherwise.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
