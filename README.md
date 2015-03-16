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
repeatedly through the documentation, shorter pseudo-code will be used instead
when the meaning is clear. For example, the word `vec` may refer to all possible
instantiations of the vec template regardless of arguments.


Requirements
------------

TODO


Installation
------------

TODO


Types
-----

### tue::vec ###

`tue::vec<T, N>` represents an N-dimensional vector with component type `T`.
2-dimensional, 3-dimensional, and 4-dimensional vec's of any component type are
supported. Template arguments `T` and `N` can be determined for a specific vec
type using the member type alias `component_type` and static const int
`component_count` respectively.

Type aliases for common combinations are provided for convenience:

- `vec2<T>`, `vec3<T>`, `vec4<T>`
- `fvec2`, `fvec3`, `fvec4` (component_type: float)
- `dvec2`, `dvec3`, `dvec4` (component_type: double)
- `ivec2`, `ivec3`, `ivec4` (component_type: int)
- `uvec2`, `uvec3`, `uvec4` (component_type: unsigned int)
- `bvec2`, `bvec3`, `bvec4` (component_type: bool)

vec's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using any of the following:

- A single scalar to initialize each component to the same value, e.g.:<br/>
  `vec2(123) == vec2(123, 123)`
- Individual component values, e.g.:<br/>
  `vec2(1, 2)`
- A smaller vec to initialize a front subset of components, followed by scalars
  to fill in the rest, e.g.:<br/>
  `vec3(vec2(1, 2), 3) == vec3(1, 2, 3)`
- A larger vec to truncate, e.g.:<br/>
  `vec2(vec3(1, 2, 3)) == vec2(1, 2)`
- Another vec with the same `component_count` but a different `component_type`
  to perform a component-wise explicit conversion, e.g.:<br/>
  `fvec2(dvec2(1.2, 3.4)) == fvec2(float(1.2), float(3.4))`

Implicit conversion operators are provided as well that perform component-wise
implicit conversion, e.g.:

    dvec2 v = fvec2(1.2f, 3.4f);
    v == dvec2(1.2f, 3.4f); // true

vec types contain the following static factory methods:

- `zero()`   Returns a `vec` with each component set to 0.
- `x_axis()` Returns a `vec` with the x-component set to 1 and all other
             components set to 0.
- `y_axis()` Returns a `vec` with the y-component set to 1 and all other
             components set to 0.
- `z_axis()` Returns a `vec` with the z-component set to 1 and all other
             components set to 0.<br>
             (`vec3` and `vec4` only)
- `w_axis()` Returns a `vec` with the w-component set to 1 and all other
             components set to 0.<br/>
             (`vec4` only)

vec components can be accessed by value using the following getters and setters:

- `x()`, `set_x(const T& x)`
- `y()`, `set_y(const T& y)`
- `z()`, `set_z(const T& z)` (`vec3` and `vec4` only)
- `w()`, `set_w(const T& w)` (`vec4` only)

Alternate component names are also included to make vec types more useful as
color representations:

- `r()`, `set_r(const T& r)` (`vec3` and `vec4` only)
- `g()`, `set_g(const T& g)` (`vec3` and `vec4` only)
- `b()`, `set_b(const T& b)` (`vec3` and `vec4` only)
- `a()`, `set_a(const T& a)` (`vec4` only)

The first 2 or 3 components of a vec can be accessed or set using single
function calls:

- `vec3` and `vec4` only:
    - `xy()`
    - `set_xy(const T& x, const T& y)`
    - `set_xy(const vec2<T>& xy)`
- `vec4` only:
    - `xyz()`
    - `set_xyz(const T& x, const T& y, const T& z)`
    - `set_xyz(const vec3<T>& xyz)`
    - `rgb()`
    - `set_rgb(const T& r, const T& g, const T& b)`
    - `set_rgb(const vec3<T>& rgb)`

A raw pointer to the underlying array of components can be accessed using the
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
- `select(const vec& v, const vec& mask)`
- `less(const vec& lhs, const vec& rhs)`
- `less_equal(const vec& lhs, const vec& rhs)`
- `greater(const vec& lhs, const vec& rhs)`
- `greater_equal(const vec& lhs, const vec& rhs)`
- `equal(const vec& lhs, const vec& rhs)`
- `not_equal(const vec& lhs, const vec& rhs)`

The following function from `math::tue` take on special meanings for vec types:

    dot(const vec& lhs, const vec& rhs);

Returns the dot product (or "inner product") of two vec's, i.e., the sum of all
the products of each pair of corresponding components.

    cross(const vec3& lhs, const vec3& rhs);

Returns the cross product of two vec's.

    length2(const vec& v);

Returns the the length-squared of the given vec, i.e., the sum of each component
squared.

    length(const vec& v);

Returns the length of the given vec, i.e., the square root of `length2(v)`.

    normalize(const vec& v);

Returns a unit vec (vec with a length of 1) with the same direction as the given
vec.
