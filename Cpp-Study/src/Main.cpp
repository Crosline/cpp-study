#include "Log.h"
#include <iostream>

struct Vector2 {
	float x, y;

	Vector2()
		: x(0.0f), y(0.0f) { }

	Vector2(float x, float y) 
		: x(x), y(y) { }

	Vector2(const Vector2& other)
		: x(other.x), y(other.y) { }

	Vector2 operator+(const Vector2& other) {
		return Add(other);
	}
	Vector2 Add(const Vector2& other) {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator*(const Vector2& other) {
		return Add(other);
	}

	Vector2 Multiply(const Vector2& other) {
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator*(const float& number) {
		return Vector2(x * number, y * number);
	}

	bool operator==(const Vector2& other) {
		const double eps = 0.00001;
		return fabs(x - other.x) < eps && fabs(y - other.y) < eps;
	}

	bool operator!=(const Vector2& other) {
		return !(operator==(other));
	}
};


inline int Multiply(int a, int b) {
	return a * b;
}

int main() {

	LogLn("Hello World");

	int a = Multiply(3, 5);

	return 0;
}