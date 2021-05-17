#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>
#include <string>

class BucketList;
class Notification;
class NotificationStructure;

class Bucket {

  private:

    //Attributes
    int bucketID, defaultPriority;
    std::string name;
    NotificationStructure* defaultNotifStruc;
    BucketList* theList;

  public:

    Bucket();
    Bucket(int ID);
    Bucket(int ID, std::string theName);       
    Bucket(int ID, int priority, std::string theName, NotificationStructure notifStruc);
    ~Bucket(); 
    int getID();
    std::string getName();
    bool setName(std::string newName);
    int getDefaultPriority();
    bool setDefaultPriority(int priority);
    BucketList getBucketList();
    NotificationStructure getDefaultNotifStruc();
    bool setDefaultNotifStruc(NotificationStructure notifStruc);
};

#endif
