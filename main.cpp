#include <iostream>
#include "headers/Artist.h"
#include "headers/Album.h"
#include "headers/Song.h"
#include "headers/myString.h"
#include "headers/Playlist.h"
#include "headers/User.h"

int main(){
    myString obiect = "numeAlbum";
    myString obiect1 = "nameAlbum";
    std::cout << (obiect > obiect1);
    int valoare = 3;
    std::cout << obiect;
    obiect.afis();

    Song cantec;
    std::cout << cantec;

    myString obiect4 = "feat1";
    myString obiect5 = "feat2";
    myString obiect6 = "feat3";


    myString* da;
    da = new myString[3];

    for(int i = 0; i < 3; i++)
        da[i] = obiect4;


    Song cantec1(2023, obiect, obiect, valoare, da);
    std::cout << cantec1;


    int an = 2022;
    Song* v;
    v = new Song[valoare];

    myString obiect2 = "O melodie frumoasa";
    myString obiect3 = "Romana";
    Song cantec2(2023, obiect2, obiect3, valoare, da);
//    *v = cantec2;
    for(int i = 0; i < valoare; i++)
        v[i] = cantec2;
    Album album1(an, obiect, valoare, v);
//    std::std::cout<< album1;

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
        l[i] = "lang";

    Album* al;
    al = new Album[nr1];

    for(int i = 0; i < nr1; i++)
        al[i] = album1;

    Song* s;
    s = new Song[nr2];

    for(int i = 0; i < nr2; i++)
        s[i] = cantec2;


    Artist donToliver(firstName, lastName, nickname, nationality, l, nr, al, nr1, s, nr2 );
     std::cout<<donToliver;

    myString titlup = "Titlu playlist-ului meu ";
    int d = 150;

    Album a;
    //plm( playlist-ul meu ;) )
    Playlist plm(titlup, s, nr2, al, nr1, 150);
    plm.repeatOne(3);

myString username = "username";
myString password = "parola";
myString email = "username@moomusic.com";
myString country = "Romania";
myString birthDate = "01.01.2000";

Playlist* favorites;
favorites = new Playlist[1];
favorites[0] = plm;

    User user1(username, password, email, country, birthDate, favorites);
    std::cout<< user1;
    //nu imi afiseaza playlist-ul favorit

    return 0;
    }
