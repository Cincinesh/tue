[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/subscript operator
=====================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// q[i]

template<typename T>
template<typename I>
T& quat<T>::operator[](const I& i) noexcept;

template<typename T>
template<typename I>
constexpr const T& quat<T>::operator[](const I& i) const noexcept;
```

Returns a reference to component `i` of this [`quat`](../../headers/quat.md). No
bounds checking is performed.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
