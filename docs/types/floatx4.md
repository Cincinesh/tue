`tue::floatx4`
=============
Provided by header [`<tue/simd.hpp>`](../headers/simd.md)

`floatx4` represents a 4-component array of single-precision floating-point
values for use with SIMD intrinsics. Currently, only an SSE-accelerated version
is provided where available with an un-accelerated compatibility fallback
otherwise. It is declared as follows:

    class floatx4;

The SSE-accelerated version is backed by a single `__m128`.

The un-accelerated compatibility fallback is simply an array of 4 `float`'s.

Note: This type is very different from [`fvec4`](../headers/vec.md). The
interface intentionally makes it difficult to access individual components since
this is a slow operation in most SIMD instruction sets, it may have stricter
alignment requirements, and all math functions operate component-wise without
any interaction between non-corresponding components, e.g., functions like
[`math::dot`](../functions/math/dot.md) and
[`math::length`](../functions/math/length.md) might not do what you expect.

Member types
------------
    using component_type = float;

Member constants
----------------
    static constexpr int component_count = 4;

Member functions
----------------
- Object creation
    - [(constructor)](../functions/floatx4/constructor.md)
	- [`zero`](../functions/floatx4/zero.md)
	- [`load`](../functions/floatx4/load.md)
	- [`loadu`](../functions/floatx4/loadu.md)
- Conversions
    - [`__m128`](../operators/floatx4/__m128.md) (SSE only)
- Accessors
    - [`store`](../functions/floatx4/store.md)
	- [`storeu`](../functions/floatx4/storeu.md)

Operators
---------
- [`+v`](../operators/floatx4/unary_plus.md)
- [`-v`](../operators/floatx4/unary_minus.md)
- [`++v`](../operators/floatx4/pre_increment.md)
- [`--v`](../operators/floatx4/pre_decrement.md)
- [`v++`](../operators/floatx4/post_increment.md)
- [`v--`](../operators/floatx4/post_decrement.md)
- [`lhs + rhs`](../operators/floatx4/addition.md)
- [`lhs - rhs`](../operators/floatx4/subtraction.md)
- [`lhs * rhs`](../operators/floatx4/multiplication.md)
- [`lhs / rhs`](../operators/floatx4/division.md)
- [`v += other`](../operators/floatx4/addition_assignment.md)
- [`v -= other`](../operators/floatx4/subtraction_assignment.md)
- [`v *= other`](../operators/floatx4/multiplication_assignment.md)
- [`v /= other`](../operators/floatx4/division_assignment.md)
- [`lhs == rhs`](../operators/floatx4/equal_to.md)
- [`lhs != rhs`](../operators/floatx4/not_equal_to.md)

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
