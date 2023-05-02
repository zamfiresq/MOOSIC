//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#ifndef OOP_PROJECT_PREMIUMUSER_H
#define OOP_PROJECT_PREMIUMUSER_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Premium.h"
#include "Playlist.h"

class premiumUser : public User, public Premium {
public:
    // Constructori
    premiumUser();
    premiumUser(const std::string& username, const std::string& password, const std::string& email,
                const std::string& country, const std::string& birthDate, const std::vector<Playlist>&playlists, bool premiumSubscription);

    premiumUser(const premiumUser &obj); // copy constructor

    //operatorul <<
    friend std::ostream& operator << (std::ostream &os, const premiumUser &obj);

    // Metode suplimentare
    void removeAd();
};



#endif //OOP_PROJECT_PREMIUMUSER_H
