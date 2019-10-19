#include <iostream>
#include <string>
#include <stdexcept>

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

namespace sdds {

	template <class T>
	class Collection {
		std::string collectName;
		T* collectArr;
		size_t cSize;
		void(*observer)(const Collection<T>&, const T&) = nullptr;
	public:

		Collection(std::string name) {
			collectName = name;
			collectArr = nullptr;
			cSize = 0u;
		}

		~Collection() { delete[] collectArr; collectArr = nullptr; }

		const std::string& name() const{ return collectName; }

		size_t size() const { return cSize; }

		void setObserver(void(*observe)(const Collection<T>&, const T&)) { observer = observe; }

		Collection<T>& operator+=(const T& item) {
			for (size_t i = 0; i < cSize; i++) {
				if (collectArr[i].title() == item.title()) {
					return *this;
				}
			}
			
			if (collectArr == nullptr) {
				cSize++;
				collectArr = new T[1]{ item };
			}
			else {
				T* dummy = new T[cSize];
				for (size_t i = 0; i < cSize; i++)
					dummy[i] = collectArr[i];
				delete[] collectArr;
				cSize++;
				collectArr = new T[cSize];
				for (size_t i = 0; i < cSize-1; i++)
					collectArr[i] = dummy[i];
				collectArr[cSize - 1] = item;
			}
			if(observer != nullptr)
				observer(*this, item);
			return *this;
		}

		T& operator[](size_t idx) const { 
			if (idx >= cSize) {
				throw std::out_of_range("Bad index " + std::to_string(idx) + ". Collection has " + std::to_string(cSize) + " items.");
			}
			return collectArr[idx];
		}

		T* operator[](std::string title) const {
			for (size_t i = 0; i < cSize; i++) {
				if (collectArr[i].title() == title) {
					return &collectArr[i];
				}
			}
			return nullptr;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Collection& src) {
			for (size_t i = 0; i < src.cSize; i++) {
				os << src.collectArr[i];
			}
			return os;
		}
	};
}

#endif // !1
