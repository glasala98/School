#ifndef BUCKET_H
#define BUCKET_H

#include <stdio.h>
#include <string.h>
#include "Notification.h"
#include "BucketList.h"

class Bucket {

  private:

    //Attributes
    int bucketID, defaultPriority;
    string name;
    NotificationStructure defaultNotifStruc;
    BucketList list;

  public:

    Bucket(int ID, string theName)       
            Bucket(int ID, int priority, string theName, NotificationStructure notifStruc);
    int getID();
    boolean setName(string newName);
    int getDefaultPriority();
    boolean setDefaultPriority(int priority);
    BucketList getBucketList();
    NotificationStructure getDefaultNotifStruc();
    boolean setDefaultNotifStruc(NotificationStructure notifStruc);
};

#endif
