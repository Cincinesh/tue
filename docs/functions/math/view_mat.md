[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`view_mat`
====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
template<typename T, int C = 4, int R = 4>
auto view_mat(
    const vec2<T>& translation,
    const T& rotation) noexcept
    -> decltype(translation_mat<T, C, R>(-translation)
       * rotation_mat<T, C, C>(-rotation));

template<typename T, int C = 4, int R = 4>
auto view_mat(const pose2d<T>& pose) noexcept
    -> decltype(translation_mat<T, C, R>(-pose.translation())
       * rotation_mat<T, C, C>(-pose.rotation()));

template<typename T, int C = 4, int R = 4>
constexpr auto view_mat(
    const vec3<T>& translation,
    const quat<T>& rotation) noexcept
    -> decltype(translation_mat<T, C, R>(-translation)
       * rotation_mat<T, C, C>(math::conjugate(rotation)));

template<typename T, int C = 4, int R = 4>
constexpr auto view_mat(const pose3d<T>& pose) noexcept
    -> decltype(translation_mat<T, C, R>(-pose.translation())
       * rotation_mat<T, C, C>(math::conjugate(pose.rotation())));
```

Returns a view transformation matrix, i.e., the inverse of the corresponding
pose transformation matrix.

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
