The Tuesday C++ Math and Template Library
=========================================

The Tuesday C++ Math and Template Library ("Tuesday" for short) is a library of
template classes and math functions with a focus on physics and graphics
applications. It provides data types commonly used in games and other
simulations such as vectors, quaternions, and matrices, operator overloads for
combining and manipulating these types, as well as some other common
mathematical functions. It was written to match the style of the C++ Standard
Library, and uses modern C++ features (i.e., C++14) extensively.


How to read this documentation
------------------------------

Tuesday makes heavy use of templates. Instead of using full template syntax
repeatedly throughout the documentation, shorter pseudo-code will be used when
the meaning is clear. For example, the word `vec` may refer to all possible
instantiations of the vec template regardless of arguments.


Requirements
------------

TODO


Installation
------------

TODO


Usage
-----

### tue::vec ###

    #include <tue/vec.hpp>

`tue::vec<T, N>` represents an N-dimensional vector with component type `T`.
2-dimensional, 3-dimensional, and 4-dimensional vec's of any component type are
supported. A specific instantiation's template arguments are made available via
the following public members:

- `using component_type = T;`
- `static const int component_count = N;`

Type aliases for common combinations are provided for convenience:

- `vec2<T>`, `vec3<T>`, `vec4<T>`
- `fvec2`, `fvec3`, `fvec4` (component_type: float)
- `dvec2`, `dvec3`, `dvec4` (component_type: double)
- `ivec2`, `ivec3`, `ivec4` (component_type: int)
- `uvec2`, `uvec3`, `uvec4` (component_type: unsigned int)
- `bvec2`, `bvec3`, `bvec4` (component_type: bool)

vec's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using any of the following:

- Individual component values, e.g.: <br/>
  `vec2(1, 2)`
- A single scalar to initialize each component to the same value, e.g.: <br/>
  `vec2(123) == vec2(123, 123)`
- A smaller vec to initialize a front subset of components, followed by scalars
  to fill in the rest, e.g.: <br/>
  `vec3(vec2(1, 2), 3) == vec3(1, 2, 3)`
- A larger vec to truncate, e.g.: <br/>
  `vec2(vec3(1, 2, 3)) == vec2(1, 2)`
- Another vec with the same `component_count` but a different `component_type`
  to perform a component-wise explicit conversion, e.g.: <br/>
  `fvec2(dvec2(1.2, 3.4)) == fvec2(float(1.2), float(3.4))`

Implicit conversion operators are provided as well, e.g.:

    dvec2 v = fvec2(1.2f, 3.4f);
    v == dvec2(1.2f, 3.4f); // true

vec types contain the following static factory methods:

- `zero()` <br/>
   Returns a `vec` with each component set to 0.
- `x_axis()` <br/>
   Returns a `vec` with the x-component set to 1 and all other components set to
   0.
- `y_axis()` <br/>
   Returns a `vec` with the y-component set to 1 and all other components set to
   0.
- `z_axis()` (`vec3` and `vec4` only) <br/>
   Returns a `vec` with the z-component set to 1 and all other components set to
   0.
- `w_axis()` (`vec4` only) <br/>
   Returns a `vec` with the w-component set to 1 and all other components set to
   0.

vec components can be accessed by value using the following getters and setters:

- `x()`, `set_x(const T& x)`
- `y()`, `set_y(const T& y)`
- `z()`, `set_z(const T& z)` (`vec3` and `vec4` only)
- `w()`, `set_w(const T& w)` (`vec4` only)

Alternate component names are also included to make vec types more useful as
color representations:

- `r()`, `set_r(const T& r)`
- `g()`, `set_g(const T& g)`
- `b()`, `set_b(const T& b)` (`vec3` and `vec4` only)
- `a()`, `set_a(const T& a)` (`vec4` only)

The first 2 or 3 components of a vec can be accessed or set using single
function calls:

- `vec3` and `vec4` only:
    - `xy()`
    - `set_xy(const vec2<T>& xy)`
    - `set_xy(const T& x, const T& y)`
    - `rg()`
    - `set_rg(const vec2<T>& rg)`
    - `set_rg(const T& r, const T& g)`
- `vec4` only:
    - `xyz()`
    - `set_xyz(const vec3<T>& xyz)`
    - `set_xyz(const T& x, const T& y, const T& z)`
    - `rgb()`
    - `set_rgb(const vec3<T>& rgb)`
    - `set_rgb(const T& r, const T& g, const T& b)`

A raw pointer to the underlying array of components can be obtained using the
following method:

- `data()`

References to individual components can be retrieved using the subscript
operator. No bounds checking is performed. Index-to-component mappings are as
follows:

