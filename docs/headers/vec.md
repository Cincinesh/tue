[Tuesday](../../README.md)/[Headers](../headers.md)/`<tue/vec.hpp>`
===================================================================
This header provides the `tue::vec` type, type aliases, and some related
non-member functions.

Types
-----
The `tue::vec` type represents an N-dimensional vector with a given component
type and count. It is declared as follows:

```c++
template<typename T, int N>
class vec;
```

`T` is used to specify the component type. No restrictions are placed on this
type.

`N` is used to specify the component count. It must be an integer between 2 and
4 inclusive.

Type aliases
------------
```c++
template<typename T>
using vec2 = vec<T, 2>;

template<typename T>
using vec3 = vec<T, 3>;

template<typename T>
using vec4 = vec<T, 4>;

using fvec2 = vec2<float>;
using fvec3 = vec3<float>;
using fvec4 = vec4<float>;

using dvec2 = vec2<double>;
using dvec3 = vec3<double>;
using dvec4 = vec4<double>;

using ivec2 = vec2<int>;
using ivec3 = vec3<int>;
using ivec4 = vec4<int>;

using uvec2 = vec2<unsigned int>;
using uvec3 = vec3<unsigned int>;
using uvec4 = vec4<unsigned int>;

using bvec2 = vec2<bool>;
using bvec3 = vec3<bool>;
using bvec4 = vec4<bool>;
```

Member types
------------
```c++
using component_type = T;
```

Member constants
----------------
```c++
static constexpr int component_count = N;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/vec/constructor.md)
    - [(conversion)](../functions/vec/conversion.md)
    - [`zero`](../functions/vec/zero.md) (static)
    - [`x_axis`](../functions/vec/x_axis.md) (static)
    - [`y_axis`](../functions/vec/y_axis.md) (static)
    - [`z_axis`](../functions/vec/z_axis.md) (static) (component_count >= 3)
    - [`w_axis`](../functions/vec/w_axis.md) (static) (component_count >= 4)
- Accessors
    - [`x, y, z, w`](../functions/vec/xyzw.md)
    - [`r, g, b, a`](../functions/vec/rgba.md)
    - [`xy, rg`](../functions/vec/xy_rg.md) (component_count > 2)
    - [`xyz, rgb`](../functions/vec/xyz_rgb.md) (component_count > 3)
    - [`v[i]`](../operators/vec/subscript.md)
    - [`data`](../functions/vec/data.md)
- Modifiers
    - [`set_x, set_y, set_z, set_w`](../functions/vec/set_xyzw.md)
    - [`set_r, set_g, set_b, set_a`](../functions/vec/set_rgba.md)
    - [`set_xy, set_rg`](../functions/vec/set_xy_rg.md) (component_count > 2)
    - [`set_xyz, set_rgb`](../functions/vec/set_xyz_rgb.md)
      (component_count > 3)

Operators
---------
- [`+v`](../operators/vec/unary_plus.md)
- [`-v`](../operators/vec/unary_minus.md)
- [`~v`](../operators/vec/bitwise_not.md)
- [`++v`](../operators/vec/pre_increment.md)
- [`--v`](../operators/vec/pre_decrement.md)
- [`v++`](../operators/vec/post_increment.md)
- [`v--`](../operators/vec/post_decrement.md)
- [`lhs + rhs`](../operators/vec/addition.md)
- [`lhs - rhs`](../operators/vec/subtraction.md)
- [`lhs * rhs`](../operators/vec/multiplication.md)
- [`lhs / rhs`](../operators/vec/division.md)
- [`lhs % rhs`](../operators/vec/modulo.md)
- [`lhs & rhs`](../operators/vec/bitwise_and.md)
- [`lhs | rhs`](../operators/vec/bitwise_or.md)
- [`lhs ^ rhs`](../operators/vec/bitwise_xor.md)
- [`lhs << rhs`](../operators/vec/shift_left.md)
- [`lhs >> rhs`](../operators/vec/shift_right.md)
- [`v += other`](../operators/vec/addition_assignment.md)
- [`v -= other`](../operators/vec/subtraction_assignment.md)
- [`v *= other`](../operators/vec/multiplication_assignment.md)
- [`v /= other`](../operators/vec/division_assignment.md)
- [`v %= other`](../operators/vec/modulo_assignment.md)
- [`v &= other`](../operators/vec/bitwise_and_assignment.md)
- [`v |= other`](../operators/vec/bitwise_or_assignment.md)
- [`v ^= other`](../operators/vec/bitwise_xor_assignment.md)
- [`v <<= other`](../operators/vec/shift_left_assignment.md)
- [`v >>= other`](../operators/vec/shift_right_assignment.md)
- [`lhs == rhs`](../operators/vec/equality.md)
- [`lhs != rhs`](../operators/vec/inequality.md)

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
        - [`cross`](../functions/math/cross.md) (component_count == 3)
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
    - Rotation conversion functions
        - [`rotation_vec`](../functions/math/rotation_vec.md)
        - [`axis_angle`](../functions/math/axis_angle.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
