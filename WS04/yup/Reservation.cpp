// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

namespace sdds {

	Reservation::Reservation() {
		resId = "";
		resName = "";
		email = "";
		numOfPeople = 0;
		currentDay = 0;
		currentHr = 0;
	}
	Reservation::Reservation(const std::string& m_res) {
		std::string dummy = m_res;
		for (size_t i = 0; i < dummy.size(); i++)
			while (dummy[i] == ' ') 
				dummy.erase(i, 1);

		resId = dummy.substr(0, dummy.find(":") + 1);
		dummy.erase(0, dummy.find(":") + 1);
		
		for (int i = 0; i < 6; i++) {
			switch (i) {
			case 1:
				resName = dummy.substr(0, dummy.find(","));
				dummy.erase(0, dummy.find(",") + 1);
				break;
			case 2:
				email = "<" + dummy.substr(0, dummy.find(",")) + ">";
				dummy.erase(0, dummy.find(",") + 1);
				break;
			case 3:
				numOfPeople = std::stoi(dummy.substr(0, dummy.find(",")));
				dummy.erase(0, dummy.find(",") + 1);
				break;
			case 4:
				currentDay = std::stoi(dummy.substr(0, dummy.find(",")));
				dummy.erase(0, dummy.find(",") + 1);
				break;
			case 5:
				currentHr = std::stoi(dummy.substr(0));
				break;
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& src) {
		os << "Reservation " << src.resId;
		os << std::setw(10) << src.resName << "  ";
		os.setf(std::ios::left);
		os << std::setw(20) << src.email;
		os.unsetf(std::ios::left);
		if (src.currentHr >= 6 && src.currentHr <= 9) 
			os << "Breakfast on day " << src.currentDay << " @ " << src.currentHr << ":00 for " << src.numOfPeople << " people" << '\n';

		else if(src.currentHr >= 11 && src.currentHr <= 15)
			os << "Lunch on day " << src.currentDay << " @ " << src.currentHr << ":00 for " << src.numOfPeople << " people" << '\n';

		else if(src.currentHr >= 17 && src.currentHr <= 21)
			os << "Dinner on day " << src.currentDay << " @ " << src.currentHr << ":00 for " << src.numOfPeople << " people" << '\n';
		else
			os << "Drinks on day " << src.currentDay << " @ " << src.currentHr << ":00 for " << src.numOfPeople << " people" << '\n';

		return os;

	}

}