[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`width`
==========================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
constexpr S rect<P, S>::width() const noexcept;
```

Returns copies of the `width` and `height` components of this
[`rect`](../../headers/rect.md)'s [`size`](size.md) component.

To access both `size` components in one function call, use [`size`](size.md)
instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
