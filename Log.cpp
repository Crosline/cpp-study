#include <iostream>

using namespace std;

void Log(const char* message) {
    cout << message;
}

void LogLn(const char* message) {
    Log(message);
    cout << endl;
}