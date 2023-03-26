//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Song.h"


Song::Song() {
    this -> year = 2023;
    this -> name = "unNume"; // incerc sa initializez un myString cu un string
    this -> language = "English";
    this -> nrFeats = 0;
    this -> feat = nullptr;
}

Song::Song(const int& year, const myString& name, const myString& language, const unsigned int& nrFeats, myString *feat) {
    this -> year = year;
    this -> name = name;
    this -> language = language;
    this -> nrFeats = nrFeats;

    if (nrFeats > 0) {
        this->feat = new myString[nrFeats];

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
        this -> feat = new myString[obiect.nrFeats];

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
myString Song::getTitle()const{
    return name;
}