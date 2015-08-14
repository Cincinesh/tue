[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`axis_angle`
======================================================================================
Provided by several headers.

```c++
// (1)
// #include <tue/vec.hpp>
template<typename T>
auto axis_angle(const vec3<T>& v) noexcept
    -> vec4<decltype(math::length(v))>;

// (2)
// #include <tue/vec.hpp>
template<typename T>
auto axis_angle(const T& x, const T& y, const T& z) noexcept
    -> vec4<decltype(math::length(x))>;

// (3)
// #include <tue/quat.hpp>
template<typename T>
auto axis_angle(const quat<T>& q) noexcept
    -> vec4<decltype(std::acos(q.s()))>;
```

1. Converts the given rotation vector to an axis-angle vector. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

2. Same as (1) but with the rotation vector given as individual components.

1. Converts the given rotation quaternion to an axis-angle vector. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
