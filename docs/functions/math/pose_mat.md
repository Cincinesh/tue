[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`pose_mat`
====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C = 4, int R = 4>
auto pose_mat(
    const vec2<T>& translation,
    const T& rotation) noexcept
    -> decltype(rotation_mat<T, R, R>(rotation)
       * translation_mat<T, C, R>(translation));

template<typename T, int C = 4, int R = 4>
auto pose_mat(const pose2d<T>& pose) noexcept
    -> decltype(rotation_mat<T, R, R>(pose.rotation())
       * translation_mat<T, C, R>(pose.translation()));

template<typename T, int C = 4, int R = 4>
constexpr auto pose_mat(
    const vec3<T>& translation,
    const quat<T>& rotation) noexcept
    -> decltype(rotation_mat<T, R, R>(rotation)
       * translation_mat<T, C, R>(translation));

template<typename T, int C = 4, int R = 4>
constexpr auto pose_mat(const pose3d<T>& pose) noexcept
    -> decltype(rotation_mat<T, R, R>(pose.rotation())
       * translation_mat<T, C, R>(pose.translation()));
```

Returns a pose transformation matrix (the composite of a rotation matrix
followed by a translation matrix).

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
