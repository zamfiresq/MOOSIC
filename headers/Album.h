//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_ALBUM_H
#define OOP_PROJECT_ALBUM_H
#include <iostream>

#include "Song.h"

class Album {
    unsigned int year; //anul lansarii albumului
    std::string name; //numele albumului
    unsigned int nrSongs; //numarul de melodii din album
    Song *songs; //vector de melodii ce reda melodiile dintr-un album

public:
    Album(); //constructor fara parametri
    Album(const unsigned int& year, const std::string& name, const unsigned int& nrSongs, Song *songs); //constructor cu parametri
    Album(const Album &other); //copy constructor

    ~Album(); //destructor

    void afis(); //functie de afisare

    //getters si setters pentru campurile clasei Album
    unsigned int getYear() const;
    void setYear(unsigned int year);

//    Album alb;
//    alb.setYear(5);
//    int val = 5; // doar la referinta asta
//    alb.setYear(val);

//    Album alb;
//    alb.setYear(5);
//
//    int(int valoare); -> int(5); // explicatie ce se intampla fara referinta

    std::string getName() const;
    void setName(std::string name);

    unsigned int getNrSongs() const;
    void setNrSongs(unsigned int nrSongs);

    Song* getSongs() const;
    void setSongs(Song *songs);

};


#endif //OOP_PROJECT_ALBUM_H
