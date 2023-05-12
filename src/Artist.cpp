//
// Created by Alexandra Zamfirescu on 13.03.2023.
//

#include "../headers/Album.h"
#include "../headers/Artist.h"



//constructor fara parametri
Artist::Artist() {
    this -> fullName = "fullName";
    this -> nationality = "nationality";
    this -> nrLanguages = 0;
    this -> nrAlbums = 0;
    this -> nrSongs = 0;
    this -> languages = {};
    this -> albums = {};
    this -> solo = {};
}

//constructor cu parametri
//Artist(const std::string &fullName, const std::string &nickname, const std::string &nationality, const std::vector<std::string>&languages, const int &nrLanguages, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs);
Artist::Artist(const std::string &fullName, const std::string &nationality, const std::vector<std::string>&languages, const int &nrLanguages, std::vector<Album>&albums, const int &nrAlbums, std::vector<Song>&solo, const int &nrSongs) {
    this->fullName = fullName;
    this->nationality = nationality;
    this->nrSongs = nrSongs;
    this->nrLanguages = nrLanguages;
    this->nrAlbums = nrAlbums;
    this->languages = languages;
    this->albums = albums;
    this->solo = solo;
}

//copy constructor
    Artist::Artist(const Artist &obiect){
        this->fullName = obiect.fullName;
        this->nationality = obiect.nationality;
        this->nrLanguages = obiect.nrLanguages;
        this->nrAlbums = obiect.nrAlbums;
        this->nrSongs = obiect.nrSongs;
        this->languages = obiect.languages;
        this->albums = obiect.albums;
        this->solo = obiect.solo;

    }

//destructor
    Artist::~Artist() {}

//afisare
    void Artist::afis() const {
        std::cout << fullName << " " << nationality << " " << nrLanguages
                  << " " << nrAlbums << " " << nrSongs << "\n";

        for (int i = 0; i < nrLanguages; i++)
            std::cout << languages[i] << " ";
        std::cout << "\n";

        for (int i = 0; i < nrAlbums; i++)
            std::cout << albums[i];
        std::cout << "\n";

        for (int i = 0; i < nrSongs; i++)
            std::cout << solo[i] << " ";
        std::cout << "\n";
    }


//operator <<
    std::ostream &operator<<(std::ostream &os, const Artist &artist) {
        os << artist.fullName << " " << artist.nationality << " "
           << artist.nrLanguages << " " << artist.nrSongs << " " << artist.nrAlbums << "\n";

        if (artist.nrLanguages) {
            os << "Limbi vorbite:\n";
            for (int i = 0; i < artist.nrLanguages; i++)
                os << i + 1 << ". " << artist.languages[i] << "\n";
            os << "\n";
        }

        if (artist.nrSongs) {
            os << "Solo-uri:\n";
            for (int i = 0; i < artist.nrSongs; i++)
                os << i + 1 << ". " << artist.solo[i] << "\n";
            os << "\n";
        }

        if (artist.nrAlbums) {
            os << "Albume:\n";
            for (int i = 0; i < artist.nrAlbums; i++)
                os << i + 1 << ". " << artist.albums[i];
            os << "\n";
        }

        return os;
    }



//getters si setters

//getter pentru full name
    std::string Artist::getFullName() const {
        return fullName;
    }
//setter pentru full name
    void Artist::setFullName(const std::string &fullName) {
        Artist::fullName = fullName;
    }

//getter pentru nationality
    std::string Artist::getNationality() const {
        return nationality;
    }
//setter pentru nationality
    void Artist::setNationality(const std::string &nationality) {
        Artist::nationality = nationality;
    }

//getter pentru nrLanguages
    int Artist::getNrLanguages() const {
        return nrLanguages;
    }
//setter pentru nrLanguages

//getter pentru nrSongs
    int Artist::getNrSongs() const {
        return nrSongs;
    }
//setter pentru nrSongs

//getter pentru nrAlbums
    int Artist::getNrAlbums() const {
        return nrAlbums;
    }
