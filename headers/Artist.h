//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_ARTIST_H
#define OOP_PROJECT_ARTIST_H

#include <iostream>
#include <string>
#include <vector>
#include "Album.h"
#include "Song.h"


class Artist {
    std::string fullName;
    std::vector<Album>albums;
    int nrAlbums;
    std::vector<Song>solo;
    int nrSongs;

public:
    Artist(); //constructor fara parametri
    //constructor cu parametri
    Artist(const std::string &fullName, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs);
    Artist(const Artist &obiect); //copy constructor

    //operatori
    friend std::ostream &operator<<(std::ostream &os, const Artist &artist); //supraincarcarea operatorului <<
    friend std::istream &operator>>(std::istream &is, Artist &artist); //supraincarcarea operatorului >>

    Artist& operator = (const Artist &other){ //supraincarcarea operatorului =
        this->fullName = other.fullName;
        this->nrAlbums = other.nrAlbums;
        this->nrSongs = other.nrSongs;
        this->albums = other.albums;
        this->solo = other.solo;

        return *this;
    }

    ~Artist(); //destructor


//    void afis() const; //functie de afisare

    //getters si setters
    std::string getFullName() const;
    void setFullName(const std::string& fullName);

    std::string getNickname() const;
    void setNickname(const std::string& nickname);

    Album* getAlbums() const;
    void setAlbums(std::vector<Album>&albums, const int& nrAlbums); //am pus ampersand

    int getNrAlbums() const;
    void setNrAlbums(const int& nrAlbums);

    Song* getSolo() const;
    void setSolo(std::vector<Song>&solo, const int& nrSongs); //am pus ampersand

    int getNrSongs() const;
    void setNrSongs(const int& nrSongs);

};



#endif //OOP_PROJECT_ARTIST_H
