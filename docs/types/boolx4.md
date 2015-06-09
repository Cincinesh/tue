[Tuesday](../../README.md)/[Types](../types.md)/`boolx4`
========================================================
Provided by header [`<tue/simd.hpp>`](../headers/simd.md)

`tue::boolx4` represents a 4-component array of booleans for use with SIMD
intrinsics. Currently, only an SSE-accelerated version is provided where
available with an un-accelerated compatibility fallback otherwise. It is
declared as follows:

```c++
class boolx4;
```

The SSE-accelerated version is backed by a single `__m128`. Its format is meant
to correspond with the output of SSE comparison intrinsics such as
`_mm_cmplt_ps` and `_mm_cmpeq_ps`.

The un-accelerated compatibility fallback is simply an array of 4 `bool`'s.

Note: This type is very different from [`bvec4`](../headers/vec.md). The
interface intentionally makes it difficult to access individual components since
this is a slow operation in most SIMD instruction sets and it may have stricter
alignment requirements.

Member types
------------
```c++
using component_type = bool;
```

Member constants
----------------
```c++
static constexpr int component_count = 4;
```

Member functions
----------------
- Object creation
    - [(constructor)](../functions/boolx4/constructor.md)
- Conversions
    - [`__m128`](../operators/boolx4/__m128.md) (SSE only)

Operators
---------
- [`~v`](../operators/boolx4/bitwise_not.md)
- [`lhs & rhs`](../operators/boolx4/bitwise_and.md)
- [`lhs | rhs`](../operators/boolx4/bitwise_or.md)
- [`lhs ^ rhs`](../operators/boolx4/bitwise_xor.md)
- [`v &= other`](../operators/boolx4/bitwise_and_assignment.md)
- [`v |= other`](../operators/boolx4/bitwise_or_assignment.md)
- [`v ^= other`](../operators/boolx4/bitwise_xor_assignment.md)
- [`lhs == rhs`](../operators/boolx4/equality.md)
- [`lhs != rhs`](../operators/boolx4/inequality.md)

Non-member functions
--------------------
- [`tue::math`](../namespaces/tue/math.md)
    - Logical functions
        - [`select`](../functions/math/select.md)

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
