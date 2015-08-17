The Tuesday C++ Math and Template Library
=========================================
The Tuesday C++ Math and Template Library ("Tuesday" for short) is a library of
template classes and math functions with a focus on physics and graphics
applications. It provides data types commonly used in games and other
simulations such as [vectors](docs/headers/vec.md),
[quaternions](docs/headers/quat.md), and [matrices](docs/headers/mat.md),
[SIMD intrinsic wrapper classes](docs/headers/simd.md) completely separate from
(but compatible with) the other types, operator overloads for combining and
manipulating all these types, as well as some other
[common mathematical functions](docs/namespaces/tue/math.md). It was written to
match the style of the C++ Standard Library and uses modern C++ features (i.e.,
C++14) extensively.

Advantages Over GLM
-------------------
[GLM](https://github.com/g-truc/glm) is great and currently provides a lot of
features Tuesday simply doesn't (yet). Tuesday does, however, provide the
following unique features:

- The dimensions of [vector](docs/headers/vec.md) and
  [matrix](docs/headers/mat.md) types are template parameters, unlike GLM where,
  e.g., `tvec2`, `tvec3`, and `tvec4` are separate types. By making the
  dimensions template parameters, it's possible to write one template function
  that can operate on and/or produce vectors or matrices of multiple dimensions.
  For example, the transformation matrix generation functions (
  [`translation_mat`](docs/functions/math/translation_mat.md),
  [`rotation_mat`](docs/functions/math/rotation_mat.md), etc.) can produce
  matrices of multiple sizes so long as they meet the minimum requirements of
  each transformation and are, at the largest, 4x4.

- It makes heavy use of `decltype` and `auto` return types. This makes it
  possible for composite types to behave much more like their component types
  when it comes to things like implicit type conversions. For example,
  `fvec3 + dvec3` results in a `dvec3` just as `float + double` results in a
  `double`.

- It uses `constexpr` whenever possible which, as it turns out, is often.

- [SIMD types](docs/headers/simd.md) are completely separate from the [vector
  types](docs/headers/vec.md). This may seem counter-intuitive, but SIMD vectors
  aren't very efficient when used as traditional 3D vectors. The fourth
  component of an SIMD vector would often go to waste, and functions where
  multiple components interact (such as the
  [length](docs/functions/math/length.md) function,
  [dot](docs/functions/math/dot.md) product, or
  [cross](docs/functions/math/cross.md) product) would be horribly inefficient
  with SIMD intrinsics. Instead, SIMD instructions should be used to perform the
  same logic on multiple vectors in parallel. Tuesday makes this easy to do. For
  example, `vec3<float32x4> v` could be thought of as 4 parallel 3D vectors
  (4 x-values, followed by 4 y-values, and finally 4 z-values). Something like
  `math::dot(v)` would then compute a single `float32x4` containing the dot
  products of those 4 parallel vectors without any inefficient component
  shuffling.

Status
------
Tuesday is currently a work-in-progress and has no version numbering scheme. It
is, however, well-tested with unit tests and already in a useful state. The
majority of the work remaining before a "release" version involves user testing
and a little more documentation.

See [issues I've opened]
(https://github.com/Cincinesh/tue/issues/created_by/Cincinesh)
for a list of currently-planned additions.

Requirements
------------
Tuesday requires Visual Studio 2015 or a C++14 compiler.

Usage
-----
Tuesday is a header-only library. Simply make sure the `include` directory in
the root of this project is on your include path. For GCC and Clang, you might
have to provide the compiler option `-std=c++14` or higher as well.

I will try to write some small examples to demonstrate Tuesday's major features
here soon.

Testing
-------
Here are some tips for running the unit tests:
- This repository uses git submodules. After cloning, make sure to use
  `git submodule init` and `git submodule update`.
- This project uses a fairly simple [CMake](http://www.cmake.org/)
  configuration. Use CMake to generate IDE project files or build scripts and
  simply build the `check` target to run the unit tests.

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
