#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_LIST_H
#define SDDS_LIST_H

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
				T cpy = tt;
				strA[counter] = cpy;
				counter++;
			}
		}
	};

	template<typename L, class V>
	class LVList : List<T, N> {
		L lab;
		V val;
		/*V sum(const L& l, const V& v) {

		}*/
	public:
		V accumulate(const L& label) const {
			V accum;
		}
	};

}

#endif