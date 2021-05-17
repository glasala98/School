#ifndef USER_H
#define USER_H


#include <iostream>
#include <fstream>
#include <string>

class ListOfBuckets;
class UserList;

class User {

  private:

    //Attributes
    int nextActID, nextBucketID, nextNotifID;
    std::string name, username, password, directory;
    bool verification;
    ListOfBuckets *buckets;
    

  public:

    User();
    User(UserList theList);
    User(std::string theName, std::string theUsername, std::string thePassword, std::string theDirectory);
    bool initialize();
    bool authenticate(std::string passwordInput);
    std::string getName();
    bool setName(std::string newName);
    std::string getUsername();
    bool setUsername(std::string newUsername);
    std::string getPassword();
    bool setPassword(std::string passwordInput, std::string newPassword);
    std::string getDirectory();
    bool setDirectory(std::string newDirectory);
    ListOfBuckets getListOfBuckets();
    int getNextActID();
    bool bumpNextActID();
    int getNextBucketID();
    bool bumpNextBucketID();
    int getNextNotifID();
    bool bumpNextNotifID();

};

#endif
