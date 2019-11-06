// Name: Stephen Griffis
// Student_ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: Sept 13, 2019
//
// I confirm that the content of this file is created by me, 
// 	with the exception of the parts provided to me by my professor

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_C_STRING_H
#define SDDS_C_STRING_H

namespace sdds {
	extern unsigned int g_maxSize;
	class String {
		char* str;
	public:
		String();
		String(const char*);
		String(const String&);
		String& operator=(const String&);
		~String();
		void display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const String&);
}

#endif 
