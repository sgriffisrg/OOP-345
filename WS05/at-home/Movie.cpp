#include <iostream>
#include <string>
#include <iomanip>
#include "Movie.h"

namespace sdds {

	Movie::Movie() {
		ttle = "";
		y = 0;
		desc = "";
	}

	Movie::Movie(const std::string& strMovie) {
		std::string dummy = strMovie;
		dummy = trim(dummy);

		ttle = dummy.substr(0, dummy.find(","));
		dummy.erase(0, dummy.find(",") + 1);

		y = std::stoi(dummy.substr(0, dummy.find(",")));
		dummy.erase(0, dummy.find(",") + 1);

		desc = dummy.substr(0);
	}

	std::string Movie::trim(std::string str) {
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

	std::ostream& operator<<(std::ostream& os, const Movie& src) {
		os << std::setw(40) << src.ttle << "|" << std::setw(4) << src.y << "|" << src.desc << std::endl;
	}

}