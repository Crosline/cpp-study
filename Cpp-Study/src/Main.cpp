#include "Log.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <functional>
#include <unordered_map>
#include <thread>
#include <chrono>
#include "Models/Vector2.h"
#include "Models/String.h"
#include <GLFW/glfw3.h>

#ifdef _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

using namespace CppStudy;

// extern "C" int glfwInit();
template<typename T, int N>
struct Array {
	T contents[N];

	int Size() {
		return N;
	}
};

struct Benchmark
{
	std::chrono::time_point<std::chrono::steady_clock> start;

	void Start() {
		start = std::chrono::high_resolution_clock::now();

	}

	float End() {
		std::chrono::duration<float> duration = std::chrono::high_resolution_clock::now() - start;
		float ms = duration.count() * 1000.0f;
		return ms;
	}
};

inline void HelloWorld() {
	Benchmark b;
	b.Start();
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Hello World\n";
	}

	float ms = b.End();
	std::cout << "Benchmark took " << ms << "ms" << std::endl;
}


inline const int Multiply(const int a, const int b) {
	return a * b;
}

static bool s_isWorking = true;
void ThreadTest() {
	while (true)
	{
		std::string p;
		std::cin >> p;

		if (p._Equal("exit"))
		{
			s_isWorking = false;
			break;
		}
	}
}

int main() {

	std::thread worker(ThreadTest);

	std::string hw = std::string("hello world");

	String smallString = "test";

	std::vector <std::string> strings;

	strings.emplace_back("Apple");
	strings.emplace_back("Banana");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
		std::cout << *it << std::endl;
	}

	std::array<int, 5> datarray; // Why we should use std array instead of other arrays?
	datarray[0] = 5;
	datarray[1] = 2;

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

	{
		//typedef const int(*multiplyFunction)(int, int);
		typedef const std::function<int(int, int)> multiplyFunction;

		multiplyFunction mul = Multiply;

		int a = mul(3, 5);
		auto v = [datarray](int value) { std::cout << value << std::endl; };
		v(5);
		v(a);
	}

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
	LOG(smallString);

	worker.join();

	int gInit = glfwInit();

	return 0;
}
