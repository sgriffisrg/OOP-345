#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H

namespace sdds {

	class SpellChecker {
		std::string m_badWords[5];
		std::string m_goodWords[5];
	public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}

#endif // !1
