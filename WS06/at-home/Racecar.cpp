// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {
		m_booster = 0;
		std::string dummy;
		std::getline(in, dummy, ',');
		m_booster = stod(dummy);
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		out <<  "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}
}