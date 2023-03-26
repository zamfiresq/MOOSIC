//
// Created by Alexandra Zamfirescu on 25.03.2023.
//

#ifndef OOP_PROJECT_MYSTRING_H
#define OOP_PROJECT_MYSTRING_H
#include <iostream>

class myString {
    char *sir; //vectorul de string-uri
    int nrStrings; //numarul de string-uri din vector

public:
    myString(); //constructor fara parametri
    myString(char *sir, int nrStrings); //constructor cu parametri
    myString(char *sir);
    myString(const myString &object); //copy constructor

    ~myString(); //destructor

    //supraincarcarea operatorului <<
    friend std::ostream &operator<<(std::ostream &os, const myString &string) {
        for(int i = 0; i < string.nrStrings; i++)
            os << (string.sir)[i];
        return os;
    }

//    //supraincarcarea operatorului >>
//    friend std::istream &operator>>(std::istream &is, myString &string) {
//
//        is >> string.nrStrings;
//        string.sir = new char [string.nrStrings];
//
//        for(int i = 0; i < string.nrStrings; i++)
//            is >> string.sir[i];
//        return is;
//    }

    //supraincarcarea operatorului =
    myString& operator = (const myString &other) {
        this -> nrStrings = other.nrStrings;
        if(other.nrStrings > 0){
            this -> sir = new char [other.nrStrings];

            for(int i = 0; i < other.nrStrings; i++)
                this -> sir[i] = other.sir[i];
        } else{
            this -> nrStrings = 0;
            this -> sir =  nullptr;
        }
        return *this;
    }

    //supraincarcarea operatorului ==
    bool operator == (const myString &other) {
        if(this -> nrStrings != other.nrStrings)
            return false;
        else{
            for(int i = 0; i < this -> nrStrings; i++)
                if(this -> sir[i] != other.sir[i])
                    return false;
        }
        return true;
    }

    //supraincarcarea operatorului !=
    bool operator != (const myString &other) {
        if(this -> nrStrings != other.nrStrings)
            return true;
        else{
            for(int i = 0; i < this -> nrStrings; i++)
                if(this -> sir[i] != other.sir[i])
                    return true;
        }
        return false;
    }

    //supraincarcarea operatorului []
    char operator[](int index) {
        if (index >= nrStrings) {
            std::cout << "Array index out of bound, exiting.\n";
            exit(1);
        }
        return sir[index];
    }

    bool operator>(myString& other) {
        int number, care = 0;
        if(nrStrings < other.nrStrings) {
            number = nrStrings;
            care = 1;
        }
        if(nrStrings > other.nrStrings) {
            number = other.nrStrings;
            care = 2;
        } else number = other.nrStrings;

        for(int i = 0; i < number; i++) {
            if(sir[i] > (other.sir)[i])
                return true;
            if(sir[i] < (other.sir)[i])
                return false;
        }

        if(care == 1)
            return false;

        return true;
    }

    bool operator<(myString& other) {
        int number, care = 0;
        if(nrStrings < other.nrStrings) {
            number = nrStrings;
            care = 1;
        }
        if(nrStrings > other.nrStrings) {
            number = other.nrStrings;
            care = 2;
        } else number = other.nrStrings;

        for(int i = 0; i < number; i++) {
            if(sir[i] > (other.sir)[i])
                return false;
            if(sir[i] < (other.sir)[i])
                return true;
        }

        if(care == 1)
            return true;

        return false;
    }


    //getters
    char* getSir() const;
    int getNrStrings() const;

    //afisare
    void afis() const;

};


#endif //OOP_PROJECT_MYSTRING_H
