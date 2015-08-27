[Tuesday](../../../README.md)/[`tue::size2d`](../../headers/size2d.md)/equality operator
========================================================================================
Provided by header [`<tue/size2d.hpp>`](../../headers/size2d.md)

```c++
// lhs == rhs
template<typename T, typename U>
constexpr bool operator==(
    const size2d<T>& lhs,
    const size2d<T>& rhs) noexcept;
```

Returns `true` if the widths and heights of two
[`size2d`](../../headers/size2d.md)'s compare equal and `false` otherwise.

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
