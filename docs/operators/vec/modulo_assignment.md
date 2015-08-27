[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/modulo assignment
==================================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
// v %= other

template<typename T, typename U, int N>
vec<T, N>& operator%=(vec<T, N>& m, const U& other) noexcept;

template<typename T, typename U, int N>
vec<T, N>& operator%=(vec<T, N>& m, const vec<U, N>& other) noexcept;
```

Performs component-wise vector modulo. If the right-hand side argument is a
scalar, the result will be as if it were a [`vec`](../../headers/vec.md) with
each component set to the value of that scalar.

Stores the result in the left-hand side argument and returns a reference to it.

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
