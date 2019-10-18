#include <iostream>
#include <string>

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

namespace sdds {

	template <typename T>
	class Collection {
		std::string collectName;
		T* collectArr;
		size_t cSize;
		void(*observer)(const Collection<T>&, const T&) = fn;
	public:

		Collection(std::string name) {
			collectName = name;
			collectArr = nullptr;
			cSize = 0u;
		}

		~Collection() { delete[] collectArr; collectArr = nullptr; }

		const std::string& name() const{ return collectName; }

		size_t size() const { return cSize; }

		void setObserver(void(*observer)(const Collection<T>&, const T&) observe) {
			observer = observe;
		}

		Collection<T>& operator+=(const T& item) {
			//bool flag = false;
			for (size_t i = 0; i < cSize; i++) {
				if (collectArr[i].title() == item.title()) {
					return *this;
				}
			}
			


			if (observer != fn)
				observer(*this, item);

		}
		
		friend std::ostream& operator<<(std::ostream& os, const Collection& src) {
			for (size_t i = 0; i < cSize; i++) {
				os << src.collectArr[i];
			}
			return os;
		}
	};

}

#endif // !1
