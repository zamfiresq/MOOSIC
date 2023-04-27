#include <iostream>
#include <vector>
#include<string>
#include "headers/Artist.h"
#include "headers/Album.h"
#include "headers/Song.h"
#include "headers/Playlist.h"
#include "headers/User.h"
#include "headers/playlistFavorite.h"


int main(){

////datele pentru clasa User
////myString username = "zamfiresq";
////myString password = "password";
////myString email = "zamfiresq@moomusic.com";
////myString country = "Romania";
////myString birthDate = "06.04.2002";
//
//
//
////datele pentru clasa Song
//
////melodii pentru album 1
////melodie 1
//int yearS1 = 2023;
//myString nameS1 = "Intenții";
//myString languageS1 = "Română";
//unsigned int nrFeatsS1 = 0;
//myString* featS1;
//featS1 = new myString[0];
//featS1[0] = "NO FEATS";
//
//
////melodie 2
//myString nameS2 = "Secrete";
//
////melodie 3
//myString nameS3 = "Nu Pot Să Nu Pot";
//
////melodie 4
//myString nameS4 = "Responsabilități";
//
////melodie 5
//myString nameS5 = "Scopul";
//
////melodie 6
//myString nameS6 = "Gata Să Mor";
//
////melodie 7
//myString nameS7 = "Tentații";
//
////melodie 8
//myString nameS8 = "Cu Cine Crezi Că Vorbești";
//
////melodie 9
//myString nameS9 = "D***uri Sau Vise";
//
////melodie 10
//myString nameS10 = "Asumă-ți";
//
////melodie 11
//myString nameS11 = "Doar mă consum";
//
////melodie 12
//myString nameS12 = "Prea Târziu";
//
//
//
////melodii pentru album 2
////melodie 13
//int yearS2 = 2020;
//myString nameS13 = "Apă";
//unsigned int nrFeatsS2 = 1;
//myString* featS2;
//featS2 = new myString[nrFeatsS2];
//featS2[0] = "Amuly";
//
////melodie 14
//myString nameS14 = "Tunechi";
//myString* featS3;
//featS3 = new myString[nrFeatsS2];
//featS3[0] = "Ian";
//
////melodie 15
//myString nameS15 = "Lacrimi";
//
////melodie 16
//myString nameS16 = "Ce Suntem?";
//myString* featS4;
//unsigned int nrFeatsS3 = 3;
//featS4 = new myString[nrFeatsS3];
//featS4[0] = "Ian";
//featS4[1] = "NANE";
//featS4[2] = "Super Ed";
//
////melodie 17
//myString nameS17 = "Gheață";
//myString* featS5;
//featS5 = new myString[nrFeatsS2];
//featS5[0] = "NANE";
//
////melodie 18
//myString nameS18 = "Fix Ce Lipsea";
//
////melodie 19
//myString nameS19 = "Timpu' Zboară";
//myString* featS6;
//featS6 = new myString[nrFeatsS2];
//featS6[0] = "Deliric";
//
////melodie 20
//myString nameS20 = "Aripi";
//myString* featS7;
//featS7 = new myString[nrFeatsS2];
//featS7[0] = "Amuly";
//
////melodie 21
//myString nameS21 = "Venă";
//myString* featS8;
//featS8 = new myString[nrFeatsS2];
//featS8[0] = "Ian";
//
////melodie 22
//myString nameS22 = "Oriunde Mă duc";
//myString* featS9;
//featS9 = new myString[nrFeatsS2];
//featS9[0] = "Ian";
//
////melodie 23
//myString nameS23 = "Ultima(Ploaie)";
//
////melodie 24
//myString nameS24 = "Good Job";
//
////melodie 25
//int yearS3 = 2022;
//myString nameS25 = "Prophet";
//
////melodie 26
//myString nameS26 = "Sin City";
//
////melodie 27
//myString nameS27 = "Astă-seară";
//
////melodie28
//int yearS4 = 2018;
//myString nameS28 = "Scuză-mă";
//
//
////apelam constructorii clasei Song
//Song melodie1(yearS1, nameS1, languageS1, nrFeatsS1, featS1);
//Song melodie2(yearS1, nameS2, languageS1, nrFeatsS1, featS1);
//Song melodie3(yearS1, nameS3, languageS1, nrFeatsS1, featS1);
//Song melodie4(yearS1, nameS4, languageS1, nrFeatsS1, featS1);
//Song melodie5(yearS1, nameS5, languageS1, nrFeatsS1, featS1);
//Song melodie6(yearS1, nameS6, languageS1, nrFeatsS1, featS1);
//Song melodie7(yearS1, nameS7, languageS1, nrFeatsS1, featS1);
//Song melodie8(yearS1, nameS8, languageS1, nrFeatsS1, featS1);
//Song melodie9(yearS1, nameS9, languageS1, nrFeatsS1, featS1);
//Song melodie10(yearS1, nameS10, languageS1, nrFeatsS1, featS1);
//Song melodie11(yearS1, nameS11, languageS1, nrFeatsS1, featS1);
//Song melodie12(yearS1, nameS12, languageS1, nrFeatsS1, featS1);
//
//Song melodie13(yearS2, nameS13, languageS1, nrFeatsS2, featS2);
//Song melodie14(yearS2, nameS14, languageS1, nrFeatsS2, featS3);
//Song melodie15(yearS2, nameS15, languageS1, nrFeatsS1, featS1);
//Song melodie16(yearS2, nameS16, languageS1, nrFeatsS3, featS4);
//Song melodie17(yearS2, nameS17, languageS1, nrFeatsS2, featS5);
//Song melodie18(yearS2, nameS18, languageS1, nrFeatsS1, featS1);
//Song melodie19(yearS2, nameS19, languageS1, nrFeatsS2, featS6);
//Song melodie20(yearS2, nameS20, languageS1, nrFeatsS2, featS7);
//Song melodie21(yearS2, nameS21, languageS1, nrFeatsS2, featS8);
//Song melodie22(yearS2, nameS22, languageS1, nrFeatsS2, featS9);
//Song melodie23(yearS2, nameS23, languageS1, nrFeatsS1, featS1);
//
//Song melodie24(yearS1, nameS24, languageS1, nrFeatsS1, featS1);
//Song melodie25(yearS3, nameS25, languageS1, nrFeatsS1, featS1);
//Song melodie26(yearS2, nameS26, languageS1, nrFeatsS1, featS1);
//Song melodie27(yearS2, nameS27, languageS1, nrFeatsS1, featS1);
//Song melodie28(yearS4, nameS28, languageS1, nrFeatsS1, featS1);
//
////datele pentru clasa Album
////album 1
//int yearA1 = 2023;
//myString nameA1 = "Ștefan III(Deluxe Version)";
//unsigned int nrSongs1 = 12;
//Song *v1 = new Song[nrSongs1];
//v1[0] = melodie1;
//v1[1] = melodie2;
//v1[2] = melodie3;
//v1[3] = melodie4;
//v1[4] = melodie5;
//v1[5] = melodie6;
//v1[6] = melodie7;
//v1[7] = melodie8;
//v1[8] = melodie9;
//v1[9] = melodie10;
//v1[10] = melodie11;
//v1[11] = melodie12;
//
////for(int i = 0; i < nrSongs1; i++){
////    std::cout<<v1[i];
////}
//
//Album album1(yearA1, nameA1, nrSongs1, v1 );
//std::cout<<album1; //afisare primul album
//
//
////album 2
//int yearA2 = 2020;
//myString nameA2 = "Apă";
//unsigned int nrSongs2 = 11;
//Song *v2 = new Song[nrSongs2];
//v2[0] = melodie13;
//v2[1] = melodie14;
//v2[2] = melodie15;
//v2[3] = melodie16;
//v2[4] = melodie17;
//v2[5] = melodie18;
//v2[6] = melodie19;
//v2[7] = melodie20;
//v2[8] = melodie21;
//v2[9] = melodie22;
//v2[10] = melodie23;
//
//    Album album2(yearA2, nameA2, nrSongs2, v2 );
//    std::cout<<album2; //afisare al doilea album
//
////artist
//myString firstName = " ";
//myString lastName = " ";
//myString nickname = "OSKY";
//myString nationality = "romanian";
//int nrAlbums = 2;
//int nrSolo = 5;
//int nrLang = 0;
//myString* lang;
//lang = new myString[0];
//lang[0] = " ";
//
////vector de solo-uri
//Song *solo;
//solo = new Song[nrSolo];
//solo[0] = melodie24;
//solo[1] = melodie25;
//solo[2] = melodie26;
//solo[3] = melodie27;
//solo[4] = melodie28;
//
//
////vector de albume
//Album *al;
//al = new Album [nrAlbums];
//al[0] = album1;
//al[1] = album2;
//
//Artist oscar(firstName, lastName, nickname, nationality, lang, nrLang, al, nrAlbums, solo, nrSolo);
//std::cout<<oscar;
//
////variabile pentru clasa Playlist
//myString titluP = "Playlist #1";
//int durataP = 150;
//
//Playlist p1(titluP, solo, nrSolo, al, nrAlbums, durataP);
//
////functionalitati
//
//p1.repeatOne(1);
//p1.previous(1);
//std::cout<<p1;
//p1.removeSong(melodie28);
//p1.addSong(melodie1);
//std::cout<<p1;

//
    std::string obiect = "Cea mai frumi melodie";
//    std::string obiect1 = "A doua cea mai frumi melodie";
//  std::cout << (obiect > obiect1);

    int valoare = 4;
//    std::cout << obiect;
    std::string obiect4 = "feat1";
    std::string obiect5 = "feat2";
    std::string obiect6 = "feat3";
//
//

    Song cantec;
//    cantec.afis();

    std::vector<std::string> da;
//
    for(int i = 0; i < 3; i++)
        da.push_back(obiect4);

//

    Song cantec1(2023, obiect, obiect, valoare, da);
//    cantec1.afis();

//    std::vector<std::shared_ptr<Song>> cantece;
//    cantece.push_back(std::make_shared<Song>(cantec1));
//    cantece.push_back(std::make_shared<Song>(cantec1));
//    cantece.push_back(std::make_shared<Song>(cantec1));

    std::vector<Song> cantece;
    cantece.push_back(cantec1);
    cantece.push_back(cantec1);
    cantece.push_back(cantec1);


//    for(auto c: cantece)
//        c.afis();

    int an = 2022;

    std::vector<Album> albume;

    Album album1(an, "da", 3, cantece); //Nume album - A doua cea mai frumi melodie
//    std::cout << album1 << "\n\n\n\n\n";
    albume.push_back(album1);
    albume.push_back(album1);
    albume.push_back(album1);

//    for(auto c: albume)
//        c.afis();

    Artist plm("Pula", "Mea", "De hartie", "Croatia", da, 3, albume, 3, cantece, 3);

//    plm.afis();

    //Playlist(const std::string& title, std::vector<Song>&songs, const int& nrSongs, std::vector<Album>&albums, const int& nrAlbums, const int& duration);
    Playlist pl("Titlu pl", cantece, 3, albume, 3, 150);
//    pl.afisare();

    std::vector<Playlist> playlists;
    playlists.push_back(pl);
    playlists.push_back(pl);
    playlists.push_back(pl);

//    for(auto c: playlists)
//        c.afisare();

//std::string username;
//    std::string password;
//    std::string email;
//    std::string country;
//    std::string birthDate;
//
//    bool subscription = false; //
//    std::vector<Playlist> playlists;

    std::string username = "zamfiresq";
    std::string password = "parolaplm";
    std::string email = "zamfiresq@gmail.com";
    std::string country = "Romania";
    std::string birthDate = "06/04/2002";


//User(std::string& username, std::string& password, std::string& email, std::string& country, std::string& birthDate, bool subscription, std::vector<Playlist>& playlists);
    User user(username,password, email, country, birthDate, false, playlists);
//    user.afisare();

    std::vector<User> users;
    users.push_back(user);
    users.push_back(user);
    users.push_back(user);

    for(auto c: users)
        c.afisare();



//    for(int i = 0; i < albume.size(); i++)
//        std::cout << albume[i] << "\n";
//
//
//    Song* v;
//    v = new Song[valoare];
//
//    myString obiect2 = "O melodie frumoasa"; //numele melodiei 2
//    myString obiect3 = "Romana"; //limba
//
//    Song cantec2(2023, obiect2, obiect3, valoare, da); //O melodie frumoasa
////    *v = cantec2;
//    for(int i = 0; i < valoare; i++)
//        v[i] = cantec2;
//
//
//    Album album1(an, obiect1, valoare, v); //Nume album - A doua cea mai frumi melodie
//
//    Album album2(2025, obiect2, valoare, v); //Nume album - O melodie frumoasa
//    std::cout<< album1;
//
//    myString firstName = "first name";
//    myString lastName = "last name";
//    myString nickname = "nickname";
//    myString nationality = "nationality";
//    int nr = 4; //nr ptr vector l
//    int nr1 = 5; // nr ptr vector albume
//    int nr2 = 3; //nr ptr vector de melodii/ singles
//
//    myString* l;
//    l = new myString[nr];
//
//    for(int i = 0; i < nr; i++)
//        l[i] = "lang";
//
//    Album* al;
//    al = new Album[nr1];
//
//    for(int i = 0; i < nr1; i++)
//        al[i] = album1;
//    al[1] = album2;
//
//    Song* s;
//    s = new Song[nr2];
//
//    for(int i = 0; i < nr2; i++)
//        s[i] = cantec2;
//
//    s[2] = cantec1;
//
//
//    Artist donToliver(firstName, lastName, nickname, nationality, l, nr, al, nr1, s, nr2 );
//     std::cout<<donToliver;
//
//    myString titlup = "Titlul playlist-ului meu";
//    int d = 150;
//
//    Album a;
//    //plm( playlist-ul meu ;) )
//    Playlist plm(titlup, s, nr2, al, nr1, d);
//    plm.repeatOne(2);
//
////    std::cout << plm;
////    plm.removeSong(cantec1); //
////    plm.removeAlbum(album1); //
////    std::cout << plm;
//plm.shuffle();



return 0;

}
