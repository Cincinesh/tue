[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`set_width, set_height`
==========================================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
void rect<P, S>::set_width(const S& width) noexcept;

template<typename P, typename S>
void rect<P, S>::set_height(const S& height) noexcept;
```

Sets the `width` and `height` components of this
[`rect`](../../headers/rect.md)'s `size` component.

To set both components in one function call, use [`set_size`](set_size.md)
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
