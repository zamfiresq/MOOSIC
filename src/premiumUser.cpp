//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#include "../headers/premiumUser.h"


premiumUser::premiumUser() {}

premiumUser::premiumUser(const std::string& username, const std::string& password, const std::string& email,
                         const std::string& country, const std::string& birthDate, const std::vector<Playlist>& playlists, bool premiumSubscription)
        : User(username, password, email, country, birthDate, playlists), Premium(premiumSubscription) {}


premiumUser::premiumUser(const premiumUser &obj) : User(obj), Premium(obj) {}

//operatorul <<
std::ostream& operator << (std::ostream &os, const premiumUser &obj) {
    os << dynamic_cast<const User&>(obj);

        if(obj.hasPremiumSubscription()==false){
            os<<" Premium subscription:(0) "<<"N AVEM ASA CEVA CA ESTI SARAC LIPIT\n";
            os<<" Playlists: "<<"Mai ai si pretentia sa ti le afisez?";
        }else{
            os<<" Premium subscription:(1) "<<"ASA DA VTM ESTI PE OPULENTZA\n\n";
            os<<"Uite aici coroana ta rege: \n\n\n";


                //creatzie
                for (int i = 1; i <= 5; i++) {
                    for (int k = 1; k <= i; k++) {
                        std::cout<<" ";
                    }
                    for (int j = 1; j <= i; j++) {
                        std::cout<<"*";
                    }
                    for (int k = 1; k <= 3 * (4 - i + 1); k++) {
                        std::cout<<" ";
                    }
                    for (int j = 1; j <= 2 * i - 1; j++) {
                        std::cout<<"*";
                    }
                    for (int k = 1; k <= 3 * (4 - i + 1); k++) {
                        std::cout<<" ";
                    }
                    for (int j = 1; j <= i; j++) {
                        std::cout<<"*";
                    }
                    std::cout<<"\n";
                }
                for (int i = 1; i <= 2; i++) {
                    for (int k = 1; k <= 5 + i - 1; k++) {
                        std::cout<<" ";
                    }
                    for (int j = 1; j <= 2 * (9 - i + 1) + 1; j++) {
                        std::cout<<  "*";
                    }
                    std::cout<<"\n";
                }

            os<<"\n\n";
            os <<" Playlists: \n\n";
            for(int i = 0; i < obj.getPlaylists().size(); i++)
                os<< (obj.getPlaylists())[i]<<"\n";
        }

    return os;
}

void premiumUser::removeAd() {
    if (hasPremiumSubscription()) {
        std::cout<< "Ads have been removed for premium users." << "\n";
    }
    else {
        std::cout<< "Upgrade to premium to remove ads." << "\n";
    }
}
