//
// Created by Alexandra Zamfirescu on 26.04.2023.
//
//
//#include "../headers/prompt.h"
//#include "../headers/Playlist.h"
//#include "../headers/User.h"
//#include "../headers/Song.h"
//#include "../headers/Album.h"
//#include "../headers/myString.h"
//
//void interactivePrompt() {
//    std::cout << "Welcome to the interactive prompt!\n";
//
//    MusicStreamingService mss;
//
//    int command;
//    do {
//        // afișează meniul de comenzi
//        std::cout << "Please enter the number of the command you want to execute:\n";
//        std::cout << "1. Create a new user\n";
//        std::cout << "2. Create a new playlist\n";
//        std::cout << "3. Add a song to a playlist\n";
//        std::cout << "4. Add an album to a playlist\n";
//        std::cout << "5. Add a playlist to a user\n";
//        std::cout << "6. Display all users\n";
//        std::cout << "7. Display all playlists\n";
//        std::cout << "8. Display all songs\n";
//        std::cout << "9. Display all albums\n";
//        std::cout << "0. Exit\n";
//        std::cin >> command;
//        std::cin.ignore();
//
//        switch (command) {
//            case 0:
//                std::cout << "Exiting the program...\n";
//                break;
//            case 1: {
//                // creează un nou utilizator
//                std::cout << "Please enter the username: ";
//                myString username;
//                std::cin >> username;
//                std::cout << "Please enter the password: ";
//                myString password;
//                std::cin >> password;
//                std::cout << "Please enter the email: ";
//                myString email;
//                std::cin >> email;
//                std::cout << "Please enter the country: ";
//                myString country;
//                std::cin >> country;
//                std::cout << "Please enter the birth date: ";
//                myString birthDate;
//                std::cin >> birthDate;
//                std::cout << "Please enter the subscription: ";
//                bool subscription;
//                std::cin >> subscription;
//                User user(username, password, email, country, birthDate, subscription);
//                mss.addUser(user);
//                std::cout << "User added successfully!\n";
//                break;
//            }
//            case 2: {
//                // creează o nouă listă de redare
//                std::cout << "Please enter the name of the playlist: ";
//                myString name;
//                std::cin >> name;
//                std::cout << "Please enter the description of the playlist: ";
//                myString description;
//                std::cin >> description;
//                Playlist playlist(name, description);
//                mss.addPlaylist(playlist);
//                std::cout << "Playlist added successfully!\n";
//                break;
//            }
//            case 3: {
//                // Căutăm utilizatorul după nume și afișăm toate playlist-urile acestuia
//                std::cout << "Please enter the name of the user: ";
//                std::string username;
//                std::cin >> username;
//                User* user = MusicService::getInstance().getUserByUsername(username);
//                if (user != nullptr) {
//                    std::vector<Playlist>& playlists = user->getPlaylists();
//                    if (playlists.empty()) {
//                        std::cout << "This user does not have any playlists yet.\n";
//                        break;
//                    }
//                    std::cout << "Please enter the name of the playlist you want to add the song to:\n";
//                    for (const auto& playlist : playlists) {
//                        std::cout << "- " << playlist.getName() << "\n";
//                    }
//                    std::string playlistName;
//                    std::cin >> playlistName;
//                    Playlist* playlist = user->getPlaylistByName(playlistName);
//                    if (playlist == nullptr) {
//                        std::cout << "Playlist not found.\n";
//                        break;
//                    }
//                    // Căutăm melodia după nume și o adăugăm la playlist
//                    std::cout << "Please enter the name of the song you want to add:\n";
//                    std::string songName;
//                    std::cin >> songName;
//                    Song* song = MusicService::getInstance().getSongByName(songName);
//                    if (song == nullptr) {
//                        std::cout << "Song not found.\n";
//                        break;
//                    }
//                    playlist->addSong(*song);
//                } else {
//                    std::cout << "User not found.\n";
//                }
//                break;
//            }
//            case 4: {
//                // Căutăm utilizatorul după nume și afișăm toate playlist-urile acestuia
//                std::cout << "Please enter the name of the user: ";
//                std::string username;
//                std::cin >> username;
//                User* user = MusicService::getInstance().getUserByUsername(username);
//                if (user != nullptr) {
//                    std::vector<Playlist>& playlists = user->getPlaylists();
//                    if (playlists.empty()) {
//                        std::cout << "This user does not have any playlists yet.\n";
//                        break;
//                    }
//                    std::cout << "Please enter the name of the playlist you want to add the album to:\n";
//                    for (const auto& playlist : playlists) {
//                        std::cout << "- " << playlist.getName() << "\n";
//                    }
//                    std::string playlistName;
//                    std::cin >> playlistName;
//                    Playlist* playlist = user->getPlaylistByName(playlistName);
//                    if (playlist == nullptr) {
//                        std::cout << "Playlist not found.\n";
//                        break;
//                    }
//                    // Căutăm albumul după nume și adăugăm toate melodiile la playlist
//                    std::cout << "Please enter the name of the album you want to add:\n";
//                    std::string albumName;
//                    std::cin >> albumName;
//                    Album* album = MusicService::getInstance().getAlbumByName(albumName);
//                    if (album == nullptr) {
//                        std::cout << "Album not found.\n";
//                        break;
//                    }
//                    for (const auto& song : album->getSongs()) {
//                        playlist->addSong(song);
//                    }
//                } else {
//                    std::cout << "User not found.\n";
//            }
//                //3. Add a song to a playlist
//                void addSongToPlaylist() {
//                    std::cout << "Please enter the username: ";
//                    myString username;
//                    std::cin >> username;
//                    User* user = findUser(username);
//                    if (user != nullptr) {
//                        std::cout << "Please enter the name of the playlist: ";
//                        myString playlistName;
//                        std::cin >> playlistName;
//
//                        Playlist* playlist = user->findPlaylist(playlistName);
//                        if (playlist != nullptr) {
//                            std::cout << "Please enter the title of the song: ";
//                            myString title;
//                            std::cin >> title;
//
//                            Song* song = findSong(title);
//                            if (song != nullptr) {
//                                playlist->addSong(*song);
//                                std::cout << "Song added successfully to playlist.\n";
//                            } else {
//                                std::cout << "Song not found.\n";
//                            }
//                        } else {
//                            std::cout << "Playlist not found.\n";
//                        }
//                    } else {
//                        std::cout << "User not found.\n";
//                    }
//                    //4. Add an album to a playlist
//                    void addAlbumToPlaylist() {
//                        std::cout << "Please enter the username: ";
//                        myString username;
//                        std::cin >> username;
//                        User* user = findUser(username);
//                        if (user != nullptr) {
//                            std::cout << "Please enter the name of the playlist: ";
//                            myString playlistName;
//                            std::cin >> playlistName;
//
//                            Playlist* playlist = user->findPlaylist(playlistName);
//                            if (playlist != nullptr) {
//                                std::cout << "Please enter the title of the album: ";
//                                myString title;
//                                std::cin >> title;
//
//                                Album* album = findAlbum(title);
//                                if (album != nullptr) {
//                                    playlist->addAlbum(*album);
//                                    std::cout << "Album added successfully to playlist.\n";
//                                } else {
//                                    std::cout << "Album not found.\n";
//                                }
//                            } else {
//                                std::cout << "Playlist not found.\n";
//                            }
//                        } else {
//                            std::cout << "User not found.\n";
//                        }
//                    }while (option != 0);
//
//                    return 0;
//                }
//
