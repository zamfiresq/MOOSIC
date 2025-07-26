//
// Created by Alexandra Zamfirescu on 26.07.2025.
//

#include "App.h"
#include "AuthManager.h"
#include "User.h"
#include "Playlist.h"
#include <iostream>
#include <fstream>
#include <sstream>


// helper pt a genera un nou ID pentru playlist
int generateNewPlaylistId() {
    std::ifstream file("data/playlists.csv");
    std::string line;
    int lastId = 0;

    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr;
        getline(ss, idStr, ',');
        try {
            int id = std::stoi(idStr);
            if (id > lastId) {
                lastId = id;
            }
        } catch (...) {
            continue;
        }
    }
    return lastId + 1;
}

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
            // Load playlists for current user from CSV
            std::ifstream playlistFile("data/playlists.csv");
            if (playlistFile.is_open()) {
                std::string line;
                while (getline(playlistFile, line)) {
                    std::stringstream ss(line);
                    std::string idStr, title, userIdStr;
                    getline(ss, idStr, ',');
                    getline(ss, title, ',');
                    getline(ss, userIdStr, ',');

                    try {
                        int userId = std::stoi(userIdStr);
                        if (userId == currentUser->getIdMax()) {
                            Playlist pl(title);  // folosim constructorul cu titlu
                            currentUser->addPlaylist(pl);
                        }
                    } catch (...) {
                        continue;
                    }
                }
                playlistFile.close();
            }
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
    std::cout << "                    Welcome to\n";
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

    int option;
    do {
        std::cout << "\n\033[1;35m"; // magenta bright
        std::cout << "\n===== MAIN MENU =====\n";
        std::cout << "\033[0m"; // reset color

        std::cout << "1. View my playlists\n";
        std::cout << "2. Create a new playlist\n";
        std::cout << "3. Logout\n";
        std::cout << "> ";
        std::cin >> option;

        switch (option) {
            case 1:
                // afisare playlist-uri
                {
                    std::ifstream playlistFile("../data/playlists.csv");
                    if (playlistFile.is_open()) {
                        std::string line;
                        while (getline(playlistFile, line)) {
                            std::stringstream ss(line);
                            std::string idStr, title, userIdStr;
                            getline(ss, idStr, ',');
                            getline(ss, title, ',');
                            getline(ss, userIdStr, ',');

                            try {
                                int userId = std::stoi(userIdStr);
                                if (userId == currentUser->getId()) {
                                    int id = std::stoi(idStr);
                                    Playlist pl(id, title);
                                    currentUser->addPlaylist(pl);
                                }
                            } catch (...) {
                                continue;
                            }
                        }
                        playlistFile.close();
                    }

                    if (currentUser->getPlaylists().empty()) {
                        std::cout << "No playlists yet 👀\n";
                    } else {
                        std::cout << "\033[1;34m"; // blue bright
                        std::cout << "\nYour Playlists:\n";
                        std::cout << "\033[0m"; // reset color

                        int index = 1;
                        for (const auto& playlist : currentUser->getPlaylists()) {
                            std::cout <<"#" << index++ << ". " << playlist.getTitle() << "\n";
                        }
                    }
                }
                break;


            // crearea unui playlist nou
            case 2: {
                std::string newPlaylistName;
                std::cout << "Enter a name for your new playlist: ";
                std::cin.ignore();
                std::getline(std::cin, newPlaylistName);
                int newId = generateNewPlaylistId();
                Playlist newPlaylist(
                    newId, newPlaylistName);
                currentUser->addPlaylist(newPlaylist);
                std::ofstream outFile("data/playlists.csv", std::ios::app);

                if (outFile.is_open()) {
                    outFile << newId << "," << newPlaylistName << "," << currentUser->getId() << "\n";
                    outFile.close();
                } else {
                    std::cerr << "[ERROR] Could not open playlists.csv for writing.\n";
                }
                std::cout << "[INFO] Playlist \"" << newPlaylistName << "\" created successfully!\n";
                break;
            }
            case 3:
                delete currentUser;
                currentUser = nullptr;
                std::cout << "Logged out.\n";
                return;
            default:
                std::cout << "❌ Invalid option. Try again.\n";
        }
    } while (currentUser != nullptr);
}