[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`cross`
=================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, typename U>
constexpr auto cross(
    const vec3<T>& lhs,
    const vec3<U>& rhs) noexcept
    -> vec<decltype(lhs[1]*rhs[2] - lhs[2]*rhs[1]), 3>;
```

Returns the cross product of the two given [`vec`](../../headers/vec.md)'s.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
