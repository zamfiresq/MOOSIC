#include <iostream>
#include <vector>
#include<string>
#include "headers/Artist.h"
#include "headers/Album.h"
#include "headers/Song.h"
#include "headers/Playlist.h"
#include "headers/User.h"
#include "headers/playlistFavorite.h"
#include "headers/Interfata.h"
#include "headers/premiumUser.h"
#include "headers/Premium.h"
#include "headers/Exceptions.h"
#include "headers/MusicPlayerManager.h"
#include "headers/AgeGroup.h"


int main() {

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
    for (int i = 0; i < 3; i++)
        da.push_back(obiect4);

//int year;  //anul lansarii melodiei
//    std::string artistName; //numele artistului
//    std::string name; //titlul melodiei
//    std::string language;  //limba melodiei
//    unsigned int nrFeats; //numarul de colaboratori dintr-o melodie
//    std::vector<std::string> feat; //vector de string-uri cu numele colaboratorilor

    int year = 2023;
    std::string artistname = "Nume Artist";
    std::string numeMelodie = "Numele melodiei";
    std::string limba = "Engleza";


    Song cantec1(year, artistname, numeMelodie, limba, 3, da);
    //cantec1.afis();

//    std::vector<std::shared_ptr<Song>> cantece;
//    cantece.push_back(std::make_shared<Song>(cantec1));
//    cantece.push_back(std::make_shared<Song>(cantec1));
//    cantece.push_back(std::make_shared<Song>(cantec1));

    std::vector<Song> cantece;
    cantece.push_back(cantec1);
    cantece.push_back(cantec1);
    cantece.push_back(cantec1);

    int an = 2022;

    std::vector<Album> albume;

    Album album1(an, "da", 3, cantece); //Nume album - A doua cea mai frumi melodie
//    std::cout << album1 << "\n\n\n\n\n";
    albume.push_back(album1);
    albume.push_back(album1);
    albume.push_back(album1);

//    for(auto c: albume)
//        c.afis();

    Artist plm("Pula Mea de Hartie", "Croatia", da, 3, albume, 3, cantece, 3);
    std::cout << plm;
//    plm.afis();

    //Playlist(const std::string& title, std::vector<Song>&songs, const int& nrSongs, std::vector<Album>&albums, const int& nrAlbums, const int& duration);
    Playlist pl("Titlu pl", cantece, 3, 150);
//    pl.afisare();
//    std::cout<<"\n";

    Album album2(an, "NU", 3, cantece); //Nume album - A doua cea mai frumi melodie
//    std::cout << album1 << "\n\n\n\n\n";
    std::vector<Album> albumele;
    albumele.push_back(album2);
    albumele.push_back(album2);
    albumele.push_back(album2);
//    pl.addAlbum(albumele);


    std::cout << "------------------------------DUPA------------------------------";
    std::cout << "\n";


    //pl.afisare();

    std::vector<Playlist> playlists;
    playlists.push_back(pl);
    playlists.push_back(pl);
    playlists.push_back(pl);

//    for(auto c: playlists)
//        c.afisare();

    std::cout << "\n";
    std::cout << "----------MOSTENIRE----------" << "\n";
//    playlistFavorite plf("Titlu pl", cantece, 3, 150, 2);
//    plf.afisare();

    std::cout << "\n";

    premiumUser pru("username", "password", "email", "country", "birthDate", playlists, true);
    std::cout << pru;


    std::cout << "\n";
    std::cout << "----------LISTA INITIALIZARE----------" << "\n";

    playlistFavorite playlistF("Melodii favorite", cantece, 3, 150, 2);
    std::cout << "TITLE: " << playlistF.getTitle() << "\n";
    std::cout << "SONGS NR: " << playlistF.getNrSongs() << "\n";
    std::cout << "DURATION: " << playlistF.getDuration() << "\n";
    std::cout << "ARTIST NR: " << playlistF.getNrArtists() << "\n\n";


    std::cout << "\n";


    std::cout << "----------DESTRUCTOR VIRTUAL----------\n";

//    // testare destructor virtual
//    absPlaylist* playlist = new AbsPlaylist();
//
//    // utilizarea playlist-ului, adaugam melodii
//    playlist->addSong(cantec);
//    playlist->addSong(cantec1);
//    playlist->addSong(cantec);
//    playlist->nextSong(0);
//
//    //stergerea obiectului prin intermediul pointer-ului la clasa de baza
//    delete playlist;

//
//
//Premium pr;
//std::cout<<pr;
//
//premiumUser userPremium(username, password, email, birthDate, country, playlists, true);
//std::cout<<userPremium;
//std::cout<<"\n";
//
//userPremium.removeAd();
//
    IPlaylist ip;

    ip.play();
    ip.pause();

    std::cout << "\n";

//ISong is;
//
//is.play();
//is.pause();
//is.afisare(); std::cout<<cantec1;
//
//std::cout<<"\n";
//
//
//    AbsPlaylist playlist;
//
//// adaugăm melodii la playlist
//    playlist.addSong(cantec1);
//    playlist.addSong(cantec1);
//    playlist.addSong(cantec1);
//
//
//    // pornim redarea de la prima melodie
//    playlist.nextSong(3);
//    std::cout<<"\n\n";


    std::cout << "\n";
    std::cout << "----------EXCEPTII----------\n";



////exceptie 1
////pentru efectuare plata abonament
//    std::string numar_card_valid = "1234567895346678";
//    std::string numar_card_invalid = "1234";
//
//    try {
//        efectuare_plata(numar_card_valid);
//        std::cout << "Plata a fost efectuata cu succes pentru numarul de card " << numar_card_valid << ".\n";
//    } catch (const std::exception& e) {
//        std::cerr << "Eroare la efectuarea platii cu cardul valid: " << e.what() << '\n\n';
//    }

//
//    try {
//        efectuare_plata(numar_card_invalid);
//        std::cout << "Plata cu cardul invalid a fost efectuata cu succes!\n\n";
//    } catch (const std::exception& e) {
//        std::cerr << "Eroare la efectuarea platii: " << e.what() << "\n\n";
//    }

    std::cout << "\n\n";


//exceptie 2
//pentru adaugarea unei melodii cu acelasi nume in Playlist

    Playlist playlist1;
    Song cantec3;
    //Song(const int& year,  const std::string& artistName, const std::string& name, const std::string& language, const unsigned int& nrFeats, std::vector<std::string>&feat);
    cantec3 = Song(1975, "Queen", "Bohemian Rhapsody", "English", 1, da);

    Song cantec4;
    cantec4 = Song(1971, "Led Zeppelin", "Stairway to Heaven", "English", 1, da);

    Song cantec5;
    cantec5 = Song(1989, "Queen", "The Show Must Go On", "English", 1, da);

    Song cantec6;
    cantec6 = Song(1989, "Queen", "The Show Must Go On", "English", 1, da);


////testare exceptie 2 - eroare la adaugarea melodiei cu acelasi nume
//try{
    playlist1.addSong(cantec3);
    playlist1.addSong(cantec5);
    playlist1.addSong(cantec4);
//    playlist1.addSong(cantec5);
//    std::cout<<playlist1;
//    playlist1.sortAfterSongTitle();
//    playlist1.sortAfterArtistName();
//    std::cout<<playlist1;
//    playlist1.removeSong(cantec6);
//    std::cout<<playlist1;
//
//} catch (const SongAlreadyExists& e) {
//    std::cerr << e.what() << "\n";
//}



////proba static
    std::cout << "\n";
    std::cout << "----------PROBA STATIC----------\n";
//Song::welcomeMessage();

    std::string data = "06/04/2002";

    User user("username", "password", "email", "country", data, playlists);
    int val = user.getYear();
//    std::cout<<val;
//






    std::cout<<"\n";

    std::cout << "----------PROBA TEMPLATE----------\n";
//    AgeGroup<User> ageGroup;
//    User user3("ghita", "parola", "ghita@gmail.com", "Romania", "16/05/1993", playlists);
//    User user4("zamfiresq", "password", "alexandrazamfiresq@gmail.com", "Romania", "06/04/2002", playlists);
//    AgeGroup.addUser(user3);
//    AgeGroup.addUser(user4);


//    std::cout << "----------PROBA SINGLETON----------\n";
//    int option;
//    int index = 4;
//    int i = 2;
//    MusicPlayerManager *mpm = mpm->getInstance();
//    while (true) {
//    std::cout << "1. Play\n";
//        std::cout << "2. Pause\n";
//        std::cout << "3. Next\n";
//        std::cout << "4. Previous\n";
//        std::cout << "5. Shuffle\n";
//        std::cout << "6. Repeat One\n";
//        std::cout << "7. Volume up\n";
//        std::cout << "8. Volume down\n";
//        std::cout << "9. Add song to playlist\n";
//        std::cout << "10. Remove song from playlist\n";
//        std::cout << "0. Exit\n";
//        std::cout << "Choose an option: ";
//        std::cin >> option;
//        switch (option) {
//            case 1:
//                mpm->play();
//                break;
//            case 2:
//                mpm->pause();
//                break;
//            case 3:
//                mpm->next(index);
//                break;
//            case 4:
//                mpm->previous(index);
//                break;
//            case 5:
//                mpm->shuffle();
//                break;
//            case 6:
//                mpm->repeatOne();
//                break;
//            case 7:
//                mpm->volumPlus();
//                break;
//            case 8:
//                mpm->volumMinus();
//                break;
//                case 9:
//                    mpm->addSongToPlaylist(cantec3, playlist1);
//                    break;
//            case 10:
//                mpm->removeSongFromPlaylist(cantec5, playlist1);
//                break;
//            case 0:
//                std::cout << "Exiting...\n";
//                return 0;
//            default:
//                std::cout << "Invalid option!\n";
//                break;
//        }
//
//
//    }
    return 0;
}