- `v[0] == v.x() == v.r()`
- `v[1] == v.y() == v.g()`
- `v[2] == v.z() == v.b()` (`vec3` and `vec4` only)
- `v[3] == v.w() == v.a()` (`vec4` only)

Most bitwise and arithmetic operators work intuitively with vec's. Unary
operators return the result of applying the operator to each component. For
example:

    -vec2(1, -2) == vec2(-1, 2); // true

Similarly, binary operators where both sides are vec's with the same
`component_count` return the result of applying the operator to each
corresponding pair of components. For example:

    vec2(1, 4) + vec2(2, 3) == vec2(1+2, 4+3); // true

If one operand of a binary operator is a vec but the other is not, the return
value is the result of applying the non-vec operand to each component of the vec
operand. For example:

    2 * vec2(3, 4) == vec2(2*3, 2*4); // true

The only exceptions to these rules are the `==` and `!=` operators. Instead of
returning the result of comparing each pair of components individually, the
equality operators return a single `bool` value indicating whether or not *all*
pairs of components are equal. To perform component-wise comparisons, use the
comparison functions from the `tue::math` namespace instead.

The two operands to a binary operator need not have the same `component_type`.
In-general, Tuesday operators perform the same type promotions that C++ performs
for the standard built-in types. For example:

    fvec2(1.2f, 3.4f) + dvec(5.6, 7.8) == dvec(1.2f+5.6, 3.4f+7.8); // true

The complete list of operators vec's support is as follows:

- `+v`
- `-v`
- `~v`
- `++v`
- `--v`
- `v++`
- `v--`
- `lhs + rhs`
- `lhs - rhs`
- `lhs * rhs`
- `lhs / rhs`
- `lhs % rhs`
- `lhs & rhs`
- `lhs | rhs`
- `lhs ^ rhs`
- `lhs << rhs`
- `lhs >> rhs`
- `lhs += rhs`
- `lhs -= rhs`
- `lhs *= rhs`
- `lhs /= rhs`
- `lhs %= rhs`
- `lhs &= rhs`
- `lhs |= rhs`
- `lhs ^= rhs`
- `lhs <<= rhs`
- `lhs >>= rhs`
- `lhs == rhs`
- `lhs != rhs`

vec's are compatible with the following functions from the `tue::math`
namespace. In-general, the return value is the result of applying the function
to each component individually:

- `sin(const vec& v)`
- `cos(const vec& v)`
- `sincos(const vec& v, vec& sin_result, vec& cos_result)`
- `exp(const vec& v)`
- `log(const vec& v)`
- `pow(const vec& base, const scalar& exponent)`
- `pow(const vec& base, const vec& exponent)`
- `recip(const vec& v)`
- `sqrt(const vec& v)`
- `rsqrt(const vec& v)`
- `min(const vec& v1, const vec& v2)`
- `max(const vec& v1, const vec& v2)`
- `abs(const vec& v)`
- `comp_mult(const vec& lhs, const vec& rhs)`
- `select(const vec& condition, const vec& value)`
- `select(const vec& condition, const vec& value, const vec& otherwise)`
- `less(const vec& lhs, const vec& rhs)`
- `less_equal(const vec& lhs, const vec& rhs)`
- `greater(const vec& lhs, const vec& rhs)`
- `greater_equal(const vec& lhs, const vec& rhs)`
- `equal(const vec& lhs, const vec& rhs)`
- `not_equal(const vec& lhs, const vec& rhs)`

The following functions from `math::tue` take on special meanings for vec types:

    dot(const vec& lhs, const vec& rhs);

Returns the dot product of two vec's.

    cross(const vec3& lhs, const vec3& rhs);

Returns the cross product of two vec's.

    length2(const vec& v);

Returns the the length-squared of the given vec, i.e., the sum of each component
squared.

    length(const vec& v);

Returns the length of the given vec, i.e., the square root of `length2(v)`.

    normalize(const vec& v);

Returns a unit vec with the same direction as the given vec.


### tue::quat ###

    #include <tue/quat.hpp>

`tue::quat<T>` represents a quaternion with component type `T`. A specific
instantiation's template argument is made available via the following public
member:

- `using component_type = T;`

Type aliases for common combinations are provided for convenience:

- `fquat` (component_type: float)
- `dquat` (component_type: double)

quat's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using any of the following:

- Individual component values, e.g.: <br/>
  `quat(1, 2, 3, 4)`
- A vector part and a scalar part, e.g.: <br/>
  `quat(vec3(1, 2, 3), 4) == quat(1, 2, 3, 4)`
