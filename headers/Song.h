//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_SONG_H
#define OOP_PROJECT_SONG_H
#include <iostream>


class Song {
    int year;
    std::string language;

    unsigned int nrFeats;
    std::string *feat;

public:
    Song();
    Song(const int& year, const std::string& language, const unsigned int& nrFeats, std::string *feat);

    ~Song();

    void afis();

    friend std::ostream &operator<<(std::ostream &os, const Song &song);

    Song& operator = (const Song other) {
        this -> year = other.year;
        this -> language = other.language;
        this -> nrFeats = other.nrFeats;
        this -> feat = other.feat;
        return *this;
    }

};

#endif //OOP_PROJECT_SONG_H
