//
// Created by Alexandra Zamfirescu on 23.03.2023.
//

#ifndef OOP_PROJECT_USER_H
#define OOP_PROJECT_USER_H
#include <iostream>
#include "Playlist.h"
#include "myString.h"
#include <vector>

class User {
    myString username;
    myString password;
    myString email;
    myString country;
    myString birthDate;

    bool subscription = false; //
    std::vector<Playlist> playlists; //alocare dinamica stl

public:
    User(); //constructor fara parametri
    User(myString username, myString password, myString email, myString country, myString birthDate, bool subscription, std::vector<Playlist>& playlists); //constructor cu parametri
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
        this -> subscription = other.subscription; //
        this -> playlists = other.playlists; //

        return *this;
    }


    //supraincarcarea operatorului << // de modificat si aici;
    friend std::ostream& operator << (std::ostream &os, const User &obj) {
        os <<"Username: " <<obj.username << "\n ";
        os <<"Password: " <<obj.password <<"\n ";
        os<<"E-mail: "  << obj.email <<"\n ";
        os<<"Country: " <<obj.country << "\n ";
        os<<"Birth date: " << obj.birthDate << "\n";


        if(obj.subscription == true) {
            os << "Subscription: " << "Valid" << "\n";
            os << "Playlists: " << "\n";
            for (int i = 0; i < obj.playlists.size(); i++)
                os << obj.playlists[i] << " ";

        }else{
            os << "Subscription: " << "Not valid" << "\n";
            os<<"Playlists: " << "No playlists" << "\n";


        }
        return os;
    }

    //functionalitati

    void addFavorite(const std::vector<Playlist> &playlist);
    void removeFavorite(const std::vector<Playlist> &playlist);
    void showFavorites() const;
    void setUserName(const myString &newUsername);
    void setPassword(const myString &newPassword);
    void setEmail(const myString &newEmail);

    void setSubscription(const bool& status); //


};


#endif //OOP_PROJECT_USER_H
