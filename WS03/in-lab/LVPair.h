#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H

namespace sdds {

	template<typename L, typename V>
	class LVPair {
		L label;
		V val;

	public:

		LVPair() {
			label = '\0';
			val = 0;
		}

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

		void display(std::ostream& os) const {
			os << label << " : " << val << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif