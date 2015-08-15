[Tuesday](../../../README.md)/[`tue::pose3d`](../../headers/pose3d.md)/`identity` (static)
==========================================================================================
Provided by header [`<tue/pose3d.hpp>`](../../headers/pose3d.md)

```c++
template<typename T>
constexpr pose3d<T> pose3d<T>::identity() noexcept;
```

Creates a new [`pose3d`](../../headers/pose3d.md) with
[`vec3<T>::zero()`](../vec/zero.md) for the translation and
[`quat<T>::identity()`](../quat/identity.md) for the rotation.

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
