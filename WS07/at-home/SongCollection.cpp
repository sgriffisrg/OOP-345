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
		Song test;
		songCollect.push_back(test);
		songCollect[count].title = str[0];
		songCollect[count].artist = str[1];
		songCollect[count].album = str[2];
		if (str[3].size() > 0)
			songCollect[count].yrRelease = str[3];
		else
			songCollect[count].yrRelease = "";
		songCollect[count].songLength = stoi(str[4]);
		songCollect[count].price = stod(str[5]);
		count++;
	}

	std::string SongCollection::trim(std::string str) {
		while (str.size() > 0 && str[0] == ' ')
			str.erase(0, 1);
		while (str.size() > 0 && str[str.size() - 1] == ' ')
			str.erase(str.size() - 1, 1);
		return str;
	}

	void SongCollection::cleanAlbum() {
		auto cleanup = [](Song& theSong) {
			if (theSong.album == "[None]") {
				theSong.album = "";
			}
		};
		std::for_each(songCollect.begin(), songCollect.end(), cleanup);
	}

	void SongCollection::sort(std::string str) {
		std::sort(songCollect.begin(), songCollect.end(), [=](Song theSong, Song otherSong) {
			if (str == "title")
				return theSong.title < otherSong.title;
			else if (str == "length")
				return theSong.songLength < otherSong.songLength;

			return theSong.album < otherSong.album;
		});
	}

	bool SongCollection::inCollection(std::string art) const {
		size_t count = 0;
		count = std::count_if(songCollect.begin(), songCollect.end(), [=](const Song theSong) {
			return theSong.artist == art ? true : false;
		});
		return count > 0 ? true : false;
	}

		std::list<Song> SongCollection::getSongsForArtist(std::string str) const {
		std::list<Song> listSong(songCollect.size());
		auto it = std::copy_if(songCollect.begin(), songCollect.end(), listSong.begin(), [=](Song theSong) {
			return theSong.artist == str;
		});
		listSong.resize(std::distance(listSong.begin(), it));
		return listSong;
	}

	void SongCollection::display(std::ostream& os) const {
		int newSeconds = 0;

		auto it = std::for_each(songCollect.begin(), songCollect.end(), [&](Song theSong) {os << theSong; newSeconds += theSong.songLength; });
		int hh, mm, ss;
		hh = newSeconds / 3600;
		newSeconds %= 3600;
		mm = newSeconds / 60;
		newSeconds %= 60;
		ss = newSeconds;
		std::string str = "Total Listening Time: " + std::to_string(hh) + ":" + std::to_string(mm) + ":" + std::to_string(ss);
		os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		os << "| " << std::setw(84) << str << " |\n";
		os << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
	}

	std::ostream& operator<<(std::ostream& os, const Song& theSong) {
		int min = 0, second = 0, time = theSong.songLength;
		os << "| " << std::setw(20) << std::left << theSong.title << " | " << std::setw(15) << theSong.artist <<
			" | " << std::setw(20) << theSong.album << " | "; 

		os << std::setw(6) << std::right << theSong.yrRelease << " | ";
		min = time / 60;
		time = time % 60;
		second = time;
		std::string str;
		if(std::to_string(second).size() > 1)
			str = std::to_string(min) + ":" + std::to_string(second);
		else
			str = std::to_string(min) + ":" + std::to_string(second) + '0';

		os << std::setprecision(2) << std::fixed << str << " | " << std::setprecision(2) << std::fixed << theSong.price << " |" << std::endl;
		return os;
	}

}