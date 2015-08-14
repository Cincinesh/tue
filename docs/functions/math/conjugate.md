[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`conjugate`
=====================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
constexpr quat<T> conjugate(const quat<T>& q) noexcept;
```

Returns the conjugate of the given [`quat`](../../headers/quat.md), i.e., another
`quat` with the vector part negated, but the scalar part unchanged.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
