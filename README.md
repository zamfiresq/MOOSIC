# MOOMUSIC - Music Player

This project was written for the OOP course at the Faculty of Mathematics and Computer Science, University of Bucharest. 


As I mentioned above, the theme I chose for this project was to create my own music player app. 

# Classes

Clasele pe care le-am implementat:

1. Song - În clasa Song avem câmpurile:
   - year (anul melodiei)
   - name (numele melodiei)
   - language (limba în care este cântată melodia)
   - nrFeats (numărul de colaborări dintr-o melodie)
   - feat (vectorul ce conține numele colaboratorilor)

        Această clasă va conține datele despre orice melodie din music player.

2. Album - Clasa Album va conține melodiile specifice ei. Câmpurile clasei Album:
   - year (anul lansarii albumului)
   - name (numele albumului)
   - nrSongs(numărul de melodii din album)
   - Song *songs (vector de melodii ce redă melodiile dintr-un album)

3. Artist - Clasa Artist va include albumele și melodiile sale. Câmpurile clasei Artist:
   - firstName (numele artistului)
   - lastName (prenumele artistului)
   - nickname (poreclă)
   - nationality (naționalitate)
   - myString *languages (vectorul ce conține limbile în care cântă artistul)
   - nrLanguages
   - Album *albums (vectorul de albume pe care le deține)
   - nrAlbums (numărul albumelor)
   - Song *solo (vectorul de melodii pe care le deține)
   - nrSongs (numărul de melodii)

4. Playlist - Clasa Playlist va conține, pe lângă albume și melodii, funcționalități. Câmpurile clasei Playlist:
   - title (titlul playlist-ului)
   - Song *songs (vectorul de melodii)
   - nrSongs (numărul de melodii)
   - Album *albums (albumele pe care le salvez în playlist)
   - nrAlbums (numărul albumelor)
   - duration (durata unui playlist, exprimată în minute)

5. User - În clasa User, am vrut să adaug funcționalități ce țin de logarea unei persoane la aplicație. Câmpuri folosite:
   - username
   - password
   - email
   - country
   - birthDate
   - Playlist *favorites (aici am încercat să fac un vector în care să includ melodiile favorite ale user-ului)

6. myString (clasă utilitară) - Am făcut această clasă cu scopul de a evita folosirea "std::string" în declararea string-urilor.



# Functionalities

Funcționalitățile acestui program sunt:
- În cadrul clasei Playlist, am implementat funcții precum:
  -  "Add song", adaugă o melodie în playlist
  -  "Add album", adaugă un întreg album în playlist
  -  "Remove song", șterge o melodie din playlist
  -  "Remove album", șterge întreg albumul din playlist
  -  "Sort", sortează melodiile din playlist în ordine alfabetică
  -  "Search", căutare după numele playlist-ului
  -  "Play", pornire melodie
  -  "Pause", pauză
  -  "Next", pornește următoarea melodie
  -  "Previous" , pornește melodia precedentă
  -  "Repeat One", repetă o melodie
  -  "Shuffle", pornește melodiile din playist random

