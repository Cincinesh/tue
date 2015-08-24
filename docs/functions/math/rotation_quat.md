[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`rotation_quat`
=========================================================================================
Provided by header [`<tue/quat.hpp>`](../../headers/quat.md)

```c++
// (1)
template<typename T>
auto rotation_quat(
    const vec3<T>& axis, const T& angle) noexcept
    -> quat<decltype(math::sin(angle))>;

// (2)
template<typename T>
auto rotation_quat(
    const T& axis_x,
    const T& axis_y,
    const T& axis_z,
    const T& angle) noexcept
    -> quat<decltype(math::sin(angle))>;

// (3)
template<typename T>
auto rotation_quat(const vec4<T>& v) noexcept
    -> quat<decltype(math::sin(v.w()))>;

// (4)
template<typename T>
auto rotation_quat(const vec3<T>& v) noexcept
    -> quat<decltype(math::sin(math::axis_angle(v).w()))>;

// (5)
template<typename T>
auto rotation_quat(const T& x, const T& y, const T& z) noexcept
    -> quat<decltype(math::sin(math::axis_angle(x, y, z).w()))>;
```

1. Converts the given axis-angle rotation to a rotation quaternion. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

2. Same as (1) but with the axis split into individual components.

3. Same as (1) but with the axis and angle combined into one
   [`vec`](../../headers/vec.md).

4. Converts the given rotation vector to a rotation quaternion. For an
   explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md).

5. Same as (4) but with the rotation vector split into individual components.

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
