#include <iostream>

#include "headers/Album.h"

int main() {
//    std::cout << "Hello, Zamfi! <3" << std::endl;

    int nr = 3;

    std::string f[] = {"da", "nu", "ceplm"};

    std::string limba = "Romana";
    int an = 2023;

    Song melodieProba(an, limba, nr, f);

    Song melodieplm(melodieProba);

    melodieProba.afis();
    melodieplm.afis();

    std::cout << melodieProba;

//    unsigned int year;
//    unsigned int nrSongs;
    std::cout << &melodieProba << std::endl;
    Song *mels;
    mels = &melodieProba;
    std::cout << mels;


    Album albumulMeu(2022, 1, mels);
    albumulMeu.afis();

//    int *p;
//    std::cout << &p << std::endl;
//    p = new int[6];
//
//    for (int i = 0; i < 6; i++)
//        *(p + i) = i; // p[i] = i; /// *(p + i) -----> p[i]
    return 0;
}