#include "MediaFactory.h"
#include <fstream>
#include <limits>

// retrieve Song data from a file and use it to create a Song object
bool MediaFactory::createSong(const string& a, const string& t, Song** song){
    ifstream mediaFile;
    mediaFile.open("media/songinfo.txt");
    string empty, title, content, category, artist, video;

    while( true ){
        cout<<"Searching for songs artist: "<<endl;
        getline(mediaFile, artist);
        cout<<"artist: "<<artist<<endl;
        getline(mediaFile, title);
        cout<<"title: \n"<<title<<endl;
        getline(mediaFile, category);
        getline(mediaFile, content);
        getline(mediaFile, video);

        // if we found the right Media, make a new object and return
        if (t == title && a == artist){
            *song = new Song(artist, title, category, content);
            mediaFile.close();
            return true;
        }

        // either there is an empty line
        // and another record, or we are done
        if(!getline(mediaFile, empty))break;
    }

    mediaFile.close();
    return false;
}

bool MediaFactory::createAlbum(const string& title, const string& owner, Album** alb){
   Album a = *(new Album(owner, title));
    *alb = &a;
    return true;

}

bool MediaFactory::createCriteria(const string& artist, const string& category, Criteria** crit){
    if(artist == "" && category == ""){return false;}
    if(artist == ""){
        C_Criteria* c = new C_Criteria(category);
        *crit = c;
        return true;
    }else if(category == ""){
        A_Criteria* a = new A_Criteria(artist);
        *crit = a;
        return true;
    }else if(artist != "" && category != ""){
        AorC_Criteria* ac = new AorC_Criteria(artist, category);
        *crit = ac;
        return true;
    }
    return false;
}