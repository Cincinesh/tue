[Tuesday](../../README.md)/[Headers](../headers.md)/`<tue/math.hpp>`
====================================================================
This header provides common mathematical constants and functions. Most of the
following functions are available in the C++ Standard Library but are also
provided here for uniformity with composite types such as [`vec`](vec.md) and
[`mat`](mat.md).

Constants
---------
```c++
namespace tue {
namespace math {

constexpr float pi = 3.14159265358979323846264338327950288f;

}}
```

Functions
---------
- [`tue::math`](../namespaces/tue/math.md)
    - Trigonometric functions
        - [`sin`](../functions/math/sin.md)
        - [`cos`](../functions/math/cos.md)
        - [`sincos`](../functions/math/sincos.md)
    - Exponential functions
        - [`exp`](../functions/math/exp.md)
        - [`log`](../functions/math/log.md)
    - Power functions
        - [`pow`](../functions/math/pow.md)
        - [`recip`](../functions/math/recip.md)
        - [`sqrt`](../functions/math/sqrt.md)
        - [`rsqrt`](../functions/math/rsqrt.md)
    - Miscellaneous functions
        - [`min`](../functions/math/min.md)
        - [`max`](../functions/math/max.md)
        - [`abs`](../functions/math/abs.md)
    - Geometric functions
        - [`dot`](../functions/math/dot.md)
        - [`length2`](../functions/math/length2.md)
        - [`length`](../functions/math/length.md)
        - [`normalize`](../functions/math/normalize.md)
        - [`comp_mult`](../functions/math/comp_mult.md)
    - Logical functions
        - [`select`](../functions/math/select.md)
        - [`less`](../functions/math/less.md)
        - [`less_equal`](../functions/math/less_equal.md)
        - [`greater`](../functions/math/greater.md)
        - [`greater_equal`](../functions/math/greater_equal.md)
        - [`equal`](../functions/math/equal.md)
        - [`not_equal`](../functions/math/not_equal.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
