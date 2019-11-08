// Name: Stephen Griffis	
// Seneca Student ID: 119051183
// Seneca email: sgriffis@myseneca.ca
// Date of completion:
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "SongCollection.h"

namespace sdds {
	int SongCollection::count = 0;

	SongCollection::SongCollection(const char* fileName) {
		std::string dummy;
		std::string dumber;
		std::ifstream file(fileName);
		if (!file) {
			std::cerr << "ERROR: Cannot open file [" << fileName << "].\n";
			return;
		}
		while (file) {
			dumber = dummy;
			std::getline(file, dummy);
			if(dummy != dumber)
				strLineChop(dummy);
		}
	}

	void SongCollection::strLineChop(std::string line) {
		std::string dummy;
		int i = 0;

		for (i; i < 3; i++) {
			dummy = trim(line.substr(0, 24));
			line.erase(0, 25);
			str[i] = dummy;
		}
		for (i; i < 6; i++) {
			dummy = trim(line.substr(0, 5));
			line.erase(0, 5);
			str[i] = dummy;
		}
		songInitialize();
	}

	void SongCollection::songInitialize() {
		songCollect.push_back(new Song);
		songCollect[count]->title = str[0];
		songCollect[count]->artist = str[1];
		songCollect[count]->album = str[2];
		if (str[3].size() > 0)
			songCollect[count]->yrRelease = str[3];
		else
			songCollect[count]->yrRelease = "";
		songCollect[count]->songLength = (stod(str[4])/60);
		songCollect[count]->price = stod(str[5]);
		count++;
	}

	std::string SongCollection::trim(std::string str) {
		while (str.size() > 0 && str[0] == ' ')
			str.erase(0, 1);
		while (str.size() > 0 && str[str.size() - 1] == ' ')
			str.erase(str.size() - 1, 1);
		return str;
	}

	void SongCollection::display(std::ostream& os) const {
		std::for_each(songCollect.begin(), songCollect.end(), [&](const Song* theSong) {os << *theSong; });
	}

	std::ostream& operator<<(std::ostream& os, const Song& theSong) {
		os << "| " << std::setw(20) << theSong.title << " | " << std::setw(15) << theSong.artist <<
			" | " << std::setw(20) << theSong.album << " | " << std::setw(6) << theSong.yrRelease << " | ";
		std::string str = std::to_string(theSong.songLength);
		//str.erase(str.find('.'), 1);
		str[str.find('.')] = ':';
		str = str.substr(0, 4);
		os << std::setprecision(2) << std::fixed << str << " | " << std::setprecision(2) << std::fixed << theSong.price << " |\n";
		return os;
	}

}