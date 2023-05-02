//
// Created by Alexandra Zamfirescu on 02.05.2023.
//

#include <iostream>
#include "../headers/Exceptions.h"

invalid_credit_card::invalid_credit_card(const std::string& message)
        : errorInput(message) {}


// verificam daca un numar de card este valid
bool validare_card(const std::string& numar_card) {
    // Verificăm dacă numărul cardului are 16 caractere
    if (numar_card.length() != 16) {
        return false;
    }

    //verificam daca numarul cardului contine doar cifre
    for (auto c : numar_card) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Verificăm dacă numărul cardului este valid folosind algoritmul Luhn
    int sum = 0;
    for (int i = 0; i < 16; i++) {
        int digit = numar_card[i] - '0';

        if (i % 2 == 0) {
            digit *= 2;

            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
    }

    return (sum % 10 == 0);
}

// efectuam plata
void efectuare_plata(const std::string& numar_card) {
    if (!validare_card(numar_card)) {
        throw invalid_credit_card("Cardul de credit nu este valid sau a expirat.");
    }

    std::cout << "Plata a fost efectuata cu succes pentru numarul de card " << numar_card << "\n";
}

//exceptie pentru adaugare playlist cu acelasi nume
PlaylistWithSameName::PlaylistWithSameName(const std::string& message)
        : errorInput(message) {}

//exceptie pentru artist not found
ArtistNotFound::ArtistNotFound(const std::string& artistName)
        : errorInput("Artistul " + artistName + " nu a fost gasit."), artistName(artistName) {

}
