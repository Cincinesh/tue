[Tuesday](../../../README.md)/[`tue::vec`](../../headers/vec.md)/`data`
=======================================================================
Provided by header [`<tue/vec.hpp>`](../../headers/vec.md)

```c++
template<typename T, int N>
T* vec<T, T>::data() noexcept;

template<typename T, int N>
const T* vec<T, N>::data() const noexcept;
```

Returns a pointer to this [`vec`](../../headers/vec.md)'s underlying component
array.

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
