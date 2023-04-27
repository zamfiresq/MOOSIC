//
// Created by Alexandra Zamfirescu on 25.03.2023.
//

#ifndef OOP_PROJECT_MYSTRING_H
#define OOP_PROJECT_MYSTRING_H
#include <iostream>
#include <vector>

//class myString {
//    std::vector<char>sir; //vectorul de string-uri
//    int nrStrings; //numarul de string-uri din vector
//
//public:
//    myString(); //constructor fara parametri
//    myString(std::vector<char>sir, int nrStrings); //constructor cu parametri
//    myString(std::vector<char>sir);
//    myString(const myString &object); //copy constructor
//
//    ~myString(); //destructor
//
//
//    //supraincarcarea operatorului <<
//    friend std::ostream &operator<<(std::ostream &os, const myString &string) {
//
//        return os;
//    }
//
////    //supraincarcarea operatorului >>
////    friend std::istream &operator>>(std::istream &is, myString &string) {
////
////        is >> string.nrStrings;
////        string.sir = new char [string.nrStrings];
////
////        for(int i = 0; i < string.nrStrings; i++)
////            is >> string.sir[i];
////        return is;
////    }
//
//    //supraincarcarea operatorului =
//    myString& operator = (const myString &other) {
//        this -> nrStrings = other.nrStrings;
//        this -> sir = other.sir;
//        return *this;
//    }
//
//    //supraincarcarea operatorului ==
//    bool operator == (const myString &other) {
//        if(this -> nrStrings != other.nrStrings || this -> sir != other.sir)
//            return false;
//        else
//        return true;
//    }
//
//    //supraincarcarea operatorului !=
//    bool operator != (const myString &other) {
//        if(this -> nrStrings != other.nrStrings || this -> sir != other.sir)
//            return true;
//        else
//        return false;
//    }
//
//    //supraincarcarea operatorului []
//    char operator[](int index) {
//        if (index >= nrStrings) {
//            std::cout << "Array index out of bound, exiting.\n";
//            exit(1);
//        }
//        return sir[index];
//    }
//
//    bool operator>(myString& other) {
//        int number, care = 0;
//        if(nrStrings < other.nrStrings && sir != other.sir) {
//            number = nrStrings;
//            care = 1;
//        }
//        if(nrStrings > other.nrStrings && sir != other.sir) {
//            number = other.nrStrings;
//            care = 2;
//        } else number = other.nrStrings;
//
//        if(care == 1)
//            return false;
//
//        return true;
//    }
//
//    bool operator<(myString& other) {
//        int number, care = 0;
//        if(nrStrings < other.nrStrings && sir != other.sir) {
//            number = nrStrings;
//            care = 1;
//        }
//        if(nrStrings > other.nrStrings && sir != other.sir) {
//            number = other.nrStrings;
//            care = 2;
//        } else number = other.nrStrings;
//
//        if(care == 1)
//            return true;
//
//        return false;
//    }
//
//
//    //getters
//    char* getSir() const;
//    int getNrStrings() const;
//
//    //afisare
//    void afis() const;
//
//    //supraincarcarea operatorului >> pentru citirea unui string
//    friend std::istream& operator>>(std::istream& is, myString& string) {
//        char *aux = new char[100];
//        is >> aux;
//        string.nrStrings = strlen(aux);
//        string.sir = new char[string.nrStrings];
//        for(int i = 0; i < string.nrStrings; i++)
//            string.sir[i] = aux[i];
//        return is;
//    }
//
//};
//

#endif //OOP_PROJECT_MYSTRING_H
