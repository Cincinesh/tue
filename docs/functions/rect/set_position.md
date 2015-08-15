[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`set_position`
=================================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
void rect<P, S>::set_position(const vec2<P>& position) noexcept;

template<typename P, typename S>
void rect<P, S>::set_position(const P& x, const P& y) noexcept;
```

Sets the `position` component of this [`rect`](../../headers/rect.md) either
using a whole [`vec2`](../../headers/vec.md) or individual component values.

To set `position` components individually, use [`set_x, set_y`](set_xy.md)
instead.

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
