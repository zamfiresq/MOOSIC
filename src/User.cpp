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
User::User(const std::string& username, const std::string& password, const std::string& email, const std::string& country, const std::string& birthDate, const std::vector<Playlist>& playlists, bool isPremium) {
    this->username = username;
    this->password = password;
    this->email = email;
    this->country = country;
    this->birthDate = birthDate;
    this->playlists = playlists;
    this->isPremium = isPremium;
    this->id = ++idMax;
}

// constructor simplificat cu id, username, email, isPremium
User::User(unsigned int id, const std::string& username, const std::string& email, bool isPremium) {
    this->id = id;
    this->username = username;
    this->email = email;
    this->isPremium = isPremium;
    if (id > idMax) idMax = id;
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

int User::getYear() const{
    std::string an;
    for(int i = 6; i <= 9; i++)
        an.push_back(birthDate[i]);

    return std::stoi(an);
}

bool User::getIsPremium() const {
    return this->isPremium;
}

void User::setIsPremium(bool premiumStatus) {
    this->isPremium = premiumStatus;
}