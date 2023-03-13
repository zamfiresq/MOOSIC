//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"


Album::Album() {
    this -> year = 2023;
    this -> nrSongs = 0;
    this -> songs = nullptr;
}

Album::Album(unsigned int year, unsigned int nrSongs, Song *songs) {
    this -> year = year;
    this -> nrSongs = nrSongs;
    this -> songs = new Song[nrSongs];

    for(int i = 0; i < nrSongs; i++)
        (this -> songs)[i] = songs[i];
}

Album::~Album() {
    delete []songs;
}

void Album::afis() {
    std::cout << year << " " << nrSongs << "\n";

    for(int i = 0; i < nrSongs; i++)
        std::cout << songs[i] << " ";
    std::cout << "\n";
}