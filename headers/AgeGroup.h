////
//// Created by Alexandra Zamfirescu on 19.05.2023.
////
//
//#ifndef OOP_PROJECT_AGEGROUP_H
//#define OOP_PROJECT_AGEGROUP_H
//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//#include "User.h"
//
////TEMPLATE CLASS
//
//template <class T> class AgeGroup {
//private:
//    std::vector<T> users; //aici vom stoca user ii pe categorii de varsta
//
//public:
//    void addUser(const T& user);
//    std::vector<T> getUsers() const;
//    std::vector<T> getUsersByAge(int minAge, int maxAge) const;
//
//    int getCurrentYear() const;
//
//
//    //operator <<
//    friend std::ostream& operator << (std::ostream& os, const AgeGroup<T>& ageGroup){
//        os << "Users: " << "\n";
//        for (const auto& user : ageGroup.users){
//            os << user << "\n";
//        }
//        return os;
//    }
//
//
//#endif //OOP_PROJECT_AGEGROUP_H
//};