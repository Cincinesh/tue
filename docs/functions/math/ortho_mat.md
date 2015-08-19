[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`ortho_mat`
=====================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (Where C = 3 or 4 and R = 4)
template<typename T, int C = 4, int R = 4>
constexpr auto ortho_mat(
    const T& width,
    const T& height,
    const T& near,
    const T& far) noexcept
    -> mat<decltype(math::recip(width)), C, R>;
```

Returns an orthographic projection matrix with the given dimensions (`C` and `R`
for column and row counts respectively).

The `width` parameter determines the horizontal clipping planes.

The `height` parameter determines the vertical clipping planes.

The `near` and `far` parameters determine the near and far clipping planes.

The exact calculation is as follows:

```
[2/width    0               0           0 ]
[   0    2/height           0           0 ]
[   0       0          2/(near-far)     0 ]
[   0       0     (near+far)/(near-far) 1 ]
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
