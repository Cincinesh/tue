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

        constexpr vec(const T& x, const T& y, const T& z, const T& w) noexcept;

        constexpr vec(const vec2<T>& xy, const T& z, const T& w) noexcept;

        constexpr vec(const vec3<T>& xyz, const T& w) noexcept;

        template<typename U>
        explicit constexpr vec(const vec<U, 4>& other) noexcept;

        template<typename U>
        constexpr operator vec<U, 4>() const noexcept;

        constexpr T x() const noexcept;

        constexpr T y() const noexcept;

        constexpr T z() const noexcept;

        constexpr T w() const noexcept;

        constexpr T r() const noexcept;

        constexpr T g() const noexcept;

        constexpr T b() const noexcept;

        constexpr T a() const noexcept;

        constexpr vec2<T> xy() const noexcept;

        constexpr vec2<T> rg() const noexcept;

        constexpr vec3<T> xyz() const noexcept;

        constexpr vec3<T> rgb() const noexcept;

        constexpr vec4<T> xyzw() const noexcept;

        constexpr vec4<T> rgba() const noexcept;

        void set_x(const T& x) noexcept;

        void set_y(const T& y) noexcept;

        void set_z(const T& z) noexcept;

        void set_w(const T& w) noexcept;

        void set_r(const T& r) noexcept;

        void set_g(const T& g) noexcept;

        void set_b(const T& b) noexcept;

        void set_a(const T& a) noexcept;

        void set_xy(const T& x, const T& y) noexcept;

        void set_xy(const vec2<T>& xy) noexcept;

        void set_rg(const T& r, const T& g) noexcept;

        void set_rg(const vec2<T>& rg) noexcept;

        void set_xyz(const T& x, const T& y, const T& z) noexcept;

        void set_xyz(const vec2<T>& xy, const T& z) noexcept;

        void set_xyz(const vec3<T>& xyz) noexcept;

        void set_rgb(const T& r, const T& g, const T& b) noexcept;

        void set_rgb(const vec2<T>& rg, const T& b) noexcept;

        void set_rgb(const vec3<T>& rgb) noexcept;

        void set_xyzw(const T& x, const T& y, const T& z, const T& w) noexcept;

        void set_xyzw(const vec2<T>& xy, const T& z, const T& w) noexcept;

        void set_xyzw(const vec3<T>& xyz, const T& w) noexcept;

        void set_xyzw(const vec4<T>& xyzw) noexcept;

        void set_rgba(const T& r, const T& g, const T& b, const T& a) noexcept;

        void set_rgba(const vec2<T>& rg, const T& b, const T& a) noexcept;

        void set_rgba(const vec3<T>& rgb, const T& a) noexcept;

        void set_rgba(const vec4<T>& rgba) noexcept;

        const T* data() const noexcept;

        T* data() noexcept;

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
}
