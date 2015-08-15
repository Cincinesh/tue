[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/multiplication assignment
============================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// (1) (q *= other)
template<typename T, typename U>
quat<T>& operator*=(quat<T>& q, const quat<U>& other) noexcept;

// (2) (v *= q)
template<typename T, typename U>
vec3<T>& operator*=(vec3<T>& v, const quat<U>& q) noexcept;
```

1. Calculates [`q * other`](multiplication.md), stores the result in `q`, and
   returns a reference to `q`.

2. Calculates [`v * q`](multiplication.md), stores the result in
   [`vec3`](../../headers/vec.md) `v`, and returns a reference to `vec3` `v`.

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
