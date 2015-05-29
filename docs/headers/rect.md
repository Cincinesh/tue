Header `<tue/rect.hpp>`
=======================
This header provides the `rect` type and type aliases.

Types
-----
The `rect` type represents a 2-dimensional rectangle consisting of a position
(represented by a [`vec2`](vec.md)) and size (represented by a
[`size2d`](size2d.md)). It is declared as follows:

```c++
template<typename P, typename S = P>
class rect;
```

`P` and `S` are used to specify the position and size component types
respectively. No restrictions are placed on these types.

Type aliases
------------
```c++
using frect = rect<float>;
using drect = rect<double>;
using irect = rect<int>;
using urect = rect<unsigned int>;
using iurect = rect<int, unsigned int>;
```

Member types
------------
```c++
using position_type = vec2<P>;
using position_component_type = P;
using size_type = size2d<S>;
using size_component_type = S;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/rect/constructor.md)
    - [(conversion)](../functions/rect/conversion.md)
- Accessors
    - [`position`](../functions/rect/position.md)
    - [`x`](../functions/rect/x.md)
    - [`y`](../functions/rect/y.md)
    - [`size`](../functions/rect/size.md)
    - [`width`](../functions/rect/width.md)
    - [`height`](../functions/rect/height.md)
- Modifiers
    - [`set_position`](../functions/rect/set_position.md)
    - [`set_x`](../functions/rect/set_x.md)
    - [`set_y`](../functions/rect/set_y.md)
    - [`set_size`](../functions/rect/set_size.md)
    - [`set_width`](../functions/rect/set_width.md)
    - [`set_height`](../functions/rect/set_height.md)

Operators
---------
- [`lhs == rhs`](../operators/rect/equality.md)
- [`lhs != rhs`](../operators/rect/inequality.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
