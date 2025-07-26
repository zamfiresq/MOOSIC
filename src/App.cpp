//
// Created by Alexandra Zamfirescu on 26.07.2025.
//

#include "App.h"
#include <iostream>

App::App() {
    currentUser = nullptr;
}

void App::run() {
    int choice;
    while (true) {
        // meniul principal (login/signup/exit)
        showWelcome();
        std::cout << "1. Login\n2. Sign up\n3. Exit\n> ";
        std::cin >> choice;

        if (choice == 3) {
            std::cout << "Goodbye!\n";
            break;  // iesire din aplicatie
        }

        if (choice == 1)
            currentUser = auth.login();
        else if (choice == 2)
            currentUser = auth.signup();
        else {
            std::cout << "❌ Invalid option.\n";
            continue;
        }

        // daca autentificarea merge
        if (currentUser != nullptr) {
            int userChoice;
            do {
                // meniul user logat
                showMainMenu();

                std::cout << "1. Logout\n> ";
                std::cin >> userChoice;

                switch (userChoice) {
                    case 1:
                        delete currentUser;
                        currentUser = nullptr;
                        std::cout << "Logged out.\n";
                        break;
                    default:
                        std::cout << "❌ Invalid option.\n";
                        break;
                }
            } while (currentUser != nullptr);
        }
    }
}

void App::showWelcome() {
    std::cout << std::endl;
    std::cout << "Welcome to\n";
    std::cout << "\033[1;35m";  // magenta
    std::cout << R"(
███    ███  ██████   ██████  ███████  ██   ██████
████  ████ ██    ██ ██    ██ ██       ██  ██
██ ████ ██ ██    ██ ██    ██ ███████  ██  ██
██  ██  ██ ██    ██ ██    ██      ██  ██  ██
██      ██  ██████   ██████  ███████  ██   ██████
)" << std::endl << std::endl;
    std::cout << "\033[0m";  // reset color
}

void App::showMainMenu() {
    std::cout << "\n\033[1;36m"; // cyan bright
    std::cout << "HELLO, " << (currentUser ? currentUser->getUsername() : "GUEST") << "!\n";
    std::cout << "\033[0m"; // reset color
    std::cout << "Main menu (under construction...)\n";
}