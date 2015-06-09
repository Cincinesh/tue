[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/bitwise AND assignment
=======================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// m &= other

template<typename T, typename U, int C, int R>
mat<T, C, R>& operator&=(mat<T, C, R>& m, const U& other) noexcept;

template<typename T, typename U, int C, int R>
mat<T, C, R>& operator&=(mat<T, C, R>& m, const mat<U, C, R>& other) noexcept;
```

Performs a component-wise bitwise AND operation. If the right-hand side argument
is a scalar, the result will be as if it were a [`mat`](../../headers/mat.md)
with each component set to the value of that scalar.

Stores the result in the left-hand side argument and returns a reference to it.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
