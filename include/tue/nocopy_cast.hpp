//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include <type_traits>

namespace tue
{
    /*!
     * \brief     Casts `x` to type `T`, avoiding a copy if possible.
     *
     * \tparam T  The return type.
     * \tparam U  The type of parameter `x`.
     *
     * \param x   The value to cast.
     *
     * \return    A const reference to `x` if `x` is already of type `T`. The
     *            new value otherwise.
     */
    template<typename T, typename U>
    constexpr std::enable_if_t<std::is_same<T, U>::value, const T&>
    nocopy_cast(const U& x) noexcept
    {
        return x;
    }

    /*!
     * \brief     Casts `x` to type `T`, avoiding a copy if possible.
     *
     * \tparam T  The return type.
     * \tparam U  The type of parameter `x`.
     *
     * \param x   The value to cast.
     *
     * \return    A const reference to `x` if `x` is already of type `T`. The
     *            new value otherwise.
     */
    template<typename T, typename U>
    constexpr std::enable_if_t<!std::is_same<T, U>::value, T>
    nocopy_cast(const U& x) noexcept
    {
        return static_cast<T>(x);
    }
}
