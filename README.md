The Tuesday C++ Math and Template Library
=========================================
The Tuesday C++ Math and Template Library ("Tuesday" for short) is a library of
template classes and math functions with a focus on physics and graphics
applications. It provides data types commonly used in games and other
simulations such as vectors, quaternions, and matrices, operator overloads for
combining and manipulating these types, as well as some other common
mathematical functions. It was written to match the style of the C++ Standard
Library and uses modern C++ features (i.e., C++14) extensively.

Status
------
Tuesday is currently a work-in-progress and has no version numbering scheme. It
is, however, well-tested with unit tests and already in a useful state. The
majority of the work remaining before a "release" version involves user testing
and documentation.

Requirements
------------
Visual Studio 2015 or a C++14 compiler.

Installation
------------
Tuesday is a header-only library. Simply make sure the `include` directory in
the root of this project is on your include path.

Developer Setup
---------------
Here are some tips if you want to make changes or additions to Tuesday:
- This repository uses git submodules. After cloning, make sure to use
  `git submodule init` and `git submodule update`.
- Only Visual Studio 2015 project files are provided. To compile the tests with
  any other IDE or build system, simply make sure `include` and
  `lib/mon/include` are in the include path and compile all the source files
  under the `tests` and `lib/mon/src` directories.

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

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
