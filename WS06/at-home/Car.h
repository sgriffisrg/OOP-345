// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"

namespace sdds {

	class Car : public sdds::Vehicle {
		std::string c_maker;
		std::string c_condition;
		double top_speed;
	public:
		Car(std::istream&);
		std::string condition() const;
		std::string trim(std::string str);
		double topSpeed() const { return top_speed; }
		void display(std::ostream&) const;

	};

}

#endif 