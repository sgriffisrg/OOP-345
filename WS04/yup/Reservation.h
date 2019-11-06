// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

namespace sdds {

	class Reservation {
		std::string resId;
		std::string resName;
		std::string email;
		size_t numOfPeople;
		size_t currentDay;
		size_t currentHr;
	public:
		Reservation();
		Reservation(const std::string& m_res);
		friend std::ostream& operator<<(std::ostream&, const Reservation&);
	};
	
	
}

#endif