[Tuesday](../../README.md)/[Headers](../headers.md)/`<tue/simd.hpp>`
====================================================================
This header provides thin wrapper classes and functions around platform-specific
SIMD intrinsics. Currently, only a few classes are provided with SSE
acceleration where available and un-accelerated compatibility fallbacks
otherwise.

Macros
------
- `#define TUE_SSE` <br/>
  Defined if the current compiler configuration supports SSE intrinsics.
- `#define TUE_SSE2` <br/>
  Defined if the current compiler configuration supports SSE2 intrinsics.

Types
-----
TODO

Type aliases
------------
TODO

Member types
------------
TODO

Member constants
----------------
TODO

Member functions
----------------
TODO

Operators
---------
TODO

Non-member functions
--------------------
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
        - [`transpose`](../functions/math/transpose.md)
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
