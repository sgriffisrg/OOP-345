#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		if (!file)
			throw "Bad File Name!";
		else {
			std::string str;
			int i = 0;
			do {
				if (file) {
					std::getline(file, str);
					if (str.length() != 0) {
						m_badWords[i] = str.substr(0, str.find(' '));
						str.erase(0, str.find(' '));

						for (size_t i = 0; i < str.size(); i++)
							while (str[i] == ' ')
								str.erase(i, 1);

						m_goodWords[i] = str;
						i++;
					}
				}
			} while (file);
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		std::string::size_type n;
		for (size_t i = 0; i < 5; i++) {
			for (size_t j = 0; j < text.length(); j++) {
				n = text.find(m_badWords[i], j);
				if (n != std::string::npos) {
					text.replace(n, m_badWords[i].length(), m_goodWords[i]);
				}
			}
		}
	}
}