//
// Created by Alexandra Zamfirescu on 25.03.2023.
//

#include "../headers/myString.h"

//constructor fara parametri
myString::myString() {
    this -> sir = nullptr;
    this -> nrStrings = 0;
}

//constructor cu parametri
myString::myString(char *sir, int nrStrings) {
    this -> nrStrings = 20;

    if(nrStrings > 0){
        this -> sir = new char [nrStrings];

        for(int i = 0; i < nrStrings; i++)
            (this -> sir)[i] = sir[i];
    } else{
        this -> nrStrings = 0;
        this -> sir =  nullptr;

    }
}

myString::myString(char *sir) {
    if(sir != nullptr) {
        this -> nrStrings = 0;
        for(int i = 0; sir[i] != '\0'; i++)
            (this -> nrStrings)++;
//        (this -> nrStrings)++; //incrementare si pentru '\0' dar nu cred ca e cazul tho
        this -> sir = new char [nrStrings];
        this -> sir = sir;
    } else {
        this -> sir = nullptr;
        this -> nrStrings = 0;
    }
}

//copy constructor
myString::myString(const myString &object) {
    this -> nrStrings = object.nrStrings;

    if(object.nrStrings > 0){
        this -> sir = new char [object.nrStrings];

        for(int i = 0; i < object.nrStrings; i++)
            this -> sir[i] = object.sir[i];
    } else{
        this -> nrStrings = 0;
        this -> sir =  nullptr;
    }
}

//apelam destructorul
myString::~myString() {
//    if(this -> sir != nullptr)
//        delete [] sir;
}

int myString::getNrStrings() const {
    return nrStrings;
}

char* myString::getSir() const {

    return sir;
}

//afisare
void myString::afis() const {
    for(int i = 0; i < nrStrings; i++)
        std::cout << sir[i];
    std::cout << "\n";
}

