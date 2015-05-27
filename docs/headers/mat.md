Tuesday C++ Math and Template Library Header `<tue/mat.hpp>`
============================================================
This header provides the `mat<T, C, R>` type, its
specializations, its type aliases, and some associated
global math functions.

Types
-----
    template<typename T, int C, int R = C>
    class mat;

Specializations
---------------
- [`mat<T, 2, R>`](../types/mat2xR.md)
- [`mat<T, 3, R>`](../types/mat3xR.md)
- [`mat<T, 4, R>`](../types/mat4xR.md)

Functions
---------
- [`namespace tue::math`](../namespaces/math.md)
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
    - [`comp_mult`](../functions/math/comp_mult.md)
    - [`transpose`](../functions/math/transpose.md)
    - [`select`](../functions/math/select.md)
    - [`less`](../functions/math/less.md)
    - [`less_equal`](../functions/math/less_equal.md)
    - [`greater`](../functions/math/greater.md)
    - [`greater_equal`](../functions/math/greater_equal.md)
    - [`equal`](../functions/math/equal.md)
    - [`not_equal`](../functions/math/not_equal.md)

Type Aliases
------------
    template<typename T>
    using mat2x2 = mat<T, 2, 2>;
    
    template<typename T>
    using mat2x3 = mat<T, 2, 3>;
    
    template<typename T>
    using mat2x4 = mat<T, 2, 4>;
    
    template<typename T>
    using mat3x2 = mat<T, 3, 2>;
    
    template<typename T>
    using mat3x3 = mat<T, 3, 3>;
    
    template<typename T>
    using mat3x4 = mat<T, 3, 4>;
    
    template<typename T>
    using mat4x2 = mat<T, 4, 2>;
    
    template<typename T>
    using mat4x3 = mat<T, 4, 3>;
    
    template<typename T>
    using mat4x4 = mat<T, 4, 4>;
    
    using fmat2x2 = mat2x2<float>;
    using fmat2x3 = mat2x3<float>;
    using fmat2x4 = mat2x4<float>;
    using fmat3x2 = mat3x2<float>;
    using fmat3x3 = mat3x3<float>;
    using fmat3x4 = mat3x4<float>;
    using fmat4x2 = mat4x2<float>;
    using fmat4x3 = mat4x3<float>;
    using fmat4x4 = mat4x4<float>;

    using dmat2x2 = mat2x2<double>;
    using dmat2x3 = mat2x3<double>;
    using dmat2x4 = mat2x4<double>;
    using dmat3x2 = mat3x2<double>;
    using dmat3x3 = mat3x3<double>;
    using dmat3x4 = mat3x4<double>;
    using dmat4x2 = mat4x2<double>;
    using dmat4x3 = mat4x3<double>;
    using dmat4x4 = mat4x4<double>;

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
