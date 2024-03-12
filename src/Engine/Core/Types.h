#pragma once
#include <glm/glm.hpp>
#include <memory>

namespace Engine {
	typedef glm::vec1   Vec1f;
	typedef glm::vec2   Vec2f;
	typedef glm::vec3   Vec3f;
	typedef glm::vec4   Vec4f;

	typedef glm::mat2   Mat2f;
	typedef glm::mat3   Mat3f;
	typedef glm::mat4   Mat4f;

	typedef uint8_t     u8t;
	typedef uint16_t    ui16;
	typedef uint32_t    ui32;
	typedef uint64_t    ui64;

	typedef int16_t     i16;
	typedef int32_t     i32;
	typedef int64_t     i64;

	typedef char16_t    c16;
	typedef char32_t    c32;

    template <typename T>
    using Ref = std::shared_ptr<T>;

    template <typename T>
    using Scope = std::unique_ptr<T>;
}
