#include "User.h"
#include "ListOfBuckets.h"
#include "UserList.h"

using namespace std;

    User::User(UserList theList) {

        string name, username, password, directory;

        cout << "\nPlease Enter Your Name: ";
        cin >> name;

        bool validUsername = false;

        while (!validUsername) {

            validUsername = true;

            cout << "\nPlease Enter Your Username: ";
            cin >> username;

            for (int i = 0; i < theList.getSize(); i++) {

                if (username == theList.get(i).getUsername()) { 
                    
                    cout << "\nA user with this username already exists, please choose a new one";
                    validUsername = false; 
             
                }

            }
        }

        //Eventually add a second password and verify they match
        cout << "\nPlease choose your password: ";
        cin >> password;

        directory = /*CONCAT("FILEPATH",*/ username/*)*/;

        User newUser = User(name, username, password, directory);
    }

    User::User(string theName, string theUsername, string thePassword, string theDirectory) {

        name = theName;
        username = theUsername;
        password = thePassword;
        directory = theDirectory;
        *buckets = ListOfBuckets();
        nextActID = 1;
        nextBucketID = 1;
        nextNotifID = 1;

    }

    bool User::initialize() {
        string str;
        string extension = "config.csv";
        str.append(username);
        str.append(extension); // Creates "user"config.csv
        ifstream file;
        file.exceptions ( ifstream::failbit | ifstream::badbit );
        try {
            file.open (str);
            while (!file.eof()) file.get();
                file.close();
                return true;
        }
        catch (ifstream::failure e) {
            cerr << "File not found exception\n";
            return false;
        }
    }

    bool User::authenticate(string passwordInput) {
        if(passwordInput == password) {
            return true;
        }
        return false;
    }

    string User::getName() {
        return name;
    }

    bool User::setName(string newName) {
        name = newName;
        return true;
    }

    string User::getUsername() {
        return username;
    }

    bool User::setUsername(string newUsername) {
        username = newUsername;
        return true;
    }

    string User::getPassword() {
        return password;
    }

    bool User::setPassword(string passwordInput, string newPassword) {
        if(passwordInput == password) {
            password = newPassword;
            return true;
        }
        return false;
    }

    string User::getDirectory() {
        return directory;
    }

    bool User::setDirectory(string newDirectory) {
        directory = newDirectory;
        return true;
    }

    ListOfBuckets User::getListOfBuckets() {
        return *buckets;
    }

    int User::getNextActID() {
        return nextActID;
    }

    bool User::bumpNextActID() {
        nextActID++;
        return true;
    }

    int User::getNextBucketID() {
        return nextBucketID;
    }

    bool User::bumpNextBucketID() {
        nextBucketID++;
        return true;
    }

    int User::getNextNotifID() {
        return nextNotifID;
    }

    bool User::bumpNextNotifID() {
        nextNotifID++;
        return true;
    }
