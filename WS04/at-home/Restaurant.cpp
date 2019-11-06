// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include "Restaurant.h"
namespace sdds {

	Restaurant::Restaurant() {
		resArray = nullptr;
	}

	Restaurant::Restaurant(Reservation* reservations, size_t cnt) {
		count = cnt;
		resArray = new Reservation[cnt];
		for (int i = 0; i < cnt; i++)
			resArray[i] = reservations[i];
	}

	Restaurant::Restaurant(const Restaurant& src) {
		resArray = nullptr;
		*this = src;
	}

	Restaurant& Restaurant::operator=(const Restaurant& src) {
		if (resArray != src.resArray) {
			delete[] resArray;
			if (src.resArray != nullptr) {
				resArray = new Reservation[src.count];
				for (int i = 0; i < src.count; i++)
					resArray[i] = src.resArray[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(const Restaurant&& src) {
		*this = std::move(src);
	}

	Restaurant& Restaurant::operator=(Restaurant&& src) {
		if (resArray != src.resArray) {
			delete[] resArray;
			resArray = src.resArray;
			count = src.count;
			src.resArray = nullptr;
			src.count = 0;
		}
		return *this;
	}

	size_t Restaurant::size() const {
		return count;	
	}

	Restaurant::~Restaurant() {
		delete[] resArray;
		resArray = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& src) {
		if (src.count == 0)
			os << "The object is empty!" << std::endl;
		else {
			os << "--------------------------\nFancy Restaurant\n--------------------------" << std::endl;
			for (int i = 0; i < src.count; i++) {

				os << src.resArray[i];
			}
		}

		return os;
	}
}
