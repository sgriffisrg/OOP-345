#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

namespace sdds {

	class Book {
		std::string author;
		std::string ttl;
		std::string cntry;
		std::string desc;
		size_t yr;
		double prc;
	public:
		Book();
		Book(const std::string&);
		std::string trim(std::string);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream&, const Book&);
		template <typename T>
		void fixSpelling(T spellChecker) { spellChecker(desc); }
	};
}
#endif