// Name: Stephen Griffis	
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: Sept 24, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Text.h"
#include "TimedEvents.h"
#include <fstream>

namespace sdds {

	Text::Text() {
		s = nullptr;
		n = 0;
	}

	Text::Text(const std::string& filename) {
		std::ifstream f(filename.c_str());
		n = 0;
		s = nullptr;
		if (!f)
			return;
		do {
			char c = f.get();
			if (c == ' ')
				n++;
		} while (!f.eof());

		f.seekg(std::ios::beg);
		s = new std::string[n];
		for (int i = 0; i < n; i++)
			std::getline(f, s[i], ' ');
	}

	Text::Text(const Text& src) {
		s = nullptr;
		*this = src;
	}

	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			n = src.n;
			delete[] s;
			if (src.s != nullptr) {
				s = new std::string[src.n];
				for (int i = 0; i < src.n; i++) {
					s[i] = src.s[i];
				}
			}
			else
				s = nullptr;
		}
		return *this;
	}

	Text::Text(const Text&& src) {
		*this = std::move(src);
	}

	Text& Text::operator=(Text&& src) {
		if (this != &src) {
			delete[] s;
			s = src.s;
			n = src.n;
			src.s = nullptr;
			src.n = 0;
		}
		return *this;
	}

		Text::~Text() {
		delete[] s;
		s = nullptr;
	}

	size_t Text::size() const {
		return n;
	}

}
