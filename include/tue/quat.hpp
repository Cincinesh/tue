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

        /*!
         * \brief    Constructs each component with the value of the
         *           corresponding argument.
         *
         * \param x  The value to construct the first component with.
         * \param y  The value to construct the second component with.
         * \param z  The value to construct the third component with.
         * \param w  The value to construct the fourth component with.
         */
        constexpr quat(
            const T& x, const T& y, const T& z, const T& w) noexcept :
            impl_({{ x, y, z, w }})
        {
        }

        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        constexpr const T& operator[](const I& i) const noexcept
        {
            return this->impl_.data[i];
        }

        /*!
         * \brief     Returns a reference to the component at the given index.
         * \details   No bounds checking is performed.
         * \tparam I  The index type.
         * \param i   The index.
         * \return    A reference to the component at the given index.
         */
        template<typename I>
        T& operator[](const I& i) noexcept
        {
            return this->impl_.data[i];
        }

        /*!
         * \brief   Returns a pointer to this `quat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `quat`'s underlying component array.
         */
        const T* data() const noexcept
        {
            return this->impl_.data;
        }

        /*!
         * \brief   Returns a pointer to this `quat`'s underlying component
         *          array.
         *
         * \return  A pointer to this `quat`'s underlying component array.
         */
        T* data() noexcept
        {
            return this->impl_.data;
        }
    };
}
