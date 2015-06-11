The Tuesday C++ Math and Template Library
=========================================

The Tuesday C++ Math and Template Library ("Tuesday" for short) is a library of
template classes and math functions with a focus on physics and graphics
applications. It provides data types commonly used in games and other
simulations such as vectors, quaternions, and matrices, operator overloads for
combining and manipulating these types, as well as some other common
mathematical functions. It was written to match the style of the C++ Standard
Library and uses modern C++ features (i.e., C++14) extensively.


Requirements
------------

TODO


Installation
------------

TODO


API Documentation
-----------------
- [Headers](docs/headers.md)
    - [`<tue/bool.hpp>`](headers/bool.md)
    - [`<tue/mat.hpp>`](headers/mat.md)
    - [`<tue/math.hpp>`](headers/math.md)
    - [`<tue/pose2d.hpp>`](headers/pose2d.md)
    - [`<tue/pose3d.hpp>`](headers/pose3d.md)
    - [`<tue/quat.hpp>`](headers/quat.md)
    - [`<tue/rect.hpp>`](headers/rect.md)
    - [`<tue/simd.hpp>`](headers/simd.md)
    - [`<tue/size2d.hpp>`](headers/size2d.md)
    - [`<tue/size3d.hpp>`](headers/size3d.md)
    - [`<tue/unused.hpp>`](headers/unused.md)
    - [`<tue/vec.hpp>`](headers/vec.md)
- [Namespaces](docs/namespaces.md)
    - [`tue`](namespaces/tue.md)
        - [`tue::math`](namespaces/tue/math.md)
- [Types](docs/types.md)
    - [`tue::bool8`](headers/bool.md)
    - [`tue::bool16`](headers/bool.md)
    - [`tue::bool32`](headers/bool.md)
    - [`tue::bool64`](headers/bool.md)
    - [`tue::mat`](headers/mat.md)
    - [`tue::pose2d`](headers/pose2d.md)
    - [`tue::pose3d`](headers/pose3d.md)
    - [`tue::quat`](headers/quat.md)
    - [`tue::rect`](headers/rect.md)
    - [`tue::simd`](headers/simd.md)
    - [`tue::size2d`](headers/size2d.md)
    - [`tue::size3d`](headers/size3d.md)
    - [`tue::vec`](headers/vec.md)


License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
