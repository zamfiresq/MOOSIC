//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#ifndef OOP_PROJECT_PREMIUM_H
#define OOP_PROJECT_PREMIUM_H
#include <iostream>
#include <string>
#include "User.h"


//aceasta va fi o clasa care intra in alcatuirea mostenirii multiple "premiumUser"
class Premium{
private:
    bool premiumSubscription;

public:
    Premium();
    Premium(const bool& premiumSubscription);

    void setPremiumSubscription(const bool& status);

    bool hasPremiumSubscription() const;

    //supraincarcarea operatorului <<
    friend std::ostream& operator << (std::ostream &os, const Premium &obj) {
        os << "Premium subscription: " << obj.premiumSubscription << "\n";

        return os;
    }

};

#endif //OOP_PROJECT_PREMIUM_H
