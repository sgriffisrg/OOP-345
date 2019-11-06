// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"

namespace sdds {

	class Racecar : public Car {
		double m_booster;
	public:
		Racecar(std::istream&);
		void display(std::ostream&) const;
		double topSpeed() const;
	};

}

#endif // !1