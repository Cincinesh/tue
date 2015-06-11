[Tuesday](../../../README.md)/[`tue::pose2d`](../../headers/pose2d.md)/`identity` (static)
==========================================================================================
Provided by header [`<tue/pose2d.hpp>`](../../headers/pose2d.md)

```c++
template<typename T>
constexpr pose2d<T> pose2d<T>::identity() noexcept;
```

Creates a new [`pose2d`](../../headers/pose2d.md) with
[`vec2<T>::zero()`](../vec/zero.md) for the translation and `T(0)` for the
rotation.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
