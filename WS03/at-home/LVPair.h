// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:	Oct 1, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H
#include <iostream>
#include <string>

namespace sdds {

	template<typename L, typename V>
	class LVPair {
		L label;
		V val;

	public:

		LVPair(){}

		LVPair(const L& aa, const V& bb) {
			label = aa;
			val = bb;
		}

		const L& key() const {
			return label;
		}

		const V& value() const {
			return val;
		}

		virtual void display(std::ostream& os) const {
			os << label << " : " << val << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static size_t minWid;
		static V iniSum;
	public:
		static const V& getInitialValue() {
			return iniSum;
		}
		SummableLVPair() : LVPair<L, V>() {}

		SummableLVPair(const L& lbl, const V& val) : LVPair<L, V>(lbl, val) {
			if (lbl.size() > minWid) {
				minWid = lbl.size()+1;
			}
		}

		V sum(const L& lbl, const V& val) const {
			if (LVPair<L, V>::key() == lbl) {
				return LVPair<L, V>::value() + val;
			}
			else {
				return val;
			}
			
		}

		void display(std::ostream& os) const {
			os.std::ios::setf(std::ios::left); os.width(minWid);
			LVPair<L, V>::display(os);
			os.std::ios::unsetf(std::ios::left);
		}
	};
	template <typename L, typename V>
	size_t sdds::SummableLVPair<L, V>::minWid = 0;
	template <typename L, typename V>
	V sdds::SummableLVPair<L, V>::iniSum = 0;
	template <>
	std::string SummableLVPair<std::string, std::string>:: iniSum = "";
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& valu) const {
		if (this->key() == lbl) {
			return valu + this->value() + ", ";
		}
		else {
			return valu;
		}
	}
}

#endif
