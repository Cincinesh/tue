[Tuesday](../../../README.md)/[`quat`](../../headers/quat.md)/multiplication assignment
=======================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// q *= other
template<typename T, typename U>
quat<T>& operator*=(quat<T>& q, const quat<U>& other) noexcept;
```

Calculates [`q * other`](multiplication.md), stores the result in `q`, and
returns a reference to `q`.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
