#include "Song.h"

Song::Song(const string& artist, const string& title, const string& category, const string& content):
artist(artist), title(title), category(category), content(content) {}

const string& Song::getArtist() const{
    return artist;
}

const string& Song::getTitle() const{
    return title;
}

const string& Song::getCategory() const{
    return category;
}

bool Song::matches(const string& artist, const string& title) const{
    return (this->artist).compare(artist) == 0 && (this->title).compare(title) == 0;
}

void Song::print(ostream& os) const{
    os<<"Artist: "<<artist<<endl;
    os<<"Title: "<<title<<endl;
        
}

void Song::play(ostream& os) const{
    print(os);
    os<<"Content: "<<content<<endl;
}

ostream& operator<<(ostream& output, const Song& t)
{
  t.print(output);
  return output;
}