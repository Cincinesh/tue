`tue::pose3d` constructor
=========================
Provided by header [`<tue/pose3d.hpp>`](../../headers/pose2d.md)

```c++
// (1)
template<typename T>
pose3d<T>::pose3d() noexcept = default;

// (2)
template<typename T>
constexpr pose3d<T>::pose3d(
    const vec3<T>& translation,
    const quat<T>& rotation) noexcept;

// (3)
template<typename T>
template<typename U>
explicit constexpr pose3d<T>::pose3d(
    const pose3d<U>& other) noexcept;
```

1. Default-constructs a new [`pose3d`](../../headers/pose3d.md).

2. Constructs a new `pose3d` with the given `translation` and `rotation`.

3. Explicitly converts the `translation` and `rotation` of another `pose3d` with
   a different component type to the new `pose3d`'s component type. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
