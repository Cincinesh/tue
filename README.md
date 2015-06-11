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
    - [`<tue/bool.hpp>`](docs/headers/bool.md)
    - [`<tue/mat.hpp>`](docs/headers/mat.md)
    - [`<tue/math.hpp>`](docs/headers/math.md)
    - [`<tue/pose2d.hpp>`](docs/headers/pose2d.md)
    - [`<tue/pose3d.hpp>`](docs/headers/pose3d.md)
    - [`<tue/quat.hpp>`](docs/headers/quat.md)
    - [`<tue/rect.hpp>`](docs/headers/rect.md)
    - [`<tue/simd.hpp>`](docs/headers/simd.md)
    - [`<tue/size2d.hpp>`](docs/headers/size2d.md)
    - [`<tue/size3d.hpp>`](docs/headers/size3d.md)
    - [`<tue/unused.hpp>`](docs/headers/unused.md)
    - [`<tue/vec.hpp>`](docs/headers/vec.md)
- [Namespaces](docs/namespaces.md)
    - [`tue`](docs/namespaces/tue.md)
        - [`tue::math`](docs/namespaces/tue/math.md)
- [Types](docs/types.md)
    - [`tue::bool8`](docs/headers/bool.md)
    - [`tue::bool16`](docs/headers/bool.md)
    - [`tue::bool32`](docs/headers/bool.md)
    - [`tue::bool64`](docs/headers/bool.md)
    - [`tue::mat`](docs/headers/mat.md)
    - [`tue::pose2d`](docs/headers/pose2d.md)
    - [`tue::pose3d`](docs/headers/pose3d.md)
    - [`tue::quat`](docs/headers/quat.md)
    - [`tue::rect`](docs/headers/rect.md)
    - [`tue::simd`](docs/headers/simd.md)
    - [`tue::size2d`](docs/headers/size2d.md)
    - [`tue::size3d`](docs/headers/size3d.md)
    - [`tue::vec`](docs/headers/vec.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
