//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// ---------
	// size2d<T>
	// ---------
	template<typename T>
	class size2d;

	using fsize2d = size2d<float>;
	using dsize2d = size2d<double>;
	using isize2d = size2d<int>;
	using usize2d = size2d<unsigned int>;

	template<typename T>
	class size2d
	{
	private:
		T width_;
		T height_;

	public:
		// -------------------
		// default constructor
		// -------------------
		size2d() noexcept = default;

		// ---------------------
		// component constructor
		// ---------------------
		explicit constexpr size2d(
			const T& width,
			const T& height) noexcept :
			width_(width),
			height_(height) {}

		// -------------------------------
		// explicit conversion constructor
		// -------------------------------
		template<typename U>
		explicit constexpr size2d(
			const size2d<U>& other) noexcept :
			width_(other.width()),
			height_(other.height()) {}

		// ----------------------------
		// implicit conversion operator
		// ----------------------------
		template<typename U>
		constexpr operator size2d<U>() const noexcept
		{
			return size2d<U>(width_, height_);
		}

		// -----
		// width
		// -----
		constexpr T width() const noexcept { return width_; }
		void set_width(const T& width) noexcept { width_ = width; }

		// ------
		// height
		// ------
		constexpr T height() const noexcept { return height_; }
		void set_height(const T& height) noexcept { height_ = height; }
	};

	// ----------
	// lhs == rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator==(
		const size2d<T>& lhs,
		const size2d<U>& rhs) noexcept
	{
		return lhs.width() == rhs.width()
			&& lhs.height() == rhs.height();
	}

	// ----------
	// lhs != rhs
	// ----------
	template<typename T, typename U>
	inline TUE_CONSTEXPR bool operator!=(
		const size2d<T>& lhs,
		const size2d<U>& rhs) noexcept
	{
		return !(lhs == rhs);
	}
}

#undef TUE_CONSTEXPR
