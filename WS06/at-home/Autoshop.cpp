// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include "Autoshop.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* newVehicle) {
		m_vehicles.push_back(newVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << "| Cars in the autoshop!|" <<
			"--------------------------------\n" ;
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << std::endl;
		}

		out << "--------------------------------\n";
	}

}