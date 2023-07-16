#include <iostream>
#include "Vector2.h"

namespace CppStudy {

	Vector2::Vector2()
		: x(0.0f), y(0.0f) { }

	Vector2::Vector2(float x, float y)
		: x(x), y(y) { }

	Vector2::Vector2(const Vector2& other)
		: x(other.x), y(other.y) { }

	Vector2::~Vector2() { }

	Vector2 Vector2::operator+(const Vector2& other) {
		return Add(other);
	}
	Vector2 Vector2::Add(const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Vector2::operator*(const Vector2& other) {
		return Add(other);
	}

	Vector2 Vector2::Multiply(const Vector2& other) {
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 Vector2::operator*(const float& number) {
		return Vector2(x * number, y * number);
	}

	bool Vector2::operator==(const Vector2& other) {
		const double eps = 0.00001;
		return fabs(x - other.x) < eps && fabs(y - other.y) < eps;
	}

	bool Vector2::operator!=(const Vector2& other) {
		return !(operator==(other));
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2& vec2) {
		stream << vec2.x << ", " << vec2.y;
		return stream;
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2* vec2) {
		return operator<<(stream, *vec2);
	}
}