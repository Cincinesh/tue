[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/inequality operator
====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// lhs != rhs
template<typename T, typename U, int C, int R>
constexpr bool operator!=(
    const mat<T, C, R>& lhs,
    const mat<U, C, R>& rhs) noexcept;
```

Returns `false` if each and every corresponding component between two
[`mat`](../../headers/mat.md)'s are equal and `true` otherwise.

To check for component-wise inequality, use
[`tue::math::not_equal`](../../functions/math/not_equal.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
