#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
#include "User.h"
#include "UserList.h"
#include "Activity.h"
#include "Notification.h"
#include "DateAndTime.h"


/*
 * A class to create and write data in a csv file.
 */
 
class CSVWriter {
    std::string fileName;
    std::string delimeter;
    int linesCount;
    
    
public:
    CSVWriter(std::string filename, std::string delm = ",") :
            fileName(filename), delimeter(delm), linesCount(0)
    {}
    /*
     * Member function to store a range as comma seperated value
     */
    template<typename T>
    void addDatainRow(T first, T last);
};


/*
 * This Function accepts a range and appends all the elements in the range
 * to the last row, seperated by delimeter (Default is comma)
 */
template<typename T>
void CSVWriter::addDatainRow(T first, T last)
{
    std::fstream file;
    file.open(fileName, std::ios::out | (linesCount ? std::ios::app : std::ios::trunc));
    for (; first != last; )
    {
        file << *first;
        if (++first != last)
            file << delimeter;
    }
    file << "\n";
    linesCount++;
    file.close();
}

int configwrite(User user){
    // Creating an object of CSVWriter
    CSVWriter writer("config\example.csv");
    std::string username;
    std::string password;
    std::string directory;
    std::string buckets;

    username = user.getUsername();
    password = user.getPassword();
    directory = user.getDirectory();

    std::vector<std::string> dataList_1 = { username, password, directory};
    // Adding vector to CSV File
    writer.addDatainRow(dataList_1.begin(), dataList_1.end());
    return 0;
}

int bucketWrite(Bucket bucket){
    // Creating an object of CSVWriter
    // create file name
    // add path to name
    // 
    CSVWriter writer("bucket.csv");
    int bucketID, defaultPriority;
    std::string name;
    NotificationStructure defaultNotifStruc;
    BucketList list;

    bucketID = bucket.getID();
    defaultPriority = bucket.getDefaultPriority();
    // list = user.getDirectory();

    std::vector<int> dataList_1 = { bucketID, defaultPriority};
    // Adding vector to CSV File
    writer.addDatainRow(dataList_1.begin(), dataList_1.end());
    return 0;
}

int activityWrite(Activity activity){
    // Creating an object of CSVWriter
    CSVWriter writer("activity.csv");
    int activityID, priority;
    std::string message, description;
    Bucket bucket;
    DateAndTime date, estimation;
    NotificationStructure notifStruc;

    activityID = activity.getID();
    priority = activity.getPriority();
    message = activity.getMesgit checsage();
    date = activity.getDate();
    estimation = activity.getEstimation();
    notifStruc = activity.getNotifStruc();

    //std::vector<std::variant<int, string>> dataList_1 = { activityID, priority, message, date, estimation, notifStruc};

    // Adding vector to CSV File
    //writer.addDatainRow(dataList_1.begin(), dataList_1.end());
    return 0;
}


int notificationWrite(Notification notification){
    // Creating an object of CSVWriter
    CSVWriter writer("notifcation.csv");
    int notificationID, status, deliveryMethodInt;
    Activity activity;
    DateAndTime delta;
    Notification deliveryMethod;

    notificationID = notification.getID();
    status = notification.getStatus();
    deliveryMethodInt = notification.getDeliveryMethod();
    activity = notification.getActivity();
    delta = notification.getDelta();

    //std::vector<std::string> dataList_1 = { notificationID, status, deliveryMethod, activity, delta};
    // Adding vector to CSV File
    //writer.addDatainRow(dataList_1.begin(), dataList_1.end());
    return 0;
}

// store activities in csv like user
// acitivty/activityid
// UserName
//      - Buckets (List of Acitvity ; bucket list Structure, with no activity)
//      - Activies (check Bucket Id ; with description etc. , store appropriately. when read in append to the correct bucket ID)
//      - Noti's strucute
    /// then noti's

// make sure everything is written
// add util exit