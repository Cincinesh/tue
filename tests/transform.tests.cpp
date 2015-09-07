//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/transform.hpp>
#include <mon/test_case.hpp>

#include <tue/vec.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(rotation_vec_to_axis_angle)
    {
        const ivec3 rv1(1, 2, 3);
        const auto aa1 = transform::axis_angle(rv1);
        test_assert(aa1.xyz() == math::normalize(rv1));
        test_assert(aa1.a() == math::length(rv1));

        const ivec3 rv2(0, 0, 0);
        const auto aa2 = transform::axis_angle(rv2);
        test_assert(aa2.xyz() == dvec3::z_axis());
        test_assert(aa2.a() == 0.0);
    }
}
