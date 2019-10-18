#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include "Book.h"

namespace sdds {

	Book::Book() {
		ttl = "";
		cntry = "";
		author = "";
		yr = 0;
		prc = 0.0;
		desc = "";
	}

	Book::Book(const std::string& strBook) {
		std::string dummy = strBook;
		dummy = trim(dummy);
		
		author = dummy.substr(0, dummy.find(","));
		dummy.erase(0, dummy.find(",") + 1);

		ttl = dummy.substr(0, dummy.find(","));
		dummy.erase(0, dummy.find(",") + 1);

		cntry = dummy.substr(0, dummy.find(","));
		dummy.erase(0, dummy.find(",") + 1);

		prc = std::stod(dummy.substr(0, dummy.find(",")));
		dummy.erase(0, dummy.find(",") + 1);

		yr = std::stoi(dummy.substr(0, dummy.find(",")));
		dummy.erase(0, dummy.find(",") + 1);

		desc = dummy.substr(0);
	}

	const std::string& Book::title() const { return ttl; }
	const std::string& Book::country() const { return cntry; }
	const size_t& Book::year() const { return yr; }
	double& Book::price() { return prc; }

	std::string Book::trim(std::string str) {

		for (size_t i = 0; i < str.length(); i++) {

			if (str[i] == ' ') {
				if (str[i + 1] == ' ' || str[i + 1] == ',' || str[i - 1] == ',') {
					str.erase(i, 1);
					i--;
				}
			}
		}
		//std::cout << str;
		return str;
	}

	std::ostream& operator<<(std::ostream& os, const Book& src) {
		os << std::setw(20) << src.author << "|"; os << std::setw(22) << src.ttl << "|"; os << std::setw(5) << src.cntry << "|";
		os << std::setw(4) << src.yr << "|"; os << std::setw(6) << std::fixed << std::setprecision(2) << src.prc << "|"; os << src.desc << std::endl;
		return os;
	}

}