#ifndef NOTIFICATIONSTRUCTURE_H
#define NOTIFICATIONSTRUCTURE_H


#include <stdio.h>
#include <vector.h>

class NotificationStructure {

  private:
    
    //Attributes
    vector <Notification> list;
    int size;

  public:

    NotificationStructure();
    bool add(Notification notification);
    bool remove(Notification notification);
    int getSize();
    vector <Notification> getList();

};

#endif
