[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/constructor
==============================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
// (1)
template<typename P, typename S>
rect<P, S>::rect() noexcept = default;

// (2)
template<typename P, typename S>
constexpr rect<P, S>::rect(
    const P& x, const P& y,
    const S& width, const S& height) noexcept;

// (3)
template<typename P, typename S>
constexpr rect<P, S>::rect(
    const P& x, const P& y,
    const size2d<S>& size) noexcept;

// (4)
template<typename P, typename S>
constexpr rect<P, S>::rect(
    const vec2<P>& position,
    const S& width, const S& height) noexcept;

// (5)
template<typename P, typename S>
constexpr rect<P, S>::rect(
    const vec2<P>& position,
    const size2d<S>& size) noexcept;

// (6)
template<typename P, typename S>
template<typename OtherP, typename OtherS>
explicit constexpr rect<P, S>::rect(
    const rect<OtherP, OtherS>& other) noexcept;
```

1. Default-constructs a new [`rect`](../../headers/rect.md).

2. Constructs a new `rect` with the given position (`x` and `y`) and size
   (`width` and `height`).

3. Constructs a new `rect` with the given position (`x` and `y`) and `size`.

4. Constructs a new `rect` with the given `position` and size (`width` and
   `height`).

5. Constructs a new `rect` with the given `position` and `size`.

6. Explicitly converts the corresponding components of another `rect` with
   different component types to the new `rect`'s component types. Implicit
   [conversion](conversion.md) is also available.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
