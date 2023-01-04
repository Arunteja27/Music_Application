#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Array.h"

using namespace std;

class Album {

	friend ostream& operator<<(ostream&, const Album&);
		
	public:
		//constructors
		Album(const string& artist, const string& albumTitle);

		//destructor
		~Album();

		//getters
		int getSize();
		Song*& operator[](int);
		bool getSong(int, Song**) const;
		string getTitle() const;

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;

		//add and remove
		bool addSong(Song*);
		bool removeSong(const string& songTitle, Song**);

		void printShort(ostream&) const;
		void print(ostream&) const;
	
	private:
		string title;
		string artist;
		Array<Song*> songs;
	
};
#endif