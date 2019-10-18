#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"

namespace sdds {

	SpellChecker::SpellChecker(const char* filename) {
		std::ifstream file(filename);
		std::string str;
		int i = 0;
		if (!file)
			throw "Bad File Name!";
		else {
			do {
				std::getline(file, str);
				m_badWords[i] = str.substr(0, str.find(' '));
				str.erase(0, str.find(' '));
				
				for (size_t i = 0; i < str.size(); i++)
					while (str[i] == ' ')
						str.erase(i, 1);

				m_goodWords[i] = str;
				i++;
			} while (file);
		}
	}

	void SpellChecker::operator()(std::string& text) const {
		std::string dumb;
		std::string dumber;
		for (int i = 0; i < 5; i++) {
			dumb = m_badWords[i];
			int size = dumb.length();
			for (int j = 0; j < text.length(); j++) {
				if (text[j] == dumb[1]) 
					dumber = text.substr(j, size - 1);
					if (dumber == dumb)
						text.replace(j, size - 1, m_goodWords[i]);
				}
			}
		}

	}

}