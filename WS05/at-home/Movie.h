#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

namespace sdds {

	class Movie {
		std::string ttle;
		size_t y;
		std::string desc;
	public:
		Movie();
		std::string trim(std::string);
		Movie(const std::string&);
		const std::string& title() const { return ttle; }
		friend std::ostream& operator<<(std::ostream&, const Movie&);
		template <typename T>
		void fixSpelling(T spellChecker) { 
			spellChecker(ttle); 
			spellChecker(desc); 
		}
	};
}
#endif
