#ifndef USERLIST_H
#define USERLIST_H

#include <iostream>
#include <vector>

class User;

class UserList {

  private:

    //Attributes
    std::vector <User> theList;
    int size;
            
  public:

    UserList();
    bool initialize();
    User get(int i);
    bool add(User user);
    bool remove(User user);
    int getSize();
};

#endif
