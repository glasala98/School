#include "Notification.h"

#include "Activity.h"
#include "DateAndTime.h"
#include "Util.h"


using namespace std;

    Notification::Notification(int ID, Activity theActivity) {
        
        notificationID = ID;
        *activity = theActivity;

        int timeDelta;

        cout << "\n\nEnter the Time Delta (How many minutes before to be notified)";
        cin >> timeDelta;

        *delta = DateAndTime(timeDelta, "time");
        
        vector <string> selections;

        selections[1] = "1: Text";
        selections[2] = "2: Email";
        selections[3] = "3: Social Media";
        selections[4] = "4: Phone Call";

        method = Util::userInput("Select the delivery method: ", selections);
        
        /*
        if (method == 0) { //Text

        }

        else if (method == 1) { //Email

        }

        else if (method == 2) { //Social Media
            
        }

        else if (method == 3)  { //Phone
            
        }
        */

        status = 0;

    }


    bool Notification::notificationTemplate() { //Used for default structures

        int timeDelta;
        cout << "\n\nEnter the Time Delta (How many minutes before to be notified)";
        cin >> timeDelta;

        *delta = DateAndTime(timeDelta, "time");
        
        vector <string> selections;

        selections[1] = "1: Text";
        selections[2] = "2: Email";
        selections[3] = "3: Social Media";
        selections[4] = "4: Phone Call";

        method = Util::userInput("Select the delivery method: ", selections);

        /*
        if (method == 0) { //Text

        }

        else if (method == 1) { //Email

        }

        else if (method == 2) { //Social Media
            
        }

        else if (method == 3)  { //Phone
            
        }
        */

       return true;
    }

    Notification::Notification(int ID, Activity theActivity, DateAndTime theDelta, int theMethod) {
        
        notificationID = ID;
        *activity = theActivity;
        *delta = theDelta;
        method = method;
        /*
        if (method == 0) { //Text

        }

        else if (method == 1) { //Email

        }

        else if (method == 2) { //Social Media
            
        }

        else if (method == 3)  { //Phone
            
        }
        */

    }

    int Notification::getID() {
        return notificationID;
    }

    int Notification::getStatus() {
        return status;
    }

    bool Notification::setStatus(int newStatus) {
        status = newStatus;
        return true;
    }

    Activity Notification::getActivity() {
        return *activity;
    }

    DateAndTime Notification::getDelta() {
        return *delta;
    }

    bool Notification::setDelta(DateAndTime newDelta) {
        *delta = newDelta;
        return true;
    }

    int Notification::getDeliveryMethod() {
        return method;
    }

    bool Notification::setDeliveryMethod(int theMethod) {
        /*
        if (method == 0) { //Text

        }

        else if (method == 1) { //Email

        }

        else if (method == 2) { //Social Media
            
        }

        else if (method == 3)  { //Phone
            
        }
        */
        return true;
    }
