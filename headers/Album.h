//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_ALBUM_H
#define OOP_PROJECT_ALBUM_H
#include <iostream>
#include <vector>
#include <string>
#include "Song.h"

class Album {
    unsigned int year; //anul lansarii albumului
    std::string name; //numele albumului
    unsigned int nrSongs; //numarul de melodii din album
    std::vector<Song>songs; //vector de melodii ce reda melodiile dintr-un album

public:
    Album(); //constructor fara parametri
    Album(const unsigned int& year, const std::string& name, const unsigned int& nrSongs, const std::vector<Song>&songs); //constructor cu parametri
    Album(const Album &other); //copy constructor

    ~Album(); //destructor

    void afis(); //functie de afisare



    //getters si setters pentru campurile clasei Album
    unsigned int getYear() const;
    void setYear(unsigned int year);

    std::string getName() const;
    void setName(std::string& name);

    unsigned int getNrSongs() const;
    void setNrSongs(unsigned int nrSongs);

    std::vector<Song> getSongs() const;
    void setSongs(std::vector<Song>&songs);


    //supraincarcarea operatorului =
    Album& operator = (const Album &other) {
        this -> year = other.year;
        this -> name = other.name;
        this -> nrSongs = other.nrSongs;
        this -> songs = other.songs;

        return *this;
    }

//supraincarcarea operatorului <<
    friend std::ostream &operator<<(std::ostream &os, const Album &album);

    bool operator==(const Album &rhs) const;

    bool operator!=(const Album &rhs) const;


};


//    Album alb;
//    alb.setYear(5);
//    int val = 5; // doar la referinta asta
//    alb.setYear(val);

//    Album alb;
//    alb.setYear(5);
//
//    int(int valoare); -> int(5); // explicatie ce se intampla fara referinta

#endif //OOP_PROJECT_ALBUM_H
