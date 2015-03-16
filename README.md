The Tuesday C++ Template Math Library

The Tuesday C++ Template Math Library ("Tue" for short) is a library of template
classes and math functions with a focus on physics and graphics applications. It
provides data types commonly used in games and other simulations such as
vectors, quaternions, and matrices, operator overloads for combining and
manipulating these types, as well as some other common mathematical functions.
It was written to match the style of the C++ Standard Library, and uses modern
C++ features (i.e. C++14) extensively.


How to read this documentation:

Tue makes heavy use of templates. Instead of using full template syntax, this
documentation will make extensive use of ad-hoc shortcuts. For example, the
word "vec" may refer to all vector types regardless of size and component type.


Requirements:

TODO


Installation:

TODO


Types:

tue::vec<typename T, int N>:

tue::vec<T, N> represents an N-dimensional vector with component type T.
2-dimensional, 3-dimensional, and 4-dimensional vec's of any component type are
supported. Template arguments T and N can be extracted from a specific vec type
using the member type alias "component_type" and static const int
"component_count" respectively.

Type aliases for common combinations are provided for convenience:
vec2<T> vec3<T> vec4<T>
fvec2 fvec3 fvec4 (component_type: float)
dvec2 dvec3 dvec4 (component_type: double)
ivec2 ivec3 ivec4 (component_type: int)
uvec2 uvec3 uvec4 (component_type: unsigned int)
bvec2 bvec3 bvec4 (component_type: bool)

vec's are default-constructable, copy-constructable, and copy-assignable.
Additionally, they can be constructed using any of the following:
* Specify a single scalar to initialize each component to the same value, e.g.
  vec2(123) == vec2(123, 123)
* Specify each component individually, in order.
* Specify a smaller vec to initialize a front subset of components, followed by
  scalars to fill in the rest, e.g. vec3(vec2(1, 2), 3) == vec3(1, 2, 3)
* Specify a larger vec to truncate, e.g. vec2(vec3(1, 2, 3)) == vec2(1, 2)
* Specify another vec with the same dimensionality but a different component
  type to perform a component-wise explicit conversion.

Implicit conversion operators are provided as well that perform component-wise
implicit conversion.

vec types contain the following static factory methods:
zero()   - Returns a vec with each component set to 0.
x_axis() - Returns a vec with the x-component set to 1 and all other components
           set to 0.
y_axis() - Returns a vec with the y-component set to 1 and all other components
           set to 0.
z_axis() - Returns a vec with the z-component set to 1 and all other components
           set to 0. (vec3 and vec4 only)
w_axis() - Returns a vec with the w-component set to 1 and all other components
           set to 0. (vec4 only)

vec components can be accessed by value using the following getters and setters:
x(), set_x(const T& x)
y(), set_y(const T& y)
z(), set_z(const T& z) (vec3 and vec4 only)
w(), set_w(const T& w) (vec4 only)

vec types are also useful for describing colors, so the following alternate
names are provided as well:
r(), set_r(const T& r) (vec3 and vec4 only)
g(), set_g(const T& g) (vec3 and vec4 only)
b(), set_b(const T& b) (vec3 and vec4 only)
a(), set_a(const T& a) (vec4 only)

The first 2 or 3 components of a vec can be accessed or set using single
function calls:
xy()                                        (vec3 and vec4 only)
set_xy(const T& x, const T& y)              (vec3 and vec4 only)
set_xy(const vec2<T>& xy)                   (vec3 and vec4 only)
xyz()                                       (vec4 only)
set_xyz(const T& x, const T& y, const T& z) (vec4 only)
set_xyz(const vec3<T>& xyz)                 (vec4 only)
rgb()                                       (vec4 only)
set_rgb(const T& r, const T& g, const T& b) (vec4 only)
set_rgb(const vec3<T>& rgb)                 (vec4 only)

A raw pointer to the underlying array of components can be accessed using the
following method:
data()

References to individual components can be retrieved using the subscript
operator. No bounds checking is performed. Index to component mappings are as
follows:
v[0] == v.x() == v.r()
v[1] == v.y() == v.g()
v[2] == v.z() == v.b() (vec3 and vec4 only)
v[3] == v.w() == v.a() (vec4 only)

Most bitwise and arithmetic operators work intuitively with vec's. Unary
operators return the result of applying the operator to each component. For
example:
-vec2(1, -2) == vec2(-1, 2).

Similarly, binary operators where both sides are vec's with the same
component_count returns the result of applying the operator to each
corresponding pair of components. For example:
vec2(1, 4) + vec2(2, 3) == vec2(1+2, 4+3)

If one operand of a binary operator is a vec but the other is not, the return
value is the result of applying the non-vec operand to each component of the vec
operand. For example:
2 * vec2(3, 4) == vec2(2*3, 2*4)

The two operands to a binary operator need not have the same component_type.
In-general, Tue operators perform the same type promotions that C++ performs
for the standard built-in types. For example:
fvec2(1.2f, 3.4f) + dvec(5.6, 7.8) == dvec(1.2f+5.6, 3.4f+7.8)

The only exceptions to these rules are the "==" and "!=" operators. Instead of
returning the result of comparing each pair of components individually, the
equality operators return a single bool value indicating whether or not all
pairs of components are equal. Component-wise vec comparisons are possible using
functions from the tue::math namespace instead.

The complete list of operators vec's support is as follows:
+v
-v
~v
++v
--v
v++
v--
lhs + rhs
lhs - rhs
lhs * rhs
lhs / rhs
lhs % rhs
lhs & rhs
lhs | rhs
lhs ^ rhs
lhs << rhs
lhs >> rhs
lhs += rhs
lhs -= rhs
lhs *= rhs
lhs /= rhs
lhs %= rhs
lhs &= rhs
lhs |= rhs
lhs ^= rhs
lhs <<= rhs
lhs >>= rhs
lhs == rhs
lhs != rhs

vec's are compatible with the following functions from the tue::math namespace.
In-general, the return value is the result of applying the function to each
component individually:
sin(const vec& v)
cos(const vec& v)
sincos(const vec& v, vec& sin_result, vec& cos_result)
exp(const vec& v)
log(const vec& v)
pow(const vec& base, const scalar& exponent)
pow(const vec& base, const vec& exponent)
recip(const vec& v)
sqrt(const vec& v)
rsqrt(const vec& v)
min(const vec& v1, const vec& v2)
max(const vec& v1, const vec& v2)
abs(const vec& v)
comp_mult(const vec& lhs, const vec& rhs)
select(const vec& v, const vec& mask)
less(const vec& lhs, const vec& rhs)
less_equal(const vec& lhs, const vec& rhs)
greater(const vec& lhs, const vec& rhs)
greater_equal(const vec& lhs, const vec& rhs)
equal(const vec& lhs, const vec& rhs)
not_equal(const vec& lhs, const vec& rhs)

dot(const vec& lhs, const vec& rhs) returns the dot product (or "inner
product") of two vec's, i.e., the sum of all the products of each pair of
corresponding components.

cross(const vec3& lhs, const vec3& rhs) returns the cross product of two vec's.

length2(const vec& v) returns the the length-squared of the given vec, i.e., the
sum of each component squared.

length(const vec& v) returns the length of the given vec, i.e., the square root
of length2(v).

normalize(const vec& v) returns a unit vec (vec with a length of 1) with the
same direction as the given vec.