- Another quat with a different `component_type` to perform a component-wise
  explicit conversion, e.g.:

      fquat(dquat(1.1, 2.2, 3.3, 4.4))
          == fquat(float(1.1), float(2.2), float(3.3), float(4.4)); // true

Implicit conversion operators are provided as well, e.g.:

    dquat q = fquat(1.1f, 2.2f, 3.3f, 4.4f);
    q == dquat(1.1f, 2.2f, 3.3f, 4.4f); // true

quat types contain the following static factory method:

- `identity()` <br/>
   Returns a `quat` with the vector part set to 0 and the scalar part set to 1.

quat components can be accessed by value using the following getters and
setters:

- `x()`, `set_x(const T& x)`
- `y()`, `set_y(const T& y)`
- `z()`, `set_z(const T& z)`
- `w()`, `set_w(const T& w)`

Alternate component names are also included for when it's more convenient to
treat a quat as a vector and a scalar part:

- `v()`
- `set_v(const vec3<T>& v)`
- `set_v(const T& x, const T& y, const T& z)`
- `s()`
- `set_s(const T& s)`

A raw pointer to the underlying array of components can be obtained using the
following method:

- `data()`

References to individual components can be retrieved using the subscript
operator. No bounds checking is performed. Index-to-component mappings are as
follows:

- `q[0] == q.x() == q.v().x()`
- `q[1] == q.y() == q.v().y()`
- `q[2] == q.z() == q.v().z()`
- `q[3] == q.w() == q.s()`

The `*` and `*=` operators can be used to calculate the Grassman product of two
quat's.

The `*` and `*=` operators can also be used to rotate a vec3 by a rotation quat.
The vec must be on the left side of the operator.

The `==` operator returns true if all the pairs of corresponding components from
two quat's are equal to each other. Otherwise it returns false. The `!=`
operator does the exact opposite.

The following functions from `math::tue` take on special meanings for quat
types:

    length2(const quat& q);

Returns the the length-squared of the given quat, i.e., the sum of each
component squared.

    length(const quat& q);

Returns the length of the given quat, i.e., the square root of `length2(q)`.

    normalize(const quat& q);

Returns a unit quat (quat with a length of 1) with the same relative component
ratios as the given quat.

    conjugate(const quat& q);

Returns the conjugate of the given quat.


### Rotations ###

While not technically a C++ type separate from the `vec` and `quat` types
already discussed, rotations in Tuesday deserve some explanation. There is one
main way to represent rotations in 2-dimensional space, and three ways in
3-dimensional space.

A 2-dimensional rotation can be represented by a single scalar angle in radians.
Tuesday treats positive angle values as counter-clockwise.

A 3-dimensional rotation can be represented in three different ways:

- Axis-angle (a `vec4`, a `vec3` and a scalar, or four scalars)
- A rotation vector (a `vec3` or three scalars)
- A normalized quaternion (a `quat`)

The meaning of the axis-angle representation is straightforward. The first three
components represent the axis of rotation. All Tuesday functions which expect
an axis-angle representation assume the axis to be a unit vector. The fourth
component represents the angle of rotation around the axis. The direction of
rotation can be determined using the right-hand rule. The axis-angle
representation is most useful when you want to rotate around an arbitrary axis.

A rotation vector is a little more complicated. There are several ways to think
about it. One way is to think about it as a more-compact version of axis-angle,
i.e. its direction is the axis of rotation, and its magnitude is the angle of
rotation. This property makes it intuitive to multiply a rotation vector by a
scalar. Another way to think about it is as three separate axis-angle
representation, i.e., the x-component represents the angle of rotation around
the x-axis, the y-component around the y-axis, and the z-component around the
z-axis. This property makes adding two rotation vectors intuitive. The rotation
vector representation is most useful for storing 3-dimensional angular velocity.

A rotation quaternion is even more complicated conceptually, but that's okay;
with Tuesday, there's rarely a need to calculate or interpret individual quat
component values. The important thing to realize is quat's can be used to rotate
vec3's and each other, as well as construct rotation matricies, using only
simple arithmetic and no expensive trigonometric functions. Quaternions are most
useful for storing 3-dimensional orientations and performing vector
transformations.

Tuesday provides the following functions in the `tue::math` namespace for
converting between different 3-dimensional rotation representations:

- `#include <tue/vec.hpp>`
    - axis-angle to rotation vector:
	    - `vec3<T> rotation_vec(const vec4<T>& v)`
	    - `vec3<T> rotation_vec(const vec3<T>& axis, const T& angle)`
		- `vec3<T> rotation_vec(const T& axis_x, const T& axis_y,
		                        const T& axis_z, const T& angle)`
	- rotation vector to axis-angle:
		- `vec4<T> axis_angle(const vec3<T>& v)`
		- `vec4<T> axis_angle(const T& x, const T& y, const T& z)`
