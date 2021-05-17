#ifndef USER_H
#define USER_H


#include <stdio.h>
#include <string.h>
#include <ListOfBuckets.h>

class User {

  private:

    //Attributes
    string name, username, password, directory;
    bool verification;
    ListOfBuckets buckets;

  public:

    User(string theName, string theUsername, string thePassword, string theDirectory);
    bool authenticate(string passwordInput);
    string getName();
    bool setName(string newName);
    string getUsername();
    bool setUsername(string newUsername);
    bool setPassword(string passwordInput, string newPassword);
    string getDirectory();
    bool setDirectory(string newDirectory);

};

#endif
