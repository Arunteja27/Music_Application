#include "Album.h"

Album::Album(const string& artist, const string& title):
artist(artist), title(title){}

Album::~Album(){
    
}

bool Album::matches(const string& artist, const string& title) const{
    return (this->artist).compare(artist) == 0 && (this->title).compare(title) == 0; 
}

bool Album::addSong(Song* song){
    songs+=song;
    return true;
}

int Album::getSize(){
    return songs.getSize();
}

string Album::getTitle() const{
    return title;
}

Song*& Album::operator[](int index){
	return songs[index];
}

bool Album::getSong(int index, Song** song) const{
    *song = songs[index];
    return song == NULL;
}

bool Album::removeSong(const string& title, Song** song){
    int s = songs.getSize();
    return (songs-=*song).getSize() < s;

}

void Album::print(ostream& os) const{
    printShort(os);
    os<<songs<<endl;
}

void Album::printShort(ostream& os) const{
    os<<"Album Artist: "<<artist<<endl;
    os<<"Album Title: "<<title<<endl;
}

ostream& operator<<(ostream& output, const Album& a)
{
  a.print(output);
  return output;
}
