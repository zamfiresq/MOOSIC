//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"


Album::Album() {
    this -> year = 2023;
    this -> name = " numeObisnuit";
    this -> nrSongs = 0;
    this -> songs = {};
}

Album::Album(const unsigned int& year, const std::string& name, const unsigned int& nrSongs, const std::vector<Song>&songs) {
    this -> year = year;
    this -> name = name;
    this -> nrSongs = nrSongs;
    this -> songs = songs;

    //comentez alocarile dinamice facute manual
//    if (nrSongs > 0 && songs != nullptr) {
//        this->songs = new Song[nrSongs];
//
//        for (int i = 0; i < nrSongs; i++)
//            (this -> songs)[i] = songs[i];
//    } else {
//        this -> nrSongs = 0;
//        this -> songs = nullptr;
//    }

    }
Album::Album(const Album &object){
    this -> year = object.year;
    this -> name = object.name;
    this -> nrSongs = object.nrSongs;
    this -> songs = object.songs;

    //comentez alocarile dinamice facute manual
//    if (object.nrSongs > 0) {
//        this -> songs = new Song[object.nrSongs];
//
//        for (int i = 0; i < object.nrSongs; i++)
//            this -> songs[i] = object.songs[i];
//    } else {
//        this -> nrSongs = 0;
//        this -> songs = nullptr;
//    }
}

Album::~Album() {}

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
std::string Album::getName() const {
    return name;
}
void Album::setName(std::string& name) {
    Album::name = name;
}
unsigned int Album::getNrSongs() const {
    return nrSongs;
}
void Album::setNrSongs(unsigned int nrSongs) {
    Album::nrSongs = nrSongs;
}
std::vector<Song>Album::getSongs() const {
    return songs;
}
void Album::setSongs(std::vector<Song>&songs) {
    Album::songs = songs;
}

bool Album::operator==(const Album &rhs) const {
//    if( year == rhs.year && name == rhs.name && nrSongs == rhs.nrSongs) {
//        for(int i = 0; i < nrSongs; i++)
//            if(songs[i] != (rhs.songs)[i])
//                return false;
//    }
//    return true;
    return (rhs == *this); // nu cred ca e ok
}

bool Album::operator!=(const Album &rhs) const {
    return !(rhs == *this);
}
