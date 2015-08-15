[Tuesday](../../../README.md)/[Namespaces](../../namespaces.md)/[`tue`](../tue.md)/`math`
=========================================================================================
`tue::math` provides common mathematical constants and functions. Many of the
following functions are available in the C++ Standard Library but are also
provided here for uniformity with composite types such as
[`vec`](../../headers/vec.md) and [`mat`](../../headers/mat.md).

Constants
---------
- [`pi`](../../headers/math.md)

Functions
---------
- Trigonometric functions
    - [`sin`](../../functions/math/sin.md)
    - [`cos`](../../functions/math/cos.md)
    - [`sincos`](../../functions/math/sincos.md)
- Exponential functions
    - [`exp`](../../functions/math/exp.md)
    - [`log`](../../functions/math/log.md)
- Power functions
    - [`pow`](../../functions/math/pow.md)
    - [`recip`](../../functions/math/recip.md)
    - [`sqrt`](../../functions/math/sqrt.md)
    - [`rsqrt`](../../functions/math/rsqrt.md)
- Miscellaneous functions
    - [`min`](../../functions/math/min.md)
    - [`max`](../../functions/math/max.md)
    - [`abs`](../../functions/math/abs.md)
- Geometric functions
    - [`dot`](../../functions/math/dot.md)
    - [`cross`](../../functions/math/cross.md)
    - [`length2`](../../functions/math/length2.md)
    - [`length`](../../functions/math/length.md)
    - [`normalize`](../../functions/math/normalize.md)
    - [`conjugate`](../../functions/math/conjugate.md)
    - [`comp_mult`](../../functions/math/comp_mult.md)
    - [`transpose`](../../functions/math/transpose.md)
- Logical functions
    - [`select`](../../functions/math/select.md)
    - [`less`](../../functions/math/less.md)
    - [`less_equal`](../../functions/math/less_equal.md)
    - [`greater`](../../functions/math/greater.md)
    - [`greater_equal`](../../functions/math/greater_equal.md)
    - [`equal`](../../functions/math/equal.md)
    - [`not_equal`](../../functions/math/not_equal.md)
- Rotation conversion functions
    - [`axis_angle`](../../functions/math/axis_angle.md)
    - [`rotation_vec`](../../functions/math/rotation_vec.md)
    - [`rotation_quat`](../../functions/math/rotation_quat.md)
- Transformation matrix generation
    - [`translation_mat`](../../functions/math/translation_mat.md)
    - [`rotation_mat`](../../functions/math/rotation_mat.md)
    - [`scale_mat`](../../functions/math/scale_mat.md)
    - [`pose_mat`](../../functions/math/pose_mat.md)
    - [`view_mat`](../../functions/math/view_mat.md)
    - [`perspective_mat`](../../functions/math/perspective_mat.md)
    - [`ortho_mat`](../../functions/math/ortho_mat.md)

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
