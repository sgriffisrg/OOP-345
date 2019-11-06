// Name: Stephen Griffis	
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

namespace sdds {

	class Text {
		std::string* s;
		int n;
	public:
		Text();
		Text( const std::string&);
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();
		size_t size() const;
	};

}

#endif