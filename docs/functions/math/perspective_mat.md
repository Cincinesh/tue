[Tuesday](../../../README.md)/[`tue::math`](../../namespaces/tue/math.md)/`perspective_mat`
===========================================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// (C and R must both = 4)
// (they're only parameters for consistency with the other transformation
//  matrices)
template<typename T, int C = 4, int R = 4>
constexpr auto perspective_mat(
    const T& fovy,
    const T& aspect,
    const T& near,
    const T& far) noexcept
    -> mat<decltype(math::sin(fovy)), C, R>;
```

Returns a 3D perspective projection matrix with the given dimensions `C` and `R`
for column and row counts respectively.

The `fovy` parameter specifies the vertical field of view.

The `aspect` parameter specifies the aspect ratio (width/height).

The `near` and `far` parameters specify the distances to the near and far
clipping planes.

The exact calculation is as follows:

```
Where f = cos(fovy/2) / sin(fovy/2)

[ f/aspect  0             0              0 ]
[    0      f             0              0 ]
[    0      0   (near+far)/(near-far)   -1 ]
[    0      0  (2*near*far)/(near-far)   0 ]
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
