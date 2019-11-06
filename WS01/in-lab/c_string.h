#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_C_STRING_H
#define SDDS_C_STRING_H

namespace sdds {
	extern unsigned int g_maxSize;
	class String {
		char str[3];
	public:
		String(const char*);
		void display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const String&);
}

#endif 
