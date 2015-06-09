[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`set_size`
=============================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
void rect<P, S>::set_size(const size2d<S>& size) noexcept;

template<typename P, typename S>
void rect<P, S>::set_size(const S& width, const S& height) noexcept;
```

Sets the `size` component of this [`rect`](../../headers/rect.md) either using a
whole [`size2d`](../../headers/size2d.md) or individual component values.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
