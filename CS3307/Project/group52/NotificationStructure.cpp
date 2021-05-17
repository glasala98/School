#include "NotificationStructure.h"

#include <string>

#include "Activity.h"
#include "DateAndTime.h"
#include "Notification.h"
#include "User.h"
#include "Util.h"

using namespace std;

    NotificationStructure::NotificationStructure() {
        size = 0;
    }

    NotificationStructure::NotificationStructure(User theUser, Activity theActivity) {

        size = 0;

        int notifID, timeDelta, method, selection;
        Notification newNotification;

        while (true) {//User can add as many notifications to the structure as they want

            notifID = theUser.getNextNotifID();
            theUser.bumpNextNotifID();

            newNotification = Notification(notifID, theActivity);
            add(newNotification);

            vector <string> selections;
            selections[1] = "1: Yes";
            selections[2] = "2: No";

            selection = Util::userInput("Would You like to add another notification?", selections);

            if (selection == 2) { break; }

        }

    }

    NotificationStructure::NotificationStructure(User theUser, Activity theActivity, NotificationStructure tempStructure) {

        size = 0;

        int ID;
        Notification newNotification;
      
        for(int i = 0; i < tempStructure.getSize(); i++) {
            ID = theUser.getNextNotifID();
            newNotification = Notification(ID, theActivity, tempStructure.get(i).getDelta(), tempStructure.get(i).getDeliveryMethod());
            theUser.bumpNextNotifID();
            add(newNotification);
        }

    }

    bool NotificationStructure::createDefaultStructure() {

        int timeDelta, method, selection;
        Notification newNotification;

        while (true) {//User can add as many notifications to the default structure as they want

            newNotification = Notification();
            newNotification.notificationTemplate();
            add(newNotification);

            selection = 0;
            vector <string> selections;

            selections[1] = "1: Yes";
            selections[2] = "2: No";

            selection = Util::userInput("Would You like to add another notification?", selections);

            if (selection == 2) {
                break;
            }
        }

        return true;
    }

    Notification NotificationStructure::get(int i) {
        return (*theList)[i];
    }

    bool NotificationStructure::add(Notification notification) {

        for(int i = 0; i < size; i++) {
            if((*theList)[i].getID() == notification.getID()) {
                return false;
            }
        }

        theList->push_back(notification);
        size++;
        return true; 

    }

    bool NotificationStructure::remove(Notification notification) {

        for(int i = 0; i < size; i++) {
            if((*theList)[i].getID() == notification.getID()) {
                theList->erase(theList->begin()+i);
                size--;
                return true;
            }
        }

        return false; 
    }

    int NotificationStructure::getSize() {
        return size;
    }

    vector <Notification> NotificationStructure::getList() {
        return *theList;
    }
