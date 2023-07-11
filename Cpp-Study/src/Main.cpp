#include "Log.h"
#include <iostream>
#include "Models/Vector2.h"


inline int Multiply(int a, int b) {
	return a * b;
}

int main() {

	LogLn("Hello World");

	int a = Multiply(3, 5);

	Vector2 test = Vector2(3, 5) + Vector2(1, 2);

	std::cout << test;

	std::cin.get();

	return 0;
}