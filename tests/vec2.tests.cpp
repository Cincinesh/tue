//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#include <tue/vec.hpp>
#include <mon/test_case.hpp>

namespace
{
    using namespace tue;

    TEST_CASE(default_constructor)
    {
        fvec2 v;
        //unused(v); // TODO
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR fvec2 v(1.2);
        test_assert(v[0] == 1.2f);
        test_assert(v[1] == 1.2f);
    }

    TEST_CASE(individual_components_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 v = { 1.2, 3.4 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
    }

    TEST_CASE(truncate_vec3_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 v(dvec3(1.2, 3.4, 5.6));
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
    }

    TEST_CASE(truncate_vec4_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 v(dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dvec2 dv(1.2, 3.4);
        CONST_OR_CONSTEXPR fvec2 fv(dv);
        test_assert(fv[0] == 1.2f);
        test_assert(fv[1] == 3.4f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fvec2 fv(1.2f, 3.4f);
        CONST_OR_CONSTEXPR dvec2 dv = fv;
        test_assert(dv[0] == 1.2f);
        test_assert(dv[1] == 3.4f);
    }

    TEST_CASE(x_y_z)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto x = v.x();
        CONST_OR_CONSTEXPR auto y = v.y();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
    }

    TEST_CASE(r_g_b)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4);
        CONST_OR_CONSTEXPR auto r = v.r();
        CONST_OR_CONSTEXPR auto g = v.g();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
    }

    // TODO
    /*TEST_CASE(xy_rg)
    {
        CONST_OR_CONSTEXPR dvec2 v(1.2, 3.4, 5.6);
        CONST_OR_CONSTEXPR auto xy = v.xy();
        CONST_OR_CONSTEXPR auto rg = v.rg();
        test_assert(xy == dvec2(1.2, 3.4));
        test_assert(rg == dvec2(1.2, 3.4));
    }*/

    TEST_CASE(set_x_y)
    {
        dvec2 v(1.2, 3.4);
        v.set_x(5.6);
        v.set_y(7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);
    }

    TEST_CASE(set_r_g)
    {
        dvec2 v(1.2, 3.4);
        v.set_r(5.6);
        v.set_g(7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);
    }

    TEST_CASE(set_xy)
    {
        dvec2 v(1.2, 3.4);
        
        v.set_xy(5.6, 7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);

        v.set_xy(dvec2(9.10, 11.12));
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
    }

    TEST_CASE(set_rg)
    {
        dvec2 v(1.2, 3.4);
        
        v.set_rg(5.6, 7.8);
        test_assert(v[0] == 5.6);
        test_assert(v[1] == 7.8);

        v.set_rg(dvec2(9.10, 11.12));
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
    }

    TEST_CASE(data)
    {
        const dvec2 cv(1.2);
        test_assert(cv.data() == static_cast<const void*>(&cv));

        dvec2 v;
        test_assert(v.data() == static_cast<void*>(&v));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dvec2 cev(1.2, 3.4);
        CONST_OR_CONSTEXPR auto cev0 = cev[0];
        CONST_OR_CONSTEXPR auto cev1 = cev[1];
        test_assert(cev0 == 1.2);
        test_assert(cev1 == 3.4);

        const auto cv = cev;
        const auto& cv0 = cv[0];
        const auto& cv1 = cv[1];
        test_assert(&cv0 == cv.data() + 0);
        test_assert(&cv1 == cv.data() + 1);

        auto v = cev;
        auto& v0 = v[0];
        auto& v1 = v[1];
        test_assert(&v0 == v.data() + 0);
        test_assert(&v1 == v.data() + 1);
    }
}
