[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`position`
=============================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
constexpr vec2<P> rect<P, S>::position() const noexcept;
```

Returns a copy of this [`rect`](../../headers/rect.md)'s `position` component
(represented by a [`vec2`](../../headers/vec.md)).

To access `position` components individually, use [`x, y`](xy.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
