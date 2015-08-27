[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/`x, y, z, w`
==============================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
template<typename T>
constexpr T quat<T>::x() const noexcept;

template<typename T>
constexpr T quat<T>::y() const noexcept;

template<typename T>
constexpr T quat<T>::z() const noexcept;

template<typename T>
constexpr T quat<T>::w() const noexcept;
```

Returns copies of the first, second, third, and fourth components of this
[`quat`](../../headers/quat.md).

Aliases for the same components can also be accessed via [`v, s`](vs.md).

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
