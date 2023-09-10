//
// Created by Alexandra Zamfirescu on 13.03.2023.
//


#include "../headers/Song.h"
#include <sstream>
#include <iomanip>


Song::Song() {
    this -> year = 2023;
    this -> artistName = "Nume Artist";
    this -> name = "Un Nume";
    this -> language = "English";
    this -> duration = 2.35;
    this -> feat = {};
}


Song::Song(const int& year, const std::string& artistName, const std::string& name, const std::string& language, const unsigned int& nrFeats, std::vector<std::string>&feat, double& duration) {
    this -> year = year;
    this -> artistName = artistName;
    this -> name = name;
    this -> language = language;
    this -> nrFeats = nrFeats;
    this-> duration = duration;
    this -> feat = feat;
}


Song::Song(const Song &obiect) {
    this -> year = obiect.year;
    this -> artistName = obiect.artistName;
    this -> name = obiect.name;
    this -> language = obiect.language;
    this -> nrFeats = obiect.nrFeats;
    this-> duration = obiect.duration;
    this -> feat = obiect.feat;
}

Song::~Song() {}


//functia de afisare

void Song::afis() {

    std::cout<<"\n\n"<< "The song is:\n";
    std::cout<<"Name: " << name <<"\n";
    std::cout<<"Artist name: "<< artistName << "\n";
    std::cout<<"Year: "<< year << "\n";
    std::cout<<"Languages: "<< language << " \n";
    std::cout<<"Feats: "<< nrFeats << "\n";

    for(int i = 0; i < nrFeats; i++)
        std::cout << feat[i] << " ";

    std::cout<<"Duration: "<< duration;
    std::cout << "\n";

}


//supraincarcarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Song &melodie) {
    os<<"\n\n"<<melodie.name << " - "<< melodie.artistName<< " ("<< melodie.year << ", "<< melodie.language << ")"<<" ";
    if(melodie.nrFeats > 0)
        os<< "feat. ";


    for(int i = 0; i < melodie.nrFeats; i++){
            os << melodie.feat[i];
            if(i != melodie.nrFeats - 1) //daca nu e ultimul feat, pune virgula
                os << ", ";
    }

    // conversie pentru durata de la double la string cu 2 zecimale
    std::ostringstream ss; // std::ostringstream pentru a converti double-ul in string
    ss << std::fixed << std::setprecision(2) << melodie.duration; // setez numarul de zecimale la 2 cu ajutorul std::setprecision(2) din <iomanip>
    std::string durataStr = ss.str();

    // inlocuiesc '.' cu ':'
    for (char &c : durataStr) {
        if (c == '.') {
            c = ':';
        }
    }


    os <<"                                  "<<durataStr;
    os << "\n";


    return os;
}


//supraincarcarea >>
std::istream &operator>>(std::istream &is, Song &song){
    std::cout<<"Type the name of the song: ";
    std::getline(is, song.name);
    std::cout<<"Type the name of the artist: ";
    std::getline(is, song.artistName);
    std::cout<<"Type the year of the song: ";
    is >> song.year;
    std::cout<<"Type the language of the song: ";
    is >> song.language;
    std::cout<<"Type the duration of the song: ";
    is >> song.duration;
    std::cout<<"Type the number of feats: ";
    is >> song.nrFeats;


    // citirea numelui de feats, daca exista
    if (song.nrFeats > 0) {
        std::cin.ignore(); // ignora caracterul newline (\n) din bufferul de intrare
        for (int i = 0; i < song.nrFeats; i++) {
            std::cout << "Type the feat #" << i + 1 << ": ";
            std::string feat;
            std::getline(is, feat); //  std::getline pentru a citi numele complet, cu tot cu spatii
            song.feat.push_back(feat);
        }
    }


    return is;
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

void Song::setArtistName(std::string& artistName) {
    this -> artistName = artistName;
}

void Song::welcomeMessage() {
    std::cout << "Welcome to the song class!\n";
}


