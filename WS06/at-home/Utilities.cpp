// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::string dummy;
		char type;
		char delim;
		std::getline(in, dummy);
		std::stringstream ss(dummy);
		ss >> type >> delim;
		if (ss) {
			if (type == 'c' || type == 'C')
				return new Car(ss);
		}
		return nullptr;
	}

}