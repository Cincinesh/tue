[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`set_x, set_y`
==========================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
void rect<P, S>::set_x(const P& x) noexcept;

template<typename P, typename S>
void rect<P, S>::set_y(const P& y) noexcept;
```

Sets the `x` and `y` components of this [`rect`](../../headers/rect.md)'s
`position` component.

To set both components in one function call, use
[`set_position`](set_position.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
