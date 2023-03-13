#include <iostream>
#include "headers/Song.h"

int main() {
//    std::cout << "Hello, Zamfi! <3" << std::endl;

    int nr = 3;

    std::string f[] = {"da", "nu", "ceplm"};

    Song melodiePulaMeaEDeHartie(2023, "Romana", nr, f);


    melodiePulaMeaEDeHartie.afis();
    std::cout << melodiePulaMeaEDeHartie;

//    unsigned int year;
//    unsigned int nrSongs;
//    Song *songs;

    Song mels[2] = {melodiePulaMeaEDeHartie, melodiePulaMeaEDeHartie};

    Album albumulMeu(2022, 2, mels);
    return 0;
}