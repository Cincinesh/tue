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
    /**
     * \brief     An `N`-dimensional vector.
     * \tparam T  The component type.
     * \tparam N  The number of components. Must be 2, 3, or 4.
     */
    template<typename T, int N>
    class vec;
}
