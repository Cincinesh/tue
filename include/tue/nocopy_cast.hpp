//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

/*!
 * \defgroup  nocopy_cast_hpp <tue/nocopy_cast.hpp>
 *
 * \brief     The `nocopy_cast<T>()` function template.
 */
namespace tue
{
    namespace detail_
    {
        template<typename T, typename U>
        inline constexpr std::enable_if_t<std::is_same<T, U>::value, const T&>
        nocopy_cast(const U& x) noexcept
        {
            return x;
        }

        template<typename T, typename U>
        inline constexpr std::enable_if_t<!std::is_same<T, U>::value, T>
        nocopy_cast(const U& x) noexcept
        {
            return static_cast<T>(x);
        }
    }

    /*!
     * \addtogroup  nocopy_cast_hpp
     * @{
     */

    /*!
     * \brief     Casts `x` to type `T`, avoiding a copy if possible.
     *
     * \tparam T  The return type.
     * \tparam U  The type of parameter `x`.
     *
     * \param x   The value to cast.
     *
     * \return    A const reference to `x` if `x` is already of type `T`.
     *            `static_cast<T>(x)` otherwise.
     */
    template<typename T, typename U>
    inline constexpr std::conditional_t<std::is_same<T, U>::value, const T&, T>
    nocopy_cast(const U& x) noexcept
    {
        return tue::detail_::nocopy_cast<T, U>(x);
    }

    template<typename T, typename U>
    void nocopy_cast(U&& x) = delete;

    /*!@}*/
}
