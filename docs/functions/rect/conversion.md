[Tuesday](../../../README.md)/[`tue::rect`](../../headers/rect.md)/conversion
=============================================================================
Provided by header [`<tue/rect.hpp>`](../../headers/rect.md)

```c++
template<typename P, typename S>
template<typename OtherP, typename OtherS>
constexpr rect<P, S>::operator rect<OtherP, OtherS>() const noexcept;
```

Implicitly converts all the components of this [`rect`](../../headers/rect.md)
to the component types of another `rect`.

Depending on the current compiler configuration, this function may or may not
produce warnings for conversions which lose precision. To suppress such
warnings, use the explicit conversion [constructor](constructor.md) instead.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](../../../LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.
