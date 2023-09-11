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
//Artist(const std::string &fullName, const std::string &nickname, const std::string &nationality, const std::vector<std::string>&languages, const int &nrLanguages, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs);
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

//afisare
//    void Artist::afis() const {
//        std::cout << fullName<< " " << nrLanguages
//                  << " " << nrAlbums << " " << nrSongs << "\n";
//
//        for (int i = 0; i < nrLanguages; i++)
//            std::cout << languages[i] << " ";
//        std::cout << "\n";
//
//        for (int i = 0; i < nrAlbums; i++)
//            std::cout << albums[i];
//        std::cout << "\n";
//
//        for (int i = 0; i < nrSongs; i++)
//            std::cout << solo[i] << " ";
//        std::cout << "\n";
//    }


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
