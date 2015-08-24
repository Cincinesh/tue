[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`scale_mat`
=====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (1)
// Where C and R are each 2, 3, or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> scale_mat(const T& x, const T& y) noexcept;

// (2)
// Where C and R are each 2, 3, or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> scale_mat(const vec2<T>& xy) noexcept;

// (3)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> scale_mat(const T& x, const T& y, const T& z) noexcept;

// (4)
// Where C and R are each 3 or 4
template<typename T, int C = 4, int R = 4>
constexpr mat<T, C, R> scale_mat(const vec3<T>& xyz) noexcept;
```

1. Returns a 2D scale matrix with the given dimensions `C` and `R` for column
   and row counts respectively. The exact calculation is as follows:
   ```
   [  x  0  0  0 ]
   [  0  y  0  0 ]
   [  0  0  1  0 ]
   [  0  0  0  1 ]
   ```

2. Same as (1) but with the `x` and `y` values combined into a single
   [`vec`](../../headers/vec.md).

3. Returns a 2D scale matrix with the given dimensions `C` and `R` for column
   and row counts respectively. The exact calculation is as follows:
   ```
   [  x  0  0  0 ]
   [  0  y  0  0 ]
   [  0  0  z  0 ]
   [  0  0  0  1 ]
   ```

4. Same as (3) but with the `x`, `y` and `z` values combined into a single
   `vec`.

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
