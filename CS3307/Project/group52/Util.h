#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>
#include <string>

class UserList;
class User;

namespace Util {

    int userInput(std::string initString, std::vector <std::string> selections);
    bool exit();
    UserList initializeSystem(std::string filepath);
    bool signIn(User theUser, UserList theList);

};

#endif
