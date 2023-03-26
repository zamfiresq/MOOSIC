//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#include "../headers/User.h"


//constructor fara parametri
User::User() {
    this->username = "username";
    this->password = "password";
    this->email = "email";
    this->country = "country";
    this->birthDate = "birthdate";
    this->favorites = nullptr;
}

//constructor cu parametri
User::User(myString username, myString password, myString email, myString country, myString birthDate, Playlist *favorites) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->country = country;
    this->birthDate = birthDate;

    if (favorites != nullptr) {
        this -> favorites = new Playlist[1];
        this -> favorites[0] = favorites[0];
    } else {
        this -> favorites = nullptr;
    }
}

//copy constructor
User::User(const User &obj) {
    this -> username = obj.username;
    this -> password = obj.password;
    this -> email = obj.email;
    this -> country = obj.country;
    this -> birthDate = obj.birthDate;
    this -> favorites = obj.favorites;
}

//destructor
User::~User() {
//    if (this -> favorites != nullptr) {
//        delete[] this -> favorites;
//    }
}

//functie de afisare
void User::afisare() const{
    std::cout << username << " " << password << " " << email << " " << country << " " << birthDate << "\n";

    for(int i = 0; i < 5; i++)
        std::cout << favorites[i] << " ";
}

//functionalitati
//functie care adauga un playlist in lista de favorite
void User::addFavorite(const Playlist &playlist) {
    if (this->favorites == nullptr) {
        this->favorites = new Playlist[1];
        this->favorites[0] = playlist;
    } else {
        Playlist *aux = new Playlist[this->favorites->getNrSongs() + 1];

        for (int i = 0; i < this->favorites->getNrSongs(); i++)
            aux[i] = this->favorites[i];

        aux[this->favorites->getNrSongs()] = playlist;

        delete[] this->favorites;
        this->favorites = aux;
    }
}


//functie care sterge un playlist din lista de favorite
void User::removeFavorite(const Playlist &playlist) {
    if (this->favorites != nullptr) {
        Playlist *aux = new Playlist[this->favorites->getNrSongs() - 1];

        int j = 0;
        for (int i = 0; i < this->favorites->getNrSongs(); i++) {
            if (this->favorites[i] != playlist) {
                aux[j] = this->favorites[i];
                j++;
            }
        }

        delete[] this->favorites;
        this->favorites = aux;
    }
}

//functie care afiseaza lista de favorite
void User::showFavorites() const {
    if (this->favorites != nullptr) {
        for (int i = 0; i < this->favorites->getNrSongs(); i++)
            std::cout << (this -> favorites)[i] << " ";
    }
}



//functie care seteaza o noua parola
void User::setPassword(const myString &newPassword) {
    this->password = newPassword;
    std::cout << "Parola a fost actualizată cu succes!" << "\n";
}

//functie care seteaza un nou email
void User::setEmail(const myString &newEmail) {
    this->email = newEmail;
    std::cout << "Email-ul a fost actualizat cu succes!" << "\n";
}


