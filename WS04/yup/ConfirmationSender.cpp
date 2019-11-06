// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
		resArr = nullptr;
		count = 0;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& src) {
		resArr = nullptr;
		*this = src;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) {
		*this = std::move(src);
	}

	/*ConfirmationSender::~ConfirmationSender() {
		delete[] resArr;
		resArr = nullptr;
	}*/

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this != &src) {
			delete[] resArr;
			count = src.count;
			if (src.resArr != nullptr) {
				resArr = new const Reservation*[src.count];
				for (int i = 0; i < src.count; i++) {
					resArr[i] = src.resArr[i];
				}
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (resArr != src.resArr) {
			
			delete[] resArr;
			resArr = src.resArr;
			count = src.count;
			src.resArr= nullptr;
			src.count = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& newEle) {
		bool flag = false;
		if (resArr == nullptr) {
			resArr = new const Reservation*[1];
			resArr[0] = &newEle;
			count++;
		}
		else {
			const Reservation** dummy = new const Reservation*[count + 1];
			for (int i = 0; i < count; i++) { if (resArr[i] == &newEle) { flag = true; } }
			if (flag == false) {
				for (int i = 0; i < count; i++)
					dummy[i] = resArr[i];
				dummy[count] = &newEle;
				count++;
				delete[] resArr;
				resArr = nullptr;
				resArr = dummy;
				dummy = nullptr;
			}
		}
		return *this;
	}
	
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& delEle) {
		if(resArr != nullptr){
			int tmp = 0;
			int index = -1;
			for (int i = 0; i < count; i++) 
				if (resArr[i] == &delEle) index = i;
			if (index != -1) {
				const Reservation** dummy = new const Reservation*[count - 1];
				for (int i = 0; i < count; i++) {
					if (i != index) {
						dummy[tmp] = resArr[i];
						tmp++;
					}
				}
			}
			else {
				return *this;
			}

		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& src) {
		if (src.resArr == nullptr) {
			os << "--------------------------\nConfirmations to Send\n--------------------------\nThe object is empty!\n--------------------------" << std::endl;
		}
		else {
			os << "--------------------------\nConfirmations to Send\n--------------------------\n";
			for (int i = 0; i < src.count; i++) {
				os << *src.resArr[i];
			}
			os << "--------------------------" << std::endl;
		}
		return os;
	}

}