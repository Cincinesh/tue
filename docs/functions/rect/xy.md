[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/`x, y`
=========================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
constexpr P rect<P, S>::x() const noexcept;

template<typename P, typename S>
constexpr P rect<P, S>::y() const noexcept;
```

Returns copies of the `x` and `y` components this
[`rect`](../../headers/rect.md)'s [`position`](position.md) component.

To access both `position` components in one function call, use
[`position`](position.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
