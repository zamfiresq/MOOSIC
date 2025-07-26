//
// Created by Alexandra Zamfirescu on 23.03.2023.
//


#ifndef OOP_PROJECT_USER_H
#define OOP_PROJECT_USER_H
#include <iostream>
#include "Playlist.h"
#include "AuthManager.h"
#include <string>
#include <vector>

class User {
    std::string username;
    std::string password;
    std::string email;
    std::string country;
    std::string birthDate;
    static unsigned int idMax;
    unsigned int id;

    // daca userul are cont premium sau nu
    bool isPremium = false;
    std::vector<Playlist> playlists;

public:
    User(); //constructor fara parametri

    User(const std::string& username, const std::string& password, const std::string& email, const std::string& country, const std::string& birthDate, const std::vector<Playlist>& playlists, bool isPremium = false);
    User(const User &obj); //copy constructor

    User(unsigned int id, const std::string& username, const std::string& email, bool isPremium = false);

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
        //this -> subscription = other.subscription; //
        this -> playlists = other.playlists; //
        this -> id = other.id;
        return *this;
    }

    void addPlaylist(const Playlist& playlist) {
        playlists.push_back(playlist);
    }

    //supraincarcarea operatorului <<
    friend std::ostream& operator << (std::ostream &os, const User &obj) {
        os << " Username: " << obj.username << "\n ";
        os << "Password: " << obj.password << "\n ";
        os << "E-mail: " << obj.email << "\n ";
        os << "Country: " << obj.country << "\n ";
        os << "Birth date: " << obj.birthDate << "\n";

        return os;
    }

    //supraincarcarea operatorului >>
    friend std::istream& operator >> (std::istream &is, User &obj) {
        std::cout << "Username: ";
        is >> obj.username;
        std::cout << "Password: ";
        is >> obj.password;
        std::cout << "E-mail: ";
        is >> obj.email;
        std::cout << "Country: ";
        is >> obj.country;
        std::cout << "Birth date: ";
        is >> obj.birthDate;

        return is;
    }

    //functionalitati

    void addFavorite(const std::vector<Playlist> &playlist);
    void removeFavorite(const std::vector<Playlist> &playlist);
    void showFavorites() const;
    void setUserName(const std::string &newUsername);
    void setPassword(const std::string &newPassword);
    void setEmail(const std::string &newEmail);


    //getters
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
    std::string getCountry() const;
    std::string getBirthDate() const;
    std::vector<Playlist> getPlaylists() const;
    int getYear() const;

    bool getIsPremium() const;

    void setIsPremium(bool premiumStatus);




//pentru static
static unsigned int getIdMax();
void setId(unsigned int &newId);

};


#endif //OOP_PROJECT_USER_H
