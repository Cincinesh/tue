Header `<tue/size2d.hpp>`
=========================
This header provides the `size2d` type and type aliases.

Types
-----
The `size2d` type represents a 2-dimensional size (width and height) with a
given component type. It is declared as follows:

    template<typename T>
    class size2d;

`T` is used to specify the component type. No restrictions are placed on this
type.

Type aliases
------------
    using fsize2d = size2d<float>;
    using dsize2d = size2d<double>;
    using isize2d = size2d<int>;
    using usize2d = size2d<unsigned int>;

Member types
------------
    using component_type = T;

Member functions
----------------
- Object creation
    - [(constructor)](../functions/size2d/constructor.md)
    - [(conversion)](../functions/size2d/conversion.md)
- Accessors
	- [`width`](../functions/size2d/width.md)
	- [`height`](../functions/size2d/height.md)
- Modifiers
	- [`set_width`](../functions/size2d/set_width.md)
	- [`set_height`](../functions/size2d/set_height.md)

Operators
---------
- [`lhs == rhs`](../operators/size2d/equal_to.md)
- [`lhs != rhs`](../operators/size2d/not_equal_to.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
