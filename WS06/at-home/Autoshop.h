// Name: Stephen
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 5, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle*);
		~Autoshop();
		void display(std::ostream&) const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (size_t i = 0; i < m_vehicles.size(); i++) {
				bool flag = test(m_vehicles[i]);
				if (flag) {
					vehicles.push_back(m_vehicles[i]);
				}
			}
		}
	};

}

#endif // !SDDS_AUTOSHOP_H
