[Tuesday](../../README.md)/[Headers](../headers.md)/`<tue/unused.hpp>`
======================================================================
This header provides the `tue::unused` function template. It is defined as
follows:

```c++
template<typename... Args>
inline void unused(Args&&...) noexcept {}
```

The `unused` function template is useful for suppressing unused variable
compiler warnings. Using it will evaluate but won't copy the given arguments.

Example
-------
```c++
#include <mutex>
#include <tue/unused.hpp>

class big_type;

std::mutex my_mutex;

void do_something(int arg1, const big_type& arg2) {
  tue::unused(arg1, arg2);

  std::lock_guard<std::mutex> my_lock(my_mutex);
  tue::unused(my_lock);

  // Now really do something
}
```

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/tue/issues.
