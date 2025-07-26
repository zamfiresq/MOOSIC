//
// Created by Alexandra Zamfirescu on 13.03.2023.
//


#include "../headers/Song.h"
#include <sstream>
#include <iomanip>


Song::Song() {
    this -> year = 0;
    this -> artistName = "Artist Test";
    this -> name = "Melodie Test";
    this -> duration = 0.00;
    this -> nrFeats = 0;
    this -> feat = {"Colaborator 1, Colaborator 2"};
}


Song::Song(const int& year, const std::string& artistName, const std::string& name, const unsigned int& nrFeats, std::vector<std::string>&feat, double& duration) {
    this -> year = year;
    this -> artistName = artistName;
    this -> name = name;
    this -> nrFeats = nrFeats;
    this-> duration = duration;
    this -> feat = feat;
}


Song::Song(const Song &obiect) {
    this -> year = obiect.year;
    this -> artistName = obiect.artistName;
    this -> name = obiect.name;
    this -> nrFeats = obiect.nrFeats;
    this-> duration = obiect.duration;
    this -> feat = obiect.feat;
}

Song::~Song() {}


//functia de afisare

void Song::afis(int index) {
    std::cout << index << ". \"" << name << "\" by " << artistName;

    if (nrFeats > 0) {
        std::cout << " feat. ";
        for (int i = 0; i < nrFeats; ++i) {
            std::cout << feat[i];
            if (i != nrFeats - 1)
                std::cout << ", ";
        }
    }

    std::cout << " | " << year << " | " << std::fixed << std::setprecision(2) << duration << " min\n";
}


//supraincarcarea operatorului <<
std::ostream &operator<<(std::ostream &os, const Song &melodie) {
    os << melodie.name << " - "<< melodie.artistName<< " ("<< melodie.year<< ")"<<" ";
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

// adaug spatii pentru afisarea duratei
    os << std::setw(15) << durataStr << "\n";


    return os;
}


//supraincarcarea >>
std::istream &operator>>(std::istream &is, Song &song) {
    std::cout << "Type the name of the song: ";
    std::getline(is, song.name);

    std::cout << "Type the name of the artist: ";
    std::getline(is, song.artistName);

    std::cout << "Type the year of the song: ";
    is >> song.year;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Type the duration of the song: ";
    is >> song.duration;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Type the number of feats: ";
    is >> song.nrFeats;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // stergerea vechilor feat-uri
    song.feat.clear();
    if (song.nrFeats > 0) {
        for (int i = 0; i < song.nrFeats; i++) {
            std::cout << "Type the feat #" << (i + 1) << ": ";
            std::string feat;
            std::getline(is, feat);
            song.feat.push_back(feat);
        }
    }

    return is;
}



//getters
std::string Song::getTitle()const{
    return name;
}
//std::string Song::getLanguage() const {
//    return language;
//}
std::vector<std::string> Song::getFeat() const {  // std::string getFeat() const;
    return feat;  //am modificat aici
}

int Song::getYear() const {
    return year;
}

std::string Song::getArtistName() const{
    return artistName;
}

double Song::getDuration() const {
    return duration;
}



//setters
void Song::setTitle(std::string& name) {
    this -> name = name;
}
//void Song::setLanguage(std::string& language) {
//    this -> language = language;
//}
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






// read from csv
void Song::readFromCSV(const std::string &line) {
    std::stringstream ss(line);
    std::string token;

    // song name
    std::getline(ss, name, ',');

    // artist name
    std::getline(ss, artistName, ',');

    // all feats in one string
    std::string featsStr;
    std::getline(ss, featsStr, ',');

    // year
    std::getline(ss, token, ',');
    try {
        year = std::stoi(token);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid year: " << token << std::endl;
        year = 0;
    }

    // duration
    std::getline(ss, token, ',');
    try {
        duration = std::stod(token);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid duration: " << token << std::endl;
        duration = 0.0;
    }

    // nr feats
    feat.clear();
    std::stringstream featsStream(featsStr);
    std::string featItem;
    while (std::getline(featsStream, featItem, ';')) {
        feat.push_back(featItem);
    }
    nrFeats = feat.size();
}



