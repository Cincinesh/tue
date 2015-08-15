[Tuesday](../../../README.md)/[`tue::mat`](../../headers/mat.md)/pre-increment
==============================================================================
Provided by header [`<tue/mat.hpp>`](../../headers/mat.md)

```c++
// ++m
template<typename T, int C, int R>
mat<T, C, R>& operator++(mat<T, C, R>& m) noexcept;
```

Pre-increments each and every component of the given
[`mat`](../../headers/mat.md) and returns a reference to it.

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
