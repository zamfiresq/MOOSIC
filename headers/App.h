//
// Created by Alexandra Zamfirescu on 26.07.2025.
//

// pagina de pornire a aplicatiei

#ifndef APP_H
#define APP_H

#include "AuthManager.h"
#include "User.h"

class App {
private:
    User* currentUser;
    AuthManager auth;

    void showWelcome();
    void showMainMenu();
public:
    App();
    void run();  // punctul de pornire
};

#endif
