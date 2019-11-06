// Name: Stephen Griffis
// Student ID: 119051183
// Seneca Email: sgriffis@myseneca.ca
// Date of completion: Sept 13, 2019
//
// I confirm that the content of this file is created by me,
//    with the exception of the parts provided to me by my professor


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "c_string.h"
#include "process.h"

namespace sdds {
	unsigned int g_maxSize = 3;

	String::String() {
		str = nullptr;
	}
	
	String::String(const char* st) {
		
		if (st == nullptr) {
			str = nullptr;
		}
		else {
			int size;

			if (g_maxSize > std::strlen(st))
				size = std::strlen(st);
			else
				size = g_maxSize;

			str = new char[size + 1];
			std::strncpy(str, st, size);
			str[size + 1] = '\0';
		}
	}
	String::~String() {
		delete [] str;
		str = nullptr;
	}

	String::String(const String& s) {
		str = nullptr;
		*this = s;
	}

	String& String::operator=(const String& src) {
		if (this != &src) {
			delete[] this->str;

			if (src.str != nullptr) {
				int size;

				if (g_maxSize > std::strlen(src.str))
					size = std::strlen(src.str);
				else
					size = g_maxSize;
				this->str = new char[size + 1];
				std::strncpy(this->str, src.str, size);
				this->str[size+1] = '\0';
			}
		}
		return *this;
	}

	void String::display(std::ostream& os) const {
		os << str;
	}

	std::ostream& operator<<(std::ostream& os, const String& s) {
		static unsigned int counter = 0;
		counter++;
		os << counter << ": ";
		s.display(os);
		return os;
	}
	
}
