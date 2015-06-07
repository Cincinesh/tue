[Tuesday](../../README.md)/[Headers](../headers.md)/`<tue/size3d.hpp>`
======================================================================
This header provides the `size3d` type and type aliases.

Types
-----
The `size3d` type represents a 3-dimensional size (width, height, and depth)
with a given component type. It is declared as follows:

```c++
template<typename T>
class size3d;
```

`T` is used to specify the component type. No restrictions are placed on this
type.

Type aliases
------------
```c++
using fsize3d = size3d<float>;
using dsize3d = size3d<double>;
using isize3d = size3d<int>;
using usize3d = size3d<unsigned int>;
```

Member types
------------
```c++
using component_type = T;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/size3d/constructor.md)
    - [(conversion)](../functions/size3d/conversion.md)
- Accessors
    - [`width`](../functions/size3d/width.md)
    - [`height`](../functions/size3d/height.md)
    - [`depth`](../functions/size3d/depth.md)
- Modifiers
    - [`set_width`](../functions/size3d/set_width.md)
    - [`set_height`](../functions/size3d/set_height.md)
    - [`set_depth`](../functions/size3d/set_depth.md)

Operators
---------
- [`lhs == rhs`](../operators/size3d/equality.md)
- [`lhs != rhs`](../operators/size3d/inequality.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
