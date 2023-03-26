#include <iostream>
#include "headers/Song.h"
#include "headers/Artist.h"
#include "headers/Album.h"
#include "headers/Playlist.h"


int main(){


    myString obiect = "numeAlbum";
    myString obiect1 = "nameAlbum";
//    std::cout << (obiect > obiect1);
    int valoare = 5;
//    std::cout << obiect;
//    obiect.afis();

//    Song cantec;
//    std::cout << cantec;

    myString obiect4 = "feat";

    myString* da;
    da = new myString[5];

    for(int i = 0; i < 5; i++)
        da[i] = obiect4;

//    *da = obiect; //da[0]
//    *(da + 1) = obiect; // da[1]
//    *(da + 2) = obiect; // da[2]
//    ....................

//    myString nu[5]; // echivalent pentru ce e mai sus
//    for(int i = 0; i < 5; i++)
//        nu[i] = obiect;

    Song cantec1(2023, obiect, obiect, valoare, da);
//    std::cout << cantec1;


    int an = 2022;
    Song* v;
    v = new Song[valoare];

    myString obiect2 = "numeCantec";
    myString obiect3 = "limba";
    Song cantec2(2023, obiect2, obiect3, valoare, da);
//    *v = cantec2;
    for(int i = 0; i < valoare; i++)
        v[i] = cantec2;
    Album album1(an, obiect, valoare, v);
//    std::cout<< album1;


//    myString firstName;
//    myString lastName;
//    myString nickname;
//    myString nationality;
//    myString *languages;
//    int nrLanguages;
//    Album *albums;
//    int nrAlbums;
//    Song *solo;
//    int nrSongs;

    myString firstName = "first name";
    myString lastName = "last name";
    myString nickname = "nickname";
    myString nationality = "nationality";
    int nr = 4;
    int nr1 = 5;
    int nr2 = 3;

    myString* l;
    l = new myString[nr];

    for(int i = 0; i < nr; i++)
        l[i] = "limba";
//    *l = "limba";

    Album* al;
    al = new Album[nr1];

    for(int i = 0; i < nr1; i++)
        al[i] = album1;



    Song* s;
    s = new Song[nr2];

    for(int i = 0; i < nr2; i++)
        s[i] = cantec2;

    Artist donToliver(firstName, lastName, nickname, nationality, l, nr, al, nr1, s, nr2 );
//    std::cout<<donToliver;

//    Playlist(const myString& title, Song *songs, const int& nrSongs, Album *albums, const int& nrAlbums, const int& duration);
    myString titlup = "titlu playlist";
    int d = 150;

    Album a;
    Playlist plm(titlup, s, nr2, al, nr1, 150);
//    plm.afisare();
//    plm.addSong(cantec1);
//    plm.addAlbum(a);
//    plm.addAlbum(album1);
//
//
//    plm.afisare();
//    plm.removeSong(cantec1);
//    plm.removeAlbum(a);
//    plm.afisare();

plm.play(2);

    return 0;
}