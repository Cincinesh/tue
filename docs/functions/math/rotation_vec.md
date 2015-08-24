[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`rotation_vec`
========================================================================================
Provided by several headers.

```c++
// (1)
// #include <vec.hpp>
template<typename T>
vec3<T> rotation_vec(const vec3<T>& axis, const T& angle) noexcept;

// (2)
// #include <vec.hpp>
template<typename T>
vec3<T> rotation_vec(
    const T& axis_x,
    const T& axis_y,
    const T& axis_z,
    const T& angle) noexcept;

// (3)
// #include <vec.hpp>
template<typename T>
vec3<T> rotation_vec(const vec4<T>& v) noexcept;

// (4)
// #include <quat.hpp>
template<typename T>
auto rotation_vec(const quat<T>& q) noexcept
    -> vec3<decltype(std::acos(q.s()))>;
```

1. Converts the given axis-angle rotation to a rotation vector. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

2. Same as (1) but with the axis split into individual components.

3. Same as (1) but with the axis and angle combined into one
   [`vec`](../../headers/vec.md).

4. Converts the given rotation quaternion to a rotation vector. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

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
