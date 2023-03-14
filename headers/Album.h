//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_ALBUM_H
#define OOP_PROJECT_ALBUM_H
#include <iostream>

#include "Song.h"

class Album {
    unsigned int year;
    unsigned int nrSongs;
    Song *songs;


public:
    Album();
    Album(const unsigned int& year, const unsigned int& nrSongs, Song *songs);

    ~Album();

    void afis();
};


#endif //OOP_PROJECT_ALBUM_H
