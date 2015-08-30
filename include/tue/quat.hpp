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
     * \brief     A quaternion.
     * \details   `quat` has the same size and alignment requirements as `T[4]`.
     * \tparam T  The component type.
     */
    template<typename T>
    class quat;

    /*!
     * \brief  A quaternion with `float` components.
     */
    using fquat = quat<float>;

    /*!
     * \brief  A quaternion with `double` components.
     */
    using dquat = quat<double>;

    /**/
    template<typename T>
    class quat
    {
        struct { T data[4]; } impl_;

    public:
        /*!
         * \brief  This `quat` type's component type.
         */
        using component_type = T;

        /*!
         * \brief  This `quat` type's component count.
         */
        static constexpr int component_count = 4;

        /*!
         * \brief  Default constructs each component.
         */
        quat() noexcept = default;
    };
}
