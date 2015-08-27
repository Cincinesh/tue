[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/inequality operator
======================================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
// lhs != rhs
template<typename P, typename S, typename OtherP, typename OtherS>
constexpr bool operator!=(
    const rect<P, S>& lhs,
    const rect<OtherP< OtherS>& rhs) noexcept;
```

Returns `false` if the positions and sizes of two
[`rect`](../../headers/rect.md)'s compare equal and `true` otherwise.

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
