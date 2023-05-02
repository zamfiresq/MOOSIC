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
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string nationality;
    std::vector<std::string>languages;
    int nrLanguages;
    std::vector<Album>albums;
    int nrAlbums;
    std::vector<Song>solo;
    int nrSongs;

public:
    Artist(); //constructor fara parametri
    //constructor cu parametri
    Artist(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &nationality, const std::vector<std::string>&languages, const int &nrLanguages, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs);
    Artist(const Artist &obiect); //copy constructor

    //operatori
    friend std::ostream &operator<<(std::ostream &os, const Artist &artst); //supraincarcarea operatorului <<

    ~Artist(); //destructor


    void afis() const; //functie de afisare

    //getters si setters
    std::string getFirstName() const;
    void setFirstName(const std::string& firstName);

    std::string getLastName() const;
    void setLastName(const std::string& lastName);

    std::string getNickname() const;
    void setNickname(const std::string& nickname);

    std::string getNationality() const;
    void setNationality(const std::string& nationality);

    std::string* getLanguages() const;
    void setLanguages(const std::vector<std::string>&languages, const int& nrLanguages); //am pus ampersand

    int getNrLanguages() const;
    void setNrLanguages(const int& nrLanguages);

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
