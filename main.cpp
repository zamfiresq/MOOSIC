#include <iostream>
#include <vector>
#include <string>
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

    //testare song
    Song cantec1;
    std::cin>>cantec1;
    std::cout<<cantec1;

//    std::cout<<cantec1;

//    std::cout << "----------PROBA SINGLETON----------\n";
//    int option;
//    int index = 4;
//    int i = 2;
//    MusicPlayerManager *mpm = mpm->getInstance();
//    while (true) {
//        std::cout << "1. Play\n";
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
//            case 9:
//                mpm->addSongToPlaylist(cantec3, playlist1);
//                break;
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


//        }
        return 0;
    }
