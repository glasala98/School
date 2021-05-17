#include "Bucket.h"

#include "BucketList.h"
#include "Notification.h"
#include "NotificationStructure.h"
#include "Util.h"

using namespace std;

    /** 
     * Interactive Bucket Constructor
     * @param ID identifies the bucket
     */
    Bucket::Bucket(int ID) {

        bucketID = ID;

        cout << "\nEnter the name of the Bucket: ";
        cin >> name;

        defaultPriority = 0;
        while (defaultPriority != 1 && defaultPriority != 2 && defaultPriority != 3) {

            cout << "\nEnter a Default Priority for the Bucket 1, 2 or 3\nSelection: ";
            cin >> defaultPriority;

            if (defaultPriority != 1 && defaultPriority != 2 && defaultPriority != 3) { cout << "\nError: Please choose 1, 2 or 3"; }

        }

        *defaultNotifStruc = NotificationStructure();
        defaultNotifStruc->createDefaultStructure();

    }

    /** 
     * Bucket constructor that sets categories that is used to store activities under
     * @param ID identifies the bucket
     * @param theName of the bucket such as 'quizzes', 'meetings' 
     */
    Bucket::Bucket(int ID, string theName) {

        bucketID = ID;
        name = theName;
        defaultPriority = 0;  /**< Priority is used to set notification persistence. */
        *defaultNotifStruc = NotificationStructure();
        *theList = BucketList();

    }

    /** 
     * Overloaded constructor
     * @param ID identifies Bucket
     * @param priority Sets the notification persistance as well as affects sort method
     * @param theName is the name of the bucket
     * @param notifStruc How the user would like to be notified
     */
    Bucket::Bucket(int ID, int priority, string theName, NotificationStructure notifStruc) {

        bucketID = ID;
        name = theName;
        defaultPriority = priority;
        *defaultNotifStruc = notifStruc;
        *theList = BucketList();

    }

    /** 
     * Getter method returns the Id of the bucket
     * @return returns the ID of the bucket
     */
    int Bucket::getID() {
        return bucketID;
    }

    /** 
     * Getter method returns the name of the bucket
     * @return returns the name of the bucket
     */
    string Bucket::getName() {
        return name;
    }

    /** 
     * Set name for bucket
     * @param newName is the newName to set bucket as
     * @return bool true after name is set
     */
    bool Bucket::setName(string newName) {
        name = newName;
        return true;
    }

    /** 
     * Gets the priority level of the bucket
     * @return returns the priority level of bucket
     */
    int Bucket::getDefaultPriority() {
        return defaultPriority;
    }

    /** 
     * Sets the priority level of the bucket
     * @param priority int value that determines how important the bucket is or is notification
     * @return bool value of true once the priority is set
     */
    bool Bucket::setDefaultPriority(int priority) {
        defaultPriority = priority;
        return true;
    }

    /** 
     * Gets list from bucket.cpp
     * @param returns the list of buckets
     */
    BucketList Bucket::getBucketList() {
        return *theList;
    }

    /** 
     * Gets default notfication structure
     * @return the notifcation structure
     */
    NotificationStructure Bucket::getDefaultNotifStruc() {
        return *defaultNotifStruc;
    }

    /** 
     * Sets the notifiation structure
     * @return bool true when notifcation structure is set
     */
    bool Bucket::setDefaultNotifStruc(NotificationStructure notifStruc) {
        *defaultNotifStruc = notifStruc;
        return true;
    }
