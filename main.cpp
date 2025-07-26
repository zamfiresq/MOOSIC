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
#include <fstream>


int main() {

    //testare song - citire din csv
    std::ifstream file("/Users/alexandrazamfirescu/CLionProjects/oop-project/csv_files/songs.csv");
    std::string line;
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    // Read each line and create a Song object
    int index = 1;
    std::getline(file, line); // Skip header line
    while (std::getline(file, line)) {
        try {
            Song song;
            song.readFromCSV(line);
            song.afis(index); // Display the song information
            index++;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error reading line: " << line << "\n" << e.what() << std::endl;
        }
    }

    file.close();
    return 0;
}
