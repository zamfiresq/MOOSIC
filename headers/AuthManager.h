//
// Created by Alexandra Zamfirescu on 26.07.2025.
//

// login si signup pentru utilizatori


#ifndef OOP_PROJECT_AUTHMANAGER_H
#define OOP_PROJECT_AUTHMANAGER_H

#include <string>

class User;

class AuthManager {
public:
    User* login();
    User* signup();
};

#endif //OOP_PROJECT_AUTHMANAGER_H
