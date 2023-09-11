//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"
#include "../headers/Artist.h"



//constructor fara parametri
Artist::Artist() {
    this -> fullName = "Travis Scott";
    this -> nrAlbums = 2;
    this -> nrSongs = 5;
    this -> albums = {Album(), Album()};
    this -> solo = {Song(), Song(), Song(), Song(), Song()};
}

//constructor cu parametri
Artist::Artist(const std::string &fullName, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs) {
    this->fullName = fullName;
    this->nrSongs = nrSongs;
    this->nrAlbums = nrAlbums;
    this->albums = albums;
    this->solo = solo;
}

//copy constructor
    Artist::Artist(const Artist &obiect){
        this->fullName = obiect.fullName;
        this->nrAlbums = obiect.nrAlbums;
        this->nrSongs = obiect.nrSongs;
        this->albums = obiect.albums;
        this->solo = obiect.solo;

    }

//destructor
    Artist::~Artist() {}


//operator <<
    std::ostream &operator<<(std::ostream &os, const Artist &artist) {
        os << artist.fullName << "\n";
        os << artist.nrAlbums << " album(s), "<< artist.nrSongs << " single(s)\n\n";


        if (artist.nrAlbums) {
            os << "Albums:\n";
            for (int i = 0; i < artist.nrAlbums; i++)
                if(i < 9)
                    os << " " << i + 1 << ". " << artist.albums[i];
                else
                    os << i + 1 << ". " << artist.albums[i];
            os << "\n";
        }

        if (artist.nrSongs) {
            os <<"Singles:\n";
            for (int i = 0; i < artist.nrSongs; i++)
                if(i < 9)
                    os << " " << i + 1 << ". " << artist.solo[i];
                else
                    os << i + 1 << ". " << artist.solo[i];
            os << "\n";
        }
            return os;
        }

//operator >>
std::istream &operator>>(std::istream &is, Artist &artist) {
    std::cout << "Enter the name of the artist: ";
    std::getline(is, artist.fullName);
    std::cout << "Type the number of albums: ";
    is >> artist.nrAlbums;
    std::cout << "Type the number of singles: ";
    is >> artist.nrSongs;

    artist.albums.clear();
    artist.albums.resize(artist.nrAlbums);

    artist.solo.clear();
    artist.solo.resize(artist.nrSongs);

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // citirea albumelor
    for (int i = 0; i < artist.nrAlbums; i++){
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignorare newline din buffer
        is >> artist.albums[i];
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // citirea melodiilor
    for (int i = 0; i < artist.nrSongs; i++){
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignorare newline din buffer
        is >> artist.solo[i];
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return is;

}


//getters si setters

//getter pentru full name
    std::string Artist::getFullName() const {
        return fullName;
    }
//setter pentru full name
    void Artist::setFullName(const std::string &fullName) {
        Artist::fullName = fullName;
    }

//getter pentru nrSongs
    int Artist::getNrSongs() const {
        return nrSongs;
    }
//setter pentru nrSongs

//getter pentru nrAlbums
    int Artist::getNrAlbums() const {
        return nrAlbums;
    }
