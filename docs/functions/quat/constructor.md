[Tuesday](../../../README.md)/[`tue::quat`](../../headers/quat.md)/constructor
==============================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// (1)
template<typename T>
quat<T>::quat() noexcept = default;

// (2)
template<typename T>
constexpr quat<T>::quat(
    const T& x, const T& y, const T& z, const T& w) noexcept;

// (3)
template<typename T>
constexpr quat<T>::quat(const vec3<T>& v, const T& s) noexcept;

// (4)
template<typename T>
template<typename U>
explicit constexpr quat<T>::quat(const quat<U>& other) noexcept;
```

1. Default-constructs a new [`quat`](../../headers/quat.md).

2. Constructs a new `quat` with individual component values.

3. Constructs a new `quat` with the first three components set to the component
   values of `v` and the last component set to the value of `s`.

4. Explicitly converts the corresponding components of another `quat` with a
   different component type to the new `quat`'s component type. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
