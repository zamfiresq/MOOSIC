//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#ifndef OOP_PROJECT_SONG_H
#define OOP_PROJECT_SONG_H
#include <iostream>
#include <string>
#include <vector>

class Song {
    int year;  //anul lansarii melodiei
    std::string artistName; //numele artistului
    std::string name; //titlul melodiei
    unsigned int nrFeats; //numarul de colaboratori dintr-o melodie //STATIC
    std::vector<std::string> feat; //vector de string-uri cu numele colaboratorilor
    double duration; //durata melodiei

public:
    Song(); //constructor fara parametri
    Song(const int& year,  const std::string& artistName, const std::string& name, const unsigned int& nrFeats, std::vector<std::string>&feat, double& duration); //constructor cu parametri
    Song(const Song &obiect); //copy constructor

    ~Song(); //destructor

    void afis(int index); //functie de afisare

    //supraincarcarea operatorului <<
    friend std::ostream &operator<<(std::ostream &os, const Song &song);

    //supraincarcarea operatorului >>
    friend std::istream &operator>>(std::istream &is, Song &song);

    Song& operator = (const Song &other) {  //copiem valorile dintr-un obiect din clasa Song intr-un alt obiect din Song
        this -> year = other.year;
        this -> artistName = other.artistName;
        this -> name = other.name;
//        this -> language = other.language;
        this -> nrFeats = other.nrFeats;
        this-> duration = other.duration;
        this -> feat = other.feat;
        return *this;
    }

//supraincarcarea operatorului ==
    bool operator == (const Song &other) const {
        return (this -> year == other.year && this -> artistName == other.artistName && this -> name == other.name && this -> nrFeats == other.nrFeats && this -> feat == other.feat
                && this -> duration == other.duration);
    }

//supraincarcarea operatorului !=
    bool operator != (const Song &other) const {
        return (this -> year != other.year || this -> artistName != other.artistName || this -> name != other.name || this -> nrFeats != other.nrFeats || this -> feat != other.feat
                || this -> duration != other.duration);
    }

    //getters
    std::string getTitle() const;
    std::string getArtistName() const;
    int getYear() const;
//    std::string getLanguage() const;
    static unsigned int getNrFeats(); //STATIC
    std::vector<std::string> getFeat() const;
    double getDuration() const;


    //setters
    void setTitle(std::string& name);
    void setYear(int& year);
    void setNrFeats(unsigned int& nrFeats);
    void setFeat(std::vector<std::string>&feat);
    void setArtistName(std::string& artistName);
    void setDuration(double& duration);

    static void welcomeMessage(); //STATIC

    // read from csv
    void readFromCSV(const std::string& line);

};


#endif //OOP_PROJECT_SONG_H
