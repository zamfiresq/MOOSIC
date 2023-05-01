//
// Created by Alexandra Zamfirescu on 01.05.2023.
//

#include "../headers/Premium.h"


Premium::Premium() {
    this->premiumSubscription = false;
}

Premium::Premium(const bool &premiumSubscription) {
    this->premiumSubscription = premiumSubscription;
}

void Premium::setPremiumSubscription(const bool &status) {
    this->premiumSubscription = status;
}

bool Premium::hasPremiumSubscription() const {
    return this->premiumSubscription;
}



