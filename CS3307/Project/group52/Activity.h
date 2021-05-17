#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <vector>

class Bucket;
class NotificationStructure;
class DateAndTime;
class Notification;
class User;

class Activity {

  private:

    //Attributes
    int activityID, priority;
    std::string message, description;
    Bucket* bucket;
    DateAndTime* date; 
    DateAndTime* estimation;
    NotificationStructure* notifStruc;

  public:

    Activity();
    Activity(User theUser);
    Activity(int ID, Bucket theBucket); 
    Activity(int ID, int thePriority, std::string theMessage, std::string theDescription, Bucket theBucket, DateAndTime theDate, DateAndTime theEstimation, NotificationStructure theNotifStruc);
    int getID();
    int getPriority();
    bool setPriority(int newPriority);
    std::string getMessage();
    bool setMessage(std::string newMessage);
    std::string getDescription();
    bool setDescription(std::string newDescription);
    Bucket getBucket();
    bool setBucket(Bucket newBucket); 
    DateAndTime getDate();
    bool setDate(DateAndTime newDate);
    DateAndTime getEstimation() ;
    bool setEstimation(DateAndTime newEstimation);
    NotificationStructure getNotifStruc();
    bool setNotifStruc(NotificationStructure newNotifStruc);
    bool addNotification(Notification notification);
    bool deleteNotification(Notification);
};

#endif
    