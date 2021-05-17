#ifndef NOTIFICATIONSTRUCTURE_H
#define NOTIFICATIONSTRUCTURE_H


#include <iostream>
#include <vector>

class Activity;
class Notification;
class User;

class NotificationStructure {

  private:
    
    //Attributes
    std::vector <Notification>* theList;
    int size;

  public:

    NotificationStructure();
    NotificationStructure(User theUser, Activity theActivity);
    NotificationStructure(User theUser, Activity theActivity, NotificationStructure tempStructure);
    bool createDefaultStructure();
    Notification get(int i);
    bool add(Notification notification);
    bool remove(Notification notification);
    int getSize();
    std::vector <Notification> getList();

};

#endif
