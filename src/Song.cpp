//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Song.h"

Song::Song() {
    this -> year = 2023;
    this -> name = "unNume";
    this -> language = "English";
    this -> nrFeats = 0;
    this -> feat = nullptr;
}

Song::Song(const int& year, const std::string& name, const std::string& language, const unsigned int& nrFeats, std::string *feat) {
    this -> year = year;
    this -> name = name;
    this -> language = language;
    this -> nrFeats = nrFeats;

    if (nrFeats > 0) {
        this->feat = new std::string[nrFeats];

        for (int i = 0; i < nrFeats; i++)
            (this->feat)[i] = feat[i];
    } else {
        this -> nrFeats = 0;
        this -> feat = nullptr;
    }
}
Song::Song(const Song &obiect) {
    this -> year = obiect.year;
    this -> name = obiect.name;
    this -> language = obiect.language;
    this -> nrFeats = obiect.nrFeats;

    if (obiect.nrFeats > 0) {
        this -> feat = new std::string[obiect.nrFeats];

        for (int i = 0; i < obiect.nrFeats; i++)
            (this -> feat)[i] =(obiect.feat)[i];
    } else {
        this -> nrFeats = 0;
        this -> feat = nullptr;
    }

}

Song::~Song() {
//    if (feat != nullptr)
//        delete []feat;
}

//functia de afisare
void Song::afis() {
    std::cout << name << " "<< year << " " << language << " " << nrFeats << "\n";

    for(int i = 0; i < nrFeats; i++)
        std::cout << feat[i] << " ";
    std::cout << "\n";
}

//supraincarcarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Song &melodie) {
    os <<melodie.name<<" "<< melodie.year << " " << melodie.language << " " << melodie.nrFeats << "\n";

    for(int i = 0; i < melodie.nrFeats; i++)
        os << melodie.feat[i] << " ";
    os << "\n";
    return os;
}

//getter
std::string Song::getTitle()const{
    return name;

}