//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/tue/issues

#pragma once

#include "../vec.hpp"

namespace tue
{
    template<typename T>
    class vec<T, 4>
    {
    public:
        using component_type = T;

        static constexpr int component_count = 4;

    private:
        struct { T data[4]; } impl_;

    public:
        vec() noexcept = default;

        template<typename U>
        explicit constexpr vec(const U& x) noexcept :
            impl_({{
                static_cast<T>(x),
                static_cast<T>(x),
                static_cast<T>(x),
                static_cast<T>(x),
            }})
        {
        }

        constexpr vec(const T& x, const T& y, const T& z, const T& w) noexcept :
            impl_({{ x, y, z, w }})
        {
        }

        constexpr vec(const vec2<T>& xy, const T& z, const T& w) noexcept :
            impl_({{ xy[0], xy[1], z, w }})
        {
        }

        constexpr vec(const vec3<T>& xyz, const T& w) noexcept :
            impl_({{ xyz[0], xyz[1], xyz[2], w }})
        {
        }

        template<typename U>
        explicit constexpr vec(const vec<U, 4>& other) noexcept :
            impl_({{
                static_cast<T>(other[0]),
                static_cast<T>(other[1]),
                static_cast<T>(other[2]),
                static_cast<T>(other[3]),
            }})
        {
        }

        template<typename U>
        constexpr operator vec<U, 4>() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        constexpr T x() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T y() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T z() const noexcept
        {
            return this->impl_.data[2];
        }

        constexpr T w() const noexcept
        {
            return this->impl_.data[3];
        }

        constexpr T r() const noexcept
        {
            return this->impl_.data[0];
        }

        constexpr T g() const noexcept
        {
            return this->impl_.data[1];
        }

        constexpr T b() const noexcept
        {
            return this->impl_.data[2];
        }

        constexpr T a() const noexcept
        {
            return this->impl_.data[3];
        }

        constexpr vec2<T> xy() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        constexpr vec2<T> rg() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
            };
        }

        constexpr vec3<T> xyz() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        constexpr vec3<T> rgb() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
            };
        }

        constexpr vec4<T> xyzw() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        constexpr vec4<T> rgba() const noexcept
        {
            return {
                this->impl_.data[0],
                this->impl_.data[1],
                this->impl_.data[2],
                this->impl_.data[3],
            };
        }

        void set_x(const T& x) noexcept
        {
            this->impl_.data[0] = x;
        }

        void set_y(const T& y) noexcept
        {
            this->impl_.data[1] = y;
        }

        void set_z(const T& z) noexcept
        {
            this->impl_.data[2] = z;
        }

        void set_w(const T& w) noexcept
        {
            this->impl_.data[3] = w;
        }

        void set_r(const T& r) noexcept
        {
            this->impl_.data[0] = r;
        }

        void set_g(const T& g) noexcept
        {
            this->impl_.data[1] = g;
        }

        void set_b(const T& b) noexcept
        {
            this->impl_.data[2] = b;
        }

        void set_a(const T& a) noexcept
        {
            this->impl_.data[3] = a;
        }

        void set_xy(const T& x, const T& y) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
        }

        void set_xy(const vec2<T>& xy) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
        }

        void set_rg(const T& r, const T& g) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
        }

        void set_rg(const vec2<T>& rg) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
        }

        void set_xyz(const T& x, const T& y, const T& z) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
        }

        void set_xyz(const vec2<T>& xy, const T& z) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
            this->impl_.data[2] = z;
        }

        void set_xyz(const vec3<T>& xyz) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
        }

        void set_rgb(const T& r, const T& g, const T& b) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
            this->impl_.data[2] = b;
        }

        void set_rgb(const vec2<T>& rg, const T& b) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
            this->impl_.data[2] = b;
        }

        void set_rgb(const vec3<T>& rgb) noexcept
        {
            this->impl_.data[0] = rgb[0];
            this->impl_.data[1] = rgb[1];
            this->impl_.data[2] = rgb[2];
        }

        void set_xyzw(const T& x, const T& y, const T& z, const T& w) noexcept
        {
            this->impl_.data[0] = x;
            this->impl_.data[1] = y;
            this->impl_.data[2] = z;
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec2<T>& xy, const T& z, const T& w) noexcept
        {
            this->impl_.data[0] = xy[0];
            this->impl_.data[1] = xy[1];
            this->impl_.data[2] = z;
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec3<T>& xyz, const T& w) noexcept
        {
            this->impl_.data[0] = xyz[0];
            this->impl_.data[1] = xyz[1];
            this->impl_.data[2] = xyz[2];
            this->impl_.data[3] = w;
        }

        void set_xyzw(const vec4<T>& xyzw) noexcept
        {
            this->impl_.data[0] = xyzw[0];
            this->impl_.data[1] = xyzw[1];
            this->impl_.data[2] = xyzw[2];
            this->impl_.data[3] = xyzw[3];
        }

        void set_rgba(const T& r, const T& g, const T& b, const T& a) noexcept
        {
            this->impl_.data[0] = r;
            this->impl_.data[1] = g;
            this->impl_.data[2] = b;
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec2<T>& rg, const T& b, const T& a) noexcept
        {
            this->impl_.data[0] = rg[0];
            this->impl_.data[1] = rg[1];
            this->impl_.data[2] = b;
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec3<T>& rgb, const T& a) noexcept
        {
            this->impl_.data[0] = rgb[0];
            this->impl_.data[1] = rgb[1];
            this->impl_.data[2] = rgb[2];
            this->impl_.data[3] = a;
        }

        void set_rgba(const vec4<T>& rgba) noexcept
        {
            this->impl_.data[0] = rgba[0];
            this->impl_.data[1] = rgba[1];
            this->impl_.data[2] = rgba[2];
            this->impl_.data[3] = rgba[3];
        }

        const T* data() const noexcept
        {
            return this->impl_.data;
        }

        T* data() noexcept
        {
            return this->impl_.data;
        }

        template<typename I>
        constexpr const T& operator[](const I& i) const noexcept
        {
            return this->impl_.data[i];
        }

        template<typename I>
        T& operator[](const I& i) noexcept
        {
            return this->impl_.data[i];
        }
    };

    namespace detail_
    {
        template<typename T, typename U>
        inline constexpr bool equality_operator(
            const vec4<T>& lhs, const vec4<U>& rhs) noexcept
        {
            return lhs[0] == rhs[0]
                && lhs[1] == rhs[1]
                && lhs[2] == rhs[2]
                && lhs[3] == rhs[3];
        }
    }
}
