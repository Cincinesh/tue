//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "size2d.hpp"
#include "vec.hpp"

namespace tue
{
	// ----------
	// rect<P, S>
	// ----------
	template<typename P, typename S = P>
	class rect;

	using frect = rect<float>;
	using drect = rect<double>;
	using irect = rect<int>;
	using urect = rect<unsigned int>;
	using iurect = rect<int, unsigned int>;

	template<typename P, typename S>
	class rect
	{
	private:
		vec2<P> position_;
		size2d<S> size_;

	public:
		// -------------------
		// default constructor
		// -------------------
		rect() = default;

		// ----------------------
		// component constructors
		// ----------------------
		explicit constexpr rect(
			const P& x,
			const P& y,
			const S& width,
			const S& height) :
			position_(x, y),
			size_(width, height) {}

		explicit constexpr rect(
			const P& x,
			const P& y,
			const size2d<S>& size) :
			position_(x, y),
			size_(size) {}

		explicit constexpr rect(
			const vec2<P>& position,
			const S& width,
			const S& height) :
			position_(position),
			size_(width, height) {}

		explicit constexpr rect(
			const vec2<P>& position,
			const size2d<S>& size) :
			position_(position),
			size_(size) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename OtherP, typename OtherS>
		explicit constexpr rect(
			const rect<OtherP, OtherS>& other) :
			position_(vec2<P>(other.position())),
			size_(size2d<S>(other.size())) {}

		// ----------------------------
		// implicit conversion operator
		// ----------------------------
		template<typename OtherP, typename OtherS>
		constexpr operator rect<OtherP, OtherS>() const
		{
			return rect<OtherP, OtherS>(position_, size_);
		}

		// --------
		// position
		// --------
		constexpr vec2<P> position() const { return position_; }
		void set_position(const P& x, const P& y)
		{
			position_.set_x(x);
			position_.set_y(y);
		}
		void set_position(const vec2<P>& position)
		{
			position_ = position;
		}

		// -
		// x
		// -
		constexpr P x() const { return position_.x(); }
		void set_x(const P& x) { position_.set_x(x); }

		// -
		// y
		// -
		constexpr P y() const { return position_.y(); }
		void set_y(const P& y) { position_.set_y(y); }

		// ----
		// size
		// ----
		constexpr size2d<S> size() const { return size_; }
		void set_size(const S& width, const S& height)
		{
			size_.set_width(width);
			size_.set_height(height);
		}
		void set_size(const size2d<S>& size)
		{
			size_ = size;
		}

		// -----
		// width
		// -----
		constexpr S width() const { return size_.width(); }
		void set_width(const S& width) { size_.set_width(width); }

		// ------
		// height
		// ------
		constexpr S height() const { return size_.height(); }
		void set_height(const S& height) { size_.set_height(height); }
	};
}
