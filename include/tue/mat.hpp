//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

namespace tue
{
  // A CxR matrix with components of the given type.
  template<typename T, int C, int R>
  class mat;

  // A 2x2 matrix with components of the given type.
  template<typename T>
  using mat2x2 = mat<T, 2, 2>;

  // A 2x3 matrix with components of the given type.
  template<typename T>
  using mat2x3 = mat<T, 2, 3>;

  // A 2x4 matrix with components of the given type.
  template<typename T>
  using mat2x4 = mat<T, 2, 4>;

  // A 3x2 matrix with components of the given type.
  template<typename T>
  using mat3x2 = mat<T, 3, 2>;

  // A 3x3 matrix with components of the given type.
  template<typename T>
  using mat3x3 = mat<T, 3, 3>;

  // A 3x4 matrix with components of the given type.
  template<typename T>
  using mat3x4 = mat<T, 3, 4>;

  // A 4x2 matrix with components of the given type.
  template<typename T>
  using mat4x2 = mat<T, 4, 2>;

  // A 4x3 matrix with components of the given type.
  template<typename T>
  using mat4x3 = mat<T, 4, 3>;

  // A 4x4 matrix with components of the given type.
  template<typename T>
  using mat4x4 = mat<T, 4, 4>;

  // A 2x2 matrix of float's.
  using fmat2x2 = mat2x2<float>;
  
  // A 2x3 matrix of float's.
  using fmat2x3 = mat2x3<float>;
  
  // A 2x4 matrix of float's.
  using fmat2x4 = mat2x4<float>;
  
  // A 3x2 matrix of float's.
  using fmat3x2 = mat3x2<float>;
  
  // A 3x3 matrix of float's.
  using fmat3x3 = mat3x3<float>;
  
  // A 3x4 matrix of float's.
  using fmat3x4 = mat3x4<float>;
  
  // A 4x2 matrix of float's.
  using fmat4x2 = mat4x2<float>;
  
  // A 4x3 matrix of float's.
  using fmat4x3 = mat4x3<float>;
  
  // A 4x4 matrix of float's.
  using fmat4x4 = mat4x4<float>;

  // A 2x2 matrix of double's.
  using dmat2x2 = mat2x2<double>;
  
  // A 2x3 matrix of double's.
  using dmat2x3 = mat2x3<double>;
  
  // A 2x4 matrix of double's.
  using dmat2x4 = mat2x4<double>;
  
  // A 3x2 matrix of double's.
  using dmat3x2 = mat3x2<double>;
  
  // A 3x3 matrix of double's.
  using dmat3x3 = mat3x3<double>;
  
  // A 3x4 matrix of double's.
  using dmat3x4 = mat3x4<double>;
  
  // A 4x2 matrix of double's.
  using dmat4x2 = mat4x2<double>;
  
  // A 4x3 matrix of double's.
  using dmat4x3 = mat4x3<double>;
  
  // A 4x4 matrix of double's.
  using dmat4x4 = mat4x4<double>;
}

#include "detail_/mat2xR.hpp"
#include "detail_/mat3xR.hpp"
#include "detail_/mat4xR.hpp"
#include "detail_/matmult.hpp"
