//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Song.h"

Song::Song() {
    this -> year = 2023;
    this -> language = "English";
    this -> nrFeats = 0;
    this -> feat = nullptr;
}

Song::Song(int year, std::string language, unsigned int nrFeats, std::string *feat) {
    this -> year = year;
    this -> language = language;
    this -> nrFeats = nrFeats;

    this -> feat = new std::string[nrFeats];

    for(int i = 0; i < nrFeats; i++)
        (this->feat)[i] = feat[i];
}

Song::~Song() {
    delete []feat;
}

void Song::afis() {
    std::cout << year << " " << language << " " << nrFeats << "\n";

    for(int i = 0; i < nrFeats; i++)
        std::cout << feat[i] << " ";
    std::cout << "\n";
}

std::ostream &operator<<(std::ostream &os, const Song &melodie) {
    std::cout << melodie.year << " " << melodie.language << " " << melodie.nrFeats << "\n";

    for(int i = 0; i < melodie.nrFeats; i++)
        std::cout << melodie.feat[i] << " ";
    std::cout << "\n";
    return os;
}