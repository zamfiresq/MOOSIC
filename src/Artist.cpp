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
    this -> languages = nullptr;
    this -> albums = nullptr;
    this -> solo = nullptr;
}

//constructor cu parametri
Artist::Artist(const myString &firstName, const myString &lastName, const myString &nickname, const myString &nationality, const myString *languages, const int &nrLanguages, const int &nrAlbums, Album *albums, Song *solo) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> nickname = nickname;
    this -> nationality = nationality;
    this -> nrLanguages = nrLanguages;
    this -> nrAlbums = nrAlbums;
    this -> languages = nullptr; // trebuie initializat cu nullptr pentru a evita erori de memorie
    this -> albums = nullptr; // trebuie initializat cu nullptr pentru a evita erori de memorie
    this -> solo = nullptr; // trebuie initializat cu nullptr pentru a evita erori de memorie

    //adaugam conditia de alocare dinamica pentru vectorul languages
    if (nrLanguages > 0 && languages != nullptr) { //daca nrLanguages este mai mare strict decat 0, atunci putem aloca dinamic in vectorul languages
        this->languages = new myString[nrLanguages];

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
        this -> languages = new myString [object.nrLanguages];

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

//destructor
Artist::~Artist() {
    if (languages != nullptr)
        delete []languages;

    if (albums != nullptr)
        delete []albums;

    if (solo != nullptr)
        delete []solo;
}

//afisare
void Artist::afis() const {
    std::cout << firstName << " " << lastName << " "
              << nickname << " " << nationality << " " << nrLanguages
              << " " << nrAlbums << " " << nrSongs << "\n";

    for (int i = 0; i < nrLanguages; i++)
        std::cout << languages[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < nrAlbums; i++)
        std::cout << &albums[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < nrSongs; i++)
        std::cout << solo[i] << " ";
    std::cout << "\n";
}

//operator =
std::ostream &operator<<(std::ostream &os, const Artist &artist) {
    os <<artist.firstName<<" "<< artist.lastName << " " << artist.nickname << " " << artist.nationality<<" "<< artist.nrLanguages << artist.nrSongs<<" "<< artist.nrAlbums <<"\n";

    for(int i = 0; i < artist.nrLanguages; i++)
        os << artist.languages[i] << " ";
    os << "\n";

    for(int i = 0; i < artist.nrSongs; i++)
        os << artist.solo[i] << " ";
    os << "\n";

    for(int i = 0; i < artist.nrAlbums; i++)
        os << artist.albums[i] << " ";
    os << "\n";

    return os;
}

//getters si setters
//getter pentru firstName
myString Artist::getFirstName() const {
    return firstName;
}
//setter pentru firstName
void Artist::setFirstName(const myString &firstName) {
    Artist::firstName = firstName;
}

//getter pentru lastName
myString Artist::getLastName() const {
    return lastName;
}
//setter pentru lastName
void Artist::setLastName(const myString &lastName) {
    Artist::lastName = lastName;
}


//getter pentru nickname
myString Artist::getNickname() const {
    return nickname;
}
//setter pentru nickname
void Artist::setNickname(const myString &nickname) {
    Artist::nickname = nickname;
}


//getter pentru nationality
myString Artist::getNationality() const {
    return nationality;
}
//setter pentru nationality
void Artist::setNationality(const myString &nationality) {
    Artist::nationality = nationality;
}


//getter pentru nrLanguages
int Artist::getNrLanguages() const {
    return nrLanguages;
}
//setter pentru nrLanguages

//getter pentru nrSongs
int Artist::getNrSongs() const {
    return nrSongs;
}
//setter pentru nrSongs

//getter pentru nrAlbums
int Artist::getNrAlbums() const {
    return nrAlbums;
}
//setter pentru nrAlbums


//getter pentru languages
//myString* Artist::getLanguages() const {
//   return languages;
//}


//setter pentru vectorul languages
//void Artist::setLanguages(const myString *languages, const int &nrLanguages) {
//    Artist::nrLanguages = nrLanguages;
//
//    if (Artist::languages != nullptr) {
//        delete[] Artist::languages;
//        Artist::languages = nullptr;
//    }
//
//    if (nrLanguages > 0) {
//        Artist::languages = new myString[nrLanguages];
//        for (int i = 0; i < nrLanguages; ++i) {
//            Artist::languages[i] = languages[i];
//        }
//    }
//}


//getter pentru vectorul albums
//Album* Artist::getAlbums() const {
//    return albums;
//}


//setter pentru vectorul allbums
//void Artist::setAlbums(Album *albums, const int &nrAlbums) {
//    Artist::nrAlbums = nrAlbums;
//
//    if (Artist::albums != nullptr) {
//        delete[] Artist::albums;
//        Artist::albums = nullptr;
//    }
//
//    if (nrAlbums > 0) {
//        Artist::albums = new Album[nrAlbums];
//        for (int i = 0; i < nrAlbums; ++i) {
//            Artist::albums[i] = albums[i];
//        }
//    }
//}


//getter pentru vectorul solo
//Song* Artist::getSolo() const {
//    return solo;
//}


//setter pentru vectorul solo
//void Artist::setSolo(Song *solo, const int &nrSongs) {
//    Artist::nrSongs = nrSongs;
//
//    if (Artist::solo != nullptr) {
//        delete[] Artist::solo;
//        Artist::solo = nullptr;
//    }
//
//    if (nrSongs > 0) {
//        Artist::solo = new Song[nrSongs];
//        for (int i = 0; i < nrSongs; ++i) {
//            Artist::solo[i] = solo[i];
//        }
//    }
//}
//}


