// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: Stephen Griffis	
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion: November 12, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		vector<double> myPrice;
		vector<string> myDescription;
		
		for (size_t i = 0; i < price.size(); i++) {
			Price myPrc = price[i];
			for (size_t j = 0; j < desc.size(); j++) {
				Description myDesc = desc[j];
				if (myPrc.code == myDesc.code) {
					myPrice.push_back(move(myPrc.price));
					myDescription.push_back(move(myDesc.desc));
				}

			}
		}
		for()
		return priceList;
	}
}