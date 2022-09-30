#include <iostream>

void Log(const char* message) {
	std::cout << message;
}
void LogLn(const char* message) {
	Log(message);
	std::cout << std::endl;
}