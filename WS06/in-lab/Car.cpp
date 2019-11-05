// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include "Car.h"

namespace sdds {

	Car::Car(std::istream& in) {
		std::string dummy;
		std::getline(in, dummy);
		dummy = trim(dummy);

		c_maker = dummy.substr(0, dummy.find(','));
		dummy.erase(0, dummy.find(',') + 1);

		c_condition = dummy[0];
		dummy.erase(0, dummy.find(',') + 1);
		

		try {
			std::getline(in, dummy, ',');
			top_speed = stod(dummy);
		}
		catch (...) {
			top_speed = 0;
		}

	}

	std::string Car::trim(const std::string str) {
		std::string dummy = str;
		for (size_t i = 0; i < dummy.size(); i++)
			while (dummy[i] == ' ')
				dummy.erase(i, 1);
		return dummy;
	}

	std::string Car::condition() const {

		if (c_condition == 'n' || c_condition == 'N')
			return "New";
		else if (c_condition == 'u' || c_condition == 'U')
			return "Used";
		else if (c_condition == 'b' || c_condition == 'B')
			return "Broken";
		else
			return "how";
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << c_maker << " | " << std::setw(6) << condition() <<
			" | " << std::setw(6) << std::setprecision(2) << std::fixed << top_speed << " | ";
	}
}