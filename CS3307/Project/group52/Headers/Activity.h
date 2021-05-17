#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include "Bucket.h"

class Activity {

  private:

    //Attributes
    int activityID, priority;
    std::string message, description;
    Bucket bucket;
    DateAndTime date, estimation;
    NotificationStructure notifStruc;

  public:

    Activity(int ID, Bucket theBucket); 
    Activity(int ID, int thePriority, std::string theMessage, std::string theDescription, Bucket theBucket, DateAndTime theDate, dateAndTime theEstimation, NotificationStructure theNotifStruc);
    int getID();
    int getPriority();
    bool setPriority(int newPriority);
    bool setMessage(std::string newMessage);
    std::string getDescription();
    bool setMessage(std::string newDescription);
    Bucket getBucket();
    bool setBucket(Bucket newBucket); 
    DateAndTime getDate();
    bool setDate(DateAndTime newDate);
    DateAndTime getEstimation() ;
    bool setEstimation(DateAndTime newEstimation);
    NotificationStructure getNotifStruc();
    bool setNotifStruc(NotificationStructure newNotifStruc);
    bool addNotification(Notification notification);
    bool deleteNotification(notification);
};

#endif
    
