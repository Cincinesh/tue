//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "../mat.hpp"
#include "../math.hpp"
#include "../vec.hpp"

#ifdef _MSC_VER
#define TUE_CONSTEXPR
#else
#define TUE_CONSTEXPR constexpr
#endif

namespace tue
{
	// -------------
	// vec2 * mat2x2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec2<T>& lhs,
		const mat2x2<U>& rhs)
	{
		return vec2<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
		};
	}

	// -------------
	// vec2 * mat3x2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec2<T>& lhs,
		const mat3x2<U>& rhs)
	{
		return vec3<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
		};
	}

	// -------------
	// vec2 * mat4x2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec2<T>& lhs,
		const mat4x2<U>& rhs)
	{
		return vec4<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
			math::dot(lhs, rhs.column(3)),
		};
	}

	// -------------
	// vec3 * mat2x3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec3<T>& lhs,
		const mat2x3<U>& rhs)
	{
		return vec2<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
		};
	}

	// -------------
	// vec3 * mat3x3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec3<T>& lhs,
		const mat3x3<U>& rhs)
	{
		return vec3<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
		};
	}

	// -------------
	// vec3 * mat4x3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec3<T>& lhs,
		const mat4x3<U>& rhs)
	{
		return vec4<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
			math::dot(lhs, rhs.column(3)),
		};
	}

	// -------------
	// vec4 * mat2x4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec4<T>& lhs,
		const mat2x4<U>& rhs)
	{
		return vec2<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
		};
	}

	// -------------
	// vec4 * mat3x4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec4<T>& lhs,
		const mat3x4<U>& rhs)
	{
		return vec3<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
		};
	}

	// -------------
	// vec4 * mat4x4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const vec4<T>& lhs,
		const mat4x4<U>& rhs)
	{
		return vec4<decltype(lhs[0] * rhs[0][0])>{
			math::dot(lhs, rhs.column(0)),
			math::dot(lhs, rhs.column(1)),
			math::dot(lhs, rhs.column(2)),
			math::dot(lhs, rhs.column(3)),
		};
	}

	// -------------
	// mat2x2 * vec2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x2<T>& lhs,
		const vec2<U>& rhs)
	{
		return vec2<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
		};
	}

	// ---------------
	// mat2x2 * mat2x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x2<T>& lhs,
		const mat2x2<U>& rhs)
	{
		return mat2x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat2x2 * mat3x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x2<T>& lhs,
		const mat3x2<U>& rhs)
	{
		return mat3x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat2x2 * mat4x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x2<T>& lhs,
		const mat4x2<U>& rhs)
	{
		return mat4x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
			}
		};
	}
	
	// -------------
	// mat2x3 * vec2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x3<T>& lhs,
		const vec2<U>& rhs)
	{
		return vec3<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
		};
	}

	// ---------------
	// mat2x3 * mat2x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x3<T>& lhs,
		const mat2x2<U>& rhs)
	{
		return mat2x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat2x3 * mat3x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x3<T>& lhs,
		const mat3x2<U>& rhs)
	{
		return mat3x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat2x3 * mat4x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x3<T>& lhs,
		const mat4x2<U>& rhs)
	{
		return mat4x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat2x4 * vec2
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x4<T>& lhs,
		const vec2<U>& rhs)
	{
		return vec4<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
			math::dot(lhs.row(3), rhs),
		};
	}

	// ---------------
	// mat2x4 * mat2x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x4<T>& lhs,
		const mat2x2<U>& rhs)
	{
		return mat2x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat2x4 * mat3x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x4<T>& lhs,
		const mat3x2<U>& rhs)
	{
		return mat3x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat2x4 * mat4x2
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat2x4<T>& lhs,
		const mat4x2<U>& rhs)
	{
		return mat4x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
				math::dot(lhs.row(3), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat3x2 * vec3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x2<T>& lhs,
		const vec3<U>& rhs)
	{
		return vec2<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
		};
	}

	// ---------------
	// mat3x2 * mat2x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x2<T>& lhs,
		const mat2x3<U>& rhs)
	{
		return mat2x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat3x2 * mat3x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x2<T>& lhs,
		const mat3x3<U>& rhs)
	{
		return mat3x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat3x2 * mat4x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x2<T>& lhs,
		const mat4x3<U>& rhs)
	{
		return mat4x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat3x3 * vec3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x3<T>& lhs,
		const vec3<U>& rhs)
	{
		return vec3<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
		};
	}

	// ---------------
	// mat3x3 * mat2x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x3<T>& lhs,
		const mat2x3<U>& rhs)
	{
		return mat2x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat3x3 * mat3x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x3<T>& lhs,
		const mat3x3<U>& rhs)
	{
		return mat3x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat3x3 * mat4x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x3<T>& lhs,
		const mat4x3<U>& rhs)
	{
		return mat4x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat3x4 * vec3
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x4<T>& lhs,
		const vec3<U>& rhs)
	{
		return vec4<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
			math::dot(lhs.row(3), rhs),
		};
	}

	// ---------------
	// mat3x4 * mat2x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x4<T>& lhs,
		const mat2x3<U>& rhs)
	{
		return mat2x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat3x4 * mat3x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x4<T>& lhs,
		const mat3x3<U>& rhs)
	{
		return mat3x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat3x4 * mat4x3
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat3x4<T>& lhs,
		const mat4x3<U>& rhs)
	{
		return mat4x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
				math::dot(lhs.row(3), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat4x2 * vec4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x2<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec2<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
		};
	}

	// ---------------
	// mat4x2 * mat2x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x2<T>& lhs,
		const mat2x4<U>& rhs)
	{
		return mat2x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat4x2 * mat3x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x2<T>& lhs,
		const mat3x4<U>& rhs)
	{
		return mat3x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat4x2 * mat4x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x2<T>& lhs,
		const mat4x4<U>& rhs)
	{
		return mat4x2<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat4x3 * vec4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x3<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec3<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
		};
	}

	// ---------------
	// mat4x3 * mat2x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x3<T>& lhs,
		const mat2x4<U>& rhs)
	{
		return mat2x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat4x3 * mat3x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x3<T>& lhs,
		const mat3x4<U>& rhs)
	{
		return mat3x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat4x3 * mat4x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x3<T>& lhs,
		const mat4x4<U>& rhs)
	{
		return mat4x3<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
			}
		};
	}

	// -------------
	// mat4x4 * vec4
	// -------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x4<T>& lhs,
		const vec4<U>& rhs)
	{
		return vec4<decltype(lhs[0][0] * rhs[0])>{
			math::dot(lhs.row(0), rhs),
			math::dot(lhs.row(1), rhs),
			math::dot(lhs.row(2), rhs),
			math::dot(lhs.row(3), rhs),
		};
	}

	// ---------------
	// mat4x4 * mat2x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x4<T>& lhs,
		const mat2x4<U>& rhs)
	{
		return mat2x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}
		};
	}

	// ---------------
	// mat4x4 * mat3x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x4<T>& lhs,
		const mat3x4<U>& rhs)
	{
		return mat3x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}
		};
	}

	// ---------------
	// mat4x4 * mat4x4
	// ---------------
	template<typename T, typename U>
	inline TUE_CONSTEXPR auto operator*(
		const mat4x4<T>& lhs,
		const mat4x4<U>& rhs)
	{
		return mat4x4<decltype(lhs[0][0] * rhs[0][0])>{
			{
				math::dot(lhs.row(0), rhs.column(0)),
				math::dot(lhs.row(1), rhs.column(0)),
				math::dot(lhs.row(2), rhs.column(0)),
				math::dot(lhs.row(3), rhs.column(0)),
			} , {
				math::dot(lhs.row(0), rhs.column(1)),
				math::dot(lhs.row(1), rhs.column(1)),
				math::dot(lhs.row(2), rhs.column(1)),
				math::dot(lhs.row(3), rhs.column(1)),
			}, {
				math::dot(lhs.row(0), rhs.column(2)),
				math::dot(lhs.row(1), rhs.column(2)),
				math::dot(lhs.row(2), rhs.column(2)),
				math::dot(lhs.row(3), rhs.column(2)),
			}, {
				math::dot(lhs.row(0), rhs.column(3)),
				math::dot(lhs.row(1), rhs.column(3)),
				math::dot(lhs.row(2), rhs.column(3)),
				math::dot(lhs.row(3), rhs.column(3)),
			}
		};
	}
}

#undef TUE_CONSTEXPR
