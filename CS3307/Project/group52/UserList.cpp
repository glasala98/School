#include "UserList.h"
#include "User.h"

using namespace std;

    UserList::UserList() {

        size = 0;

    }

    User UserList::get(int i) {
        return theList[i];
    }

    bool UserList::initialize(){
        return true;
    }

    bool UserList::add(User user) {

        for(int i = 0; i < size; i++) {
            if(theList[i].getUsername() == user.getUsername()) {
                return false;
            }
        }

        theList.push_back(user);
        size++;
        return true; 

    }

    bool UserList::remove(User user) {

        for(int i = 0; i < size; i++) {
            if(theList[i].getUsername() == user.getUsername()) {
                theList.erase(theList.begin()+i);
                size--;
                return true;
            }
        }

        return false; 
    }

    int UserList::getSize() {
        return size;
    }
