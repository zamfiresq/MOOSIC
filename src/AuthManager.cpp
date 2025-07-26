//
// Created by Alexandra Zamfirescu on 26.07.2025.
//

#include "AuthManager.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
#include <iomanip>
#include <openssl/sha.h>
#include <termios.h>
#include <unistd.h>

const std::string USERS_FILE = "/Users/alexandrazamfirescu/CLionProjects/oop-project/data/users.csv";

// helper pt a elimina spatiile
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == std::string::npos) ? "" : str.substr(first, last - first + 1);
}

// verifica daca username sau email exista deja
bool isUserExists(const std::string& username, const std::string& email) {
    std::ifstream file(USERS_FILE);
    if (!file.is_open()) {
        return false;
    }
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, name, mail, hashedPass, isPremiumStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, mail, ',');
        // nu conteaza parola/isPremium aici
        if (trim(name) == trim(username) || trim(mail) == trim(email)) {
            return true;
        }
    }
    return false;
}

// citeste parola mascata de la consola (Linux/macOS)
std::string getPassword() {
    std::string password;
    struct termios oldt, newt;
    std::cout << "Password: ";
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::getline(std::cin, password);
    if (password.empty()) std::getline(std::cin, password);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    std::cout << std::endl;
    return password;
}

// functie pt sha-256 hashing cu openssl
std::string sha256(const std::string& str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

// validatoare
bool isValidPassword(const std::string& password) {
    if (password.length() < 8) return false; // minim 8 caractere
    if (!std::regex_search(password, std::regex("[A-Z]"))) return false; // cel putin o litera mare
    if (!std::regex_search(password, std::regex("[0-9]"))) return false; // cel putin o cifra
    return true;
}


User* AuthManager::login() {
    std::string username, password;
    std::cout << "\nLOGIN\nUsername: ";
    std::cin >> username;
    // elimina newline ramas de la std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    password = getPassword();

    std::string hashedPassword = sha256(password);

    std::ifstream file(USERS_FILE);
    if (!file.is_open()) {
        std::cerr << "❌ Failed to open users file.\n";
        return nullptr;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string idStr, name, mail, hashedPass, isPremiumStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, mail, ',');
        getline(ss, hashedPass, ',');
        getline(ss, isPremiumStr, ',');

        if (trim(name) == username && trim(hashedPass) == hashedPassword) {
            int id = std::stoi(idStr);
            bool isPremium = (isPremiumStr == "true");
            std::cout << "✅ Login successful!\n";
            return new User(id, name, mail, isPremium);
        }
    }

    std::cout << "❌ User not found or incorrect password.\n";
    return nullptr;
}

User* AuthManager::signup() {
    std::string username, email, password;
    std::cout << "\nSIGN UP\nChoose a username: ";
    std::cin >> username;
    std::cout << "Email: ";
    std::cin >> email;
    // elimina newline ramas de la std::cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // verifica daca userul exista deja
    if (isUserExists(username, email)) {
        std::cout << "❌ Username or email already exists. Please try another.\n";
        return nullptr;
    }

    // parola cu validare
    while (true) {
        std::cout << "Choose a password (min 8 chars, 1 uppercase, 1 digit): ";
        password = getPassword();
        if (isValidPassword(password)) {
            break;
        } else {
            std::cout << "❌ Password too weak. Try again.\n";
        }
    }

    std::string hashedPassword = sha256(password);

    std::ifstream inFile(USERS_FILE);
    std::string line;
    int lastId = 0;

    // ia ultimul ID din fisier
    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string idStr;
        getline(ss, idStr, ',');
        lastId = std::stoi(idStr);
    }

    int newId = lastId + 1;
    bool isPremium = false;

    std::ofstream outFile(USERS_FILE, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "❌ Failed to open users file.\n";
        return nullptr;
    }

    outFile << newId << "," << username << "," << email << "," << hashedPassword << "," << (isPremium ? "true" : "false") << "\n";
    outFile.close();

    std::cout << "✅ Sign up successful! You are now logged in.\n";
    return new User(newId, username, email, isPremium);
}