Header `<tue/pose2d.hpp>`
=========================
This header provides the `pose2d` type and type aliases.

Types
-----
The `pose2d` type represents a 2-dimensional translation (represented by a
[`vec2`](vec.md)) and rotation (represented by a scalar of counter-clockwise
radians). It is declared as follows:

```c++
template<typename T>
class pose2d;
```

`T` is used to specify the translation and rotation component types. No
restrictions are placed on this type.

Type aliases
------------
```c++
using fpose2d = pose2d<float>;
using dpose2d = pose2d<double>;
```

Member types
------------
```c++
using translation_type = vec2<T>;
using rotation_type = T;
using component_type = T;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/pose2d/constructor.md)
    - [(conversion)](../functions/pose2d/conversion.md)
- Accessors
    - [`translation`](../functions/pose2d/translation.md)
    - [`rotation`](../functions/pose2d/rotation.md)
- Modifiers
    - [`set_translation`](../functions/pose2d/set_translation.md)
    - [`set_rotation`](../functions/pose2d/set_rotation.md)

Operators
---------
- [`lhs == rhs`](../operators/pose2d/equality.md)
- [`lhs != rhs`](../operators/pose2d/inequality.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
