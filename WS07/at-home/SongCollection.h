// Name: Stephen Griffis	
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <list>
#include <numeric>

namespace sdds {
	struct Song {
		std::string artist;
		std::string title;
		std::string album;
		double price;
		std::string yrRelease;
		int songLength;
	};

	class SongCollection {
		std::vector<Song> songCollect;
		std::string str[6];
		static int count;
	public:
		SongCollection(const char*);
		std::string trim(std::string);
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
		void strLineChop(std::string);
		void songInitialize();
		void display(std::ostream&) const;
	};
	std::ostream& operator<<(std::ostream&, const Song&);
	
}

#endif // !SDDS_SONGCOLLECTION_H
