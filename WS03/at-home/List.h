#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Name: Stephen Griffis
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:	Oct 1, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>

namespace sdds {

	template <class T, unsigned int N>
	class List {
		T strA[N];
		int counter = 0;
	public:
		size_t size() const {
			return counter;
		}

		const T& operator[](size_t i) {
			return strA[i];
		}

		void operator+=(const T& tt) {
			if(counter != N){	
				strA[counter] = tt;
				counter++;
			}
		}
	};

	template<typename L, typename V, typename T, unsigned int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			V accum;
			T LVvar;
			accum = LVvar.getInitialValue();
			for(unsigned int i = 0; i < ((List<T, N>&) * this).size(); i++){
				if (((List<T, N>&)*this)[i].key() == label){
					accum = ((List<T, N>&)*this)[i].sum(label, accum);
				}
			}
			return accum;
		}
	};

}

#endif
