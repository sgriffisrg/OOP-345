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
		resArr = src.resArr;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender&& src) {
		resArr = std::move(src.resArr);
	}

	ConfirmationSender::~ConfirmationSender() {
		delete[] resArr;
		resArr = nullptr;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src) {
		if (this->resArr != src.resArr) {
			delete[] resArr;
			if (src.resArr != nullptr) {
				resArr = new Reservation*[src.count];
				for (int i = 0; i < src.count; i++) {
					resArr[i] = src.resArr[i];
				}
				count = src.count;
			}
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) {
		if (resArr != src.resArr) {
			count = src.count;
			resArr = src.resArr;
			src.resArr = nullptr;
			src.count = 0;
		}
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& newEle) {
		if (resArr == nullptr) {
			resArr = new Reservation*[1];
			resArr[0] = newEle;
			count++;
		}
		for (int i = 0; i < count; i++) {
			if (resArr[i] != &newEle && count == 1) {
				
			}
		}
	}
}
