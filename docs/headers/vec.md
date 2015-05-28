Header `<tue/vec.hpp>`
===============
This header provides the `vec` type, type aliases, and some related global math
functions.

Types
-----
The `vec` type is declared as follows:

    template<typename T, int N>
    class vec;

`T` may be any type, though the interface is optimized for simple data types.

`N` must be an integer between 2 and 4 inclusive.

Type Aliases
------------
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

Global Math Functions
---------------------
- [`tue::math`](../namespaces/math.md)
    - [`sin`](../functions/math/sin.md)
    - [`cos`](../functions/math/cos.md)
    - [`sincos`](../functions/math/sincos.md)
    - [`exp`](../functions/math/exp.md)
    - [`log`](../functions/math/log.md)
    - [`pow`](../functions/math/pow.md)
    - [`recip`](../functions/math/recip.md)
    - [`sqrt`](../functions/math/sqrt.md)
    - [`rsqrt`](../functions/math/rsqrt.md)
    - [`min`](../functions/math/min.md)
    - [`max`](../functions/math/max.md)
    - [`abs`](../functions/math/abs.md)
    - [`dot`](../functions/math/dot.md)
    - [`cross`](../functions/math/cross.md)
    - [`length2`](../functions/math/length2.md)
    - [`length`](../functions/math/length.md)
    - [`normalize`](../functions/math/normalize.md)
    - [`comp_mult`](../functions/math/comp_mult.md)
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
