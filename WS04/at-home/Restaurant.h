// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
/* A
	B
		B
		A
		B
		C
		A
		A
		A
		B
		A
*/// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* resArray;
		size_t count = 0;
	public:
		Restaurant();
		Restaurant(Reservation*, size_t);
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);
		Restaurant(const Restaurant&&);
		Restaurant& operator=(Restaurant&&);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};

}

#endif
