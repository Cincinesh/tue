[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/subscript operator
===================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// v[i]

template<typename T, int N>
template<typename I>
T& vec<T, N>::operator[](const I& i) noexcept;

template<typename T, int N>
template<typename I>
constexpr const T& vec<T, N>::operator[](const I& i) const noexcept;
```

Returns a reference to component `i` of this [`vec`](../../headers/vec.md). No
bounds checking is performed.

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
