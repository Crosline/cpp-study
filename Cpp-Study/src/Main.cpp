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
};


inline int Multiply(int a, int b) {
	return a * b;
}

int main() {

	LogLn("Hello World");

	int a = Multiply(3, 5);

	return 0;
}