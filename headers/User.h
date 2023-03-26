//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#ifndef OOP_PROJECT_USER_H
#define OOP_PROJECT_USER_H
#include <iostream>
#include "Playlist.h"
#include "myString.h"

class User {
    myString username;
    myString password;
    myString email;
    myString country;
    myString birthDate;
    Playlist *favorites;

public:
    User(); //constructor fara parametri
    User(myString username, myString password, myString email, myString country, myString birthDate, Playlist *favorites); //constructor cu parametri
    User(const User &obj); //copy constructor

    //destructor
    ~User();

    //functie de afisare
    void afisare() const;

    //supraincarcarea operatorului =
    User& operator = (const User &other) {
        this -> username = other.username;
        this -> password = other.password;
        this -> email = other.email;
        this -> country = other.country;
        this -> birthDate = other.birthDate;
        this -> favorites = other.favorites;
        return *this;
    }


    //supraincarcarea operatorului <<
    friend std::ostream& operator << (std::ostream &os, const User &obj) {
        os << obj.username << " " << obj.password << " " << obj.email << " " << obj.country << " " << obj.birthDate << "\n";
        return os;
    }

    //functionalitati
    void addFavorite(const Playlist &playlist);
    void removeFavorite(const Playlist &playlist);
    void showFavorites() const;
    void setPassword(const myString &newPassword);
    void setEmail(const myString &newEmail);

};


#endif //OOP_PROJECT_USER_H
