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
        fvec4 v;
        //unused(v); // TODO
    }

    TEST_CASE(scalar_constructor)
    {
        CONST_OR_CONSTEXPR fvec4 v(1.2);
        test_assert(v[0] == 1.2f);
        test_assert(v[1] == 1.2f);
        test_assert(v[2] == 1.2f);
        test_assert(v[3] == 1.2f);
    }

    TEST_CASE(individual_components_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { 1.2, 3.4, 5.6, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(first_two_components_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { { 1.2, 3.4 }, 5.6, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(first_three_components_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 v = { { 1.2, 3.4, 5.6 }, 7.8 };
        test_assert(v[0] == 1.2);
        test_assert(v[1] == 3.4);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(explicit_conversion_constructor)
    {
        CONST_OR_CONSTEXPR dvec4 dv(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR fvec4 fv(dv);
        test_assert(fv[0] == 1.2f);
        test_assert(fv[1] == 3.4f);
        test_assert(fv[2] == 5.6f);
        test_assert(fv[3] == 7.8f);
    }

    TEST_CASE(implicit_conversion_operator)
    {
        CONST_OR_CONSTEXPR fvec4 fv(1.2f, 3.4f, 5.6f, 7.8f);
        CONST_OR_CONSTEXPR dvec4 dv = fv;
        test_assert(dv[0] == 1.2f);
        test_assert(dv[1] == 3.4f);
        test_assert(dv[2] == 5.6f);
        test_assert(dv[3] == 7.8f);
    }

    TEST_CASE(x_y_z_w)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto x = v.x();
        CONST_OR_CONSTEXPR auto y = v.y();
        CONST_OR_CONSTEXPR auto z = v.z();
        CONST_OR_CONSTEXPR auto w = v.w();
        test_assert(x == 1.2);
        test_assert(y == 3.4);
        test_assert(z == 5.6);
        test_assert(w == 7.8);
    }

    TEST_CASE(r_g_b_a)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto r = v.r();
        CONST_OR_CONSTEXPR auto g = v.g();
        CONST_OR_CONSTEXPR auto b = v.b();
        CONST_OR_CONSTEXPR auto a = v.a();
        test_assert(r == 1.2);
        test_assert(g == 3.4);
        test_assert(b == 5.6);
        test_assert(a == 7.8);
    }

    // TODO
    /*TEST_CASE(xy_rg)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xy = v.xy();
        CONST_OR_CONSTEXPR auto rg = v.rg();
        test_assert(xy == dvec2(1.2, 3.4));
        test_assert(rg == dvec2(1.2, 3.4));
    }*/

    // TODO
    /*TEST_CASE(xyz_rgb)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyz = v.xyz();
        CONST_OR_CONSTEXPR auto rgb = v.rgb();
        test_assert(xyz == dvec3(1.2, 3.4, 5.6));
        test_assert(rgb == dvec3(1.2, 3.4, 5.6));
    }*/

    // TODO
    /*TEST_CASE(xyzw_rgba)
    {
        CONST_OR_CONSTEXPR dvec4 v(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto xyzw = v.xyzw();
        CONST_OR_CONSTEXPR auto rgba = v.rgba();
        test_assert(xyzw == dvec4(1.2, 3.4, 5.6, 7.8));
        test_assert(rgba == dvec4(1.2, 3.4, 5.6, 7.8));
    }*/

    TEST_CASE(set_x_y_z_w)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        v.set_x(9.10);
        v.set_y(11.12);
        v.set_z(13.14);
        v.set_w(15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);
    }

    TEST_CASE(set_r_g_b_a)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        v.set_r(9.10);
        v.set_g(11.12);
        v.set_b(13.14);
        v.set_a(15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);
    }

    TEST_CASE(set_xy)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_xy(9.10, 11.12);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);

        v.set_xy(dvec2(13.14, 15.16));
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_rg)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_rg(9.10, 11.12);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);

        v.set_rg(dvec2(13.14, 15.16));
        test_assert(v[0] == 13.14);
        test_assert(v[1] == 15.16);
        test_assert(v[2] == 5.6);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_xyz)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_xyz(9.10, 11.12, 13.14);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 7.8);

        v.set_xyz(dvec2(15.16, 17.18), 19.20);
        test_assert(v[0] == 15.16);
        test_assert(v[1] == 17.18);
        test_assert(v[2] == 19.20);
        test_assert(v[3] == 7.8);

        v.set_xyz(dvec3(21.22, 23.24, 25.26));
        test_assert(v[0] == 21.22);
        test_assert(v[1] == 23.24);
        test_assert(v[2] == 25.26);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_rgb)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_rgb(9.10, 11.12, 13.14);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 7.8);

        v.set_rgb(dvec2(15.16, 17.18), 19.20);
        test_assert(v[0] == 15.16);
        test_assert(v[1] == 17.18);
        test_assert(v[2] == 19.20);
        test_assert(v[3] == 7.8);

        v.set_rgb(dvec3(21.22, 23.24, 25.26));
        test_assert(v[0] == 21.22);
        test_assert(v[1] == 23.24);
        test_assert(v[2] == 25.26);
        test_assert(v[3] == 7.8);
    }

    TEST_CASE(set_xyzw)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_xyzw(9.10, 11.12, 13.14, 15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);

        v.set_xyzw(dvec2(17.18, 19.20), 21.22, 23.24);
        test_assert(v[0] == 17.18);
        test_assert(v[1] == 19.20);
        test_assert(v[2] == 21.22);
        test_assert(v[3] == 23.24);

        v.set_xyzw(dvec3(25.26, 27.28, 29.30), 31.32);
        test_assert(v[0] == 25.26);
        test_assert(v[1] == 27.28);
        test_assert(v[2] == 29.30);
        test_assert(v[3] == 31.32);

        v.set_xyzw(dvec4(33.34, 35.36, 37.38, 39.40));
        test_assert(v[0] == 33.34);
        test_assert(v[1] == 35.36);
        test_assert(v[2] == 37.38);
        test_assert(v[3] == 39.40);
    }

    TEST_CASE(set_rgba)
    {
        dvec4 v(1.2, 3.4, 5.6, 7.8);
        
        v.set_rgba(9.10, 11.12, 13.14, 15.16);
        test_assert(v[0] == 9.10);
        test_assert(v[1] == 11.12);
        test_assert(v[2] == 13.14);
        test_assert(v[3] == 15.16);

        v.set_rgba(dvec2(17.18, 19.20), 21.22, 23.24);
        test_assert(v[0] == 17.18);
        test_assert(v[1] == 19.20);
        test_assert(v[2] == 21.22);
        test_assert(v[3] == 23.24);

        v.set_rgba(dvec3(25.26, 27.28, 29.30), 31.32);
        test_assert(v[0] == 25.26);
        test_assert(v[1] == 27.28);
        test_assert(v[2] == 29.30);
        test_assert(v[3] == 31.32);

        v.set_rgba(dvec4(33.34, 35.36, 37.38, 39.40));
        test_assert(v[0] == 33.34);
        test_assert(v[1] == 35.36);
        test_assert(v[2] == 37.38);
        test_assert(v[3] == 39.40);
    }

    TEST_CASE(data)
    {
        const dvec4 cv(1.2);
        test_assert(cv.data() == static_cast<const void*>(&cv));

        dvec4 v;
        test_assert(v.data() == static_cast<void*>(&v));
    }

    TEST_CASE(subscript_operator)
    {
        CONST_OR_CONSTEXPR dvec4 cev(1.2, 3.4, 5.6, 7.8);
        CONST_OR_CONSTEXPR auto cev0 = cev[0];
        CONST_OR_CONSTEXPR auto cev1 = cev[1];
        CONST_OR_CONSTEXPR auto cev2 = cev[2];
        CONST_OR_CONSTEXPR auto cev3 = cev[3];
        test_assert(cev0 == 1.2);
        test_assert(cev1 == 3.4);
        test_assert(cev2 == 5.6);
        test_assert(cev3 == 7.8);

        const auto cv = cev;
        const auto& cv0 = cv[0];
        const auto& cv1 = cv[1];
        const auto& cv2 = cv[2];
        const auto& cv3 = cv[3];
        test_assert(&cv0 == cv.data() + 0);
        test_assert(&cv1 == cv.data() + 1);
        test_assert(&cv2 == cv.data() + 2);
        test_assert(&cv3 == cv.data() + 3);

        auto v = cev;
        auto& v0 = v[0];
        auto& v1 = v[1];
        auto& v2 = v[2];
        auto& v3 = v[3];
        test_assert(&v0 == v.data() + 0);
        test_assert(&v1 == v.data() + 1);
        test_assert(&v2 == v.data() + 2);
        test_assert(&v3 == v.data() + 3);
    }
}
