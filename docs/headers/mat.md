Header `<tue/mat.hpp>`
===============
This header provides the `mat` type, type aliases, and some related non-member
functions.

Types
-----
The `mat` type represents a 2-dimensional matrix with a given component type and
dimensions. It is declared as follows:

    template<typename T, int C, int R>
    class mat;

`T` is used to specify the component type. No restrictions are placed on this
type.

`C` and `R` are used to specify the column and row counts respectively. Each
value must be an integer between 2 and 4 inclusive.

Type aliases
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

Member types
------------
    using column_type = vec<T, R>;
    using row_type = vec<T, C>;
    using component_type = T;

Member constants
----------------
    static constexpr int column_count = C;
    static constexpr int row_count = R;
    static constexpr int component_count = column_count * row_count;

Member functions
----------------
- Object creation
    - [(constructor)](../functions/mat/constructor.md)
    - [`identity`](../functions/mat/identity.md)
    - [`zero`](../functions/mat/zero.md)
- Accessors
    - [`column`](../functions/mat/column.md)
	- [`columns`](../functions/mat/columns.md)
    - [`row`](../functions/mat/row.md)
    - [`data`](../functions/mat/data.md)
- Modifiers
    - [`set_column`](../functions/mat/set_column.md)
    - [`set_row`](../functions/mat/set_row.md)

Operators
---------
- [`+m`](../operators/mat/unary_plus.md)
- [`-m`](../operators/mat/unary_minus.md)
- [`~m`](../operators/mat/bitwise_not.md)
- [`++m`](../operators/mat/pre_increment.md)
- [`--m`](../operators/mat/pre_decrement.md)
- [`m++`](../operators/mat/post_increment.md)
- [`m--`](../operators/mat/post_decrement.md)
- [`lhs + rhs`](../operators/mat/addition.md)
- [`lhs - rhs`](../operators/mat/subtraction.md)
- [`lhs * rhs`](../operators/mat/multiplication.md)
- [`lhs / rhs`](../operators/mat/division.md)
- [`lhs % rhs`](../operators/mat/modulo.md)
- [`lhs & rhs`](../operators/mat/bitwise_and.md)
- [`lhs | rhs`](../operators/mat/bitwise_or.md)
- [`lhs ^ rhs`](../operators/mat/bitwise_xor.md)
- [`lhs << rhs`](../operators/mat/shift_left.md)
- [`lhs >> rhs`](../operators/mat/shift_right.md)
- [`m += other`](../operators/mat/addition_assignment.md)
- [`m -= other`](../operators/mat/subtraction_assignment.md)
- [`m *= other`](../operators/mat/multiplication_assignment.md)
- [`m /= other`](../operators/mat/division_assignment.md)
- [`m %= other`](../operators/mat/modulo_assignment.md)
- [`m &= other`](../operators/mat/bitwise_and_assignment.md)
- [`m |= other`](../operators/mat/bitwise_or_assignment.md)
- [`m ^= other`](../operators/mat/bitwise_xor_assignment.md)
- [`m <<= other`](../operators/mat/shift_left_assignment.md)
- [`m >>= other`](../operators/mat/shift_right_assignment.md)
- [`lhs == rhs`](../operators/mat/equal_to.md)
- [`lhs != rhs`](../operators/mat/not_equal_to.md)
- [`m[i]`](../operators/mat/subscript.md)

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
	- Transformation matrix generation
	    - [`translation_mat`](../functions/math/translation_mat.md)
	    - [`rotation_mat`](../functions/math/translation_mat.md)
	    - [`scale_mat`](../functions/math/translation_mat.md)
	    - [`pose_mat`](../functions/math/translation_mat.md)
	    - [`view_mat`](../functions/math/translation_mat.md)
	    - [`perspective_mat`](../functions/math/translation_mat.md)
	    - [`ortho_mat`](../functions/math/translation_mat.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
