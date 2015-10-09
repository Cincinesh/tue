//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

/*!
 * \addtogroup  simd_hpp
 * @{
 */
#if defined(__SSE__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 1) \
    || defined(_M_X64)
/*!
 * \brief Defined if the current compiler configuration supports SSE
 *        intrinsics.
 */
#define TUE_SSE
#endif

#if defined(__SSE2__) \
    || (defined(_M_IX86_FP) && _M_IX86_FP >= 2) \
    || defined(_M_X64)
/*!
 * \brief Defined if the current compiler configuration supports SSE2
 *        intrinsics.
 */
#define TUE_SSE2
#endif

/*!@}*/
