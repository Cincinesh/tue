//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

namespace tue {

template<typename T, int C, int R = C>
class mat;

template<typename T>
using mat2x2 = mat<T, 2, 2>;

template<typename T>
using mat2x3 = mat<T, 2, 3>;

template<typename T>
using mat2x4 = mat<T, 2, 4>;

template<typename T>
using mat3x2 = mat<T, 3, 2>;

template<typename T>
using mat3x3 = mat<T, 3, 3>;

template<typename T>
using mat3x4 = mat<T, 3, 4>;

template<typename T>
using mat4x2 = mat<T, 4, 2>;

template<typename T>
using mat4x3 = mat<T, 4, 3>;

template<typename T>
using mat4x4 = mat<T, 4, 4>;

using fmat2x2 = mat2x2<float>;
using fmat2x3 = mat2x3<float>;
using fmat2x4 = mat2x4<float>;
using fmat3x2 = mat3x2<float>;
using fmat3x3 = mat3x3<float>;
using fmat3x4 = mat3x4<float>;
using fmat4x2 = mat4x2<float>;
using fmat4x3 = mat4x3<float>;
using fmat4x4 = mat4x4<float>;

using dmat2x2 = mat2x2<double>;
using dmat2x3 = mat2x3<double>;
using dmat2x4 = mat2x4<double>;
using dmat3x2 = mat3x2<double>;
using dmat3x3 = mat3x3<double>;
using dmat3x4 = mat3x4<double>;
using dmat4x2 = mat4x2<double>;
using dmat4x3 = mat4x3<double>;
using dmat4x4 = mat4x4<double>;

namespace detail_
{
    template<typename T, int C, int R>
    struct mat_utils;
}

}

#include "detail_/mat2xR.hpp"
#include "detail_/mat3xR.hpp"
#include "detail_/mat4xR.hpp"
#include "detail_/matmult.hpp"
#include "detail_/mattransform.hpp"
