#include "NotificationDelivery.h"
#include "DateAndTime.h"
#include "Activity.h"

using namespace std;

    NotificationDelivery::NotificationDelivery(DateAndTime time, int method, Activity theActivity) {

    }

    bool push() {
        //Code to Push
        return true;
    }

    int NotificationDelivery::getID() {
        return notificationID;
    }

    Activity NotificationDelivery::getActivity() {
        return *activity;
    }

    DateAndTime NotificationDelivery::getPushTime() {
        return *pushTime;
    }

    bool NotificationDelivery::setPushTime(DateAndTime newTime) {

        *pushTime = newTime;
        return true;

    }

    int NotificationDelivery::getDeliveryMethod() {
        return method;
    }

    bool NotificationDelivery::setDeliveryMethod(int newMethod) {
        method = newMethod;

        //Code to update method

        return true;
    }
