#include "Log.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Models/Vector2.h"
#include "Models/String.h"
#include <GLFW/glfw3.h>

// extern "C" int glfwInit();
template<typename T, int N>
struct Array {
	T contents[N];

	int Size() {
		return N;
	}
};


inline int Multiply(int a, int b) {
	return a * b;
}

int main() {

	std::string hw = std::string("hello world");

	String smallString = "test";

	std::vector <std::string> strings;

	strings.emplace_back("Apple");
	strings.emplace_back("Banana");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	Array<int, 5> myLittelArray;

	for (int i = 0; i < myLittelArray.Size(); i++)
	{
		myLittelArray.contents[i] = i * i;
	}

	for (auto content : myLittelArray.contents)
	{
		std::cout << content << "\t";
	}
	std::cout << std::endl;

	int a = Multiply(3, 5);

	{

		std::unique_ptr<Vector2> test;

		{

			test = std::make_unique<Vector2>(1, 2);

			std::cout << test.get() << std::endl;
		}

		std::cout << test.get() << std::endl;
	}

	long xoffset = (long)&((Vector2*)nullptr)->x;
	long yoffset = (long)&((Vector2*)nullptr)->y;

	std::cout << xoffset << " : " << yoffset << std::endl;

	std::cout <<  smallString.contains("es") << std::endl;
	std::cout <<  smallString.contains(String("test")) << std::endl;
	std::cout << smallString << std::endl;

	std::cin.get();

	int gInit = glfwInit();

	return 0;
}