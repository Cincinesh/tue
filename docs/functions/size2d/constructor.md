[Tuesday](../../../README.md)/[`tue::size2d`](../../headers/size2d.md)/constructor
==================================================================================
Provided by header [`<tue/size2d.hpp>`](../../headers/size2d.md)

```c++
// (1)
template<typename T>
size2d<T>::size2d() noexcept = default;

// (2)
template<typename T>
constexpr size2d<T>::size2d(const T& width, const T& height) noexcept;

// (3)
template<typename T>
template<typename U>
explicit constexpr size2d<T>::size2d(const size2d<U>& other) noexcept;
```

1. Default-constructs a new [`size2d`](../../headers/size2d.md).

2. Constructs a new `size2d` with the given `width` and `height`.

3. Explicitly converts the corresponding components of another `size2d` with
   a different component type to the new `size2d`'s component type. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
