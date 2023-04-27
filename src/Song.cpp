//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Song.h"


Song::Song() {
    this -> year = 2023;
    this -> artistName = "numeArtist";
    this -> name = "unNume";
    this -> language = "English";
    this -> nrFeats = 0;
    this -> feat = {};
}

Song::Song(const int& year, const std::string& artistName, const std::string& name, const std::string& language, const unsigned int& nrFeats, std::vector<std::string>&feat) {
    this -> year = year;
    this -> artistName = artistName;
    this -> name = name;
    this -> language = language;
    this -> nrFeats = nrFeats;
    this -> feat = feat;


}
Song::Song(const Song &obiect) {
    this -> year = obiect.year;
    this -> artistName = obiect.artistName;
    this -> name = obiect.name;
    this -> language = obiect.language;
    this -> nrFeats = obiect.nrFeats;
    this -> feat = obiect.feat;


}

Song::~Song() {}

//functia de afisare
void Song::afis() {
    std::cout<<"Name: " << name <<"\n";
    std::cout<<"Artist name: "<< artistName << "\n";
    std::cout<<"Year: "<< year << "\n";
    std::cout<<"Languages: "<< language << " \n";
    std::cout<<"Feats: "<< nrFeats << "\n";

    for(int i = 0; i < nrFeats; i++)
        std::cout << feat[i] << " ";
        std::cout<<"dadaadada";
    std::cout << "\n";
}

//supraincarcarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Song &melodie) {
    os << melodie.name << " " <<melodie.artistName<< " " << melodie.year << " " << melodie.language << " " << melodie.nrFeats << "\n";

    for(int i = 0; i < melodie.nrFeats; i++){
            os << melodie.feat[i] <<"\n"; //afisare feat
        }


    return os;
}


//getters
std::string Song::getTitle()const{
    return name;
}
std::string Song::getLanguage() const {
    return language;
}
std::vector<std::string> Song::getFeat() const {  // std::string getFeat() const;
    return feat;  //am modificat aici
}
unsigned int Song::getNrFeats() const {
    return nrFeats;
}
int Song::getYear() const {
    return year;
}

std::string Song::getArtistName() const{
    return artistName;
}


//setters
void Song::setTitle(std::string& name) {
    this -> name = name;
}
void Song::setLanguage(std::string& language) {
    this -> language = language;
}
void Song::setFeat(std::vector<std::string>&feat) {
    this -> feat = feat;
}
void Song::setNrFeats(unsigned int& nrFeats) {
    this -> nrFeats = nrFeats;
}
void Song::setYear(int& year) {
    this -> year = year;
}


//bool operator == (const Song &other) {
//cepulamea
//bool Song::operator==(const Song &other) {
//    return year == other.year &&
//           name == other.name &&
//           language == other.language &&
//           nrFeats == other.nrFeats &&
//           feat == other.feat;
//}
//
//bool Song::operator!=(const Song &rhs) {
//    return !(rhs == *this);
//}
