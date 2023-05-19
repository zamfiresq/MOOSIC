//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#include "../headers/User.h"
#include "../headers/Playlist.h"

//variabila statica
unsigned int User::idMax = 0;


//constructor fara parametri
User::User() = default;


//constructor cu parametri
User::User(const std::string& username, const std::string& password, const std::string& email, const std::string& country, const std::string& birthDate, const std::vector<Playlist>& playlists) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->country = country;
    this->birthDate = birthDate;
    this->playlists = playlists;
    this->id = ++idMax;

}

//copy constructor - lista de initializare
    User::User(const User &obj) : username{obj.username}, password{obj.password}, email{obj.email},
                                  country{obj.country}, birthDate{obj.birthDate},
                                  playlists{obj.playlists} {
    }


//destructor
    User::~User() {}

//functie de afisare
    void User::afisare() const {
        std::cout << username << " " << password << " " << email << " " << country << " " << birthDate << "\n";

        for (int i = 0; i < playlists.size(); i++)
            std::cout << playlists[i] << " ";
    }


////functionalitati
////functie care adauga un playlist in lista de favorite
//void User::addFavorite(const std::vector<Playlist>& playlist) {
//    if (this->playlists == nullptr) {
//        this->playlists = new std::vector<Playlist>{playlist};
//    }
//    else {
//        this->playlists->push_back(playlist);
//    }
//}



////functie care sterge un playlist din lista de favorite
//    void User::removeFavorite(const std::vector<Playlist> &playlist) {
//        if (this->playlists != nullptr) {
//            Playlist *aux = new Playlist[this->playlists->getNrSongs() - 1];
//
//            int j = 0;
//            for (int i = 0; i < this->playlists->getNrSongs(); i++) {
//                if (this->playlists[i] != playlist) {
//                    aux[j] = this->playlists[i];
//                    j++;
//                }
//            }
//
//            delete[] this->playlists;
//            this->playlists = aux;
//        }
//    }
//
////functie care afiseaza lista de favorite
//    void User::showplaylists() const {
//        if (this->playlists != nullptr) {
//            for (int i = 0; i < this->playlists->getNrSongs(); i++)
//                std::cout << (this->playlists)[i] << " ";
//        }
//    }


//functie care seteaza o noua parola
    void User::setPassword(const std::string &newPassword) {
        this->password = newPassword;
        std::cout << "Parola a fost actualizată cu succes!" << "\n";
    }

//functie care seteaza un nou email
    void User::setEmail(const std::string &newEmail) {
        this->email = newEmail;
        std::cout << "Email-ul a fost actualizat cu succes!" << "\n";
    }

    //getters
    std::string User::getUsername() const {
        return this->username;
    }

    std::string User::getPassword() const {
        return this->password;
    }

    std::string User::getEmail() const {
        return this->email;
    }

    std::string User::getCountry() const {
        return this->country;
    }

    std::string User::getBirthDate() const {
        return this->birthDate;
    }

    std::vector<Playlist> User::getPlaylists() const {
        return this->playlists;
    }

//pentru static
    unsigned int User::getIdMax() {
        return idMax;
    }


void User::setId( unsigned int &newId) {
    this->id = newId;
    if(newId > idMax)
        idMax = ++newId;
    std::cout<<id<<"\n";
    std::cout<<idMax<<"\n";
}

// 06/04/2002
int User::getYear() const{
    std::string an;
    for(int i = 6; i <= 9; i++)
        an.push_back(birthDate[i]);

    return std::stoi(an);
}
