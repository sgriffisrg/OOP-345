// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

// Name: Stephen Griffis
// Student ID: 119051183
// Student email: sgriffis@myseneca.ca
// Date of completion: Sept 13, 2019
//
// I confirm that the content of this file is create by me,
// 	with the exception of the parts provided to me by my professor

#include <iostream>
#include "process.h"
#include "c_string.h"
#define _CRT_SECURE_NO_WARNINGS
// TODO: write the prototype for the main function
//         to accept command line arguments

int main(int argc, char* argv[]){
	std::cout << "Command Line:\n";
	// TODO: print the command line here, in the format
	// 1: first argument
	// 2: second argument
	// 3: third argument

	std::cout << std::endl;

    if (argc < 2)
	{
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        return 1;
	}
	else 
		for (int i = 0; i < argc; i++) 
			std::cout << i + 1 << ": " << argv[i] << std::endl;

	std::cout << "------------------\n";
	std::cout << "Global variable:\n";
	std::cout << "------------------\n";
	std::cout << "Old Value: " << sdds::g_maxSize << '\n';
	sdds::g_maxSize = 4;
	std::cout << "New Value: " << sdds::g_maxSize << '\n';
	std::cout << "------------------\n\n";

	std::cout << "------------------\n";
	std::cout << "First processing:\n";
	std::cout << "------------------\n";
	for (int i = 1; i < argc; i++)
		sdds::process(argv[i]);
	std::cout << "------------------\n\n";

	sdds::g_maxSize = 5;

	std::cout << "------------------\n";
	std::cout << "Second processing:\n";
	std::cout << "------------------\n";
	for (int i = 1; i < argc; i++)
		sdds::process(argv[i]);
	std::cout << "------------------\n\n";

	sdds::g_maxSize = 42;
	sdds::String str1(argv[1]);
	str1.display(std::cout);
	std::cout << '\n';
	sdds::String str2 = str1;
	str2.display(std::cout);
	std::cout << '\n';
	sdds::String str3("School of Software Design and Data Science(SDDS)");
	str3.display(std::cout);
	std::cout << '\n';
	str3 = str1;
	std::cout << str1 << '\n' << str2 << '\n' << str3 << '\n';

	return 0;
}
