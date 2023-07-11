#pragma once
#include <string>

class String {
private:
	char* m_Buffer;
	size_t m_Size;
	
	bool isCopy;
public:
	String(const char* string);

	String(const std::string string) = delete;

	String(const String& other);

	~String();

	bool contains(const String& other);

	bool contains(const char* buffer);

	char& operator[](unsigned int index);

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};