#include "Log.h"
#include <iostream>

int Multiply(int a, int b) {
	return a * b;
}

int main() {

	LogLn("Hello World");

	int a = Multiply(3, 5);

	return 0;
}