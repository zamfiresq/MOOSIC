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
    this -> languages = {};
    this -> albums = {};
    this -> solo = {};
}

//constructor cu parametri
Artist::Artist(const std::string &firstName, const std::string &lastName, const std::string &nickname, const std::string &nationality, const std::vector<std::string>&languages, const int &nrLanguages, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs) {
    this -> firstName = firstName;
    this -> lastName = lastName;
    this -> nickname = nickname;
    this -> nationality = nationality;
    this -> nrSongs = nrSongs;
    this -> nrLanguages = nrLanguages;
    this -> nrAlbums = nrAlbums;
    this -> languages = languages;
    this -> albums = albums;
    this -> solo = solo;


    //comentez toate alocarile dinamice facute manual
    //adaugam conditia de alocare dinamica pentru vectorul languages
//    if (nrLanguages > 0 && languages != nullptr) { //daca nrLanguages este mai mare strict decat 0, atunci putem aloca dinamic in vectorul languages
//        this->languages = new std::string nrLanguages];
//
//        for (int i = 0; i < nrLanguages; i++) {
//            this -> languages[i] = languages[i];
//        }
//    } else {
//        this -> languages = nullptr;
//    }
//
//    if (nrAlbums > 0 && albums != nullptr) { //alocam dinamic vectorul de albume, punanad conditia de verificare
//        this -> nrAlbums = nrAlbums;
//        this -> albums = new Album[nrAlbums];
//
//        for (int i = 0; i < nrAlbums; i++) {
//            (this -> albums)[i] = albums[i];
//        }
//    }
//
//    if (nrSongs > 0 && solo != nullptr) { //alocam dinamic vectorul solo, punand conditia de verificare
//        this -> nrSongs = nrSongs;
//        this -> solo = new Song[nrSongs];
//
//        for (int i = 0; i < nrSongs; i++) {
//            (this -> solo)[i] = solo[i];
//        }
//    }
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
    this -> languages = object.languages;
    this -> albums = object.albums;
    this -> solo = object.solo;


    //comentez tot ce am alocat dinamic manual
//    if (object.nrSongs > 0) {
//        this -> solo = new Song[object.nrSongs];
//
//        for (int i = 0; i < object.nrSongs; i++)
//            this -> solo[i] = object.solo[i];
//    } else {
//        this -> nrSongs = 0;
//        this -> solo = nullptr;
//    }
//
//    if (object.nrLanguages > 0) {
//        this -> languages = new std::string [object.nrLanguages];
//
//        for (int i = 0; i < object.nrLanguages; i++)
//            this -> languages[i] = object.languages[i];
//    } else {
//        this->nrLanguages = 0;
//        this->languages = nullptr;
//    }
//
//    if (object.nrAlbums > 0) {
//        this -> albums = new Album[object.nrAlbums];
//
//        for (int i = 0; i < object.nrAlbums; i++)
//            this -> albums[i] = object.albums[i];
//    } else {
//        this->nrAlbums = 0;
//        this->albums = nullptr;
//    }
    }

//destructor
Artist::~Artist() {
//    if (languages != nullptr)
//        delete []languages;
//
//    if (albums != nullptr)
//        delete []albums;
//
//    if (solo != nullptr)
//        delete []solo;
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
        std::cout << albums[i];
    std::cout << "\n";

    for (int i = 0; i < nrSongs; i++)
        std::cout << solo[i] << " ";
    std::cout << "\n";
}

//operator <<
std::ostream &operator<<(std::ostream &os, const Artist &artist) {
    os <<artist.firstName<<" "<< artist.lastName << " " << artist.nickname << " " << artist.nationality<< " "<< artist.nrLanguages << " " << artist.nrSongs<<" "<< artist.nrAlbums <<"\n";

    if(artist.nrLanguages) {
        os << "Limbi vorbite:\n";
        for(int i = 0; i < artist.nrLanguages; i++)
            os << i + 1 << ". " << artist.languages[i] << "\n";
        os << "\n";
    }

    if(artist.nrSongs){
        os << "Solo-uri:\n";
        for(int i = 0; i < artist.nrSongs; i++)
            os << i + 1 << ". " << artist.solo[i] << "\n";
        os << "\n";
    }

    if(artist.nrAlbums){
        os << "Albume:\n";
        for(int i = 0; i < artist.nrAlbums; i++)
            os << i + 1 << ". " << artist.albums[i];
        os << "\n";
    }

    return os;
}



//getters si setters

//getter pentru firstName
std::string Artist::getFirstName() const {
    return firstName;
}
//setter pentru firstName
void Artist::setFirstName(const std::string &firstName) {
    Artist::firstName = firstName;
}

//getter pentru lastName
std::string Artist::getLastName() const {
    return lastName;
}
//setter pentru lastName
void Artist::setLastName(const std::string &lastName) {
    Artist::lastName = lastName;
}

//getter pentru nickname
std::string Artist::getNickname() const {
    return nickname;
}
//setter pentru nickname
void Artist::setNickname(const std::string &nickname) {
    Artist::nickname = nickname;
}

//getter pentru nationality
std::string Artist::getNationality() const {
    return nationality;
}
//setter pentru nationality
void Artist::setNationality(const std::string &nationality) {
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



