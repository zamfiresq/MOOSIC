//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"
#include "../headers/Artist.h"

//constructor fara parametri
Artist::Artist() {
    this -> firstName = "firstName";
    this -> lastName = "lastName";
    this -> nickname = "nickname";
    this -> nationality = "nationality";
    this -> nrLanguages = 0;
    this -> nrAlbums = 0;
    this -> nrSongs = 0;
    this -> albums = nullptr;
    this -> solo = nullptr;
}

//constructor cu parametri
Artist::Artist(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &nationality, const std::string *languages, const int &nrLanguages, const int &nrAlbums, Album *albums, Song *solo) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> nickname = nickname;
    this -> nationality = nationality;
    this -> nrLanguages = nrLanguages;
    this -> nrAlbums = nrAlbums;
    this -> albums = nullptr; // trebuie initializat cu nullptr pentru a evita erori de memorie
    this -> solo = nullptr; // trebuie initializat cu nullptr pentru a evita erori de memorie

    //adaugam conditia de alocare dinamica pentru vectorul languages
    if (nrLanguages > 0 && languages != nullptr) { //daca nrLanguages este mai mare strict decat 0, atunci putem aloca dinamic in vectorul languages
        this->languages = new std::string[nrLanguages];

        for (int i = 0; i < nrLanguages; i++) {
            this -> languages[i] = languages[i];
        }
    } else {
        this -> languages = nullptr;
    }

    if (nrAlbums > 0 && albums != nullptr) { //alocam dinamic vectorul de albume, punanad conditia de verificare
        this -> nrAlbums = nrAlbums;
        this -> albums = new Album[nrAlbums];

        for (int i = 0; i < nrAlbums; i++) {
            (this -> albums)[i] = albums[i];
        }
    }

    if (nrSongs > 0 && solo != nullptr) { //alocam dinamic vectorul solo, punand conditia de verificare
        this -> nrSongs = nrSongs;
        this -> solo = new Song[nrSongs];

        for (int i = 0; i < nrSongs; i++) {
            (this -> solo)[i] = solo[i];
        }
    }
}

//copy constructor
Artist::Artist(const Artist &object){
    this -> firstName = object.firstName;
    this -> lastName = object.lastName;
    this -> nickname = object.nickname;
    this -> nationality = object.nationality;
    this -> nrLanguages = object.nrLanguages;
    this -> nrAlbums = object.nrAlbums;
    this -> nrSongs = object.nrSongs;

    if (object.nrSongs > 0) {
        this -> solo = new Song[object.nrSongs];

        for (int i = 0; i < object.nrSongs; i++)
            this -> solo[i] = object.solo[i];
    } else {
        this -> nrSongs = 0;
        this -> solo = nullptr;
    }

    if (object.nrLanguages > 0) {
        this -> languages = new std::string [object.nrLanguages];

        for (int i = 0; i < object.nrLanguages; i++)
            this -> languages[i] = object.languages[i];
    } else {
        this->nrLanguages = 0;
        this->languages = nullptr;
    }

    if (object.nrAlbums > 0) {
        this -> albums = new Album[object.nrAlbums];

        for (int i = 0; i < object.nrAlbums; i++)
            this -> albums[i] = object.albums[i];
    } else {
        this->nrAlbums = 0;
        this->albums = nullptr;
    }
    }

