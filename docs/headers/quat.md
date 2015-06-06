Header `<tue/quat.hpp>`
=======================
This header provides the `quat` type, type aliases, and some related non-member
functions.

Types
-----
The `quat` type represents a quaternion with a given component type. It is
declared as follows:

```c++
template<typename T>
class quat;
```

`T` is used to specify the component type. No restrictions are placed on this
type.

A `quat` can be viewed as an array of four scalar components (`x`, `y`, `z`, and
`w`) or as a vector part and sclar part (`v` and `s`).

Type aliases
------------
```c++
using fquat = quat<float>;
using dquat = quat<double>;
```

Member types
------------
```c++
using component_type = T;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/quat/constructor.md)
    - [(conversion)](../functions/quat/conversion.md)
    - [`identity`](../functions/quat/identity.md) (static)
- Accessors
    - [`x`](../functions/quat/x.md)
    - [`y`](../functions/quat/y.md)
    - [`z`](../functions/quat/z.md)
    - [`w`](../functions/quat/w.md)
    - [`q[i]`](../operators/quat/subscript.md)
    - [`data`](../functions/quat/data.md)
    - [`v`](../functions/quat/v.md)
    - [`s`](../functions/quat/s.md)
- Modifiers
    - [`set_x`](../functions/quat/set_x.md)
    - [`set_y`](../functions/quat/set_y.md)
    - [`set_z`](../functions/quat/set_z.md)
    - [`set_w`](../functions/quat/set_w.md)
    - [`set_v`](../functions/quat/set_v.md)
    - [`set_s`](../functions/quat/set_s.md)

Operators
---------
- [`lhs * rhs`](../operators/quat/multiplication.md)
- [`q *= other`](../operators/quat/multiplication_assignment.md)
- [`lhs == rhs`](../operators/quat/equality.md)
- [`lhs != rhs`](../operators/quat/inequality.md)

Non-member functions
--------------------
- [`tue::math`](../namespaces/tue/math.md)
    - Geometric functions
        - [`length2`](../functions/math/length2.md)
        - [`length`](../functions/math/length.md)
        - [`normalize`](../functions/math/normalize.md)
        - [`conjugate`](../functions/math/conjugate.md)
    - Rotation conversion functions
        - [`axis_angle`](../functions/math/axis_angle.md)
        - [`rotation_vec`](../functions/math/rotation_vec.md)
        - [`rotation_quat`](../functions/math/rotation_quat.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
