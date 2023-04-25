//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"



Album::Album() {
    this -> year = 2023;
    this -> name = " numeObisnuit";
    this -> nrSongs = 0;
    this -> songs = nullptr;
}

Album::Album(const unsigned int& year, myString name, const unsigned int& nrSongs, Song *songs) { /// conditie neaparata ca sa fie minim doua melodii/album, altfel sa nu se apeleze constructorul
    this -> year = year;
    this -> name = name;
    this -> nrSongs = nrSongs;

    if (nrSongs > 0 && songs != nullptr) {
        this->songs = new Song[nrSongs];

        for (int i = 0; i < nrSongs; i++)
            (this -> songs)[i] = songs[i];
    } else {
        this -> nrSongs = 0;
        this -> songs = nullptr;
    }
    }
Album::Album(const Album &object){
    this -> year = object.year;
    this -> name = object.name;
    this -> nrSongs = object.nrSongs;

    if (object.nrSongs > 0) {
        this -> songs = new Song[object.nrSongs];

        for (int i = 0; i < object.nrSongs; i++)
            this -> songs[i] = object.songs[i];
    } else {
        this -> nrSongs = 0;
        this -> songs = nullptr;
    }
}

Album::~Album() {
//    if (songs != nullptr)
//        delete []songs;
}

void Album::afis() {
    std::cout<< name << " " << year << " " << nrSongs << "\n";

    for(int i = 0; i < nrSongs; i++)
        std::cout << songs[i] << " ";
    std::cout << "\n";
}

std::ostream &operator<<(std::ostream &os, const Album &album) {
    os <<album.name<<", "<< album.year << ", " << album.nrSongs<<" songs" << "\n";

    for(int i = 0; i < album.nrSongs; i++) {
        os << i + 1 << ". " << album.songs[i];
    }
    os << "\n";
    return os;
}



//getters and setters
unsigned int Album::getYear() const {
    return year;
}
void Album::setYear(unsigned int year) {
    Album::year = year;
}
myString Album::getName() const {
    return name;
}
void Album::setName(myString name) {
    Album::name = name;
}
unsigned int Album::getNrSongs() const {
    return nrSongs;
}
void Album::setNrSongs(unsigned int nrSongs) {
    Album::nrSongs = nrSongs;
}
Song *Album::getSongs() const {
    return songs;
}
void Album::setSongs(Song *songs) {
    Album::songs = songs;
}
