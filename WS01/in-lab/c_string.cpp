#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "c_string.h"
#include "process.h"

namespace sdds {
	unsigned int g_maxSize = 3;	
	String::String(const char* st) {
	
		str[3] = '\0';		
	
		if (st == nullptr) {
			str[0] = '\0';
		}
		else {
			std::strncpy(str, st, g_maxSize);
		}
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
