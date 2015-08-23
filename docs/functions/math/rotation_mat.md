[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`rotation_mat`
========================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (1)
// Where C and R are each 2, 3, or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const T& angle) noexcept
    -> mat<decltype(math::sin(angle)), C, R>;

// (2)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(
    const T& axis_x,
    const T& axis_y,
    const T& axis_z,
    const T& angle) noexcept
    -> mat<decltype(math::sin(angle)), C, R>;

// (3)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const vec3<T>& axis, const T& angle) noexcept
    -> mat<decltype(math::sin(angle)), C, R>;

// (4)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const vec4<T>& axis_angle) noexcept
    -> mat<decltype(math::sin(axis_angle.w())), C, R>;

// (5)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const T& x, const T& y, const T& z) noexcept
    -> mat<decltype(math::axis_angle(x, y, z).w()), C, R>;

// (6)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const vec3<T>& v) noexcept
    -> mat<decltype(math::axis_angle(v).w()), C, R>;

// (6)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> rotation_mat(const quat<T>& q) noexcept;
```

TODO.

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
