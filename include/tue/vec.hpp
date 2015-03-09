//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace tue {

template<typename T, int N>
class vec;

template<typename T>
using vec2 = vec<T, 2>;

template<typename T>
using vec3 = vec<T, 3>;

template<typename T>
using vec4 = vec<T, 4>;

using fvec2 = vec2<float>;
using fvec3 = vec3<float>;
using fvec4 = vec4<float>;
using dvec2 = vec2<double>;
using dvec3 = vec3<double>;
using dvec4 = vec4<double>;
using ivec2 = vec2<int>;
using ivec3 = vec3<int>;
using ivec4 = vec4<int>;
using uvec2 = vec2<unsigned int>;
using uvec3 = vec3<unsigned int>;
using uvec4 = vec4<unsigned int>;
using bvec2 = vec2<bool>;
using bvec3 = vec3<bool>;
using bvec4 = vec4<bool>;

}

#include "detail_/vec2.hpp"
#include "detail_/vec3.hpp"
#include "detail_/vec4.hpp"
