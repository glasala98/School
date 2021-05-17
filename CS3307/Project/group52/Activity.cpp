#include "Activity.h"
#include "Bucket.h"
#include "BucketList.h"
#include "DateAndTime.h" 
#include "ListOfBuckets.h"
#include "NotificationStructure.h"
#include "Notification.h"
#include "User.h"
#include "Util.h"

using namespace std;

    Activity::Activity(User theUser) {

        activityID = theUser.getNextActID();
        if(!theUser.bumpNextActID()) { cout << "\n\n\nERROR! Could not bump User NextActID\n\n\n"; }

        ListOfBuckets buckets = theUser.getListOfBuckets();
        int bucketNum = 0;
        while(true) {

            cout << "\n\nChoose a Bucket";

            for (int i = 0; i < buckets.getSize(); i++) {
                printf("\n%d: %s", i, buckets.get(i).getName().c_str());
            }
            
            cout << "Selection: ";
            cin >> bucketNum;

            if (bucketNum < 1 || bucketNum >= buckets.getSize()) {
                cout << "\nError: Please choose from the available options"; 
            }

            else {
                break;
            }

        }

        *bucket = buckets.get(bucketNum);

        priority = 0;
        while (priority != 1 && priority != 2 && priority != 3) {

            cout << "\nEnter a Priority 1, 2 or 3\nSelection: ";
            cin >> priority;

            if (priority != 1 && priority != 2 && priority != 3) { cout << "\nError: Please choose from the available options"; }

        }

        cout << "\nEnter a message for the notification: ";
        cin >> message;

        cout << "\nEnter a description: ";
        cin >> description;

        int day, time;
        cout << "\nEnter the Date: ";
        cin >> day;

        cout << "\nEnter the Time: ";
        cin >> time;

        *date = DateAndTime(day, time);

        cout << "\nEnter the estimation (integer)";
        cin >> time;
                                    
        *estimation = DateAndTime(time, "time");

        vector <string> selections;

        selections[1] = "1: Default for activity type";
        selections[2] = "2: Custom";

        int selection = Util::userInput("Please choose an option for Notification Structure", selections);

        if (selection == 1) {

            *notifStruc = NotificationStructure(theUser, *this, bucket->getDefaultNotifStruc());

        }
        
        else {

            *notifStruc = NotificationStructure();

        }

        bucket->getBucketList().add(*this);

    }

    Activity::Activity(int ID, Bucket theBucket) {

        activityID = ID;
        priority = 0;
        message = "";
        description = "";
        *bucket = theBucket;
        *date = DateAndTime(0,0); //Would like to make this default to today
        *estimation = DateAndTime(0, "time");
        *notifStruc = NotificationStructure();

    }

    Activity::Activity(int ID, int thePriority, string theMessage, string theDescription, Bucket theBucket, DateAndTime theDate, DateAndTime theEstimation, NotificationStructure theNotifStruc) {

        activityID = ID;
        priority = thePriority;
        message = theMessage;
        description = theDescription;
        *bucket = theBucket;
        *date = theDate;
        *estimation = theEstimation;
        *notifStruc = theNotifStruc;

    }

    int Activity::getID() {
        return activityID;
    }

    int Activity::getPriority() {
        return priority;
    }

    bool Activity::setPriority(int newPriority) {
        priority = newPriority;
        return true;
    }

    string Activity::getMessage() {
        return message;
    }

    bool Activity::setMessage(string newMessage) {
        message = newMessage;
        return true;
    }

    string Activity::getDescription() {
        return description;
    }

    bool Activity::setDescription(string newDescription) {
        description = newDescription;
        return true;
    }

    Bucket Activity::getBucket() {
        return *bucket;
    }

    bool Activity::setBucket(Bucket newBucket) {
        *bucket = newBucket;
        return true;
    }

    DateAndTime Activity::getDate() {
        return *date;
    }

    bool Activity::setDate(DateAndTime newDate) {
        *date = newDate;
        return true;
    }

    DateAndTime Activity::getEstimation() {
        return *estimation;
    }

    bool Activity::setEstimation(DateAndTime newEstimation) {
        *estimation = newEstimation;
        return true;
    }

    NotificationStructure Activity::getNotifStruc() {
        return *notifStruc;
    }

    bool Activity::setNotifStruc(NotificationStructure newNotifStruc) {
        *notifStruc = newNotifStruc;
        return true;
    }

    bool Activity::addNotification(Notification notification) {
        return notifStruc->add(notification);
    }

    bool Activity::deleteNotification(Notification notification) {
        return notifStruc->remove(notification);
    }
