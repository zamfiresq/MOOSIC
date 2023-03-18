//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"


Album::Album() {
    this -> year = 2023;
    this -> nrSongs = 0;
    this -> songs = nullptr;
}

Album::Album(const unsigned int& year, const unsigned int& nrSongs, Song *songs) { /// conditie neaparata ca sa fie minim doua melodii/album, altfel sa nu se apeleze constructorul
    this -> year = year;
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

Album::~Album() {
    if (songs != nullptr)
        delete []songs; /// aici e problema in pl mea da nuj cum s o rezolv
}

void Album::afis() {
    std::cout << year << " " << nrSongs << "\n";

    for(int i = 0; i < nrSongs; i++)
        std::cout << songs[i] << " ";
    std::cout << "\n";
}


