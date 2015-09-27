//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

namespace tue
{
    /*!
     * \defgroup  unused_hpp <tue/unused.hpp>
     *
     * \brief     The `unused()` function template.
     *
     * @{
     */

    /*!
     * \brief        Suppresses unused variable warnings.
     *
     * \tparam Args  The parameter types with reference qualifiers removed.
     */
    template<typename... Args>
    inline void unused(Args&&...) noexcept
    {
    }

    /*!@}*/
}
