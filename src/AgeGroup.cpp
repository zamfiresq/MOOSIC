//
// Created by Alexandra Zamfirescu on 19.05.2023.
//

#include "../headers/AgeGroup.h"

template <class T>
void AgeGroup<T>::addUser(const T& user) {
    users.push_back(user);
}

template <class T>
std::vector<T> AgeGroup<T>::getUsers() const {
    return users;
}


template <class T>
std::vector<T> AgeGroup<T>::getUsersByAge(int minAge, int maxAge) const {
    std::vector<T> filteredUsers;

    for (const auto& user : users) {
        int age = user.getAge(); // Presupun că clasa T are o metodă getAge() care returnează vârsta utilizatorului

        if (age >= minAge && age <= maxAge) {
            filteredUsers.push_back(user);
        }
    }

    return filteredUsers;
}

template <class T>
int AgeGroup<T>::getCurrentYear() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

