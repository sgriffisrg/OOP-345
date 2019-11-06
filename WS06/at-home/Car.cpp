// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 5, 2019
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
		std::getline(in, dummy, ',');
		dummy = trim(dummy);

		c_maker = dummy.substr(0, ',');
		dummy.erase(0, dummy.find(',') + 1);

		std::getline(in, dummy, ',');
		dummy = trim(dummy);
		if (dummy.size() > 0) {
			if (dummy[0] == 'n' || dummy[0] == 'N' || dummy[0] == ' ')
				c_condition = "New";
			else if (dummy[0] == 'u' || dummy[0] == 'U')
				c_condition = "Used";
			else if (dummy[0] == 'b' || dummy[0] == 'B')
				c_condition = "Broken";
			else {
				throw "Invalid Record!";
			}
		}
		else {
			c_condition = "New";
		}
		dummy.erase(0, dummy.find(',') + 1);
		

		try {
			std::getline(in, dummy, ',');
			top_speed = stod(dummy);
		}
		catch (...) {
			top_speed = 0;
			throw "Invalid Record!";
		}
	}

	std::string Car::trim(const std::string str) {
		std::string dummy = str;
		while (dummy.size() > 0 && dummy[0] == ' ')
			dummy.erase(0, 1);
		while(dummy.size() > 0 && dummy[dummy.length()-1] == ' ')
			dummy.erase(dummy.length() - 1, 1);
		return dummy;
	}

	std::string Car::condition() const {
		return c_condition;
	}

	void Car::display(std::ostream& out) const {
		out << "| " << std::setw(10) << c_maker << " | " << std::setw(6) << condition() <<
			" | " << std::setprecision(2) << std::fixed << topSpeed() << " |";
	}
}