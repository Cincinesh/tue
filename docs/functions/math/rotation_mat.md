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
auto rotation_mat(const vec3<T>& axis, const T& angle) noexcept
    -> mat<decltype(math::sin(angle)), C, R>;

// (3)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(
    const T& axis_x,
    const T& axis_y,
    const T& axis_z,
    const T& angle) noexcept
    -> mat<decltype(math::sin(angle)), C, R>;

// (4)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const vec4<T>& axis_angle) noexcept
    -> mat<decltype(math::sin(axis_angle.w())), C, R>;

// (5)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const vec3<T>& v) noexcept
    -> mat<decltype(math::axis_angle(v).w()), C, R>;

// (6)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
auto rotation_mat(const T& x, const T& y, const T& z) noexcept
    -> mat<decltype(math::axis_angle(x, y, z).w()), C, R>;

// (7)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> rotation_mat(const quat<T>& q) noexcept;
```

1. Returns a 2D rotation matrix with the given dimensions `C` and `R` for column
   and row counts respectively. `angle` is treated as counter-clockwise radians.
   The exact calculation is as follows:
   ```
   [  cos(angle)  sin(angle)  0  0 ]
   [ -sin(angle)  cos(angle)  0  0 ]
   [      0           0       1  0 ]
   [      0           0       0  1 ]
   ```

2. Returns a 3D rotation matrix with the given dimensions `C` and `R` for column
   and row counts respectively. `angle` is treated as counter-clockwise radians
   around the given `axis`. The exact calculation is as follows:
   ```
   Where x, y, and z are the components of the given axis and s and c are
   sin(angle) and cos(angle) respectively.

   [ xx(1-c)+c   xy(1-c)+zs  xz(1-c)-ys  0 ]
   [ xy(1-c)-zs  yy(1-c)+c   yz(1-c)+xs  0 ]
   [ xz(1-c)+ys  yz(1-c)-xs  zz(1-c)+c   0 ]
   [     0           0           0       1 ]
   ```

3. Same as (2) except with the axis split into individual components.

4. Same as (2) except with the axis and angle combined into one
   [`vec`](../../headers/vec.md).

5. Same as (4) except with a rotation vector instead of the axis-angle
   representation. For an explanation of the differences between the two, see
   [Rotation Types](../../other/rotation_types.md). This overload behaves as if
   `math::rotation_mat<T, C, R>(math::axis_angle(v))` were called.

6. Same as (5) except with the rotation vector split into individual components.

7. Returns a 3D rotation matrix with the given dimensions `C` and `R` for column
   and row counts respectively. `q` is treated as a
   [rotation quaternion](../../other/rotation_types.md). The exact calculation
   is as follows:
   ```
   Where x, y, z, and w are the components of the given quat.

   [ 1-2yy-2zz    2xy+2zw    2xz-2yw  0 ]
   [   2xy-2zw  1-2xx-2zz    2yz+2xw  0 ]
   [   2xz+2yw    2yz-2xw  1-2xx-2yy  0 ]
   [      0          0          0     1 ]
   ```

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
