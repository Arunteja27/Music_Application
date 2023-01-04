#include "Songify.h"


Songify::Songify()
{
   
}

Songify::~Songify(){
    
}

bool Songify::addAlbum(const string& artist, const string& albumTitle){
    if(albums.isFull()){
        cout<<"Album Array is full!"<<endl;
        return false;
    }
    Album *a = new Album(artist, albumTitle);
    albums+= a;
    return true;
}

bool Songify::removeAlbum(const string& artist, const string& albumTitle){
    for(int i=0; i<albums.getSize(); ++i){
        if(albums[i]->getTitle() == albumTitle){
            albums-=albums[i];
            return true;
        }
    }
    return false;
}

bool Songify::addSong(const string& artist, const string& songTitle, const string& albumTitle){
    for(int i=0; i<albums.getSize(); ++i){
        if(albums[i]->getTitle() == albumTitle){
            Song* s = new Song();  
            mediaFactory.createSong(artist, songTitle, &s);
            albums[i]->addSong(s);
            return true;
        }
    }
    return false;
}

bool Songify::removeSong(const string& artist, const string& songTitle, const string& albumTitle){
    Song* s = new Song("","","","");
    for(int i=0; i<albums.getSize(); ++i){
        if(albums[i]->getTitle() == albumTitle){
            albums[i]->removeSong(songTitle, &s);
            return true;
        }
    }
    return false;
}

bool Songify::getAlbum(int i, Album** a){
    if( i < 0 || i>= albums.getSize()){
        return false;
    }

    *a = albums[i];
    return true;
}

Array<Album*> Songify::getAlbums(){
    Array<Album*> &a = albums;
    return a;
}

void Songify::getPlaylist(const string& artist, const string& category, Array<Song*>& playlist){

    Criteria* c;
    mediaFactory.createCriteria(artist,category,(Criteria**)&c);
    
    for(int i=0; i<getAlbums().getSize(); ++i){
        
        for(int j =0; j<albums[i]->getSize(); ++j){
            Song* s = new Song();
            albums[i]->getSong(j,&s);
            if((c)->matches(*s)){
                playlist.add(s);
            }

        }

    }

    
    
}


