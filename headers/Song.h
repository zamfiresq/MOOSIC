//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_SONG_H
#define OOP_PROJECT_SONG_H
#include <iostream>
#include <string>
#include<vector>

class Song {
    int year;  //anul lansarii melodiei
    std::string name; //titlul melodiei
    std::string language;  //limba melodiei
    unsigned int nrFeats; //numarul de colaboratori dintr-o melodie
    std::vector<std::string> feat; //vector de string-uri cu numele colaboratorilor

public:
    Song(); //constructor fara parametri
    Song(const int& year, const std::string& name, const std::string& language, const unsigned int& nrFeats, std::vector<std::string>&feat); //constructor cu parametri
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
        return (this -> year == other.year && this -> name == other.name && this -> language == other.language && this -> nrFeats == other.nrFeats && this -> feat == other.feat);
    }

//supraincarcarea operatorului !=
    bool operator != (const Song &other) {
        return (this -> year != other.year || this -> name != other.name || this -> language != other.language || this -> nrFeats != other.nrFeats || this -> feat != other.feat);
    }

    //getters
    std::string getTitle() const;
    int getYear() const;
    std::string getLanguage() const;
    unsigned int getNrFeats() const;
    std::vector<std::string> getFeat() const;

    //setters
    void setTitle(std::string& name);
    void setYear(int& year);
    void setLanguage(std::string& language);
    void setNrFeats(unsigned int& nrFeats);
    void setFeat(std::vector<std::string>&feat);

};


#endif //OOP_PROJECT_SONG_H
