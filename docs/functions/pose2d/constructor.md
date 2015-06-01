`tue::pose2d` constructor
=========================
Provided by header [`<tue/pose2d.hpp>`](../../headers/pose2d.md)

```c++
// (1)
template<typename T>
pose2d<T>::pose2d() noexcept = default;

// (2)
template<typename T>
constexpr pose2d<T>::pose2d(
    const vec2<T>& translation,
    const T& rotation) noexcept;

// (3)
template<typename T>
template<typename U>
explicit constexpr pose2d<T>::pose2d(
    const pose2d<U>& other) noexcept;
```

1. Default-constructs a new [`pose2d`](../../headers/pose2d.md).

2. Constructs a new `pose2d` with the given `translation` and `rotation`.

3. Explicitly converts the corresponding components of another `pose2d` with a
   different component type to the new `pose2d`'s component type. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
