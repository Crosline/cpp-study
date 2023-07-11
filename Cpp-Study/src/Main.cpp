#include "Log.h"
#include <iostream>
#include <string>
#include "Models/Vector2.h"
#include "Models/String.h"


inline int Multiply(int a, int b) {
	return a * b;
}

int main() {

	std::string hw = std::string("hello world");

	String smallString = "test";

	int a = Multiply(3, 5);

	{

		std::shared_ptr<Vector2> test;

		{

			test = std::make_shared<Vector2>(1, 2);

			std::cout << test.get() << std::endl;
		}

		long xoffset = (long)&((Vector2*)nullptr)->x;
		long yoffset = (long)&((Vector2*)nullptr)->y;

		std::cout << test.get() << std::endl;
		std::cout << xoffset << " : " << yoffset << std::endl;
	}

	std::cout <<  smallString.contains("es") << std::endl;
	std::cout <<  smallString.contains(String("test")) << std::endl;
	std::cout << smallString << std::endl;

	std::cin.get();

	return 0;
}