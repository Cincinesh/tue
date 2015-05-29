Header `<tue/pose3d.hpp>`
=========================
This header provides the `pose3d` type and type aliases.

Types
-----
The `pose3d` type represents a 3-dimensional translation (represented by a
[`vec3`](vec.md)) and rotation (represented by a [`quat`](quat.md)). It is
declared as follows:

```c++
template<typename T>
class pose3d;
```

`T` is used to specify the translation and rotation component types. No
restrictions are placed on this type.

Type aliases
------------
```c++
using fpose3d = pose3d<float>;
using dpose3d = pose3d<double>;
```

Member types
------------
```c++
using translation_type = vec3<T>;
using rotation_type = quat<T>;
using component_type = T;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/pose3d/constructor.md)
    - [(conversion)](../functions/pose3d/conversion.md)
- Accessors
    - [`translation`](../functions/pose3d/translation.md)
    - [`rotation`](../functions/pose3d/rotation.md)
- Modifiers
    - [`set_translation`](../functions/pose3d/set_translation.md)
    - [`set_rotation`](../functions/pose3d/set_rotation.md)

Operators
---------
- [`lhs == rhs`](../operators/pose3d/equality.md)
- [`lhs != rhs`](../operators/pose3d/inequality.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
