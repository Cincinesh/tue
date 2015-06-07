[Tuesday](../../../README.md)/[`size3d`](../../headers/size3d.md)/constructor
=============================================================================
Provided by header [`<tue/size3d.hpp>`](../../headers/size3d.md)

```c++
// (1)
template<typename T>
size3d<T>::size3d() noexcept = default;

// (2)
template<typename T>
constexpr size3d<T>::size3d(
    const T& width,
    const T& height,
    const T& depth) noexcept;

// (3)
template<typename T>
template<typename U>
explicit constexpr size3d<T>::size3d(
    const size3d<U>& other) noexcept;
```

1. Default-constructs a new [`size3d`](../../headers/size3d.md).

2. Constructs a new `size3d` with the given `width`, `height`, and `depth`.

3. Explicitly converts the corresponding components of another `size3d` with
   a different component type to the new `size3d`'s component type. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
