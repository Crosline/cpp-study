#include "String.h"
#include <iostream>

namespace CppStudy {
	String::String(const char* string) {
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);

		m_Buffer[m_Size] = 0;
		isCopy = false;
	}

	String::String(const String& other)
		: m_Size(other.m_Size) {
		m_Buffer = new char[m_Size + 1]; // allocate a new buffer
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1); // copy the content of the buffer 

		isCopy = true;
	}

	String::~String() {
		delete[] m_Buffer;
	}


	bool String::contains(const String& other) {
		return strstr(m_Buffer, other.m_Buffer);
	}

	bool String::contains(const char* buffer) {
		return strstr(m_Buffer, buffer);
	}

	char& String::operator[](unsigned int index) {
		return m_Buffer[index];
	}

	std::ostream& operator<<(std::ostream& stream, const String& string) {
		stream << string.m_Buffer;
		return stream;
	}
}