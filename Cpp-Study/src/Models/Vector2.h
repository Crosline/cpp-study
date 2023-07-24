#pragma once

namespace CppStudy {
	struct Vector2 {
		float x { 0 };
		float y { 0 };

		Vector2();

		Vector2(float x, float y);

		Vector2(const Vector2& other);

		~Vector2();

		Vector2 operator+(const Vector2& other);
		Vector2 Add(const Vector2& other);

		Vector2 operator*(const Vector2& other);

		Vector2 Multiply(const Vector2& other);

		Vector2 operator*(const float& number);

		bool operator==(const Vector2& other);

		bool operator!=(const Vector2& other);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vec2);

		friend std::ostream& operator<<(std::ostream& stream, const Vector2* vec2);

		const static Vector2 up;
		const static Vector2 down;
		const static Vector2 forward;
		const static Vector2 back;
	};
}