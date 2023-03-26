//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_SONG_H
#define OOP_PROJECT_SONG_H
#include <iostream>
#include "myString.h"


class Song {
    int year;  //anul lansarii melodiei
    myString name; //titlul melodiei
    myString language;  //limba melodiei
    unsigned int nrFeats; //numarul de colaboratori dintr-o melodie
    myString *feat; //vector de string-uri cu numele colaboratorilor

public:
    Song(); //constructor fara parametri
    Song(const int& year, const myString& name, const myString& language, const unsigned int& nrFeats, myString *feat); //constructor cu parametri
    Song(const Song &obiect); //copy constructor

    ~Song(); //destructor

    void afis(); //functie de afisare


    friend std::ostream &operator<<(std::ostream &os, const Song &song); //supraincarcarea operatorului <<

    Song& operator = (const Song &other) {  //copiem valorile dintr-un obiect din clasa Song intr-un alt obiect din Song
        this -> year = other.year;
        this -> name = other.name;
        this -> language = other.language;
        this -> nrFeats = other.nrFeats;
        this -> feat = other.feat;
        return *this;
    }

//supraincarcarea operatorului ==
    bool operator == (const Song &other) {
        if (this -> year == other.year && this -> name == other.name && this -> language == other.language && this -> nrFeats == other.nrFeats && this -> feat == other.feat) {
            return true;
        }
        return false;
    }

//supraincarcarea operatorului !=
    bool operator != (const Song &other) {
        if (this -> year != other.year || this -> name != other.name || this -> language != other.language || this -> nrFeats != other.nrFeats || this -> feat != other.feat) {
            return true;
        }
        return false;
    }


    //getters
    myString getTitle() const;
    int getYear() const;
    myString getLanguage() const;
    unsigned int getNrFeats() const;
    myString* getFeat() const;

    //setters
    void setTitle(myString& name);
    void setYear(int& year);
    void setLanguage(myString& language);
    void setNrFeats(unsigned int& nrFeats);
    void setFeat(myString *feat);

};


#endif //OOP_PROJECT_SONG_H
