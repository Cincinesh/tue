//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

// The Tuesday C++ math and template library.
namespace tue
{
  // An N-component vector with components of the given type.
  template<typename T, int N>
  class vec;

  // A 2-component vector with components of the given type.
  template<typename T>
  using vec2 = vec<T, 2>;

  // A 3-component vector with components of the given type.
  template<typename T>
  using vec3 = vec<T, 3>;

  // A 4-component vector with components of the given type.
  template<typename T>
  using vec4 = vec<T, 4>;

  // A 2-component vector of float's.
  using fvec2 = vec2<float>;

  // A 3-component vector of float's.
  using fvec3 = vec3<float>;

  // A 4-component vector of float's.
  using fvec4 = vec4<float>;

  // A 2-component vector of double's.
  using dvec2 = vec2<double>;

  // A 3-component vector of double's.
  using dvec3 = vec3<double>;

  // A 4-component vector of double's.
  using dvec4 = vec4<double>;

  // A 2-component vector of int's.
  using ivec2 = vec2<int>;

  // A 3-component vector of int's.
  using ivec3 = vec3<int>;

  // A 4-component vector of int's.
  using ivec4 = vec4<int>;

  // A 2-component vector of unsigned int's.
  using uvec2 = vec2<unsigned int>;

  // A 3-component vector of unsigned int's.
  using uvec3 = vec3<unsigned int>;

  // A 4-component vector of unsigned int's.
  using uvec4 = vec4<unsigned int>;
}

#include "detail_/vec2.hpp"
#include "detail_/vec3.hpp"
#include "detail_/vec4.hpp"
