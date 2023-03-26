//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_ARTIST_H
#define OOP_PROJECT_ARTIST_H

#include <iostream>
#include "myString.h"
#include "Album.h"
#include "Song.h"


class Artist {
    myString firstName;
    myString lastName;
    myString nickname;
    myString nationality;
    myString *languages;
    int nrLanguages;
    Album *albums;
    int nrAlbums;
    Song *solo;
    int nrSongs;

public:
    Artist(); //constructor fara parametri
    //constructor cu parametri
    Artist(const myString &firstName, const myString &lastName, const myString &nickname, const myString &nationality, const myString *languages, const int &nrLanguages, const int &nrAlbums, Album *albums, Song *solo);
    Artist(const Artist &obiect); //copy constructor

    //operatori
    friend std::ostream &operator<<(std::ostream &os, const Artist &artst); //supraincarcarea operatorului <<


    ~Artist(); //destructor


    void afis() const; //functie de afisare

    //getters si setters
    myString getFirstName() const;
    void setFirstName(const myString& firstName);

    myString getLastName() const;
    void setLastName(const myString& lastName);

    myString getNickname() const;
    void setNickname(const myString& nickname);

    myString getNationality() const;
    void setNationality(const myString& nationality);

    myString* getLanguages() const;
    void setLanguages(const myString* languages, const int& nrLanguages);

    int getNrLanguages() const;
    void setNrLanguages(const int& nrLanguages);

    Album* getAlbums() const;
    void setAlbums(Album *albums, const int& nrAlbums);

    int getNrAlbums() const;
    void setNrAlbums(const int& nrAlbums);

    Song* getSolo() const;
    void setSolo(Song *solo, const int& nrSongs);

    int getNrSongs() const;
    void setNrSongs(const int& nrSongs);
};

#endif //OOP_PROJECT_ARTIST_H