- `#include <tue/quat.hpp>`
	- axis-angle to rotation quaternion:
	    - `quat<T> rotation_quat(const vec4<T>& v)`
	    - `quat<T> rotation_quat(const vec3<T>& axis, const T& angle)`
		- `quat<T> rotation_quat(const T& axis_x, const T& axis_y,
		                         const T& axis_z, const T& angle)`
	- rotation quaternion to axis-angle:
		- `vec4<T> axis_angle(const quat<T>& q)`
	- rotation quaternion to rotation vector:
		- `vec3<T> rotation_vec(const quat<T>& q)`

Note: rotation conversion functions that take a rotation vector safely handle
the zero vector, e.g., `axis_angle(0, 0, 0)` returns a valid axis-angle vec4.


### tue::pose2d ###

    #include <tue/pose2d.hpp>

`pose2d<T>` represents a 2-dimensional position, i.e., combined translation and
rotation. The translation is represented by a `vec2<T>` and the rotation a
single scalar `T`. A specific instantiation's translation and rotation types,
as well as the template argument itself, are made available via the following
public members:

- `using translation_type = vec2<T>;`
- `using rotation_type = T;`
- `using component_type = T;`

Type aliases for common combinations are provided for convenience:

- `fpose2d` (component_type: float)
- `dpose2d` (component_type: double)

pose2d's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using either of the following:

- Translation and rotation values, e.g.: <br/>
  `pose2d(vec2(1, 2), 3)`
- Another pose2d with a different `component_type` to perform a component-wise
  explicit conversion, e.g.: <br/>

      fpose2d(dpose2d(
          dvec2(1.2, 3.4),
          5.6))
      == fpose2d(
          fvec2(dvec2(1.2, 3.4)),
          float(5.6)); // true

Implicit conversion operators are provided as well, e.g.:

    dpose2d p = fpose2d(fvec2(1.1f, 2.2f), 3.3f);
    p == dpose2d(fvec2(1.1f, 2.2f), 3.3f); // true

pose2d components can be accessed by value using the following getters and
setters:

- `translation()`
- `set_translation(const vec2<T>& translation)`
- `set_translation(const T& x, const T& y)`
- `rotation()`
- `set_rotation(const T& rotation)`

The `==` operator returns true if all the pairs of corresponding components from
two pose2d's are equal to each other. Otherwise it returns false. The `!=`
operator does the exact opposite.


### tue::pose3d ###

    #include <tue/pose3d.hpp>

`pose3d<T>` represents a 3-dimensional position, i.e., combined translation and
rotation. The translation is represented by a `vec3<T>` and the rotation a
`quat<T>`. A specific instantiation's translation and rotation types, as well as
the template argument itself, are made available via the following public
members:

- `using translation_type = vec3<T>;`
- `using rotation_type = quat<T>;`
- `using component_type = T;`

Type aliases for common combinations are provided for convenience:

- `fpose3d` (component_type: float)
- `dpose3d` (component_type: double)

pose3d's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using either of the following:

- Translation and rotation values, e.g.: <br/>
  `pose3d(vec3(1, 2, 3), quat(4, 5, 6, 7))`
- Another pose3d with a different `component_type` to perform a component-wise
  explicit conversion, e.g.: <br/>

      fpose3d(dpose3d(
          dvec3(1.1, 2.2, 3.3),
          dquat(4.4, 5.5, 6.6, 7.7)))
      == fpose3d(
          fvec3(dvec3(1.1, 2.2, 3.3)),
          fquat(dquat(4.4, 5.5, 6.6, 7.7))); // true

Implicit conversion operators are provided as well, e.g.:

    dpose3d p = fpose3d(
        fvec3(1.1f, 2.2f, 3.3f),
        fquat(4.45, 5.5f, 6.6f, 7.7f));
    p == dpose3d(
        fvec3(1.1f, 2.2f, 3.3f),
        fquat(4.45, 5.5f, 6.6f, 7.7f)); // true

pose3d components can be accessed by value using the following getters and
setters:

- `translation()`
- `set_translation(const vec3<T>& translation)`
- `set_translation(const T& x, const T& y, const T& z)`
- `rotation()`
- `set_rotation(const quat<T>& rotation)`

The `==` operator returns true if all the pairs of corresponding components from
two pose3d's are equal to each other. Otherwise it returns false. The `!=`
operator does the exact opposite.


### tue::mat ###

TODO


### tue::math ###

TODO


### tue/simd.hpp ###

TODO


### tue::size2d ###

TODO


### tue::rect ###

TODO


### tue::unused() ###

TODO


License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
